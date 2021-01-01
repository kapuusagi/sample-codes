#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <circularly-list.h>
#include "read-args.h"

struct sample_list_entry {
    struct sample_list_entry *prev;
    struct sample_list_entry *next;
    int data;
};
struct sample_list {
    struct sample_list_entry *head;
};

static struct sample_list SampleList;

static void print_proc(void);
static void add_proc(char **argv, int argc);
static void splice_proc(char **argv, int argc);


int
main(int ac, char **av)
{
    char buf[256];

    CLIST_INIT(&SampleList);

    while (1) {
	fprintf(stdout, ">");
	fflush(stdout);
	char *argv[32];
	int argc = read_args(stdin, buf, sizeof(buf), argv, 32);
	if (argc < 0) {
	    break;
	}
	if ((argc == 1) && (strcmp(argv[0], "q") == 0)) {
	    break;
	} else if (((argc == 1) && (strcmp(argv[0], "p") == 0))
		|| ((argc == 1) && (strcmp(argv[0], "print") == 0))) {
	    print_proc();
	} else if ((argc >= 2) && (strcmp(argv[0], "add") == 0)) {
	    add_proc(argv + 1, argc - 1);
	} else if ((argc >= 2) && (strcmp(argv[0], "splice") == 0)) {
	    splice_proc(argv + 1, argc - 1);
	} else {
	    printf("commands:\n");
	    printf("add value# [value# [... ] ]: Add value.\n");
	    printf("splice begin# [count#]: Remove value# which find first.\n");
	    printf("print : print data.\n");
	    printf("p : print data.\n");
	    printf("q : quit application.\n");
	}
    }

    while (!CLIST_IS_EMPTY(&SampleList)) {
	struct sample_list_entry *p = CLIST_HEAD(&SampleList);
	CLIST_REMOVE(&SampleList, p);
	free(p);
    }

    return 0;
}

static void
print_proc(void)
{
    struct sample_list_entry *p = CLIST_HEAD(&SampleList);
    while (p != NULL) {
	printf("%d ", p->data);
	p = CLIST_HAS_NEXT(&SampleList, p) ? CLIST_ENTRY_NEXT(p) : NULL;
    }
    printf("\n");

    return ;
}

static void
add_proc(char **argv, int argc)
{
    if (argc == 0) {
	return ;
    }
    printf("added:");
    for (int i = 0; i < argc; i++) {
	int d = strtol(argv[i], NULL, 0);
	struct sample_list_entry *p = (struct sample_list_entry*)(
		malloc(sizeof(struct sample_list_entry)));
	if (p == NULL) {
	    fprintf(stderr, "%s\n", strerror(errno));
	    return;
	}

	CLIST_ENTRY_INIT(p);
	p->data = d;
	CLIST_ADD(&SampleList, p);
	printf("%d ", d);
    }
    printf("\n");
}
static void
splice_proc(char **argv, int argc)
{
    int begin = strtol(argv[0], NULL, 0);
    int count = (argc >= 2) ? strtol(argv[1], NULL, 0) : 1;

    int index = 0;
    struct sample_list_entry *p = CLIST_HEAD(&SampleList);
    while ((index < begin) && CLIST_HAS_NEXT(&SampleList, p)) {
	p = CLIST_ENTRY_NEXT(p);
	index++;
    }
    printf("removed:");
    while ((count > 0) && (p != NULL)) {
	struct sample_list_entry *remove_entry = p;
	p = (p != CLIST_TAIL(&SampleList)) ? CLIST_ENTRY_NEXT(p) : NULL;

	int d = remove_entry->data;
	CLIST_REMOVE(&SampleList, remove_entry);
	free(remove_entry);

	printf("%d ", d);
	count--;
    }
    printf("\n");
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "read-args.h"

int
read_args(FILE* fp, char *buf, size_t bufsize, char **argv, int max_argv)
{
    if (fgets(buf, bufsize, fp) == NULL) {
	/* detect EOF */
	errno = ENODATA;
	return -1;

    }
    size_t len = strlen(buf);
    if ((len > 0) && (buf[len - 1] == '\n')) {
	buf[len - 1] = '\0';
    }

    int count = 0;
    char *ptr;
    char *token = strtok_r(buf, " \t\r\n", &ptr);
    while ((token != NULL) && (count < max_argv)) {
	argv[count] = token;
	count++;
	token = strtok_r(NULL, " \t\r\n", &ptr);
    }

    return count;
}

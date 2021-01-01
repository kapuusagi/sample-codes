CFLAGS = -Werror -Wall -I../include
BLIST_TEST = blist-test
BLIST_TEST_OBJS = blist-test.o read-args.o 
CLIST_TEST = clist-test
CLIST_TEST_OBJS = clist-test.o read-args.o 

TARGETS = $(BLIST_TEST) $(CLIST_TEST)

all : $(TARGETS)

$(BLIST_TEST) : $(BLIST_TEST_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(CLIST_TEST) : $(CLIST_TEST_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o : %.c
	$(CC) -c $(CFLAGS) -o $@ $<


clean:
	rm -f $(TARGETS) *.o

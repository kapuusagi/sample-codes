CFLAGS = -ggdb

all : incbin-test

incbin-test : main.o resource.o
	gcc $(CFLAGS) -o $@ $^


%.o : %.c
	gcc $(CFLAGS) -c -o $@ $<

%.o : %.S
	gcc $(CFLAGS) -c -o $@ $<


clean: 
	rm -f *.o incbin-test

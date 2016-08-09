CC=gcc
CFLAGS=-std=c99 -Wall -pedantic -g3

all: testCounter

testCounter: counter.o testCounter.o
	$(CC) $(CFLAGS) -o $@ $^
	echo $@ "built finished."

testCounter.o:  counter.h

test:
	./testCounter

clean:
	$(RM) testCounter *.o *~
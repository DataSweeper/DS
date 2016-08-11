CC=gcc
CFLAGS=-std=c99 -Wall -pedantic -g3

all: useDeclareSort

useDeclareSort: useDeclareSort.o
	$(CC) $(CFLAGS) -o $@ $^
	echo $@ "built finished."

useDeclareSort.o: declareSort.h

test:
	./useDeclareSort

clean:
	$(RM) useDeclareSort *.o *~
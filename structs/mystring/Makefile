CC=gcc
CFLAGS=-std=c99 -Wall -pedantic -g3

all: myString

myString: myString.o
	$(CC) $(CFLAGS) -o $@ $^
	echo $@ "built finished."

myString.o: myString.c myString.h

test:
	./myString

clean:
	$(RM) myString *.o
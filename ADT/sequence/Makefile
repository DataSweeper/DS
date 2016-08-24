CC=gcc
CFLAGS=-std=c99 -g3 -pedantic -Wall

all: seqprinter

seqprinter: main.o sequence.o
	$(CC) $(CFLAGS) -o $@ $^

test: seqprinter
	./seqprinter

main.o: main.c sequence.h
sequence.o: sequence.o sequence.h

clean:
	$(RM) -f seqprinter *.o
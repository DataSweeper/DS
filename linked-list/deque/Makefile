CC=gcc

CFLAGS=-std=c99 -Wall -pedantic -O3 -g3

ITERATIONS=10000000
VALGRIND_ITERATIONS=100

all: testDeque testRingBuffer

time: all
	time ./testDeque $(ITERATIONS)
	time ./testRingBuffer $(ITERATIONS)

test: all
	./testDeque $(ITERATIONS)
	./testRingBuffer $(ITERATIONS)

testDeque: deque.o testDeque.o
	$(CC) $(CFLAGS) -o $@ $^

testRingBuffer: ringBuffer.o testDeque.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) testDeque testRingBuffer *.o *~

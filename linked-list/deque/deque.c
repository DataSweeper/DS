#include <stdlib.h>
#include <assert.h>
#include <stddef.h>

#include "deque.h"

#define NUM_DIRECTIONS (2)

struct deque {
    struct deque *next[NUM_DIRECTIONS];
    int value;
};

Deque
dequeCreate (void)
{
    Deque d;
    d = malloc(offsetof(struct deque, value));
    if (d) {
	d->next[DEQUE_FRONT] = d->next[DEQUE_BACK] = d;
    }
    return d;
}

void
dequePush (Deque d, int direction, int value)
{
    Deque e;

    assert(direction == DEQUE_FRONT || direction == DEQUE_BACK);

    e = malloc(sizeof(struct deque));
    assert(e);

    e->next[direction] = d->next[direction];
    e->next[!direction] = d;
    e->value = value;

    d->next[direction] = e;
    e->next[direction]->next[!direction] = e;
}

int
dequePop(Deque d, int direction)
{
    struct deque *e;
    int retval;
    assert(direction == DEQUE_FRONT || direction == DEQUE_BACK);
    e = d->next[direction];
    if(e == d) {
	return DEQUE_EMPTY;
    }
    /* else remove it */
    d->next[direction] = e->next[direction];
    e->next[direction]->next[!direction] = d;
    retval = e->value;
    free(e);
    return retval;
}

int
dequeIsEmpty(const Deque d)
{
    return d->next[DEQUE_FRONT] == d;
}

void
dequeDestroy(Deque d)
{
    while(!dequeIsEmpty(d)) {
	dequePop(d, DEQUE_FRONT);
    }
    free(d);
}

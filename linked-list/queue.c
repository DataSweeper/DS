#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct elt {
    struct elt *next;
    int value;
};

struct queue {
    struct elt *head;
    struct elt *tail;
};

typedef struct queue *Queue;

Queue
queueCreate (void)
{
    Queue q;
    q = malloc(sizeof(struct queue));
    q->head = q->tail = 0;
    return q;
}

void
enq (Queue q, int value)
{
    struct elt *e;

    e = malloc(sizeof(struct elt));
    assert(e);
    e->value = value;
    e->next = 0;
    
    if(q->head == 0) {
	q->head = e;
    } else {
	q->tail->next = e;
    }

    q->tail = e;
}

int
queueEmpty (const Queue q)
{
    return (q->head == 0);
}

int
deq (Queue q)
{
    int ret;
    struct elt *e;
    assert(!queueEmpty(q));
    ret = q->head->value;
    e = q->head;
    q->head = e->next;
    free(e);
    return ret;
}

void
queuePrint (Queue q)
{
    struct elt *e;

    for (e = q->head; e != 0; e = e->next) {
	printf("%d", e->value);
    }

    putchar('\n');
}

void
queueDestroy (Queue q)
{
    while (!queueEmpty(q)) {
	deq(q);
    }
    free(q);
}

int
main (int argc, char **argv)
{
    int i;
    Queue q;
    q = queueCreate();

    for (i = 0; i < 5; i++) {
	printf("enq %d\n", i);
	enq(q, i);
	queuePrint(q);
    }

    while(!queueEmpty(q)) {
	printf("deq get %d\n", deq(q));
	queuePrint(q);
    }

    queueDestroy(q);

    return 0;
}

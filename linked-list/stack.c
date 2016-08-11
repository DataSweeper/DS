#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct elt {
    struct elt *next;
    int value;
};

typedef struct elt *Stack;

#define STACK_EMPTY (0)

Stack
stackPush (Stack s, int value)
{
    struct elt *e;

    e = malloc(sizeof(struct elt));
    assert(e);

    e->value = value;
    e->next = s;
    s = e;
    return s;
}

int
stackEmpty (Stack s)
{
    return (s == 0);
}

Stack
stackPop (Stack s)
{
    // int ret;
    struct elt *e;

    assert (!stackEmpty(s));

    // ret = s->value;

    e = s;
    s = e->next;
    
    free(e);

    return s;
}

void
stackPrint(Stack s)
{
    struct elt *e;
    for(e = s; e != 0; e = e->next) {
	printf("%d ", e->value);
    }
    putchar('\n');
}

int
main(int argc, char **argv)
{
    int i;
    Stack s;
    s = STACK_EMPTY;

    printf("=====================Push Stack====================\n");
    for(i = 0; i < 5; i++) {
	s = stackPush(s, i);
	stackPrint(s);
    }
    
    printf("=====================Pop Stack====================\n");
    while(!stackEmpty(s)) {
	s = stackPop(s);
	stackPrint(s);
    }

    return 0;
}

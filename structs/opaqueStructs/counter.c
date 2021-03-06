#include <stdlib.h>
#include <assert.h>
#include "counter.h"

/* counter structure */
struct counter {
    int value;
};

Counter
counterCreate(void)
{
    Counter c;
    c = malloc(sizeof(struct counter));
    assert(c);
    c->value = 0;
    return c;
}

void
counterDestroy(Counter c)
{
    free(c);
}

void
initCounter(Counter c, int a)
{
    c->value = a;
}

int
counterIncrement(Counter c)
{
    return ++(c->value);
}

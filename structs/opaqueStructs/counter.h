/* Create a new counter, initialized to 0. Call counterDestroy to get rid of it. */

typedef struct counter *Counter;

Counter counterCreate(void);
/* Free space used by a counter. */
void counterDestroy(Counter);
/* Increment a counter and return new value. */
int counterIncrement(Counter);
/* Initialize the counter start value */
void initCounter(Counter, int);

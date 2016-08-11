typedef struct deque *Deque;

#define DEQUE_FRONT (0)
#define DEQUE_BACK (1)

#define DEQUE_EMPTY (-1)

Deque dequeCreate(void);

void dequePush(Deque, int, int);

int dequePop(Deque, int);

int dequeIsEmpty(const Deque);

void dequeDestroy(Deque);

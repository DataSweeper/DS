typedef struct sequence *Sequence;

Sequence seq_create(int init);

Sequence seq_create_step(int init, int step);

void seq_destroy(Sequence);

int seq_next(Sequence);

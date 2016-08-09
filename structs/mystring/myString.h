typedef struct string String;

String *makeString(const char *s);

void destroyString(String *);

int stringLength(String *);

int stringCharAt(String *s, int index);

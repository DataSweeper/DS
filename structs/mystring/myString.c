#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "myString.h"

struct string {
    int length;
    char *data;
};

String *
makeString(const char *s)
{
    String *s2;

    s2 = malloc(sizeof(struct string));
    if (s2 == 0) { return 0; }
    
    s2->length = strlen(s);
    
    s2->data = malloc(s2->length);
    if(s2->data == 0) {
	free(s2);
	return 0;
    }

    strncpy(s2->data, s, s2->length);
    
    return s2;
}

void
destroyString(String *s)
{
    free(s->data);
    free(s);
}

int stringLength (String *s)
{
    return s->length;
}

int
stringCharAt (String *s, int index)
{
    if(index < 0 || index >= s->length) {
	return -1;
    } else {
	return s->data[index];
    }
}

int
main (int argc, char** argv)
{
    String *s = makeString("SivaGnanam");
    printf("dummy main function. %s\n", s->data);
    destroyString(s);
    //printf("dummy main function1. %s\n", s->data);
    return 0;
}

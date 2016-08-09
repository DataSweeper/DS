#include <stdio.h>

enum TypeCode { TYPE_INT, TYPE_DOUBLE, TYPE_STRING };

struct lispObject {
    int type;
    union {
	int intVal;
	double floatVal;
	char* stringVal;
	struct {
	    struct lispObject *car;
	     struct lispObject *cdr;
	} consVal;
    } u;
};

struct LispValue {
    enum TypeCode typeCode;
    union {
	int i;
	double d;
	char *s;
    } value;
};

int
main (int argc, char** argv)
{
    struct lispObject o;
    struct LispValue lv;

    lv.typeCode = TYPE_INT;
    lv.value.i = 10;
    o.type = TYPE_INT;
    o.u.intVal = 27;
    //o.u.consVal.car = &o;
    printf("%d\n %d\n", o.u.intVal, lv.value.i);
}

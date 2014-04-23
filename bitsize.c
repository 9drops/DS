#include <stdio.h>

struct test{
	int a:2;
	int b:2;
	int c:1;
	int :0;/*new word begin*/
	int :6;
};


int main()
{
	struct test t;
	t.a = 1;
	t.b = 5;  /*high bits fill sign 0*/
	t.c = 1;   /*high bits fill sign 1*/
	
	printf("sizeof(t):%d t.a:%d t.b:%d t.c:%d\n", sizeof(t), t.a, t.b, t.c);
	return 0;
}

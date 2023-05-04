#include <stdio.h>
#include "stack.h"

int main(void)
{
	Stack s1, s2;
	//Stack stacks[100];
	
	//s1.tos = 0;
	//s2.tos = 0;
	initStack(&s1, 100, sizeof(int));
	initStack(&s2, 10, sizeof(double));
	
	int i = 100; push(&s1, &i);
	//push(&s1, 100);
	i = 200; push(&s1, &i);
	i = 300; push(&s1, &i);
	
	int re;
	pop(&s1, &re); printf("s1 1st pop() : %d\n", re);
	pop(&s1, &re); printf("s1 2nd pop() : %d\n", re);
	pop(&s1, &re); printf("s1 3rd pop() : %d\n", re);
	
	double d = 1.1; push(&s2, &d);
	d = 2.2; push(&s2, &d);
	d= 3.3; push(&s2, &d);
	
	double re2;
	pop(&s2, &re2); printf("s2 1st pop() : %f\n", re2);
	pop(&s2, &re2); printf("s2 2nd pop() : %f\n", re2);
	pop(&s2, &re2); printf("s2 3rd pop() : %f\n", re2);
	
	cleanupStack(&s1);
	cleanupStack(&s2);
	
	return 0;
}

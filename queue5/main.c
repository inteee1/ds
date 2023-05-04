#include <stdio.h>
#include "queue.h"


int main(void)
{
	Queue q1, q2;
	initQueue(&q1, 100, sizeof(int));
	initQueue(&q2, 10, sizeof(double));
	
	int j; 
	j = 100; push(&q1, &j);
	j = 200; push(&q1, &j);
	j = 300; push(&q1, &j);
	
	int re;
	pop(&q1, &re); printf("1st pop() : %d\n", re);
	pop(&q1, &re); printf("2nd pop() : %d\n", re);
	pop(&q1, &re); printf("3rd pop() : %d\n", re);
	
	double d; 
	d = 1.1; push(&q2, &d);
	d = 2.2; push(&q2, &d);
	d= 3.3; push(&q2, &d);
	
	double re2;
	pop(&q2, &re2); printf("1st pop() : %f\n", re2);
	pop(&q2, &re2); printf("2nd pop() : %f\n", re2);
	pop(&q2, &re2); printf("3rd pop() : %f\n", re2);
	
	cleanupQueue(&q1);
	cleanupQueue(&q2);
	
	return 0;
}

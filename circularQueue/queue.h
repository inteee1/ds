#ifndef QUEUE_H
#define QUEUE_H


typedef struct queue {
	int *pArr;
	int size;
	int front;
	int rear;
	int i;
} Queue;


void initQueue(Queue *pq, int size);
void cleanupQueue(Queue *pq);
void push(Queue *pq, int data);
int pop(Queue *pq);


#endif

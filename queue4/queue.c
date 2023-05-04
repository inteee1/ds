#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "queue.h"


void push(Queue *pq, int data)
{
	assert(pq->rear != pq->size);
	pq->pArr[pq->rear] = data;
	++pq->rear;
}

int pop(Queue *pq)
{
	assert(pq->rear != pq->front);
	pq->i = pq->front;
	++pq->front;
	return pq->pArr[pq->i];
}

void initQueue(Queue *pq, int size)
{
	pq->pArr = malloc(sizeof(int) * size);
	assert(pq->pArr != NULL);
	pq->size = size;
	pq->front = 0;
	pq->rear = 0;
}

void cleanupQueue(Queue *pq) {
	free(pq->pArr);
}


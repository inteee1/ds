#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "stack.h"

void push(Stack *ps, const void *pData)
{
	/*if (ps->tos == STACK_SIZE) {
	 fprintf(stderr, "stack is full\n");
	 exit(1);
	}*/
	assert(ps->tos != ps->size);
	//ps->pArr[ps->tos] = data;
	//memcpy(&ps->pArr[ps->tos], pData, ps->eleSize);
	 memcpy((unsigned char *)ps->pArr + ps->tos * ps->eleSize, pData, ps->eleSize);
	++ps->tos;
}

void pop(Stack *ps, void *pData)
{
	/*if (ps->tos == 0) {
	 fprintf(stderr, "stack is empty\n");
	 exit(2);
	}*/
	assert(ps->tos != 0);
	--ps->tos;
	//return ps->array[ps->tos];
	//*pData = ps->pArr[ps->tos];
	memcpy(pData, (unsigned char *)ps->pArr+ ps->tos * ps->eleSize, ps->eleSize);
}

void initStack(Stack *ps, int size, int eleSize)
{
	ps->pArr = malloc(sizeof(eleSize) * size);
	assert(ps->pArr);
	ps->eleSize = eleSize;
	ps->size = size;
	ps->tos = 0;
	//ps->tos = 0;
}
void cleanupStack(Stack *ps)
{
	free(ps->pArr);
}

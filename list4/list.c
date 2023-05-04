#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"

void initList(List *pList, int eleSize){
	pList->ptr = malloc(sizeof(Node) /*+ eleSize*/ );
	pList->ptr->next = NULL;
	pList->eleSize = eleSize;
}

void cleanupList(List *pList){
	Node *p = pList->ptr;
	while(p){
		Node *tmp = p;
		p = p->next;
		free(tmp);
	}
}
void printList(const List *pList, void (*print)(const void *)){
	Node *p = pList->ptr->next;
	printf("[");
	while (p){
		//printf("%d. ", p->data);
		(*print)(p+1); 			//print(p+1);
		printf( (p->next) ? ", " : "");
		p = p->next;
	}
	printf("]\n");
}
void insertFirstNode(List *pList, const void *pData){
	Node *p = malloc(sizeof(Node) + pList->eleSize);
	//p->data = data;
	memcpy(p + 1, pData, pList->eleSize);
	p->next = pList->ptr->next;
	pList->ptr->next = p;
}
void insertNode(List *pList, const void *pPrevData, const void *pData){
	Node *p = pList->ptr->next;
	while (p){
		if (memcmp(p + 1, pPrevData, pList->eleSize) == 0)/*(p->data == prevData)*/{
		break;
		}
		p = p->next;
	}
	if (p){
		Node *tmp = malloc(sizeof(Node) + pList->eleSize);
		//tmp->data =data;
		memcpy(tmp + 1, pData, pList->eleSize);
		tmp->next = p->next;
		p->next = tmp; 
	}
}
void deleteNode(List *pList, const void *pData){
	Node *p = pList->ptr->next;
	Node *p2 = pList->ptr;
	
	while(p){
		if (memcmp(p + 1, pData, pList->eleSize) == 0)
		 break; 
	p = p->next;
	p2 = p2->next;
	}
	if(p){
		p2->next = p->next;
		free(p);
	}
}

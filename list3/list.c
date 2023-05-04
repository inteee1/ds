#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


static Node *createNode(int data, Node *next){
	Node *p = malloc(sizeof(Node));
	assert(p );
	p->data = data;
	p->next = next;
	
	return p;
}

void initList(List *pList){
	pList->ptr = createNode(-1, NULL);
}

void cleanupList(List *pList){
	Node *p = pList->ptr;
	while(p){
		Node *tmp = p;
		p = p->next;
		free(tmp);
	}
}
void printList(const List *pList){
	Node *p = pList->ptr->next;
	while (p){
		printf("%d. ", p->data);
		if(p->next != NULL)
		printf(", ");
		else
		printf(" ");
		p = p->next;
	}
	printf("\n");
}

void insertFirstNode(List *pList, int data){
	pList->ptr->next = createNode(data, pList->ptr->next);
}
void insertNode(List *pList, int prevData, int data){
	Node *p = pList->ptr->next;
	while (p){
		if (p->data == prevData){
		break;
		}
		p = p->next;
	}
	if (p){
		p->next = createNode(data, p->next);
	}
}
void deleteNode(List *pList, int data){
	Node *p = pList->ptr->next;
	Node *p2 = pList->ptr;
	
	while(p){
		if(p->data == data) break;
	p = p->next;
	p2 = p2->next;
	}
	if(p){
		p2->next = p->next;
		free(p);
	}
}

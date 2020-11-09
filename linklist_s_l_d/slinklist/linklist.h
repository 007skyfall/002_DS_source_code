#ifndef __LINKLIST_H__
#define __LINKLIST_H__
#include <stdio.h>
#include <stdlib.h>

typedef int datatype;
typedef struct node{
	datatype data;
	struct node * next;
}Linknode, * Linknode_t;

Linknode_t  create_linklist();
void show_linklist(Linknode_t H);
#endif

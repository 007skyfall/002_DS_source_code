#ifndef __LINKLIST_H__
#define __LINKLIST_H__
#include <stdio.h>
#include <stdlib.h>

typedef int datatype;
typedef struct node{
	datatype data;
	struct node * next;
	struct node * prior;
}DLinknode, *DLinknode_t;

DLinknode_t  create_dlinklist();
void show_dlinklist(DLinknode_t H);
DLinknode_t getnode_dlinklist(DLinknode_t H, int pos);
int insert_dlinklist(DLinknode_t H, datatype x, int pos);
int delete_dlinklist(DLinknode_t H, int pos);
#endif

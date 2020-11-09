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
int headinsert_linklist(Linknode_t H, datatype x);
int headdelete_linklist(Linknode_t H);
void show_linklist(Linknode_t H);
Linknode_t getnode_linklist(Linknode_t H, int pos);
Linknode_t locate_linklist(Linknode_t H, datatype x);
int insert_linklist(Linknode_t H, datatype x, int pos);
int delete_linklist(Linknode_t H, int pos);
#endif

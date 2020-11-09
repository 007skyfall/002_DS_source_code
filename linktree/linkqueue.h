#ifndef __LINKQUEUE_H__
#define __LINKQUEUE_H__

#include <stdio.h>
#include <stdlib.h>
#include "linktree.h"

typedef struct node_t * datatype;
//结点结构
typedef struct lquenode{
	datatype data;
	struct lquenode * next;
}Quenode, *Quenode_t;
//队列结构
typedef struct linkque{
	struct lquenode * front;
	struct lquenode * rear;
}Linkque, *Linkque_t;

void create_linkque(Linkque_t *Q);
int in_linkque(Linkque_t Q, datatype x);
datatype out_linkque(Linkque_t Q);
void show_linkque(Linkque_t Q);
int is_empty_linkque(Linkque_t Q);

#endif

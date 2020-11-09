#ifndef __LINKTREE_H__
#define __LINKTREE_H__

#include <stdio.h>
#include <stdlib.h>
#include "linkqueue.h"

typedef int Tdatatype;

typedef struct node_t{
	Tdatatype data;
	struct node_t *lchild;
	struct node_t *rchild;
}btreenode, *btreenode_t;

btreenode_t create_btree(int i, int n);
void pre_order(btreenode_t root);
void min_order(btreenode_t root);
void post_order(btreenode_t root);
void level_order(btreenode_t root);
#endif


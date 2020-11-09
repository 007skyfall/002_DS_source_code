/*链式的树*/
#ifndef _TREE_H_
#define _TREE_H_

#include <stdio.h>
#include <stdlib.h>

//节点类型
typedef struct tree{
	int data; 			//节点的编号
	struct tree *lchild;//左孩子的指针
	struct tree *rchild;//右孩子的指针
}linktree_t;

//创建完全二叉树
linktree_t *linktree_create(int i, int n);

#endif

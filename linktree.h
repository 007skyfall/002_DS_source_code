#ifndef __LINKTREE_H__
#define __LINKTREE_H__

typedef int Tdatatype;

typedef struct node_t{
	Tdatatype data;
	struct node_t *lchild;
	struct node_t *rchild;
}btreenode, *btreenode_t;





#endif


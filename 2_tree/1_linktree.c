/*链式的树*/

#include <stdio.h>
#include <stdlib.h>

//节点类型
typedef struct tree{
	int data; 			//节点的编号
	struct tree *lchild;//左孩子的指针
	struct tree *rchild;//右孩子的指针
}linktree_t;

//创建完全二叉树
linktree_t *linktree_create(int i, int n)
{
	linktree_t *root = (linktree_t*)malloc(sizeof(linktree_t)); 	//开辟节点的空间
	root->data = i;
	if(2*i <= n)
	{
		 root->lchild = linktree_create(2*i, n);
	}
	else
	{
		root->lchild = NULL; 		//没有左孩子指向NULL
	}

	if(2*i+1 <= n)
	{
		root->rchild = linktree_create(2*i+1, n);
	}
	else
	{
		root->rchild = NULL; 		//没有右孩子指向NULL
	}

	return root;
}

//遍历(先序：根左右)
int linktree_pre_order(linktree_t *root)
{
	printf("%d  ",root->data);
	if(root->lchild != NULL)
	{
		linktree_pre_order(root->lchild);
	}

	if(root->rchild != NULL)
	{
		linktree_pre_order(root->rchild);
	}

	return 0;
}

int main(int argc, const char *argv[])
{
	linktree_t *root = linktree_create(1, 8);
	linktree_pre_order(root);
	putchar(10);
	
	return 0;
}



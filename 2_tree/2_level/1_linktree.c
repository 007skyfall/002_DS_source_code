/*链式的树*/
#include "2_linktree.h"
#include "4_linkqueue.h"

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

int linktree_level(linktree_t *root)
{
	linkqueue_t *queue = linkqueue_create();
	linkqueue_input(queue, root);

	while(!linkqueue_is_empty(queue))
	{
		root = linkqueue_output(queue);
		printf("%d  ",root->data);

		if(root->lchild != NULL)
		{
			linkqueue_input(queue, root->lchild);
		}

		if(root->rchild != NULL)
		{
			linkqueue_input(queue, root->rchild);
		}
	}
	putchar('\n');
	return 0;
}

int main(int argc, const char *argv[])
{
	linktree_t *root = linktree_create(1, 8);
	linktree_level(root);
	
	return 0;
}



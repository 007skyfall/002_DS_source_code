#include "linktree.h"

btreenode_t create_btree(int i, int n){
	btreenode_t root = NULL;
	if((root = (btreenode *)malloc(sizeof(btreenode))) == NULL ){ 
		printf("create error!\n"); return NULL;
	}
	root->data = i;
	if(2*i<=n){
		root->lchild = create_btree(2*i, n);
	}else{
		root->lchild = NULL;
	}
	if(2*i+1 <= n){
		root->rchild = create_btree(2*i+1, n);
	}else{
		root->rchild= NULL;
	}
	return root;
}
void pre_order(btreenode_t root){
	if( root != NULL ){
		printf("%d\t", root->data);
		pre_order(root->lchild);
		pre_order(root->rchild);
	}
	return;
}
void min_order(btreenode_t root){
	if( root != NULL ){
		min_order(root->lchild);
		printf("%d\t", root->data);
		min_order(root->rchild);
	}
	return;
}
void post_order(btreenode_t root){
	if( root != NULL ){
		post_order(root->lchild);
		post_order(root->rchild);
		printf("%d\t", root->data);
	}
	return;
}

void level_order(btreenode_t root){
	//1. 初始化队列
	Linkque_t Q = NULL;
	create_linkque(&Q);
	//2. 根入队
	in_linkque(Q, root);

	//3. 循环孩子
	while(is_empty_linkque(Q) != 1){
		//出队当前父结点
		root = out_linkque(Q);
		printf("%d\t", root->data);
		//当前父结点的孩子入队
		if(root->lchild != NULL ){
			in_linkque(Q, root->lchild);
		}
		if(root->rchild != NULL ){
			in_linkque(Q, root->rchild);
		}
	}
}

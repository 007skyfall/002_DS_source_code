#include "linkqueue.h"

void create_linkque(Linkque_t *Q){
	//创建队列结构
	(*Q) = (Linkque *)malloc(sizeof(Linkque));
	if(NULL == (*Q)){ return; }

	//创建头结点
	//Quenode_t head = NULL;
	(*Q)->front = (Quenode *)malloc(sizeof(Quenode));
	if( NULL == (*Q)->front ){ free(*Q); return; }
	
	//(*Q)->front->data = 0;
	(*Q)->front->next = NULL;
	(*Q)->rear = (*Q)->front;
	return;
}
int in_linkque(Linkque_t Q, datatype x){
	//创建新结点
	Quenode_t new = NULL;
	new = (Quenode *)malloc(sizeof(Quenode));
	if(NULL == new){ return -1; }
	new->data = x;
	new->next = Q->rear->next;
	//让原来的队尾结点找到新的结点
	Q->rear->next = new;
	//更新队尾指针
	Q->rear = Q->rear->next;
	return 0;
}
int is_empty_linkque(Linkque_t Q){
	if( NULL == Q ){ return -1; }
	return ((Q->front == Q->rear) ? 1:0);
}
datatype out_linkque(Linkque_t Q){
	if(NULL == Q){ return -1; }
	if(is_empty_linkque(Q) == 1 ){ return -1; }	
	datatype del = 0;
	//找到队头数据结点
	Quenode_t t = Q->front->next;
	//出队队头数据结点
	Q->front->next = t->next;
	//校正rear,特殊情况
	if(Q->front->next == NULL){
		Q->rear = Q->front;
	}
	//释放出队数据结点
	del = t->data;
	free(t);
	t = NULL;
	return del;
}
void show_linkque(Linkque_t Q){
	if(NULL == Q){ return; }
	if(is_empty_linkque(Q) == 1){
		printf("Q is empty!\n");
		return;
	}
	Quenode_t p = Q->front;
	while(p->next != NULL){
		printf("%d, %p\n", p->next->data, p->next);
		p = p->next;
	}
	puts("----------------------");	
}

#include "seqqueue.h"

Seqqueue_t create_seqqueue(){
	Seqqueue_t Q = NULL;
	Q = (Seqqueue *)malloc(sizeof(Seqqueue));
	if( NULL == Q){ return NULL; }
	Q->front = Q->rear = MAXSIZE-1;
	return Q;
}
int is_full_seqqueue(Seqqueue_t Q){
	return ( ((Q->front%MAXSIZE) == ((Q->rear+1)%MAXSIZE)) ? 1 : 0 );
}

int in_seqqueue(Seqqueue_t Q, datatype x){
	if(is_full_seqqueue(Q) == 1){ return -1;}
	Q->rear = (Q->rear+1)%MAXSIZE;
	Q->data[Q->rear] = x;
	printf("in %d\n", Q->data[Q->rear]);
	return 0;
}
int is_empty_seqqueue(Seqqueue_t Q){
	return ((Q->front == Q->rear)?1:0);
}
int out_seqqueue(Seqqueue_t Q){
	if(is_empty_seqqueue(Q) == 1 ){ return -1; }
	printf("out %d\n", Q->data[Q->front]);
	Q->front = (Q->front+1)%MAXSIZE;
	return 0;
}
void show_seqqueue(Seqqueue_t Q){
	if(is_empty_seqqueue(Q) == 1){ return; }
	puts("----begine----");
	int i = (Q->front%MAXSIZE);
	while(i != (Q->rear+1)%MAXSIZE){
		printf("%d\n", Q->data[i]);
		i= (i+1)%MAXSIZE;
	}
	puts("-----end-----");
	return;
}

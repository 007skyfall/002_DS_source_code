#include <stdio.h>
#include <stdlib.h>

#define N 10

typedef int datatype;
typedef int postype;

typedef struct list{
	datatype data[N];
	postype last;
}SeqList,* SeqList_t;

//函数：创建空表的函数；
SeqList_t create_seqlist(void){
	//创建空表
	SeqList_t L = NULL;
	L = (SeqList *)malloc(sizeof(SeqList));
	if( NULL == L ){
		printf("create error!\n");
		return NULL;
	}
	L->last = -1;
	return L;
}
//判断满
int is_full_seqlist(SeqList_t L){
	return ((L->last == N-1) ? 1 : 0);
}
int is_empty_seqlist(SeqList_t L){
	return ((L->last == -1) ? 1 : 0);
}
//插入数据
int insert_seqlist(SeqList_t L, postype pos, datatype x){
	if( NULL == L ){
		printf("L is NULL!\n");
		return -1;
	}
	if( is_full_seqlist(L) == 1 || pos<0 || pos>(L->last+1) ){
		printf("pos error!\n");
		return -1;
	}
	int i;
	for(i = L->last; i >= pos; i--){
		L->data[i+1] = L->data[i]; 
	}
	L->data[pos] = x;
	L->last++;
	return 0;
}
//查看函数
void show_seqlist(SeqList_t L){
	if( NULL == L ){
		printf("show: L is NULL!\n");
		return;
	}
	if(is_empty_seqlist(L) == 1){
		printf("L is empty!\n");
		return;
	}
	int i;
	for(i = 0; i <= L->last; i++){
		printf("%d\t", L->data[i]);
	}
	puts("");
}

int main(int argc, const char *argv[])
{
	//创建空表
	SeqList *L1 = create_seqlist();
	//SeqList *L2 = create_seqlist();
#if 0
	//insert_seqlist(L1, 2, 100); error
	insert_seqlist(L1, 0, 100);
#endif
#if 1
	int i;
	for(i = 0; i < 5; i++){
		insert_seqlist(L1, i, 99);
	}
#endif
	show_seqlist(L1);
	return 0;
}

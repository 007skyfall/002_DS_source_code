#include "seqlist.h"

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
	if( NULL == L ){
		printf("L is NULL!\n");
		return -1;
	}
	return ((L->last == N-1) ? 1 : 0);
}
//判断空
int is_empty_seqlist(SeqList_t L){
	if( NULL == L ){
		printf("L is NULL!\n");
		return -1;
	}
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
int delete_seqlist(SeqList_t L, postype pos){
	if( NULL == L ){
		printf("show: L is NULL!\n");
		return -1;
	}
	if( pos<0 || pos>L->last || is_empty_seqlist(L) == 1){
		printf("pos error!\n");
		return -1;
	}

	int i;
	for(i = pos+1; i <= L->last; i++){
		L->data[i-1] = L->data[i];
	}
	L->last--;
	return 0;
}
void free_seqlist(SeqList **L){
	if( NULL == L ){
		printf("L is NULL!\n");
		return;
	}
	free(*L);
	(*L) = NULL;
}
void clear_seqlist(SeqList_t L){
	if( NULL == L ){
		printf("L is NULL!\n");
		return;
	}
	L->last = -1;
}
int len_seqlist(SeqList_t L){
	if( NULL == L ){
		printf("L is NULL!\n");
		return -1;
	}
	return (L->last+1);
}
datatype getdata_seqlist(SeqList_t L,postype pos){
	if( NULL == L ){
		printf("L is NULL!\n");
		return -1;
	}
	if(is_empty_seqlist(L) == 1 || pos<0 || pos > L->last){
		printf("pos error!\n");
		return -1;
	}
	return (L->data[pos]);
}
postype loacte_seqlist(SeqList_t L , datatype value){
	if( NULL == L ){
		printf("L is NULL!\n");
		return -1;
	}
	int i = 0;
	while( i <= L->last ) {
		if(value == L->data[i]){
			return i;
		}else{
			i++;
		}
	}
	return -1;
}

int change_seqlist(SeqList_t L,postype  pos,datatype value){
	if( NULL == L ){
		printf("L is NULL!\n");
		return -1;
	}
	if(is_empty_seqlist(L) == 1 || pos<0 || pos > L->last){
		printf("pos error!\n");
		return -1;
	}
	L->data[pos] = value;
	return 0;
}
int union_seqlist(SeqList_t LA, SeqList_t LB){
	if(NULL == LA || NULL == LB){
		return -1;
	}
	int i = 0, x = 0;
	while(i < len_seqlist(LB)){
		x = getdata_seqlist(LB, i);
		if( loacte_seqlist(LA, x) == -1 ){
			if(insert_seqlist(LA, 0, x) == -1){
				printf("insert error!\n");
				return -1;
			}
		}
		i++;
	}
	return 0;
}
int delre_seqlist(SeqList_t L){
	if( NULL == L ){
		printf("L is NULL!\n");
		return -1;
	}
	int i = 0, j = 0;
	for(i = 0; i < len_seqlist(L); i++){
		for(j = i+1; j < len_seqlist(L); j++){
			if(L->data[i] == L->data[j]){
				delete_seqlist(L,j);
				j--;	
			}
		}
	}
	return 0;
}


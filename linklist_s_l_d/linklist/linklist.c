#include  "linklist.h"

Linknode_t  create_linklist(){
	Linknode_t H = NULL;
	//头结点
	H = (Linknode *)malloc(sizeof(Linknode));
	if(NULL == H){
		return NULL;
	}
	H->data = 0;
	H->next = NULL;
	return H;
}
int headinsert_linklist(Linknode_t H, datatype x){
	if(NULL == H){
		printf("H is NULL!\n");
		return -1;
	}
	Linknode_t new = NULL;
	new = (Linknode *)malloc(sizeof(Linknode));
	if(NULL == new){
		return -1;
	}
	new->data = x;
	new->next = H->next;
	H->next = new;
	return 0;
}
int headdelete_linklist(Linknode_t H){
	if(NULL == H){
		printf("H is NULL!\n");
		return -1;
	}
	if(H->next == NULL){
		printf("H is NULL\n");
		return -1;
	}
	Linknode_t del = NULL;
	del = H->next;
	H->next = del->next;
	free(del);
	//del = NULL;
	return 0;
}
void show_linklist(Linknode_t H){
	if(NULL == H){
		printf("H is NULL!\n");
		return;
	}
	Linknode_t p = H->next;
	while(p != NULL){
		printf("%d\n", p->data);
		p = p->next;
	}
}
//根据位置找结点
Linknode_t getnode_linklist(Linknode_t H, int pos){
	if(pos < 0){
		printf("pos error!\n");return NULL;
	}
	if(NULL == H){
		printf("H is NULL!\n");return NULL;
	}
	Linknode_t p = H->next; //不计算头结点
	int i = 0;
	while(p != NULL && i < pos){ 
		p = p->next;
		i++;
	}
	if( pos == i){
		return p;
	}
	printf("pos is violation!\n");
	return NULL;
}
//根据数据找结点
Linknode_t locate_linklist(Linknode_t H, datatype x){
	if(NULL == H){
		printf("H is NULL!\n");return NULL;
	}
	Linknode_t p = H->next;
	while( p != NULL && p->data != x){
		p = p->next;
	}
	if(x == p->data){
		return p;
	}
	printf("value not have!\n");
	return NULL;
}
int insert_linklist(Linknode_t H, datatype x, int pos){
	if(NULL == H || pos < 0){ return -1;}
	Linknode_t p = NULL;
	if(pos == 0){
		p = H;
	}else{
		p = getnode_linklist(H, pos-1);
	}
	if( NULL == p ){ return -1; }
	Linknode_t new = NULL;
	new = (Linknode *)malloc(sizeof(Linknode));
	if( NULL == new){
		return -1;
	}
	new->data = x;
	new->next = p->next;
	p->next = new;
	return 0;
}
int delete_linklist(Linknode_t H, int pos){
	if(NULL == H || pos < 0){ return -1; }
	Linknode_t p = NULL;
	if(pos == 0){
		p = H;
	}else{
		p = getnode_linklist(H, pos-1);
	}
	if(NULL == p || NULL == p->next){ return -1; }
	Linknode_t del = p->next;
	p->next = del->next;
	free(del);
	del = NULL;
	return 0;
}

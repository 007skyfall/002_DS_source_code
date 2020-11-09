#include  "dlinklist.h"

DLinknode_t  create_dlinklist(){
	DLinknode_t H = NULL;
	//头结点
	H = (DLinknode *)malloc(sizeof(DLinknode));
	if(NULL == H){
		return NULL;
	}
	H->data = 0;
	H->next = H;
	H->prior = H;
	return H;
}
void show_dlinklist(DLinknode_t H){
	if(NULL == H){
		printf("H is NULL!\n");
		return;
	}
	DLinknode_t p = H->next;
	while(p != H){//遍历了一遍，再次找到头结点
		printf("%d\n", p->data);
		p = p->next;
	}
}
DLinknode_t getnode_dlinklist(DLinknode_t H, int pos){
	if(pos < 0){
		printf("pos error!\n");return NULL;
	}
	if(NULL == H){
		printf("H is NULL!\n");return NULL;
	}
	DLinknode_t p = H->next; //不计算头结点
	int i = 0;
	while(p != H && i < pos){ 
		p = p->next;
		i++;
	}
	if( pos == i){
		return p;
	}
	printf("pos is violation!\n");
	return NULL;
}
int insert_dlinklist(DLinknode_t H, datatype x, int pos){
	if(NULL == H || pos < 0){ return -1;}
	DLinknode_t p = NULL;
	if(pos == 0){
		p = H;
	}else{
		p = getnode_dlinklist(H, pos);
	}
	if( NULL == p ){ return -1; }
	DLinknode_t new = NULL;
	new = (DLinknode *)malloc(sizeof(DLinknode));
	if( NULL == new){
		return -1;
	}
	new->data = x;
	//1.
	new->prior = p->prior;
	//2.
	new->next = p;
	//3.
	(p->prior)->next = new;
	//4.
	p->prior = new;
	return 0;
}
int delete_dlinklist(DLinknode_t H, int pos){
	if(NULL == H || pos < 0){ return -1;}
	DLinknode_t del = getnode_dlinklist(H, pos);
	if(NULL == del) { return -1; }
	//1.
	(del->prior)->next = del->next;
	//2.
	(del->next)->prior = del->prior;
	//3.
	free(del);
	del = NULL;
	return 0;
}



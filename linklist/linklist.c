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

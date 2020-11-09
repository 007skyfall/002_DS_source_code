#include  "linklist.h"

Linknode_t  create_linklist(){
	Linknode_t H = NULL;
	//头结点
	H = (Linknode *)malloc(sizeof(Linknode));
	if(NULL == H){
		return NULL;
	}
	H->data = 0;
	H->next = H;
	return H;
}
Linknode_t  create_all_linklist(){
	Linknode_t H = NULL, r, p = NULL;
	int value = 0;
	//头结点
	H = (Linknode *)malloc(sizeof(Linknode));
	if(NULL == H){
		return NULL;
	}
	H->data = 0;
	H->next = H;
	r = H;
	while(1){
		scanf("%d", &value);
		if(value == -1){
			break;
		}
		p = (Linknode *)malloc(sizeof(Linknode));
		if(NULL == p){ return NULL; }
		p->data = value;
		p->next = H;
		r->next = p;
		r = p;
	}
	return H;
}

void show_linklist(Linknode_t H){
	if(NULL == H){
		printf("H is NULL!\n");
		return;
	}
	Linknode_t p = H->next;
	while(p != H){//遍历了一遍，再次找到头结点
		printf("%d\n", p->data);
		p = p->next;
	}
}



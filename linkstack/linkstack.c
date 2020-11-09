#include "linkstack.h"
//有头结点的链栈
Linkstacknode_t create_linkstack(){
	Linkstacknode_t top = NULL;
	top = (Linkstacknode *)malloc(sizeof(Linkstacknode));
	if( NULL == top ){ return NULL; }
	top->data = 0;
	top->next = NULL;
	return top;
}
int is_empty_linkstack(Linkstacknode_t s){	
	if( NULL == s ){ return -1; }
	return ((s->next == NULL)?1:0);
}
int push_linkstack(Linkstacknode_t s, datatype x){
	if( NULL == s ){ return -1; }
	Linkstacknode_t new = NULL;
	new = (Linkstacknode *)malloc(sizeof(Linkstacknode));
	if(NULL == new){ return -1; }
	new->data = x;
	new->next = s->next;
	s->next = new;
	printf("push %d\n", s->next->data);
	return 0;
}
datatype pop_linkstack(Linkstacknode_t s){
	if( (NULL == s) || (is_empty_linkstack(s) == 1) )
	{ return -1; }
	Linkstacknode_t del = NULL;
	del = s->next;
	s->next = del->next;
	datatype ret = del->data;
	printf("pop %d\n", ret);
	free(del); 
	del = NULL;
	return ret;
}
void show_linkstack(Linkstacknode_t s){
	if( NULL == s || (is_empty_linkstack(s) == 1))
	{ return; }
	Linkstacknode_t p = s->next;
	while(p!=NULL){
		printf("%d\n", p->data);
		p = p->next;
	}
}
datatype gettop_linkstack(Linkstacknode_t s){
	return s->next->data;
}
void clear_linkstack(Linkstacknode_t s){
	if( NULL == s)
	{ printf("s is NULL!\n"); return; }
	if(is_empty_linkstack(s) == 1 )
	{ printf("s is empty!\n"); return; }
	Linkstacknode_t del = s->next;
	//del = s; //free_linkstack;
	while(del != NULL){
		s->next = del->next;
		free(del);
		del = s->next;
	}
}

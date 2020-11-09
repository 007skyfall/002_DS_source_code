#include "seqstack.h"

Seqstack_t create_seqstack(int len){
	Seqstack_t s = NULL;
	if( NULL == (s = (Seqstack *)malloc(sizeof(Seqstack)))){ return NULL; }
	s->data = (Sdatatype *)malloc(sizeof(Sdatatype)*len);
	if( NULL == s->data ){
		free(s);
		return NULL;
	}
	s->length = len;
	s->top = -1;
	return s;
}
int is_empty_seqstack(Seqstack_t s){
	if(NULL == s){ return -1;}
	return ((s->top == -1) ? 1: 0);
}
int is_full_seqstack(Seqstack_t s){
	return ((s->top == s->length-1) ? 1 : 0);
}
int  clear_seqstack(Seqstack_t s){	
	if(NULL == s){ return -1;}
	s->top = -1;
	return 0;
}
int free_seqstack(Seqstack_t *s){
	if( NULL == s || NULL == *s ){ return -1;}
	free((*s)->data); (*s)->data = NULL;
	free(*s); *s = NULL;
	return 0;
}
int push_seqstack(Seqstack_t s, Sdatatype x){
	if(is_full_seqstack(s) == 1){ return -1; }
	s->data[s->top+1] = x;
	s->top++;
	//printf("push %d\n", s->data[s->top]);
	return 0;
}
Sdatatype pop_seqstack(Seqstack_t s){	
	if(NULL == s){ return -1;}
	if(is_empty_seqstack(s) == 1){ return -1; }
	Sdatatype ret = 0;
	ret = s->data[s->top];
	s->top--;
	return ret;
}
void show_seqstack(Seqstack_t s){
	int i = s->top;
	while(i >= 0){
		printf("%d\n", s->data[i--]);
	}
}
Sdatatype gettop_seqstack(Seqstack_t s){
	return s->data[s->top];
}

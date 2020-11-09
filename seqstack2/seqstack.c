#include "seqstack.h"


Seqstack_t create_seqstack(int len){
	Seqstack_t s = NULL;
	if( NULL == (s = (Seqstack *)malloc(sizeof(Seqstack)))){ return NULL; }
	s->data = (datatype *)malloc(sizeof(datatype)*len);
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
int push_seqstack(Seqstack_t s, datatype x){
	if(is_full_seqstack == 1){ return -1; }
	s->data[s->top+1] = x;
	s->top++;
	return 0;
}
int pop_seqstack(Seqstack_t s){
//
}

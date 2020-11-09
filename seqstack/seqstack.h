#ifndef __SEQSTACK_H__
#define __SEQSTACK_H__
#include <stdio.h>
#include <stdlib.h>


typedef int datatype;
typedef int postype;
typedef struct seqstack{
	datatype *data;
	int length;
	postype top;
}Seqstack, *Seqstack_t;

Seqstack_t create_seqstack(int len);
int is_empty_seqstack(Seqstack_t s);
int clear_seqstack(Seqstack_t s);
int free_seqstack(Seqstack_t *s);
int push_seqstack(Seqstack_t s, datatype x);
int is_full_seqstack(Seqstack_t s);
int pop_seqstack(Seqstack_t s);
void show_seqstack(Seqstack_t s);
#endif

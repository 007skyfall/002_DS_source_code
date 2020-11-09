#ifndef __SEQSTACK_H__
#define __SEQSTACK_H__
#include <stdio.h>
#include <stdlib.h>
#include "linkqueue.h"

//typedef int datatype;
typedef int Sdatatype;
typedef int postype;
typedef struct seqstack{
	Sdatatype *data;
	int length;
	postype top;
}Seqstack, *Seqstack_t;

Seqstack_t create_seqstack(int len);
int is_empty_seqstack(Seqstack_t s);
int clear_seqstack(Seqstack_t s);
int free_seqstack(Seqstack_t *s);
int push_seqstack(Seqstack_t s, Sdatatype x);
int is_full_seqstack(Seqstack_t s);
Sdatatype pop_seqstack(Seqstack_t s);
void show_seqstack(Seqstack_t s);
Sdatatype gettop_seqstack(Seqstack_t s);

#endif

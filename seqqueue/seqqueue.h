#ifndef __SEQQUEUE_H__
#define __SEQQUEUE_H__

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
typedef int datatype;
typedef struct seqque{
	datatype data[MAXSIZE];
	int front, rear;
}Seqqueue, *Seqqueue_t;

Seqqueue_t create_seqqueue();
int is_full_seqqueue(Seqqueue_t Q);
int in_seqqueue(Seqqueue_t Q, datatype x);
int is_empty_seqqueue(Seqqueue_t Q);
int out_seqqueue(Seqqueue_t Q);
void show_seqqueue(Seqqueue_t Q);
#endif

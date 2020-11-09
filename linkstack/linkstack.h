#ifndef __LINKSTACK_H__
#define __LINKSTACK_H__
#include <stdio.h>
#include <stdlib.h>

typedef int datatype;

typedef struct nodestack{
	datatype data;
	struct nodestack *next;
}Linkstacknode, *Linkstacknode_t;

Linkstacknode_t create_linkstack();
int is_empty_linkstack(Linkstacknode_t s);
int push_linkstack(Linkstacknode_t s, datatype x);
datatype pop_linkstack(Linkstacknode_t s);
void show_linkstack(Linkstacknode_t s);
datatype gettop_linkstack(Linkstacknode_t s);
void clear_linkstack(Linkstacknode_t s);
#endif

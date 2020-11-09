#include "linkstack.h"

int main(int argc, const char *argv[])
{
	Linkstacknode_t ss = NULL;
	ss = create_linkstack();
	int i;
	for(i=0; i<10; i++){
		push_linkstack(ss, i+1);
	}
	show_linkstack(ss);
	puts("-----------------");
	for(i=0; i<10; i++){
		pop_linkstack(ss);
	}
	show_linkstack(ss);
	
	puts("-----------------");
	clear_linkstack(ss);
	show_linkstack(ss);
	
	return 0;
}

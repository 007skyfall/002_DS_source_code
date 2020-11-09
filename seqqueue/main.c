#include "seqqueue.h"

int main(int argc, const char *argv[])
{
	Seqqueue_t Q = NULL;
	Q = create_seqqueue();
	int i;
	for(i = 0; i < 15; i++){
		in_seqqueue(Q, i+1);
	}
	show_seqqueue(Q);
	
	for(i = 0; i < 15; i++){
		out_seqqueue(Q);
	}
	puts("last show:");
	show_seqqueue(Q);

	return 0;
}

#include "seqstack.h"

int main(int argc, const char *argv[])
{
	Seqstack_t s = NULL;
	int n = 0;
	printf("input n:\n");
	scanf("%d", &n);
	s = create_seqstack(n);
	int i;
	for(i = 0; i < 10; i++){
		push_seqstack(s, i+1);
	}
	show_seqstack(s);
	for(i = 0; i < 9; i++){
		pop_seqstack(s);
	}
	show_seqstack(s);
	return 0;
}

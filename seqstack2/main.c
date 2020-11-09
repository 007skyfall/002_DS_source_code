#include "seqstack.h"

int main(int argc, const char *argv[])
{
	Seqstack_t s = NULL;
	int n = 0;
	printf("input n:\n");
	scanf("%d", &n);
	s = create_seqstack(n);
	is( pop_seqstack(s, 10) == 0){	
		printf("suss!\n");
	}

	return 0;
}

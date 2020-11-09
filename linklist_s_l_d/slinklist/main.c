#include "linklist.h"

int main(int argc, const char *argv[])
{
	Linknode_t H = NULL;
	H = create_all_linklist();
	
	show_linklist(H);

	return 0;
}



#include "dlinklist.h"

int main(int argc, const char *argv[])
{
	DLinknode_t H = NULL;
	H = create_dlinklist();
	int i;
	for(i = 0; i<10; i++){
		insert_dlinklist(H, i, 0);
	}
	show_dlinklist(H);
	printf("-----------------");
	delete_dlinklist(H,5);
	show_dlinklist(H);

	return 0;
}



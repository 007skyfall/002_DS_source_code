#include "linklist.h"

int main(int argc, const char *argv[])
{
	Linknode_t H = NULL;
	H = create_linklist();
	int i = 0;
	for(i = 0; i < 10; i++){
		headinsert_linklist(H, i+1);
	}
	printf("------before-----------\n");
	show_linklist(H);
	headdelete_linklist(H);
	printf("------after------------\n");
	show_linklist(H);

	return 0;
}

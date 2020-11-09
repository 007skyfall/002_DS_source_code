#include "linktree.h"
//#include "linkqueue.h"

int main(int argc, const char *argv[])
{
	btreenode_t root = NULL;
	root = create_btree(1, 10);
	
	printf("pre_order:\n");
	pre_order(root);

	printf("\nmin_order\n");
	min_order(root);

	printf("\npost_order:\n");
	post_order(root);
#if 1
	printf("\nlevel_order\n");
	level_order(root);
#endif
	puts("");
	return 0;
}

#include "seqlist.h"
int main(int argc, const char *argv[])
{
	//创建空表
	SeqList *LA = create_seqlist();

	//SeqList *LB = create_seqlist();
#if 0
	//insert_seqlist(L1, 2, 100); error
	insert_seqlist(L1, 0, 100);
#endif
#if 1
	int i;
	for(i = 0; i < 5; i++){
		insert_seqlist(LA, 0, 2);
		insert_seqlist(LA, 0, i);
	}
#endif
	printf("before:\n");
	show_seqlist(LA);
	printf("-------------------\n");
	//show_seqlist(LB);
	//printf("-------------------\n");
#if 0	
	//delete_seqlist(L, 2);
	if(union_seqlist(LA, LB) == -1){
		printf("union_seqlist error!\n");
		return 0;
	}
	printf("after:\n");
	show_seqlist(LA);
	printf("-------------------\n");
	show_seqlist(LB);
	printf("-------------------\n");
	//free_seqlist(&L);
	//printf("test free:\n");
	//show_seqlist(L);
#endif
	printf("after:\n");
	delre_seqlist(LA);
	show_seqlist(LA);

	return 0;
}

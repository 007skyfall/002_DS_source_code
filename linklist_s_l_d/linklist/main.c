#include "linklist.h"

int main(int argc, const char *argv[])
{
	Linknode_t H = NULL;
	H = create_linklist();
	int i = 0;
	for(i = 0; i < 10; i++){
		//headinsert_linklist(H, i+1);
		insert_linklist(H, i+2, 0);
		//按位置插入函数模拟头插法插入数据
	}
	insert_linklist(H, 100, 6);
	printf("------before-----------\n");
	show_linklist(H);
#if 1
	//headdelete_linklist(H);
	delete_linklist(H, 0);
	//按位置删除模拟头删法删除数据
	printf("------after------------\n");
	show_linklist(H);
#endif
#if 0
	Linknode_t p = getnode_linklist(H, 3);
	printf("pos = 3, p->data = %d\n", p->data);
	p = locate_linklist(H, 3);
	printf("value = 3, p = %p, p->data = %d\n", p, p->data);
#endif
	
	return 0;
}



/*哈希表：多个链表的集合*/

#include <stdio.h>
#include <stdlib.h>

#define P 13 			//N=12  N*4/3以内的最大质数

typedef int data_t;
typedef struct node{
	data_t data;
	struct node *next;
}linknode_t;

//创建空的HASH表
linknode_t **linkHASH_create()
{
	int i;
	linknode_t **H = (linknode_t**)malloc( P * sizeof(linknode_t*)); 	//开辟P*4字节的空间,指针数组

	for(i=0; i<P; i++)
	{
		H[i] = (linknode_t*)malloc(sizeof(linknode_t)); //循环开辟P个头节点
		H[i]->next = NULL; 								//头节点的地址段为NULL
	}

	return H;
}

int linkHASH_insert(linknode_t **H, data_t value)
{
	int key = value % P;
	linknode_t *head = H[key]; 				//选择要插入的链表

	linknode_t *node = (linknode_t *)malloc(sizeof(linknode_t));
	node->data = value; 					//开辟空间存储数据

	node->next = head->next; 				//连接
	head->next = node;

	return 0;
}

int linkHASH_show(linknode_t **H)
{
	int i;
	linknode_t *head = NULL;

	for(i=0; i<P; i++)
	{
		head = H[i];
		printf("H[%2d]:",i);

		while(head->next != NULL)
		{
			head = head->next;
			printf("%2d  ",head->data);
		}
		putchar('\n');
	}
	return 0;
}

//有返回1 没有返回0
int linkHASH_serach(linknode_t **H, int value)
{
	linknode_t *head = H[value % P];
	while(head->next != NULL)
	{
		head = head->next;
		if(head->data == value)
		{
			return 1;
		}
	}

	return 0;
}

int main(int argc, const char *argv[])
{
	linknode_t **H = linkHASH_create();
	linkHASH_insert(H, 11);
	linkHASH_insert(H, 12);
	linkHASH_insert(H, 35);
	linkHASH_insert(H, 0);
	linkHASH_insert(H, 56);
	linkHASH_insert(H, 3);
	linkHASH_insert(H, 14);
	linkHASH_insert(H, 27);
	linkHASH_insert(H, 21);
	linkHASH_insert(H, 13);
	linkHASH_insert(H, 12);
	linkHASH_insert(H, 15);
	linkHASH_show(H);
	if(linkHASH_serach(H, 17))
	{
		printf("有\n");
	}
	else
	{
		printf("没有\n");
	}
	
	return 0;
}

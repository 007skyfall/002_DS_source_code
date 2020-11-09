/*线性表的链式存储：链表，每来一个数据开辟一个空间*/
#include <stdio.h>
#include <stdlib.h>

//数据类型
typedef int data_t;
//每一个节点类型
typedef struct node{
	data_t data; 			//存储数据
	struct node *next; 		//存储下一个节点的地址
}linknode_t; 				//类型名

//创建空的链表
//头节点：数据段为空，地址段为NULL,用于做链表结束的标志
linknode_t *linklist_create()
{
	linknode_t *head = NULL;
	head = (linknode_t *)malloc(sizeof(linknode_t)); 	//给头节点开辟空间
	head->next = NULL;

	return head;
}

//增：插入数据在头节的后面
int linklist_insert(linknode_t *head, data_t value)
{
	linknode_t *node = (linknode_t *)malloc(sizeof(linknode_t)); 	//给新节点开辟空间
	node->data = value; 			//新节点的数据段为value

	node->next = head->next; 		//新节点与第一个节点相连
	head->next = node; 				//头节点与新节点相连
	return 0;
}

//增：尾插入法
int linklist_insert_tail(linknode_t *head, data_t value)
{
	linknode_t *node = (linknode_t *)malloc(sizeof(linknode_t)); 	//给新节点开辟空间
	node->data = value;
	node->next = NULL;

	while(head->next != NULL)
	{
		head = head->next; 			//指针head循环向后移动
	} 								//跳出循环时head指向最后一个节点

	head->next = node; 				//最后一个节点与新节点相连
	return 0;
}

//为空返回1 非空返回0
int linklist_is_empty(linknode_t *head)
{
	return head->next == NULL ? 1 : 0;
}

//删：头删除法
int linklist_delete(linknode_t *head)
{
	if(linklist_is_empty(head))
	{
		printf("empty");
		return -1;
	}

	linknode_t *temp = head->next; 	//temp：临时记录第一个节点的地址
	head->next = temp->next;		//head->next = head->next->next; 	
									//将头节点与第二个节点相连
	free(temp); 					//释放第一个节点
	temp = NULL; 					//防止野指针的形成

	return 0;
}

//增：按位置插入
int linklist_insert_pos(linknode_t *head, int pos, data_t value)
{
	if(pos < 1)
	{
		printf("pos error\n");
		return -1;
	}

	int i;
	linknode_t *node = (linknode_t *)malloc(sizeof(linknode_t));
	node->data = value;

	for(i=1; i<pos && head->next != NULL; i++)
	{ 								//head->next != NULL ：当pos过大时数据插在最后一个位置
		head = head->next; 			//指针循环向后移动pos-1次
	} 								//跳出循环后：head指向前一个节点

	node->next = head->next; 		//新节点与后一个节点相连
	head->next = node; 				//前一个节点与新节点相连

	return 0;
}

//增：按顺序插入
int linklist_insert_sort(linknode_t *head, data_t value)
{
	linknode_t *node = (linknode_t *)malloc(sizeof(linknode_t)); 
	node->data = value;

	while(head->next != NULL &&  head->next->data < value) 	//运算不可以调换顺序(短路原则)
	{
		head = head->next; 			//指针向后移动
	} 								//跳出循环时：head指向前一个数据

	node->next = head->next; 		//新节点与后一个节点相连
	head->next = node; 				//前一个节点与新节点相连

	return 0;
}

//改：数据翻转
int linklist_reverse(linknode_t *head)
{
	linknode_t *temp = head->next; 		//temp指向第一个节点，无头的旧链表
	linknode_t *dele = NULL;
	head->next = NULL; 					//head代表新链表的地址

	while(temp != NULL)
	{
		dele = temp; 					//dele临时记录要删除的节点
		temp = temp->next; 				//头删除法

		dele->next = head->next; 		//新节点节点与第一个节点相连
		head->next = dele; 				//头节点与新节点相连
	}

	return 0;
}

//遍历链表
int linklist_show(linknode_t *head)
{
	while(head->next != NULL) 		//判断下一个数据是不是NULL
	{
		head = head->next; 			//指针head循环向后移动
		printf("%d  ",head->data); 	//打印节点的数据段
	}
	putchar('\n');
	return 0;
}

int main(int argc, const char *argv[])
{
	linknode_t *h = linklist_create();
	linklist_insert(h,10);
	linklist_insert(h,20);
	linklist_insert(h,30);
	linklist_insert(h,40);
	linklist_insert(h,50);
	printf("头插入法：");
	linklist_show(h);

	linklist_insert_tail(h,60);
	printf("尾插入法：");
	linklist_show(h);

	linklist_delete(h);
	printf("头删除法：");
	linklist_show(h);

	linklist_insert_pos(h,5,17);
	printf("按位置插：");
	linklist_show(h);

	putchar('\n');
	linknode_t *w = linklist_create();
	linklist_insert_sort(w,32);
	linklist_insert_sort(w,12);
	linklist_insert_sort(w,24);
	linklist_insert_sort(w,28);
	linklist_insert_sort(w,19);
	linklist_insert_sort(w,31);
	linklist_insert_sort(w,14);
	linklist_insert_sort(w,29);
	printf("按顺序插：");
	linklist_show(w); 			//升序排好的链表

	linklist_reverse(w);
	printf("数据翻转：");
	linklist_show(w); 			//降序

	return 0;
}

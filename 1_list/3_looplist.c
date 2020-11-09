/*循环链表*/
#include <stdio.h>
#include <stdlib.h>

typedef int data_t;
typedef struct node{
	data_t data;
	struct node *next;
}linknode_t;

//创建空的链表
linknode_t *linkloop_create()
{
	linknode_t *head = (linknode_t*)malloc(sizeof(linknode_t));
	head->next = head;
	return head;
}

//尾插入
int linkloop_insert_tail(linknode_t *head, data_t value)
{
	linknode_t *temp = head; 	//temp：临时记录头节点的地址
	linknode_t *node = (linknode_t *)malloc(sizeof(linknode_t));
	node->data = value; 		//数据段为value
	node->next = head; 		 	//地址段指向head 

	while(head->next != temp)
	{
		head = head->next; 		//指针head循环向后移动
	} 							//循环结束，head指向最后一个节点

	head->next = node; 			//最后一个节点与新节点相连
	return 0;
}

//遍历
int linkloop_show(linknode_t *head)
{
	linknode_t *temp = head;
	while(head->next != temp) 	
	{
		head = head->next; 		//指针循环向后移动
		printf("%d  ",head->data);//打印数据
	}
	putchar('\n');
	return 0;
}

//砍头函数
linknode_t * linkloop_cut_head(linknode_t *head)
{
	linknode_t *temp = head;
	while(head->next != temp)
	{
		head = head->next; 		//指针循环向后移动
	} 							//跳出循环时head指向最后一个节点
	
	head->next = temp->next; 	//最后一个节点与第一个节点相连
	free(temp); 				//释放头节点的地址
	temp = NULL; 				//防止野指针的形成

	return head->next; 			//把新的头(第一个节点)返回
}

//无头的遍历
int linkloop_show_nohead(linknode_t *head)
{
	linknode_t *temp = head;
	while(head->next != temp)
	{
		printf("%d  ",head->data);
		head = head->next;
	}
	printf("%d\n", head->data);

	return 0;
}



int main(int argc, const char *argv[])
{
	linknode_t *l = linkloop_create();
	linkloop_insert_tail(l, 10);
	linkloop_insert_tail(l, 20);
	linkloop_insert_tail(l, 30);
	linkloop_insert_tail(l, 40);
	linkloop_insert_tail(l, 50);
	linkloop_insert_tail(l, 60);
	linkloop_show(l);

	l = linkloop_cut_head(l);
	linkloop_show_nohead(l);
	
	return 0;
}
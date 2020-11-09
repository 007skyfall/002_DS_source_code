/*链式的队列：先进先出*/
#include <stdio.h>
#include <stdlib.h>

//数据的类型
typedef int data_t;
//节点类型
typedef struct node{
	data_t data; 			//数据段
	struct node *next; 		//记录下一个节点的地址
}linknode_t;
//队列的类型
typedef struct queue{
	linknode_t *front; 		//指向队头(头节点)
	linknode_t *rear; 		//指向队尾(最后一个节点)
}linkqueue_t;

//创建空的队列
linkqueue_t *linkqueue_create()
{
	linknode_t *head = (linknode_t *)malloc(sizeof(linknode_t)); 	//开辟头节点的空间
	head->next = NULL;

	linkqueue_t *queue = (linkqueue_t*)malloc(sizeof(linkqueue_t)); //开辟队列的空间(front与rear的空间)
	queue->front = head;
	queue->rear  = head;

	return queue;
}

//入队(尾插入)
int linkqueue_input(linkqueue_t *queue, data_t value)
{
	linknode_t *node = (linknode_t *)malloc(sizeof(linknode_t)); 	//开辟新节点的空间
	node->data = value;
	node->next = NULL; 

	queue->rear->next = node; 		//最后一个节点与新节点相连
	queue->rear = node; 			//rear永远指向最后一个节点

	return 0;
}

//为空返回1  非空返回0
int linkqueue_is_empty(linkqueue_t *queue)
{
	return queue->front->next == NULL ? 1 : 0;
}

//出队(头删除)
data_t linkqueue_output(linkqueue_t *queue)
{
	if(linkqueue_is_empty(queue))
	{
		printf("empty\n");
		return -1;
	}

	linknode_t *temp = queue->front->next; 	//temp临时记录要删除的节点(第一个节点)
	queue->front->next = temp->next; 		//头节点与第二个节点相连

	if(queue->front->next == NULL)
	{
		queue->rear = queue->front;  		//当数据删除为空时，rear要重新指回头节点
	}

	data_t value = temp->data; 				//记录要删除的数据
	free(temp); 							//释放temp所指向的动态内存空间
	temp = NULL;

	return value;
}

int main(int argc, const char *argv[])
{
	linkqueue_t *q = linkqueue_create();
	linkqueue_input(q,10);
	linkqueue_input(q,20);
	linkqueue_input(q,30);
	linkqueue_input(q,40);
	linkqueue_input(q,50);
	linkqueue_input(q,60);
	printf("%d  ",linkqueue_output(q));
	printf("%d  ",linkqueue_output(q));
	printf("%d  ",linkqueue_output(q));
	printf("%d  ",linkqueue_output(q));
	printf("%d  ",linkqueue_output(q));
	printf("%d  ",linkqueue_output(q));
	putchar(10);
	
	return 0;
}

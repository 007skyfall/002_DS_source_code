#ifndef _QUEUE_H_
#define _QUEUE_H_

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
linkqueue_t *linkqueue_create();
//入队(尾插入)
int linkqueue_input(linkqueue_t *queue, data_t value);
//为空返回1  非空返回0
int linkqueue_is_empty(linkqueue_t *queue);
//出队(头删除)
data_t linkqueue_output(linkqueue_t *queue);

#endif

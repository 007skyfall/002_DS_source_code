/*顺序队列：先进先出*/

#include <stdio.h>
#include <stdlib.h>

#define N 8

typedef int data_t;
typedef struct {
	data_t a[N]; 		//存储数据
	int front; 			//队头的下标
	int rear; 			//队尾的下标
}sqqueue_t;


//创建空的队列
sqqueue_t *sqqueue_create()
{
	sqqueue_t *queue = (sqqueue_t*)malloc(sizeof(sqqueue_t)); 	//开辟队列的空间
	queue->front = 0; 
	queue->rear  = 0; 	//下标值必须相等，代表队列为空

	return queue;
}

//为满返回1 不满返回0
int sqqueue_is_full(sqqueue_t *queue)
{
	return (queue->rear+1) % N == queue->front ? 1 : 0;
}

//为空返回1 非空返回0
int sqqueue_is_empty(sqqueue_t *queue)
{
	return queue->rear == queue->front ? 1 : 0;
}

//入队函数
int sqqueue_input(sqqueue_t *queue, data_t value)
{
	if(sqqueue_is_full(queue))
	{
		printf("full\n");
		return -1;
	}

	queue->a[queue->rear] = value;
	queue->rear = (queue->rear + 1) % N;

	return 0;
}

//出队函数
data_t sqqueue_output(sqqueue_t *queue)
{
	if(sqqueue_is_empty(queue))
	{
		printf("empty\n");
		return -1;
	}

	data_t value = queue->a[queue->front];
	queue->front = (queue->front + 1) % N;

	return value;
}

int main(int argc, const char *argv[])
{
	sqqueue_t *q = sqqueue_create();
	sqqueue_input(q, 10);
	sqqueue_input(q, 20);
	sqqueue_input(q, 30);
	sqqueue_input(q, 40);
	sqqueue_input(q, 50);
	sqqueue_input(q, 60);
	
	printf("%d  ",sqqueue_output(q));
	printf("%d  ",sqqueue_output(q));
	printf("%d  ",sqqueue_output(q));
	printf("%d  ",sqqueue_output(q));
	printf("%d  ",sqqueue_output(q));
	printf("%d  ",sqqueue_output(q));
	putchar('\n');

	
	return 0;
}

#include "2_sqstack.h"
#include "4_linkqueue.h"

#define Ball 27

//验证队列里的顺序,返回1升序，返回0乱序
int sort(linkqueue_t *queue)
{
	int i,x = 0;
	linknode_t *head = queue->front;
	for(i=1; i<=Ball && head->next != NULL; i++)
	{
		head = head->next;
		if(head->data == i)
		{
			x++;
		}
	}
	return x == Ball ? 1 : 0;
}


int ball_fun(linkqueue_t *queue)
{
	sqstack_t *stack1 = sqstack_create();
	sqstack_t *stack5 = sqstack_create();
	sqstack_t *stack6 = sqstack_create();
	int ball_value, sign = 0;
	int time = 0;

	ball_value = linkqueue_output(queue);
	
	while(!sort(queue))
	{
		if(sign)
		{
			ball_value = linkqueue_output(queue); 			//出队列一个球
		}
		sign = 1;
		time++;

		if(sqstack_push(stack1, ball_value, 4) == -1) 	//入1栈
		{
			while(!sqstack_is_empty(stack1)) 		
			{
				linkqueue_input(queue, sqstack_pop(stack1)); //清空1栈入队列
			}

			if(sqstack_push(stack5, ball_value, 11) == -1) 	//入5栈
			{
				while(!sqstack_is_empty(stack5))
				{
					linkqueue_input(queue, sqstack_pop(stack5)); 	//清空5栈入队列
				}

				if(sqstack_push(stack6, ball_value, 11) == -1) 		//入6栈
				{
					while(!sqstack_is_empty(stack6))
					{
						linkqueue_input(queue, sqstack_pop(stack6));
					}

					linkqueue_input(queue, ball_value);
				}
			}
		}
	}
	return time;
}

int main(int argc, const char *argv[])
{
	linkqueue_t *queue = linkqueue_create();
	int i;
	for(i=1; i<=Ball; i++)
	{
		linkqueue_input(queue, i);
	}

	int time = 0;
	time = ball_fun(queue);
	printf("time = %d\n",time);
	printf("time = %d天 %d时 %d分\n",time/60/24, time/60%24, time%60);

//	printf("sort = %d\n",sort(queue));
	
	return 0;
}

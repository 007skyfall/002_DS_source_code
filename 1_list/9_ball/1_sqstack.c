//顺序表实现栈：先进后出
#include "2_sqstack.h"

//开辟结构体空间(空的栈)
sqstack_t * sqstack_create()
{
	sqstack_t* stack = (sqstack_t *)malloc(sizeof(sqstack_t));
	stack->top = -1;

	return stack;
}

//满return 1；不满return 0；
int sqstack_is_full(sqstack_t *stack, int n)
{
	return stack->top == n-1 ? 1 : 0;
}

//空return 1；非空return 0；
int sqstack_is_empty(sqstack_t *stack)
{
	return stack->top == -1 ? 1 : 0;
}

//入栈： 成功returnn 0；已满失败return -1；
int sqstack_push(sqstack_t *stack , data_s value, int n)
{
	if(sqstack_is_full(stack,n))
	{
	//	printf("full\n"); 
		return -1;
	}
	stack->top++;
	stack->a[stack->top] = value;

	return 0;
}

//出栈： 成功return value；已空失败return -1；
data_s sqstack_pop(sqstack_t *stack)
{
	if(sqstack_is_empty(stack))
	{
	//	puts("empty");
		return -1;
	}

	data_s value = 0;
	value = stack->a[stack->top];
	stack->top--;
	
	return value;
}



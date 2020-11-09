#ifndef _STATCK_H_
#define _STATCK_H_

//函数的声明 头文件的包含 宏 全局变量 类型的定义
#include <stdio.h>
#include <stdlib.h>

#define N 11

typedef int data_s; 	

typedef struct {
	data_s a[N]; 		
	int top; 				//栈顶 ----> last
}sqstack_t; 				


//开辟结构体空间(空的栈)
sqstack_t * sqstack_create();
//满return 1；不满return 0；
int sqstack_is_full(sqstack_t *stack, int n);
//空return 1；非空return 0；
int sqstack_is_empty(sqstack_t *stack);
//入栈： 成功returnn 0；已满失败return -1；
int sqstack_push(sqstack_t *stack , data_s value, int n);
//出栈： 成功return value；已空失败return -1；
data_s sqstack_pop(sqstack_t *stack);

#endif

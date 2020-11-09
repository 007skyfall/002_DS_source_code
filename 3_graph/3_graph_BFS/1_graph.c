/*图：邻接矩阵法*/
#include <stdio.h>
#include <stdlib.h>
#include "3_linkqueue.h"

#define N 9
//数据类型
typedef int data_t;
//图的类型
typedef struct{
	data_t a[N]; 		//存储数据
	int matrix[N][N]; 	//存储顶点之间的关系
	int sign[N];
}graph_t;

//创建没有关系的图
graph_t *graph_create()
{
	int i;
	graph_t *g = (graph_t*)malloc(sizeof(graph_t)); 	//开辟图的空间
	for(i=0; i<N; i++) 		//存储数据
	{
		g->a[i] = 2*i+1;
	}

	return g;
}

//输入无向图的关系
int graph_input(graph_t *g)
{
	int i,j;
	printf("(Vi,Vj)\n");
	while(scanf("(V%d,V%d)",&i, &j) == 2)
	{
		getchar(); 					//吃掉垃圾字符 ‘\n’
		g->matrix[i][j] = 1;
		g->matrix[j][i] = 1;
	}

	return 0;
}

//广度优先搜索(入队标记 出队访问)
int graph_BFS(int v, graph_t *g)
{
	linkqueue_t *queue = linkqueue_create();
	linkqueue_input(queue, v);
	g->sign[v] = 1;
	int i;

	while(!linkqueue_is_empty(queue))
	{
		v = linkqueue_output(queue);
		printf("V%d : %d\n",v, g->a[v]);

		for(i=0; i<N; i++)
		{
			if(g->matrix[v][i] == 1 && g->sign[i] == 0)
			{
				linkqueue_input(queue, i);
				g->sign[i] = 1;
			}
		}
	}
	return 0;
}


int main(int argc, const char *argv[])
{
	graph_t *g = graph_create();
	graph_input(g);
	graph_BFS(0,g);
	
	return 0;
}

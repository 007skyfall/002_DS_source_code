/*图：邻接矩阵法*/
#include <stdio.h>
#include <stdlib.h>

#define N 9

//数据类型
typedef int data_t;
//图的类型
typedef struct{
	data_t a[N]; 		//存储数据
	int matrix[N][N]; 	//存储顶点之间的关系
	int sign[N]; 		//标记位
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

//找下一个邻接点
int graph_find_next(int v, graph_t *g)
{
	int i;
	for(i=0; i<N; i++)
	{
		if(g->matrix[v][i] == 1 && g->sign[i] == 0) 		//找没有被访问过的邻接点
		{
			return i;
		}
	}

	return -1;
}

//深度优先搜索
int graph_DFS(int v, graph_t *g)
{
	printf("V%d ：%d\n",v, g->a[v]); 	//访问数据
	g->sign[v] = 1; 					//标记位置
	int i;

	i = graph_find_next(v,g); 			//返回1
	while(i >= 0)
	{
		graph_DFS(i,g); 				//访问1、2、3
		i = graph_find_next(v,g);   	//返回2
	}

	return 0;
}


int main(int argc, const char *argv[])
{
	graph_t *g = graph_create();
	graph_input(g);
	graph_DFS(0,g);
	
	return 0;
}

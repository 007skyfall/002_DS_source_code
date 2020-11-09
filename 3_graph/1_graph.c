/*图：邻接矩阵法*/
#include <stdio.h>
#include <stdlib.h>

#define N 5
//数据类型
typedef int data_t;
//图的类型
typedef struct{
	data_t a[N]; 		//存储数据
	int matrix[N][N]; 	//存储顶点之间的关系
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

//输出无向图的关系
int graph_output(graph_t *g)
{
	int i,j;
	printf("  V0 V1 V2 V3 V4\n");
	for(i=0; i<N; i++)
	{
		printf("V%d",i);

		for(j=0; j<N; j++)
		{
			printf(" %d ",g->matrix[i][j]);
		}
		putchar('\n');
	}
	return 0;
}


int main(int argc, const char *argv[])
{
	graph_t *g = graph_create();
	graph_input(g);
	graph_output(g);
	
	return 0;
}

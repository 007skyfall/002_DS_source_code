#include "graph.h"

adjmatrix_t *CreateGraph()
{
	adjmatrix_t *g = (adjmatrix_t *)malloc(sizeof(adjmatrix_t));
	int i, j, n;
	char ch;
	i = n = 0;
	printf("input the V:");
	while((ch = getchar()) != '#')
	{
		n++;
		if(n > MAXN - 1) n = MAXN-1;//溢出处理
		g->vertex[i++] = ch;
	}

	while(getchar() != '\n');
	
	bzero(g->relation, sizeof(g->relation));
	printf("input the edge:\n");
	while(scanf("V%d V%d", &i, &j) == 2)
	{
		if(i < 0 || i >= MAXN || j < 0 || j >= MAXN)
			break;
		g->relation[i][j] = 1;
		g->relation[j][i] = 1;
		getchar();
	}
	for(i =0; i<n; i++)
	{
		for(j=0;j<n;j++){
			printf("%3d",g->relation[i][j]);
		}
		putchar(10);
	}
	return g;
}
//获得顶点的下标
int LocateVex(adjmatrix_t *g, char v)
{
	int i;
	for(i = 0; i < MAXN; i++)
	{
		if(g->vertex[i] == v)
			return i;
	}

	return -1;
}

int FirstAdj(adjmatrix_t *g,int v)
{
	int i;
	
	for(i = 0; i < MAXN; i++)
	{
		if(g->relation[v][i] == 1)
			return i;
	}

	return -1;
}
int NextAdj(adjmatrix_t *g, int v, int u)
{
	int  i;

	for(i = u + 1; i < MAXN; i++)
	{
		if(g->relation[v][i] == 1)
			return i;
	}
	return -1;
}
void DFS(adjmatrix_t *g, int v, int visited[])
{
	int u;

	printf("%c ", g->vertex[v]);
	visited[v] = 1;
	u = FirstAdj(g, v);
	while(u != -1)
	{
		if(visited[u] == 0)
			DFS(g, u, visited);
		u = NextAdj(g, v, u);
	}

	return;
}
#if 1
void BFS(adjmatrix_t *g, int v, int visited[])
{
	int  u;
	Linkque_t lq;
	//初始化队列	
	create_linkque(&lq);
	//入队第一个结点
	in_linkque(lq, v);
	printf("%c ", g->vertex[v]);
	while(is_empty_linkque(lq) != 0)
	{
		//队列不为空出队给v
		v = out_linkque(lq);
		//用v访问结点判断需不需要继续访问后继
#if 0
		if(visited[v] == 1)
			continue;
		printf("%c ", g->vertex[v]);
		visited[v] = 1;
		
#endif
		//取第一邻接点序号
		u = FirstAdj(g, v);
		while(u != -1)
		{   //若u没有访问，入队
			if(visited[u] == 0){
				printf("%c ", g->vertex[v]);
				visited[v] = 1;
				in_linkque(lq, u); 
			}
			//取v关于u的下一邻接点
			u = NextAdj(g, v, u);
		}
	}
}
#endif


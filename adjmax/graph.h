#ifndef __GRAPH_H__
#define __GRAPH_H__
#define MAXN 64

#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
#include "linkqueue.h"

typedef struct {
	char vertex[MAXN];
	int relation[MAXN][MAXN];
}adjmatrix_t;
//创建图
extern adjmatrix_t *CreateGraph();
//获得顶点的下标
extern int LocateVex(adjmatrix_t *g, char v);
extern void DFS(adjmatrix_t *g, int v, int visited[]);
extern void BFS(adjmatrix_t *g, int v, int visited[]);

#endif

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main(int argc, const char *argv[])
{
	int visited[MAXN] = {0};
	adjmatrix_t *g = CreateGraph();
	printf("\nDFS : ");
	DFS(g, 0, visited);
	putchar(10);
#if 1
	bzero(visited, sizeof(visited));
	printf("\nBFS : ");
	BFS(g, 0, visited);
	free(g);
#endif
	return 0;
}

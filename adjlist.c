#include <stdio.h>
#include <stdlib.h>

#define N 5
//无向图
typedef struct node_t
{
	int vertex;
	struct node_t *next;
} linknode_t, *linklist_t;

void AddEdge(linklist_t h, int vertex)
{
	linklist_t p;

	while ((h->next != NULL) && (h->next->vertex < vertex)) h = h->next;
	p = (linklist_t)malloc(sizeof(linknode_t));
	p->vertex = vertex;
	p->next = h->next;
	h->next = p;

	return;
}

int FirstAdj(linknode_t s[], int v)
{
	return s[v].next->vertex;
}

int NextAdj(linknode_t s[], int v, int u)
{
	linklist_t p;

	p = s[v].next;
	while (p->vertex != u) p = p->next;
	p = p->next;

	return (p == NULL ? -1 : p->vertex);
}

int main()
{
	linknode_t s[N] = {{0, NULL}};
	int i, j;
	linklist_t p;

	while(1)
	{
		scanf("%d,%d", &i, &j);
		if (i == j) break;
		AddEdge(s+i, j);
		AddEdge(s+j, i);
	}

	for (i=0; i<N; i++)
	{
		printf("V%d : ", i);
		p = s[i].next;
		while (p != NULL)
		{
			printf("V%d ", p->vertex);
			p = p->next;
		}
		printf("\n");
	}
	
	return 0;
}

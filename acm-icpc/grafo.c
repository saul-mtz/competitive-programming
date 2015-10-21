#include <stdio.h>

#define MAXV            100           /* maximum number of vertices */
#define MAXDEGREE       50            /* maximum vertex outdegree */

bool processed[MAXV];  /* which vertices have been processed */
bool discovered[MAXV]; /* which vertices have been found */
int parent[MAXV]; /* discovery relation */


typedef struct {
        int edges[MAXV+1][MAXDEGREE]; /* adjacency info */
        int degree[MAXV+1];           /* outdegree of each vertex */
        int nvertices;                /* number of vertices in graph */
        int nedges;                   /* number of edges in graph */
} graph;

read_graph(graph *g, bool directed)
{
        int i;                          /* counter */
        int m;                          /* number of edges */
        int x, y;                       /* vertices in edge (x,y) */
        initialize_graph(g);
        scanf("%d %d",&(g->nvertices),&m);
        for (i=1; i<=m; i++) {
                scanf("%d %d",&x,&y);
                insert_edge(g,x,y,directed);
        }
}


initialize_graph(graph *g)
{
        int i;                          /* counter */
        g -> nvertices = 0;
        g -> nedges = 0;
        for (i=1; i<=MAXV; i++) g->degree[i] = 0;
}

insert_edge(graph *g, int x, int y, bool directed)
{
        if (g->degree[x] > MAXDEGREE)
             printf("Warning: insertion(%d,%d) exceeds max degree\n",x,y);
        g->edges[x][g->degree[x]] = y;
        g->degree[x] ++;
        if (directed == FALSE)
                 insert_edge(g,y,x,TRUE);
        else
                 g->nedges ++;
}

print_graph(graph *g)
{
        int i,j;                        /* counters */
        for (i=1; i<=g->nvertices; i++) {
                printf("%d: ",i);
                for (j=0; j<g->degree[i]; j++)
                        printf(" %d",g->edges[i][j]);
                printf("\n");
        }
}

bfs(graph *g, int start)
{
        queue q;                         /* queue of vertices to visit */
        int v;                           /* current vertex */
        int i;                           /* counter */
        init_queue(&q);
        enqueue(&q,start);
        discovered[start] = TRUE;
        while (empty(&q) == FALSE) {
                v = dequeue(&q);
                process_vertex(v);
                processed[v] = TRUE;
                for (i=0; i<g->degree[v]; i++)
                    if (valid_edge(g->edges[v][i]) == TRUE) {
                         if (discovered[g->edges[v][i]] == FALSE) {
                                 enqueue(&q,g->edges[v][i]);
                                 discovered[g->edges[v][i]] = TRUE;
                                 parent[g->edges[v][i]] = v;
                         }
                         if (processed[g->edges[v][i]] == FALSE)
                                 process_edge(v,g->edges[v][i]);
                    }
        }
}

initialize_search(graph *g)
{
        int i;                          /* counter */
        for (i=1; i<=g->nvertices; i++) {
                processed[i] = discovered[i] = FALSE;
                parent[i] = -1;
        }
}

int main()
{
	puts("madre mia!!!");
	return 0;
}


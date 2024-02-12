#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
/*
typedef struct
{
    int V, E; //nr. varfuri si muchii
    int ** a; //matricea de adiacenta
} Graph;
*/

struct ListNode
{
    int vertex_no; //informatia utila = numarul varfului de stocat
    struct ListNode* next;
};
typedef struct ListNode Node;

typedef struct
{
    int V, E;
    Node** a; //vector pentru capetele de liste – lungime V
} Graph;

int printSolution(int dist[], int n)
{
    printf("Varf Distanta fata de sursa \n");
    for (int i = 0; i < n; i++)
        printf("%d %d\n", i, dist[i]);
}

int minDistance(int dist[], int sps[], int V)
{
    int v, min = INT_MAX, min_index;
    for ( v = 0; v < V; v++)
        if (sps[v] == 0 && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    return min_index;
}
void dijkstra(Graph *g, int s )
{
    int i, j, u;
    int dist[g->V];
    int sps[g->V];
    for ( i = 0; i < g->V; i++)
    {
        dist[i] = INT_MAX;
        sps[i] = 0;
    }
    dist[s] = 0;
    for (j = 0; j < g->V-1; j++)
    {
        u = minDistance(dist, sps, g->V);
        printf("%d\n",u);
        sps[u] = 1;
        for (i = 0; i < g->V; i++)
        {
            /* if (sps[i] == 0 && g->a[u][i]!=0 &&
                     dist[u] != INT_MAX && dist[u]+g->a[u][i] < dist[i])
                 dist[i] = dist[u] + g->a[u][i];*/

            if (sps[i] == 0 && g->a[u][i].vertex_no!=0 &&
                    dist[u] != INT_MAX && dist[u]+g->a[u][i].vertex_no < dist[i])
                dist[i] = dist[u] + g->a[u][i].vertex_no;
        }
    }
    printSolution(dist, g->V);
} ///Complexitatea O(VxE) pentru reprezentarea cu lista de adiacenta

Graph * alocGraph (int val)  // functie pentru alocat spatiu pentru un graf,
{
    int i,j ; // fara initializare ponderi
    Graph *g =(Graph*) malloc(sizeof(Graph));
    if (g==NULL) return NULL;
    (g->V)=val;
    g->a = (int**)malloc(sizeof(int*)*g->V);
    for (i=0; i<g->V; i++)
        g->a[i]=(int*)calloc(g->V,sizeof(int));
    return g;
}

void printGraph(Graph *g)
{
    int i, j;

    for (i=0; i<g->V; i++)
    {
        for (j=0; j<g->V; j++)
            printf( " %d ",g->a[i][j]);
        printf("\n");
    }
}

/*
void printGraph(Graph *g)
{
    int i, j;
    for (i=0; i<g->V; i++)
    {
        while (g->a[i]!=NULL)
        {
            printf( "%d ",g->a[i]->vertex_no);
            g->a[i] = g->a[i]->next;
        }
        printf("\n");
    }
}
*/

int BF(Graph*g, int s)
{
    int i, j, k,m;
    int dist[g->V];
    int pred[g->V];

    for ( i = 0; i < g->V; i++)
    {
        dist[i] = INT_MAX;
        pred[i]=-1;
    }
    dist[s]=0;

    for (i = 0; i < g->V -1 ; i++)
        for (j = 0; j < g->V ; j++)
            for (k = 0; k< g->V ; k++)
                if (g->a[j][k].vertex_no!=0 && dist[k] >dist[j]+g->a[j][k].vertex_no)
                {
                    dist[k] =dist[j]+g->a[j][k].vertex_no;
                    pred[k]=j;
                }

    printf("\n ");
    for ( m = 0; m < g->V; m++) printf("%d ",pred[m]);
    printf("\n ");
    for ( m = 0; m < g->V; m++) printf("%d ",dist[m]);

    for (j = 0; j < g->V ; j++)
        for (k = 0; k< g->V ; k++)
            if (g->a[j][k].vertex_no!=0 &&dist[k] >dist[j]+g->a[j][k].vertex_no)
                return 0;
    return 1;
}


int main()
{
    int i,j,v,w;
    int graph[9][9] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };

    Graph *g = alocGraph(9);

    for ( v = 0; v < g->V; v++)
        for ( w = 0; w < g->V; w++)
            g->a[v][w].vertex_no = graph[v][w];

    printGraph(g);
    dijkstra(g,0);
    BF(g,0);

    return 0;
}

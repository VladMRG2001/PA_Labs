#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct
{
    int V; //nr. varfuri
    int E; //nr. muchii
    int ** a; //double – daca vrem sa stocam ponderile, iar acestea nu sunt intregi
// int a[V][V]; //sau asa daca stiu ca nu se modifica numarul de varfuri
} Graph;

Graph * create ()  // functia aloca spatiu pentru un graf si il initializeaza cu valori
{
    int i, j, orientat; //Tema: Modificati functia astfel incat sa citeasca date dintr-un fisier
    Graph *g = (Graph *) malloc (sizeof(Graph));
    if (g==NULL)
    {
        printf ( " no memory for this graph");
        return NULL;
    }
    printf("Cate varfuri are ?");
    scanf (" %d", &(g->V));
    g->a = (int **) malloc(g->V*sizeof(int*));
    for (i=0; i<g->V; i++) g->a[i] = (int *) calloc(g->V, sizeof(int)); //o initializez cu 0
    if (g->a==NULL)
    {
        printf ( " no memory for this matrix");
        return NULL;
    }
    g->E = 0;
    printf("E orientat? 0 - da, altfel – nu este");
    scanf (" %d", &orientat);
    if (orientat!=0)  //daca nu e orientat => matricea a este simetrica
    {
        for (i=0; i<g->V; i++)
            for (j=0; j<i; j++)
            {
                printf( "Exista arc de la %d la %d?\n", i, j);
                scanf ("%d", &g->a[i][j]);
                g->a[j][i]=g->a[i][j];
                if(g->a[i][j]!=0) g->E+=2;
            }
    }
    else     //este orientat
    {
        for (i=0; i<g->V; i++)
            for (j=0; j<g->V; j++)
            {
                printf( "Exista arc de la %d la %d?\n",i,j);
                scanf ("%d", &g->a[i][j]);
                if(g->a[i][j]!=0) g->E++;
            }
    }
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
//am afisat matricea de adiacenta linie cu linie
}

void Destroy(Graph *g)
{
    int i,j;
    for(i=0; i<g->V; i++)
        for(j=0; j<g->V; j++)
            free(g->a[i][j]);
}

void matrix2list(Graph *g)
{
    printf("Lista de adiacenta: \n");
    int i,j;
    for(i=0; i<g->V; i++)
    {
        printf(" %d ",i);
        for(j=0; j<g->V; j++)
        {
            if(g->a[i][j]==1) printf (" %d ",j);
        }
        printf("\n");
    }
}

void existenta_muchie(Graph *g, int n1, int n2)
{
    //int i,j;
    //for(i=0; i<g->V; i++)
    //for(j=0; j<g->V; j++)
    if(g->a[n1][n2]==1) printf("Exista nod de la %d la %d\n",n1,n2);
}

void incidenta(Graph *g, int n)
{
    printf("Muchii incidente in %d: \n",n);
    int i,j;
    for(i=0; i<g->V; i++)
        if(g->a[i][n]) printf("muchia %d-%d  ",i,n);
    for(j=0; j<g->V; j++)
        if(g->a[n][j]) printf("muchia %d-%d  ",n,j);

    printf("\n\n");
}

Graph R_W(Graph *g)
{
    int D[10][10];
    int i,j,k;
    for(i=0; i<g->V; i++)
        for(j=0; j<g->V; j++)
            D[i][j]=g->a[i][j];

    for (i=0; i<g->V; i++)
    {
        for (j=0; j<g->V; j++)
            printf( " %d ",D[i][j]);
        printf("\n");
    }

    for(k=0; k<g->V; k++)
        for(i=0; i<g->V; i++)
            for(j=0; j<g->V; j++)
        {
            if(i!=j && D[i][j]==0 && g->a[i][k]==1 && g->a[k][j]==1)
                D[i][j]==1;
        }

    printf("\n");

    for (i=0; i<g->V; i++)
    {
        for (j=0; j<g->V; j++)
            printf( " %d ",D[i][j]);
        printf("\n");
    }
}

int main()
{
    Graph *g = create();
    printGraph(g);
    matrix2list(g);
    existenta_muchie(g,1,2);
    incidenta(g,0);
    R_W(g);
    //Destroy(g);
    return 0;
}

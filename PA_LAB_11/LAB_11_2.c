#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

Graph * create ()  // creare graf folosind liste de adiacenta
{
    int i, j, next,val;
    Graph *g = (Graph *) malloc (sizeof(Graph));
    if (g==NULL)
    {
        printf ( " no memory for this graph");
        return NULL;
    }
    printf("Cate varfuri are ?");
    scanf (" %d", &(g->V));
    g->a=(Node**)malloc(g->V * sizeof(Node*));
    for (i=0; i<g->V; i++)
    {
        printf( "Dati nr varfului stocat ca si capat de lista pe pozitia %d \n",i);
        scanf("%d",&val);
        Node * newnode=(Node*)malloc(sizeof(Node));
        newnode->vertex_no =val;
        newnode->next=NULL;
        g->a[i]=newnode;
    }
    g->E = 0;
    for (i=0; i<g->V; i++)
    {
        printf( "dati varfurile care urmeaza dupa %d \n",g->a[i]->vertex_no );
        next=0;
        Node*p = g->a[i]; // stochez adresa in p pentru ca nu vreau sa o modific
        while (next==0)   //adaug varfuri in lista
        {
            printf( "exista varf urmator? da=0, nu- altceva");
            scanf(" %d", &next);
            if (next ==0)
            {
                printf( "care e varful urmator ?\n");
                scanf ("%d", &val);
                Node * newnode=(Node*)malloc(sizeof(Node));
                newnode->vertex_no =val;
                newnode->next=NULL;
                p->next = newnode; //adaug varful
                p = p->next ; //ma pozitionez la finalul listei
                g->E++; //cresc numarul de muchii
            }
        }
    }
    return g;
}

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

void Destroy(Graph *g)
{
    int i,j;
    for(i=0; i<g->V; i++)
        for(j=0; j<g->V; j++)
            free(g);
}

int main()
{
    Graph *g = create();
    printGraph(g);
    Destroy(g);
    return;
}

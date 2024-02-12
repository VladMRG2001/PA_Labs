#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "min_heap.h"

///1
Heap * create (int capacitate /*, int heap_type*/)  // se da capacitatea (eventual si tipul)
{
    Heap * h = (Heap *) malloc (sizeof(Heap));
    if (h == NULL)
    {
        printf("Nu s-a putut aloca spatiu");
        return NULL;
    };
    h->size = 0; //initial SD e goala; as putea sa pornesc de la -1
    h->capacity = capacitate;
    h->vec = (Data*) malloc(sizeof(Data)*h->capacity);
    if (h->vec == NULL)
    {
        printf("Nu s-a putut aloca spatiu");
        return;
    };
    return h;
}

///2
void resize(Heap *h)
{
    Data * v=(Data * )realloc( h->vec, h->capacity=7);  // nu vreau sa pierd vec in caz de
    if (v == NULL)
    {
        printf ( "out-of-memory");    // out-of-memory
        return ;
    }
    if (h->vec!=NULL) free(h->vec);
    h->vec=v;
}

///3
void delete (Heap**h)
{
    if (*h==NULL) return;
    if ((*h)->vec!=NULL) free((*h)->vec);
    free(*h );
    *h=NULL;
}

///4
void printHeap(Heap *h)
{
    int i;
    for (i=0; i<h->size; i++) printf("%d ",h->vec[i]);
    printf("\n");
}

///5
int parent(Heap *h, int i)
{
    if (i>h->size - 1 || i<=0) // 0 e radacina
        return -1; //nu are parinte
    return (i-1)/2; // se rotunjeste inferior
}

int leftChild(Heap *h,int i)
{
    int poz = 2*i+1;
    if (poz > h->size -1 || i<0)
        return -1; // nu are copil stg
    return poz;
}

int rightChild(Heap *h,int i)
{
    int poz = 2*i+2;
    if (poz > h->size-1 || i<0)
        return -1; // nu are copil dr
    return poz;
}

///6
Data min(Heap *h)
{
    if (h->size==0)
        return INT_MIN; //constanta definita
    int min,i;
    min=h->vec[0];
    for(i=1; i<h->size; i++)
    {
        if(min>h->vec[i])
            min=h->vec[i];
    }
    return min;
}

///7
void heapify_down(Heap *h, int i)  // percolate _down
{
    int l, r, max=i, aux;
    l= leftChild(h,i); //pozitia copilului stang al lui i
    r= rightChild(h,i); //pozitia copilului drept al lui i
    if(l==-1 && r==-1) return; //daca e frunza -> am terminat
    if (l!=-1 && h->vec[l]> h->vec[max]) max = l; //in max stochez i sau l
    if (r!=-1 && h->vec[r]> h->vec[max]) max = r;
//in max stochez pozitia copilului cu valoare mai mare (daca e cazul)
//interschimb elementele
    if(max!=i)  //proprietatea de heap nu e respectata
    {
//repet procesul pentru toate nodurile de sub cel cu indice i
        aux=h->vec[i];
        h->vec[i]=h->vec[max];
        h->vec[max]=aux;
        heapify_down(h,max);
    }
//altfel ->am terminat, prop. heap e respectata
}

///8
void heapify_up(Heap *h, int i)
{

}

///9
void insert (Heap *h, Data x)
{
    int i;
    if (h->size==h->capacity) resize(h); // nu am loc pentru noul nod asa ca realoc spatiul pt vec
    i=h->size; // pozitia ultimului nod adaugat (size incepe de la 0)
    h->size++; //cresc nr. de elemente pt. ca am mai adaug un nod
//percolate _up/heapify_up
    while ( i > 0 && x < h->vec[(i-1)/2])  // compar x cu informatia din parintele sau
    {
        h->vec[i] = h->vec[(i-1)/2]; // mut datele parintelui in locul datelor copilului
        i=(i-1)/2; // modific pozitia pe care se afla nodul cu valoarea x
    } //pana gasesc pozitia sa finala in vector
    h->vec[i] = x; // am gasit pozitia finala, stochez valoarea
}

///10
void deleteRoot(Heap *h, int n)
{
    int lastElement = h->vec[n - 1];
    h->vec[0] = lastElement;
    n = n - 1;
    heapify_down(h, 0);

}

///11
void heapsort(Heap *h, Data *buf, int n)  // vectorul de sortat e in buf si are n elemente
{
    if (h==NULL || buf==NULL ||n==0) return;
    while ( n > h->capacity) resize(h);
//populez heapul cu valorile din vectorul de sortat
    for (int i=0; i<n; i++) h->vec[i]=buf[i];
    h->size = n;
    for (int i=(n-1)/2-1; i>=0; i--)
        heapify_down (h,i); // heapify pentru toate nodurile interne O(n)
//extrag pe rand elementele din heap - mereu max si le stochez in ordine crescatoare
    for (int i=n-1; i>=0; i--)  //in h->vec; as putea sa le pun in buf
    {
        int aux = h->vec[0];
        h->vec[0]=h->vec[i];
        h->vec[i]=aux; //am pus max pe ultima pozitie si in locul lui un element de la
        h->size = i; //final de heap pe care aplic heapify down
        heapify_down(h,0);
    }
//O(nlogn)
    h->size = n;
    printHeap(h);
}

void populateHeap ( Heap * h, Data *buf, int n)  //creare heap dintr-un vector - buf cu n valori
{
    if (h==NULL || buf==NULL ||n==0) return;
    while ( n > h->capacity)
        resize(h); // dublez capacitatea si realoc spatiu pana cand am suficient pentru a stoca n valori
    for (int i=0; i<n; i++)
        h->vec[i]=buf[i]; //copiez valorile din buf in heapul h
    h->size = n;
    for (int i=(n-1)/2; i>=0; i--) // heapify pentru toate nodurile interne
        heapify_down(h,i); //complexitatea functiei heapify depinde de inaltimea nodului - O(h)
}

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "min_heap.h"
#include "min_heap.c"

int main()
{
    int i=0,capacity=12;
    //printf("Capacitatea heap-ului este: ");
    //scanf("%d",&capacity);

    ///1
    Heap *h=create(capacity);

    ///9
    printf("Adaugati elementele: ");
    while (i>-1)
    {
        scanf("%d",&i);
        if (i>-1)
            insert(h,i);
    }
    printf("Termenii sunt: ");

    ///4
    printHeap(h);

    ///7
    heapify_down(h, 3);

    ///8
    heapify_up(h, 3);

    ///5
    printf("\n%d ", h->vec[ parent(h,3)]);
    printf("\n%d ", h->vec[leftChild(h,1)]);
    printf("\n%d ", h->vec[rightChild(h,1)]);

    ///6
    printf("\nMinimul este %d\n", min(h) );

    ///11
    int buf[20]={12,54,34,65,11,23,99,45};
    printf("Heapsort pt buf: ");
    heapsort(h, buf, 8);

    ///10
    printf("Eliminare radacina: ");
    deleteRoot(h, capacity);
    printHeap(h);

    ///2
    resize(h);

    ///3
    delete(h);

    Heap *hh=create(8);
    int buff[20]={11,76,34,87,22,99,12,92};
    int nn=8;
    //Data *buff = (int *)malloc(nn*sizeof(Data));
    populateHeap(hh, buff, nn);
    printf("Creare heap din vectorul buff: ");
    printHeap(hh);

    ///5 bis
    printf("\n%d ", hh->vec[ parent(hh,3)]);
    printf("\n%d ", hh->vec[leftChild(hh,2)]);
    printf("\n%d ", hh->vec[rightChild(hh,2)]);

    return 0;
}

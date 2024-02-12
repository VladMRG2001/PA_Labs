#include <stdlib.h>
#include <stdio.h>

///CountingSort

void countingSort(int v[], int n)
{
    int vf[11];
    for (int i=0;i<10;i++)
    {
        vf[i]=0;
    }

    for (int i=0;i<n;i++)
    {
        vf[v[i]]++;
    }

    printf("Vectorul vf: ");

    for (int i=0;i<10;i++)
    {
        printf("vf[%d]=%d ",i, vf[i]);
    }
    printf("\n");

    printf("Vectorul sortat: ");

    for(int i=0;i<10;i++)
        {
            for(int j=0;j<vf[i];j++)
            printf("%d ", i);
        }
}

int main()
{
    int v[] = {8,0,5,7,3,0,9,3};
    int n = sizeof(v)/sizeof(v[0]);
    printf("Numarul de elemente: %d \n", n);
    countingSort(v,n);

    return 0;
}

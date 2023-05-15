#include <stdio.h>
#include <stdlib.h>

int citire(int *v)
{int i=0;
    while(1)
    {
        printf("Scrie numarul %d: ", i);
        scanf("%d", &v[i]);
        if(v[i] == -1)
            {
                break;
            }
            else i++;
    }
    return i;
}

void afisare(int *v,int n)
{
    printf("%d ", v[n]);
    if(n<1) exit(0);
    afisare(v,n-1);
}

int main()
{
    int i=0;
    int v[100];
    i=citire(v);
    printf("Sunt %d numere \n",i);
    printf("Afisare inversa: ");
    afisare(v,i);
}

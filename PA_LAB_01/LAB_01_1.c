#include <stdlib.h>
#include <stdio.h>

//1.
int *alocare(int nr)
{
	int *v;
	v= (int*)calloc(nr, sizeof(int));
	if (v == NULL)
	{
        printf("Eroare");
        exit(-1);
	}
	if (v != NULL) printf("Alocare reusita \n");
	return v;
}

void citire(int *v, int n)
{
	for(int i=0;i<n;i++)
	{
		printf("v[%d] = ", i);
		scanf("%d", &v[i]);
	}
}

void sortare(int *v, int n)
{
	int aux;
 	for(int i=0; i<n; i++)
 		for(int j = i; j < n; j++)
 			if(v[i] > v[j])
 			{
 				aux = v[i];
 				v[i] = v[j];
				 v[j] = aux;
			}
}

void afisare(int *v, int n)
{
	for(int i=0;i<n;i++)
	printf("v[%d] = %d\n", i,v[i]);
}

int main()
{
	int *v;
	int n;
	printf("Numarul de termeni este ");
	scanf("%d", &n);
	v=alocare(n);
	citire(v,n);
	sortare(v,n);
	printf("Vectorul sortat este: \n");
	afisare(v,n);
	if (v!=NULL) free(v);
	v=NULL;
}



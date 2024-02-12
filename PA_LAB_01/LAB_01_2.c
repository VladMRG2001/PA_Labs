#include <stdlib.h>
#include <stdio.h>

//2
int **alocare(int l,int c)
{
	int **matr;
	int i;
	matr = (int**)malloc(l*sizeof(int*));
	for (i=0; i<l; i++)
	matr[i] = (int*)malloc(c*sizeof(int));
	if (matr == NULL)
	{
        printf("Eroare");
        exit(-1);
	}
	if (matr != NULL) printf("Alocare reusita \n");
	return matr;
}

int citire(int **m, int lin, int col)
{
	int i, j;
	for (i=0; i<lin; i++)
	for(j=0;j<col;j++)
    {
        printf("v[%d][%d] = ",i,j);
        scanf("%d", &m[i][j]);
        //printf("\n");
    }

}

int afisare(int **m, int lin, int col)
{
    printf("Matricea este \n");
	int i, j;
	for (i=0; i<lin; i++)
	{
		for(j=0;j<col;j++)
		{
			printf("%d ", m[i][j]);
		}
		printf("\n");
	}
}

void inmultire_matrice(int **m,int l,int c,int **p)
 {
     if(l!=c)
        {
            printf("Matricea nu e patratica, deci nu se poate ridica la patrat");
            exit(-2);
        }
     else
        {
		for(int i=0; i<l; i++)
 			for(int j=0; j<c; j++)
			 	{
				 p[i][j]=0;
 					for(int k=0; k<c;k++)
 						p[i][j] = p[i][j] + m[i][k] * m[k][j];

				 }
        }
}

int suma_diagonala_principala(int **m,int l,int c)
{
	int s = 0;
	for(int i = 0; i < l; i++)
		for(int j = 0; j < c; j++)
			if(i == j)
			{
				s = s + m[i][j];
			}
	return s;
	printf("Suma este %d", s);
}

int main()
{
	int **matr,**p;
	int l, c, i;
	printf("Numarul de linii este ");
	scanf("%d",&l);
	printf("Numarul de coloane este ");
	scanf("%d",&c);
	matr = alocare(l,c);
	citire(matr, l, c);
	afisare(matr,l,c);
	suma_diagonala_principala(matr,l,c);
	p = alocare(l,c);
	inmultire_matrice(matr,l,c,p);
	afisare(p,l,c);
	free(matr);
	matr=NULL;
	free(p);
	p=NULL;
}

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Masina
{
   char *marca; //daca e nume compus se citeste cu cratima: Aston Martin se va introduce ca  Aston-Martin
   int pret;
   char numar[8]; //ex: IF09BCX, B89FMH
}Masina;

//1
Masina citire(Masina m, int l, int c)
{

    {
        char buf[250];
		printf("marca %d - %d: ", l,c);
		scanf("%s", buf);
        m.marca = malloc(strlen(buf)*sizeof(char));
        strncpy(m.marca,buf,strlen(buf));
		printf("numar %d - %d: ", l,c);
		scanf("%s", m.numar);
		printf("pret %d - %d: ", l,c);
		scanf("%d", &m.pret);
    }
		return m;
}

//2
void afisare(Masina m)
{
    {
		printf("marca este %s \n", m.marca);
		printf("numar este %s \n", m.numar);
		printf("pret este %d \n", m.pret);
    }
}

//3
void afisare_in_fisier(Masina m, FILE *f)
{
	//FILE *f;
	//f=fopen("parcare.txt", "wt");
 	fprintf(f,"%s %s %d \n", m.marca, m.numar, m.pret);
    //fclose(f);
}

Masina citire_din_fisier(Masina m, FILE *f)
{
    fscanf(f,"%s %s %d \n", m.marca, m.numar, &m.pret);
    return m;
}

//4
void modificare_marca (Masina m, char *marca_noua)
{
	printf("marca noua este ");
	scanf("%s", marca_noua);
    strcpy(m.marca,marca_noua);
}

//5
Masina copie (Masina m)
{
    Masina z;
    z.marca = (char*) malloc((strlen(m.marca)+1)*sizeof(char));
	strncpy(z.marca,m.marca,strlen(m.marca));
	strcpy(z.numar,m.numar);
	z.pret=m.pret;
	printf("%s %s %d ", z.marca, z.numar, z.pret);
	return z;
}

//7
int suma(Masina **parcare, int c, int l)
{
	int s=0;
	for(int j=0;j<c;j++)
	s=s+parcare[l][j].pret;

	return s;
}

//6
int main()
{
    FILE *f;
    f=fopen("parcare.txt", "wt");
    int n;
	Masina m;

	Masina **parcare;
	int i,j;
	int l,c;
	printf("n= ");
	scanf("%d",&n);
	parcare = (Masina**)malloc(n*sizeof(int*));
	for (i=0; i<n; i++)
	{parcare[i] = (Masina*)malloc(n*sizeof(int));}

	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	parcare[i][j]=citire(m,i,j);

    for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            {
                afisare(parcare[i][j]);
            }

    printf("%d \n", suma(parcare,n,1));

    printf("%d", copie(parcare[0][0]).pret);

    for(i=0;i<n;i++)
        {for(j=0;j<n;j++)
            {afisare_in_fisier(parcare[i][j],f);}}

    Masina m2;
    m2=copie(parcare[0][0]);

    fclose(f);

    Masina m3;

    f=fopen("parcare.txt", "rt");
    m3=citire_din_fisier(parcare[3][3],f);
    fclose(f);

    //8
	Masina v[100];
	for(int k=0;k<n;k++)
	v[k]=parcare[k][k];

	for(int k=0;k<n;k++)
    {
        printf("%d ", v[k].pret);
    }

    free(v);
    free(m.marca);
    for(i=0;i<n;i++)
        free(parcare[i]);

    free(parcare);

    return 0;
}

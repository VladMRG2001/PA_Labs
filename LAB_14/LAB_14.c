#include <stdio.h>
#include <conio.h>
#define max 10

int greutate[max],i,j,profit[max];
int n,capacitate;
float ratio[max];
int y[max],x[max],profit_final=-1,greutate_finala;

void citire()
{
    printf("Numarul de obiecte: ");
    scanf("%d",&n);
    printf("Capacitatea rucsacului: ");
    scanf("%d",&capacitate);
    for(i=0; i<n; i++)
    {
        printf("Greutatea obiectului %d: ",i+1);
        scanf("%d",&greutate[i]);
        printf("Profitul obiectului %d: ", i+1);
        scanf("%d", &profit[i]);
    }
}

void afisare()
{
    printf("\n");
    float s=0.0;

    for(i=0; i<n; i++)
        printf("Obiectul %d are g = %d & p = %d & raport = %f. In rucsac se afla %d din el.\n",i+1,greutate[i],profit[i],ratio[i],x[i]);

    for(i=0; i<n; i++)
        if(x[i]==1)
        {
            printf("%d ",i+1);
            s = s + (float) profit[i] * (float) x[i];
        }
    printf("\nProfit maxim: %f ",s);
}

void sortare()
{
    int t0,t1;
    float t2;
    for(i=0; i<n; i++)
        ratio[i] = (float) profit[i] / (float) greutate[i];
    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(ratio[i]  < ratio[j])
            {
                t2 = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = t2;
                t0 = profit[i];
                profit[i] = profit[j];
                profit[j] = t0;
                t1 = greutate[i];
                greutate[i] = greutate[j];
                greutate[j] =t1;
            }
        }
    }
}

float bound(float profit_curent,float greutate_curenta,int k)
{
    float b = profit_curent;
    float c = greutate_curenta;
    for(i=k; i<=n; i++)
    {
        c = c+greutate[i];
        if( c < capacitate)
            b = b +profit[i];
        else
            return (b+(1-(c-capacitate)/ (float)greutate[i])*profit[i]);
    }
    return b;
}

void rucsac(int k,float profit_curent,float greutate_curenta)
{
    if(greutate_curenta+greutate[k] <= capacitate)
    {
        y[k] = 1;
        if(k <= n)
            rucsac(k+1,profit_curent+profit[k],greutate_curenta+greutate[k]);
        if(((profit_curent+profit[k]) > profit_final) && ( k == n))
        {
            profit_final = profit_curent+profit[k];
            greutate_finala = greutate_curenta+greutate[k];
            for(j=0; j<=k; j++)
                x[j] = y[j];
        }
    }
    if(bound(profit_curent,greutate_curenta,k) >= profit_final)
    {
        y[k] = 0;
        if( k <= n)
            rucsac(k+1,profit_curent,greutate_curenta);
        if((profit_curent > profit_final) && (k == n))
        {
            profit_final = profit_curent;
            greutate_finala = greutate_curenta;
            for(j=0; j<=k; j++)
                x[j] = y[j];
        }
    }
}

int main()
{
    citire();
    printf("\nComponentele rucsacului: \n");
    sortare();
    rucsac(0,0.0,0.0);
    afisare();
    return 0;
}

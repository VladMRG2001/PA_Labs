# include<stdio.h>

void rucsac(int n, float greutate[], float profit[], float capacitate)
{
    float x[20], profit_total = 0;
    int i, j, u;
    u = capacitate;

    for (i = 0; i < n; i++)
        x[i] = 0.0;

    for (i = 0; i < n; i++)
    {
        if (greutate[i] > u)
            break;
        else
        {
            x[i] = 1.0;
            profit_total = profit_total + profit[i];
            u = u - greutate[i];
        }
    }

    if (i < n)
        x[i] = u / greutate[i];
    ///pt cazul cu obiecte intregi x[i]=0 aici, in rest e la fel.
    ///x[i] = 0;

    profit_total = profit_total + (x[i] * profit[i]);
    /*
       printf("Obiectele in rucsac: \n");
       for (i = 0; i < n; i++)
          printf("%f ", x[i]);
    */
    printf("\n");
    for (i = 0; i < n; i++)
    {
        printf("Obiectul %d are g = %f & p = %f & raport = %f. In rucsac se afla %f din el.\n",i+1,greutate[i],profit[i],profit[i]/greutate[i],x[i]);
    }

    printf("\nProfit maxim: %f", profit_total);

}

int main()
{
    float greutate[20], profit[20], capacitate;
    int num, i, j;
    float ratio[20], temp;

    printf("Numarul de obiecte: ");
    scanf("%d", &num);

    printf("Greutatea si profitul fiecarui obiect: \n");
    for (i = 0; i < num; i++)
    {
        scanf("%f", &greutate[i]);
        scanf("%f", &profit[i]);
    }

    printf("Capacitatea rucsacului: ");
    scanf("%f", &capacitate);

    for (i = 0; i < num; i++)
    {
        ratio[i] = profit[i] / greutate[i];
    }

    for (i = 0; i < num; i++)
    {
        for (j = i + 1; j < num; j++)
        {
            if (ratio[i] < ratio[j])
            {
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;

                temp = greutate[j];
                greutate[j] = greutate[i];
                greutate[i] = temp;

                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;
            }
        }
    }

    rucsac(num, greutate, profit, capacitate);

    return 0;
}

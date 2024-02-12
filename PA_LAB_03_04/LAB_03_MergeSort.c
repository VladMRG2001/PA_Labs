#include <stdlib.h>
#include <stdio.h>

///MergeSort

void merge(int arr[], int left, int middle, int right)
{
    int i,j,k;
    int n1 = middle-left+1;
    int n2 = right-middle;
    int left_arr[n1], right_arr[n2];
    for (i = 0; i < n1; i++)
    {
        left_arr[i] = arr[left+i];
    }
    for (j = 0; j < n2; j++)
    {
        right_arr[j] = arr[middle+1+j];
    }
    i = 0;
    j = 0;
    k = left;
    while (i<n1 && j<n2)
    {
        if (left_arr[i]<=right_arr[j])
        {
            arr[k] = left_arr[i];
            i=i+1;
        }
        else
        {
            arr[k] = right_arr[j];
            j=j+1;
        }
        k=k+1;
    }

    while (i<n1)
    {
        arr[k] = left_arr[i];
        i++;
        k++;
    }

    while (j<n2)
    {
        arr[k] = right_arr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right)
{
    if (left<right)
    {
        int middle = (left+right)/2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle+1, right);

        merge(arr, left, middle, right);
    }
}

void afisare(int arr[], int nr)
{
	for (int i=0;i<nr;i++)
    {
        printf("arr[%d] = %d ",i,arr[i]);
        printf("\n");
    }
	printf("\n");
}

int main()
{
    int arr[] = {1,7,-45,0,9,5,-8};
	int n = sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr,0,n-1);
    printf("Elementele sortate: \n");
    afisare(arr,n);

    return 0;
}

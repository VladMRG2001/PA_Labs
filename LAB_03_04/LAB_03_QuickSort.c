#include <stdlib.h>
#include <stdio.h>

///QuickSort

void interschimba(int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

int partition (int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = low-1;

	for (int j=low;j<=high-1;j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			interschimba(&arr[i], &arr[j]);
		}
	}
	interschimba(&arr[i+1], &arr[high]);
	return (i+1);
}

void quickSort(int array[], int low, int high)
{
	if (low<high)
	{
		int q = partition(array, low, high);

		quickSort(array, low, q-1);
		quickSort(array, q+1, high);
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
	int arr[] = {2,76,9876,-12,0,9};
	int n = sizeof(arr)/sizeof(arr[0]);
	quickSort(arr,0,n-1);
	printf( "Elementele sortate: \n");
	afisare(arr,n);

	return 0;
}

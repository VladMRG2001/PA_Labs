#include <stdlib.h>
#include <stdio.h>

int factorial( int n)
{	int p;
	if(n<=1)
		return 1;
	else
		p = n*factorial(n-1);

	return p;

}

int main()
{
	int n,f;
	printf("Introduceti un nr: ");
	scanf("%d", &n);
	f = factorial(n);
	printf("%d! = %d",n,f);

	return 0;
}

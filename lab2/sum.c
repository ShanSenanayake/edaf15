#include <stdio.h>

#define N (4)

int	a[] = { 1, 2, 3, 4, 0};
int     x = 1000;

int main()
{
	int	i;	
	int	sum = 0;

	printf("welcome to the buggy sum program. the sum should be 10\n");

	for (i = 0; i < N; i++)
		sum += a[i];

	printf("sum = %d\n", sum);
	return 0;
}

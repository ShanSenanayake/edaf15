#include <stdio.h>

#define N (1000)

int	a[N] = { 1, 2, 3, 4, };
long long     x = 1000;

int main()
{
	int	i;	
	int	sum;

	for (i = 0; i < N; i++)
		a[i] = 0;
	a[N+1]=0;
	printf("x = %lld\n", x);
	return 0;
}

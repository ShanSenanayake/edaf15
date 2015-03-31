#include <stdio.h>

int main(int argc, char* argv[])
{
	int	sum =0;
	int temp;
	size_t i;
	FILE* fp;
	fp = fopen("data.txt", "w"); // open the fil e for writing .
	for(i=1;i<argc;i++){
		//printf("%s\n",argv[i]);
		sscanf(argv[i],"%d",&temp);
		fprintf(fp, "%d ", temp);
		sum+=temp;
	}

	fprintf(fp, ": %d\n", sum);
	fclose(fp);

	return 0;
}

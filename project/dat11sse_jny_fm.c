#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>


int* aParser(FILE* fp,int* nRows,int* nCols);
int* cParser(FILE* fp,int* n_vals);

static unsigned long long	fm_count;
static volatile bool		proceed = false;

static void done(int unused)
{
	proceed = false;
	unused = unused;
}
	
unsigned long long name_fm(char* aname, char* cname, int seconds)
{
	FILE*		afile = fopen(aname, "r");
	FILE*		cfile = fopen(cname, "r");

	fm_count = 0;

	if (afile == NULL) {
		fprintf(stderr, "could not open file A\n");
		exit(1);
	}

	if (cfile == NULL) {
		fprintf(stderr, "could not open file c\n");
		exit(1);
	}

	/* read A and c files. */


	int n_rows,n_cols,n_vals;
	int* matrix_A=aParser(afile,&n_rows,&n_cols);
	int* vector_C=cParser(cfile,&n_vals);
		
	fclose(afile);
	fclose(cfile);

	if (seconds == 0) {
		/* Just run once for validation. */
			
		// Uncomment when your function and variables exist...
		// return fm_elim(rows, cols, a, c);
		return 1; // return one, i.e. has a solution for now...
	}

	/* Tell operating system to call function DONE when an ALARM comes. */
	signal(SIGALRM, done);
	alarm(seconds);

	/* Now loop until the alarm comes... */
	proceed = true;
	while (proceed) {
		// Uncomment when your function and variables exist...
		// fm_elim(rows, cols, a, c);

		fm_count++;
	}

	return fm_count;
}



int* aParser(FILE* fp,int* n_rows,int* n_cols)
{
	char string[512];
	fgets(string,512,fp);
	int nrows,ncols;
	sscanf(string,"%d %d\n",&nrows,&ncols);
	printf("%d %d\n",nrows,ncols);
	
	int* matrix=malloc(sizeof(int)*nrows*ncols);
	if(matrix==NULL){
		fprintf(stderr,"malloc failed");
		exit(1);
	}
	*n_rows=nrows;
	*n_cols=ncols;
	int i,j;
	const char* delim=" \t\n";
	for(i=0;i<nrows;++i){
		fgets(string,512,fp);
		char* token=strtok(string,delim);
		for(j=0;j<ncols;j++){
			sscanf(token,"%d",&matrix[nrows*i+j]);	
			token=strtok(NULL,delim);
		}
	}

	/*Only for printing*/
	for(i=0;i<nrows;++i){
		for(j=0;j<ncols;j++){
			printf("%d ",matrix[nrows*i+j]);	
		}
		printf("\n");
	}
	printf("\n");
	return matrix;
} 

int* cParser(FILE* fp,int* n_vals)
{
	char string[512];
	fgets(string,512,fp);
	int nvals;
	sscanf(string,"%d",&nvals);
	printf("%d \n",nvals);
	
	int* vector=malloc(sizeof(int)*nvals);
	if(vector==NULL){
		fprintf(stderr,"malloc failed\n");
		exit(1);
	}
	*n_vals=nvals;
	int i;
	for(i=0;i<nvals;++i){
		fgets(string,512,fp);
		sscanf(string,"%d",&vector[i]);	
	}

	/*Only for printing*/
	for(i=0;i<nvals;++i){
		printf("%d\n",vector[i]);	
	}
	printf("\n");
	return vector;
} 
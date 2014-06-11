#include<stdio.h>
#include<omp.h>
#include<stdbool.h>
int main(int argc,char *argv[])
{
	int n,tid,x;
	#pragma omp parallel private(tid,n)
	{
		tid=omp_get_thread_num();
		printf("Hello from thread %d\n",tid);
		if(tid==0)
		{
			x=5;
			n=omp_get_num_threads();
			printf("Number of threads %d\n",n);
		}
	}
	#pragma omp parallel shared(x) private(tid)
	{
		tid=omp_get_thread_num();
		printf("In thread %d value of x is %d\n",tid,x);
	}
	return 0;
}

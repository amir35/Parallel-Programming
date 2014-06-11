#include<stdio.h>
#include<omp.h>
int main(int argc,char *argv[])
{
	int a[10][10],b[10][10],sum[10][10];
	int tid,i,j;
		//	#pragma omp for
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			a[i][j]=random()%10;
			b[i][j]=random()%10;
		}
	}
	#pragma omp parallel num_threads(10)
	{

		#pragma omp critical
		for(i=0;i<10;i++)
		{
			printf("thread %d\n",omp_get_thread_num());
			for(j=0;j<10;j++)
			{
				sum[i][j]=a[i][j]+b[i][j];
			}
		}
	}
	printf("Matrix A\n");
//	#pragma omp critical
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	printf("Matrix B\n");
//	#pragma omp critical
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			printf("%d\t",b[i][j]);
		}
		printf("\n");
	}
	printf("Result matrix\n");
//	#pragma omp critical 
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			printf("%d\t",sum[i][j]);
		}
		printf("\n");
	}
	return 0;
}
	
				

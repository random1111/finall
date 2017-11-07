#include<stdio.h>
#include<pthread.h>

int a[40][40],b[40][40],c[40][40];
int r1,r2,c1,c2;

void *multi(void *p);

void main()
{
	int i,j,k;
	pthread_t thread[10];
	
	printf("enter dimention of array a");
	scanf("%d%d",&r1,&c1);
	printf("enter array elements");
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}

	printf("enter dimention of array b\n");
	scanf("%d%d",&r2,&c2);
	printf("enter array elements\n");
	for(i=0;i<r2;i++)
	{
		for(j=0;j<c2;j++)
		{								
			scanf("%d",&b[i][j]);
		}
	}

	printf("a matrix elements are\n ");
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}

	printf("b matrix elements are \n");
	for(i=0;i<r2;i++)
	{
		for(j=0;j<c2;j++)
		{
			printf("%d\t",b[i][j]);
		}
		printf("\n");
	}

	//multiplication
	if(c1==r2)
	{	
		for(i=0;i<r1;i++)
		{	
			
			pthread_create(&thread[i],NULL,multi,(void *)i);
			
		}	

		for(i=0;i<r1;i++)
		{	
			
			pthread_join(thread[i],NULL);
			
		}
		printf("c matrix elements are\n ");
		for(i=0;i<r1;i++)                                          //r1 c2
		{
			for(j=0;j<c2;j++)
			{
				printf("%d\t",c[i][j]);
			}
			printf("\n");
		}
	}
	else
	{
		printf("Multiplication is not possible");
	}
}
void *multi(void *p)
{
	int k,j,z;
	 z=(int)p;
	
	for(j=0;j<c2;j++)
	{
		c[z][j] = 0;
		for(k=0;k<c1;k++)
		{	
			c[z][j] = c[z][j] + (a[z][k] * b[k][j]);		
		}
	}
	
}

/*ssl@ssl-ThinkCentre-M60e:~/Desktop$ gcc m.c -lpthread;
ssl@ssl-ThinkCentre-M60e:~/Desktop$ ./a.out
enter dimention of array a3
3
enter array elements1
2
3
1
2
3
54
6
7
enter dimention of array b
3
3
enter array elements
1
0
0
0
1
0
0
0
1
a matrix elements are
 1	2	3	
1	2	3	
54	6	7	
b matrix elements are 
1	0	0	
0	1	0	
0	0	1	
c matrix elements are
 1	2	3	
1	2	3	
54	6	7	
ssl@ssl-ThinkCentre-M60e:~/Desktop$ 
*/

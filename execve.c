#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>

int A[10], n;

void sort() 
{
	int i,j, temp;
	for(i=0;i<n;i++){
		for(j=0;j<n-i-1;j++) 
                {
			if(A[j]>=A[j+1])
			{
				temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
			}
		}
	}
	printf("\nSorted");
	for(i=0;i<n;i++) 
		printf("\n%d\n", A[i]);
}

void main() 
{
	int  i;
	pid_t pid;
	char str[10];
	char *arg[10];

	printf("\nEnter number of elements :");
	scanf("%d", &n);
	
	printf("\nEnter %d elements\n", n);
	for(i=0;i<n;i++) 
		scanf("%d", &A[i]);

	sort();
	pid = fork();

	if(pid==0) {
		//printf("\nNow converting");
		
		for(i=0;i<n;i++)
		{
			sprintf(str, "%d", A[i]);	
			arg[i] = malloc(sizeof(str));
			strcpy(arg[i], str);
		}
		arg[i] = NULL;
		execve("a", arg, NULL);
		printf("\nConverted and called");
	} 
	else 
	{
		wait(NULL);
	}
}

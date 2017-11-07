#include<stdio.h>
#include<stdlib.h>

int A[10];

int main(int argc, char *argv[]) 
{

	int i, key, mid, end, beg;

	for(i=0;i<argc;i++) 
		A[i] = atoi(argv[i]);

	printf("\nEnter element to be searched: \t");
	scanf("%d", &key);		

	beg = 0;
	end = argc;
	mid = end/2;
	int flag = 0;

	while(beg<=end) 
	{
		
		if(A[mid] == key) 
		{
			printf("\nElement %d found at location %d\n", key, mid+1);
			flag = 1;
			break;
		} 
		else if(A[mid]>key) 
		{
			end = mid-1;
		} 
		else 
		{
			beg = mid+1;
		}
		mid = (beg+end)/2;
	}

	if(flag == 0) 
	{
		printf("\nElement %d not found in list\n", key);
	}

	return 0;
}

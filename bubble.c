#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

void asc(int [],int );
void des(int [],int);

int main()
{
   int i,n;
   pid_t pid;
 
   printf("enter the number of elements to be entered :\t");
   scanf("%d",&n);
  
   int a[n];
  
   printf("enter the array elements :\n");
  
   for( i=0;i<n;i++)
   {
       scanf("%d",&a[i]);
   }
   
    pid=fork();
   
    if(pid==0)
    {

       printf("this is a child process\n");
       asc(a,n);
     }
     else
     {
         printf("this is a parent process\n");
         des(a,n);
         wait(NULL) ;   
      }
     
  }
 
  void asc(int a[],int n)
  {
      int temp,i,j;
           for( i=0;i<n-1;i++)
           {
               for( j=i+1;j<n;j++)
               {
                      if(a[i]>a[j])
                      {
                          temp=a[i];
                          a[i]=a[j];
                          a[j]=temp;
                       }
                 }
             }
         printf("array in ascending order :\t") ;  
         for( i=0;i<n;i++)
         {
            printf("%d",a[i]);                   
         }  
         printf("\n");
   }   
  
    void des(int a[],int n)
  {
      int temp,i,j;
           for( i=0;i<n-1;i++)
           {
               for( j=i+1;j<n;j++)
               {
                      if(a[i]<a[j])
                      {
                          temp=a[i];
                          a[i]=a[j];
                          a[j]=temp;
                       }
                 }
             }
         printf("array in descending order :\t") ;  
         for( i=0;i<n;i++)
         {
            printf("%d",a[i]);                   
         }
         printf("\n"); 
        
   }        

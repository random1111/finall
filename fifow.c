#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
     int fd,fd1,i=0;
     int arr[3];
     char str[30];     
     char txt;

     mkfifo("myfifo",0666);
     fd = open("myfifo",O_WRONLY);
     txt = getchar();

     while(txt!='Q')
     {
        str[i] = txt;
        txt = getchar();
        i++;     
     }

     write(fd,str,sizeof(str));
     close(fd);

     mkfifo("myfifo1",0666);
     fd1 = open("myfifo1",O_RDONLY);
     read(fd1,arr,sizeof(arr));

     printf("No of characters are %d\n",arr[0]); 
     printf("No of words are %d\n",arr[1]); 
     printf("No of lines are %d\n",arr[2]); 
}

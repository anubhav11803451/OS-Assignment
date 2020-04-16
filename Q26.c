#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/wait.h>
#define size 50

int main(int arguments, char* arv[]) 
{
    int file[2];
    pid_t child;
    char Buffer[size];
    pipe(file);
    if( arguments != 3 ) 
    {
        printf("ERROR: Need exactly 2 parameters.\n");
        exit(1);
    }
    int fileOpen = open(arv[1], 0);
    int TargetFile = open(arv[2], O_RDWR|O_CREAT|O_APPEND, 0666);
    if (fileOpen == -1 || TargetFile == -1) 
    {
        printf("File can not be opend\n");
        exit(1);
    }
    child = fork();
    if (child== 0) 
    {
        close(file[1]);
	while (read(file[0], Buffer, sizeof(Buffer)) > 0) 
	{
		write(TargetFile, Buffer, strlen(Buffer) - 1);
        }
        close(file[0]);
        close(TargetFile);
    }
    else 
    {
        close(file[0]);
	while (read(fileOpen, Buffer, sizeof(Buffer)) > 0) 
	{
            write(file[1], Buffer, sizeof(Buffer));
            memset(Buffer, 0, size);
        }
        close(file[1]);
        close(fileOpen);
        wait(NULL);
    }
}
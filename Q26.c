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
    char Buffer[size]; // we can directly give 50 here also but,
                        // just to make more clear i've used seprate variable
    pipe(file); //  Pipes are useful for communication between related processes(inter-process communication).
    if( arguments != 3 ) 
    {
        printf("ERROR: Need exactly 2 parameters.\n");
        exit(1);
    }
    int FileOriginal = open(arv[1], 0); // open() system call used to Open the file for reading, writing or both
    int Filecopy = open(arv[2], O_RDWR|O_CREAT|O_APPEND, 0666);
    if (FileOriginal == -1 || Filecopy == -1) 
    {
        printf("File can not be opend\n");
        exit(1);
    }
    child = fork();
    if (child== 0) //task for the child process should be written in p==0 part.
    {
        close(file[1]);
	    while (read(file[0], Buffer, sizeof(Buffer)) > 0) //The read() system call reads input typed by the user via the keyboard (file descriptor 0)
        // and stores it in the buffer (buff) which is nothing but a character array. It will read maximum of 50 bytes.
	    {
		    write(Filecopy, Buffer, strlen(Buffer) - 1); //write() system call is used to write to a file descriptor.
        }
        close(file[0]);     // used to close open file.
        close(Filecopy);
    }
    else 
    {
        close(file[0]);
	while (read(FileOriginal, Buffer, sizeof(Buffer)) > 0) 
	{
            write(file[1], Buffer, sizeof(Buffer));
            memset(Buffer, 0, size); // memset() is used to fill a block of memory with a particular value
        }
        close(file[1]);
        close(FileOriginal);
        wait(NULL);
    }
}
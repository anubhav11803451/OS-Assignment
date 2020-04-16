#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
// declaring required variable
   int i,n;
   pid_t child;

   printf("Enter a number:\n");
   scanf("%d", &n);

   if (n < 0)	// used this condition to make sure positive value is entered
      printf("Please enter a non-negative integer!\n");
   else
   {
      child = fork();   //fork() is a system call used to create a new process. 
                        //fork() returns -1 on failure; On success it returns ‘0’ in the child process and process-id of the child in the parent process.  	
      if (child == 0)
      {  //task for the child process should be written in p==0 part.
         while (n>0)
         {
            printf("%d \n",n);
	    n = n/2;
         }
         printf("Child Process ends\n"); 
      }
      else 
      {  //task you want the parent to perform should be written in the else 
         printf("Parent is waiting for child to complete...\n");
         wait(NULL);
         printf("Parent Process ends\n");
      }
   }
   return 0;
}
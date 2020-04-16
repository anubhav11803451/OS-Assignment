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
      child = fork();	
      if (child == 0)
      {
         while (n>0)
         {
            printf("%d \n",n);
	    n = n/2;
         }
         printf("Child Process ends\n"); 
      }
      else 
      {
         printf("Parent is waiting for child to complete...\n");
         wait(NULL);
         printf("Parent Process ends\n");
      }
   }
   return 0;
}
#include <stdio.h>   /* printf, stderr, fprintf */
#include <sys/types.h> /* pid_t */
#include <unistd.h>  /* _exit, fork */
#include <stdlib.h>  /* exit */
#include <errno.h>   /* errno */

int main(void)
{
   pid_t  pid;

   pid = fork();

   if (pid == -1)
   {
      fprintf(stderr, "error %d\n", errno);
      exit(EXIT_FAILURE);
   }
   else if (pid == 0)
   {
      /* Child process:
       * When fork() returns 0, we are in
       * the child process.
       */
      int  j;
      for (j = 0; j < 10; j++)
      {
         printf("child: %d\n", j);
         sleep(1);
      }
      _exit(0);  
   }
   else
   {
      /* When fork() returns a positive number, we are in the parent process
       * (the fork return value is the PID of the newly created child process)
       * Again we count up to ten.
       */
      int  i;
      for (i = 0; i < 10; i++)
      {
         printf("parent: %d\n", i);
         sleep(1);
      }
      exit(0);
   }
   return 0;
}










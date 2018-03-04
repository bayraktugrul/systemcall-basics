#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	kill(getpid(),SIGKILL);
	printf("sending SIGKILL"); //wont execute this line
}



//SIGKILL signal cannot be caught and blocked

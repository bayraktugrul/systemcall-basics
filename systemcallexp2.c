#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	kill(getpid(),SIGKILL);
	printf("sending SIGKILL");
}



//SIGKILL signal cannot be caught and blocked

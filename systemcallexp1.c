#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void catchsignal(int signum) {
	printf("\n%d signal delivered!", signum );
}

int main() {
	struct sigaction newop; 

	newop.sa_handler = catchsignal;
	newop.sa_flags = 0;
	
	while(1)
		sigaction(SIGINT, &newop,NULL); 
}
//SIGINT : Terminal interrupt character


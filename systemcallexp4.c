#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

//sigsuspend example
//signals in the set will be suspended

int count = 0;

void catchsignal(int signum) {
    printf("\n%d signal delivered!", signum );
    count++;
}

int main() {

     sigset_t x;  
     sigemptyset (&x);
     sigaddset(&x, SIGINT);
     struct sigaction newop; 

     newop.sa_handler = catchsignal;
     newop.sa_flags = 0;

     while(1){
        sigaction(SIGINT, &newop,NULL); 

        if(count==5){   
            sigsuspend(&x);
        }
    }

}
//SIGINT : Terminal interrupt character


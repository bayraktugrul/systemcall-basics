#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

//sigprocmask example
//SIGINT signal will be blocked after 5 times signal delivered. 

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
            sigprocmask(SIG_BLOCK, &x, NULL);
        }
    }

}
//SIGINT : Terminal interrupt character


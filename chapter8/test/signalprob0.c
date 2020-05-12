#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <signal.h>

/* $begin signalprob0 */
pid_t pid;
int num = 2;
int *counter = &num;

void handler1(int sig) {
    printf("%d", --*counter);
    fflush(stdout); 
    exit(0);
}

int main() {
    signal(SIGUSR1, handler1);

    printf("%d", *counter);
    fflush(stdout);

    if ((pid = fork()) == 0) {
	while(1) {};
    }
    kill(pid, SIGUSR1); 
    waitpid(-1, NULL, 0);
    printf("%d\n", ++*counter);
    exit(0);
}
/* $end signalprob0 */

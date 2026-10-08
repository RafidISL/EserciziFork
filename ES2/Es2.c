#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    for (int i = 0; i < 3; i++) {

        pid = fork();

        if (pid == 0) {
            printf("[Figlio] PID: %d\n", getpid());
            printf("[Figlio] PID: %d\n", getpid());

            sleep(2);

            printf("[Figlio] PID %d terminato.\n", getpid());

            exit(0);
        }
    }

    for (int i = 0; i < 3; i++) {
        wait(NULL);
    }

    printf("[Padre] Tutti i figli sono terminati.\n");

    return 0;
}
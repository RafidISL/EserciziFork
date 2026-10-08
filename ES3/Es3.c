#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid == 0) {
        printf("[Padre] Sono il processo padre. PID: %d\n", getpid());

        pid_t pid_nipote = fork();

        if (pid_nipote == 0) {
            printf("[Nipote] Sono il processo nipote. PID: %d\n", getpid());

            printf("[Nipote] Termino.\n");

            exit(0);

        } else {
            wait(NULL);

            printf("[Padre] Il nipote è terminato. Termino anch'io.\n");

            exit(0);
        }

    } else {
        wait(NULL);

        printf("[Nonno] Il padre è terminato. Termino anch'io.\n");
    }

    return 0;
}

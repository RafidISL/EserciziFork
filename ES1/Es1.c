#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
    pid_t pid=fork();
    if (pid<0) {
        perror("errore nella fork");
        exit(EXIT_FAILURE);
    }

    if (pid==0) {
        for (int i=1;i<=5;i++) {
            printf("Figlio %d\n",i);
            sleep(1);
        }
        exit(0);
    }

    else {
        wait(NULL);

        for (int i=6;i<=10;i++) {
            printf("Padre %d\n",i);
        }

        return 0;
    }
}


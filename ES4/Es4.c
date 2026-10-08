
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        int numero;
        int primo = 1;

        printf("[Figlio] Inserisci un numero intero: ");
        scanf("%d", &numero);

        if (numero < 2) {
            primo = 0;
        } else {
            for (int i = 2; i < numero; i++) {
                if (numero % i == 0) {
                    primo = 0;
                    break;
                }
            }
        }

        if (primo) {
            exit(1);
        } else if (numero % 2 == 0) {
            exit(2);
        } else {
            exit(3);
        }

    } else {
        int status;

        pid_t child_pid = wait(&status);

        if (WIFEXITED(status)) {
            int exit_code = WEXITSTATUS(status);

            if (exit_code == 1) {
                printf("[Padre] Il figlio %d ha comunicato: il numero è primo.\n",
                child_pid);

            } else if (exit_code == 2) {
                printf("[Padre] Il figlio %d ha comunicato: il numero è pari e non primo.\n",
                child_pid);

            } else if (exit_code == 3) {
                printf("[Padre] Il figlio %d ha comunicato: il numero è dispari e non primo.\n",
                child_pid);
            }

        } else {
            printf("[Padre] Il figlio è terminato in modo anomalo.\n");
        }
    }

    return 0;
}

#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include <zconf.h>
#include <signal.h>
#include <wait.h>

void exer2() {

    pid_t f;

    int arr[2];
    pipe(arr);
    char str[] = "String";
    char buffer[7];

    f = fork();

    if (f > 0) {
        write(arr[1], str, sizeof(str) + 1);
    } else if (f == 0) {
        read(arr[0], buffer, sizeof(buffer));
        printf("%s\n", buffer);
    }
    close(arr[0]);
    close(arr[1]);
}

void exer1() {
    int arr[2];
    pipe(arr);
    char str[] = "String";
    char buffer[7];

    write(arr[1], str, sizeof(str));
    read(arr[0], buffer, sizeof(buffer));
    printf("%s\n", buffer);

    close(arr[0]);
    close(arr[1]);
}

void handle() {
    printf("Hvatit\n");
}

void my_handler(int sig) {

    if (sig == SIGUSR1) {
        printf("%s", "Handled SIGUSR1!\n");
        exit(SIGUSR1);
    } else if (sig == SIGSTOP) {
        printf("%s", "Handled SIGSTOP!\n");
        exit(SIGSTOP);
    } else if (sig == SIGKILL) {
        printf("%s", "Handled SIGKILL!\n");
        exit(SIGKILL);
    }
}

void exer3() {

    while (1) {
        printf("%s\n", "Privet");
        sleep(1);
        signal(SIGINT, handle);
    }
}

void exer4() {
    kill(getpid(), SIGUSR1);
    while (1) {
        printf("%s", "Processing...");
        fflush(stdout);
        sleep(1);
    }

}

void exer5() {
    pid_t id;
    id = fork();

    if (id == 0) {
        while (1) {
            printf("%s\n", "I'm alive");
            sleep(1);
        }
    } else {
        sleep(10);
        kill(id, SIGTERM); //we can send signal here or in the terminal
    }

}

void exer6() {

    int arr[2];
    pipe(arr);
    int status;
    pid_t child1, child2, id_2, get_id;

    child1 = fork();
    if (child1 == 0) {
        printf("I'm the first child with %d\n", getpid());
        sleep(3);
        read(arr[0], get_id, sizeof(get_id));
        kill(get_id, SIGSTOP);
    }

    if (child1 > 0) {
        child2 = fork();
        sleep(2);


        if (child2 == 0) {
            sleep(3);
            printf("I'm the second child with %d\n", getpid());
        } else {
            write(arr[1], id_2, sizeof(id_2) + 1);
            waitpid(child2, &status, 0);
            printf("The end\n");
        }
    }


    close(arr[0]);
    close(arr[1]);
}

int main() {
    //exer1();
    //exer2();
    //exer3();
    //exer4();
    //exer5();
    //exer6();

    return 0;
}



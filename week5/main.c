#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <zconf.h>

pthread_t thread_id[10];

void *tread(void *id) {
    sleep(1);
    printf("\n>I am thread: %d", id);
    pthread_exit(NULL);
}

void exer1() {
    printf("Treads are in a parallel\n");
    for (int i = 0; i < 10; ++i) {
        pthread_create(&thread_id[i], NULL, tread, (void *) i);
    }
    for (int j = 0; j < 10; ++j) {
        pthread_join(thread_id[j], NULL);
    }
    printf("\n__________________\n");
}

void exer2() {
    printf("Treads are sequentially\n");
    for (int i = 0; i < 10; ++i) {
        pthread_create(&thread_id[i], NULL, tread, (void *) i);
        pthread_join(thread_id[i], NULL);
    }
    printf("\n__________________\n");

}

int main() {
    //exer1();
    exer2();
    return 0;
}

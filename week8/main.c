#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <zconf.h>
#include <sys/resource.h>

void exer2() {
    for (int i = 0; i < 10; i++) {
        void *p = malloc(1024 * 1024 * 10);
        memset(p, 0, 1024 * 1024 * 10);
        sleep(1);
        free(p);
    }
}

void exer4() {
    struct rusage mem_usage;
    for (int i = 0; i < 10; i++) {
        void *m = malloc(10 * 1024 * 1024);
        memset(m, 0, 10 * 1024 * 1024);
        getrusage(RUSAGE_SELF, &mem_usage);
        printf("Memory usage = %ld\n", mem_usage.ru_maxrss);
        sleep(1);
    }
}

int main() {
    // exer2();
    exer4();
    return 0;
}

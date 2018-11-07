#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <zconf.h>

void exer1() {
    FILE *f = fopen("/dev/random", "r");
    char *file_open = (char *) malloc(sizeof(char));
    fgets(file_open, 20, f);
    puts(file_open);
}

void exer2(int argc, char *argv[]) {

    FILE *f, *f1;
    char buffer;

    int status_tee = strcmp(argv[1], "tee"); // first argument always should be tee

    //first conditions for tee file1 file2
    if (status_tee == 0 && argc == 4) {
        f = fopen(argv[2], "r");
        f1 = fopen(argv[3], "w");

        while (!feof(f)) {
            buffer = fgetc(f);
            fputc(buffer, f1);
            printf("%c", buffer);
        }

        fclose(f);
        fclose(f1);
    } else if (status_tee == 0 && strcmp(argv[2], "-a") == 0 &&
               argc == 5) { //second conditions for tee -a file1 "something_to_append"
        f = fopen(argv[3], "a");
        fputs(argv[4], f);
        fclose(f);
    }
}

int main(int argc, char *argv[]) {
    //exer1();
    //exer2(argc, argv);
    return 0;
}


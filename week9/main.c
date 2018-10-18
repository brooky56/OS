#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <zconf.h>

int *fr_address;
int *fr_status;

void oldStatus(int VA, int frames_number) {

    int old_page_index = 0;
    int old_page_age = 0;

    for (int i = 0; i < frames_number; i++) {
        if (fr_status[i] > old_page_age) {
            old_page_age = fr_status[i];
            old_page_index = i;
        }
    }

    fr_address[old_page_index] = VA;
    fr_status[old_page_index] = 0;

}

int aging_Algorithm(int VA, int frames_number) {

    // aging if page referenced we should shift right and put most significant bit and said that page is used put 1 if it don't used put 0

    for (int i = 0; i < frames_number; i++) {
        if (fr_status[i] != INT_MAX) {
            fr_status[i]++;
        }
    }

    // if page was founded in
    for (int i = 0; i < frames_number; i++) {
        if (fr_address[i] == VA) {
            fr_status[i] = 0;
            return 0;
        }
    }

    oldStatus(VA, frames_number);

    return 1;
}

void readFile() {

    FILE *file_input;
    int N;
    printf("%s", "Number of page frames: ");
    scanf("%d", &N);

    fr_address = malloc(sizeof(int) * N);
    fr_status = malloc(sizeof(int) * N);

    for (int i = 0; i < N; i++) {
        fr_address[i] = -1;
        fr_status[i] = INT_MAX;
    }

    file_input = fopen("input.txt", "r");

    int arr[1000];
    int i = 0;

    int hit = 0;
    int miss = 0;

    while (fscanf(file_input, "%i", &(arr[i])) != EOF) {

        if (aging_Algorithm(arr[i], N) == 0) {
            hit++;
        } else {
            miss++;
        }

        i++;
    }

    fclose(file_input);

    printf("Hitrates: %d\n", hit);
    printf("Missrates: %d\n", miss);
}

int main() {

    readFile();
    return 0;
}

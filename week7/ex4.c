#include <stdlib.h>
#include <stdio.h>

//kostul solution
int * my_realloc(int *arr, int old_k, int new_k ){
    int *new_arr = malloc(new_k * sizeof(int));

    for(int i=0; i<old_k; i++){
        new_arr[i] = arr[i];
    }
    free(arr);
    return new_arr;
}

int main() {
    int k1;
    printf("Enter your k: ");
    scanf("%d", &k1);
    int *input = malloc(k1 * sizeof(int));

    int k2;
    printf("Enter your k: ");
    scanf("%d", &k2);

	//do
	for(int i = 0; i<k1; i++){
		printf("%d\n",input[i]);
	}

    	input = my_realloc(input, k1, k2);

	//posle
	for(int i = 0;i<k2;i++){
		printf("%d\n",input[i]);
	}
	printf("\n");
    return 0;
}

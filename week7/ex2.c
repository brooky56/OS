#include <stdio.h>
#include <stdlib.h>
  int main() {
    printf("%s", "Put your size of array N: " );
    int n;
    scanf("%d", &n);
    int *arr = malloc(n*sizeof(int));
	for(int i = 0; i < n; i++){
		arr[i] = i;
		printf("%d\n", arr[i]);
	}

    free(arr);


    return 0;
  }

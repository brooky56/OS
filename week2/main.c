#include <stdio.h>
#include <limits.h>
#include <float.h>

void exer1()
{
	int i = INT_MAX;
	float f = FLT_MAX;
	double d = DBL_MAX;

	printf("INT: %d \n",sizeof(int));
	printf("%d \n",i);
	printf("FLOAT: %d \n",sizeof(float));
	printf("%f \n", f);
	printf("DOUBLE: %d \n",sizeof(double));
	printf("%lf \n",d);
}

void exer2()
{
	 char input[256];
	 fgets(input,256, stdin);
	 char output[strlen(input)];
	 int k = 0;
	 for(int i = strlen(input)-1; i>=0; i--){
		output[k] = input[i];
		k++;
	 }

 	output[k] = "\0";
	printf("%s", output);

}

void exer3()
{
	int n; //height
        char str[1];
        fgets(str, 4, stdin);
        sscanf(str, "%d", &n);
        int dlina = 2*n - 1;
        char treygolnik[dlina*n];
        int j = 0;
        int lvl = n - 1;
        int stars = 1;
        int i;
        for(i=0; i < n; i++){
            int k;
            for(k=0;k<lvl;k++){
                treygolnik[j] = ' ';
                j += 1;
            }
            for(k=0;k<stars;k++){
                treygolnik[j] = '*';
                count += 1;
            }
            for(k=0;k<lvl;k++){
                treygolnik[j] = ' ';
                j += 1;
            }
        stars += 2;
        lvl = lvl - 1;
        treygolnik[j] = '\n';
        j += 1;
       }
	treygolnik[j] = "\0";
        printf("%s", treygolnik);
}

void exer4()
{
	char str[2];
	int a;
	int b;
	fgets(str, 4, stdin);
	sscanf(str, "%d %d", &a, &b);
	printf("%d \n", a);
	printf("%d \n", b);

	swap(&a,&b);

	printf("%d \n", a);
	printf("%d \n", b);
}

void swap(int *q, int *d){
	int  t;
	t = *q;
	*q = *d;
	*d = t;
}

int main()
{
 //exer1();
 //exer2();
	 exer3();
 //exer4();
 return 0;
}

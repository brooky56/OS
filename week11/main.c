#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


void exer4(){

	int f1 = open("ex1.txt", O_RDWR);
 	struct stat fileStat;
	int st = fstat(f1,&fileStat);
	printf("%d\n",fileStat.st_size);

        FILE *f_2 = fopen("ex1.memcpy.txt", "w");
        ftruncate(fileno(f_2), fileStat.st_size);
        fclose(f_2);

	void* map_1 = mmap(0, fileStat.st_size, PROT_READ|PROT_WRITE, MAP_SHARED, f1, 0);
	close(f1);
	int f2 = open("ex1.memcpy.txt",O_RDWR);
	void* map_2 = mmap(0,fileStat.st_size,PROT_WRITE|PROT_READ, MAP_SHARED, f2,0);
	memcpy(map_2,map_1,fileStat.st_size);
}

void exer3_1(){
	printf("Hello");
	fork();
	printf("\n");
}

void exer3_2(){
	printf("Hello\n");
	fork();
	printf("\n");
}

void exer2(){
	char buffer[BUFSIZ];
	FILE *file1 = fopen("ex2.txt", "w");
	setbuf(file1,buffer);
	fputs("H",file1);
	sleep(1);
	fputs("e",file1);
	sleep(1);
	fputs("l",file1);
	sleep(1);
	fputs("l", file1);
	sleep(1);
	fputs("o", file1);
	sleep(1);
	fflush(file1);
    	fclose(file1);
}

void exer1(){

	struct stat bufstat;
	int f = open("ex1.txt", O_RDWR);
	void* map;
	int status = fstat(f, &bufstat);
	map = mmap(0,bufstat.st_size,PROT_READ | PROT_WRITE ,MAP_SHARED, f , 0);
	memcpy(map,"This a nice day!\n",bufstat.st_size);

}
int main(){
	//exer1();
	//exer2();
	//exer3_1();
	//exer3_2();
	//exer4();
	return 0;
}


      #include <sys/mman.h>
       #include <sys/stat.h>
       #include <fcntl.h>
       #include <stdio.h>
       #include <stdlib.h>
       #include <unistd.h>
       #include <string.h>

void exer4(){

	struct stat statbuf;

		FILE *f1 = fopen("ex1.txt", "rb");

		fseek(f1 , 0 , SEEK_END);                          // устанавливаем позицию в конец файла
  		long lSize = ftell(f1);                            // получаем размер в байтах
  		rewind(f1);
		char *buffer = (char*) malloc(sizeof(char) * lSize);
		size_t result = fread(buffer, 1, lSize, f1);

		FILE *f2 = fopen("ex1.memcpy.txt","rb");
		memcpy(f2,buffer,strlen(buffer));
		fclose(f1);
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
	//exer3_1();
	//exer3_2();
	exer4();
	return 0;
}

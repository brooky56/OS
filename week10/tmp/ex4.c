#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>

void searchDir(char *dir, int depth)
{
    DIR *dp;
    struct dirent *entry;
    struct stat stat;
    if((dp = opendir(dir)) == NULL) {
        fprintf(stderr,"cannot open directory: %s\n", dir);
        return;
    }
    chdir(dir);
    while((entry = readdir(dp)) != NULL) {
        lstat(entry->d_name,&stat);
        if(S_ISDIR(stat.st_mode)) {
            if(strcmp(".",entry->d_name) == 0 ||
                strcmp("..",entry->d_name) == 0)
                continue;
            printf("%*s%s/\n",depth,"",entry->d_name);
		//Recursively going througth directories
            searchDir(entry->d_name,depth+4);
        }
        else{
		//here we check files which have 2 or more hardlinks
		if(stat.st_nlink >= 2){
		  printf("%*s%s\n",depth,"",entry->d_name);
		}
	}
    }
    chdir("..");
    closedir(dp);
}

int main()
{
    printf("Directory scan /tmp:\n");
    searchDir("/home/aidar/labs/week10/tmp",0);
    exit(0);
}

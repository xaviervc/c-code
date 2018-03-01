#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

//#include "text.h"



void traverse();


int main(int argc, char const *argv[]) {

char *string = "apple";

traverse(string);

  return 0;
}

void traverse(char *searchString){
	
	struct dirent *de;
	DIR *dr = opendir(".");
	
	if(dr != NULL){
		while((de = readdir(dr)) != NULL){
			struct stat buf;
			stat(de->d_name, &buf);
			if(S_ISREG(buf.st_mode)){
				//call search and replace on the file here
				//test for ".txt" file too
				char *textFile = de->d_name;
				if(strstr(textFile, ".txt")){
					//printf("%s\n", de->d_name);
					
				}
			}
		}
		rewinddir(dr);
		while((de = readdir(dr)) != NULL){
			struct stat buf;
			stat(de->d_name, &buf);
			if(S_ISDIR(buf.st_mode)){
				if(strcmp(de->d_name, ".")!=0 && strcmp(de->d_name, "..")!=0){
					if(chdir(de->d_name)==0){
						printf("%s\n", de->d_name);
						traverse(searchString);
					}
				}
			}
		}
		closedir(dr);
	}
}

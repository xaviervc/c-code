#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

//#include "textTest.h"

//need to add these at the top
void directory();

int main(void){

  char *firstDirectory = "./";
  // char *searchCase = "string";

  directory(firstDirectory);
  return 0;
}

void directory(char *currentDirectory){

	//pointer for dirent struct
 	struct dirent *de;
	//pointer for the stat buffer

 	//opens the current directory which is the first one
 	DIR *dr = opendir(currentDirectory);

	//if the directory cant be opened
  	if(dr == NULL){
		printf("Could not open current directory");
	}
	//check for files first
	while ((de = readdir(dr)) != NULL){
    struct stat buf;
		stat(de->d_name, &buf);
		if(S_ISREG(buf.st_mode)){
			//this step is being skipped

			printf("%s\n", de->d_name);

		}
	}
  	closedir(dr);
	//re open directory and travserse again
  struct dirent *newde;
	DIR *newdr = opendir(currentDirectory);
	while ((newde = readdir(newdr)) != NULL){
    struct stat buffer;
		stat(newde->d_name, &buffer);
		if(S_ISDIR(buffer.st_mode)){
			if(strcmp(newde->d_name, ".")!=0 && strcmp(newde->d_name, "..")!=0){
				char *folderName = newde->d_name;
				char pathName[4096];
				strcat(pathName, currentDirectory);
				strcat(pathName, folderName);
				strcat(pathName, "/");
				printf("%s\n", pathName);
				directory(pathName);
			}
		}
	}
	closedir(newdr);
}

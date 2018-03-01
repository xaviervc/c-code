#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "text.h"

/*
Written by Xavier Vani-Charron
08/02/2018
Student ID: 27055838

traversal looks for text files and passes their location and name to text.c
once the file look up is complete it moves onto the directories
*/


//this section for report.c

// struct fileInfo{
//
// 	char *targetString;
// 	char *firstWD;
// 	char *fileName[];
// 	int *update;
//
// };

//this section for testing purposes

// void traverse();
//
//
// int main(int argc, char const *argv[]) {
//
// char *string = "apple";
//
// traverse(string);
//
//   return 0;
// }

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
					searchReplace(textFile, searchString);
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
						//printf("%s\n", de->d_name);
						traverse(searchString);
					}
				}
			}
		}
		closedir(dr);
	}
}

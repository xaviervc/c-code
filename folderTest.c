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

  char *firstDirectory = ".";
  char *searchCase = "string";

  directory(firstDirectory, searchCase);
  return 0;
}

void directory(char *currentDirectory, char *searchCase){
  //pointer for dirent struct
  struct dirent *de;
  //opens the current directory which is the first one
  DIR *dr = opendir(currentDirectory);
 //if the directory cant be opened
  if(dr == NULL){
    printf("Could not open current directory");
  }
  //constant string to find ".txt" files
  // static const char TXT[] = ".txt";

  while ((de = readdir(dr)) != NULL){
    // printf("%s\n", de->d_name);
    //string point p, strtstr checks for a substring ".txt" and then returns
    //the substring to p
    char *p = de->d_name;
    if(strstr(p,".txt")){
      printf("Text file found\n");
      //call the open file function here
      //searchReplace(de->d_name, searchCase);
    }
    //check if it is a directory (works)
    struct stat buf;
    stat(de->d_name, &buf);
    //need to exclude "." and ".."
    if(S_ISDIR(buf.st_mode)){
      if(strcmp(de->d_name, ".")!=0 && strcmp(de->d_name, "..")!=0){

         //printf("%s\n", de->d_name);
        //the path name of the folder needs to be formatted but i am not sure how to do this.
        directory(de->d_name, searchCase);
      }
    }

  }
  closedir(dr);
}

#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void directory();

int main(int argc, char const *argv[]) {
  /* code */
  char *str = ".";

  directory(str);

  return 0;
}


void directory(char *path){
  struct dirent *dirStruct;
  DIR *dirPointer = opendir(path);

  if(dirPointer!=NULL){

    while ((dirStruct = readdir(dirPointer)) != NULL){
      struct stat buffer1;

      stat(dirStruct->d_name, &buffer1);
      if(S_ISREG(buffer1.st_mode)){
        //call search replace function here

        printf("%s\n", dirStruct->d_name);

      }
    }
    rewinddir(dirPointer);


    while((dirStruct = readdir(dirPointer))!=NULL){
      struct stat buffer;

      stat(dirStruct->d_name, &buffer);
      if(S_ISDIR(buffer.st_mode)){
  			if(strcmp(dirStruct->d_name, ".")!=0 && strcmp(dirStruct->d_name, "..")!=0){
  				char *folderName = dirStruct->d_name;
  				char pathName[FILENAME_MAX];
  				strcat(pathName, path);
          strcat(pathName, "/");
  				strcat(pathName, folderName);
  				printf("%s\n", pathName);
  				directory(pathName);
  			}
    }else{
      //do nothing?
    }
  }

  	closedir(dirPointer);

}
}

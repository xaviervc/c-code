#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
Written by Xavier Vani-Charron
07/02/2018
Student ID: 27055838

searchReplace takes a file location and a search string. It replaces every occurence of the search string
including case sensitive versions of the same string
*/




 void searchReplace();




 int main(int argc, char const *argv[]) {
  char *pathName = "test.txt";
   searchReplace(pathName, "apple");
   return 0;
 }

void searchReplace(char *location, char *searchString){
  //array of chars that fgets points to, each line of text file lives here
	char readLine[512];  //hopefully doesn't exceed this


  FILE *filePointer = fopen(location, "r+");

  if(!filePointer){
    perror("File opening failed");
  }

  while(fgets(readLine, 512, filePointer) != NULL){
    //stores the substring pointer for strstr function
    char *temp;
    temp = malloc(sizeof(char)*strlen(readLine));
    int index = 0;
    //copy readLine to temp
    strcpy(temp, readLine);
    //find the indexes
    while((temp = strcasestr(temp, searchString))!=NULL){
      index = strlen(readLine)-strlen(temp);
      //convert to uppercase
      for(int i = index; i<index+strlen(searchString); i++){
        readLine[i] = toupper(readLine[i]);
      }
      //increment temp pointer
      temp += strlen(searchString);
    }
    //write to file or atleast try
    fpos_t position;
    fgetpos(filePointer, &position);
    //had to remove the +1 on linux but it works on windos that way
    fseek(filePointer, -(strlen(readLine)), SEEK_CUR);
    fprintf(filePointer, "%s", readLine);

    fsetpos(filePointer, &position);
    }
    //close file being read
    if(filePointer){
      fclose(filePointer);
    }
  }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <strings.h>

/*
Written by Xavier Vani-Charron
07/02/2018
Student ID: 27055838

searchReplace takes a file location and a search string. It replaces and exact
match of the string ie. search string is apple, pineapple will not be affected
*/


 void searchReplace();




 int main(int argc, char const *argv[]) {
	char *pathName = "test.txt";
	searchReplace(pathName, "apple");
	return 0;
 }

void searchReplace(char *location, char *searchString){

	FILE *filePointer = fopen(location, "r+");

	if(!filePointer){
    		perror("File opening failed");
  	}
	char temp[512];
	char period[512];
	char excla[512];
	char ques[512];

	strcat(period, searchString);
	strcat(period, ".");
	strcat(excla, searchString);
	strcat(excla, "!");
	strcat(ques, searchString);
	strcat(ques, "?");

	while(fscanf(filePointer, "%s", temp) != EOF){

		//strcasecmp compares while ignoring case!
		if(strcasecmp(searchString, temp)==0){
			//printf("There is an absolute match\n");
			for(int i = 0; i<strlen(searchString); i++){
			        temp[i] = toupper(temp[i]);
      			}
			//write to file
			//check cursor position
			//printf("%ld\n", ftell(filePointer));
   			fpos_t position;
    			fgetpos(filePointer, &position);
			//had to remove the +1 on linux but it works on windos that way
    			fseek(filePointer, -(strlen(temp)), SEEK_CUR);
    			fprintf(filePointer, "%s", temp);
			fsetpos(filePointer, &position);
			}
		if(strstr(temp, period) || strstr(temp, excla) || strstr(temp, ques)){
			printf("Still a match even with punctuation\n");
			for(int i = 0; i<strlen(searchString); i++){
			        temp[i] = toupper(temp[i]);
      			}
			//write to file
			//check cursor position
			//printf("%ld\n", ftell(filePointer));
   			fpos_t position;
    			fgetpos(filePointer, &position);
			//had to remove the +1 on linux but it works on windos that way
    			fseek(filePointer, -(strlen(temp)), SEEK_CUR);
    			fprintf(filePointer, "%s", temp);
			fsetpos(filePointer, &position);
		}
	}
    if(filePointer){
      fclose(filePointer);
    }
  }

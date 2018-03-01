#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Written by Xavier Vani-Charron
07/02/2018
Student ID: 27055838

Basic report formatting, takes 4 arguments, the search case, the first working directory,
an array of strings containing the file names and their sub directories and the amount of times
the file was updated (how many string matches in the particular file)
*/

// void report();
//
//
// int main(int argc, char const *argv[]) {
//
//
//   return 0;
// }



void report(struct fileInfo info){

// printf("Target string: %s\n", info.targetString);
// printf("\n");
// printf("Search begins in current folder: %s\n", info.firstWD);
// printf("\n");
// printf("\n");
// printf("** Search Report **\n");
// printf("\n");
//
// if(info.update!=NULL){
//
// 	for(int i=0; i<sizeof(info.update)/sizeof(info.update[0]);i++){
// 		printf("%i	%s\n", info.update[i], info.fileName[i]);
// 	}
// 		}else{
// 	printf("No updates made\n");
// 	}
printf("%i", info.update[0]);
}

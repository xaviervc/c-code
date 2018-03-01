#include <stdio.h>
#include "traversal.h"
#include "text.h"
//#include "report.h"

/*
Written by Xavier Vani-Charron
07/02/2018
Student ID: 27055838

the main takes the argument and passes it to the traverse function
*/


int main(int argc, char const *argv[]) {
  /* code */

  if (argc == 1){
    //convert this to an stderror thing
    printf("Expecting atleast one argument!\n");
  }else if(argc == 2){
    //argv[] array holds the argument string
    //argv[0] is the program name!
    //printf("The argument supplied is %s\n", argv[1]);
    traverse(argv[1]);
  }
}

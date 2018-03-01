#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char const *argv[]) {
  /* code */

  char str[] = "not hello hello";
  char *temp;

  temp = malloc(sizeof(char)*strlen(str));
  char testCase[] = "hello";

  int index=0;

  //copy string into place holder
  strcpy(temp, str);

  //index finder
  while((temp = strstr(temp, testCase))!=NULL){

    index = strlen(str)-strlen(temp);
    for(int i = index; i<index+strlen(testCase); i++){
      str[i]=toupper(str[i]);
    }
    temp += strlen(testCase);

  }

printf("%s\n", str);

free(temp);
  return 0;
}

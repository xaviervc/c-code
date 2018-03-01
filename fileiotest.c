#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

int main(int argc, char const *argv[]) {
  /* code */
  FILE* fp = fopen("test.txt", "r");
  if(!fp){
    perror("File opening failed");
    return EXIT_FAILURE;
  }

  int c;
  while((c = fgetc(fp))!= EOF){
    putchar(c);
  }

  if(ferror(fp))
    puts("I/O error when reading");
  else if(feof(fp))
    puts("End of file reached succesfully");

    fclose(fp);
    char option;
    do
    {
        printf("Enter q to quit: ");
        option = getchar();
        while(getchar() != '\n'); //Enter this line here.
    }
    while (option != 'q');
  return 0;
}

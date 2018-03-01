#include <stdio.h>

int main(int argc, char** argv)
{
	char animal[10];
	float weight;
	int age;

	FILE *inputFile = fopen(argv[1], "r");
	fscanf(inputFile,"%s %f %d", animal, &weight, &age);
	
	FILE *outputFile = fopen("output.txt","w");
	fprintf(outputFile,"ANIMAL: %s\nWEIGHT: %f\nAGE:%d\n",animal,weight,age);
	fclose(inputFile);
	fclose(outputFile);
	return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Constant Declarations:
#define POP_SIZE 10
#define CHARMAP "abcdefghijklmnopqrstuvwxyz"\
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"\
		"0123456789"\
		"!@#$%%^&*(_-)+=[]{}<>|\\;:'\",./?~` "

//Function declarations:
void initialization();
void fitnessCalculation();
void selection();
void mutation();
int isDone();

void printPopulation();

//Global Variables:
char *target = "Hello World";
char *population[POP_SIZE];

int main()
{

	initialization();

	while(!isDone())
	{
		fitnessCalculation();
		selection();
		mutation();
		
	}

	printPopulation();

	return 0;
}

//GA Steps - Functions:

void initialization()
{
	int i = 0;
	while(i < POP_SIZE)
	{
		population[i] = malloc(sizeof(target));
		population[i][strlen(target)-1] = '\0';
		i++;
	}
}

void fitnessCalculation(){}

void selection(){}

void mutation(){}

int isDone(){return 1;}

// Helper Functions:
void printPopulation()
{
	for(int i = 0; i < POP_SIZE; i++)
	{
		printf("%s\n",population[i]);
	}
}
/*
char rndchr(char* map)
{
	return *(map+RANDBETWEEN(0, strlen(map)));
}
*/

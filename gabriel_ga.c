#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//Constant Declarations:
#define POP_SIZE 10
#define CHARMAP "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%%^&*(_-)+=[]{}<>|\\;:'\",./?~` "

//Function declarations:
void initialization();
void fitnessCalculation();
void selection();
void mutation();
int isDone();

void printPopulation();
char randchar();

//Global Variables:
char *target = "Hello World";
char *population[POP_SIZE];
char *charmap = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*(_-)+=[]{}<>|;:',./?~` ";

int main()
{
	//Initializing population:
	srand((unsigned int)time(NULL));
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
		for(int j = 0; j < strlen(target); j++)
		{
			population[i][j] = randchar();
		}
		population[i][strlen(target)] = '\0';
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
	printf("%s\n",target);
}

char randchar()
{

	return charmap[rand()%(int)(strlen(charmap)-1)];
}


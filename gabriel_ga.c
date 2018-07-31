#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//Constant Declarations:
#define POP_SIZE 10

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
int fitness[POP_SIZE];

int main()
{
	//Initializing population:
	srand((unsigned int)time(NULL));
	initialization();

	fitnessCalculation();

//	while(fitnessCalculation())
	while(!isDone())
	{
		selection();
		mutation();
	}

	printPopulation();
	
	return 0;
}

//	======================= GA Steps =======================//

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

//The lesser the better. 0 is the optimal value:
void fitnessCalculation()
{
	int i = POP_SIZE-1;
	int j;
	while(i >= 0)
	{
		fitness[i] = 0;
		for (j = (int)sizeof(target)-1; j >= 0; j--) {
			fitness[i] += abs(target[j]-population[i][j]);
		}
		i--;
	}
}

void selection(){}

void mutation(){}

// ========================================================//

// Helper Functions:
int isDone(){return 1;}

void printPopulation()
{
	for(int i = 0; i < POP_SIZE; i++)
	{
		printf("P: %s F: %d\n",population[i],fitness[i]);
	}
	printf("%s\n",target);
}

char randchar()
{

	return charmap[rand()%(int)(strlen(charmap)-1)];
}


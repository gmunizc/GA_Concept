#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//Constant Declarations:
#define POP_SIZE 8192

//Function declarations:
void initialization();
void fitnessCalculation();
void crossover();
void mutation(char *mutant, int n);

int isDone();
void printPopulation();
char randChar();
int randNumb(int n);

//Global Variables:
char *target = "Hello World";
char *population[POP_SIZE];
char *charmap = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*(_-)+=[]{}<>|;:',./?~` ";
int fitness[POP_SIZE];
int best = 500;
int fit = 0;
int distance = 50;
int mutChance = 10;

int main()
{
	//Initializing population:
	srand((unsigned int)time(NULL));
	initialization();

	fitnessCalculation();

//	while(!isDone())
	while(best)
	{
		crossover();
		fitnessCalculation();
		printf("Best:%s - %d\n",population[fit], best);
		printf("dist: %d | mut: %d\n",distance,mutChance);
		//printPopulation();
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
			population[i][j] = randChar();
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
		if(fitness[i] < best)
		{
			best = fitness[i];
			fit = i;
		}
		i--;
	}
}

void crossover()
{	
//	mutation(population[fit],1);			

	int j = 0;
	char *newBorn = population[0];
	for(int i = 0; i < strlen(target); i++)
	{
		//printf("i: %d\n",i);
		while(1)
		{
			//printf("j: %d\n",j);
			if(j >= POP_SIZE)
			{
				j = 0;
			}
			if(fitness[j] <= best + distance)
			{
				//mutation(population[j],randNumb(1));
				newBorn = population[j];
				j++;
				break;
			}
			else
			{
				//newBorn = population[j];
				for(int n = 0; n < strlen(target)/5; n++)
				{
					population[j][randNumb(strlen(target))] = newBorn[randNumb(strlen(target))];
				}
				mutation(population[j],randNumb(strlen(target)/2));
			}
			j++;
		}
	}
	if(distance > 0)
	{
		distance --;
	}
	if(distance == 0)
	{
		distance = 100;
	}
/*	if(distance < 0)
	{
		distance = 5;
	}
*/
}

void mutation(char *mutant, int n)
{
	for(int k = 0; k < n; k++)
	{
		mutant[randNumb(strlen(target))] = randChar();
	}

	
	if(best < 15)
	{
		mutChance = 6;
	}
	if(mutChance > 3)
	{
		mutChance--;
	}
}

// ========================================================//

// Helper Functions:
int isDone(){return 1;}

void printPopulation()
{
	for(int i = 0; i < POP_SIZE; i++)
	{
		printf("P: %s F: %d\n",population[i],fitness[i]);
	}
	printf("Target: %s\n",target);
	printf("Best: %s - %d\n",population[fit],best);
}

char randChar()
{

	return charmap[randNumb(strlen(charmap)-1)];
}

int randNumb(int n)
{
	return (rand()%(int)(n));
}


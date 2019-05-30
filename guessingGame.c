#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

struct guess
{
	int number;
	bool correctGuess;
};

int takeInput()
{
	int input;
	scanf("%d", &input);
	return input;
}

int generateRandomNumber()
{
	int number= rand() % 10 + 1;
	return number;
}

void initializeArray(int* array)
{
	array[0]= 0;
	array[1]= 0;
	array[2]= 0;
}

void initializeTargetArray(int* array)
{
	srand(time(NULL));
	array[0]= generateRandomNumber();
	array[1]= generateRandomNumber();
	array[2]= generateRandomNumber();
}

void makeStructGuesses(struct guess *mainGuessArray, int* array)
{
	int i=0;
	for(i;i<3;i++)
	{
		mainGuessArray[i].number= array[i];
		mainGuessArray[i].correctGuess= 0;
	}
}

void printGuesses(struct guess *mainGuessArray)
{
	int i=0;
	for(i;i<3;i++)
	{
		printf("%d\n", mainGuessArray[i].number);
		printf("%d\n", mainGuessArray[i].correctGuess);
		printf("\n");
	}
}

int compare(struct guess *mainGuessArray, int* inputArray)
{
	if((mainGuessArray[0].number==inputArray[0])&&(mainGuessArray[1].number==inputArray[1])&&(mainGuessArray[2].number==inputArray[2]))
	{
		return 4;
	}
	else
	{
		int i=0;
		int count= 0;
		for(i;i<3;i++)
		{
			int toFind= inputArray[i];
			int j=0;
			for(j;j<3;j++)
			{
				if((toFind==mainGuessArray[j].number)&&(mainGuessArray[j].correctGuess==0))
				{
					count++;
					mainGuessArray[j].correctGuess= 1;
				}
			}
		}
		return count;
	}
}

int givePoints(int correctGuesses)
{
	if(correctGuesses==0)
	{
		return 0;
	}
	if(correctGuesses==1)
	{
		return 10;
	}
	if(correctGuesses==2)
	{
		return 100;
	}
	if(correctGuesses==3)
	{
		return 1000;
	}
	if(correctGuesses==4)
	{
		return 1000000;
	}
}

int main()
{	
	int* inputs= malloc(3*sizeof(*inputs));
	initializeArray(inputs);
	int* target= malloc(3*sizeof(*inputs));
	initializeTargetArray(target);

	struct guess *mainGuessArray= malloc(3*sizeof(*mainGuessArray));
	makeStructGuesses(mainGuessArray, target);

	//Printing the randomly generated numbers to cross-check
	//printf("%d\n",target[0]);
	//printf("%d\n",target[1]);
	//printf("%d\n",target[2]);

	printf("Guess 3 numbers between 0 to 10:\n");
	int i=0;
	for(i;i<3;i++)
	{
		inputs[i]= takeInput();
	}

	int correctGuesses= compare(mainGuessArray,inputs);
	int totalPoints= givePoints(correctGuesses);
	printf("You scored %d points!\n",totalPoints);
	if(correctGuesses==4)
	{
		printf("You guessed all 3 in the correct order!!\n");
	}
	else
	{
		printf("You correctly guessed %d number(s)\n", correctGuesses);
	}
}
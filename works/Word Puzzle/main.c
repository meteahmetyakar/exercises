#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


#define SIZECOLUMN 15
#define SIZEROW 15

void fetchDataFromTxt(int numberOfData, char wordArray[][100]);
void fillUniqueNumbers(int array[], int arraySize, int limit);
int isThereInArray(int number, int array[], int arraySize);

enum directions {LEFT_TO_RIGHT, RIGHT_TO_LEFT, UP_TO_DOWN, DOWN_TO_UP, LEFT_UP_CROSS, RIGHT_UP_CROSS, LEFT_DOWN_CROSS, RIGHT_DOWN_CROSS};

int main()
{
	srand(time(NULL));
	char wordArray[7][100];
	int numberOfData = 7;
	int dataIndexes[numberOfData];
	fetchDataFromTxt(numberOfData, wordArray);


	printf("\n");
	for(int i=0; i<numberOfData; i++)
		printf("%s - ", wordArray[i]);

	char map[SIZECOLUMN][SIZEROW];
	fillMap(numberOfData, wordArray, map);

}

void fillMap(int numberOfData ,char wordArray[][100], char map[SIZECOLUMN][SIZEROW])
{
	int direction;
	int isCellAvailable, isDirectionAvailable=0;
	int row, column;
	int lenghtOfData;

	for(int i=0; i<SIZEROW; i++)
		for(int j=0; j<SIZECOLUMN; j++)
			map[i][j] = ' ';

	for(int i=0; i<numberOfData; i++)
	{
		lenghtOfData = strlen(wordArray[i]);
		isCellAvailable = 0;
		while(!isCellAvailable)
		{
			column = rand() % SIZECOLUMN;
			row = rand() % SIZEROW;
			if(map[column][row] == ' ')
			{
				while(!isDirectionAvailable)
				{

					if()
				}
			}
		}

	}

}

int writeWord(char map[SIZEROW][SIZECOLUMN], char word[100])
{
	int isDirectionAvailable;
	int direction;
	int counter=0;

	int directionMap[8];
	for(int i=0; i<8; i++)
		directionMap[i] = 0;

	while(counter != 8)
	{
		isDirectionAvailable = 0;
		do
		{
			direction = rand() % 8;
			if(directionMap[direction] == 0)
			{
				directionMap[direction] = 1;
				isDirectionAvailable = 1;
				counter++;
			}

		}while(!isDirectionAvailable);

		if(direction = LEFT_TO_RIGHT)
		{

		}
		else if(direction = RIGHT_TO_LEFT)
		{

		}
		else if(direction = UP_TO_DOWN)
		else if(direction = DOWN_TO_UP)
		else if(direction = LEFT_UP_CROSS)
		else if(direction = RIGHT_UP_CROSS)
		else if(direction = LEFT_DOWN_CROSS)
		else if(direction = RIGHT_DOWN_CROSS)


	}



}

void fetchDataFromTxt(int numberOfData, char wordArray[][100])
{
	FILE *fp;
	fp = fopen("wordlist.txt", "r");

	int dataIndexes[numberOfData];
	char temp[100];



	fillUniqueNumbers(dataIndexes, numberOfData, 49);

	for(int i=0; i<numberOfData; i++)
		printf("%d - ", dataIndexes[i]);

	for(int i=0; i<numberOfData; i++)
	{
		for(int k=0; k<dataIndexes[i]; k++)
		{
			if(k == dataIndexes[i]-1)
				fscanf(fp, "%s", wordArray[i]);
			else
				fscanf(fp, "%s", temp);
		}
		rewind(fp);
	}

}

int isThereInArray(int number, int array[], int arraySize)
{
	for(int i=0; i<arraySize; i++)
		if(array[i] == number) return 1;

	return 0;
}

void fillUniqueNumbers(int array[], int arraySize, int limit)
{
	int number;
	int isUnique;

	for(int i=0; i<arraySize; i++)
		array[i] = -1;

	for(int i=0; i<arraySize; i++)
	{
		isUnique = 0;
		while(!isUnique)
		{
			number = rand() % limit +1;
			if(!isThereInArray(number, array, arraySize))
			{
				array[i] = number;
				isUnique = 1;
			}
		}
	}
}

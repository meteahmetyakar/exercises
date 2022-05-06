#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#define COLUMNSIZE 15
#define ROWSIZE 15
#define DIRECTION_LIMIT 8
#define NUMBEROFDATA 7

void fetchDataFromTxt(char wordArray[][100]);						//fetching random words from wordlist.txt
void fillMap(char wordArray[][100], char map[ROWSIZE][COLUMNSIZE]);	//filling map with correct words and random characters
void printMap(char map[ROWSIZE][COLUMNSIZE]);						//printing the given array
void fillUniqueNumbers(int array[], int arraySize, int limit); 		//filling array with random unique numbers

int isThereInArray(int number, int array[], int arraySize); 		//checking number in array, if there is in array, function returns 1
int setCorrectWord(char map[ROWSIZE][COLUMNSIZE], int columnIndex, int rowIndex, char word[100]);	//adding word with random direction to map
int findWord(char word[100], char map[ROWSIZE][COLUMNSIZE], int columnIndex, int rowIndex); 		//checking word, if there is in given column-row indexes return 1 else 0
int checkQuit();													//Checking if the user has entered :q

void setTextColor(int colorCode); 									//changing the terminal color
void clearBuffer();

enum directions {LEFT_TO_RIGHT, RIGHT_TO_LEFT, UP_TO_DOWN, DOWN_TO_UP, LEFT_UP_CROSS, RIGHT_UP_CROSS, LEFT_DOWN_CROSS, RIGHT_DOWN_CROSS};
enum colors {reset, green};

int main()
{
	srand(time(NULL));

	char wordArray[NUMBEROFDATA][100];
	int dataIndexes[NUMBEROFDATA];
	fetchDataFromTxt(wordArray); 			//fetching datas from txt and adding NUMBEROFDATA numbers to the array

	char map[COLUMNSIZE][ROWSIZE];
	for(int i=0; i<ROWSIZE; i++) 			//in this for loop, we fill map with space character for deleting garbage values
		for(int j=0; j<COLUMNSIZE; j++)
			map[i][j] = ' ';


	fillMap(wordArray, map);
	printMap(map);

	char word[100];
	int row, column;

	int isCorrectFormat, isQuit=0;
	int health = 3, correctCounter = 0,totalPoint = 0;

	while(health > 0 && !isQuit && correctCounter < NUMBEROFDATA)
	{
		printf("\nEnter coordinates and word:");
		isCorrectFormat = scanf("%d %d %s", &row, &column, word); 	//if scanf returns 0, this mean it cannot take %d %d %s format
		if(!isCorrectFormat)		//if isCorrectFormat equal to 0
		{
			isQuit = checkQuit();	//given values could not add to variables because of invalid format, that's why this values waiting on buffer. And we check buffer with CheckQuit and then we clearing the buffer
			if(!isQuit)				//if isQuit equal to 1, this mean is user has entered :q, if it equal to 0, user has entered wrong input and we printing error
				printf("\n\nInvalid Format! TRY AGAIN!\n\n");
		}
		else	//enter if if correct format
		{
			if(findWord(word, map, row, column) == 0) //if given word is not in given row-column findWord function returns 0
			{
				health--;
				if(health != 0)
					printf("\n\nWrong choice! You have only %d lefts\n\n", health);
			}
			else
			{
				totalPoint += 2;
				correctCounter++;
				printf("\n\nFounded! You got 2 point. Your total points: %d\n\n", totalPoint);

			}
			printMap(map);
		}

	}

	printf("Your total points: %d", totalPoint);


}

void fetchDataFromTxt(char wordArray[][100])
{
	FILE *fp;
	fp = fopen("wordlist.txt", "r");

	int dataIndexes[NUMBEROFDATA];	//it holds which will fetch words of index in txt
	char temp[100];

	fillUniqueNumbers(dataIndexes, NUMBEROFDATA, 49); //filling given array till NUMBEROFDATA, 49 is limit of index

	for(int i=0; i<NUMBEROFDATA; i++)
	{
		for(int k=0; k<dataIndexes[i]; k++) //it loops until k equal to index in dataIndexes
		{
			if(k == dataIndexes[i]-1)	//if k reach the target index
				fscanf(fp, "%s", wordArray[i]);	//take word
			else
				fscanf(fp, "%s", temp);	//if k is not reach the target index, pass the current word
		}
		rewind(fp);
	}

	fclose(fp);
}

void fillUniqueNumbers(int array[], int arraySize, int limit)
{
	int number;
	int isUnique;

	for(int i=0; i<arraySize; i++) //filling array with -1 for garbage values
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

int isThereInArray(int number, int array[], int arraySize)
{
	for(int i=0; i<arraySize; i++)
		if(array[i] == number) return 1;

	return 0;
}

void fillMap(char wordArray[][100], char map[ROWSIZE][COLUMNSIZE])
{
	char word[100];

	int direction;
	int isCellEmpty, isWritten=1;
	int rowIndex, columnIndex;
	int lenghtOfData;
	int situation;


	for(int i=0; i<NUMBEROFDATA; i++)
	{
		strcpy(word, wordArray[i]);
		lenghtOfData = strlen(word);

		isCellEmpty = 0;
		while(!isCellEmpty || !isWritten) //if cell is not empty and word has not written to array, it loops
		{
			columnIndex = rand() % COLUMNSIZE;	//generate random column index
			rowIndex = rand() % ROWSIZE;		//generate random row index
			if(map[rowIndex][columnIndex] == ' ')	//if that row-column is empty
			{
				isCellEmpty = 1;
				isWritten = setCorrectWord(map, columnIndex, rowIndex, word);	//setting correct word to map, if it cannot do that, it means there is no available direction for write the word, that function return 0, if has written it returns 1
			}
			else
				isCellEmpty = 0;
		}

	}



	 	/* IF YOU OPEN THIS BLOCK IT PRINTS ANSWER KEY */

			printMap(map);
			printf("\n");
			printf("YOU CAN TURN OFF ANSWERS FROM MAIN.C LINE 180");
			printf("\n\n\n");





	for(int i=0; i<ROWSIZE; i++)	//filling empty cells of the map with random characters
		for(int j=0; j<COLUMNSIZE; j++)
			if(map[i][j] == ' ')
				map[i][j] = 'a' + rand() % 26;


}

int setCorrectWord(char map[ROWSIZE][COLUMNSIZE], int columnIndex, int rowIndex, char word[100])
{
	int direction, tryingCounter=0;
	int directionMap[DIRECTION_LIMIT]; //we check the directions with this array, it check only one time whole directions with this

	for(int i=0; i<DIRECTION_LIMIT; i++)
		directionMap[i] = 0;



	int lenghtOfData = strlen(word);
	int isThereCharOnWay;

	int isCollideRight, isCollideLeft, isCollideUp, isCollideDown;

	/* checking if collides border */
	isCollideRight = (COLUMNSIZE < columnIndex + lenghtOfData);
	isCollideLeft = (-1 > columnIndex - lenghtOfData);
	isCollideUp = (-1 > rowIndex - lenghtOfData);
	isCollideDown = (ROWSIZE < rowIndex + lenghtOfData);

	while(tryingCounter < DIRECTION_LIMIT)	//if tryinCounter equal to direction limit this mean all directions checked
	{
		direction = rand() % DIRECTION_LIMIT;
		isThereCharOnWay = 0;
		switch(direction)
		{
			case LEFT_TO_RIGHT:
				if(!isCollideRight && directionMap[LEFT_TO_RIGHT] == 0)	//if there is no char on direction way it fill the direction as correct word
				{
					directionMap[LEFT_TO_RIGHT] = 1;
					tryingCounter++;

					for(int i=0; i<lenghtOfData; i++)
					{
						if(map[rowIndex][columnIndex+i] != ' ')
						{
							isThereCharOnWay = 1;
							break;
						}
					}

					if(!isThereCharOnWay)
					{
						for(int i=0; i<lenghtOfData; i++)
							map[rowIndex][columnIndex+i] = word[i];

						return 1;

					}
				}
				break;

			case RIGHT_TO_LEFT:
				if(!isCollideLeft && directionMap[RIGHT_TO_LEFT] == 0) //if there is no char on direction way it fill the direction as correct word
				{
					directionMap[RIGHT_TO_LEFT] = 1;
					tryingCounter++;

					for(int i=0; i<lenghtOfData; i++)
					{
						if(map[rowIndex][columnIndex-i] != ' ')
						{
							isThereCharOnWay = 1;
							break;
						}
					}

					if(!isThereCharOnWay)
					{
						for(int i=0; i<lenghtOfData; i++)
							map[rowIndex][columnIndex-i] = word[i];

						return 1;

					}
				}
				break;

			case UP_TO_DOWN:
				if(!isCollideDown && directionMap[UP_TO_DOWN] == 0) //if there is no char on direction way it fill the direction as correct word
				{
					directionMap[UP_TO_DOWN] = 1;
					tryingCounter++;

					for(int i=0; i<lenghtOfData; i++)
					{
						if(map[rowIndex+i][columnIndex] != ' ')
						{
							isThereCharOnWay = 1;
							break;
						}
					}

					if(!isThereCharOnWay)
					{
						for(int i=0; i<lenghtOfData; i++)
							map[rowIndex+i][columnIndex] = word[i];

						return 1;

					}
				}
				break;

			case DOWN_TO_UP:
				if(!isCollideUp && directionMap[DOWN_TO_UP] == 0) //if there is no char on direction way it fill the direction as correct word
				{
					directionMap[DOWN_TO_UP] = 1;
					tryingCounter++;

					for(int i=0; i<lenghtOfData; i++)
					{
						if(map[rowIndex-i][columnIndex] != ' ')
						{
							isThereCharOnWay = 1;
							break;
						}
					}

					if(!isThereCharOnWay)
					{
						for(int i=0; i<lenghtOfData; i++)
							map[rowIndex-i][columnIndex] = word[i];

						return 1;

					}
				}
				break;

			case LEFT_UP_CROSS:
				if(!isCollideLeft && !isCollideUp && directionMap[LEFT_UP_CROSS] == 0) //if there is no char on direction way it fill the direction as correct word
				{
					directionMap[LEFT_UP_CROSS] = 1;
					tryingCounter++;

					for(int i=0; i<lenghtOfData; i++)
					{
						if(map[rowIndex-i][columnIndex-i] != ' ')
						{
							isThereCharOnWay = 1;
							break;
						}
					}

					if(!isThereCharOnWay)
					{
						for(int i=0; i<lenghtOfData; i++)
							map[rowIndex-i][columnIndex-i] = word[i];

						return 1;

					}
				}
				break;

			case RIGHT_UP_CROSS: 
				if(!isCollideRight && !isCollideUp && directionMap[RIGHT_UP_CROSS] == 0) //if there is no char on direction way it fill the direction as correct word
				{
					directionMap[RIGHT_UP_CROSS] = 1;
					tryingCounter++;

					for(int i=0; i<lenghtOfData; i++)
					{
						if(map[rowIndex-i][columnIndex+i] != ' ')
						{
							isThereCharOnWay = 1;
							break;
						}
					}

					if(!isThereCharOnWay)
					{
						for(int i=0; i<lenghtOfData; i++)
							map[rowIndex-i][columnIndex+i] = word[i];

						return 1;

					}
				}
				break;

			case LEFT_DOWN_CROSS:
				if(!isCollideLeft && !isCollideDown && directionMap[LEFT_DOWN_CROSS] == 0) //if there is no char on direction way it fill the direction as correct word
				{
					directionMap[LEFT_DOWN_CROSS] = 1;
					tryingCounter++;

					for(int i=0; i<lenghtOfData; i++)
					{
						if(map[rowIndex+i][columnIndex-i] != ' ')
						{
							isThereCharOnWay = 1;
							break;
						}
					}

					if(!isThereCharOnWay)
					{
						for(int i=0; i<lenghtOfData; i++)
							map[rowIndex+i][columnIndex-i] = word[i];

						return 1;

					}
				}
				break;

			case RIGHT_DOWN_CROSS:
				if(!isCollideRight && !isCollideDown && directionMap[RIGHT_DOWN_CROSS] == 0) //if there is no char on direction way it fill the direction as correct word
				{
					directionMap[RIGHT_DOWN_CROSS] = 1;
					tryingCounter++;

					for(int i=0; i<lenghtOfData; i++)
					{
						if(map[rowIndex+i][columnIndex+i] != ' ')
						{
							isThereCharOnWay = 1;
							break;
						}
					}

					if(!isThereCharOnWay)
					{
						for(int i=0; i<lenghtOfData; i++)
							map[rowIndex+i][columnIndex+i] = word[i];

						return 1;
					}
				}
				break;

		}
	}

	return 0;

}

void printMap(char map[COLUMNSIZE][ROWSIZE]) //printing given map(matrix)
{
	for(int i=0; i<ROWSIZE; i++)
	{
		for(int j=0; j<COLUMNSIZE; j++)
		{
			if(map[i][j] == 'X')
				setTextColor(green);

			printf("%c ", map[i][j]);
			setTextColor(reset);
		}

		printf("\n");

	}
}

int checkQuit()	//checking if user enter :q
{
	char input[100], c;
	int i=0;

	do
	{
		c = getchar();

		/* clearing buffer and add values to input array */
		if(c == '\n')
			input[i] = '\0';
		else
			input[i] = c;

		i++;

	}while(c != '\n');

	//when we come here buffer has been clear and input array filled

	if(strcmp(input, ":q") == 0) //we check input if it equal to :q return 1 and quit the game
		return 1;
	else
		return 0;

}

int findWord(char word[100], char map[ROWSIZE][COLUMNSIZE], int rowIndex, int columnIndex)
{
	int direction=0, isCorrect;

	int lenghtOfData = strlen(word);

	int isCollideRight, isCollideLeft, isCollideUp, isCollideDown;

	direction = LEFT_TO_RIGHT;

	isCollideRight = (COLUMNSIZE < columnIndex + lenghtOfData);
	isCollideLeft = (-1 > columnIndex - lenghtOfData);
	isCollideUp = (-1 > rowIndex - lenghtOfData);
	isCollideDown = (ROWSIZE < rowIndex + lenghtOfData);

	while(direction < DIRECTION_LIMIT)
	{
		isCorrect = 1;
		switch(direction) /* checking all directions and if find correct word then way filling with X character*/
		{
			case LEFT_TO_RIGHT:
				if(!isCollideRight)
				{
					for(int i=0; i<lenghtOfData; i++)
					{
						if(map[rowIndex][columnIndex+i] != word[i])
						{
							isCorrect = 0;
							break;
						}
					}

					if(isCorrect)
					{
						for(int i=0; i<lenghtOfData; i++)
							map[rowIndex][columnIndex+i] = 'X';

						return 1;
					}

				}
				direction++;
				break;

			case RIGHT_TO_LEFT:

				if(!isCollideLeft)
				{

					for(int i=0; i<lenghtOfData; i++)
					{
						if(map[rowIndex][columnIndex-i] != word[i])
						{
							isCorrect = 0;
							break;
						}
					}

					if(isCorrect)
					{
						for(int i=0; i<lenghtOfData; i++)
							map[rowIndex][columnIndex-i] = 'X';

						return 1;
					}
				}

				direction++;
				break;

			case UP_TO_DOWN:

				if(!isCollideDown)
				{

					for(int i=0; i<lenghtOfData; i++)
					{
						if(map[rowIndex+i][columnIndex] != word[i])
						{
							isCorrect = 0;
							break;
						}
					}

					if(isCorrect)
					{
						for(int i=0; i<lenghtOfData; i++)
							map[rowIndex+i][columnIndex] = 'X';

						return 1;
					}

				}

				direction++;
				break;

			case DOWN_TO_UP:

				if(!isCollideUp)
				{

					for(int i=0; i<lenghtOfData; i++)
					{
						if(map[rowIndex-i][columnIndex] != word[i])
						{
							isCorrect = 0;
							break;
						}
					}

					if(isCorrect)
					{
						for(int i=0; i<lenghtOfData; i++)
							map[rowIndex-i][columnIndex] = 'X';

						return 1;
					}
				}

				direction++;
				break;

			case LEFT_UP_CROSS:

				if(!isCollideLeft)
				{

					for(int i=0; i<lenghtOfData; i++)
					{
						if(map[rowIndex-i][columnIndex-i] != word[i])
						{
							isCorrect = 0;
							break;
						}
					}

					if(isCorrect)
					{
						for(int i=0; i<lenghtOfData; i++)
							map[rowIndex-i][columnIndex-i] = 'X';

						return 1;
					}
				}

				direction++;
				break;

			case RIGHT_UP_CROSS:

				if(!isCollideRight)
				{

					for(int i=0; i<lenghtOfData; i++)
					{
						if(map[rowIndex-i][columnIndex+i] != word[i])
						{
							isCorrect = 0;
							break;
						}
					}

					if(isCorrect)
					{
						for(int i=0; i<lenghtOfData; i++)
							map[rowIndex-i][columnIndex+i] = 'X';

						return 1;
					}
				}

				direction++;
				break;

			case LEFT_DOWN_CROSS:

				if(!isCollideLeft && !isCollideDown)
				{

					for(int i=0; i<lenghtOfData; i++)
					{
						if(map[rowIndex+i][columnIndex-i] != word[i])
						{
							isCorrect = 0;
							break;
						}
					}

					if(isCorrect)
					{
						for(int i=0; i<lenghtOfData; i++)
							map[rowIndex+i][columnIndex-i] = 'X';

						return 1;
					}
				}

				direction++;
				break;

			case RIGHT_DOWN_CROSS:

				if(!isCollideRight && !isCollideDown)
				{

					for(int i=0; i<lenghtOfData; i++)
					{
						if(map[rowIndex+i][columnIndex+i] != word[i])
						{
							isCorrect = 0;
							break;
						}
					}

					if(isCorrect)
					{
						for(int i=0; i<lenghtOfData; i++)
							map[rowIndex+i][columnIndex+i] = 'X';

						return 1;
					}
				}

				direction++;
				break;
		}
	}
	return 0;
}

void setTextColor(int colorCode) //it changes text color on terminal
{
    if(colorCode == 0)
        printf("\033[0m");      //reset
    else if(colorCode == 1)
        printf("\033[0;32m");   //green
}




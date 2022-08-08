#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* area size */
#define COLUMNSIZE 30
#define ROWSIZE 15

enum colors {yellow, blue, green, red, reset};	//using for change the color of terminal text
enum ways {right, down, left, up};				//using for moving direction
enum players {P1, P2};							//used to indicate players


int dice();
int startGame();
void printMap();

/* movement and movement control functions */
int play(int player);
int movePlayer1(int step);
int movePlayer2(int step);
void penalty(int player,int array[], int index, int way);

/* area placement and clear functions */
void putPlayers();
void fillSigns();
void clearLocation(int player);

void setTextColor(int color);


/* Locations of X characters for penalty */
int locationsOfX[9][2] = {
	{1,14},
	{3,10},
	{3,18},
	{5,26},
	{7,28},
	{10,26},
	{11,10},
	{11,18},
	{13,14},
};

/* these arrays will use for locations of players. first assignments are start locations */
int player1[2] = {1,1};
int player2[2] = {3,3};

/* empty game area */
char gameArea[ROWSIZE][COLUMNSIZE] = {
	"..............................",
	":                            :",
	": .......................... :",
	": :                        : :",
	": : ...................... : :",
	": : :                    : : :",
	": : :                    : : :",
	": : :                    : : :",
	": : :                    : : :",
	": : :                    : : :",
	": : ...................... : :",
	": :                        : :",
	": .......................... :",
	":                            :",
	"..............................",
};

int main()
{

	int whoWillStart;
	int diceP1, diceP2;
	int situationP1, situationP2;
	int isOver = 0;

	srand(time(NULL));

	/* filling map with players and signs and then printing */
	putPlayers();
	fillSigns();
	printMap();

	printf("To start to game, players should dice and decide who is going to start first according to it...\n");

	whoWillStart = startGame();
	printf(" *** PLAYER %d will start the game... ***\n", whoWillStart);

	while(!isOver)
	{
		if(whoWillStart == 1)
		{
			diceP1 = play(P1);
			diceP2 = play(P2);
		}
		else
		{
			diceP2 = play(P2);
			diceP1 = play(P1);
		}

		situationP1 = movePlayer1(diceP1);
		if(situationP1 == 1)
		{
			setTextColor(yellow);
			printf("\n\n\n\n *** PLAYER 1 WON THE GAME ***\n\n");

			putPlayers();

			printMap();
			isOver = 1;
		}

		situationP2 = movePlayer2(diceP2);

		if(situationP2 == 1)
		{
			setTextColor(blue);
			printf("\n\n\n\n *** PLAYER 2 WON THE GAME ***\n\n");

			putPlayers();

			printMap();
			isOver = 1;
		}

		if(!isOver)
		{
			putPlayers();
			printMap();
		}
	}

}

int dice()	//it returns 1-6
{
	return rand() % 6 +1;
}

void printMap()	//printing the game map
{
	int xloc=0;
	for(int i=0; i<15; i++)
	{
		for(int j=0; j<30; j++)
		{
			setTextColor(reset);
			if(i==locationsOfX[xloc][0] && j==locationsOfX[xloc][1])	//if in location of X then text color will be red for print X
			{
				setTextColor(red);
				xloc++;
			}
			else if((i == 2 && j == 1) || (i==4 && j==3))	//for printing _ symbol
				setTextColor(green);

			if(i == player1[0] && j == player1[1])	//for printing player 1
				setTextColor(yellow);

			if(i == player2[0] && j == player2[1]) //for printing player 1
				setTextColor(blue);

			printf("%c", gameArea[i][j]);	//printing the game area
		}
		printf("\n");
	}
}

int startGame()	//it returns which player will start the game
{
	int diceP1, diceP2;
	char enter;
	do{
		diceP1 = play(P1);
		diceP2 = play(P2);

		setTextColor(reset);

		if(diceP1 == diceP2)
			printf("Same dice value... Please try again.\n");

	}while(diceP1 == diceP2);

	if(diceP1 > diceP2)
		return 1;
	else
		return 2;
}

int movePlayer1(int step)	//moving player1 in array
{
	clearLocation(P1);

	if(player1[1] < 28 && player1[0] == 1)			//this block for player goes right
	{
		player1[1] += step;

		if(player1[1] == 14)					//penalty check
			penalty(P1, player1, 1, right);

		if(player1[1] > 28)						//border control, if enter this player changes its direction
		{
			player1[0] += player1[1] % 28;
			player1[1] = 28;
		}

	}
	else if(player1[1] == 28 && player1[0] < 13)	//this block for player goes down
	{

		player1[0] += step;

		if(player1[0] == 7)						//penalty check
			penalty(P1, player1, 0, down);

		if(player1[0] > 13)						//border control, if enter this player changes its direction
		{
			player1[1] -= player1[0] % 13;
			player1[0] = 13;
		}
	}
	else if(player1[0] == 13 && player1[1] > 1)		//this block for player goes left
	{

		player1[1] -= step;

		if(player1[1] == 14)					//penalty check
			penalty(P1, player1, 1, left);


		if(player1[1] < 1)						//border control, if enter this player changes its direction
		{
			player1[1] *= -1;
			player1[0] -= player1[1] % 28;
			player1[1] = 1;
		}

	}
	else if(player1[1] == 1 && player1[0] > 0)		//this block for player goes up
	{
		player1[0] -= step;
		if(player1[0] <= 1)						//border control, if enter this player changes its direction and return 1 if player win
		{
			player1[0] *= -1;
			player1[1] += player1[0] % 13;
			player1[0] = 1;
			return 1;
		}

	}

	return 0;


}

int movePlayer2(int step)	//moving player2 in array
{
	clearLocation(P2);


	if(player2[1] < 26 && player2[0] == 3)		//this block for player goes right
	{
		player2[1] += step;

		if(player2[1] == 10 || player2[1] == 18)	//penalty check
			penalty(P2, player2, 1, right);

		if(player2[1] > 26)						//border control, if enter this player changes its direction
		{
			player2[0] += player2[1] % 26;

			if(player2[0] == 5)					//penalty check
				penalty(P2, player2, 0, down);

			player2[1] = 26;
		}

	}
	else if(player2[1] == 26 && player2[0] < 11)	//this block for player goes down
	{

		player2[0] += step;

		if(player2[0] == 5 || player2[0] == 10)	//penalty check
			penalty(P2, player2, 0, down);

		if(player2[0] > 11)					//border control, if enter this player changes its direction
		{
			player2[1] -= player2[0] % 11;
			player2[0] = 11;
		}
	}
	else if(player2[0] == 11 && player2[1] > 1)	//this block for player goes left
	{

		player2[1] -= step;

		if(player2[1] == 10 || player2[1] == 18)	//penalty check
			penalty(P2, player2, 1, left);


		if(player2[1] <= 3)					//border control, if enter this player changes its direction
		{
			if(player2[1] < 0)
				player2[1] *= -1;

			player2[0] -= player2[1] % 3;
			player2[1] = 3;
		}

	}
	else if(player2[1] == 3 && player2[0] > 2)	//this block for player goes up
	{
		player2[0] -= step;
		if(player2[0] < 5)
		{
			if(player2[0] < 0)
				player2[0] *= -1;

			player2[1] += player2[0] % 3;
			player2[0] = 3;
			return 1;
		}

	}


}


void clearLocation(int player)	//clearing the locations of player. this function is used to delete players' old places
{
	if(player == P1)
		gameArea[player1[0]][player1[1]] = ' ';
	else if(player == P2)
		gameArea[player2[0]][player2[1]] = ' ';
}


void putPlayers()	//location of players putting the map
{
	gameArea[player1[0]][player1[1]] = '1';
	gameArea[player2[0]][player2[1]] = '2';
}

int play(int player) //the selected player rolls the dice
{
	int dicep;
	if(player == P1)
		setTextColor(yellow);
	else if(player == P2)
		setTextColor(blue);

	printf("PLAYER %d... press ENTER to dice", player+1);
	getchar();
	dicep = dice();
	printf("DICE: %d\n", dicep);

	return dicep;
}


void setTextColor(int color) //it changes text color on terminal
{
    if(color == yellow)
		printf("\033[0;33m");
	else if(color == blue)
        printf("\033[0;34m");
    else if(color == green)
        printf("\033[0;32m");
    else if(color == red)
		printf("\033[0;31m");
	else if(color == reset)
        printf("\033[0m");

}

void penalty(int player,int array[], int index, int way) //The player go to back two steps if this function run
{
	if(player == P1)
		setTextColor(yellow);
	else if(player == P2)
		setTextColor(blue);

	printf("penalty for player%d\n", player+1);

	if(way == right || way == down)
		array[index] -= 2;
	else if(way == left || way == up)
		array[index] += 2;
}

void fillSigns()	//filling X and _ symbols to array
{
	for(int i=0; i<9; i++)
	{
		int r_index = locationsOfX[i][0];
		int c_index = locationsOfX[i][1];
		gameArea[r_index][c_index] = 'X';
	}

	gameArea[2][1] = '_';
	gameArea[4][3] = '_';
}

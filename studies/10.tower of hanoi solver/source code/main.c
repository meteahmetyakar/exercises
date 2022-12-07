#include <stdio.h>
#include <stdlib.h>
#include <string.h>

<<<<<<< HEAD


#define STACK_BLOCK_SIZE 10

enum directions {left, right};
=======
#define STACK_BLOCK_SIZE 10

enum directions {right, left};
>>>>>>> 091ee0628d8bc91fcc4e7825e4fc267dc9ffa505

typedef int data_type;

typedef struct {
	data_type *array;
<<<<<<< HEAD
	int id;
=======
>>>>>>> 091ee0628d8bc91fcc4e7825e4fc267dc9ffa505
	int currentsize;
	int maxsize;
}stack;

<<<<<<< HEAD
struct node {
    stack *pole;
    struct node * next;
	struct node * prev;
};
=======
typedef struct node{
    stack *pole;
	int id;
    struct node * next;
	struct node * prev;
}node;
>>>>>>> 091ee0628d8bc91fcc4e7825e4fc267dc9ffa505


int push(stack *s, int d); 	/* the stack array will grow STACK_BLOCK_SIZE entries at a time */
data_type pop(stack *s); 	/* the stack array will shrink STACK_BLOCK_SIZE entries at a time */
stack *init_return(); 		/* initializes an empty stack */
int init(stack *s); 		/* returns 1 if initialization is successful */
void printPole(stack *s, char name);
<<<<<<< HEAD
struct node* switchPole(struct node *pole, int direction);
=======
node* switchPole(node* pole, int direction);
int clearBuffer();
>>>>>>> 091ee0628d8bc91fcc4e7825e4fc267dc9ffa505
int isEmpty(data_type *array);



int main()
{
<<<<<<< HEAD
=======
	/* Initializing stacks and circular linked list */
>>>>>>> 091ee0628d8bc91fcc4e7825e4fc267dc9ffa505
	stack *leftPole;
	stack *midPole;
	stack *rightPole;

	leftPole = init_return();
	midPole = init_return();
	rightPole = init_return();

<<<<<<< HEAD
	midPole -> id = 2;
	rightPole -> id = 3;
	//fillPole(midPole, "b");
	//fillPole(rightPole, "c");


	struct node *lP;
	struct node *mP;
	struct node *rP;
	struct node *currentPole;
	struct node *prevPushed;
	struct node *prevPopped;

	int towerSize;
	printf("Enter Tower size: ");
	scanf("%d", &towerSize);

	lP = malloc(sizeof(struct node));
	mP = malloc(sizeof(struct node));
	rP = malloc(sizeof(struct node));
	currentPole = malloc(sizeof(struct node));

	prevPushed = malloc(sizeof(struct node));
	prevPushed = NULL;

	prevPopped = malloc(sizeof(struct node));
	prevPopped = NULL;

=======
	if(!init(leftPole) || !init(midPole) || !init(rightPole))
	{
		printf("\n### STACK FAILED TO INITIALIZE, TRY AGAIN ###\n");
		return 0;
	}

	//I used circular linked list for passing stacks, I only use this to switch between poles, linked lists don't matter much in the flow of the program, everything is done with stacks.
	node *lP;
	node *mP;
	node *rP;
	node *currentPole;
	node *prevPushed;
	node *prevPopped;

	lP = malloc(sizeof(node));
	mP = malloc(sizeof(node));
	rP = malloc(sizeof(node));
	currentPole = malloc(sizeof(node));

	prevPushed = malloc(sizeof(node));
	prevPushed = NULL;

	prevPopped = malloc(sizeof(node));
	prevPopped = NULL;

	lP -> id = 1;
>>>>>>> 091ee0628d8bc91fcc4e7825e4fc267dc9ffa505
	lP->pole = leftPole;
	lP->next = mP;
	lP->prev = rP;

<<<<<<< HEAD
=======
	mP -> id = 2;
>>>>>>> 091ee0628d8bc91fcc4e7825e4fc267dc9ffa505
	mP->pole = midPole;
	mP->next = rP;
	mP->prev = lP;

<<<<<<< HEAD
	rP->pole = rightPole;
	rP->next = lP;
	rP->prev = mP;

	currentPole = lP;

	
	int select, num, popNum, pushCase, stepCounter = 0;


	printf("### start case ###\n");
	printPole(lP->pole, 'A');
	printPole(mP->pole, 'B');
	printPole(rP->pole, 'C');


	int direction = (STACK_BLOCK_SIZE%2);
	int popResult, pushResult;

	while(towerSize != rP->pole->currentsize)
	{
		if(prevPushed != currentPole)
			popResult = pop(currentPole->pole);
		else
			popResult = -1;

		if(popResult == -1)
			switchPole(currentPole, direction);
		else
		{
			prevPopped = currentPole;

			switchPole(currentPole, direction);

			pushResult = push(currentPole->pole, popResult);

			if(pushResult == 1)
			{
				printf("Move the disk %d from '%d' to '%d'\n", popResult, prevPopped->pole->id, currentPole->pole->id);
				prevPushed = currentPole;
				currentPole = lP;
=======
	rP -> id = 3;
	rP->pole = rightPole;
	rP->next = lP;
	rP->prev = mP;
	/* end of initializing */

	currentPole = lP;

	int select, num, popNum, pushCase, stepCounter = 0;

	int towerSize, isBufferClear = 0;

	/* loop until valid input*/
	while(!isBufferClear)
	{
		printf("Enter a valid tower size: ");
		scanf("%d", &towerSize);
		isBufferClear = clearBuffer();
	}

	//filling first pole
	for(int i=towerSize; i>0; i--)
		push(leftPole, i);


	/* printing first state */
	printf("### Initial State Of The Poles ###\n");
	printPole(leftPole, '1');
	printPole(midPole, '2');
	printPole(rightPole, '3');


	int direction = (towerSize%2);
	int popResult, pushResult; //popResult is return value of pop, pushResult is return value of push

	/* calculating minimum step*/
	int step = 1;
	for(int i=0; i<towerSize; i++) //calculating power of 2
		step *= 2;
	step -= 1; //the minimum step calculating with 2^n-1, that's why we subtracting 1



						/* RULES FOR SOLVING EACH LENGTH IN MINIMUM STEPS */
	/*	There are four conditions for the solution in every case n;
	*
	*	1-) If disk size even, constantly look to the right of pole, if disk size odd, constantly look to the left of pole.
	*	2-) Return to the far left pole again each time you put it down.
	*	3-) Do not retake the disc you drop a step ago.
	*	4-) Drop your disc on the first pole you can drop.
	*
	*	After playing the game for a while, I discovered that by controlling these four states, game can be finished.
	*	I used a circular linked list for constantly looking left or right.
	*/


	while(towerSize != rightPole->currentsize) //if right pole is full, game will be finished
	{
		if(prevPushed != currentPole) //check for do not retake the disc drop a step ago.
			popResult = pop(currentPole->pole);
		else
			popResult = -1; //if prevPushed and currentPole is same

		if(popResult == -1) //if popResuks is -1, this mean is it cannot take disk from currentPole that's why it pass the next pole with swtichPole function
			currentPole = switchPole(currentPole, direction);
		else
		{
			//if it can take disk with pop, it enter here
			prevPopped = currentPole;
			currentPole = switchPole(currentPole, direction); //skip the next pole for to put the imported disk
			pushResult = push(currentPole->pole, popResult);	//pushing

			if(pushResult == 1) //if pushResult equal to 1 this mean push process succeed
			{
				//writing movement
				printf("Move the disk %d from '%d' to '%d'\n", popResult, prevPopped->id, currentPole->id);
				prevPushed = currentPole;
				currentPole = lP; //setting leftPole to currentPole because it dropped successfully here we applying second item of game solve rules
>>>>>>> 091ee0628d8bc91fcc4e7825e4fc267dc9ffa505
				stepCounter++;
			}
			else
			{
<<<<<<< HEAD
				
				switchPole(currentPole, direction);

				pushResult = push(currentPole->pole, popResult);
				if(pushResult == 1)
				{
					printf("Move the disk %d from '%d' to '%d'\n", popResult, prevPopped->pole->id, currentPole->pole->id);
					prevPushed = currentPole;
					currentPole = lP;
					stepCounter++;
				}
				else
				{
					push(prevPopped->pole, popResult);
					switchPole(prevPopped, direction);
=======
				currentPole = switchPole(currentPole, direction); //if it cannot push, we skip the next pole

				pushResult = push(currentPole->pole, popResult);	//trying again push
				if(pushResult == 1) //if pushResult equal to 1 this mean push process succeed
				{
					printf("Move the disk %d from '%d' to '%d'\n", popResult, prevPopped->id, currentPole->id);
					prevPushed = currentPole;
					currentPole = lP; //setting leftPole to currentPole because it dropped successfully here we applying second item of game solve rules
					stepCounter++;
				}
				else
				{	//If it couldn't put it here either, that means there's nowhere to put this disc, that's why it's returned to where it was taken from
					push(prevPopped->pole, popResult);
					currentPole = switchPole(prevPopped, direction); //pass from the pole where the disc is drop to the next pole
>>>>>>> 091ee0628d8bc91fcc4e7825e4fc267dc9ffa505
				}
			}
		}
	}

<<<<<<< HEAD
	printf("\n\n\n### end case ###\n");
	printPole(lP->pole, '1');
	printPole(mP->pole, '2');
	printPole(rP->pole, '3');

	printf("step count = %d", stepCounter);

=======
	printf("\n\n\n### Final State Of The Poles ###\n");
	printPole(leftPole, '1');
	printPole(midPole, '2');
	printPole(rightPole, '3');

	printf("Done in %d steps.\nThe minimum number of steps was %d", stepCounter, step);
>>>>>>> 091ee0628d8bc91fcc4e7825e4fc267dc9ffa505


}

<<<<<<< HEAD
struct node* switchPole(struct node *pole, int direction)
{
	if(direction == right)
		pole = pole->next;
	else if(direction ==left)
		pole = pole->prev;

	return pole;

}
void printPole(stack *s, char name)
{
	int top = s->maxsize;
	int poleSize = s->currentsize;
=======
node* switchPole(node* pole, int direction)	//skip pole by direction
{
	if(direction == right)
		pole = pole->next;
	else if(direction == left)
		pole = pole->prev;

	return pole;
}

void printPole(stack *s, char name) //printing pole with given name
{
	int top = s->maxsize;
	int poleSize = s->currentsize;

>>>>>>> 091ee0628d8bc91fcc4e7825e4fc267dc9ffa505
	printf("pole = %c\n", name);

	if(s->currentsize == 0)
		printf("No Disk\n");
	else
	{
<<<<<<< HEAD
		for(int i=top-poleSize; i<s->currentsize; i++)
			printf("%d\n", s->array[i]);
	}
	
=======
		for(int i=top-poleSize; i<top; i++)
			printf("%d\n", s->array[i]);
	}

>>>>>>> 091ee0628d8bc91fcc4e7825e4fc267dc9ffa505
	printf("\n");

}

data_type pop(stack *s)
{
	int maxsize = s->maxsize;
	int currentsize = s->currentsize;
	int num;

<<<<<<< HEAD
	if(currentsize > 0)
	{
		num = *(s->array + maxsize-currentsize);
		*(s->array + maxsize-currentsize) = 0;
		s->currentsize -= 1;
		return num;
	}

	return -1;
=======
	if(currentsize > 0) //this is mean is if there is element in array
	{
		num = *(s->array + maxsize-currentsize); //taking element
		*(s->array + maxsize-currentsize) = 0;
		s->currentsize -= 1;
		return num; // return element
	}

	return -1; //if it cannot take, it returns -1
>>>>>>> 091ee0628d8bc91fcc4e7825e4fc267dc9ffa505
}

int push(stack *s, int d)
{
	int maxsize = s->maxsize;
	int currentsize = s->currentsize;
<<<<<<< HEAD

	if(maxsize == currentsize)
		return -1;

	if(d < *(s->array+maxsize-currentsize) || *(s->array+maxsize-currentsize) == 0)
	{
=======
	int *tempStack;
	int tempLen = maxsize + STACK_BLOCK_SIZE;

	if(maxsize <= currentsize) //if the array is full, its size is increased by STACK_BLOCK_SIZE
	{
		tempStack = calloc(tempLen, sizeof(data_type));

		for(int i=0; i<maxsize; i++)
			tempStack[tempLen-i-1] = *(s->array+maxsize-i-1);

		s->array = realloc(s->array, tempLen * sizeof(data_type));

		for(int i=0; i<tempLen; i++)
			*(s->array + i) = tempStack[i];

		s->maxsize = tempLen;
		maxsize = s->maxsize;
		free(tempStack);
	}

	if(d < *(s->array+maxsize-currentsize) || *(s->array+maxsize-currentsize) == 0) //if given integer is smaller than top of array or element is equal to 0
	{
		//adding d to stack
>>>>>>> 091ee0628d8bc91fcc4e7825e4fc267dc9ffa505
		*(s->array + maxsize-currentsize-1) = d;
		s->currentsize += 1;
	}
	else
<<<<<<< HEAD
		return 0;

	return 1;
}

stack* init_return() /* initializes an empty stack */
{
=======
		return 0;	//if d is bigger than top

	return 1; //return 1 if process is succesfull
}

stack* init_return()
{
	/* initializes an empty stack */
>>>>>>> 091ee0628d8bc91fcc4e7825e4fc267dc9ffa505
	stack *tempStack;
	tempStack = malloc(sizeof(stack));

	tempStack->currentsize = 0;
	tempStack->maxsize = STACK_BLOCK_SIZE;
	tempStack->array = calloc(STACK_BLOCK_SIZE, sizeof(data_type));
<<<<<<< HEAD
	tempStack->id = 0;

	return tempStack;
=======

	return tempStack;

>>>>>>> 091ee0628d8bc91fcc4e7825e4fc267dc9ffa505
}

int init(stack *s)
{
<<<<<<< HEAD
=======
	/* returns 1 if initialization is successful */

>>>>>>> 091ee0628d8bc91fcc4e7825e4fc267dc9ffa505
	if(s->currentsize != 0)
		return 0;

	if(s->maxsize != STACK_BLOCK_SIZE)
		return 0;

	if(!isEmpty(s->array))
		return 0;

	return 1;
}

int isEmpty(data_type *array)
{
<<<<<<< HEAD
=======
	/* Checking if array is empty */
>>>>>>> 091ee0628d8bc91fcc4e7825e4fc267dc9ffa505
	for(int i=0; i<STACK_BLOCK_SIZE; i++)
		if(*(array + i) != 0)
			return 0;

	return 1;
}
<<<<<<< HEAD
=======

int clearBuffer()	//this function checks if the buffer is clean, if it's not clean it cleans it
{
	int isBufferClear=1;
	while(getchar() != '\n')
		isBufferClear++;
	if(isBufferClear == 1)
		return 1;
	else
		return 0;
}
>>>>>>> 091ee0628d8bc91fcc4e7825e4fc267dc9ffa505

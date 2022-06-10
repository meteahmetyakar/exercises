#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#define STACK_BLOCK_SIZE 10

enum directions {left, right};

typedef int data_type;

typedef struct {
	data_type *array;
	int id;
	int currentsize;
	int maxsize;
}stack;

struct node {
    stack *pole;
    struct node * next;
	struct node * prev;
};


int push(stack *s, int d); 	/* the stack array will grow STACK_BLOCK_SIZE entries at a time */
data_type pop(stack *s); 	/* the stack array will shrink STACK_BLOCK_SIZE entries at a time */
stack *init_return(); 		/* initializes an empty stack */
int init(stack *s); 		/* returns 1 if initialization is successful */
void printPole(stack *s, char name);
struct node* switchPole(struct node *pole, int direction);
int isEmpty(data_type *array);



int main()
{
	stack *leftPole;
	stack *midPole;
	stack *rightPole;

	leftPole = init_return();
	midPole = init_return();
	rightPole = init_return();

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

	lP->pole = leftPole;
	lP->next = mP;
	lP->prev = rP;

	mP->pole = midPole;
	mP->next = rP;
	mP->prev = lP;

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
				stepCounter++;
			}
			else
			{
				
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
				}
			}
		}
	}

	printf("\n\n\n### end case ###\n");
	printPole(lP->pole, '1');
	printPole(mP->pole, '2');
	printPole(rP->pole, '3');

	printf("step count = %d", stepCounter);



}

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
	printf("pole = %c\n", name);

	if(s->currentsize == 0)
		printf("No Disk\n");
	else
	{
		for(int i=top-poleSize; i<s->currentsize; i++)
			printf("%d\n", s->array[i]);
	}
	
	printf("\n");

}

data_type pop(stack *s)
{
	int maxsize = s->maxsize;
	int currentsize = s->currentsize;
	int num;

	if(currentsize > 0)
	{
		num = *(s->array + maxsize-currentsize);
		*(s->array + maxsize-currentsize) = 0;
		s->currentsize -= 1;
		return num;
	}

	return -1;
}

int push(stack *s, int d)
{
	int maxsize = s->maxsize;
	int currentsize = s->currentsize;

	if(maxsize == currentsize)
		return -1;

	if(d < *(s->array+maxsize-currentsize) || *(s->array+maxsize-currentsize) == 0)
	{
		*(s->array + maxsize-currentsize-1) = d;
		s->currentsize += 1;
	}
	else
		return 0;

	return 1;
}

stack* init_return() /* initializes an empty stack */
{
	stack *tempStack;
	tempStack = malloc(sizeof(stack));

	tempStack->currentsize = 0;
	tempStack->maxsize = STACK_BLOCK_SIZE;
	tempStack->array = calloc(STACK_BLOCK_SIZE, sizeof(data_type));
	tempStack->id = 0;

	return tempStack;
}

int init(stack *s)
{
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
	for(int i=0; i<STACK_BLOCK_SIZE; i++)
		if(*(array + i) != 0)
			return 0;

	return 1;
}

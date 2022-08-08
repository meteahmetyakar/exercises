#include <stdio.h>
#include <stdlib.h>
#include "util.h"

int main()
{
	printf("\n\n");

	int seqlen, xs;

	printf("Please enter the sequence lenght: ");
	scanf("%d", &seqlen);

	printf("Please enter the first element: ");
	scanf("%d", &xs);

	int *loop, *looplen, *h;
	int firstlen = seqlen/2;
	looplen = &firstlen;
	loop = calloc(firstlen, sizeof(int));


	check_loop_iterative(generate_sequence,xs, seqlen, loop, looplen);	//Checking whether there is a loop in the array produced from the generate_sequence function

	//printing repating loop if any
	if(loop[0] != 0)
		printArray(loop, *looplen, "Loop");
	else
		printf("No loop found.\n\n");


	h = calloc(9, sizeof(int));
	hist_of_firstdigits(generate_sequence, xs, seqlen, h, 1); //finding histogram
	printArray(h, 9, "Histogram of the sequence");			  //printing histogram

}



#include <stdio.h>
#include "util.h"

void hist_of_firstdigits(void (*f)(), int xs, int seqlen, int *h, int digit)	//finding histogram
{

	int *seq;
	seq = malloc(seqlen * sizeof(int));
	f(xs, 0, seqlen, seq); //the array is fills

	int num = seq[seqlen-digit]; //starting from last index of seq, taking it

	while(num >= 10)	//finding first digit of num
		num /= 10;

	h[num-1] += 1;	//adding digit to histogram

	if(digit < seqlen)	//it checks while digit equal to seqlen so it checks until last index
		hist_of_firstdigits(generate_sequence, xs, seqlen, h, digit+1);	//recursive function called

	return;	//quit the functinon

}

void check_loop_iterative(void (*f)(), int xs, int seqlen, int *loop, int *looplen)
{
	int *ls, *le;	// * *ls is loop starting index and le is loop end index
	int *seq;	//sequence array

	seq = malloc(seqlen * sizeof(int));
	f(xs, 0, seqlen, seq); //the array is fills

	if(seqlen/2 == *looplen) // if this condition is true this means the function called first time and print sequence
	{
		printf("\n");
		printArray(seq, seqlen, "Sequence");
	}

	if(*looplen > 1)	//looplen is using on recursive and it loops until looplen equal to 1
	{
		printf("Checking if there is a loop of lenght %d...\n", *looplen);
		if(has_loop(seq, seqlen, *looplen, ls, le))	//checking is there a loop the size of a looplen
		{
			for(int j=0; j<*le-*ls+1; j++)	//if there is a loop, this loop fills to loop array
				loop[j] = seq[*ls+j];

			return;
		}
		else
		{
			*looplen = *looplen-1;	//decrement the looplen
			check_loop_iterative(generate_sequence,xs, seqlen, loop, looplen); //recursive function called
		}
	}

}

int has_loop(int *arr, int n, int looplen, int *ls, int *le) //checking if there is any loop in size of looplen
{
	int *temp, *search;
	search = malloc(looplen * sizeof(int)); // array to store the loop to search
	temp = malloc(looplen * sizeof(int));	// array to compare with search array

	for(int i=0; i<n-looplen-2; i++) //n-looplen-2 is number of checks that can be made with a looplen length array and i is current index
	{
		for(int j=0; j<looplen; j++)	//filling the search array
			search[j] = arr[i+j];

		for(int j=0; j<looplen; j++)
		{
			if(i+looplen+j < n)	//if sum of current index, looplen and current index for temp array (this index is j) smaller than n (n is lenght of *arr) enter here and filling the temp
				temp[j] = arr[i+looplen+j];
			else
				break;
		}
			if(isArraysSame(search, temp, looplen))	//compare temp and search arrays
			{	/* if they are same*/
				*ls = i; //current index of *arr assign to ls
				*le = i+looplen-1; //last index of loop assing to le
				printf("\n\nLoop detected with a lenght of %d\n", looplen);
				printf("The indexes of the loop's first occurance: %d (first digit), %d (last digit)\n", *ls, *le);

				return 1;
			}
	}

	return 0;
}

int isArraysSame(int *arr, int *arr2, int lenght)
{
	for(int i=0; i<lenght; i++)
		if(arr[i] != arr2[i]) //if their elements different in current same index, it return 0
			return 0;

	return 1;

}

void generate_sequence( int xs, int currentlen, int seqlen, int *seq)
{
	int number=xs;
	seq[currentlen] = number;
	if(seqlen > 1) //seqlen is using on recursive and it loops until seqlen equal to 1
	{
		/* appyling collatz formula */
		if(xs % 2==0)
			number = xs / 2;
		else
			number = (3*xs) + 1;

		generate_sequence(number, currentlen+1, seqlen-1, seq); //recursive function called
	}

	return;
}

void printArray(int *arr, int arrSize, char *title)
{
		fputs(title, stdout);	//it print given title (I used fputs instead of puts because in puts function it prints new line)
		printf(": {");
		for(int i=0; i<arrSize; i++)
		{
			printf("%d, ", arr[i]);
		}
			printf("\b\b}\n\n");

		/*
			if arr is {3,2,1,5,6},
		   	result is:
		   	 title: {3,2,1,5,6}
		*/
}

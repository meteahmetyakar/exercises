#include <stdio.h>
#include <math.h>



typedef enum {Triangle=1, Quadrilateral=2, Circle=3, Pyramid=4, Cylinder=5} shapes;
typedef enum {Area=1, Perimeter=2, Volume=3} calculators;

#define PI 3.14

//operation functions
int select_shape();
int select_calc();
int calculate(int (), int ());

//calculating functions
int calc_triangle(calculators calc);
int calc_quadrilateral(calculators calc);
int calc_circle(calculators calc);
int calc_pyramid(calculators calc);
int calc_cylinder(calculators calc);

//control functions
int isValidTriangle(float a, float b, float c);
int clearBuffer();

int main()
{
	printf("Welcome to the geometric calculator!\n");
	while(calculate(select_shape, select_calc));	//this while is looping while don't return 0 from select_shape or select_calc functions
}

int select_shape()
{
	int select=-1;
	int isBufferClear, isOutOfRange;
	do
	{
		printf("Select a shape to calculate:\n");
		printf("----------------------------\n");
		printf("1. Triangle\n");
		printf("2. Quadrilateral\n");
		printf("3. Circle\n");
		printf("4. Pyramid\n");
		printf("5. Cylinder\n");
		printf("0. Exit\n");
		printf("----------------------------\n");
		printf("Input: ");
		scanf("%d", &select);

		isOutOfRange = select < 0 || select > 5; //checks if the input is in range
		isBufferClear = clearBuffer();
		if(!isBufferClear || isOutOfRange)
			printf("\nERROR ! Please enter a valid entry.\n\n");
	}while(!isBufferClear || isOutOfRange);

	return select;

}

int select_calc()
{
	int select=-1;
	int isBufferClear, isOutOfRange;
	do
	{
		printf("Select calculator:\n");
		printf("----------------------------\n");
		printf("1. Area\n");
		printf("2. Perimeter\n");
		printf("3. Volume\n");
		printf("0. Exit\n");
		printf("----------------------------\n");
		printf("Input: ");
		scanf("%d", &select);

		isOutOfRange = select < 0 || select > 3;
		isBufferClear = clearBuffer();
		if(!isBufferClear || isOutOfRange)
			printf("\nERROR ! Please enter a valid entry.\n\n");
	}while(!isBufferClear || isOutOfRange);

	return select;
}

int calculate(int s_shape(), int s_calc())
{
	/* variables of type enum*/
	shapes selectionShape;
	calculators selectionCalc;

	selectionShape = s_shape();

	if(selectionShape == 0)	//0 is exit on select_shape
		return 0;

	selectionCalc = s_calc();

	if(selectionCalc == 0) //0 is exit on select_calc
		return 0;


	switch(selectionShape)
	{
		case Triangle:
			calc_triangle(selectionCalc);
			break;
		case Quadrilateral:
			calc_quadrilateral(selectionCalc);
			break;
		case Circle:
			calc_circle(selectionCalc);
			break;
		case Pyramid:
			calc_pyramid(selectionCalc);
			break;
		case Cylinder:
			calc_cylinder(selectionCalc);
			break;
	}
	return 1;

}

int calc_triangle(calculators calc)
{
	float a, b, c;
	int isBufferClear, isNegativeNumber;

	if(calc != Volume)
	{
		do	//the loop loops until valid input
		{
			a=0,b=0,c=0;
			printf("Please enter three sides of Triangle :\n");
			scanf("%f%f%f", &a, &b, &c);
			isBufferClear = clearBuffer();
			isNegativeNumber = a<=0 || b<=0 || c<=0; //checks if the input is in range
			if(!isBufferClear || isNegativeNumber)
				printf("\nERROR ! Please enter a valid entry.\n\n");

		}while(!isBufferClear || isNegativeNumber || !isValidTriangle(a,b,c));
	}

	float s, area, perimeter;

	switch(calc)
	{
		case Area:
			//area
			s = (a+b+c)/2;
			area = sqrt(s*(s-a)*(s-b)*(s-c));
			printf("Area of TRIANGLE : %.2f\n", area);
			break;
		case Perimeter:
			perimeter = a+b+c;
			printf("perimeter of TRIANGLE : %.2f\n", perimeter);
			break;
		case Volume:
			printf("\nERROR ! You cannot calculate the volume of a Triangle. Please try again.\n\n");
			break;
	}

	return 1;

}

int calc_quadrilateral(calculators calc)
{
	int isBufferClear, isNegativeNumber;
	float a, b, c, d;
	if(calc != Volume)
	{
		do	//the loop loops until valid input
		{
			a=0,b=0,c=0,d=0;
			printf("Please enter four sides of Quadrilateral :\n");
			scanf("%f%f%f%f", &a, &b, &c, &d);
			isBufferClear = clearBuffer();
			isNegativeNumber = a<=0 || b<=0 || c<=0 || d<=0; //checks if the input is in range
			if(!isBufferClear || isNegativeNumber)
				printf("\nERROR ! Please enter a valid entry.\n\n");

		}while(!isBufferClear || isNegativeNumber);
	}

	float s, area, perimeter;

	switch(calc)
	{
		case Area:
			//area
			s = (a+b+c+d)/2;
			area = sqrt((s-a)*(s-b)*(s-c)*(s-d));
			printf("Area of Quadrilateral : %.2f\n", area);
			break;
		case Perimeter:
			//perimeter
			perimeter = a+b+c+d;
			printf("perimeter of Quadrilateral : %.2f\n", perimeter);
			break;
		case Volume:
			printf("\nERROR ! You cannot calculate the volume of a Quadrilateral. Please try again.\n\n");
			break;
	}

	return 1;
}

int calc_circle(calculators calc)
{
	float r;
	int isBufferClear, isNegativeNumber;
	if(calc != Volume)
	{
		do	//the loop loops until valid input
		{
			r=0;
			printf("Please enter the radius of Circle :\n");
			scanf("%f", &r);
			isBufferClear = clearBuffer();
			isNegativeNumber = r<=0;	//checks if the input is in range
			if(!isBufferClear || isNegativeNumber)
				printf("\nERROR ! Please enter a valid entry.\n\n");

		}while(!isBufferClear || isNegativeNumber);
	}

	float area, perimeter;

	switch(calc)
	{
		case Area:
			//area
			area = PI*(r*r);
			printf("Area of CIRCLE : %.2f\n", area);
			break;
		case Perimeter:
			//perimeter
			perimeter = 2*PI*r;
			printf("perimeter of Quadrilateral : %.2f\n", perimeter);
			break;
		case Volume:
			printf("\nERROR ! You cannot calculate the volume of a Circle. Please try again.\n\n");
			break;
	}

	return 1;
}

int calc_pyramid(calculators calc)
{
	float a, l, h;
	int isBufferClear, isNegativeNumber;

	float baseSurfaceArea, lateralSurfaceArea, surfaceArea, volume, perimeter;

	switch(calc)
	{
		case Area:
			//area
			do
			{ 	//the loop loops until valid input
				a=0,l=0;
				printf("Please enter the base side and slant height of a Pyramid :\n");
				scanf("%f%f", &a, &l);
				isBufferClear = clearBuffer();
				isNegativeNumber = a<=0 || l<=0; //checks if the input is in range
				if(!isBufferClear || isNegativeNumber)
					printf("\nERROR ! Please enter a valid entry.\n\n");

			}while(!isBufferClear || isNegativeNumber);

			baseSurfaceArea = a*a;
			lateralSurfaceArea = 2*a*l;
			surfaceArea = baseSurfaceArea + lateralSurfaceArea;
			printf("Base Surface Area of a PYRAMID : %.2f\n", baseSurfaceArea);
			printf("Lateral Surface Area of a PYRAMID : %.2f\n", lateralSurfaceArea);
			printf("Surface Area of a PYRAMID : %.2f\n", surfaceArea);
			break;
		case Perimeter:
			//perimeter
			do
			{	//the loop loops until valid input
				a=0;
				printf("Please enter the base side of a Pyramid :\n");
				scanf("%f", &a);
				isBufferClear = clearBuffer();
				isNegativeNumber = a<=0;	 //checks if the input is in range
				if(!isBufferClear || isNegativeNumber)
					printf("\nERROR ! Please enter a valid entry.\n\n");

			}while(!isBufferClear || isNegativeNumber);
			perimeter = a*4;
			printf("perimeter of Pyramid : %.2f\n", perimeter);
			break;
		case Volume:
			do
			{	//the loop loops until valid input
				a=0, h=0;
				printf("Please enter the base side and height of a Pyramid :\n");
				scanf("%f%f", &a, &h);
				isBufferClear = clearBuffer();
				isNegativeNumber = a<=0 || l<=0;	//checks if the input is in range
				if(!isBufferClear || isNegativeNumber)
					printf("\nERROR ! Please enter a valid entry.\n\n");

			}while(!isBufferClear || isNegativeNumber);
			volume = ((a*a)*h)/3;
			printf("Volume of PYRAMID : %.2f\n", volume);
			break;
	}

	return 1;
}

int calc_cylinder(calculators calc)
{
	float r, h;
	int isBufferClear, isNegativeNumber;

	float baseSurfaceArea, lateralSurfaceArea, surfaceArea, volume, perimeter;

	do		//the loop loops until valid input
	{
		r=0, h=0;
		printf("Please enter the radius and height of a Cylinder :\n");
		scanf("%f%f", &r, &h);
		isBufferClear = clearBuffer();
		isNegativeNumber = r<=0 || h<=0;	//checks if the input is in range
		if(!isBufferClear || isNegativeNumber)
			printf("\nERROR ! Please enter a valid entry.\n\n");

	}while(!isBufferClear || isNegativeNumber);

	switch(calc)
	{
		case Area:
			//area
			baseSurfaceArea = PI*(r*r);
			lateralSurfaceArea = 2*PI*r*h;
			surfaceArea = 2*PI*r*(r+h);
			printf("Base Surface Area of a CYLINDER : %.2f\n", baseSurfaceArea);
			printf("Lateral Surface Area of a CYLINDER : %.2f\n", lateralSurfaceArea);
			printf("Surface Area of a CYLINDER : %.2f\n", surfaceArea);
			break;
		case Perimeter:
			//perimeter
			perimeter = 2*PI*r;
			printf("perimeter of CYLINDER : %.2f\n", perimeter);
			break;
		case Volume:
			volume = PI*(r*r)*h;
			printf("Volume of CYLINDER : %.2f\n", volume);
			break;
	}

	return 1;
}

int isValidTriangle(float a, float b, float c)	//check triangle if valid triangle, if it's not valid it print error message
{
	if ((a + b < c || a + c < b || b + c < a))
	{
		printf("\nERROR ! Please enter a valid triangle.\n\n");
        return 0;
	}

    return 1;
}

int clearBuffer()	//this function checks if the buffer is clean, if it's not clean it cleans it
{
	int isBufferClear=1;
	while(getchar() != '\n')
		isBufferClear++;

	if(isBufferClear)
		return 1;
	else
		return 0;
}

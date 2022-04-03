#include <stdio.h>

/* define colors for using on setTextColor function */
#define reset 0
#define green 1
#define blue 2

void setTextColor(int colorCode); //it changes text color on terminal

int main()
{

    int x,y;
    int a, b, c;
    int A, B, C;
    char symbol;
    int repeater = 1, selection;

    FILE* file;

    while(repeater)
    {
        printf("1 -> Enter the coefficients.\n");
        printf("2 -> Draw the graph.\n");
        printf("3 -> Print the graph into a .txt fle.\n");
        printf("4 -> Exit.\n");
        printf("\nChoice: ");
        scanf("%d", &selection);

        switch(selection)
        {
            case 1:
                printf("Please enter the coefficients for the following equation x=a(y*y) + b*y + c \n\n");
                printf("a: ");
                scanf(" %d", &A);
                printf("b: ");
                scanf(" %d", &B);
                printf("c: ");
                scanf(" %d", &C);

                printf("\ncoefficients.txt file has been created.\n");

                file = fopen("coefficients.txt", "w");
                fprintf(file, "%d\n%d\n%d", A,B,C);
                fclose(file);
                break;
            case 2:
                if(file = fopen("coefficients.txt", "r"))   //if file is exist, it enter this scope
                {
                    fscanf(file, "%d%d%d", &a,&b,&c);
                    fclose(file);
                    printf("\nCoefficients has been read from the coefficient.txt file.\n");
                    printf("Printing the graph of x=%d(y*y) + %d*y + %d\n\n", a, b, c);

                    for(y = 16; y>=-15; y--)
                    {
                        for(x = -55; x<=55; x++)
                        {

                            setTextColor(reset); //reset the terminal text color

                            if(x==(a*(y*y) + (b*y) + c) && y != 16) //We check -16 so that the y-axis does not put # on the line with the arrow
                            {                                       //# is the most dominant character because printing is done in the first statement, and the graphic is always written at the top
                                setTextColor(blue);
                                printf("#");
                            }
                            else if(y == 16 && x == 0)
                                printf("^");
                            else if(x == -2 && (y % 5 == 0 && y != 0))
                            {
                                if(y == 15 || y == 10 || y == -5)
                                    printf("\b");
                                else if(y == -15 || y == -10)
                                    printf("\b\b");

                                setTextColor(green);
                                printf("%d", y);    //write numbers of y-axis
                            }
                            else if(x == 0)
                                printf("|");
                            else if(y == 0)
                            {
                                if(x==-55)
                                    printf("<");
                                else if(x==55)
                                    printf(">");
                                else
                                    printf("-");
                            }
                            else if(y==-1) //in this scope we writing numbers of the x-axis
                            {
                                setTextColor(green);
                                if(x % 10 == -9)
                                    printf("0");
                                else if(x%10==0)
                                {
                                    if(x<=0)
                                        printf("%d", -1*x/10);
                                    else
                                        printf("%d", x/10);
                                }
                                else if(x % 10 == -1)
                                {
                                    if(x==-1)
                                        printf("0");
                                    else
                                        printf("-");
                                }
                                else if(x % 10 == 1 && x != 1)
                                    printf("0");
                                else
                                    printf(" ");
                                setTextColor(reset);
                            }
                            else
                                printf(" ");
                        }
                        printf("\n");
                    }
                }
                else
                    printf("\n\n### THERE IS NO COEFFICIENTS.TXT FILE IN DIRECTORY###\n\n");

                break;
            case 3:
                if(file = fopen("coefficients.txt", "r"))   //if file is exist, it enter this scope
                {   //here we do same thing in case 2, only there are no numbers writing and we write to file symbols
                    fscanf(file, "%d%d%d", &a,&b,&c);
                    fclose(file);

                    printf("\nCoefficients has been read from the coefficient.txt file.\n");
                    printf("The graph of x=%d*(y*y) + %d*y + %d has been written to graph.txt file.\n\n", a, b, c);

                    file = fopen("graph.txt", "w");

                    for(int i=0; i<55; i++)
                        fprintf(file," ");

                    fprintf(file, "^");
                    fprintf(file,"\n");

                    for(y = 15; y>=-15; y--)
                    {
                        for(x = -55; x<=55; x++)
                        {
                            if(x==(a*(y*y) + (b*y) + c))
                                fprintf(file, "#");
                            else if(x == 0)
                                fprintf(file, "|");
                            else if(y == 0)
                            {
                                if(x==-55)
                                    fprintf(file, "<");
                                else if(x==55)
                                    fprintf(file, ">");
                                else
                                    fprintf(file, "-");
                            }
                            else
                                fprintf(file, " ");

                        }
                        fprintf(file,"\n");
                    }
                    fclose(file);
                }
                else
                    printf("\n\n### THERE IS NO COEFFICIENTS.TXT FILE IN DIRECTORY###\n\n");
                break;
            case 4:
                repeater = 0; //exit
                break;
            default:
                printf("\n\n### ENTERED A WRONG INPUT ###\n\n");
                break;
        }
    }

}

void setTextColor(int colorCode) //it changes text color on terminal
{
    if(colorCode == 0)
        printf("\033[0m");      //reset
    else if(colorCode == 1)
        printf("\033[0;32m");   //green
    else if(colorCode == 2)
        printf("\033[0;34m");   //blue
}

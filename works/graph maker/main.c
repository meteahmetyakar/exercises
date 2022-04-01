#include <stdio.h>

#define reset 0
#define green 1
#define blue 2

void setTextColor(int colorCode);
void writeFile(char* txtName, char character, int mode);
void clearTxt(char* txtName);

int main()
{

    int x,y;
    int a, b, c;
    char n1,n2,n3;
    char symbol;
    int repeater = 1, selection;
    
    clearTxt("graph.txt");
    clearTxt("coefficients.txt");

    a=0;
    b=5;
    c=0;


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
                scanf(" %c", &n1);
                printf("b: ");
                scanf(" %c", &n2);
                printf("c: ");
                scanf(" %c", &n3);

                printf("\n coefficients.txt file has been created.");

                writeFile("coefficients.txt", "48", 1);
                writeFile("coefficients.txt", "2", 1);
                writeFile("coefficients.txt", "3", 1);
                break;
            case 2:
                for(int i=0; i<55; i++)
                    printf(" ");
                printf("^\n");

                for(y = 15; y>=-15; y--)
                {
                    for(x = -55; x<=55; x++)
                    {


                        if(y == -1 && (x % 10 == 0))
                        {
                            setTextColor(green);
                            if(x < 0)
                                printf("\b\b\b");
                            else if(x == 0)
                                printf("\b");
                            else
                                printf("\b\b");
                            printf("%d", x);
                        }

                        setTextColor(reset);
                        

                        if(x==(a*(y*y) + (b*y) + c))
                        {
                            setTextColor(blue);
                            printf("#");
                        }
                        else if(x == -2 && (y % 5 == 0 && y != 0))
                        {
                            if(y == 15 || y == 10 || y == -5)
                                printf("\b");
                            else if(y == -15 || y == -10)
                                printf("\b\b");
                            
                            setTextColor(green);
                            printf("%d", y);
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
                        else
                            printf(" ");
                    }
                    printf("\n");
                }
                break;
            case 3:
                for(int i=0; i<55; i++)
                    writeFile("graph.txt", ' ', 0);

                writeFile("graph.txt", '^', 0);
                writeFile("graph.txt", '\n', 0);

                for(y = 15; y>=-15; y--)
                {
                    for(x = -55; x<=55; x++)
                    {
                        if(x==(a*(y*y) + (b*y) + c))
                            symbol = '#'; 
                        else if(x == 0)
                            symbol = '|'; 
                        else if(y == 0)
                        {
                            if(x==-55)
                                symbol = '<'; 
                            else if(x==55)
                                symbol = '>';
                            else
                                symbol = '-'; 
                        }
                        else
                            symbol = ' '; 
                        
                        writeFile("graph.txt", symbol, 0);
                    }
                    writeFile("graph.txt", '\n', 0);
                }
                break;
            case 4:
                repeater = 0;
                break;
            default:
                printf("wrong");
                break;
        }
    }
    
}

void clearTxt(char* txtName)
{
    FILE* file;
    file = fopen(txtName, "w");
    fclose(file);
}

void writeFile(char* txtName, char character, int newLine)
{
    FILE* file;
    file = fopen(txtName, "a");
    fprintf(file, "%c", character);
    if(newLine == 1)
        fprintf(file, "\n");
    fclose(file);
}

void setTextColor(int colorCode)
{
    if(colorCode == 0)
        printf("\033[0m");      //reset
    else if(colorCode == 1)
        printf("\033[0;32m");    //green
    else if(colorCode == 2)
        printf("\033[0;34m");   //blue
}
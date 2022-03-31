#include <stdio.h>

int main()
{

    int x;
    int y;
    int a, b, c;
    int condition = a*y*y + b*y + c;

    a=0;
    b=1;
    c=5;

    for(int i=0; i<55; i++)
        printf(" ");
    printf("^\n");


    for(y = 16; y>=-15; y--)
    {
        for(x = -55; x<=55; x++)
        {
            //printf("(%d %d)", x,y);
            /*if(x == -5)
            {
                if(y % 5 == 0 && y != 0)
                    printf("%d", y);
            }
            else if(y==-1)
            {
                if(x%10 == 0)
                    printf("%d", x);
            }*/
                
            if(x==(a*(y*y) + (b*y) + c))
            {

                printf("#");

            }
            else if(x == 0)
            {
                if(y==-1)
                    printf("\b%d",x);
                
                printf("|");
            }
            else if(y == 0)
            {
                if(x==-55)
                    printf("<");
                else if(x==55)
                    printf(">");
                else
                    printf("-");
            }
            else if(x == -2 && y % 5 == 0)
            {
                if(y == 15 || y == 10 || y == -5)
                    printf("\b");
                else if(y == -15 || y == -10)
                    printf("\b\b");

                printf("%d", y);
            }
            else if(y == -1 && (x % 10 == 0 || x == 0))
            {
                if(x != 0)
                    printf("\b");
                printf("\b%d",x);
            }
            else
                printf(" ");
        }
        printf("\n");
    }
}

void setTextColor(int a)
{
    if(a == 0)
        printf()
}
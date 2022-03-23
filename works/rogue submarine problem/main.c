#include <stdio.h>

int main()
{
    int data[5] = {1,2,3,4,5};
    
    for(int i=0; i<5;i++)
    {
        for(int j=i+1; j<5; j++)
        {
            for(int k=j+1; k<5; k++)
            {
                for(int t=k+1; t<5; t++)
                {
                    printf("%d%d%d%d",data[i],data[j],data[k],data[t]);
                    printf("\n");
                }
            }
        }
    }
}

void print_double(int data[])
{
    for(int i=0; i<5;i++)
    {
        for(int j=i+1; j<5; j++)
        {
            printf("%d%d",data[i],data[j]);
            printf("\n");
        }
    }
}



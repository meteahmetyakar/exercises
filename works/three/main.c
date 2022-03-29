#include <stdio.h>
#define MAX_VALUE 99999

int main()
{
    FILE* file;
    FILE* tempFile;
    /*fprintf(file, "%s", "1 3 5 4 1 2 6 4 5");
    fprintf(file, "\n%s", "12 5 3 6 7 8 9 12");*/

    int pointer, min1, min2, min3;
    //            1         2         3
    int min1Counter = -1, min2Counter = -1, min3Counter = -1;
    //int fileLenght;

    for(int i=0; i<numberOfLoopRequired(); i++)
    {
        file = fopen("deneme.txt", "r");
        tempFile = fopen("temp.txt", "a+");
        min1 = MAX_VALUE;
        min2 = MAX_VALUE;
        min3 = MAX_VALUE;

        while(!feof(file))
        {
            printf("-- %d %d %d --\n", min1, min2, min3);
            fscanf(file, "%d ", &pointer);

            if(!isThereInTempFile(pointer))
            {
                if(min1 > pointer)
                {
                    min3 = min2;
                    min2 = min1;
                    min1 = pointer;

                }
                else if (min2 > pointer && pointer != min1)
                {
                    min3 = min2;
                    min2 = pointer;
                }
                else if (min3 > pointer && pointer != min2 && pointer != min1)
                    min3 = pointer;

            }
        }

        if(min1 != MAX_VALUE)
            for(int i=0; i<repetitionCounter(min1); i++)
                fprintf(tempFile, "%d ", min1);
        if(min2 != MAX_VALUE)
            for(int i=0; i<repetitionCounter(min2); i++)
                fprintf(tempFile, "%d ", min2);
        if(min3 != MAX_VALUE)
            for(int i=0; i<repetitionCounter(min3); i++)
                fprintf(tempFile, "%d ", min3);
        
        fclose(tempFile);
        fclose(file);
    }

    //fprintf(tempFile,"%d %d %d ", min1,min2,min3);

    
}

int numberOfLoopRequired()
{
    FILE* file;
    file = fopen("deneme.txt", "r");

    int counter=0, unnecessary;

    while(!feof(file))
    {
        fscanf(file,"%d ", &unnecessary);
        counter++;
    }

    //fclose(file);

    if(counter % 3 == 0)
        return (counter/3);
    else
        return ((counter/3) + 1);
}

int isThereInTempFile(int pointer)
{
    FILE* tempFile;
    tempFile = fopen("temp.txt", "r");
    int value;

    while(!feof(tempFile))
    {
        fscanf(tempFile, "%d ", &value);
        if(pointer == value)
        {
            fclose(tempFile);
            return 1;
        }
    }

    fclose(tempFile);
    return 0;

}

int repetitionCounter(int soughtNumber)
{
    FILE* tempFile;
    tempFile = fopen("deneme.txt", "r");
    int counter = 0, value;

    while(!feof(tempFile))
    {
        fscanf(tempFile, "%d ", &value);
        if(soughtNumber == value)
            counter++;
    }

    fclose(tempFile);
    return counter;
}
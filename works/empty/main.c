#include <stdio.h>
int main()
{
    //3
    /*FILE* tempFile;
    tempFile = fopen("results.txt", "w+");
    fputs("30 31 32 2822 36 36 40 41 42 43", tempFile);
    rewind(tempFile);
    int counter = 0, value;
    int istenenIndex = 3;
    int index = 0 ;
    int pos=0;
    char oldChar, newChar;
    newChar = fgetc(tempFile);
    while(index < istenenIndex)
    {
        oldChar = newChar;
        newChar = fgetc(tempFile);
        if(oldChar == ' ' && newChar != ' ')
        {
            index++;
            printf("%c-%c\n", oldChar, newChar);
        }
        pos++;
    }
    printf("%d", pos);


    

    int valueLenght=0;
    fseek(tempFile, pos, SEEK_SET);
    fscanf(tempFile, "%d ", &value);
    printf("\n%d ", value);

    while(value>0)
    {
        value = value/10;
        valueLenght++;
    }
    printf(" -- %d\n", valueLenght);

    fseek(tempFile, pos, SEEK_SET);
    for(int i=0; i<valueLenght; i++)
        fputs(" ", tempFile);

    fclose(tempFile);

    //rewind(tempFile);

    /*for(int i=0; i<=istenenIndex; i++)
        fscanf(tempFile, "%d ", &value);
    printf("%d", value);

    
    */

    /*while(1)
    {
        /*scanf("%d", &istenenIndex);
        rewind(tempFile);*/

        /*int index = 0;
        int pos=0;*/
        /* */


        /*while(index<istenenIndex)
        {
            if(fgetc(tempFile) == " " && fgetc(tempFile != " "))
                index++;
        }*/

        /*char oldChar, newChar;
        newChar = fgetc(tempFile);
        while(!feof(tempFile))
        {
            oldChar = newChar;
            newChar = fgetc(tempFile);
            if(oldChar == ' ' && newChar != ' ')
                index++;
        }
        printf("%d", index);

        

        rewind(tempFile);
        /*fscanf(tempFile, "%d ", &value);
        printf("%d\n", value);*/

        /*fseek(tempFile, index, SEEK_SET);
        for(int i=0; i<valueLenght; i++)
            fputs(" ", tempFile);*/
       

    /*}*/


/*    
    fseek(tempFile, 20, SEEK_SET);
    fputs(" ", tempFile);
*/

    //fscanf(tempFile, "%d ", &value);
    //printf("%d\n", value);
    
    /*while(!feof(tempFile))
    {
    }*/
    //remove("results.txt");

    removeIndexFromTxt(3);
}
    
void removeIndexFromTxt(int index)
{
    FILE* tempFile;
    tempFile = fopen("results.txt", "r+");
    //fputs("30 31 32 2822 36 36 40 41 42 43", tempFile);
    rewind(tempFile);
    int counter = 0, value;
    int cursorIndex = 0 ;
    int pos=0;
    char oldChar, newChar;

    do{
        newChar = fgetc(tempFile);
        if(newChar == ' ')
            pos++;
    }while(newChar == ' ');

    while(cursorIndex < index)
    {
        oldChar = newChar;
        newChar = fgetc(tempFile);
        printf("%c%c\n", oldChar,newChar);
        if(oldChar == ' ' && newChar != ' ')
            cursorIndex++;
        pos++;
    }

    int valueLenght=0;
    fseek(tempFile, pos, SEEK_SET);
    fscanf(tempFile, "%d ", &value);



    do
    {
        value = value/10;
        valueLenght++;
    }while(value>0);

    fseek(tempFile, pos, SEEK_SET);
    for(int i=0; i<valueLenght; i++)
        fputs("a", tempFile);

    fclose(tempFile);
}
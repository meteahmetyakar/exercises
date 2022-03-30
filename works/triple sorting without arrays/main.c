#include <stdio.h>
#include <math.h>

#define MAX_VALUE 2147483647

int main()
{
    while(1)
    {
        int select = -1, sumOrMulti=-1, evenOrOdd=-1;
        int N1 = -1, N2 = -1;
        int N3, result;

        while(select < 1 || select > 5)
        {
            printf("Select operation\n");
            printf("1. Calculate sum/multiplication between two numbers\n");
            printf("2. Calculate prime numbers\n");
            printf("3. Show number sequence in file\n");
            printf("4. Sort number sequence in file\n");
            printf("5. Exit\n");
            printf("---------------------------------\n");
            scanf("%d", &select);
        }

        switch(select)
        {
            case 1:
                while(sumOrMulti < 0 || sumOrMulti > 1)
                {
                    printf("Please enter '0' for sum, '1' for multiplication.\n");
                    scanf("%d", &sumOrMulti);
                    if(sumOrMulti < 0 || sumOrMulti > 1)
                        printf("\n\n### INVALID INPUT TRY AGAIN ###\n\n");
                }

                while(evenOrOdd < 0 || evenOrOdd > 1)
                {
                    printf("Please enter '0' to work on even numbers, '1' to work on odd numbers.\n");
                    scanf("%d", &evenOrOdd);
                    if(evenOrOdd < 0 || evenOrOdd > 1)
                        printf("\n\n### INVALID INPUT TRY AGAIN ###\n\n");
                }

                while(N1 == N2)
                {
                    do
                    {
                        printf("Number 1: ");
                        scanf("%d", &N1);
                    }while(N1 < 0);

                    do
                    {
                        printf("Number 2: ");
                        scanf("%d", &N2);
                    }while(N2 < 0);

                    if(N1 == N2)
                        printf("Numbers must be different.\n");
                }

                int sumResult, multiResult;
                switch(sumOrMulti)
                {
                    case 0 : 
                        sumResult = sum(N1, N2, evenOrOdd);
                        write_file(sumResult);
                        break;
                    case 1 : 
                        multiResult = multi(N1, N2, evenOrOdd);
                        write_file(multiResult);
                        break;
                    default:
                        printf("Something went wrong!");
                }
                break;
            case 2:
                printf("Please enter an integer: ");
                scanf("%d", &N3);
            
                for(int i=2; i<N3; i++)
                {
                result = isprime(i);

                    if(result == 1)
                        printf("%d is a prime number.\n", i);
                    else
                        printf("%d is not a prime number, it is dividible by %d.\n", i, result);
                }
                printf("\n\n\n");
                break;
            case 3:
                print_file();
                break;
            case 4:
                sort_file();
                printf("\n\n### File Sorted ###\n\n");
                break;
            case 5:
                return 1;
        }
    }
}

int isprime(int a)
{
    for(int X=2; X<=sqrt(a); X++)
    {
        if(a % X == 0)
            return X;
    }

    return 1;
}

void print_file()
{
    FILE* file;
    file = fopen("results.txt", "r");
    int value;

    printf("\n\n############################## RESULTS.TXT #################################\n\n");

    while(!feof(file))
    {
        fscanf(file, "%d ", &value);
        printf("%d ", value);
    }

    printf("\n\n###########################################################################\n\n");
}

void write_file(int number)
{
    FILE* file;
    file = fopen("results.txt", "a");
    fprintf(file, "%d ", number);
    fclose(file);
}

void sort_file()
{
   
    FILE* file;
    FILE* tempFile;

    int pointer, min1, min2, min3;
    int indexOfPointer = -1, indexOfmin1=0, indexOfmin2=0, indexOfmin3=0;

    int min1Counter = -1, min2Counter = -1, min3Counter = -1;

    int loopTimes = numberOfLoopRequired();

    for(int i=0; i<loopTimes; i++)
    {

        file = fopen("results.txt", "r+");
        min1 = MAX_VALUE;
        min2 = MAX_VALUE;
        min3 = MAX_VALUE;

        indexOfPointer = -1;
        indexOfmin1=0; 
        indexOfmin2=0; 
        indexOfmin3=0;

        while(!feof(file))
        {
            fscanf(file, "%d ", &pointer);
            indexOfPointer++;

            printf("\nindex = %d -- pointer = %d\n", indexOfPointer, pointer);

            if(min1 >= pointer)
            {
                min3 = min2;
                indexOfmin3 = indexOfmin2;

                min2 = min1;
                indexOfmin2 = indexOfmin1;

                min1 = pointer;
                indexOfmin1 = indexOfPointer;

            }
            else if (min2 >= pointer)
            {
                min3 = min2;
                indexOfmin3 = indexOfmin2;

                min2 = pointer;
                indexOfmin2 = indexOfPointer;
            }
            else if (min3 >= pointer)
            {
                min3 = pointer;
                indexOfmin3 = indexOfPointer;
            }
        }

        tempFile = fopen("temp.txt", "a");
        if(min1 != MAX_VALUE && min2 != MAX_VALUE && min3 != MAX_VALUE)
            fprintf(tempFile, "%d %d %d ", min1, min2, min3);
        else if(min1 != MAX_VALUE && min2 != MAX_VALUE)
            fprintf(tempFile, "%d %d ", min1, min2);
        else if(min1 != MAX_VALUE)
            fprintf(tempFile, "%d ", min1);

        fclose(tempFile);

        fclose(file);

        int temp;
        if(indexOfmin1 > indexOfmin3)
        {
            temp = indexOfmin1;
            indexOfmin1 = indexOfmin3;
            indexOfmin3 = temp;
        } 
        
        if(indexOfmin1 > indexOfmin2)
        {    
            temp = indexOfmin1;
            indexOfmin1 = indexOfmin2;
            indexOfmin2 = temp;
        } 

        if(indexOfmin2 > indexOfmin3)
        {
            temp = indexOfmin2;
            indexOfmin2 = indexOfmin3;
            indexOfmin3 = temp;
        } 

        printf(" %d -- %d -- %d\n", indexOfmin3, indexOfmin2, indexOfmin1);

        removeIndexFromTxt(indexOfmin3);
        removeIndexFromTxt(indexOfmin2);
        removeIndexFromTxt(indexOfmin1);

    }
    
    remove("results.txt");
    rename("temp.txt", "results.txt");
}

void removeIndexFromTxt(int index)
{
    FILE* tempFile;
    tempFile = fopen("results.txt", "r+");

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
        if(oldChar == ' ' && newChar != ' ')
            cursorIndex++;
        pos++;
    }

    int valueLenght=0;
    fseek(tempFile, pos, SEEK_SET);
    fscanf(tempFile, "%d ", &value);

    while(value>0)
    {
        value = value/10;
        valueLenght++;
    }

    fseek(tempFile, pos, SEEK_SET);
    for(int i=0; i<valueLenght; i++)
        fputs(" ", tempFile);

    fclose(tempFile);
}

int sum(int N1, int N2, int flag)
{
    int sum = 0;

    //if is necessary swap N1 and N2 for put smallest to N1
    if(N1 > N2)
    {
        int temp = N1;
        N1 = N2;
        N2 = temp;
    }

    if(flag == 0 && N1 % 2 != 0)
        N1 += 1;
    else if(flag == 1 && N1 % 2 == 0)
        N1 += 1;
    else
        N1 += 2;

    for(; N1<N2; N1 += 2)
    {
        printf("%d", N1);
        if(N1+2 < N2)
            printf(" + ");
        sum += N1;
    }
    printf(" = %d\n\n", sum);

    return sum;
}

int multi(int N1, int N2, int flag)
{
    int multi = 1;

    //if is necessary swap N1 and N2 for put smallest to N1
    if(N1 > N2)
    {
        int temp = N1;
        N1 = N2;
        N2 = temp;
    }

    if(flag == 0 && N1 % 2 != 0)
        N1 += 1;
    else if(flag == 1 && N1 % 2 == 0)
        N1 += 1;
    else
        N1 += 2;

    for(; N1<N2; N1 += 2)
    {
        printf("%d", N1);
        if(N1+2 < N2)
            printf(" * ");
        multi *= N1;
    }
    printf(" = %d\n\n", multi);

    return multi;
}

int numberOfLoopRequired()
{
    FILE* file;
    file = fopen("results.txt", "r");

    int counter=0, unnecessary;

    while(!feof(file))
    {
        fscanf(file,"%d ", &unnecessary);
        counter++;
    }

    if(counter % 3 == 0)
        return (counter/3);
    else
        return ((counter/3) + 1);
    
    fclose(file);
}
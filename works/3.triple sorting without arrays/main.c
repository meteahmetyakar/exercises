#include <stdio.h>
#include <math.h>

#define MAX_VALUE 2147483647

int isprime(int a);
void print_file();
void write_file(int number);
void sort_file();
void removeIndexFromTxt(int index);
int sum(int N1, int N2, int flag);
int multi(int N1, int N2, int flag);
int numberOfLoopRequired();

int main()
{
    int repeat = 1;
    while(repeat)
    {
        int select = -1, sumOrMulti=-1, evenOrOdd=-1;   //selection variables
        int N1 = -1, N2 = -1;   //numbers   (1)
        int N3, result;         //for prime numbers (2)

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
                        if(sumResult != -1)   //-1 is error code, returns -1 if a range that cannot be calculated is entered for example sum odd numbers between 1 to 3
                        {
                            write_file(sumResult);
                            printf("\nThe result is written to the results.txt file.\n\n");
                        }
                        else
                            printf("\n### The requested operation cannot be performed within this range. ###\n\n");

                        break;

                    case 1 : 
                        multiResult = multi(N1, N2, evenOrOdd);
                        if(multiResult != -1)   //-1 is error code, returns -1 if a range that cannot be calculated is entered for example multi odd numbers between 1 to 3
                        {
                            write_file(multiResult);
                            printf("\nThe result is written to the results.txt file.\n\n");
                        }
                        else
                            printf("\n### The requested operation cannot be performed within this range. ###\n\n");

                        break;
                    default:
                        printf("Something went wrong!");
                }
                break;
            case 2: //prime number calculator
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
                print_file();
                break;
            case 5:
                repeat = 0;
                break;
        }
    }
}

int isprime(int a)
{   //A is prime if A is not dividible by any integer X where X is; 1 < 𝑋 ≤ sqrt(a)
    for(int X=2; X<=sqrt(a); X++)
    {
        if(a % X == 0)
            return X;
    }

    return 1;
}

int sum(int N1, int N2, int flag)
{
    int sum = 0;
    int isHaveResult = 0;   //if it can calculate within the given range it will be 1

    //if is necessary swap N1 and N2 for put smallest to N1
    if(N1 > N2)
    {
        int temp = N1;
        N1 = N2;
        N2 = temp;
    }

    printf("Result \n");

    //Calculating how many numbers from N1 to start calculating
    if(flag == 0 && N1 % 2 != 0)
        N1 += 1;
    else if(flag == 1 && N1 % 2 == 0)
        N1 += 1;
    else
        N1 += 2;

    //Adding is done by starting from N1 and increasing by twos up to N2.
    for(; N1<N2; N1 += 2)
    {
        isHaveResult = 1;
        printf("%d", N1);
        if(N1+2 < N2)
            printf(" + ");
        sum += N1;
    }
    if(isHaveResult)
        printf(" = %d\n", sum);
    else if(!isHaveResult)
        return (-1);

    return sum;
}

int multi(int N1, int N2, int flag)
{
    int multi = 1;
    int isHaveResult = 0;   ////if it can calculate within the given range it will be 1

    //if is necessary swap N1 and N2 for put smallest to N1
    if(N1 > N2)
    {
        int temp = N1;
        N1 = N2;
        N2 = temp;
    }

    printf("Result \n");

    //Calculating how many numbers from N1 to start calculating
    if(flag == 0 && N1 % 2 != 0)
        N1 += 1;
    else if(flag == 1 && N1 % 2 == 0)
        N1 += 1;
    else
        N1 += 2;

    //multiplying is done by starting from N1 and increasing by twos up to N2.
    for(; N1<N2; N1 += 2)
    {   
        isHaveResult = 1;
        printf("%d", N1);
        if(N1+2 < N2)
            printf(" * ");
        multi *= N1;
    }

    if(isHaveResult)
        printf(" = %d\n", multi);
    else if(!isHaveResult)
        return(-1);
    return multi;
}

void write_file(int number)
{
    FILE* file;
    file = fopen("results.txt", "a"); //If the file does not exist, it is being created, if there is, it is opened for writing.
    fprintf(file, "%d ", number);   //write number to file
    fclose(file);
}

void print_file()
{
    FILE* file;
    file = fopen("results.txt", "r");
    int value;

    if(file != NULL)
    {
        printf("\n\n############################## RESULTS.TXT #################################\n\n");

        while(!feof(file))
        {
            fscanf(file, "%d ", &value);
            printf("%d ", value);
        }

        printf("\n\n###########################################################################\n\n");
    }
    else
        printf("\n\n### File is not exist. ###\n\n");
    
}

void sort_file()
{
   
    FILE* file;
    FILE* tempFile;

    int pointer, min1, min2, min3;
    int indexOfPointer = -1, indexOfmin1=0, indexOfmin2=0, indexOfmin3=0;

    if(!(file = fopen("results.txt", "r")))  //If the file does not exist, it creates
    {
        file = fopen("results.txt", "a");
        fclose(file);
    }

    int min1Counter = -1, min2Counter = -1, min3Counter = -1;

    int loopTimes = numberOfLoopRequired(); //Calculating how many times the file should be read

    if(loopTimes == 0)
        printf("\n --- The file does not have enough numbers to sort --- \n\n");
    else
    {
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

            //Read to the end of the file and find the three smallest numbers in the file
            while(!feof(file))
            {
                fscanf(file, "%d ", &pointer);
                indexOfPointer++;

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

            /*it also checks the cases where there is no triple and prints it to the file.
            For example, if there are 14 elements in the file,
            we cannot triple print for the last 2 elements,
            we need to print them in binary. In this part, we do that.*/

            tempFile = fopen("temp.txt", "a");
            if(min1 != MAX_VALUE && min2 != MAX_VALUE && min3 != MAX_VALUE)
                fprintf(tempFile, "%d %d %d ", min1, min2, min3);
            else if(min1 != MAX_VALUE && min2 != MAX_VALUE)
                fprintf(tempFile, "%d %d ", min1, min2);
            else if(min1 != MAX_VALUE)
                fprintf(tempFile, "%d ", min1);

            fclose(tempFile);

            fclose(file);

            /*While sorting the elements, we delete from the file so that a previously checked number is not checked again,
            and we do the deletion from the file according to the rank of the element.
            We keep these indexes while sorting the elements. Since the order of the other indexes will shift when you delete an index,
            we list these three indexes to be deleted here, and when deleting, the largest index is deleted first.*/

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

            //delete th element
            removeIndexFromTxt(indexOfmin3);
            removeIndexFromTxt(indexOfmin2);
            removeIndexFromTxt(indexOfmin1);

        }
        printf("\n\n### File Sorted ###\n\n");
        remove("results.txt");
        rename("temp.txt", "results.txt");
    }
    


}

void removeIndexFromTxt(int index)
{
    /*If a character is followed by a space, it is a number and counts as an index.
    When the given index number is reached, the characters of the number in that index are replaced with spaces and deleted.*/

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

    //The number of characters in the index is calculated and the number of elements calculated from that position is deleted.
    do
    {
        value = value/10;
        valueLenght++;
    }while(value>0);

    fseek(tempFile, pos, SEEK_SET);
    for(int i=0; i<valueLenght; i++)
        fputs(" ", tempFile);

    fclose(tempFile);
}

int numberOfLoopRequired()
{
    //The number of elements in the file divided by three is required, here this is calculated.
    FILE* file;
    file = fopen("results.txt", "r");

    int counter=0, unnecessary;

    while(!feof(file))
    {
        if(fscanf(file,"%d ", &unnecessary))
            counter++;
    }
    
    if(counter == 1)
        return (0);
    else if(counter % 3 == 0)
        return (counter/3);
    else
        return ((counter/3) + 1);

    
    fclose(file);
}
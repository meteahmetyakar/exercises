#include <stdio.h>
#include "util.h"

int main()
{
    /* menu variables */
    int selectMainScreen = -1;
    int selectUserScreen = -1;
    int selectLastScreen = -1;

    /* user information */
    char identity_number[11];
    int isValidate = 0;
    int password;

    /* cash variables */
    float cash_amount;
    int withdrawable;

    /* divisible part variables */
    int firstInteger, secondInteger;
    int divisor;
    int numberOfStepsAfterDivisible;
    int nthNumber;

    while(1)
    {
        while(selectMainScreen <= 0 || selectMainScreen  >= 3)  //A loop that loops unless selectMainScreen is 1 or 2
        {
            printf("\n===========MAIN SCREEN==========\n");
            printf("1- Find Divisible (PART 1)\n");
            printf("2- User Screen    (PART 2 & PART 3)\n");
            printf(">>> ");
            scanf("%d", &selectMainScreen);

            if(selectMainScreen <= 0 || selectMainScreen  >= 3) //if selectMainScreen is not 1 or 2, print error msg to screen
            {
                printf("\n===============CAUTION==============\n");
                printf("------------INVALID INPUT----------\n\n");
                printf("======================================\n");
            }
        }
        
        /* PART 1 START */
        if(selectMainScreen == 1) //if 1 is selected in MAIN SCREEN
        {
            printf("\n\nEnter the first integer: ");
            scanf("%d", &firstInteger);

            printf("Enter the second integer: ");
            scanf("%d", &secondInteger);

            printf("Enter the divisor: ");
            scanf("%d", &divisor);

            int divisibleNumber = find_divisible(firstInteger, secondInteger, divisor); //The divisible number of the divisor between f_i and s_i is assigned to divisibleNumber
            if(divisibleNumber == -1) //-1 is the error code
                printf("\nThere is not any integer between %d and %d can be divided by %d\n", firstInteger, secondInteger, divisor);
            else
            {
                printf("\nThe first integer between %d and %d divided by %d is %d\n", firstInteger, secondInteger, divisor, divisibleNumber);

                printf("Enter the number how many next: ");
                scanf("%d", &numberOfStepsAfterDivisible);

                nthNumber = find_nth_divisible(numberOfStepsAfterDivisible, divisibleNumber, divisor);

                int place = numberOfStepsAfterDivisible + 1; //With the first number n. by adding the number, the resulting place is calculated.
                
                char* placeTag = "th";          //setting characters to be used in place as 2nd,3rd ... 8th
                if(place == 2)
                    placeTag = "nd";
                else if(place == 3)
                    placeTag = "rd";


                if(nthNumber >= secondInteger)  //If nthNumber is greater than secondInteger then out of range
                    printf("No possible to find %d%s divisible between %d and %d divided by %d\n", place, placeTag, firstInteger, secondInteger, divisor);
                else
                    printf("%d%s integer between %d and %d divided by %d is %d\n", place, placeTag, firstInteger, secondInteger, divisor, nthNumber);
            }
        /* PART 1 END */
        }/* PART 2 & PART 3 START  */
        else if(selectMainScreen == 2)  //if 1 is selected in MAIN SCREEN
        {
            while(selectUserScreen <= 0 || selectUserScreen  >= 3)      //A loop that loops unless selectUserScreen is 1 or 2
            {
                printf("\n===========USER SCREEN=======\n");
                printf("1-Login\n");
                printf("2-New Registration\n");
                printf(">>> ");
                scanf("%d", &selectUserScreen);
                if(selectUserScreen <= 0 || selectUserScreen  >= 3)     //if selectUserScreen is not 1 or 2, print error msg to screen
                {
                    printf("\n===============CAUTION==============\n");
                    printf("------------INVALID INPUT----------\n\n");
                    printf("======================================\n");
                }
            }

            if(selectUserScreen == 1) //if 1 is selected in USER SCREEN
            {
                for(int entries=3; entries>0; entries--) //A loop that loops 3 times, with this we will give the user three wrong inputs right
                {   
                    printf("\nEnter your identity number: ");
                    scanf("%s", identity_number);

                    printf("Enter your password: ");
                    scanf("%d", &password);

                    if(check_login(identity_number, password))                  //if check_login returns 1, ID and passwd are correct
                    {
                        printf("\n=== Login Succesfull ===\n\n");
                        printf("Enter your withdraw amount: ");
                        scanf("%f", &cash_amount);
                        withdrawable = withdrawable_amount(cash_amount);        //withdrawable amount puts to withdrawable variable
                        printf("Withdrawable amount is: %d\n\n", withdrawable);
                        break;
                    }
                    else                    //if check_login returns without 1, print error msg and entry info
                    {   
                        printf("\n=============CAUTION=============\n");
                        printf("Invalid identity number or password\n");
                        if(entries-1 != 0)  //if entries-1 is not zero, users have remaining incorrect rights and we print the remaining incorrect login rights
                        {
                            printf("You have %d wrong entries left\n", entries-1);
                        }
                        else                //if entries - 1 in zero, we print error msg and terminate the program
                        {
                            printf("You made too many incorrect entries, the program is terminating.\n");
                            return (0);
                        }
                        printf("======================================\n");
                    }
                }
                
            }
            else if(selectUserScreen == 2)  //if 2 is selected in USER SCREEN
            {
                do  //a loop that loops until a valid ID is entered
                {
                    printf("\nEnter your identity number: ");
                    scanf("%s", identity_number);

                    isValidate = validate_identity_number(identity_number);

                    if(!isValidate) //if it isn't validate 
                    {
                        printf("\n===============CAUTION==============\n");
                        printf("This is not a validate ID number\n");
                        printf("======================================\n");
                    }

                }while(!isValidate);
                
                printf("Enter your password: ");
                scanf("%d", &password);
                
                create_customer(identity_number, password);
                printf("User Created\n");
            }
        }

        while(selectLastScreen <= 0 || selectLastScreen >= 4)       //A loop that loops unless selectLastScreen is 1, 2 or 3
        {
            printf("\n\n============= EXIT SCREEN ==========\n");
            printf("1- Go to Main Screen\n");
            printf("2- Go to User Screen\n");
            printf("3- EXIT\n");
            printf(">>> ");
            scanf("%d", &selectLastScreen);
            if(selectLastScreen <= 0 || selectLastScreen >= 4)      //if selectLastScreen is not 1, 2 or 3, print error msg to screen
            {
                printf("\n===============CAUTION==============\n");
                printf("------------INVALID INPUT----------\n\n");
                printf("======================================\n");
                
            }
        }

        //Making settings to go to the screen selected at above
        if(selectLastScreen==1)
            selectMainScreen = -1;
        else if(selectLastScreen == 2)
            selectMainScreen = 2;
        else if(selectLastScreen = 3)
            return (0);

        selectUserScreen = -1;
        selectLastScreen = -1;

        /* PART 2 & PART 3 END  */
    }
    

}
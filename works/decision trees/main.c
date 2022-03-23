#include <stdio.h>
#include <stdlib.h>
#include "util.h"


int main() {

    /* Ask for the problem selection (1,2,3) .....  */

    char selection = 0;
    
    //Problem 0
    int t, s = -1, w = -1; //temperature(t), sunny_or_not(s) and day_of_the_week(w)
    double p, h; //pressure(p), humidity(h)

    //Problem 1
    float PL, PW, SL, SW;
    char result_dt1a, result_dt1b;

    //Problem 2
    float x1, x2, x3;
    int x4, x5;
    float result_dt2a, result_dt2b;
    
    //Problem 3
    float result_dt3a, result_dt3b;
    int age = -1, isStudent = -1, timeOnComputer = -1, whatFor = -1, income = -1; 
    /* isStudent = binary
       timeOnComputer = daily time spent at the computer 
       whatFor = what do you use the computer for (game, movie/music, work)
       income = budget allocated to purchase a computer */


    while(selection < 48 || selection > 51)
    {
        printf("What problem do you want to solve\n");
        printf("0 - example tree\n");
        printf("1 - First tree\n");
        printf("2 - Second tree\n");
        printf("3 - Third tree\n");
        scanf("%c", &selection);

        if(selection < 48 || selection > 51)
            printf("\n\nPlease enter valid input!!\n\n");
    }

    if(selection=='0')
    {
        printf("Please enter temperature");
        scanf("%d", &t);

        while(s < 0 || s>1)
        {
            printf("is it sunny \n 0 - NO\n 1 = YES\n");
            scanf("%d", &s);
        }
        
        while(w<1 || w>7)
        {
            printf("what day\n");
            printf("1 - Mon\n");
            printf("2 - Tue\n");
            printf("3 - Wed\n");
            printf("4 - Thu\n");
            printf("5 - Fri\n");
            printf("6 - Sat\n");
            printf("7 - Sun\n");
            scanf("%d", &w);
        }

        printf("Please enter pressure\n");
        scanf("%lf", &p);


        printf("Please enter humidity\n");
        scanf("%lf", &h);

    }
    else if(selection == '1')
    {
        printf("Please enter the PL PW SL SW values in order\n");
        scanf("%f%f%f%f", &PL, &PW, &SL, &SW);

        result_dt1a = dt1a(PL, PW, SL, SW);
        result_dt1b = dt1b(PL, PW, SL, SW);

        if(result_dt1a == result_dt1b)
        {
            printf("Values are same in trees, answer is ");
            if(result_dt1a == 's')
                printf("setosa\n");
            else if(result_dt1a == 'i')
                printf("virginica\n");
            else if (result_dt1a == 'v')
                printf("versicolor\n");
        }
        else
        {
            printf("Values are not same\n");
            printf("result of first tree = ");
            if(result_dt1a == 's')
                printf("setosa");
            else if(result_dt1a == 'i')
                printf("virginica");
            else if (result_dt1a == 'v')
                printf("versicolor");
            
            printf("\nresult of second tree = ");
            if(result_dt1b == 's')
                printf("setosa\n");
            else if(result_dt1b == 'i')
                printf("virginica\n");
            else if (result_dt1b == 'v')
                printf("versicolor\n");
        }

    }
    else if(selection == '2')
    {
        printf("Please enter the x1, x2, x3, x4, x5 values in order\n");
        scanf("%f%f%f%d%d",&x1, &x2, &x3, &x4, &x5);

        result_dt2a = dt2a(x1, x2, x3, x4, x5);
        result_dt2b = dt2b(x1, x2, x3, x4, x5);

        if(result_dt2a == result_dt2b + CLOSE_ENOUGH || result_dt2a == result_dt2b - CLOSE_ENOUGH)
            printf("values are close enough result is ", (result_dt2a+result_dt2b)/2);
        else
            printf("values are not close enough\n result of first tree = %f\n result of second tree = %f\n", result_dt2a, result_dt2b);

    }
    else if(selection == '3')
    {
        printf("\n\n\n##################################################################");
        printf("\nHow much of the money you allocate on buying a computer should you buy computer equipment?\n");
        printf("\nWe'll calculate that\n");
        printf("\nEquipments\n-Mouse\n-Keyboard\n-Headphones\n-Computer chair\n\n");
        while(age < 0 || age > 99)
        {
            printf("Enter your age\n");
            scanf("%d", &age);
        }

        while(isStudent < 0 || isStudent > 1)
        {
            printf("Are you a student?\n0 - No \n1 - Yes \n");
            scanf("%d", &isStudent);
        }

        while(timeOnComputer < 0.1)
        {
            printf("Please enter daily time spent at the computer\n");
            scanf("%f", &timeOnComputer);
        }

        while(whatFor < 1 || whatFor > 3)
        {
            printf("what do you use the computer for \n1 - game\n2 - movie/music\n3 - work\n");
            scanf("%d", &whatFor);
        }

        while(income < 0)
        {
            printf("Enter your budget allocated to purchase a computer as dollar\n");
            scanf("%d", &income);
        }

        result_dt3a = dt3a(age, isStudent, timeOnComputer, whatFor, income);
        result_dt3b = dt3b(age, isStudent, timeOnComputer, whatFor, income);

        if(result_dt3a == result_dt3b)
            printf("results are same. result is %f", result_dt3a);
        else
        {
            printf("results are not same.\nresult of first tree = %f\n",result_dt3a);
            printf("result of second tree = %f\n",result_dt3b);
        }
    }

    return 0;
}

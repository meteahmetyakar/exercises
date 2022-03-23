#include <stdio.h>
#include "util.h"

/* Example decision tree - see the HW2 description */
int dt0(int t, double p, double h, int s, int w) {
    int r = 0;
    
    if (t>35 && w!=3) r = 1;
    else if (t<=35 && s==0) r = 1;
    
    return r;
}

char dt1a(float PL, float PW, float SL, float SW){
    if(PL < 2.45)
        return('s');
    else if(PW < 1.75)
    {
        if(PL < 4.95)
        {
            if(PW<1.65)
                return('v');
            else
                return('i');
        }
        else
            return('i');
    }
    else
        return('i');

}

char dt1b(float PL, float PW, float SL, float SW){
    if(PL < 2.55)
        return('s');
    else if(PW < 1.69)
    {
        if(PL < 4.85)
            return('v');
        else
            return('i');
    }
    else
        return('i');

}

double dt2a(float x1, float x2, float x3, int x4, int x5)
{
    if(x1<31.5)
    {
        if(x2> -2.5)
        {
            return 5.0;
        }
        else
        {
            if(x2-0.1 <= x1 && x1 <= x2+0.1)
                return 2.1;
            else
                return -1.1;
        }
    }
    else
    {
        if(-1<=x3 && x3<=2)
        {
            return 1.4;
        }
        else
        {
            if(x4 && x5)
                return -2.23;
            else
                return 11.0;
        }
    }
}

double dt2b(float x1, float x2, float x3, int x4, int x5)
{
    const float root2 = 1.414;

    if(12<x1 && x1<22)
    {
        if(x3> 5.0/3.0)
            return -2.0;
        else
        {
            if(x1-0.1 <= x3 && x3 <= x1+0.1)
                return 1.01;
            else
                return -8;
        }
    }
    else
    {
        if(x4 && x5)
        {
            return -1;
        }
        else
        {
            if(-1<=x2 && x2<=2)
                return(-1.0/7.0);
            else
                return(root2/3);
        }
    }
}

/*  The some values is kept high in order to buy a computer chair
        for people who sit in front of the computer for a long time
        and who are in the developmental age. */

// how much money should be spent on computer equipment

float dt3a(int age, int isStudent, float timeOnComputer, int whatFor, int income)
{
   if(isStudent == 1)
       return(takePercent(income,25.0));
    else
    {
        if(whatFor == 1) //1 = game
        {
            if(timeOnComputer > 6)
            {
                if(income>1000)
                    return(takePercent(income,30.0));
                else if(income>750)
                    return(takePercent(income,20.0));
                else if(income>500)
                    return(takePercent(income,20.0));
                else
                    return(takePercent(income, 25.0));
            }
            else if(income > 400)
                return(takePercent(income,10.0));
            else
                return(takePercent(income,2.5));
        }
        else if(whatFor == 2) //2 = music/movie
        {
            if(timeOnComputer<2)
                return(takePercent(income,2.5));
            else if(income>350)
                return(takePercent(income,2.5));
            else
                return(takePercent(income, 1.0));
        }
        else if(whatFor == 3) //3 = work
        {
            if(age>40)
                return(takePercent(income, 25.0));
            else if(income>100)
                return(takePercent(income, 20.0));
            else if(income>750)
                return(takePercent(income, 5.0));
            else
                return(takePercent(income, 2.5));
        }
    }
}

float dt3b(int age, int isStudent, float timeOnComputer, int whatFor, int income)
{
    if(timeOnComputer<1.5)
        return(takePercent(income,1.0));
    else
    {
        if(whatFor == 1)
        {
            if(timeOnComputer<4.5)
            {
                if(income > 400)
                    return(takePercent(income,10.0));
                else
                    return(takePercent(income, 2.5));
            }
            else
            {
                if(income>1000)
                    return(takePercent(income, 30.0));
                else
                {
                    if(14 < age && age < 21)
                    {
                        if(income>500)
                            return(takePercent(income, 20.0));
                        else
                            return(takePercent(income, 25.0));
                    }
                    else
                    {
                        if(income>500)
                            return(takePercent(income, 10.0));
                        else
                            return(takePercent(income, 5.0));
                    }

                }
            }
        }
        else if(whatFor == 2)
        {
            if(timeOnComputer<2.5)
                return(takePercent(income, 2.5));
            else if(income > 350)
                 return(takePercent(income, 2.5));
            else
                return(takePercent(income, 1.0));
        }
        else if(whatFor == 3)
        {
            if(isStudent == 1)
            {
                if(income>750)
                    return(takePercent(income, 25.0));
                else
                    return(takePercent(income, 20.0));
            }
            else if(income>750)
                return(takePercent(income, 5.0));
            else
                return(takePercent(income, 2.5));
        }
    }
}

float takePercent(int income, float percent) // Function that takes the percentage of the given number
{
    float f_income = income * 1.0; //income converting to float
    return((f_income*percent)/100);
}

/* Provide your implementations for all the requested functions here */

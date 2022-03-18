#include <stdio.h>
#include "util.h"

/* Example decision tree - see the HW2 description */
int dt0(int t, double p, double h, int s, int w) {
    int r = 0;
    if (t>35 && w!=3) r = 1;
    else if (t<=35 && s==0) r = 1;
    return r;
}


/* Provide your implementations for all the requested functions here */
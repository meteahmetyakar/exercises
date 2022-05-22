#ifndef _UTIL_H_
#define _UTIL_H_

#define CLOSE_ENOUGH 0.001

/* Example decision tree - see the HW2 description */
int dt0(int t, double p, double h, int s, int w);

char dt1a(float PL, float PW, float SL, float SW);
char dt1b(float PL, float PW, float SL, float SW);

double dt2a(float x1, float x2, float x3, int x4, int x5);
double dt2b(float x1, float x2, float x3, int x4, int x5);

/* Write the prototype of the functions implementing the decision trees for the third problem */
float dt3a(int age, int isStudent, float timeOnComputer, int whatFor, int income);
float dt3b(int age, int isStudent, float timeOnComputer, int whatFor, int income);


float takePercent(int income, float percent);

#endif /* _UTIL_H_ */
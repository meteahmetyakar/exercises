#include <stdio.h>
#include "util.h"
/* functions of PART 1 */
                 //start, end,   divisor
int find_divisible(int x, int y, int z){
    for(; x<y; ++x)                                 //A loop that loops while y bigger than x
        if(x % z == 0)      
            return x;
    return -1;                                      //If it comes this far, then there is no divisible number in the range.
}
                     //nth,   star,    divisor
int find_nth_divisible(int n, int f_i, int z){
    int nthNumber;
    nthNumber = f_i + (n*z);                        //desired number calculating
    return nthNumber;
}
/* end functions of PART 1  */

/* functions of PART 2 */
int validate_identity_number(char identity_number[]){
    
    int step = 0;
    int sumOfEvenIndex=0;   //0 2 4 6 8 <-- indexes
    int sumOfOddIndex=0;    //1 3 5 7   <-- indexes
    int evenOrOddIndex=0;   /*It will to be used as flag. 0 means it is a even index, 
                            if it is a even index the sum will be added to sumOfEvenIndex. For 1, the opposite is true, odd index, added to sumOfOddIndex*/

    if(identity_number[0] == '0')   //if first element is zero
        return (0);
    
    for(step=0; ; step++)           //lenght control of identity_number
	{
		if(identity_number[step] == '\0') 
		{
            if(step != 11)
                return (0);
			break;
		}
	}

    step = 0;

    while(identity_number[step] != '\0') //a loop that loops until end of identity_number
    {
        if(identity_number[step] < 48 || identity_number[step] > 57 ) //if characters are number (ASCII[48-57])
            return (0);
        else
        {
            int digit = identity_number[step] - 48; //convert from char to integer
            if(step < 9)                            //if in first 9 index in identity_number
            {   
                if(evenOrOddIndex == 0)             //here we control being even or odd of index
                {                                   //if index is even then digit add to sumOfEvenIndex
                    sumOfEvenIndex += digit;
                    evenOrOddIndex = 1;
                }
                else
                {                                   //if index is odd then digit add to sumOfOddIndex
                    sumOfOddIndex += digit;     
                    evenOrOddIndex = 0;
                }                                   //in this way, we sum the values of the first nine elements while checking if the character is a number.
            }                                       //so we obtain info (valid character, sum of 1-3-5-7-9 and sum of 2-4-6-8) in one loop
        }
        step += 1;
    }

    int modulusFor10th = (sumOfEvenIndex*7 - sumOfOddIndex) % 10;

    if(modulusFor10th != identity_number[9] - 48)           //if 10th element is not equal to modulos of sum of first 9 elements
        return (0);

    int sumOfFirstTenDigit = sumOfEvenIndex + sumOfOddIndex + (identity_number[9] - 48);
    int modulusFor11th = sumOfFirstTenDigit % 10;

    if(modulusFor11th != identity_number[10] - 48)          //if 11th element is not equal to modulos of sum of all 11 elements
       return (0);

    return (1);
}

int create_customer(char identity_number[], int password){
    const char* FILE_NAME = "customeraccounts.txt";
    FILE* database = fopen(FILE_NAME, "w");
    fprintf(database,"%s,%d", identity_number, password); //print to file process
}

/* end functions of PART 2 */

/* functions of PART 3 */
int check_login(char identity_number[], int password)
{
    const char* FILE_NAME = "customeraccounts.txt";
    FILE* database = fopen(FILE_NAME, "r");
    
    char nullCharacter[1];                      //to put ',' character in txt file
    char correnctIdentityNumber[11];            //ID number which take from database
    int correctPassword;                        //ID number which take from database
    
    //take first 11 character from txt file
    for(int index = 0; index<11; index++)                               
    {
        fscanf(database, "%c", &correnctIdentityNumber[index]);
        if(identity_number[index] != correnctIdentityNumber[index])
        {
            return (0);
            fclose(database);
        }
    }

    fscanf(database, "%c", &nullCharacter[0]);  //for the pointer stays in the 12th index (',' character in txt). we take with that and then we can take password 
    fscanf(database, "%d", &correctPassword);   //taking password
    fclose(database);

    if(correctPassword != password)
        return (0);
        
    return (1);
}

int withdrawable_amount(float cash_amount)
{
	int withdrawable_amount; 
    withdrawable_amount = (int)cash_amount;             //convert from float to int to delete after comma (123.42 --> 123)
	withdrawable_amount = (withdrawable_amount/10)*10;  //divide and multiply to 10 for roll down (123 --> 120)

    return (withdrawable_amount);
}
/* end functions of PART 3 */

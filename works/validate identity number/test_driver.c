#include <stdio.h>
#include "util.h"
#include <assert.h>

int main() {

   // Part 1 Tests

   int a = find_divisible(100, 200, 7);
   printf("Part case 1 Result: %d The result should be: %d\n", a, 105);

   int b = find_nth_divisible(4, a,  7);
   printf("Part case 2 Result: %d The result should be: %d\n", b, 133);


   int c = find_divisible(198, 200, 7);
   printf("Part case 3 Result: %d  The result should be: %d\n", c, -1 );

   int d = find_nth_divisible(4, c,  7);
   printf("Part case 4 Result: %d The result should be: %d\n", d, -999);

   // TCKN Validation Tests 

   // correct tckn cases
   int return_value = validate_identity_number("84038726200");
   printf("Is valid tckn %d\n", return_value);

   return_value = validate_identity_number("40644083762");
   printf("Is valid tckn %d\n", return_value);
   
   // false tckn cases
   return_value = validate_identity_number("01234567890");
   printf("Is valid tckn %d\n", return_value);

   return_value = validate_identity_number("84abc726200");
   printf("Is valid tckn %d\n", return_value);

   return_value = validate_identity_number("111");
   printf("Is valid tckn %d\n", return_value);

   return_value = validate_identity_number("abcdefghabc");
   printf("Is valid tckn %d\n", return_value);

   return_value = validate_identity_number("11111111111111111");
   printf("Is valid tckn %d\n", return_value);

   // Create Customer and Check Login Tests 

   int cr_rv = create_customer("84038726200", 1234);
   printf("Valid tckn - create_customer result: %d\n", cr_rv);

   int cl_rv = check_login("84038726200", 1234);
   printf("Check login valid tckn %d\n", cl_rv);

/*
   cr_rv = create_customer("40644083762", 4568);
   printf("Valid tckn - create_customer result: %d\n", cr_rv);

   cl_rv = check_login("40644083762", 4568);
   printf("Check login valid tckn %d\n", cl_rv);

   cr_rv = create_customer("01234567890", 6777) ;
   printf("invalid tckn - create_customer result: %d\n", cr_rv);

   cl_rv = check_login("01234567890", 6777);
   printf("Check login invalid tckn %d\n", cl_rv);

   cr_rv = create_customer("84abc726200", 0123);
   printf("invalid tckn - create_customer result: %d\n", cr_rv);

   cl_rv = check_login("84abc726200", 0123);
   printf("Check login invalid tckn %d\n", cl_rv);


   // wrong password case

   cr_rv = create_customer("84038726200", 4568);
   printf("Valid tckn - create_customer result: %d\n", cr_rv);

   cl_rv = check_login("84038726200", 1234);
   printf("Check login invalid password %d\n", cl_rv);


*/


   int wr = withdrawable_amount(100.75);
   printf("withdrawable_amount for 100.75 is : %d\n", wr);

   wr = withdrawable_amount(105);
   printf("withdrawable_amount for 105 is : %d\n", wr);

   wr = withdrawable_amount(118);
   printf("withdrawable_amount for 118 is %d\n", wr);



    
    return(0);
}

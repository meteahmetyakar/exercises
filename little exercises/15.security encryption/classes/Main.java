/**
 * Main class for test inputs
 */
public class Main {
    static String username = "";
    static String password1 = "";
    static int password2 = 0;

    /**
     * main method
     *
     */
    public static void main(String[] args)
    {
        boolean isValid = true;

        if(!Encryption.checkIfValidUsername(username,0))
        {
            System.out.println("invalid username due to letters or its lenght");
            isValid &= false;
        }
        else if(!Encryption.isValidPswd(password1))
        {
            System.out.println("invalid password1 due to does not contain least 2 bracket, invalid lenght or it does not have letter ");
            isValid &= false;
        }
        else if(password2 < 10 || password2 > 10000)
        {
            System.out.println("invalid password2 number must be between 10 and 10000.");
            isValid &= false;
        }
        else if(!Encryption.containsUserNameSpirit(username, password1))
        {
            System.out.println("invalid password1 it does not contain at least one letter of the username");
            isValid &= false;
        }
        else if(!Encryption.isBalancedPassword(password1))
        {
            System.out.println("invalid password1 is not balanced");
            isValid &= false;
        }
        else if(!Encryption.isPalindromePossible(password1))
        {
            System.out.println("invalid password1 it is not possible to obtain a palindrome from password1");
            isValid &= false;
        }
        else if(!Encryption.isExactDivision(password2, new int[]{4,17,29}))
        {
            System.out.println("invalid password2 it is not possible to obtain the password by the summation of denominations along with arbitrary coefficients");
            isValid &= false;
        }

        if(isValid)
            System.out.println("The username and passwords are valid. The door is opening, please wait...");

    }


}
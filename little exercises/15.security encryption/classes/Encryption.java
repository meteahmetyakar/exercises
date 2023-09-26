import java.util.Stack;

/**
 * Encryption class for decode inputs
 */
public class Encryption {
    /**
     *
     * @param password1 first password of officer
     * @return true if is password1 valid
     */
    public static boolean isValidPswd(String password1)
    {
        if(password1.length() < 8)
            return false;

        int brackets = 0;
        boolean isHaveChar = false;

        for(Character ch : password1.toCharArray())
        {
            if(!Character.isLetter(ch))
            {
                if(ch == '{') brackets++;
                else if(ch == '}') brackets++;
                else if(ch == '[') brackets++;
                else if(ch == ']') brackets++;
                else if(ch == '(') brackets++;
                else if(ch == ')') brackets++;
                else return false;
            }
            else
                isHaveChar = true;
        }

        return brackets >= 2 && isHaveChar;
    }

    /**
     * it check username is valid with recursion
     * @param username username of officer
     * @param idx idx of username characters, it using in recursion calls
     * @return true if username valid
     */
    public static boolean checkIfValidUsername(String username, int idx)
    {
        boolean res = true;

        if(username.length() < 1)
            return false;

        if(!Character.isLetter(username.charAt(idx)))
            return false;

        if(idx < username.length() - 1)
            res &= checkIfValidUsername(username, idx+1);

        return res;
    }

    /**
     * a function which checks if the string password contains at least one letter of the username.
     * @param username username of officer
     * @param password1 first password of officer
     * @return true if password contains at least one letter of the username
     */
    public static boolean containsUserNameSpirit(String username, String password1)
    {
        Stack<Character> staqUsername = new Stack<>();
        Stack<Character> tmpStaqUsername = new Stack<>();
        Stack<Character> staqPsswd = new Stack<>();

        for(Character ch : username.toCharArray())
            staqUsername.push(ch);

        for(Character ch : password1.toCharArray())
            staqPsswd.push(ch);

        Character usn;
        Character psw;
        while(!staqPsswd.empty())
        {
            psw = staqPsswd.pop();
            while(!staqUsername.empty())
            {
                usn = staqUsername.pop();

                tmpStaqUsername.push(usn);

                if(usn == psw)
                    return true;

            }

            while(!tmpStaqUsername.empty())
                staqUsername.push(tmpStaqUsername.pop());
        }

        return false;
    }

    /**
     * it check is password balanced
     * @param password1 first password of officer
     * @return true if password balanced
     */
    public static boolean isBalancedPassword(String password1)
    {

        Stack<Character> staq = new Stack<>();

        for(int i = 0; i < password1.length(); i++)
        {
            Character ch = password1.charAt(i);

            if(ch == '(' || ch == '{' || ch == '[')
                staq.push(ch);
            else if(ch == ')' || ch == '}' || ch == ']')
            {
                if(staq.empty())
                    return false;

                if(staq.peek() == '(')
                {
                    if(ch == ')')
                        staq.pop();
                    else
                        return false;
                }
                else if(staq.peek() == '{')
                {
                    if(ch == '}')
                        staq.pop();
                    else
                        return false;
                }
                else if(staq.peek() == '[')
                {
                    if(ch == ']')
                        staq.pop();
                    else
                        return false;
                }
            }
        }

        return staq.empty();
    }

    /**
     * it check if generete palindrome from given password
     * @param password1 first password of officer
     * @return true if it is generete palindrome from given password
     */
    public static boolean isPalindromePossible(String password1)
    {
        int letters[] = new int[58];
        return generetePalindrome(password1, letters, 0);

    }

    /**
     * it using in generatePalindrome
     */
    private static boolean ignored = false;

    /**
     * it check if generete palindrome from given password
     * @param password1 first password of officer
     * @param letters it hold letters count in password
     * @param idx index of letters
     * @return true if it can generete palindrom from given password
     */
    private static boolean generetePalindrome(String password1, int letters[], int idx)
    {
        boolean res = true;

        if(idx >= password1.length())
            return true;

        if(Character.isLetter(password1.charAt(idx)))
            letters[password1.charAt(idx) - 'A']++;

        res &= generetePalindrome(password1, letters, idx+1);

        if(!Character.isLetter(password1.charAt(idx)))
            return res;

        if(letters[password1.charAt(idx) - 'A'] % 2 == 0)
            letters[password1.charAt(idx) - 'A'] = 0;
        else if(!ignored)
        {
            letters[password1.charAt(idx) - 'A'] = 0;
            ignored = true;
        }
        else
            return false;

        return res;
    }

    /**
     * it check if it is possible to obtain the password by the summation of denominations along with arbitrary coefficients
     * @param password2 second password of officer
     * @param denominations denominations
     * @return true if it is possible obtain the password by the summation of denominations
     */
    public static boolean isExactDivision(int password2, int[] denominations) { return isExactDivisionHelper(password2, denominations, 0); }
    private static boolean isExactDivisionHelper(int psswd2, int[] denominations, int idx)
    {
        return psswd2>=0 && idx<denominations.length && (isExactDivisionHelper(psswd2 - denominations[idx], denominations, idx) || isExactDivisionHelper(psswd2, denominations, idx+1));
    }


}

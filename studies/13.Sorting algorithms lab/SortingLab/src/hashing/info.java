package hashing;

/**
 * it holds string array, its size and push function for add element to string array
 */
public class info {

    /**
     * count of words
     */
    private int count;
    /**
     * words
     */
    private String[] words;

    /**
     * empty parameter constructor it initialize count with 0
     */
    info()
    {
        count = 0;
    }

    /**
     * constructor, it initialize words and add given str
     * @param str string for element
     */
    info(String str)
    {
        this();
        push(str);
    }

    /**
     * given string adds to words array
     * @param str string for add to words
     */
    public void push(String str)
    {
        String[] newWords = new String[count + 1]; //create a new array with current array's size + 1
        for(int i=0; i<count; i++) //fill new array with old array
            newWords[i] = words[i];

        newWords[count] = str;  //add given string to new array
        count++; //words size increment

        words = newWords; //words reference assing to newWords reference
    }

    /**
     * overrided toString function
     * @return it returns words array as [word1, word2, ...]
     */
    @Override
    public String toString()
    {
        String result = new String();
        result += "[";
        int idx;
        for(idx = 0; idx < words.length-1; idx++)
           result += words[idx] + ", " ;
        result += words[idx] + "]";

        return result;
    }

    /**
     * getter for count
     * @return count
     */
    public int getCount() { return count; }

    /**
     * getter for words
     * @return words
     */
    public String[] getWords() { return words; }

}

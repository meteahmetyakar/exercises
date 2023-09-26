package hashing;

import java.util.LinkedHashMap;

/**
 * simple map but it initialize with words of given string
 */
public class myMap {
    /**
     * map, its key is Character and its value is HW6.Hashing.info
     */
    private LinkedHashMap<Character, info> map;
    /**
     * size of map
     */
    private int mapSize;
    /**
     * given original string
     */
    private String originalStr;

    /**
     * preprocessed string
     */
    private String preprocessedStr;

    /**
     * getter for map
     * @return map
     */
    public LinkedHashMap<Character, info> getMap() {
        return map;
    }

    /**
     * getter for mapSize
     * @return mapSize
     */
    public int getMapSize() {
        return mapSize;
    }

    /**
     * getter for originalStr
     * @return originalStr
     */
    public String getOriginalStr() {
        return originalStr;
    }

    /**
     * getter for preprocessedStr
     * @return preprocessedStr
     */
    public String getPreprocessedStr() {
        return preprocessedStr;
    }

    /**
     * constructor with parameter, it initialize originalStr and build map with given string
     * @param str
     */
    public myMap(String str)
    {
        this();
        this.originalStr = str;
        buildMap(str);
    }

    /**
     * it initialize map and mapSize
     */
    public myMap()
    {
        map = new LinkedHashMap<>();
        mapSize = 0;
    }

    /**
     * it convert  given input to valid form
     * @param input input for convert to valid
     * @return return valid form
     */
    private String setValid(String input)
    {
        String result = new String();
        for (int i = 0; i < input.length(); i++)
        {
            char c = input.charAt(i);
            if (Character.isLetter(c)) {
                result += Character.toLowerCase(c);
            } else if (c == ' ' && result.length() != 0 && result.charAt(result.length()-1) != ' ') {
                result += ' ';
            }
        }

        System.out.println("Input: " + input + "\nConverted to valid form: " + result + "\n");

        return result;
    }

    /**
     * build map with given input, firstly it convert to valid form and split it with ' ' (space), and it add to map these splitted words
     * @param input string for build map
     */
    private void buildMap(String input)
    {
        preprocessedStr = setValid(input);

        for(String str : preprocessedStr.split(" "))
        {
            for(Character ch : str.toCharArray())
            {
                if(map.get(ch) == null)
                    this.put(ch, new info(str));
                else
                    map.get(ch).push(str);
            }
        }

    }

    /**
     * put given element to map
     * @param ch key
     * @param inf value
     */
    public void put(Character ch, info inf)
    {
        map.put(ch, inf);
        mapSize++;
    }

    /**
     * overrided toString function
     * @return empty
     */
    @Override
    public String toString()
    {
        String result = new String();
        for(var key : map.keySet())
            result += "Letter: " + key + " - " + "Count: " + map.get(key).getCount() + " - " + "Words: " + map.get(key) + "\n";
        return result;
    }

}

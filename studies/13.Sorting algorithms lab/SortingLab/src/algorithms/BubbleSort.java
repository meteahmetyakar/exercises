package algorithms;

import hashing.myMap;

import java.util.Set;

/**
 * it implements BubbleSort algorithm
 */
public class BubbleSort {

    /**
     * unsorted form of map
     */
    private myMap originalMap;
    /**
     * sorted form of map
     */
    private myMap sortedMap;
    /**
     * auxilary for sort operation
     */
    private Character[] aux;

    /**
     * constructor it initialize an object with given map
     * @param originalMap map to be sorted
     */

    public BubbleSort(myMap originalMap)
    {

        this.originalMap = originalMap;
        sortedMap = new myMap();
        aux = new Character[originalMap.getMapSize()];

        Set<Character> keys = originalMap.getMap().keySet();

        int idx = 0;
        for (Character key : keys)
            aux[idx++] = key;

    }

    public void sort()
    {
        long startTime = System.nanoTime();

        boolean isSwapped;
        for(int i = 0; i<aux.length; i++)
        {
            isSwapped = false;
            for(int j = 0; j<aux.length - 1 - i; j++)
            {
                if(originalMap.getMap().get(aux[j]).getCount() > originalMap.getMap().get(aux[j+1]).getCount())
                {
                    Character ch = aux[j];
                    aux[j] = aux[j+1];
                    aux[j+1] = ch;
                    isSwapped = true;
                }
            }
            if(!isSwapped)
                break;
        }

        for(var e : aux)
            sortedMap.put(e, originalMap.getMap().get((Character) e));

        long endTime   = System.nanoTime();
        long totalTime = endTime - startTime;
        System.out.println(totalTime);

    }

    /**
     * getter for originalMap
     * @return originalMap
     */
    public myMap getOriginalMap() {
        return originalMap;
    }

    /**
     * getter for sortedMap
     * @return sortedMap
     */
    public myMap getSortedMap() {
        return sortedMap;
    }


}

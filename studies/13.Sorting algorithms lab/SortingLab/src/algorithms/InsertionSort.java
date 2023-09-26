package algorithms;


import hashing.myMap;

import java.util.Set;
/**
 * it implements InsertionSort algorithm
 */
public class InsertionSort {

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
    public InsertionSort(myMap originalMap)
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

        for(int i = 1; i<aux.length; i++)
        {
            Character ch = aux[i];
            int j = i - 1;
            while(j>=0 && originalMap.getMap().get(aux[j]).getCount() > originalMap.getMap().get(ch).getCount())
            {
                aux[j+1] = aux[j];
                j--;
            }

            aux[j + 1] = ch;

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

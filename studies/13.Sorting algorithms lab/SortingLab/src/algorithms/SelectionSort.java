package algorithms;

import hashing.info;
import hashing.myMap;

import java.util.Set;
/**
 * it implements SelectionSort algorithm
 */
public class SelectionSort {
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
    public SelectionSort(myMap originalMap)
    {
        this.originalMap = originalMap;
        sortedMap = new myMap();
        aux = new Character[originalMap.getMapSize()];

        Set<Character> keys = originalMap.getMap().keySet();

        int idx = 0;
        for (Character key : keys)
            aux[idx++] = key;

    }

    /**
     * implementing selection sort algorithm, it choose smallest element in array every time and swap with start of unsorted part in array
     */
    public void sort()
    {
        long startTime = System.nanoTime();
        info smallest;
        int idx;
        for(int i = 0; i<aux.length; i++)
        {
            smallest = originalMap.getMap().get(aux[i]);
            idx = i;
            for(int j = i; j<aux.length; j++)
            {
                if(originalMap.getMap().get(aux[j]).getCount() < smallest.getCount())
                {
                    smallest = originalMap.getMap().get(aux[j]);
                    idx = j;
                }
            }

            Character ch = aux[i];
            aux[i] = aux[idx];
            aux[idx] = ch;
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

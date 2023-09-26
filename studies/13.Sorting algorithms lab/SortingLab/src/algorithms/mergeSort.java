package algorithms;


import hashing.myMap;

import java.util.Set;

/**
 * it implements mergeSort algorithm
 */
public class mergeSort {

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
    public mergeSort(myMap originalMap)
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
     * it merges two interval ([startIdxP1 - endIdxP1], [startIdxP2 - endIdxP2]) by low to high, include cross intervals
     * @param aux auxiliary array for merge operation
     * @param startIdxP1  start index of Part 1
     * @param endIdxP1  end index of Part 1
     * @param startIdxP2    start index of Part 2
     * @param endIdxP2  end index of Part 2
     */
    private void mergeSortedParts(Character[] aux, int startIdxP1, int endIdxP1, int startIdxP2, int endIdxP2)
    {
        int leftPtrP1 = startIdxP1;
        int leftPtrP2 = startIdxP2;

        Character[] sorted = new Character[(endIdxP1 - startIdxP1) + (endIdxP2 - startIdxP2) + 2]; //create new array for sorted form
        int idx = 0;

        /* fill sorted array with low to high */
        while(leftPtrP1 <= endIdxP1 && leftPtrP2 <= endIdxP2)
            sorted[idx++] = originalMap.getMap().get(aux[leftPtrP1]).getCount() <= originalMap.getMap().get(aux[leftPtrP2]).getCount() ? aux[leftPtrP1++] : aux[leftPtrP2++];

        // this will work if not all part 1 is added to sorted array
        while(leftPtrP1 <= endIdxP1)
            sorted[idx++] = aux[leftPtrP1++];

        // this will work if not all part 2 is added to sorted array
        while(leftPtrP2 <= endIdxP2)
            sorted[idx++] = aux[leftPtrP2++];

        /* total operation is n (sorted array size) times in 3 while */

        idx = 0;

        /* fill aux with sorted elements */
        for(int i=startIdxP1; i<=endIdxP1; i++)
            aux[i] = sorted[idx++];

        for(int i=startIdxP2; i<=endIdxP2; i++)
            aux[i] = sorted[idx++];

    }

    /**
     * recursion merge sort algorithm, It continuously divides the aux into two parts and then combines them in order.
     * @param aux auxilary array
     * @param startIdx start index
     * @param endIdx end index
     */
    private void mergeSort(Character[] aux, int startIdx, int endIdx)
    {
        if(startIdx < endIdx)
        {
            int midIdx = (startIdx + endIdx) / 2;
            mergeSort(aux, startIdx, midIdx);
            mergeSort(aux, midIdx+1, endIdx);
            mergeSortedParts(aux, startIdx, midIdx, midIdx+1, endIdx);
        }
    }

    /**
     * sort aux and fill sortedMap with sorted aux elements
     */
    public void sort() {
        long startTime = System.nanoTime();

        mergeSort(aux, 0, aux.length-1);

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

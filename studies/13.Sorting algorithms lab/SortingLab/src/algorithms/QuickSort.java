package algorithms;


import hashing.myMap;

import java.util.Set;

/**
 * it implements QuickSort algorithm
 */
public class QuickSort {

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
    public QuickSort(myMap originalMap)
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
     * it swaps two element in array
     * @param aux array
     * @param idx1 first element for swapping
     * @param idx2 second element for swapping
     */
    private void swap(Character[] aux, int idx1, int idx2)
    {
        Character ch = aux[idx1];
        aux[idx1] = aux[idx2];
        aux[idx2] = ch;
    }

    /**
     * This function takes last element as pivot, places the pivot element at its correct position in sorted array, and places all smaller to left of pivot and all greater elements to right of pivot
     * @param aux array for sort
     * @param leftPtr index of left side
     * @param rightPtr index of right side
     * @return returns pivot
     */
    private int partition(Character[] aux, int leftPtr, int rightPtr)
    {
        Character pivot = aux[rightPtr];
        int i = (leftPtr - 1);

        for (int j = leftPtr; j <= rightPtr - 1; j++)
        {
            if (originalMap.getMap().get(aux[j]).getCount() <= originalMap.getMap().get(pivot).getCount())
            {
                i++;
                swap(aux, i, j);
            }
        }
        swap(aux, i + 1, rightPtr);
        return (i + 1);
    }

    /**
     * quick sort algorithm
     * @param leftPtr Starting index
     * @param rightPtr Ending index
     */
    public void quickSort(Character[] aux, int leftPtr, int rightPtr)
    {
        if (leftPtr < rightPtr)
        {
            int pivot = partition(aux, leftPtr, rightPtr);

            quickSort(aux, leftPtr, pivot - 1);
            quickSort(aux, pivot + 1, rightPtr);
        }
    }

    /**
     * sort aux and fill sortedMap with sorted aux elements
     */
    public void sort() {
        long startTime = System.nanoTime();

        quickSort(aux, 0, aux.length-1);

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

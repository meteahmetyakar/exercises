package testing;

import algorithms.*;

import hashing.myMap;

/**
 * test operations for test to HW6.Hashing.info, HW6.Hashing.myMap and HW6.mergeSort classes
 */
public class Main {
    public static void main(String[] args)
    {
        String[] tst = new String[]{"Buzzing bees buzz."};
        String[] best = new String[]{"a bb ccc dddd eeeee ffffff ggggggg hhhhhhhh iiiiiiiii jjjjjjjjjj kkkkkkkkkkk llllllllllll mmmmmmmmmmmmm nnnnnnnnnnnnnn ooooooooooooooo pppppppppppppppp qqqqqqqqqqqqqqqqq rrrrrrrrrrrrrrrrrr sssssssssssssssssss tttttttttttttttttttt uuuuuuuuuuuuuuuuuuuuu vvvvvvvvvvvvvvvvvvvvvv wwwwwwwwwwwwwwwwwwwwwww xxxxxxxxxxxxxxxxxxxxxxxx yyyyyyyyyyyyyyyyyyyyyyyyy zzzzzzzzzzzzzzzzzzzzzzzzzz"};
        String[] worst = new String[]{"zzzzzzzzzzzzzzzzzzzzzzzzzz yyyyyyyyyyyyyyyyyyyyyyyyy xxxxxxxxxxxxxxxxxxxxxxxx wwwwwwwwwwwwwwwwwwwwwww vvvvvvvvvvvvvvvvvvvvvv uuuuuuuuuuuuuuuuuuuuu tttttttttttttttttttt sssssssssssssssssss rrrrrrrrrrrrrrrrrr qqqqqqqqqqqqqqqqq pppppppppppppppp ooooooooooooooo nnnnnnnnnnnnnn mmmmmmmmmmmmm llllllllllll kkkkkkkkkkk jjjjjjjjjj iiiiiiiii hhhhhhhh ggggggg ffffff eeeee dddd ccc bb a"};
        String[] average = new String[]{
                "zzzzzzzzzzzzzzzzzzzzzzzzzz yyyyyyyyyyyyyyyyyyyyyyyyy xxxxxxxxxxxxxxxxxxxxxxxx wwwwwwwwwwwwwwwwwwwwwww vvvvvvvvvvvvvvvvvvvvvv uuuuuuuuuuuuuuuuuuuuu tttttttttttttttttttt sssssssssssssssssss rrrrrrrrrrrrrrrrrr qqqqqqqqqqqqqqqqq pppppppppppppppp ooooooooooooooo nnnnnnnnnnnnnn mmmmmmmmmmmmm llllllllllll kkkkkkkkkkk jjjjjjjjjj iiiiiiiii hhhhhhhh ggggggg ffffff eeeee dddd ccc bb a",
                "a zzzzzzzzzzzzzzzzzzzzzzzzzz yyyyyyyyyyyyyyyyyyyyyyyyy xxxxxxxxxxxxxxxxxxxxxxxx wwwwwwwwwwwwwwwwwwwwwww vvvvvvvvvvvvvvvvvvvvvv uuuuuuuuuuuuuuuuuuuuu tttttttttttttttttttt sssssssssssssssssss rrrrrrrrrrrrrrrrrr qqqqqqqqqqqqqqqqq pppppppppppppppp ooooooooooooooo nnnnnnnnnnnnnn mmmmmmmmmmmmm llllllllllll kkkkkkkkkkk jjjjjjjjjj iiiiiiiii hhhhhhhh ggggggg ffffff eeeee dddd ccc bb",
                "a bb zzzzzzzzzzzzzzzzzzzzzzzzzz yyyyyyyyyyyyyyyyyyyyyyyyy xxxxxxxxxxxxxxxxxxxxxxxx wwwwwwwwwwwwwwwwwwwwwww vvvvvvvvvvvvvvvvvvvvvv uuuuuuuuuuuuuuuuuuuuu tttttttttttttttttttt sssssssssssssssssss rrrrrrrrrrrrrrrrrr qqqqqqqqqqqqqqqqq pppppppppppppppp ooooooooooooooo nnnnnnnnnnnnnn mmmmmmmmmmmmm llllllllllll kkkkkkkkkkk jjjjjjjjjj iiiiiiiii hhhhhhhh ggggggg ffffff eeeee dddd ccc",
                "a bb ccc zzzzzzzzzzzzzzzzzzzzzzzzzz yyyyyyyyyyyyyyyyyyyyyyyyy xxxxxxxxxxxxxxxxxxxxxxxx wwwwwwwwwwwwwwwwwwwwwww vvvvvvvvvvvvvvvvvvvvvv uuuuuuuuuuuuuuuuuuuuu tttttttttttttttttttt sssssssssssssssssss rrrrrrrrrrrrrrrrrr qqqqqqqqqqqqqqqqq pppppppppppppppp ooooooooooooooo nnnnnnnnnnnnnn mmmmmmmmmmmmm llllllllllll kkkkkkkkkkk jjjjjjjjjj iiiiiiiii hhhhhhhh ggggggg ffffff eeeee dddd",
                "a bb ccc dddd zzzzzzzzzzzzzzzzzzzzzzzzzz yyyyyyyyyyyyyyyyyyyyyyyyy xxxxxxxxxxxxxxxxxxxxxxxx wwwwwwwwwwwwwwwwwwwwwww vvvvvvvvvvvvvvvvvvvvvv uuuuuuuuuuuuuuuuuuuuu tttttttttttttttttttt sssssssssssssssssss rrrrrrrrrrrrrrrrrr qqqqqqqqqqqqqqqqq pppppppppppppppp ooooooooooooooo nnnnnnnnnnnnnn mmmmmmmmmmmmm llllllllllll kkkkkkkkkkk jjjjjjjjjj iiiiiiiii hhhhhhhh ggggggg ffffff eeeee",
                "a bb ccc dddd eeeee zzzzzzzzzzzzzzzzzzzzzzzzzz yyyyyyyyyyyyyyyyyyyyyyyyy xxxxxxxxxxxxxxxxxxxxxxxx wwwwwwwwwwwwwwwwwwwwwww vvvvvvvvvvvvvvvvvvvvvv uuuuuuuuuuuuuuuuuuuuu tttttttttttttttttttt sssssssssssssssssss rrrrrrrrrrrrrrrrrr qqqqqqqqqqqqqqqqq pppppppppppppppp ooooooooooooooo nnnnnnnnnnnnnn mmmmmmmmmmmmm llllllllllll kkkkkkkkkkk jjjjjjjjjj iiiiiiiii hhhhhhhh ggggggg ffffff",
                "a bb ccc dddd eeeee ffffff zzzzzzzzzzzzzzzzzzzzzzzzzz yyyyyyyyyyyyyyyyyyyyyyyyy xxxxxxxxxxxxxxxxxxxxxxxx wwwwwwwwwwwwwwwwwwwwwww vvvvvvvvvvvvvvvvvvvvvv uuuuuuuuuuuuuuuuuuuuu tttttttttttttttttttt sssssssssssssssssss rrrrrrrrrrrrrrrrrr qqqqqqqqqqqqqqqqq pppppppppppppppp ooooooooooooooo nnnnnnnnnnnnnn mmmmmmmmmmmmm llllllllllll kkkkkkkkkkk jjjjjjjjjj iiiiiiiii hhhhhhhh ggggggg",
                "a bb ccc dddd eeeee ffffff ggggggg zzzzzzzzzzzzzzzzzzzzzzzzzz yyyyyyyyyyyyyyyyyyyyyyyyy xxxxxxxxxxxxxxxxxxxxxxxx wwwwwwwwwwwwwwwwwwwwwww vvvvvvvvvvvvvvvvvvvvvv uuuuuuuuuuuuuuuuuuuuu tttttttttttttttttttt sssssssssssssssssss rrrrrrrrrrrrrrrrrr qqqqqqqqqqqqqqqqq pppppppppppppppp ooooooooooooooo nnnnnnnnnnnnnn mmmmmmmmmmmmm llllllllllll kkkkkkkkkkk jjjjjjjjjj iiiiiiiii hhhhhhhh",
                "a bb ccc dddd eeeee ffffff ggggggg hhhhhhhh zzzzzzzzzzzzzzzzzzzzzzzzzz yyyyyyyyyyyyyyyyyyyyyyyyy xxxxxxxxxxxxxxxxxxxxxxxx wwwwwwwwwwwwwwwwwwwwwww vvvvvvvvvvvvvvvvvvvvvv uuuuuuuuuuuuuuuuuuuuu tttttttttttttttttttt sssssssssssssssssss rrrrrrrrrrrrrrrrrr qqqqqqqqqqqqqqqqq pppppppppppppppp ooooooooooooooo nnnnnnnnnnnnnn mmmmmmmmmmmmm llllllllllll kkkkkkkkkkk jjjjjjjjjj iiiiiiiii",
                "a bb ccc dddd eeeee ffffff ggggggg hhhhhhhh iiiiiiiii zzzzzzzzzzzzzzzzzzzzzzzzzz yyyyyyyyyyyyyyyyyyyyyyyyy xxxxxxxxxxxxxxxxxxxxxxxx wwwwwwwwwwwwwwwwwwwwwww vvvvvvvvvvvvvvvvvvvvvv uuuuuuuuuuuuuuuuuuuuu tttttttttttttttttttt sssssssssssssssssss rrrrrrrrrrrrrrrrrr qqqqqqqqqqqqqqqqq pppppppppppppppp ooooooooooooooo nnnnnnnnnnnnnn mmmmmmmmmmmmm llllllllllll kkkkkkkkkkk jjjjjjjjjj",
                "a bb ccc dddd eeeee ffffff ggggggg hhhhhhhh iiiiiiiii jjjjjjjjjj zzzzzzzzzzzzzzzzzzzzzzzzzz yyyyyyyyyyyyyyyyyyyyyyyyy xxxxxxxxxxxxxxxxxxxxxxxx wwwwwwwwwwwwwwwwwwwwwww vvvvvvvvvvvvvvvvvvvvvv uuuuuuuuuuuuuuuuuuuuu tttttttttttttttttttt sssssssssssssssssss rrrrrrrrrrrrrrrrrr qqqqqqqqqqqqqqqqq pppppppppppppppp ooooooooooooooo nnnnnnnnnnnnnn mmmmmmmmmmmmm llllllllllll kkkkkkkkkkk",
                "a bb ccc dddd eeeee ffffff ggggggg hhhhhhhh iiiiiiiii jjjjjjjjjj kkkkkkkkkkk zzzzzzzzzzzzzzzzzzzzzzzzzz yyyyyyyyyyyyyyyyyyyyyyyyy xxxxxxxxxxxxxxxxxxxxxxxx wwwwwwwwwwwwwwwwwwwwwww vvvvvvvvvvvvvvvvvvvvvv uuuuuuuuuuuuuuuuuuuuu tttttttttttttttttttt sssssssssssssssssss rrrrrrrrrrrrrrrrrr qqqqqqqqqqqqqqqqq pppppppppppppppp ooooooooooooooo nnnnnnnnnnnnnn mmmmmmmmmmmmm llllllllllll",
                "a bb ccc dddd eeeee ffffff ggggggg hhhhhhhh iiiiiiiii jjjjjjjjjj kkkkkkkkkkk llllllllllll zzzzzzzzzzzzzzzzzzzzzzzzzz yyyyyyyyyyyyyyyyyyyyyyyyy xxxxxxxxxxxxxxxxxxxxxxxx wwwwwwwwwwwwwwwwwwwwwww vvvvvvvvvvvvvvvvvvvvvv uuuuuuuuuuuuuuuuuuuuu tttttttttttttttttttt sssssssssssssssssss rrrrrrrrrrrrrrrrrr qqqqqqqqqqqqqqqqq pppppppppppppppp ooooooooooooooo nnnnnnnnnnnnnn mmmmmmmmmmmmm",
                "a bb ccc dddd eeeee ffffff ggggggg hhhhhhhh iiiiiiiii jjjjjjjjjj kkkkkkkkkkk llllllllllll mmmmmmmmmmmmm zzzzzzzzzzzzzzzzzzzzzzzzzz yyyyyyyyyyyyyyyyyyyyyyyyy xxxxxxxxxxxxxxxxxxxxxxxx wwwwwwwwwwwwwwwwwwwwwww vvvvvvvvvvvvvvvvvvvvvv uuuuuuuuuuuuuuuuuuuuu tttttttttttttttttttt sssssssssssssssssss rrrrrrrrrrrrrrrrrr qqqqqqqqqqqqqqqqq pppppppppppppppp ooooooooooooooo nnnnnnnnnnnnnn",
                "a bb ccc dddd eeeee ffffff ggggggg hhhhhhhh iiiiiiiii jjjjjjjjjj kkkkkkkkkkk llllllllllll mmmmmmmmmmmmm nnnnnnnnnnnnnn zzzzzzzzzzzzzzzzzzzzzzzzzz yyyyyyyyyyyyyyyyyyyyyyyyy xxxxxxxxxxxxxxxxxxxxxxxx wwwwwwwwwwwwwwwwwwwwwww vvvvvvvvvvvvvvvvvvvvvv uuuuuuuuuuuuuuuuuuuuu tttttttttttttttttttt sssssssssssssssssss rrrrrrrrrrrrrrrrrr qqqqqqqqqqqqqqqqq pppppppppppppppp ooooooooooooooo",
                "a bb ccc dddd eeeee ffffff ggggggg hhhhhhhh iiiiiiiii jjjjjjjjjj kkkkkkkkkkk llllllllllll mmmmmmmmmmmmm nnnnnnnnnnnnnn ooooooooooooooo zzzzzzzzzzzzzzzzzzzzzzzzzz yyyyyyyyyyyyyyyyyyyyyyyyy xxxxxxxxxxxxxxxxxxxxxxxx wwwwwwwwwwwwwwwwwwwwwww vvvvvvvvvvvvvvvvvvvvvv uuuuuuuuuuuuuuuuuuuuu tttttttttttttttttttt sssssssssssssssssss rrrrrrrrrrrrrrrrrr qqqqqqqqqqqqqqqqq pppppppppppppppp",
                "a bb ccc dddd eeeee ffffff ggggggg hhhhhhhh iiiiiiiii jjjjjjjjjj kkkkkkkkkkk llllllllllll mmmmmmmmmmmmm nnnnnnnnnnnnnn ooooooooooooooo pppppppppppppppp zzzzzzzzzzzzzzzzzzzzzzzzzz yyyyyyyyyyyyyyyyyyyyyyyyy xxxxxxxxxxxxxxxxxxxxxxxx wwwwwwwwwwwwwwwwwwwwwww vvvvvvvvvvvvvvvvvvvvvv uuuuuuuuuuuuuuuuuuuuu tttttttttttttttttttt sssssssssssssssssss rrrrrrrrrrrrrrrrrr qqqqqqqqqqqqqqqqq",
                "a bb ccc dddd eeeee ffffff ggggggg hhhhhhhh iiiiiiiii jjjjjjjjjj kkkkkkkkkkk llllllllllll mmmmmmmmmmmmm nnnnnnnnnnnnnn ooooooooooooooo pppppppppppppppp qqqqqqqqqqqqqqqqq zzzzzzzzzzzzzzzzzzzzzzzzzz yyyyyyyyyyyyyyyyyyyyyyyyy xxxxxxxxxxxxxxxxxxxxxxxx wwwwwwwwwwwwwwwwwwwwwww vvvvvvvvvvvvvvvvvvvvvv uuuuuuuuuuuuuuuuuuuuu tttttttttttttttttttt sssssssssssssssssss rrrrrrrrrrrrrrrrrr",
                "a bb ccc dddd eeeee ffffff ggggggg hhhhhhhh iiiiiiiii jjjjjjjjjj kkkkkkkkkkk llllllllllll mmmmmmmmmmmmm nnnnnnnnnnnnnn ooooooooooooooo pppppppppppppppp qqqqqqqqqqqqqqqqq rrrrrrrrrrrrrrrrrr zzzzzzzzzzzzzzzzzzzzzzzzzz yyyyyyyyyyyyyyyyyyyyyyyyy xxxxxxxxxxxxxxxxxxxxxxxx wwwwwwwwwwwwwwwwwwwwwww vvvvvvvvvvvvvvvvvvvvvv uuuuuuuuuuuuuuuuuuuuu tttttttttttttttttttt sssssssssssssssssss",
                "a bb ccc dddd eeeee ffffff ggggggg hhhhhhhh iiiiiiiii jjjjjjjjjj kkkkkkkkkkk llllllllllll mmmmmmmmmmmmm nnnnnnnnnnnnnn ooooooooooooooo pppppppppppppppp qqqqqqqqqqqqqqqqq rrrrrrrrrrrrrrrrrr sssssssssssssssssss zzzzzzzzzzzzzzzzzzzzzzzzzz yyyyyyyyyyyyyyyyyyyyyyyyy xxxxxxxxxxxxxxxxxxxxxxxx wwwwwwwwwwwwwwwwwwwwwww vvvvvvvvvvvvvvvvvvvvvv uuuuuuuuuuuuuuuuuuuuu tttttttttttttttttttt",
                "a bb ccc dddd eeeee ffffff ggggggg hhhhhhhh iiiiiiiii jjjjjjjjjj kkkkkkkkkkk llllllllllll mmmmmmmmmmmmm nnnnnnnnnnnnnn ooooooooooooooo pppppppppppppppp qqqqqqqqqqqqqqqqq rrrrrrrrrrrrrrrrrr sssssssssssssssssss tttttttttttttttttttt zzzzzzzzzzzzzzzzzzzzzzzzzz yyyyyyyyyyyyyyyyyyyyyyyyy xxxxxxxxxxxxxxxxxxxxxxxx wwwwwwwwwwwwwwwwwwwwwww vvvvvvvvvvvvvvvvvvvvvv uuuuuuuuuuuuuuuuuuuuu",
                "a bb ccc dddd eeeee ffffff ggggggg hhhhhhhh iiiiiiiii jjjjjjjjjj kkkkkkkkkkk llllllllllll mmmmmmmmmmmmm nnnnnnnnnnnnnn ooooooooooooooo pppppppppppppppp qqqqqqqqqqqqqqqqq rrrrrrrrrrrrrrrrrr sssssssssssssssssss tttttttttttttttttttt uuuuuuuuuuuuuuuuuuuuu zzzzzzzzzzzzzzzzzzzzzzzzzz yyyyyyyyyyyyyyyyyyyyyyyyy xxxxxxxxxxxxxxxxxxxxxxxx wwwwwwwwwwwwwwwwwwwwwww vvvvvvvvvvvvvvvvvvvvvv",
                "a bb ccc dddd eeeee ffffff ggggggg hhhhhhhh iiiiiiiii jjjjjjjjjj kkkkkkkkkkk llllllllllll mmmmmmmmmmmmm nnnnnnnnnnnnnn ooooooooooooooo pppppppppppppppp qqqqqqqqqqqqqqqqq rrrrrrrrrrrrrrrrrr sssssssssssssssssss tttttttttttttttttttt uuuuuuuuuuuuuuuuuuuuu vvvvvvvvvvvvvvvvvvvvvv zzzzzzzzzzzzzzzzzzzzzzzzzz yyyyyyyyyyyyyyyyyyyyyyyyy xxxxxxxxxxxxxxxxxxxxxxxx wwwwwwwwwwwwwwwwwwwwwww",
                "a bb ccc dddd eeeee ffffff ggggggg hhhhhhhh iiiiiiiii jjjjjjjjjj kkkkkkkkkkk llllllllllll mmmmmmmmmmmmm nnnnnnnnnnnnnn ooooooooooooooo pppppppppppppppp qqqqqqqqqqqqqqqqq rrrrrrrrrrrrrrrrrr sssssssssssssssssss tttttttttttttttttttt uuuuuuuuuuuuuuuuuuuuu vvvvvvvvvvvvvvvvvvvvvv wwwwwwwwwwwwwwwwwwwwwww zzzzzzzzzzzzzzzzzzzzzzzzzz yyyyyyyyyyyyyyyyyyyyyyyyy xxxxxxxxxxxxxxxxxxxxxxxx",
                "a bb ccc dddd eeeee ffffff ggggggg hhhhhhhh iiiiiiiii jjjjjjjjjj kkkkkkkkkkk llllllllllll mmmmmmmmmmmmm nnnnnnnnnnnnnn ooooooooooooooo pppppppppppppppp qqqqqqqqqqqqqqqqq rrrrrrrrrrrrrrrrrr sssssssssssssssssss tttttttttttttttttttt uuuuuuuuuuuuuuuuuuuuu vvvvvvvvvvvvvvvvvvvvvv wwwwwwwwwwwwwwwwwwwwwww xxxxxxxxxxxxxxxxxxxxxxxx zzzzzzzzzzzzzzzzzzzzzzzzzz yyyyyyyyyyyyyyyyyyyyyyyyy",
                "a bb ccc dddd eeeee ffffff ggggggg hhhhhhhh iiiiiiiii jjjjjjjjjj kkkkkkkkkkk llllllllllll mmmmmmmmmmmmm nnnnnnnnnnnnnn ooooooooooooooo pppppppppppppppp qqqqqqqqqqqqqqqqq rrrrrrrrrrrrrrrrrr sssssssssssssssssss tttttttttttttttttttt uuuuuuuuuuuuuuuuuuuuu vvvvvvvvvvvvvvvvvvvvvv wwwwwwwwwwwwwwwwwwwwwww xxxxxxxxxxxxxxxxxxxxxxxx yyyyyyyyyyyyyyyyyyyyyyyyy zzzzzzzzzzzzzzzzzzzzzzzzzz",
        };

        System.out.println("BEST");
        for(String str : best)
            testQuick(str);

        System.out.println("AVERAGE");
        for(String str : average)
            testMerge(str);

        System.out.println("WORST");
        for(String str : worst)
            testMerge(str);


    }

    /**
     * it test given string in merge sort
     * @param str string for testing
     */
    public static void testMerge(String str)
    {
        System.out.println("-------------------------------- TEST START ------------------------------------");
        myMap map = new myMap(str);

        mergeSort test = new mergeSort(map);
        test.sort();

        System.out.println("Type : Merge Sort");
        System.out.println("Original String : " + test.getOriginalMap().getOriginalStr());
        System.out.println("Preprocessed String : " + test.getOriginalMap().getPreprocessedStr());
        System.out.println();
        System.out.println();

        System.out.println("The original (unsorted) map:");
        System.out.println(test.getOriginalMap());

        System.out.println();
        System.out.println();

        System.out.println("The sorted map:");
        System.out.println(test.getSortedMap());
        System.out.println("-------------------------------- TEST END ------------------------------------");
        System.out.println();
        System.out.println();
    }

    /**
     * it test given string in selection sort
     * @param str string for testing
     */
    public static void testSelection(String str)
    {
        System.out.println("-------------------------------- TEST START ------------------------------------");
        myMap map = new myMap(str);

        SelectionSort test = new SelectionSort(map);
        test.sort();

        System.out.println("Type : Selection Sort");
        System.out.println("Original String : " + test.getOriginalMap().getOriginalStr());
        System.out.println("Preprocessed String : " + test.getOriginalMap().getPreprocessedStr());
        System.out.println();
        System.out.println();

        System.out.println("The original (unsorted) map:");
        System.out.println(test.getOriginalMap());

        System.out.println();
        System.out.println();

        System.out.println("The sorted map:");
        System.out.println(test.getSortedMap());
        System.out.println("-------------------------------- TEST END ------------------------------------");
        System.out.println();
        System.out.println();
    }

    /**
     * it test given string in insertion sort
     * @param str string for testing
     */
    public static void testInsertion(String str)
    {
        System.out.println("-------------------------------- TEST START ------------------------------------");
        myMap map = new myMap(str);

        InsertionSort test = new InsertionSort(map);
        test.sort();

        System.out.println("Type : Insertion Sort");
        System.out.println("Original String : " + test.getOriginalMap().getOriginalStr());
        System.out.println("Preprocessed String : " + test.getOriginalMap().getPreprocessedStr());
        System.out.println();
        System.out.println();

        System.out.println("The original (unsorted) map:");
        System.out.println(test.getOriginalMap());

        System.out.println();
        System.out.println();

        System.out.println("The sorted map:");
        System.out.println(test.getSortedMap());
        System.out.println("-------------------------------- TEST END ------------------------------------");
        System.out.println();
        System.out.println();
    }


    /**
     * it test given string in bubble sort
     * @param str string for testing
     */
    public static void testBubble(String str)
    {
        System.out.println("-------------------------------- TEST START ------------------------------------");
        myMap map = new myMap(str);

        BubbleSort test = new BubbleSort(map);
        test.sort();

        System.out.println("Type : Bubble Sort");
        System.out.println("Original String : " + test.getOriginalMap().getOriginalStr());
        System.out.println("Preprocessed String : " + test.getOriginalMap().getPreprocessedStr());
        System.out.println();
        System.out.println();

        System.out.println("The original (unsorted) map:");
        System.out.println(test.getOriginalMap());

        System.out.println();
        System.out.println();

        System.out.println("The sorted map:");
        System.out.println(test.getSortedMap());
        System.out.println("-------------------------------- TEST END ------------------------------------");
        System.out.println();
        System.out.println();
    }

    /**
     * it test given string in quick sort
     * @param str string for testing
     */
    public static void testQuick(String str)
    {
        System.out.println("-------------------------------- TEST START ------------------------------------");
        myMap map = new myMap(str);

        QuickSort test = new QuickSort(map);
        test.sort();

        System.out.println("Type : Quick Sort");
        System.out.println("Original String : " + test.getOriginalMap().getOriginalStr());
        System.out.println("Preprocessed String : " + test.getOriginalMap().getPreprocessedStr());
        System.out.println();
        System.out.println();

        System.out.println("The original (unsorted) map:");
        System.out.println(test.getOriginalMap());

        System.out.println();
        System.out.println();

        System.out.println("The sorted map:");
        System.out.println(test.getSortedMap());
        System.out.println("-------------------------------- TEST END ------------------------------------");
        System.out.println();
        System.out.println();
    }

}
/*********************************************************************************************************
* Author:                   Aaron Day
* Date Created:             10/25/2015
* Last Modification Date:   10/31/2015
* Assignment Number:        Lab 2
* Filename:                 main.cpp
 *********************************************************************************************************/
#include <iostream>
#include <vector>

#include "sortfunctions.h"
#include "driver.h"

using namespace std;


int main(int argc, char* argv[])
{
    //set the size of the array with a single command-line argument
    int n;
    if(argc != 2)
    {
        n = 1000;
    }
    else
    {
        n = atoi(argv[1]);
    }

    //create an array of size n with random ints
    int* rand_array = RandGen(n);

    //create an empty output file
    string fileName = "tests.txt";
    ofstream output;
    output.open(fileName.c_str());

    test_BruteForceBubbleSort(output, rand_array, n);
    test_FlaggedBubbleSort(output, rand_array, n);
    test_SelectionSort(output, rand_array, n);
    test_InsertionSort(output, rand_array, n);
    test_ShellSort(output, rand_array, n);
    test_HeapSort(output, rand_array, n);
    test_MergeSort(output, rand_array, n);
    test_QuickSort(output, rand_array, n);

    output.close();

    //ensure the random array created in the beginning is deleted
    delete [] rand_array;

    return 0;
}


    /*
    int SIZE = argc;
    int* cArray = new int[SIZE];
    vector<int> vec;
    Array<int> myArray(SIZE);
    GenNums(cArray, vec, myArray, SIZE);
    DisplayArray(cArray, SIZE);

    //C-Array

    int* bruteCarray = new int[SIZE];
    Copy(cArray, bruteCarray, SIZE);
    clock_t start = clock();
    BruteForceBubbleSort(bruteCarray, SIZE);
    clock_t duration = clock() - start;
    Output("Brute Force Bubble - C-Array", duration, bruteCarray, SIZE);
    delete [] bruteCarray;

    int* flagCarray = new int[SIZE];
    Copy(cArray, flagCarray, SIZE);
    start = clock();
    FlaggedBubbleSort(flagCarray, SIZE);
    duration = clock() - start;
    Output("Flagged Bubble - C-Array", duration, flagCarray, SIZE);
    delete [] flagCarray;

    int* selectionCarray = new int[SIZE];
    Copy(cArray, selectionCarray, SIZE);
    start = clock();
    SelectionSort(selectionCarray, SIZE);
    duration = clock() - start;
    Output("Selection - C-Array", duration, selectionCarray, SIZE);
    delete [] selectionCarray;

    int* insertionCarray = new int[SIZE];
    Copy(cArray, insertionCarray, SIZE);
    start = clock();
    InsertionSort(insertionCarray, SIZE);
    duration = clock() - start;
    Output("Insertion - C-Array", duration, insertionCarray, SIZE);
    delete [] insertionCarray;

    int* shellCarray = new int[SIZE];
    Copy(cArray, shellCarray, SIZE);
    start = clock();
    ShellSort(shellCarray, SIZE);
    duration = clock() - start;
    Output("Shell - C-Array", duration, shellCarray, SIZE);
    delete [] shellCarray;

    int* heapCarray = new int[SIZE];
    Copy(cArray, heapCarray, SIZE);
    start = clock();
    HeapSort(heapCarray, SIZE);
    duration = clock() - start;
    Output("Heap - C-Array", duration, heapCarray, SIZE);
    delete [] heapCarray;

    int* mergeCarray = new int[SIZE];
    Copy(cArray, mergeCarray, SIZE);
    start = clock();
    MergeSort(mergeCarray, SIZE);
    duration = clock() - start;
    Output("Merge - C-Array", duration, mergeCarray, SIZE);
    delete [] mergeCarray;

    int* quickCarray = new int[SIZE];
    Copy(cArray, quickCarray, SIZE);
    start = clock();
    QuickSort(quickCarray, SIZE);
    duration = clock() - start;
    Output("Quick - C-Array", duration, quickCarray, SIZE);
    delete [] quickCarray;

    //Vector

    vector<int> bruteVector;
    Copy(cArray, bruteVector, SIZE);
    start = clock();
    BruteForceBubbleSort(&bruteVector, SIZE);
    duration = clock() - start;
    Output("Brute Force Bubble - Vector", duration, &bruteVector, SIZE);

    vector<int> flagVector;
    Copy(cArray, flagVector, SIZE);
    start = clock();
    FlaggedBubbleSort(&flagVector, SIZE);
    duration = clock() - start;
    Output("Flagged Bubble - Vector", duration, &flagVector, SIZE);

    vector<int> selectionVector;
    Copy(cArray, selectionVector, SIZE);
    start = clock();
    SelectionSort(&selectionVector, SIZE);
    duration = clock() - start;
    Output("Selection - Vector", duration, &selectionVector, SIZE);

    vector<int> insertionVector;
    Copy(cArray, insertionVector, SIZE);
    start = clock();
    InsertionSort(&insertionVector, SIZE);
    duration = clock() - start;
    Output("Insertion - Vector", duration, &insertionVector, SIZE);

    vector<int> shellVector;
    Copy(cArray, shellVector, SIZE);
    start = clock();
    ShellSort(&shellVector, SIZE);
    duration = clock() - start;
    Output("Shell - Vector", duration, &shellVector, SIZE);

    vector<int> heapVector;
    Copy(cArray, heapVector, SIZE);
    start = clock();
    HeapSort(&heapVector, SIZE);
    duration = clock() - start;
    Output("Heap - Vector", duration, &heapVector, SIZE);

    vector<int> mergeVector;
    Copy(cArray, mergeVector, SIZE);
    start = clock();
    MergeSort(&mergeVector, SIZE);
    duration = clock() - start;
    Output("Merge - Vector", duration, &mergeVector, SIZE);

    vector<int> quickVector;
    Copy(cArray, quickVector, SIZE);
    start = clock();
    QuickSort(&quickVector, SIZE);
    duration = clock() - start;
    Output("Quick - Vector", duration, &quickVector, SIZE);

    //myArray

    Array<int> bruteMyArray;
    Copy(cArray, bruteMyArray, SIZE);
    start = clock();
    BruteForceBubbleSort(&bruteMyArray, SIZE);
    duration = clock() - start;
    Output("Brute Force Bubble - myArray", duration, &bruteMyArray, SIZE);

    Array<int> flagMyArray;
    Copy(cArray, flagMyArray, SIZE);
    start = clock();
    FlaggedBubbleSort(&flagMyArray, SIZE);
    duration = clock() - start;
    Output("Flagged Bubble - myArray", duration, &flagMyArray, SIZE);

    Array<int> selectionMyArray;
    Copy(cArray, selectionMyArray, SIZE);
    start = clock();
    SelectionSort(&selectionMyArray, SIZE);
    duration = clock() - start;
    Output("Selection - myArray", duration, &selectionMyArray, SIZE);

    Array<int> insertionMyArray;
    Copy(cArray, insertionMyArray, SIZE);
    start = clock();
    InsertionSort(&insertionMyArray, SIZE);
    duration = clock() - start;
    Output("Insertion - myArray", duration, &insertionMyArray, SIZE);

    Array<int> shellMyArray;
    Copy(cArray, shellMyArray, SIZE);
    start = clock();
    ShellSort(&shellMyArray, SIZE);
    duration = clock() - start;
    Output("Shell - myArray", duration, &shellMyArray, SIZE);

    Array<int> heapMyArray;
    Copy(cArray, heapMyArray, SIZE);
    start = clock();
    HeapSort(&heapMyArray, SIZE);
    duration = clock() - start;
    Output("Heap - myArray", duration, &heapMyArray, SIZE);

    Array<int> mergeMyArray;
    Copy(cArray, mergeMyArray, SIZE);
    start = clock();
    MergeSort(&mergeMyArray, SIZE);
    duration = clock() - start;
    Output("Merge - myArray", duration, &mergeMyArray, SIZE);

    Array<int> quickMyArray;
    Copy(cArray, quickMyArray, SIZE);
    start = clock();
    QuickSort(&quickMyArray, SIZE);
    duration = clock() - start;
    Output("Quick - myArray", duration, &quickMyArray, SIZE);

    DisplayArray(cArray, SIZE);
    delete [] cArray;
    */

//    return 0;
//}



/*********************************************************************************************************
* Author:                   Aaron Day
* Date Created:             10/25/2015
* Last Modification Date:   10/31/2015
* Assignment Number:        Lab 2
* Filename:                 sortfunctions.h
 *********************************************************************************************************/
#include <iomanip>
#include <ctime>
//#include <cstdlib>
#include <fstream>
//#include <vector>
#include "array.h"

#ifndef SORTFUNCTIONS
#define SORTFUNCTIONS

using namespace std;

//
//basic functions
//

int* RandGen(int size);
template<typename t_array>
void DisplayArray(t_array &arr, int arrSize);
template<typename t_array>
void OutputArrayTest(string functName, ofstream &stream, double duration, t_array &arr, int arrSize);
template<typename t_array>
void swap(t_array &arr, int index1, int index2);
template<typename t_array, typename t_element>
void swapHelper(t_array &arr, t_element, int index1, int index2);
template<typename t_array>
void copyArray(int* from, t_array &to, int arrSize);
template<typename t_array>
bool isSorted(t_array &arr, int arrSize);

//
//sorts
//

template<typename t_array>
void BruteForceBubbleSort(t_array &arr, int arrSize);
template<typename t_array>
void FlaggedBubbleSort(t_array &arr, int arrSize);
template<typename t_array>
void SelectionSort(t_array &arr, int arrSize);
template<typename t_array>
void InsertionSort(t_array &arr, int arrSize);
template<typename t_array, typename t_element>
void InsertionSortHelper(t_array &arr, t_element, int arrSize);
template<typename t_array>
void ShellSort(t_array &arr, int arrSize);
template<typename t_array>
void HeapSort(t_array &arr, int arrSize);
template<typename t_array>
void MergeSort(t_array &arr, int arrSize);
template<typename t_array>
void QuickSort(t_array &arr, int arrSize);

//
//sort helpers
//

//heap sort helpers
template<typename t_array>
void BuildMaxHeap(t_array &arr, int arrSize);
template<typename t_array>
void MaxHeapDown(t_array &arr, int parent, int arrSize);

//merge sort helpers
template<typename t_array>
void MergeSortInternal(t_array &arr, int low, int high);
template<typename t_array>
void MergeFunction(t_array &arr, int low, int mid, int high);
template<typename t_array, typename t_element>
void MergeFunctionHelper(t_array &arr, t_element, int low, int mid, int high);

//quick sort helpers
template<typename t_array>
void QuickSortInternal(t_array &arr, int low, int high);
template<typename t_array, typename t_element>
int PartitionFunction(t_array &arr, t_element, int low, int high);

int* RandGen(int size)
{
    srand((unsigned)time(0));
    int* arr = new int[size];
    for(int i = 0; i < size; ++i)
    {
        arr[i] = rand() % 100;
    }
    return arr;
}
template<typename t_array>
void DisplayArray(t_array &arr, int arrSize)
{
    for(int row = 0; row <= (arrSize - 1) / 10; ++row)
    {
        cout << "\t\t";
        for(int col = 0; col < 10 && (row * 10) + col < arrSize; ++col)
        {
            if(arr[(row * 10) + col] < 10)
            {
                cout << " ";
            }
            cout << arr[(row * 10) + col];
            if(col != 9)
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}
template<typename t_array>
void DisplayArrayTest(string functName, double duration, t_array &arr, int arrSize)
{
    double clocks = CLOCKS_PER_SEC;
    duration /= clocks;
    if(isSorted(arr,arrSize))
    {
        cout << functName << " took: " << fixed << setprecision(6) << duration << " seconds" << endl;
    }
    else
    {
        cout << functName << " failed!"<< endl;
    }
}
template<typename t_array>
void OutputArray(ofstream &stream, t_array &arr, int arrSize)
{
    for(int row = 0; row <= (arrSize - 1) / 10; ++row)
    {
        stream << "\t\t";
        for(int col = 0; col < 10 && (row * 10) + col < arrSize; ++col)
        {
            if(arr[(row * 10) + col] < 10)
            {
                stream << " ";
            }
            stream << arr[(row * 10) + col];
            if(col != 9)
            {
                stream << " ";
            }
        }
        stream << endl;
    }
}
template<typename t_array>
void OutputArrayTest(string functName, ofstream &stream, double duration, t_array &arr, int arrSize)
{
    double clocks = CLOCKS_PER_SEC;
    duration /= clocks;
    if(isSorted(arr,arrSize))
    {
        stream << '\t' << functName << " took: " << fixed << setprecision(6) << duration << " seconds" << endl;
    }
    else
    {
        stream << functName << " failed!"<< endl;
    }
}
template<typename t_array>
void swap(t_array &arr, int index1, int index2)
{
    swapHelper(arr, arr[0], index1, index2);
}
template<typename t_array, typename t_element>
void swapHelper(t_array &arr, t_element, int index1, int index2)
{
    t_element temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}
template<typename t_array>
void copyArray(int* from, t_array &to, int arrSize)
{
    for(int i = 0; i < arrSize; ++i)
    {
        to[i] = from[i];
    }
}
template<typename t_array>
bool isSorted(t_array &arr, int arrSize)
{
    for(int i = 1; i < arrSize; ++i)
    {
        if(arr[i] < arr[i - 1])
        {
            return false;
        }
    }
    return true;
}

//
//SORTS
//

template<typename t_array>
void BruteForceBubbleSort(t_array &arr, int arrSize)
{
    for(int i = 0; i < arrSize - 1; ++i)
    {
        for(int j = 0; j < arrSize - 1 - i; ++j)
        {
            if(arr[j] > arr[j + 1])
            {
                swap(arr, j, j + 1);
            }
        }
    }
}
template<typename t_array>
void FlaggedBubbleSort(t_array &arr, int arrSize)
{
    int needPass = true;
    for(int i = 0; i < arrSize && needPass; ++i)
    {
        needPass = false;
        for(int j = 0; j < arrSize - 1 - i; ++j)
        {
            if(arr[j] > arr[j + 1])
            {
                swap(arr, j, j + 1);
                needPass = true;
            }
        }
    }
}
template<typename t_array>
void SelectionSort(t_array &arr, int arrSize)
{
    int minIndex; //index of the smallest value in unsorted list

    for (int i = 0; i < arrSize - 1; ++i) //unsorted list; elements smaller than i are sorted
    {
        minIndex = i; //set minIndex to the first index of the remaining unsorted list

        //go from the next index to the end and search for smaller values
        for(int j = i + 1; j < arrSize; ++j)
        {
            //if a smaller value is found, set minIndex to the smaller values index
            if(arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        //if a smaller was found in the unsorted list
        //  swap the smallest value with the first value in the unsorted list
        if(minIndex != i)
        {
            swap(arr, minIndex, i);
        }
    }
}
template<typename t_array>
void InsertionSort(t_array &arr, int arrSize)
{
    InsertionSortHelper(arr, arr[0], arrSize);
}
template<typename t_array, typename t_element>
void InsertionSortHelper(t_array &arr, t_element, int arrSize)
{
    for(int i = 0; i < arrSize; ++i)
    {
        t_element current = arr[i];
        int j;
        for(j = i - 1; j >= 0 && arr[j] > current; --j)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = current;
    }
}
template<typename t_array>
void ShellSort(t_array &arr, int arrSize)
{
    //set initial jump size
    int jump = 1;
    while(jump < arrSize)
    {
        jump = 3 * jump + 1;
    }

    //start sorting
    while(jump > 0)
    {
        jump = jump / 3;       //reduce jump

        //first "jump" elements are starting points
        for(int i = 0; i < jump; ++i)
        {
            //start at second element in series
            for(int j = i + jump; j < arrSize; j += jump)
            {
                //k is element being inserted
                //count by jump size
                for(int k = j; k - jump >= 0 && arr[k - jump] > arr[k]; k -= jump)
                {
                    swap(arr, k, k - jump);
                }
            }
        }
    }
}
template<typename t_array>
void HeapSort(t_array &arr, int arrSize)
{
    //start by sorting the array into a heap
    //  where the parents are greater than or equal to the children
    BuildMaxHeap(arr, arrSize);
    //first element now has highest value
    //  swap the first and last elements and process the new first element
    //  down until it is larger than its children
    for(int i = 0; i < arrSize - 1; ++i)
    {
        swap(arr, 0, arrSize - 1 - i);
        MaxHeapDown(arr, 0, arrSize - 1 - i);
    }
}
template<typename t_array>
void MergeSort(t_array &arr, int arrSize)
{
    if(arrSize > 1)
    {
        MergeSortInternal(arr, 0, arrSize - 1);
    }
}
template<typename t_array>
void QuickSort(t_array &arr, int arrSize)
{
    QuickSortInternal(arr, 0, arrSize - 1);
}

//
//Heap Sort Helpers
//

template<typename t_array>
void BuildMaxHeap(t_array &arr, int arrSize)
{
    //starting from the last parent to the first
    //  ensure the parent is greater than or equal to its children
    for(int i = arrSize / 2 - 1; i >= 0; --i)
    {
        MaxHeapDown(arr, i, arrSize);
    }
}
template<typename t_array>
void MaxHeapDown(t_array &arr, int parent, int arrSize)
{
    //don't proceed if parent has no children
    if(parent <= arrSize / 2 - 1)
    {
        //get index of children
        int lChild = parent * 2 + 1;
        int rChild = parent * 2 + 2;
        int maxChild; //index of child with greatest value
        //if there is only one child then it has the greater value
        if(rChild >= arrSize)
        {
            maxChild = lChild;
        }
        //otherwise compare the child values and set maxChild to the
        //  index of the one with the greater value
        else
        {
            maxChild = arr[lChild] > arr[rChild] ? lChild : rChild;
        }
        //if the value at maxChild is greater than the value at parent
        //  swap the values and recursively call the MaxHeapDown for the maxChild
        if(arr[parent] < arr[maxChild])
        {
            swap(arr, parent, maxChild);
            MaxHeapDown(arr, maxChild, arrSize);
        }
    }
}

//
//Merge Sort Helpers
//

template<typename t_array>
void MergeSortInternal(t_array &arr, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        MergeSortInternal(arr, low, mid); //sort first half
        MergeSortInternal(arr, mid + 1, high); //sort second half
        MergeFunction(arr, low, mid, high); //merge two halves
    }
}
template<typename t_array>
void MergeFunction(t_array &arr, int low, int mid, int high)
{
    MergeFunctionHelper(arr, arr[0], low, mid, high);
}
template<typename t_array, typename t_element>
void MergeFunctionHelper(t_array &arr, t_element, int low, int mid, int high)
{
    int firstIterator = low;        //iterate from low to mid
    int secondIterator = mid + 1;   //iterate from mid + 1 to high
    t_element* temp = new t_element[high - low + 1];  //new temp array
    int tempIterator = 0;                             //temp array index

    //cycle through both halves copying the lower values into the temp array
    while(firstIterator <= mid && secondIterator <= high)
    {
        if(arr[firstIterator] < arr[secondIterator])
        {
            temp[tempIterator] = arr[firstIterator];
            ++firstIterator;
        }
        else
        {
            temp[tempIterator] = arr[secondIterator];
            ++secondIterator;
        }
        ++tempIterator;
    }
    //copy remaining values from half that did not iterate to the end
    for(int i = firstIterator; i <= mid; ++i)
    {
        temp[tempIterator] = arr[i];
        ++tempIterator;
    }
    for(int i = secondIterator; i <= high; ++i)
    {
        temp[tempIterator] = arr[i];
        ++tempIterator;
    }
    //overwrite current section of array with the temp array values
    for(int i = 0; i <= high - low; ++i)
    {
        arr[low + i] = temp[i];
    }
    //delete the temp array
    delete [] temp;
}

//
//Quick Sort Helpers
//

template<typename t_array>
void QuickSortInternal(t_array &arr, int low, int high)
{
    if (low < high)
    {
        int pivotLoc = PartitionFunction(arr, arr[0], low, high);

        QuickSortInternal(arr, low, pivotLoc - 1);  //sort everything before pivot
        QuickSortInternal(arr, pivotLoc + 1, high); //sort everything after pivot
    }
}
template<typename t_array, typename t_element>
int PartitionFunction(t_array &list, t_element, int low, int high)
{
    t_element pivot = list[low];     //Pivot value
    int small = low + 1;            //Index of smaller element
    int large = high;               //Index of larger element

    while(small < large)
    {
        //incriment the small index until it finds a value larger than the pivot
        while(small <= large && list[small] <= pivot)
        {
            ++small;
        }
        //decriment the large index until it finds a value smaller than the pivot
        while(small <= large && list[large] > pivot)
        {
            --large;
        }
        //if the small and large indexes did not pass, swap the values
        if(small < large)
        {
            swap(list, small, large);
        }
    }
    //pass over values equal to pivot if necessary
    while(low < large && pivot <= list[large])
    {
        --large;
    }
    //swap pivot with the value at the large index if necessary
    //  return the index of the pivot
    if(pivot > list[large])
    {
        list[low] = list[large];
        list[large] = pivot;
        return large;
    }
    else
    {
        return low;
    }
}

#endif // SORTFUNCTIONS


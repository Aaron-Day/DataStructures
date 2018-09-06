/*********************************************************************************************************
* Author:                   Aaron Day
* Date Created:             10/23/2015
* Last Modification Date:   10/31/2015
* Assignment Number:        Lab 2
* Filename:                 driver.h
 *********************************************************************************************************/
#include "sortfunctions.h"
#include "array.h"
#include <vector>

#ifndef DRIVER_H
#define DRIVER_H

//all test results output to text file
//  array contents may be displayed by uncommenting the text in the desired test

void test_BruteForceBubbleSort(ofstream &stream, int* mixed, int size)
{
    stream << "Brute Force Bubble Sort" << endl;

    int* c_array = new int[size];
    copyArray(mixed, c_array, size);
    clock_t start = clock();
    BruteForceBubbleSort<int*>(c_array, size);
    clock_t duration = clock() - start;
    OutputArrayTest("  c-array", stream, duration, c_array, size);
//    stream << "\t\tBefore:" << endl;
//    OutputArray(stream, mixed, size);
//    stream << "\t\tAfter:" << endl;
//    OutputArray(stream, c_array, size);
//    stream << endl;
    delete [] c_array;

    Array<int> my_array(size);
    copyArray(mixed, my_array, size);
    start = clock();
    BruteForceBubbleSort<Array<int>>(my_array, size);
    duration = clock() - start;
    OutputArrayTest(" my-array", stream, duration, my_array, size);
//    stream << "\t\tBefore:" << endl;
//    OutputArray(stream, mixed, size);
//    stream << "\t\tAfter:" << endl;
//    OutputArray(stream, my_array, size);
//    stream << endl;

    vector<int> stl_array(size);
    copyArray<vector<int>>(mixed, stl_array, size);
    start = clock();
    BruteForceBubbleSort<vector<int>>(stl_array, size);
    duration = clock() - start;
    OutputArrayTest<vector<int>>("stl-array", stream, duration, stl_array, size);
//    stream << "\t\tBefore:" << endl;
//    OutputArray(stream, mixed, size);
//    stream << "\t\tAfter:" << endl;
//    OutputArray<vector<int>>(stream, stl_array, size);
//    stream << endl;
}
void test_FlaggedBubbleSort(ofstream &stream, int* mixed, int size)
{
    stream << "Flagged Bubble Sort" << endl;

    int* c_array = new int[size];
    copyArray(mixed, c_array, size);
    clock_t start = clock();
    FlaggedBubbleSort<int*>(c_array, size);
    clock_t duration = clock() - start;
    OutputArrayTest("  c-array", stream, duration, c_array, size);
//    stream << "\t\tBefore:" << endl;
//    OutputArray(stream, mixed, size);
//    stream << "\t\tAfter:" << endl;
//    OutputArray(stream, c_array, size);
//    stream << endl;
    delete [] c_array;

    Array<int> my_array(size);
    copyArray(mixed, my_array, size);
    start = clock();
    FlaggedBubbleSort<Array<int>>(my_array, size);
    duration = clock() - start;
    OutputArrayTest(" my-array", stream, duration, my_array, size);
//    stream << "\t\tBefore:" << endl;
//    OutputArray(stream, mixed, size);
//    stream << "\t\tAfter:" << endl;
//    OutputArray(stream, my_array, size);
//    stream << endl;

    vector<int> stl_array(size);
    copyArray(mixed, stl_array, size);
    start = clock();
    FlaggedBubbleSort<vector<int>>(stl_array, size);
    duration = clock() - start;
    OutputArrayTest("stl-array", stream, duration, stl_array, size);
//    stream << "\t\tBefore:" << endl;
//    OutputArray(stream, mixed, size);
//    stream << "\t\tAfter:" << endl;
//    OutputArray(stream, stl_array, size);
//    stream << endl;
}
void test_SelectionSort(ofstream &stream, int* mixed, int size)
{
    stream << "Selection Sort" << endl;

    int* c_array = new int[size];
    copyArray(mixed, c_array, size);
    clock_t start = clock();
    SelectionSort<int*>(c_array, size);
    clock_t duration = clock() - start;
    OutputArrayTest("  c-array", stream, duration, c_array, size);
//    stream << "\t\tBefore:" << endl;
//    OutputArray(stream, mixed, size);
//    stream << "\t\tAfter:" << endl;
//    OutputArray(stream, c_array, size);
//    stream << endl;
    delete [] c_array;

    Array<int> my_array(size);
    copyArray(mixed, my_array, size);
    start = clock();
    SelectionSort<Array<int>>(my_array, size);
    duration = clock() - start;
    OutputArrayTest(" my-array", stream, duration, my_array, size);
//    stream << "\t\tBefore:" << endl;
//    OutputArray(stream, mixed, size);
//    stream << "\t\tAfter:" << endl;
//    OutputArray(stream, my_array, size);
//    stream << endl;

    vector<int> stl_array(size);
    copyArray(mixed, stl_array, size);
    start = clock();
    SelectionSort<vector<int>>(stl_array, size);
    duration = clock() - start;
    OutputArrayTest("stl-array", stream, duration, stl_array, size);
//    stream << "\t\tBefore:" << endl;
//    OutputArray(stream, mixed, size);
//    stream << "\t\tAfter:" << endl;
//    OutputArray(stream, stl_array, size);
//    stream << endl;
}
void test_InsertionSort(ofstream &stream, int* mixed, int size)
{
    stream << "Insertion Sort" << endl;

    int* c_array = new int[size];
    copyArray(mixed, c_array, size);
    clock_t start = clock();
    InsertionSort<int*>(c_array, size);
    clock_t duration = clock() - start;
    OutputArrayTest("  c-array", stream, duration, c_array, size);
//    stream << "\t\tBefore:" << endl;
//    OutputArray(stream, mixed, size);
//    stream << "\t\tAfter:" << endl;
//    OutputArray(stream, c_array, size);
//    stream << endl;
    delete [] c_array;

    Array<int> my_array(size);
    copyArray(mixed, my_array, size);
    start = clock();
    InsertionSort<Array<int>>(my_array, size);
    duration = clock() - start;
    OutputArrayTest(" my-array", stream, duration, my_array, size);
//    stream << "\t\tBefore:" << endl;
//    OutputArray(stream, mixed, size);
//    stream << "\t\tAfter:" << endl;
//    OutputArray(stream, my_array, size);
//    stream << endl;

    vector<int> stl_array(size);
    copyArray(mixed, stl_array, size);
    start = clock();
    InsertionSort<vector<int>>(stl_array, size);
    duration = clock() - start;
    OutputArrayTest("stl-array", stream, duration, stl_array, size);
//    stream << "\t\tBefore:" << endl;
//    OutputArray(stream, mixed, size);
//    stream << "\t\tAfter:" << endl;
//    OutputArray(stream, stl_array, size);
//    stream << endl;
}
void test_ShellSort(ofstream &stream, int* mixed, int size)
{
    stream << "Shell Sort" << endl;

    int* c_array = new int[size];
    copyArray(mixed, c_array, size);
    clock_t start = clock();
    ShellSort<int*>(c_array, size);
    clock_t duration = clock() - start;
    OutputArrayTest("  c-array", stream, duration, c_array, size);
//    stream << "\t\tBefore:" << endl;
//    OutputArray(stream, mixed, size);
//    stream << "\t\tAfter:" << endl;
//    OutputArray(stream, c_array, size);
//    stream << endl;
    delete [] c_array;

    Array<int> my_array(size);
    copyArray(mixed, my_array, size);
    start = clock();
    ShellSort<Array<int>>(my_array, size);
    duration = clock() - start;
    OutputArrayTest(" my-array", stream, duration, my_array, size);
//    stream << "\t\tBefore:" << endl;
//    OutputArray(stream, mixed, size);
//    stream << "\t\tAfter:" << endl;
//    OutputArray(stream, my_array, size);
//    stream << endl;

    vector<int> stl_array(size);
    copyArray(mixed, stl_array, size);
    start = clock();
    ShellSort<vector<int>>(stl_array, size);
    duration = clock() - start;
    OutputArrayTest("stl-array", stream, duration, stl_array, size);
//    stream << "\t\tBefore:" << endl;
//    OutputArray(stream, mixed, size);
//    stream << "\t\tAfter:" << endl;
//    OutputArray(stream, stl_array, size);
//    stream << endl;
}
void test_HeapSort(ofstream &stream, int* mixed, int size)
{
    stream << "Heap Sort" << endl;

    int* c_array = new int[size];
    copyArray(mixed, c_array, size);
    clock_t start = clock();
    HeapSort<int*>(c_array, size);
    clock_t duration = clock() - start;
    OutputArrayTest("  c-array", stream, duration, c_array, size);
//    stream << "\t\tBefore:" << endl;
//    OutputArray(stream, mixed, size);
//    stream << "\t\tAfter:" << endl;
//    OutputArray(stream, c_array, size);
//    stream << endl;
    delete [] c_array;

    Array<int> my_array(size);
    copyArray(mixed, my_array, size);
    start = clock();
    HeapSort<Array<int>>(my_array, size);
    duration = clock() - start;
    OutputArrayTest(" my-array", stream, duration, my_array, size);
//    stream << "\t\tBefore:" << endl;
//    OutputArray(stream, mixed, size);
//    stream << "\t\tAfter:" << endl;
//    OutputArray(stream, my_array, size);
//    stream << endl;

    vector<int> stl_array(size);
    copyArray(mixed, stl_array, size);
    start = clock();
    HeapSort<vector<int>>(stl_array, size);
    duration = clock() - start;
    OutputArrayTest("stl-array", stream, duration, stl_array, size);
//    stream << "\t\tBefore:" << endl;
//    OutputArray(stream, mixed, size);
//    stream << "\t\tAfter:" << endl;
//    OutputArray(stream, stl_array, size);
//    stream << endl;
}
void test_MergeSort(ofstream &stream, int* mixed, int size)
{
    stream << "Merge Sort" << endl;

    int* c_array = new int[size];
    copyArray(mixed, c_array, size);
    clock_t start = clock();
    MergeSort<int*>(c_array, size);
    clock_t duration = clock() - start;
    OutputArrayTest("  c-array", stream, duration, c_array, size);
//    stream << "\t\tBefore:" << endl;
//    OutputArray(stream, mixed, size);
//    stream << "\t\tAfter:" << endl;
//    OutputArray(stream, c_array, size);
//    stream << endl;
    delete [] c_array;

    Array<int> my_array(size);
    copyArray(mixed, my_array, size);
    start = clock();
    MergeSort<Array<int>>(my_array, size);
    duration = clock() - start;
    OutputArrayTest(" my-array", stream, duration, my_array, size);
//    stream << "\t\tBefore:" << endl;
//    OutputArray(stream, mixed, size);
//    stream << "\t\tAfter:" << endl;
//    OutputArray(stream, my_array, size);
//    stream << endl;

    vector<int> stl_array(size);
    copyArray(mixed, stl_array, size);
    start = clock();
    MergeSort<vector<int>>(stl_array, size);
    duration = clock() - start;
    OutputArrayTest("stl-array", stream, duration, stl_array, size);
//    stream << "\t\tBefore:" << endl;
//    OutputArray(stream, mixed, size);
//    stream << "\t\tAfter:" << endl;
//    OutputArray(stream, stl_array, size);
//    stream << endl;
}
void test_QuickSort(ofstream &stream, int* mixed, int size)
{
    stream << "Quick Sort" << endl;

    int* c_array = new int[size];
    copyArray(mixed, c_array, size);
    clock_t start = clock();
    QuickSort<int*>(c_array, size);
    clock_t duration = clock() - start;
    OutputArrayTest("  c-array", stream, duration, c_array, size);
//    stream << "\t\tBefore:" << endl;
//    OutputArray(stream, mixed, size);
//    stream << "\t\tAfter:" << endl;
//    OutputArray(stream, c_array, size);
//    stream << endl;
    delete [] c_array;

    Array<int> my_array(size);
    copyArray(mixed, my_array, size);
    start = clock();
    QuickSort<Array<int>>(my_array, size);
    duration = clock() - start;
    OutputArrayTest(" my-array", stream, duration, my_array, size);
//    stream << "\t\tBefore:" << endl;
//    OutputArray(stream, mixed, size);
//    stream << "\t\tAfter:" << endl;
//    OutputArray(stream, my_array, size);
//    stream << endl;

    vector<int> stl_array(size);
    copyArray(mixed, stl_array, size);
    start = clock();
    QuickSort<vector<int>>(stl_array, size);
    duration = clock() - start;
    OutputArrayTest("stl-array", stream, duration, stl_array, size);
//    stream << "\t\tBefore:" << endl;
//    OutputArray(stream, mixed, size);
//    stream << "\t\tAfter:" << endl;
//    OutputArray(stream, stl_array, size);
//    stream << endl;
}

#endif // DRIVER_H


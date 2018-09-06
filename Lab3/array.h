/*********************************************************************************************************
* Author:                   Aaron Day
* Date Created:             10/01/2015
* Last Modification Date:   11/01/2015
* Assignment Number:        5
* Filename:                 array.h
*
* Overview:     Array class provides a method of storing an array dynamically on the heap.
*
* Input:        Inputs are the data that needs to be stored.
*
* Output:       Subscript operators allow retrieval of data in the array at a given index
 *********************************************************************************************************/
#ifndef ARRAY_H
#define ARRAY_H

#include <cmath>

/*********************************************************************************************************
 * Class: Array
 *
 * Constructors/Destructors:
 *      Array()
 *              Default constructor, creates a new empty array
 *      Array(int length, int start_index)
 *              1/2 arg constructor, creates a new array with a given length and optional starting index
 *      Array(const Array& copy)
 *              Copy constructor, copies an existing array into a new array
 *      ~Array()
 *              Destructor, frees memory when the array is destroyed
 *
 * Accessors:
 *      int getStartIndex()const
 *              Returns the starting index of the array
 *      int getLength() const
 *              Returns the length of the array
 *      T& operator[](int index)
 *              Returns by reference an element in the array at a given index from m_start_index
 *      const T& operator[](int index) const
 *              Returns by reference a const element in the array at a given index from m_start_index
 *
 * Mutators:
 *      Array& operator=(const Array& rhs)
 *              Empties the array and turns it into a copy of another array
 *      void setStartIndex(int start_index)
 *              Adjust the starting index
 *      void setLength(int length)
 *              Adjust the length of the array
 *********************************************************************************************************/

template<typename T>
class Array
{
public:
    //constructors
    Array();
    Array(int length, int start_index = 0);
    Array(const Array& copy);
    ~Array();

    //accessors
    int getStartIndex() const;
    int getLength() const;
    T& operator[](int index);
    const T& operator[](int index) const;

    //mutators
    Array& operator=(const Array& rhs);
    void setStartIndex(int start_index);
    void setLength(int length);

private:
    T* m_array;
    int m_length;
    int m_start_index;
};

#include "array.inc"

#endif // ARRAY_H

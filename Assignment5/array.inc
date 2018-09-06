/*********************************************************************************************************
* Author:                   Aaron Day
* Date Created:             10/01/2015
* Last Modification Date:   11/01/2015
* Assignment Number:        5
* Filename:                 array.inc
 *********************************************************************************************************/
#include "array.h"
#include "exception.h"

//
//constructors
//

/*********************************************************************************************************
 * template<typename T>
 * Array<T>::Array()
 *
 *  Purpose:    Create a new empty array of 0 length
 *
 *  Entry:      No entry
 *
 *  Exit:       Created a new array of 0 length
 *********************************************************************************************************/
template<typename T>
Array<T>::Array()
    :m_length(0), m_start_index(0)
{
    m_array = new T[0];
}

/*********************************************************************************************************
 * template<typename T>
 * Array<T>::Array(int length, int start_index)
 *
 *  Purpose:    Create a new empty array of a given length with an optional starting index
 *
 *  Entry:      Length of array and optional starting index
 *
 *  Exit:       Created a new empty array with the given length
 *********************************************************************************************************/
template<typename T>
Array<T>::Array(int length, int start_index)
    :m_length(abs(length)), m_start_index(start_index)
{
    m_array = new T[m_length];
}

/*********************************************************************************************************
 * template<typename T>
 * Array<T>::Array(const Array& copy)
 *
 *  Purpose:    Create a new array with the same data as an existing array
 *
 *  Entry:      Array to copy
 *
 *  Exit:       Created a new array identical to the passed array
 *********************************************************************************************************/
template<typename T>
Array<T>::Array(const Array& copy)
    :m_length(copy.m_length), m_start_index(copy.m_start_index)
{
    m_array = new T[m_length];
    for(int i = 0; i < m_length; ++i)
    {
        m_array[i] = copy.m_array[i];
    }
}

/*********************************************************************************************************
 * template<typename T>
 * Array<T>::~Array()
 *
 *  Purpose:    Safely destruct an array
 *
 *  Entry:      No entry
 *
 *  Exit:       Frees memory allocated to store the array
 *********************************************************************************************************/
template<typename T>
Array<T>::~Array()
{
    delete [] m_array;
}

//
//accessors
//

/*********************************************************************************************************
 * template<typename T>
 * int Array<T>::getStartIndex() const
 *
 *  Purpose:    Get the starting index of the array
 *
 *  Entry:      No entry
 *
 *  Exit:       Returns the starting index of the array
 *********************************************************************************************************/
template<typename T>
int Array<T>::getStartIndex() const
{
    return m_start_index;
}
/*********************************************************************************************************
 * template<typename T>
 * int Array<T>::getLength() const
 *
 *  Purpose:    Get the length of the array
 *
 *  Entry:      No entry
 *
 *  Exit:       Returns the length of the array
 *********************************************************************************************************/
template<typename T>
int Array<T>::getLength() const
{
    return m_length;
}
/*********************************************************************************************************
 * template<typename T>
 * T& Array<T>::operator[](int index)
 *
 *  Purpose:    Retrieve the data at a given index in the array
 *
 *  Entry:      Index of data
 *
 *  Exit:       Returns by reference the data at the given index from the starting index
 *********************************************************************************************************/
template<typename T>
T& Array<T>::operator[](int index)
{
    if(index < 0)
    {
        char msg[] = "Error: lower bound";
        throw Exception(msg);
    }
    if(index >= m_length)
    {
        char msg[] = "Error: upper bound";
        throw Exception(msg);
    }
    return m_array[(index + m_start_index) % m_length];
}

//
//mutators
//

/*********************************************************************************************************
 * template<typename T>
 * Array<T>& Array<T>::operator=(const Array<T>& rhs)
 *
 *  Purpose:    Empty the array and make it an exact copy of another existing array
 *
 *  Entry:      Array to copy
 *
 *  Exit:       The array is now identical to the passed array
 *********************************************************************************************************/
template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& rhs)
{
    if(this != &rhs)
    {
        delete [] m_array;
        m_length = rhs.m_length;
        m_start_index = rhs.m_start_index;
        m_array = new T[m_length];
        for(int i = 0; i < m_length; ++i)
        {
            m_array[i] = rhs.m_array[i];
        }
    }
    return *this;
}
/*********************************************************************************************************
 * template<typename T>
 * void Array<T>::setStartIndex(int start_index)
 *
 *  Purpose:    Adjust the starting index of the array
 *
 *  Entry:      New starting index
 *
 *  Exit:       Starting index now has the given value
 *********************************************************************************************************/
template<typename T>
void Array<T>::setStartIndex(int start_index)
{
    m_start_index = start_index % m_length;
}
/*********************************************************************************************************
 * template<typename T>
 * void Array<T>::setLength(int length)
 *
 *  Purpose:    Adjust the length of the array
 *
 *  Entry:      New array length
 *
 *  Exit:       Array length now has the given value
 *********************************************************************************************************/
template<typename T>
void Array<T>::setLength(int length)
{
    T* old = m_array;
    int oldLen = m_length;
    m_array = new T[length];
    m_length = length;
    for(int i = 0; i < min(oldLen,length); ++i)
    {
        m_array[i] = old[i];
    }
    delete [] old;
}

/*
 * Assignment       :   1
 * Class            :   CST211
 *
 * Author           :   Aaron Day
 *
 * File             :   array.inc
 *
 * Description      :   Definitions for the Array template class
 */

#include "array.h"
#include "exception.h"

/**
 * @brief Array<T>::Array       Default constructor. Creates a new array of type T with a length of 0.
 */
template<typename T>
Array<T>::Array()
    :m_length(0), m_start_index(0)
{
    m_array = new T[0];
}

/**
 * @brief Array<T>::Array       2-arg constructor. Creates a new array of type T with a user defined
 *                                  length and starting index
 * @param length                Number of elements in the array
 * @param start_index           Starting index for the array
 */
template<typename T>
Array<T>::Array(int length, int start_index)
    :m_length(abs(length)), m_start_index(start_index)
{
    m_array = new T[m_length];
}

/**
 * @brief Array<T>::Array       Copy constructor. Creates a new array identical to an existing array
 *
 * @param copy                  Reference to an existing array to duplicate
 */
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

/**
 * @brief                       Destructor. Deletes heap memory associated with the array
 */
template<typename T>
Array<T>::~Array()
{
    delete [] m_array;
}

/**
 * @brief operator=             Equal operator. Deletes the current array from the left-hand-side (lhs)
 *                                  then creates a new array identical to the right-hand-side (rhs)
 * @param rhs                   Right-hand-side of the operation
 */
template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& rhs)
{
    if(this != rhs)
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
    return this;
}

/**
 * @brief operator[]            Index operator. Returns by reference the element of the array at a given index
 *
 * @param index                 Index of the element to return. Based on the starting index of the array
 */
template<typename T>
T& Array<T>::operator[](int index)
{
    if(index < m_start_index)
    {
        char* c = new char;
        *c = 'l';
        throw Exception(c);
    }
    if(index > m_start_index + m_length - 1)
    {
        char* c = new char;
        *c = 'u';
        throw Exception(c);
    }
    return m_array[index - m_start_index];
}

/**
 * @brief getStartIndex         Returns the starting index of the array
 *
 * @return                      Starting index
 */
template<typename T>
int Array<T>::getStartIndex() const
{
    return m_start_index;
}

/**
 * @brief setStartIndex         Changes the start index of the array
 *
 * @param start_index           New starting index for the array
 */
template<typename T>
void Array<T>::setStartIndex(int start_index)
{
    m_start_index = start_index;
}

/**
 * @brief getLength             Returns the number of elements the array can hold
 *
 * @return                      Array capacity
 */
template<typename T>
int Array<T>::getLength() const
{
    return m_length;
}

/**
 * @brief setLength             Creates a new array with a given length, copies as much data from the old
 *                                  array to the new array as possible, then deletes the old array.
 *
 * @param length                New length of array
 */
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

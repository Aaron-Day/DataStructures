/*********************************************************************************************************
* Author:                   Aaron Day
* Date Created:             10/07/2015
* Last Modification Date:   10/26/2015
* Assignment Number:        Lab 2
* Filename:                 array.inc
 *********************************************************************************************************/
#include "array.h"
#include "exception.h"

template<typename T>
Array<T>::Array()
    :m_length(0), m_start_index(0)
{
    m_array = new T[0];
}

template<typename T>
Array<T>::Array(int length, int start_index)
    :m_length(abs(length)), m_start_index(start_index)
{
    m_array = new T[m_length];
}

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

template<typename T>
Array<T>::~Array()
{
    delete [] m_array;
}

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

template<typename T>
int Array<T>::getStartIndex() const
{
    return m_start_index;
}

template<typename T>
void Array<T>::setStartIndex(int start_index)
{
    m_start_index = start_index;
}

template<typename T>
int Array<T>::getLength() const
{
    return m_length;
}

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

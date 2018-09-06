/*
 * Assignment       :   1
 * Class            :   CST211
 *
 * Author           :   Aaron Day
 *
 * File             :   array.h
 *
 * Description      :   Declarations for the Array template class
 */

#ifndef ARRAY_H
#define ARRAY_H

#include <cmath>

template<typename T>
class Array
{
public:
    Array();
    Array(int length, int start_index = 0);
    Array(const Array& copy);
    ~Array();

    Array& operator=(const Array& rhs);
    T& operator[](int index);
    int getStartIndex() const;
    void setStartIndex(int start_index);
    int getLength() const;
    void setLength(int length);

private:
    T* m_array;
    int m_length;
    int m_start_index;
};

#include "array.inc"

#endif // ARRAY_H

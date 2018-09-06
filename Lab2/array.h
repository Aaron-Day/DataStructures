/*********************************************************************************************************
* Author:                   Aaron Day
* Date Created:             10/07/2015
* Last Modification Date:   10/26/2015
* Assignment Number:        Lab 2
* Filename:                 array.h
 *********************************************************************************************************/

#include <cmath>

#ifndef ARRAY_H
#define ARRAY_H

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

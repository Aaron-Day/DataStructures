/*********************************************************************************************************
 * Author:                      Aaron Day
 * Date Created:                10/07/2015
 * Last Modification Date:      10/09/2015
 * Assignment Number:           2
 * Filename:                    row.h
 *
 * Overview:
 *      This program will take a 2D array and an int and create a new
 *      2D array composed only of the row from the original array at
 *      the given row index int
 * Input:
 *      The input is a 2D array of data and an int representing a row
 *      index. This program is composed of array2d and it must be
 *      included at the time this program is compiled.
 * Output:
 *      There is no output stream for this program
 *********************************************************************************************************/

#ifndef ROW_H
#define ROW_H

#include <cmath>

#include "exception.h"

template<typename T>        //forward declaration
class Array2D;

/*********************************************************************************************************
 * Class: Row
 *
 * Constructors/Destructors:
 *      Row(Array2D<T>& array, int row)
 *              Construct a row object from an existing array and row index
 *
 * Accessors:
 *      T& operator[](int column)
 *              Overloaded subscript operator so that one may return
 *              elements of a row
 *      const T& operator[](int column) const
 *              Per the assignment stipulations, this is an additional
 *              overloaded subscript operator so that one may return
 *              const elements from a row
 *********************************************************************************************************/

template<typename T>
class Row
{
public:
    //
    //Constructors/Destructors
    //

    //Construct a row object from an existing 2D array and row index
    Row(Array2D<T>& array, int row);

    //
    //Accessors
    //

    //Overloaded subscript operator to return standard elements
    T& operator[](int column);

    //Overloaded subscript operator to return const elements
    const T& operator[](int column) const;

private:
    Array2D<T>& m_array2D;      //2D array of data elements
    int m_row;                  //Row index of 2D array this row was derived from

};

#include "row.inc"

#endif // ROW_H

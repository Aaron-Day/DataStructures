/*********************************************************************************************************
 * Author:                      Aaron Day
 * Date Created:                10/07/2015
 * Last Modification Date:      10/09/2015
 * Assignment Number:           2
 * Filename:                    array2d.h
 *
 * Overview:
 *      This program stores data in a 2D array and allows the user to
 *      query specific elements of the array or return entire rows of an
 *      array as new array. To return a row, the row class must be
 *      included when compiled.
 * Input:
 *      User can create a new array of a specific size, modify the size
 *      of an existing array, or copy an existing array. Input into the
 *      array is done with the equal operator.
 * Output:
 *      There is no output stream for this program
 *********************************************************************************************************/

#ifndef ARRAY2D_H
#define ARRAY2D_H

#include <cmath>

#include "row.h"
#include "exception.h"

/*********************************************************************************************************
 * Class: Array2D
 *
 * Constructors/Destructors:
 *      Array2D()
 *              Default constructor, creates a 2D array with 1 row and column
 *      Array2D(int row, int col)
 *              1/2-arg constructor, creates a 2D array with a user defined
 *              number of rows and no columns
 *      Array2D(const Array2D &copy)
 *              Copy constructor, copies an existing array into a new array
 *      ~Array2D()
 *              Destructor, frees memory when arrays are destroyed
 *
 * Accessors:
 *      int getRow() const
 *              Returns the number of rows in the array
 *      int getColumn() const
 *              Returns the number of columns in the array
 *      Row<T> operator[](int index)
 *              Returns the entire row as an array from a given index
 *      const Row<T> operator[](int index) const
 *              Returns the entire const row as an array from a given index
 *      T& Select(int row, int column) const
 *              Returns the element at a specified row and column
 *
 * Mutators:
 *      void setRow(int rows)
 *              Changes the number of rows in the array
 *      void setColumn(int columns)
 *              Changes the number of columns in the array
 *      Array2D& operator=(const Array2D& rhs)
 *              Makes an existing array a copy of another existing array
 *********************************************************************************************************/

template<typename T>
class Array2D
{
public:
    //
    //Constructors/Destructors
    //

    //Default constructor
    Array2D();

    //1/2-arg constructor
    Array2D(int row, int col = 0);

    //Copy constructor
    Array2D(const Array2D& copy);

    //Destructor
    ~Array2D();

    //
    //Accessors
    //

    //Returns m_row
    int getRow() const;

    //Returns m_col
    int getColumn() const;

    //Returns row at row index
    Row<T> operator[](int index);

    //Returns const row at row index
    const Row<T> operator[](int index) const;

    //Returns element at row/column index
    T& Select(int row, int column) const;

    //
    //Mutators
    //

    //Modifies m_row
    void setRow(int rows);

    //Modifies m_col
    void setColumn(int columns);

    //Copies existing array to another existing array
    Array2D& operator=(const Array2D& rhs);

private:
    T** m_array;    //Pointer to 2D array of data
    int m_row;      //Number of rows in array
    int m_col;      //Number of columns in array

};

#include "array2d.inc"

#endif // ARRAY2D_H

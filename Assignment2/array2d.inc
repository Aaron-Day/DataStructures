/*********************************************************************************************************
 * Author:                      Aaron Day
 * Date Created:                10/07/2015
 * Last Modification Date:      10/09/2015
 * Assignment Number:           2
 * Filename:                    array2d.inc
 *********************************************************************************************************/

#include "array2d.h"

//
//Constructors/Destructors
//

/*********************************************************************************************************
 * template<typename T>
 * Array2D()
 *
 *  Purpose:    Default constructor, creates an empty 2D array with
 *              1 row and column
 *
 *  Entry:      Takes no arguments
 *
 *  Exit:       New object is created with 1 row and column
 *********************************************************************************************************/
template<typename T>
Array2D<T>::Array2D()
    :m_row(1), m_col(1)                       //Initialize the row and column size with 1
{
    m_array = new T*[m_row];                  //Create a new array and assign to current
    for(int i = 0; i < m_col; ++i)
    {
        m_array[i] = new T[m_col];
    }
}

/*********************************************************************************************************
 * template<typename T>
 * Array2D(int row, int col)
 *
 *  Purpose:    1/2-arg constructor, creates an empty 2D array with
 *              a user defined number of rows and columns. Columns
 *              is defaulted to 0.
 *
 *  Entry:      Desired number of rows and columns for the new array
 *
 *  Exit:       New 2D array with user defined number of rows and
 *              columns
 *********************************************************************************************************/
template<typename T>
Array2D<T>::Array2D(int row, int col)
    :m_row(row), m_col(col)                   //Initialize the row and column size
{
    m_array = new T*[m_row];                  //Create a new array and assign to current
    for(int i = 0; i < m_col; ++i)
    {
        m_array[i] = new T[m_col];
    }
}

/*********************************************************************************************************
 * template<typename T>
 * Array2D(const Array2D& copy)
 *
 *  Purpose:    Copy constructor, creates a new 2D array identical to
 *              an existing array
 *
 *  Entry:      2D array to copy
 *
 *  Exit:       New 2D array identical to an existing array
 *********************************************************************************************************/
template<typename T>
Array2D<T>::Array2D(const Array2D& copy)
    :m_row(copy.m_row), m_col(copy.m_col)                   //Initialize the row and column size
{
    m_array = new T*[m_row];                                //Create a new array and assign to current
    for(int i = 0; i < m_col; ++i)
    {
        m_array[i] = new T[m_col];
    }
    for(int r = 0; r < m_row; ++r)                          //Loop through rows
    {
        for(int c = 0; c < m_col; ++c)                      //Loop through columns
        {
            *(m_array[r] + c) = *(copy.m_array[r] + c);     //Copy elements
        }
    }
}

template<typename T>
Array2D<T>::~Array2D()
{
    for(int i = 0; i < m_row; ++i)
    {
        delete [] m_array[i];
    }
    delete [] m_array;
}

//
//Accessors
//

/*********************************************************************************************************
 * template<typename T>
 * int getRow() const
 *
 *  Purpose:    This function returns the number of rows in the array
 *
 *  Entry:      Function must be connected to an Array2D object
 *
 *  Exit:       Returns m_row
 *********************************************************************************************************/
template<typename T>
int Array2D<T>::getRow() const
{
    return m_row;
}

/*********************************************************************************************************
 * template<typename T>
 * int getColumn() const
 *
 *  Purpose:    This function returns the number of columns in the array
 *
 *  Entry:      Function must be connected to an Array2D object
 *
 *  Exit:       Returns m_col
 *********************************************************************************************************/
template<typename T>
int Array2D<T>::getColumn() const
{
    return m_col;
}

/*********************************************************************************************************
 * template<typename T>
 * Row<T> operator[](int index)
 *
 *  Purpose:    This function returns the row object for a given row
 *              index of the array
 *
 *  Entry:      Requires a valid row index
 *
 *  Exit:       Returns a row object for the given row index
 *********************************************************************************************************/
template<typename T>
Row<T> Array2D<T>::operator[](int index)
{
    if(index < 0)                               //Check if the index is below the lower bound index of the array
    {
        char error[] = "Index low error";       //Message if out of bounds
        throw Exception(error);                 //Throw exception
    }
    else if(index >= m_row)                     //Check if the index is above the upper bound index of the array
    {
        char error[] = "Index high error";      //Message if out of bounds
        throw Exception(error);                 //Throw exception
    }
    else                                        //If the index is not out of bounds, continue
    {
        Row<T>* row = new Row<T>(this, index);  //Create a new row object passing this array and the index as parameters
        return *row;                            //Return the row
    }
}

/*********************************************************************************************************
 * template<typename T>
 * const Row<T> operator[](int index) const
 *
 *  Purpose:    This function returns the const row object for a given
 *              row index of the array
 *
 *  Entry:      Requires a valid row index
 *
 *  Exit:       Returns a const row object for the given row index
 *
 *  Exception:  Throws an exception if the index is invalid
 *********************************************************************************************************/
template<typename T>
const Row<T> Array2D<T>::operator[](int index) const
{
    if(index < 0)                               //Check if the index is below the lower bound index of the array
    {
        char error[] = "Index low error";       //Message if out of bounds
        throw Exception(error);                 //Throw exception
    }
    else if(index >= m_row)                     //Check if the index is above the upper bound index of the array
    {
        char error[] = "Index high error";      //Message if out of bounds
        throw Exception(error);                 //Throw exception
    }
    else                                        //If the index is not out of bounds, continue
    {
        Row<T>* row = new Row<T>(this, index);  //Create a new row object passing this array and the index as parameters
        return *row;                            //Return the row
    }
}

/*********************************************************************************************************
 * template<typename T>
 * T& Select(int row, int column) const
 *
 *  Purpose:    This function returns the element at a given row and
 *              column index
 *
 *  Entry:      A valid row and column index is required
 *
 *  Exit:       Returns element at given row and column index
 *
 *  Exception:  Throws an exception if the row or column index is
 *              invalid
 *********************************************************************************************************/
template<typename T>
T& Array2D<T>::Select(int row, int column) const
{
    if(row < 0)                                 //Check if row is below the index of the 2D array
    {
        char error[] = "Row low error";         //Message if out of bounds
        throw Exception(error);                 //Throw exception
    }
    if(row >= m_row)                            //Check if row is above the index of the 2D array
    {
        char error[] = "Row high error";        //Message if out of bounds
        throw Exception(error);                 //Throw exception
    }
    if(column < 0)                              //Check if column is below the index of the 2D array
    {
        char error[] = "Column low error";      //Message if out of bounds
        throw Exception(error);                 //Throw exception
    }
    if(column >= m_col)                         //Check if column is above the index of the 2D array
    {
        char error[] = "Column high error";     //Message if out of bounds
        throw Exception(error);                 //Throw exception
    }
    return *(m_array[row] + column);            //If not out of bounds, return element
}

//
//Mutators
//

/*********************************************************************************************************
 * template<typename T>
 * void setRow(int rows)
 *
 *  Purpose:    This function modifies the number of rows in the array
 *
 *  Entry:      Desired number of rows. This function must be connected
 *              to an Array 2D object.
 *
 *  Exit:       Array now has the specified number of rows
 *********************************************************************************************************/
template<typename T>
void Array2D<T>::setRow(int rows)
{
    if(rows != m_row)                                       //If current number of rows is different, continue
    {
        T** oldArray = m_array;                             //Current array becomes old array
        m_array = new T*[rows];                             //Create a new array and assign to current
        for(int i = 0; i < m_col; ++i)
        {
            m_array[i] = new T[m_col];
        }
        int copyRows = rows > m_row ? m_row : rows;         //Number of rows that will be copied
        m_row = rows;
        for(int r = 0; r < copyRows; ++r)                   //Loop through rows
        {
            for(int c = 0; c < m_col; ++c)                  //Loop through columns
            {
                *(m_array[r] + c) = *(oldArray[r] + c);     //Copy elements
            }
            delete [] oldArray[r];
        }
        delete [] oldArray;                                 //Delete the old array
    }
}

/*********************************************************************************************************
 * template<typename T>
 * void setColumn(int columns);
 *
 *  Purpose:    This function dynamically modifies the number of
 *              columns in the array
 *
 *  Entry:      Desired number of columns. This function must be
 *              connected to an Array2D object.
 *
 *  Exit:       Array now has the specified number of columns
 *********************************************************************************************************/
template<typename T>
void Array2D<T>::setColumn(int columns)
{
    if(columns != m_col)                                    //If current number of columns is different, continue
    {
        T** oldArray = m_array;                             //Current array becomes old array
        m_array = new T*[m_row];                            //Create a new array (dynamically) and assign to current
        for(int i = 0; i < columns; ++i)
        {
            m_array[i] = new T[columns];
        }
        int copyColumns = columns > m_col ? m_col : columns;//Number ol columns that will be copied
        m_col = columns;
        for(int r = 0; r < m_row; ++r)                      //Loop through rows
        {
            for(int c = 0; c < copyColumns; ++c)            //Loop through columns
            {
                *(m_array[r] + c) = *(oldArray[r] + c);     //Copy elements
            }
            delete [] oldArray[r];
        }
        delete [] oldArray;                                 //Delete the old array
    }
}

/*********************************************************************************************************
 * template<typename T>
 * Array2D<T>& operator=(const Array2D<T>& rhs)
 *
 *  Purpose:    Overloaded equal operator so that an Array2D object
 *              can easily be set equal to that of an existing Array2D
 *              object using a deep copy
 *
 *  Entry:      This function takes an Array2D object on both sides
 *              of the binary operator
 *
 *  Exit:       Array is now a deep copy of anothr existing array
 *********************************************************************************************************/
template<typename T>
Array2D<T>& Array2D<T>::operator=(const Array2D<T>& rhs)
{
    if(this != &rhs)                                    //If these are not the same objects, continue
    {
        for(int i = 0; i < m_row; ++i)                  //Delete the current array
        {
            delete [] m_array[i];
        }
        delete [] m_array;
        m_row = rhs.m_row;                              //Set the number of rows equal to the rhs
        m_col = rhs.m_col;                              //Set the number of columns equal to the rhs
        m_array = new T*[m_row];                        //Create a new array and assign to current
        for(int i = 0; i < m_col; ++i)
        {
            m_array[i] = new T[m_col];
        }
        for(int r = 0; r < m_row; ++r)                  //Loop through rows
        {
            for(int c = 0; c < m_col; ++c)              //Loop through columns
            {
                *(m_array[r] + c) = rhs.Select(r, c);   //Copy elements
            }
        }
    }
    return *this;
}

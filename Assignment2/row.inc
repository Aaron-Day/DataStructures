/*********************************************************************************************************
 * Author:                      Aaron Day
 * Date Created:                10/07/2015
 * Last Modification Date:      10/09/2015
 * Assignment Number:           2
 * Filename:                    row.inc
 *********************************************************************************************************/

#include "row.h"

/*********************************************************************************************************
 * template<typename T>
 * Row(Array2D<T>& array, int row)
 *
 *  Purpose:    2-arg constructor that creates a row object from an
 *              existing 2D array and row index
 *
 *  Entry:      2D array of data and a row index
 *
 *  Exit:       Row object is created with the data from the row in
 *              the 2D array.
 *********************************************************************************************************/
template<typename T>
Row<T>::Row(Array2D<T>& array, int row)
    :m_array2D(array), m_row(row)   //Initialize array and row number
{

}

/*********************************************************************************************************
 * template<typename T>
 * T& operator[](int column)
 *
 *  Purpose:    This function returns the element at a given column index
 *
 *  Entry:      Column index for the element needed
 *
 *  Exit:       Returns the element at the given index
 *
 *  Exception:  Throws an exception if the index is out of bounds
 *********************************************************************************************************/
template<typename T>
T& Row<T>::operator[](int column)
{
    if(column < 0)                          //Check if the column index is out of bounds
    {
        char error[] = "Column low error";  //Message if column is out of bounds
        throw Exception(error);             //Throw exception
    }
    if(column >= m_array2D.getColumn())     //Check if the column index is out of bounds
    {
        char error[] = "Column high error"; //Message if column is out of bounds
        throw Exception(error);             //Throw exception
    }
    return m_array2D.Select(m_row, column); //Return the element at a given column index
}

/*********************************************************************************************************
 * template<typename T>
 * const T& operator[](int column) const
 *
 *  Purpose:    This function returns the element at a given column index
 *
 *  Entry:      Column index for the element needed
 *
 *  Exit:       Returns the element at the given index
 *
 *  Exception:  Throws an exception if the index is out of bounds
 *********************************************************************************************************/
template<typename T>
const T& Row<T>::operator[](int column) const
{
    if(column < 0)                          //Check if the column index is out of bounds
    {
        char error[] = "Column low error";  //Message if column is out of bounds
        throw Exception(error);             //Throw exception
    }
    if(column >= m_array2D.getColumn())     //Check if the column index is out of bounds
    {
        char error[] = "Column high error"; //Message if column is out of bounds
        throw Exception(error);             //Throw exception
    }
    return m_array2D.Select(m_row, column); //Return the const element at a given column index
}


/*********************************************************************************************************
 * Author:                      Aaron Day
 * Date Created:                10/17/2015
 * Last Modification Date:      10/19/2015
 * Assignment Number:           Lab 1
 * Filename:                    cell.h
 *
 * Overview:
 *      This program manipulates the cells of a minesweeber board.
 * Input:
 *      There is no input for this class
 * Output:
 *      There is no output stream for this class
 *********************************************************************************************************/

#ifndef CELL_H
#define CELL_H

#include "array2d.h"
#include "row.h"
#include "exception.h"
#include "cell.h"

/*********************************************************************************************************
 * Class: Cell
 *
 * Constructors/Destructors:
 *      Cell()
 *              Default constructor, creates a cell that is covered an unmarked with no uncovered value
 *
 * Accessors:
 *      char getUncovered() const
 *              Returns the uncovered value of the cell
 *      bool isCovered() const
 *              Returns true if the cell is covered
 *      bool isMarked() const
 *              Returns true if the cell is marked
 *      bool isBomb() const
 *              Returns true if the uncovered value of the cell is X
 *
 * Mutators:
 *      void markCell()
 *              Toggles the value of m_marked
 *      void setUncovered(char value)
 *              Sets the uncovered value of the cell
 *      void selectCell()
 *              Uncovers/Unmarks the cell
 *********************************************************************************************************/

class Cell
{
public:
    //constructor
    Cell();

    //accessors
    char getUncovered() const;
    bool isCovered() const;
    bool isMarked() const;
    bool isBomb() const;

    //mutators
    void markCell();
    void setUncovered(char value);
    void selectCell();

private:
    bool m_covered;     //Cell is covered
    bool m_marked;      //Cell is marked
    char m_uncovered;   //Uncovered value
};

#endif // CELL_H

/*********************************************************************************************************
 * Author:                      Aaron Day
 * Date Created:                10/17/2015
 * Last Modification Date:      10/19/2015
 * Assignment Number:           Lab 1
 * Filename:                    cell.cpp
 *********************************************************************************************************/

#include "cell.h"

using namespace std;

//
//constructor
//

Cell::Cell()
    :m_covered(true), m_marked(false), m_uncovered(' ')
{
}

//
//accessors
//

/*********************************************************************************************************
 * char Cell::getUncovered() const
 *
 *  Purpose:    Get the uncovered cell value
 *
 *  Entry:      No entry
 *
 *  Exit:       Returns the uncovered cell value
 *********************************************************************************************************/
char Cell::getUncovered() const
{
    return m_uncovered;
}
/*********************************************************************************************************
 * bool Cell::isCovered() const
 *
 *  Purpose:    Check if the cell is covered
 *
 *  Entry:      No entry
 *
 *  Exit:       Returns true if the cell is covered
 *********************************************************************************************************/
bool Cell::isCovered() const
{
    return m_covered;
}
/*********************************************************************************************************
 * bool Cell::isMarked() const
 *
 *  Purpose:    Check if the cell is marked
 *
 *  Entry:      No entry
 *
 *  Exit:       Returns true if the cell is marked
 *********************************************************************************************************/
bool Cell::isMarked() const
{
    return m_marked;
}
/*********************************************************************************************************
 * bool Cell::isBomb() const
 *
 *  Purpose:    Checks if a cell is a bomb
 *
 *  Entry:      No entry
 *
 *  Exit:       Returns true if the uncovered value is X
 *********************************************************************************************************/
bool Cell::isBomb() const
{
    return m_uncovered == 'X';
}

//
//mutators
//

/*********************************************************************************************************
 * void Cell::markCell()
 *
 *  Purpose:    Toggles the value of m_marked to mark/unmark a cell
 *
 *  Entry:      No entry
 *
 *  Exit:       Sets the current value to the opposite
 *********************************************************************************************************/
void Cell::markCell()
{
    if(m_covered)
    {
        m_marked = !m_marked;
    }
}
/*********************************************************************************************************
 * void Cell::setUncovered(char value)
 *
 *  Purpose:    Set the uncovered value of a cell
 *
 *  Entry:      Value to set
 *
 *  Exit:       Cell has a new uncovered value
 *********************************************************************************************************/
void Cell::setUncovered(char value)
{
    m_uncovered = value;
}
/*********************************************************************************************************
 * void Cell::selectCell()
 *
 *  Purpose:    Uncover a cell
 *
 *  Entry:      No entry
 *
 *  Exit:       m_covered and m_marked are set to false
 *********************************************************************************************************/
void Cell::selectCell()
{
    m_marked = false;
    m_covered = false;
}

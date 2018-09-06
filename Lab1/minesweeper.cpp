/*********************************************************************************************************
 * Author:                      Aaron Day
 * Date Created:                10/17/2015
 * Last Modification Date:      10/19/2015
 * Assignment Number:           Lab 1
 * Filename:                    minesweeper.cpp
 *********************************************************************************************************/

#include "minesweeper.h"
#include "board.h"

using namespace std;

//constructor
Minesweeper::Minesweeper(char level)
    :Board(level)
{
}

//
//accessors
//

/*********************************************************************************************************
 * void Minesweeper::display()
 *
 *  Purpose:    Create a simple display for users to see the layout of the board
 *
 *  Entry:      No entry
 *
 *  Exit:       Board layout is sent to the screen
 *********************************************************************************************************/
void Minesweeper::display()
{
    int rows = getBoard().getRow();
    int cols = getBoard().getColumn();
    //top row of column numbers
    cout << " |";
    for(int c = 0; c < cols; ++c)
    {
        if(c <= 10)
        {
            cout << " " << c;
        }
        else
        {
            cout << c;
        }
    }
    //dashed line after column numbers
    cout << "|\n---";
    for(int c = 0; c < cols; ++c)
    {
        cout << "--";
    }
    cout << endl;
    //begin every row with the row number (in reverse order)
    for(int r = rows - 1; r >= 0; --r)
    {
        if(r < 10)
        {
            cout << " " << r << "|";
        }
        else
        {
            cout << r << "|";
        }
        //display each cell: covered, marked, number of adjacent mines, or blank
        //follow every cell with the | symbol to separate them
        for(int c = 0; c < cols; ++c)
        {
            if(getBoard().Select(r, c).isCovered() && getBoard().Select(r, c).isMarked())
            {
                cout << "M|";
            }
            else if(getBoard().Select(r, c).isCovered())
            {
                cout << "?|";
            }
            else
            {
                cout << getBoard().Select(r, c).getUncovered() << "|";
            }
        }
        //dashed line after every row
        cout << r << "\n---";
        for(int c = 0; c < cols; ++c)
        {
            cout << "--";
        }
        cout << "--" << endl;
    }
    //bottom row of column numbers
    cout << " |";
    for(int c = 0; c < cols; ++c)
    {
        if(c <= 10)
        {
            cout << " " << c;
        }
        else
        {
            cout << c;
        }
    }
    cout << "|\n" << endl;
}
/*********************************************************************************************************
 * void Minesweeper::getInput()
 *
 *  Purpose:    Request specific information from the user, get that information, and process it
 *
 *  Entry:      User will enter a row and column as well as indicate if this will be to mark that cell
 *              or not.
 *
 *  Exit:       Cell is uncovered or marked/unmarked depending on user input
 *********************************************************************************************************/
void Minesweeper::getInput()
{
    char mark;
    int row, col;
    cout << "Marked: " << m_marked << "/" << getMines() << " mines";
    cout << '\t' << m_covered << " still covered\t" << endl;
    cout << "Enter: MARK ROW COL" << endl;
    cout << "For example: N 5 3 selects row 5 col 3" << endl;
    cout << "        and: Y 8 2 marks row 8 col 2" << endl;
    cout << "Your selection: ";
    cin >> mark >> row >> col;
    if(isValid(row, col))
    {
        if(mark == 'n' || mark == 'N')
        {
            selectCell(row, col);
        }
        else
        {
            markCell(row, col);
        }
    }
}
/*********************************************************************************************************
 * bool Minesweeper::gameOver() const
 *
 *  Purpose:    Check if all the bombs have been marked or if there are only enough covered cells to
 *              cover the bombs
 *
 *  Entry:      No entry
 *
 *  Exit:       Returns true if all criteria for a win exist
 *********************************************************************************************************/
bool Minesweeper::gameOver() const
{
    return m_remaining == 0 || m_covered == getMines();
}

//
//mutators
//

/*********************************************************************************************************
 * void Minesweeper::selectCell(int row, int col)
 *
 *  Purpose:    Uncovers a cell and if the uncovered value is blank it continues uncovering cells until
 *              it reaches an edge or a number
 *
 *  Entry:      Row and col of initial cell to uncover
 *
 *  Exit:       Cell is uncovered; as well as any adjacent cell if the uncovered value was blank
 *********************************************************************************************************/
void Minesweeper::selectCell(int row, int col)
{
    if(getBoard().Select(row, col).getUncovered() != ' ' && getBoard().Select(row, col).isCovered())
    {
        if(getBoard().Select(row, col).isMarked())
        {
            --m_marked;
        }
        getBoard().Select(row, col).selectCell();
        if(getBoard().Select(row, col).isBomb())
        {
            display();
            cout << "Bomb triggered, game over" << endl;
            exit(0);
        }
        if(gameOver())
        {
            display();
            cout << "CONGRATULATIONS!!! All the bombs have been defused." << endl;
            exit(0);
        }
    }
    else if(getBoard().Select(row, col).getUncovered() == ' ' && getBoard().Select(row, col).isCovered())
    {
        //upper
        if(isValid(row - 1, col - 1))
        {
            selectCell(row - 1, col - 1);
        }
        if(isValid(row - 1, col))
        {
            selectCell(row - 1, col);
        }
        if(isValid(row - 1, col + 1))
        {
            selectCell(row - 1, col + 1);
        }
        //middle
        if(isValid(row, col - 1))
        {
            selectCell(row, col - 1);
        }
        getBoard().Select(row, col).selectCell(); //current cell
        if(isValid(row, col + 1))
        {
            selectCell(row, col + 1);
        }
        //lower
        if(isValid(row + 1, col - 1))
        {
            selectCell(row + 1, col - 1);
        }
        if(isValid(row + 1, col))
        {
            selectCell(row + 1, col);
        }
        if(isValid(row + 1, col + 1))
        {
            selectCell(row + 1, col + 1);
        }
    }
    setCovered();
}
/*********************************************************************************************************
 * void Minesweeper::markCell(int row, int col)
 *
 *  Purpose:    Provide a visual indication on the display for users to see where they believe a bomb
 *              exists
 *
 *  Entry:      Row and column of cell to mark
 *
 *  Exit:       Cell now displays M indicating that the user has marked this as a bomb location
 *********************************************************************************************************/
void Minesweeper::markCell(int row, int col)
{
    getBoard().Select(row, col).isMarked() ? --m_marked : ++m_marked;
    getBoard().Select(row, col).markCell();
    if(getBoard().Select(row, col).isBomb() && getBoard().Select(row, col).isMarked())
    {
        --m_remaining;
    }
    if(getBoard().Select(row, col).isBomb() && !getBoard().Select(row, col).isMarked())
    {
        ++m_remaining;
    }
}



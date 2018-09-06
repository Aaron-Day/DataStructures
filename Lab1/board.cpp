/*********************************************************************************************************
 * Author:                      Aaron Day
 * Date Created:                10/17/2015
 * Last Modification Date:      10/19/2015
 * Assignment Number:           Lab 1
 * Filename:                    board.cpp
 *********************************************************************************************************/

#include "board.h"

using namespace std;

//
//constructor
//
Board::Board(char level)
{
    if(level == 'e' || level == 'E')
    {
        m_board = *(new Array2D<Cell>(16, 30));
        m_mines = 100;
        m_remaining = 100;
        m_covered = 16 * 30;
        m_marked = 0;
    }
    else if(level == 'i' || level == 'I')
    {
        m_board = *(new Array2D<Cell>(16, 16));
        m_mines = 40;
        m_remaining = 40;
        m_covered = 16 * 16;
        m_marked = 0;
    }
    else
    {
        m_board = *(new Array2D<Cell>(10, 10));
        m_mines = 10;
        m_remaining = 10;
        m_covered = 10 * 10;
        m_marked = 0;
    }
    layMines();
    scanAll();
}

//
//accessors
//

/*********************************************************************************************************
 * int Board::getMines() const
 *
 *  Purpose:    Get the number of mines in this level of game
 *
 *  Entry:      No entry
 *
 *  Exit:       Returns the number of mines in this game
 *********************************************************************************************************/
int Board::getMines() const
{
    return m_mines;
}
/*********************************************************************************************************
 * bool Board::isValid(int row, int col)
 *
 *  Purpose:    Check if the given row and col is on the game board
 *
 *  Entry:      No entry
 *
 *  Exit:       Returns true if the row and col reference is a valid cell on the game board
 *********************************************************************************************************/
bool Board::isValid(int row, int col)
{
    return row >= 0 && row < getBoard().getRow() && col >= 0 && col < getBoard().getColumn();
}

//
//mutators
//

/*********************************************************************************************************
 * int Board::getMines() const
 *
 *  Purpose:    Scans all cells and checks if they are covered or not, then updates m_covered with the
 *              correct count.
 *
 *  Entry:      No entry
 *
 *  Exit:       Updates m_covered with the number of covered cells
 *********************************************************************************************************/
void Board::setCovered()
{
    m_covered = 0;
    for(int r = 0; r < m_board.getRow(); ++r)
    {
        for(int c = 0; c < m_board.getColumn(); ++c)
        {
            if(m_board.Select(r, c).isCovered())
            {
                ++m_covered;
            }
        }
    }
}
/*********************************************************************************************************
 * void Board::layMines()
 *
 *  Purpose:    Set the uncovered value of cells to X until the number of mines for the game have been set
 *
 *  Entry:      No entry
 *
 *  Exit:       The number of cells with uncovered values of X are now equal to the number of mines
 *********************************************************************************************************/
void Board::layMines()
{
    srand((unsigned)time(0));
    int rows = m_board.getRow();
    int cols = m_board.getColumn();
    int mines = 0;
    while(mines < m_mines)  //until all the mines have been laid
    {
        int row = rand() % rows;    //randomly generate a row number < the number of rows
        int col = rand() % cols;    //randomly generate a col number < the number of columns
        if(m_board.Select(row, col).getUncovered() != 'X')  //if a mine is already here, skip
        {
            m_board.Select(row, col).setUncovered('X');     //otherwise set one here
            ++mines;
        }
    }
}
/*********************************************************************************************************
 * void Board::scanCell(int row, int col)
 *
 *  Purpose:    Sets the uncovered value to the number of adjacent cells containing mines, unless this
 *              cell is a mine. None adjacent means no change from the default ' ' char.
 *
 *  Entry:      Row and column reference
 *
 *  Exit:       Cells uncovered value now equals the number of mines it is adjacent to. ' ' if not adjacent
 *              to any.
 *********************************************************************************************************/
void Board::scanCell(int row, int col)
{
    int near = 0;
    if(!m_board.Select(row,col).isBomb()) //if the cell isn't a bomb, check how many bombs are adjacent
    {
        //upper row
        if(isValid(row - 1, col - 1))
        {
            if(m_board.Select(row - 1, col - 1).isBomb())
            {
                ++near;
            }
        }
        if(isValid(row - 1, col))
        {
            if(m_board.Select(row - 1, col).isBomb())
            {
                ++near;
            }
        }
        if(isValid(row - 1, col + 1))
        {
            if(m_board.Select(row - 1, col + 1).isBomb())
            {
                ++near;
            }
        }
        //middle row
        if(isValid(row, col - 1))
        {
            if(m_board.Select(row, col - 1).isBomb())
            {
                ++near;
            }
        }
        if(isValid(row, col + 1))
        {
            if(m_board.Select(row, col + 1).isBomb())
            {
                ++near;
            }
        }
        //lower row
        if(isValid(row + 1, col - 1))
        {
            if(m_board.Select(row + 1, col - 1).isBomb())
            {
                ++near;
            }
        }
        if(isValid(row + 1, col))
        {
            if(m_board.Select(row + 1, col).isBomb())
            {
                ++near;
            }
        }
        if(isValid(row + 1, col + 1))
        {
            if(m_board.Select(row + 1, col + 1).isBomb())
            {
                ++near;
            }
        }
        if(near > 0)
        {
            m_board.Select(row, col).setUncovered('0' + static_cast<char>(near));
        }
    }
}
/*********************************************************************************************************
 * void Board::scanAll()
 *
 *  Purpose:    Perform the scanCell function on every cell in the board
 *
 *  Entry:      No entry
 *
 *  Exit:       Every cell performs scanCell
 *********************************************************************************************************/
void Board::scanAll()
{
    for(int r = 0; r < m_board.getRow(); ++r)
    {
        for(int c = 0; c < m_board.getColumn(); ++c)
        {
            scanCell(r, c);
        }
    }
}

//
//derived functions
//

/*********************************************************************************************************
 * int Board::getMines() const
 *
 *  Purpose:    For derived classes to get access to the board for use with play
 *
 *  Entry:      No entry
 *
 *  Exit:       Returns the game board
 *********************************************************************************************************/
Array2D<Cell>& Board::getBoard()
{
    return m_board;
}

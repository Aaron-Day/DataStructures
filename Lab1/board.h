/*********************************************************************************************************
 * Author:                      Aaron Day
 * Date Created:                10/17/2015
 * Last Modification Date:      10/19/2015
 * Assignment Number:           Lab 1
 * Filename:                    board.h
 *
 * Overview:
 *      This program generates a minesweeper board and sets it up to be ready for play. Derived classes
 *      (i.e. Minesweeper) build from this for play.
 * Input:
 *      Input is from the Minesweeper class and is only a char indicating the level of game to play
 * Output:
 *      There is no output stream for this class
 *********************************************************************************************************/

#ifndef BOARD_H
#define BOARD_H

#include <ctime>
#include <cmath>

#include "array2d.h"
#include "row.h"
#include "exception.h"
#include "cell.h"

/*********************************************************************************************************
 * Class: Board
 *
 * Constructors/Destructors:
 *      Board(char level = 'b')
 *              Default constructor, creates a board of the appropriate size determined by the game
 *              level. Then sets all the member variables, lays the mines, and sets the uncovered
 *              values.
 *
 * Accessors:
 *      int getMines() const
 *              Returns the number of mines for this level of game
 *
 * Mutators:
 *      void setCovered()
 *              Checks all the cells to see if they are covered, then sets m_covered to that number
 *              of cells.
 *      void layMines()
 *              Places mines randomly on the board until all mines for this level game have been laid
 *      void scanCell(int row, int col)
 *              Searches adjacent cells for mines then sets the uncovered value to the number found
 *      void scanAll()
 *              Performs scanCell for every cell that is not a mine
 *      bool isValid(int row, int col)
 *              Returns true if the row and col given are on the game board
 *********************************************************************************************************/

class Board
{
public:
    //constructor
    Board(char level = 'b');

    //accessors
    int getMines() const;
    bool isValid(int row, int col);

    //mutators
    void setCovered();
    void layMines();
    void scanCell(int row, int col);
    void scanAll();

protected:
    Array2D<Cell>& getBoard();              //go to derived class to manipulate board for play
    int m_remaining, m_covered, m_marked;   //unmarked mines remaining, cells covered, cells marked

private:
    Array2D<Cell> m_board;  //2D array of Cells
    int m_mines;            //Number of mines in this game
};

#endif // BOARD_H

/*********************************************************************************************************
 * Author:                      Aaron Day
 * Date Created:                10/17/2015
 * Last Modification Date:      10/19/2015
 * Assignment Number:           Lab 1
 * Filename:                    minesweeper.h
 *
 * Overview:
 *      This program generates a minesweeper board and manipulates the cell in the board
 * Input:
 *      Input is from the user and is a char indicating the level of game to play which determines
 *      board size and number of mines. The user also inputs cell references to either uncover or mark
 *      them.
 * Output:
 *      There is a display function to display the board in it's current configuration. There is also
 *      functions to display user information and get input
 *********************************************************************************************************/

#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include "array2d.h"
#include "row.h"
#include "exception.h"
#include "cell.h"
#include "board.h"

/*********************************************************************************************************
 * Class: Minesweeper
 *
 * Constructors/Destructors:
 *      Minesweeper(char level = 'b')
 *              Default constructor, creates a board the appropriate size for the level. Then lays
 *              mines and uncovered values.
 *
 * Accessors:
 *      void display()
 *              Displays a board with the current configuration
 *      void getInput()
 *              Gets input from the user to select/mark a cell
 *      bool gameOver() const
 *              Checks if game winning criteria are met
 *
 * Mutators:
 *      void selectCell(int row, int col)
 *              Uncovers a cell, if the uncovered value is blank then it does a flood fill to uncover
 *              adjacent cells until it reaches a number
 *      void markCell(int row, int col)
 *              Marks a cell
 *********************************************************************************************************/

class Minesweeper : Board
{
public:
    //constructor
    Minesweeper(char level = 'b');

    //accessors
    void display();
    void getInput();
    bool gameOver() const;

    //mutators
    void selectCell(int row, int col);
    void markCell(int row, int col);
};

#endif // MINESWEEPER_H

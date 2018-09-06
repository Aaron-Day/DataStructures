/*********************************************************************************************************
* Author:                   Aaron Day
* Date Created:             11/08/2015
* Last Modification Date:   11/10/2015
* Assignment Number:        Lab 3
* Filename:                 freecell.h
*
* Overview:     Freecell class is the freecell game engine
*
* Input:        Input is provided from the getMove function which gets the from and to locations from the
*               user at runtime
*
* Output:       Displays game layout to the screen as well as user instructions
 *********************************************************************************************************/
#ifndef FREECELL_H
#define FREECELL_H

#include "array.h"
#include "stack.h"
#include "card.h"
#include "deck.h"

class Freecell
{
public:
    //constructors
    Freecell();
    
    //accessors
    int HeightOfPlay() const; //max stack size in play area
    bool GameOver() const;
    void display() const;

    //mutators
    void getMove();
    void move(int from, int to);
    Card* fromLoc(int from);
    void toLoc(Card* card, int from, int to);
    void putBack(Card* card, int from);

private:
    Array<Card*> m_free;        //freecells

    Stack<Card*> m_spades;      //spade home stack
    Stack<Card*> m_clubs;       //club home stack
    Stack<Card*> m_hearts;      //heart home stack
    Stack<Card*> m_diamonds;    //diamond home stack

    Stack<Card*> m_1;           //play column 1
    Stack<Card*> m_2;           //play column 2
    Stack<Card*> m_3;           //play column 3
    Stack<Card*> m_4;           //play column 4
    Stack<Card*> m_5;           //play column 5
    Stack<Card*> m_6;           //play column 6
    Stack<Card*> m_7;           //play column 7
    Stack<Card*> m_8;           //play column 8
};

#endif // FREECELL_H

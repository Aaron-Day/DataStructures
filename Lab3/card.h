/*********************************************************************************************************
* Author:                   Aaron Day
* Date Created:             11/08/2015
* Last Modification Date:   11/10/2015
* Assignment Number:        Lab 3
* Filename:                 card.h
*
* Overview:     Card class stores information about a single card from a standard deck of 52 cards
*
* Input:        Card number 0-51:
*               Suit order: Spades, Clubs, Hearts, Diamonds;
*               Card order in suit: Ace - King
*               Example: card 26 is the Ace of Hearts
*
* Output:       Get functions enable retrieval of card information
 *********************************************************************************************************/
#ifndef CARD_H
#define CARD_H

#include <string>

using namespace std;

class Card
{
public:
    //constructors
    Card(int card);

    //accessors
    string getRank() const;
    string getSuit() const;
    string getColor() const;
    string showCard() const;
    int getCard() const;
    int getRankInt() const;
    int getSuitInt() const;
    bool isRed() const;

private:
    int m_card;     //0-51
};

#endif // CARD_H

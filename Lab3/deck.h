/*********************************************************************************************************
* Author:                   Aaron Day
* Date Created:             11/08/2015
* Last Modification Date:   11/10/2015
* Assignment Number:        Lab 3
* Filename:                 deck.h
*
* Overview:     Deck class creates a standard deck of 52 cards (Card class) and provides shuffle
*               and deal functions
*
* Input:        No input
*
* Output:       Deal returns a card and removes it from the deck
 *********************************************************************************************************/
#ifndef DECK_H
#define DECK_H

#include "card.h"
#include <vector>

class Deck
{
public:
    Deck();

    void shuffle();
    Card dealCard();

private:
    vector<Card> m_deck;
};

#endif // DECK_H

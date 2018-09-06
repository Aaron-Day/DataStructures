/*********************************************************************************************************
* Author:                   Aaron Day
* Date Created:             11/08/2015
* Last Modification Date:   11/10/2015
* Assignment Number:        Lab 3
* Filename:                 deck.cpp
 *********************************************************************************************************/
#include "deck.h"
#include <ctime>

Deck::Deck()
{
    for(int i = 0; i < 52; ++i)
    {
        m_deck.push_back(Card(i));
    }
    shuffle();
}

void Deck::shuffle()
{
    //shuffle the deck of cards 4 times
    srand((unsigned)time(0));
    for(int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 52; ++j)
        {
            int index = rand() % 52;
            Card temp = m_deck[(size_t)j];
            m_deck[(size_t)j] = m_deck[(size_t)index];
            m_deck[(size_t)index] = temp;
        }
    }
}

Card Deck::dealCard()
{
    Card temp = m_deck.back();
    m_deck.pop_back();
    return temp;
}

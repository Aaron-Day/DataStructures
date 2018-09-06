/*********************************************************************************************************
* Author:                   Aaron Day
* Date Created:             11/08/2015
* Last Modification Date:   11/10/2015
* Assignment Number:        Lab 3
* Filename:                 card.cpp
 *********************************************************************************************************/
#include "card.h"

Card::Card(int card)
{
    //ensure a valid card input
    if(card < 0)
    {
        card *= -1;
    }
    card %= 52;
    m_card = card;
}

string Card::getRank() const
{
    string rank[13] = {"Ace","2","3","4","5","6","7","8","9","10","Jack","Queen","King"};
    return rank[getRankInt()];
}

string Card::getSuit() const
{
    string suit[4] = {"Spades","Clubs","Hearts","Diamonds"};
    return suit[getSuitInt()];
}

string Card::getColor() const
{
    string color[2] = {"Black","Red"};
    return color[(int)isRed()];
}

string Card::showCard() const
{
    return getRank() + " " + getSuit();
}

int Card::getCard() const
{
    return m_card;
}

int Card::getRankInt() const
{
    return m_card % 13;
}

int Card::getSuitInt() const
{
    return m_card / 13;
}

bool Card::isRed() const
{
    return m_card >= 26;
}

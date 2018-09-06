/*********************************************************************************************************
* Author:                   Aaron Day
* Date Created:             11/08/2015
* Last Modification Date:   11/10/2015
* Assignment Number:        Lab 3
* Filename:                 freecell.cpp
 *********************************************************************************************************/
#include "freecell.h"
#include <iomanip>

Freecell::Freecell()
    :m_free(4), m_spades(13), m_clubs(13), m_hearts(13), m_diamonds(13),
      m_1(52), m_2(52), m_3(52), m_4(52), m_5(52), m_6(52), m_7(52), m_8(52)
{
	for (int i = 0; i < 4; ++i)
	{
		m_free[i] = nullptr;
	}
    Deck cards;
	int col = 0;
    for(int i = 0; i < 52; ++i)
    {
        switch(col)
        {
        case 0:
            m_1.Push(new Card(cards.dealCard().getCard()));
            break;
        case 1:
            m_2.Push(new Card(cards.dealCard().getCard()));
            break;
        case 2:
            m_3.Push(new Card(cards.dealCard().getCard()));
            break;
        case 3:
            m_4.Push(new Card(cards.dealCard().getCard()));
            break;
        case 4:
            m_5.Push(new Card(cards.dealCard().getCard()));
            break;
        case 5:
            m_6.Push(new Card(cards.dealCard().getCard()));
            break;
        case 6:
            m_7.Push(new Card(cards.dealCard().getCard()));
            break;
        case 7:
            m_8.Push(new Card(cards.dealCard().getCard()));
            break;
        }
        ++col %= 8;
    }
}

int Freecell::HeightOfPlay() const
{
    int max = 0;
    if(m_1.Size() > max)
    {
        max = m_1.Size();
    }
    if(m_2.Size() > max)
    {
        max = m_2.Size();
    }
    if(m_3.Size() > max)
    {
        max = m_3.Size();
    }
    if(m_4.Size() > max)
    {
        max = m_4.Size();
    }
    if(m_5.Size() > max)
    {
        max = m_5.Size();
    }
    if(m_6.Size() > max)
    {
        max = m_6.Size();
    }
    if(m_7.Size() > max)
    {
        max = m_7.Size();
    }
    if(m_8.Size() > max)
    {
        max = m_8.Size();
    }
    return max;
}
bool Freecell::GameOver() const
{
    bool over = true;
    for(int i = 0; i < 4; ++i)
    {
        if(m_free[i] != nullptr)
        {
            over = false;
            break;
        }
    }
    return over && HeightOfPlay() == 0;
}
void Freecell::display() const
{
    //FREE & HOME HEADER
    cout << " Freecell (9)  "
         << " Freecell (10) "
         << " Freecell (11) "
         << " Freecell (12) "
         << "  Spades (13)  "
         << "  Clubs (14)   "
         << "  Hearts (15)  "
         << " Diamonds (16) "
         << endl;
    //FREE & HOME CARDS
    cout << left << setw(15) << (m_free[0] == nullptr ? "     empty     " : m_free[0]->showCard());
    cout << left << setw(15) << (m_free[1] == nullptr ? "     empty     " : m_free[1]->showCard());
    cout << left << setw(15) << (m_free[2] == nullptr ? "     empty     " : m_free[2]->showCard());
    cout << left << setw(15) << (m_free[3] == nullptr ? "     empty     " : m_free[3]->showCard());
    cout << left << setw(15) << (m_spades.isEmpty() ? "     empty     " : "     " + m_spades.Peek()->getRank());
    cout << left << setw(15) << (m_clubs.isEmpty() ? "     empty     " : "     " + m_clubs.Peek()->getRank());
    cout << left << setw(15) << (m_hearts.isEmpty() ? "     empty     " : "     " + m_hearts.Peek()->getRank());
    cout << left << setw(15) << (m_diamonds.isEmpty() ? "     empty     " : "     " + m_diamonds.Peek()->getRank());

    //PLAY HEADER
    cout << endl << endl;
    cout << "      (1)      "
         << "      (2)      "
         << "      (3)      "
         << "      (4)      "
         << "      (5)      "
         << "      (6)      "
         << "      (7)      "
         << "      (8)      "
         << endl;
    //PLAY CARDS
    Iterator<Card*> col_1 = m_1.Begin();
    Iterator<Card*> col_2 = m_2.Begin();
    Iterator<Card*> col_3 = m_3.Begin();
    Iterator<Card*> col_4 = m_4.Begin();
    Iterator<Card*> col_5 = m_5.Begin();
    Iterator<Card*> col_6 = m_6.Begin();
    Iterator<Card*> col_7 = m_7.Begin();
    Iterator<Card*> col_8 = m_8.Begin();
    for(int i = 0; i < HeightOfPlay(); ++i)
    {
        if(col_1.getNode() != nullptr)
        {
            cout << left << setw(15) << (*col_1)->showCard();
            ++col_1;
        }
        else
        {
            cout << "               ";
        }
        if(col_2.getNode() != nullptr)
        {
            cout << left << setw(15) << (*col_2)->showCard();
            ++col_2;
        }
        else
        {
            cout << "               ";
        }
        if(col_3.getNode() != nullptr)
        {
            cout << left << setw(15) << (*col_3)->showCard();
            ++col_3;
        }
        else
        {
            cout << "               ";
        }
        if(col_4.getNode() != nullptr)
        {
            cout << left << setw(15) << (*col_4)->showCard();
            ++col_4;
        }
        else
        {
            cout << "               ";
        }
        if(col_5.getNode() != nullptr)
        {
            cout << left << setw(15) << (*col_5)->showCard();
            ++col_5;
        }
        else
        {
            cout << "               ";
        }
        if(col_6.getNode() != nullptr)
        {
            cout << left << setw(15) << (*col_6)->showCard();
            ++col_6;
        }
        else
        {
            cout << "               ";
        }
        if(col_7.getNode() != nullptr)
        {
            cout << left << setw(15) << (*col_7)->showCard();
            ++col_7;
        }
        else
        {
            cout << "               ";
        }
        if(col_8.getNode() != nullptr)
        {
            cout << left << setw(15) << (*col_8)->showCard();
            ++col_8;
        }
        else
        {
            cout << "               ";
        }
        cout << endl;
    }
}

void Freecell::getMove()
{
	cout << "Locations are in parenthesis. Enter 'from' and 'to' locations: ";
	int from, to;
	cin >> from >> to;
	move(from, to);
}

void Freecell::move(int from, int to)
{
    if(from != to && from >= 1 && from <= 12 && to >= 1 && to <= 16)
    {
        toLoc(fromLoc(from), from, to);
    }
	else
	{
		char msg[] = "Unable to get card";
		throw Exception(msg);
	}
}
Card* Freecell::fromLoc(int from)
{
    Card* temp = nullptr;
    bool success = false;
    switch(from)
    {
    //play stacks
    case 1:
        if(!m_1.isEmpty())
        {
            temp = m_1.Pop();
            success = true;
        }
        break;
    case 2:
        if(!m_2.isEmpty())
        {
            temp = m_2.Pop();
            success = true;
        }
        break;
    case 3:
        if(!m_3.isEmpty())
        {
            temp = m_3.Pop();
            success = true;
        }
        break;
    case 4:
        if(!m_4.isEmpty())
        {
            temp = m_4.Pop();
            success = true;
        }
        break;
    case 5:
        if(!m_5.isEmpty())
        {
            temp = m_5.Pop();
            success = true;
        }
        break;
    case 6:
        if(!m_6.isEmpty())
        {
            temp = m_6.Pop();
            success = true;
        }
        break;
    case 7:
        if(!m_7.isEmpty())
        {
            temp = m_7.Pop();
            success = true;
        }
        break;
    case 8:
        if(!m_8.isEmpty())
        {
            temp = m_8.Pop();
            success = true;
        }
        break;
    //freecells
    case 9:
        if(m_free[0] != nullptr)
        {
            temp = m_free[0];
            m_free[0] = nullptr;
            success = true;
        }
        break;
    case 10:
        if(m_free[1] != nullptr)
        {
            temp = m_free[1];
            m_free[1] = nullptr;
            success = true;
        }
        break;
    case 11:
        if(m_free[2] != nullptr)
        {
            temp = m_free[2];
            m_free[2] = nullptr;
            success = true;
        }
        break;
    case 12:
        if(m_free[3] != nullptr)
        {
            temp = m_free[3];
            m_free[3] = nullptr;
            success = true;
        }
        break;
    }
    if(success)
    {
        return temp;
    }
    else
    {
        char msg[] = "Unable to get card";
        throw Exception(msg);
    }
}
void Freecell::toLoc(Card* card, int from, int to)
{
    bool success = false;
    switch(to)
    {
    //play stacks
    //if the stack is empty or the top card is 1 higher rank and different color
    case 1:
        if(m_1.Size() == 0 ||
                (m_1.Peek()->getRankInt() == card->getRankInt() + 1 && m_1.Peek()->isRed() != card->isRed()))
        {
            m_1.Push(card);
            success = true;
        }
        break;
    case 2:
        if(m_2.Size() == 0 ||
                (m_2.Peek()->getRankInt() == card->getRankInt() + 1 && m_2.Peek()->isRed() != card->isRed()))
        {
            m_2.Push(card);
            success = true;
        }
        break;
    case 3:
        if(m_3.Size() == 0 ||
                (m_3.Peek()->getRankInt() == card->getRankInt() + 1 && m_3.Peek()->isRed() != card->isRed()))
        {
            m_3.Push(card);
            success = true;
        }
        break;
    case 4:
        if(m_4.Size() == 0 ||
                (m_4.Peek()->getRankInt() == card->getRankInt() + 1 && m_4.Peek()->isRed() != card->isRed()))
        {
            m_4.Push(card);
            success = true;
        }
        break;
    case 5:
        if(m_5.Size() == 0 ||
                (m_5.Peek()->getRankInt() == card->getRankInt() + 1 && m_5.Peek()->isRed() != card->isRed()))
        {
            m_5.Push(card);
            success = true;
        }
        break;
    case 6:
        if(m_6.Size() == 0 ||
                (m_6.Peek()->getRankInt() == card->getRankInt() + 1 && m_6.Peek()->isRed() != card->isRed()))
        {
            m_6.Push(card);
            success = true;
        }
        break;
    case 7:
        if(m_7.Size() == 0 ||
                (m_7.Peek()->getRankInt() == card->getRankInt() + 1 && m_7.Peek()->isRed() != card->isRed()))
        {
            m_7.Push(card);
            success = true;
        }
        break;
    case 8:
        if(m_8.Size() == 0 ||
                (m_8.Peek()->getRankInt() == card->getRankInt() + 1 && m_8.Peek()->isRed() != card->isRed()))
        {
            m_8.Push(card);
            success = true;
        }
        break;
    //freecells
    //if freecell is empty
    case 9:
        if(m_free[0] == nullptr)
        {
            m_free[0] = card;
            success = true;
        }
        break;
    case 10:
        if(m_free[1] == nullptr)
        {
            m_free[1] = card;
            success = true;
        }
        break;
    case 11:
        if(m_free[2] == nullptr)
        {
            m_free[2] = card;
            success = true;
        }
        break;
    case 12:
        if(m_free[3] == nullptr)
        {
            m_free[3] = card;
            success = true;
        }
        break;
    //home stacks
    //if suit matches and top card is 1 less or empty
    case 13:
        if(card->getSuitInt() == 0)
        {
            if(m_spades.isEmpty())
            {
                if(card->getRankInt() == 0)
                {
                    m_spades.Push(card);
                    success = true;
                }
            }
            else if(m_spades.Peek()->getRankInt() == card->getRankInt() - 1)
            {
                m_spades.Push(card);
                success = true;
            }
        }
        break;
    case 14:
        if(card->getSuitInt() == 1)
        {
            if(m_clubs.isEmpty())
            {
                if(card->getRankInt() == 0)
                {
                    m_clubs.Push(card);
                    success = true;
                }
            }
            else if(m_clubs.Peek()->getRankInt() == card->getRankInt() - 1)
            {
                m_clubs.Push(card);
                success = true;
            }
        }
        break;
    case 15:
        if(card->getSuitInt() == 2)
        {
            if(m_hearts.isEmpty())
            {
                if(card->getRankInt() == 0)
                {
                    m_hearts.Push(card);
                    success = true;
                }
            }
            else if(m_hearts.Peek()->getRankInt() == card->getRankInt() - 1)
            {
                m_hearts.Push(card);
                success = true;
            }
        }
        break;
    case 16:
        if(card->getSuitInt() == 3)
        {
            if(m_diamonds.isEmpty())
            {
                if(card->getRankInt() == 0)
                {
                    m_diamonds.Push(card);
                    success = true;
                }
            }
            else if(m_diamonds.Peek()->getRankInt() == card->getRankInt() - 1)
            {
                m_diamonds.Push(card);
                success = true;
            }
        }
        break;
    }
    if(!success)
    {
        putBack(card, from);
        char msg[] = "Unable to place card";
        throw Exception(msg);
    }
}
void Freecell::putBack(Card* card, int from)
{
    switch(from)
    {
    //play stacks
    case 1:
        m_1.Push(card);
        break;
    case 2:
        m_2.Push(card);
        break;
    case 3:
        m_3.Push(card);
        break;
    case 4:
        m_4.Push(card);
        break;
    case 5:
        m_5.Push(card);
        break;
    case 6:
        m_6.Push(card);
        break;
    case 7:
        m_7.Push(card);
        break;
    case 8:
        m_8.Push(card);
        break;
    //freecells
    case 9:
        m_free[0] = card;
        break;
    case 10:
        m_free[1] = card;
        break;
    case 11:
        m_free[2] = card;
        break;
    case 12:
        m_free[3] = card;
        break;
    }
}


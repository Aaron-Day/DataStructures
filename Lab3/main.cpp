/*********************************************************************************************************
* Author:                   Aaron Day
* Date Created:             11/08/2015
* Last Modification Date:   11/10/2015
* Assignment Number:        Lab 3
* Filename:                 main.cpp
*
* Overview:     Runs the freecell game
 *********************************************************************************************************/
#include <iostream>

#include "card.h"
#include "deck.h"
#include "freecell.h"

using namespace std;

int main()
{
    Freecell game;
	while (!game.GameOver())
	{
		game.display();
		bool goodMove = false;
		while (!goodMove)
		{
			try
			{
				game.getMove();
				goodMove = true;
			}
			catch (Exception ex)
			{
				cout << ex << endl;
				goodMove = false;
			}
		}
	}

    return 0;
}


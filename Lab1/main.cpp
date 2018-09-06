#include <iostream>

#include "minesweeper.h"

using namespace std;

int main()
{
    char level;
    cout << "Enter level: b = beginner, i = intermediate, e = expert ";
    cin >> level;
    Minesweeper newGame(level);
    while(!newGame.gameOver())
    {
        newGame.display();
        newGame.getInput();
    }
    if(newGame.gameOver())
    {
        newGame.display();
        cout << "CONGRATULATIONS!!! All the bombs have been defused." << endl;
    }

    return 0;
}


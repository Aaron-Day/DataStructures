/*********************************************************************************************************
* Author:                   Aaron Day
* Date Created:             11/15/2015
* Last Modification Date:   11/16/2015
* Assignment Number:        Lab 4
* Filename:                 main.cpp
*
* Overview:     Runs all of the tests for the AVLTree class
*
* Output:       Outputs to the screen the result of all of the tests
 *********************************************************************************************************/
#include <iostream>
#include "avltree.h"

using namespace std;

int main()
{
    //
    //Test AVL
    //

    cout << "\nTESTING AVLTREE CLASS\n" << endl;

    int numbers[9] = {8, 9, 10, 2, 1, 5, 3, 4, 6};

    AVLTree<int> tree;
    for(int i = 0; i < 9; ++i)
    {
        tree.Insert(numbers[i]);
    }

    tree.Traverse(tree.show);

    /*
     *              8
     *             / \
     *            /   \
     *           4     9
     *          / \     \
     *         /   \     \
     *        2     5     10
     *       / \     \
     *      /   \     \
     *     1     3     6
     */

    cout << endl;
    cout << "Answers:" << endl;
    cout << "Data: 1 Height: 0 Balance: 0" << endl;
    cout << "Data: 2 Height: 1 Balance: 0" << endl;
    cout << "Data: 3 Height: 0 Balance: 0" << endl;
    cout << "Data: 4 Height: 2 Balance: 0" << endl;
    cout << "Data: 5 Height: 1 Balance: 1" << endl;
    cout << "Data: 6 Height: 0 Balance: 0" << endl;
    cout << "Data: 8 Height: 3 Balance: -1" << endl;
    cout << "Data: 9 Height: 1 Balance: 1" << endl;
    cout << "Data: 10 Height: 0 Balance: 0" << endl;
    cout << endl;


    return 0;
}


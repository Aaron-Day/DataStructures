/*********************************************************************************************************
* Author:                   Aaron Day
* Date Created:             10/04/2015
* Last Modification Date:   11/08/2015
* Assignment Number:        6
* Filename:                 main.cpp
*
* Overview:     Runs all of the tests for the BST class stored in the driver.h file
*
* Output:       Outputs to the screen the result of all of the tests
 *********************************************************************************************************/
#include <iostream>
#include "bst.h"
#include "driver.h"
#include <ctime>
#include <vector>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main()
{
    //
    //Test BST
    //

    cout << "\nTESTING BST CLASS\n" << endl;

    //constructors
    testBST_ctor();

    cout << endl;

	//accessors
    testBST_Height();
	fillTree(); //fill the test array with a known list of ints
	testBST_InOrder();
	testBST_PreOrder();
	testBST_PostOrder();
	testBST_BreadthFirst();

	cout << endl;

	//mutators
    testBST_Insert();
    testBST_Delete();
    testBST_Purge();

	cout << endl;

	srand((unsigned)time(0));			//seed the random number generator
	BST<int> bigTree;					//create a binary search tree to store 100,000 random numbers
	for (int i = 0; i < 100000; ++i)	//populate the tree with random numbers
	{
		bigTree.Insert(rand());
	}

	//run searches to see how long each one takes
	clock_t start = clock();
	bigTree.InOrder(bigTree.Visit);
	clock_t end = clock();
	double duration = (end - start) / (double)CLOCKS_PER_SEC;
	cout << "InOrder Time Test: " << fixed << setprecision(6) << duration << endl;

	start = clock();
	bigTree.PreOrder(bigTree.Visit);
	end = clock();
	duration = (end - start) / (double)CLOCKS_PER_SEC;
	cout << "PreOrder Time Test: " << fixed << setprecision(6) << duration << endl;

	start = clock();
	bigTree.PostOrder(bigTree.Visit);
	end = clock();
	duration = (end - start) / (double)CLOCKS_PER_SEC;
	cout << "PostOrder Time Test: " << fixed << setprecision(6) << duration << endl;

	start = clock();
	bigTree.BreadthFirst(bigTree.Visit);
	end = clock();
	duration = (end - start) / (double)CLOCKS_PER_SEC;
	cout << "Breadth First Time Test: " << fixed << setprecision(6) << duration << endl;

    cout << endl;


    return 0;
}


/*********************************************************************************************************
* Author:                   Aaron Day
* Date Created:             11/04/2015
* Last Modification Date:   11/08/2015
* Assignment Number:        6
* Filename:                 driver.h
*
* Overview:     Used for testing the BST class
 *********************************************************************************************************/
#ifndef DRIVER_H
#define DRIVER_H

#include <string>
#include "bst.h"

using namespace std;

//function to print test results to the screen
void display(bool pass, string functionName)
{
    if(pass)
    {
        cout << "PASS - ";
    }
    else
    {
        cout << "FAIL - ";
    }
    cout << functionName << endl;
}

//
//BST Tests
//

//
//constructors
//

void testBST_ctor()
{
    BST<int> tree;
    bool pass = tree.Height() == 0;
    display(pass, "testBST_ctor()");
}

//
//accessors
//

void testBST_Height()
{
    BST<int> tree;
    bool pass = tree.Height() == 0;
    display(pass, "testBST_Height()");
}

//array used for comparing searches
int my_array[] = { 15, 10, 20, 5, 12, 18, 25, 11, 19, 23, 30, 22 };
/*
inorder: 5, 10, 11, 12, 15, 18, 19, 20, 22, 23, 25, 30
preorder: 15, 10, 5, 12, 11, 20, 18, 19, 25, 23, 22, 30
postorder: 5, 11, 12, 10, 19, 18, 22, 23, 30, 25, 20, 15
breadth: 15, 10, 20, 5, 12, 18, 25, 11, 19, 23, 30, 22
*/
//fill a tree for testing searches
BST<int> tree;
void fillTree()
{
	for (int i = 0; i < 12; ++i)
	{
		tree.Insert(my_array[i]);
	}
}

void testBST_InOrder()
{
	cout << "\ntestBST_InOrder():" << endl;
	cout << "Top number must match bottom number to pass" << endl;
	tree.InOrder(tree.TestVisit);
	cout << endl;
	int array[12] = { 5, 10, 11, 12, 15, 18, 19, 20, 22, 23, 25, 30 };
	for (int i = 0; i < 12; ++i)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}
void testBST_PreOrder()
{
	cout << "\ntestBST_PreOrder():" << endl;
	cout << "Top number must match bottom number to pass" << endl;
	tree.PreOrder(tree.TestVisit);
	cout << endl;
	int array[12] = { 15, 10, 5, 12, 11, 20, 18, 19, 25, 23, 22, 30 };
	for (int i = 0; i < 12; ++i)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}
void testBST_PostOrder()
{
	cout << "\ntestBST_PostOrder():" << endl;
	cout << "Top number must match bottom number to pass" << endl;
	tree.PostOrder(tree.TestVisit);
	cout << endl;
	int array[12] = { 5, 11, 12, 10, 19, 18, 22, 23, 30, 25, 20, 15 };
	for (int i = 0; i < 12; ++i)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}
void testBST_BreadthFirst()
{
	cout << "\ntestBST_BreadthFirst():" << endl;
	cout << "Top number must match bottom number to pass" << endl;
	tree.BreadthFirst(tree.TestVisit);
	cout << endl;
	int array[12] = { 15, 10, 20, 5, 12, 18, 25, 11, 19, 23, 30, 22 };
	for (int i = 0; i < 12; ++i)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

//
//mutators
//

void testBST_Insert()
{
    BST<int> tree1;
    tree1.Insert(1);
    tree1.Insert(2);
    tree1.Insert(3);
    tree1.Insert(4);
    tree1.Insert(5);
    BST<int> tree2;
    tree2.Insert(3);
    tree2.Insert(2);
    tree2.Insert(4);
    tree2.Insert(1);
    tree2.Insert(5);
    bool pass = tree1.Height() == 5 && tree2.Height() == 3;
    display(pass, "testBST_Insert()");
}

void testBST_Delete()
{
    BST<int> tree;
    tree.Insert(5);
    tree.Delete(5);
    bool pass = tree.Height() == 0;
    display(pass, "testBST_Delete()");
}

void testBST_Purge()
{
    BST<int> tree;
    tree.Insert(5);
    tree.Purge();
    bool pass = tree.Height() == 0;
    display(pass, "testBST_Purge()");
}

#endif // DRIVER_H


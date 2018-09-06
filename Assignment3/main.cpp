/*********************************************************************************************************
* Author:                   Aaron Day
* Date Created:             10/16/2015
* Last Modification Date:   10/21/2015
* Assignment Number:        3
* Filename:                 main.cpp
*
* Overview:     Runs all of the tests for the Node, Iterator, and LinkedList classes stored in the
*               driver.h file
* Output:       Outputs to the screen the result of all of the tests
 *********************************************************************************************************/
#include <iostream>
#include "node.h"
#include "iterator.h"
#include "linkedlist.h"
#include "driver.h"

using namespace std;

int main()
{
    //
    //Test Node
    //

    cout << "\nTESTING NODE CLASS\n" << endl;

    //constructors
    testNode_ctor();
    testNode_cctor();

    cout << endl;

    //accessors
    testNode_getData();
    testNode_getNext();
    testNode_getPrev();
    testNode_isNextNull();
    testNode_isPrevNull();

    cout << endl;

    //mutators
    testNode_equal_oper();
    testNode_setData();
    testNode_setNext();
    testNode_setPrev();

    //
    //Test Iterator
    //

    cout << "\nTESTING ITERATOR CLASS\n" << endl;

    //constructors
    testIterator_ctor();
    testIterator_cctor();

    cout << endl;

    //accessors
    testIterator_getNode();
    testIterator_deref_oper();

    cout << endl;

    //mutators
    testIterator_equal_oper();
    testIterator_add_prefix_oper();
    testIterator_add_postfix_oper();
    testIterator_sub_prefix_oper();
    testIterator_sub_postfix_oper();

    //
    //Test LinkedList
    //

    cout << "\nTESTING LINKEDLIST CLASS\n" << endl;

    //constructors
    testLinkedList_ctor();
    testLinkedList_cctor();

    cout << endl;

    //accessors
    testLinkedList_isEmpty();
    testLinkedList_Begin();
    testLinkedList_End();
    testLinkedList_Empty();

    cout << endl;

    //mutators
    testLinkedList_equal_oper();
    testLinkedList_First();
    testLinkedList_Last();
    testLinkedList_Prepend();
    testLinkedList_Append();
    testLinkedList_Purge();
    testLinkedList_Extract();
    testLinkedList_InsertAfter();
    testLinkedList_InsertBefore();

    cout << endl;

    return 0;
}


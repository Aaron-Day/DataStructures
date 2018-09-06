/*********************************************************************************************************
* Author:                   Aaron Day
* Date Created:             10/21/2015
* Last Modification Date:   11/01/2015
* Assignment Number:        5
* Filename:                 main.cpp
*
* Overview:     Runs all of the tests for the Queue and CQueue classes stored in the driver.h file
*
* Output:       Outputs to the screen the result of all of the tests
 *********************************************************************************************************/
#include <iostream>
#include "queue.h"
#include "driver.h"

using namespace std;

int main()
{
    //
    //Test Queue
    //

    cout << "\nTESTING QUEUE CLASS\n" << endl;

    //constructors
    testQueue_ctor();
    testQueue_cctor();

    cout << endl;

    //accessors
    testQueue_Front();
    testQueue_Size();
    testQueue_isEmpty();
    testQueue_isFull();

    cout << endl;

    //mutators
    testQueue_equal_oper();
    testQueue_Enqueue();
    testQueue_Dequeue();

    cout << endl;

    //
    //Test Circular Queue
    //

    cout << "\nTESTING CQUEUE CLASS\n" << endl;

    //constructors
    testCQueue_ctor();
    testCQueue_cctor();

    cout << endl;

    //accessors
    testCQueue_Front();
    testCQueue_Size();
    testCQueue_isEmpty();
    testCQueue_isFull();

    cout << endl;

    //mutators
    testCQueue_equal_oper();
    testCQueue_Enqueue();
    testCQueue_Dequeue();

    cout << endl;


    return 0;
}


/*********************************************************************************************************
* Author:                   Aaron Day
* Date Created:             10/21/2015
* Last Modification Date:   10/21/2015
* Assignment Number:        4
* Filename:                 main.cpp
*
* Overview:     Runs all of the tests for the Stack class stored in the driver.h file
*
* Output:       Outputs to the screen the result of all of the tests
 *********************************************************************************************************/
#include <iostream>
#include "stack.h"
#include "driver.h"

using namespace std;

int main()
{
    //
    //Test Stack
    //

    cout << "\nTESTING STACK CLASS\n" << endl;

    //constructors
    testStack_ctor();
    testStack_cctor();

    cout << endl;

    //accessors
    testStack_Peek();
    testStack_Size();
    testStack_isEmpty();
    testStack_isFull();

    cout << endl;

    //mutators
    testStack_equal_oper();
    testStack_Push();
    testStack_Pop();

    cout << endl;


    return 0;
}


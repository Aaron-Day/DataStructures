/*********************************************************************************************************
* Author:                   Aaron Day
* Date Created:             10/21/2015
* Last Modification Date:   10/21/2015
* Assignment Number:        4
* Filename:                 driver.h
*
* Overview:     Used for testing the Stack class
 *********************************************************************************************************/
#ifndef DRIVER_H
#define DRIVER_H

#include <string>
#include "stack.h"

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
//constructors
//

void testStack_ctor()
{
    Stack<int> stk(3);
    stk.Push(2);
    bool pass = stk.Peek() == 2;
    display(pass, "testStack_ctor()");
}
void testStack_cctor()
{
    Stack<int> stk(3);
    stk.Push(2);
    Stack<int> cpy(stk);
    bool pass = cpy.Peek() == 2;
    display(pass, "testStack_cctor()");
}

//
//accessors
//

void testStack_Peek()
{
    Stack<int> stk(3);
    stk.Push(2);
    bool pass = stk.Peek() == 2;
    display(pass, "testStack_Peek()");
}
void testStack_Size()
{
    Stack<int> stk(3);
    int size1 = stk.Size();
    stk.Push(2);
    int size2 = stk.Size();
    bool pass = size1 == 0 && size2 == 1;
    display(pass, "testStack_Size()");
}
void testStack_isEmpty()
{
    Stack<int> stk(3);
    bool pass = stk.isEmpty();
    display(pass, "testStack_isEmpty()");
}
void testStack_isFull()
{
    Stack<int> stk(3);
    stk.Push(2);
    stk.Push(1);
    stk.Push(1);
    bool pass = stk.isFull();
    display(pass, "testStack_isFull()");
}

//
//mutators
//

void testStack_equal_oper()
{
    Stack<int> stk(3);
    stk.Push(2);
    Stack<int> equal(1);
    equal = stk;
    bool pass = equal.Peek() == 2;
    display(pass, "testStack_equal_oper()");
}
void testStack_Push()
{
    Stack<int> stk(3);
    stk.Push(2);
    bool pass = stk.Peek() == 2;
    display(pass, "testStack_Push()");
}
void testStack_Pop()
{
    Stack<int> stk(3);
    stk.Push(2);
    bool pass = stk.Pop() == 2 && stk.isEmpty();
    display(pass, "testStack_Pop()");
}

#endif // DRIVER_H

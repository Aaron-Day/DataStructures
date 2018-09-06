/*********************************************************************************************************
* Author:                   Aaron Day
* Date Created:             10/30/2015
* Last Modification Date:   11/01/2015
* Assignment Number:        5
* Filename:                 driver.h
*
* Overview:     Used for testing the Queue and CQueue classes
 *********************************************************************************************************/
#ifndef DRIVER_H
#define DRIVER_H

#include <string>
#include "queue.h"
#include "cqueue.h"

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
//Queue Tests
//

void testQueue_ctor()
{
    Queue<int> que(5);
    bool pass = que.Size() == 0;
    display(pass, "testQueue_ctor()");
}
void testQueue_cctor()
{
    Queue<int> que(3);
    que.Enqueue(2);
    Queue<int> cpy(que);
    bool pass = cpy.Front() == 2;
    display(pass, "testQueue_cctor()");
}

//
//accessors
//
void testQueue_Front()
{
    Queue<int> que(3);
    que.Enqueue(2);
    bool pass = que.Front() == 2;
    display(pass, "testQueue_Front()");
}
void testQueue_Size()
{
    Queue<int> que(3);
    int size1 = que.Size();
    que.Enqueue(2);
    int size2 = que.Size();
    bool pass = size1 == 0 && size2 == 1;
    display(pass, "testQueue_Size()");
}
void testQueue_isEmpty()
{
    Queue<int> que(3);
    bool pass = que.isEmpty();
    display(pass, "testQueue_isEmpty()");
}
void testQueue_isFull()
{
    Queue<int> que(3);
    que.Enqueue(2);
    que.Enqueue(1);
    que.Enqueue(1);
    bool pass = que.isFull();
    display(pass, "testQueue_isFull()");
}

//
//mutators
//

void testQueue_equal_oper()
{
    Queue<int> que(3);
    que.Enqueue(2);
    Queue<int> equal(1);
    equal = que;
    bool pass = equal.Front() == 2;
    display(pass, "testQueue_equal_oper()");
}
void testQueue_Enqueue()
{
    Queue<int> que(3);
    que.Enqueue(2);
    bool pass = que.Front() == 2;
    display(pass, "testQueue_Enqueue()");
}
void testQueue_Dequeue()
{
    Queue<int> que(3);
    que.Enqueue(2);
    bool pass = que.Dequeue() == 2 && que.isEmpty();
    display(pass, "testQueue_Dequeue()");
}

//
//Circular Queue Tests
//

void testCQueue_ctor()
{
    CQueue<int> myCQueue(5);
    bool pass = myCQueue.Size() == 0;
    display(pass, "testCQueue_ctor()");
}
void testCQueue_cctor()
{
    CQueue<int> que(3);
    que.Enqueue(2);
    CQueue<int> cpy(que);
    bool pass = cpy.Front() == 2;
    display(pass, "testCQueue_cctor()");
}

//
//accessors
//
void testCQueue_Front()
{
    CQueue<int> que(3);
    que.Enqueue(2);
    bool pass = que.Front() == 2;
    display(pass, "testCQueue_Front()");
}
void testCQueue_Size()
{
    CQueue<int> que(3);
    int size1 = que.Size();
    que.Enqueue(2);
    int size2 = que.Size();
    bool pass = size1 == 0 && size2 == 1;
    display(pass, "testCQueue_Size()");
}
void testCQueue_isEmpty()
{
    CQueue<int> que(3);
    bool pass = que.isEmpty();
    display(pass, "testCQueue_isEmpty()");
}
void testCQueue_isFull()
{
    CQueue<int> que(3);
    que.Enqueue(2);
    que.Enqueue(1);
    que.Enqueue(1);
    bool pass = que.isFull();
    display(pass, "testCQueue_isFull()");
}

//
//mutators
//

void testCQueue_equal_oper()
{
    CQueue<int> que(3);
    que.Enqueue(2);
    CQueue<int> equal(1);
    equal = que;
    bool pass = equal.Front() == 2;
    display(pass, "testCQueue_equal_oper()");
}
void testCQueue_Enqueue()
{
    CQueue<int> que(3);
    que.Enqueue(2);
    bool pass = que.Front() == 2;
    display(pass, "testCQueue_Enqueue()");
}
void testCQueue_Dequeue()
{
    CQueue<int> que(3);
    que.Enqueue(1);
    que.Enqueue(2);
    que.Enqueue(3);
    bool pass = que.isFull() == true && que.Dequeue() == 1 && que.Front() == 2 && que.isFull() == false;
    display(pass, "testCQueue_Dequeue()");
}

#endif // DRIVER_H


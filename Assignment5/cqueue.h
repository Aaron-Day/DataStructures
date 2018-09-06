/*********************************************************************************************************
* Author:                   Aaron Day
* Date Created:             10/21/2015
* Last Modification Date:   11/01/2015
* Assignment Number:        5
* Filename:                 cqueue.h
*
* Overview:     Interface for Array class to use it like a circular queue (cqueue)
*
* Input:        Desired capacity of the queue
*
* Output:       Output is provided through the Front and Dequeue functions
 *********************************************************************************************************/
#ifndef CQUEUE_H
#define CQUEUE_H

#include "array.h"
#include "exception.h"

/*********************************************************************************************************
 * Class: CQueue
 *
 * Constructors/Destructors:
 *      CQueue(int capacity)
 *              1 arg constructor, creates a cqueue with a defined capacity
 *      CQueue(const CQueue& copy)
 *              Copy constructor, creates a new cqueue and copies all the data from the given array.
 *              The array's copy constructor is called to appropriately manage memory
 *      ~CQueue()
 *              The array's destructor is called automatically when this object is destroyed to
 *              appropriately manage memory
 *
 * Accessors:
 *      T& Front()
 *              Returns, by reference, the first element in the cqueue but does not remove it
 *      int Size() const
 *              Returns the number of items currently on the cqueue
 *      bool isEmpty() const
 *              Returns true if the cqueue is empty
 *      bool isFull() const
 *              Returns true if the cqueue is full
 *
 * Mutators:
 *      CQueue& operator=(const CQueue& rhs)
 *              Empties the cqueue and turns it into a copy of another cqueue
 *      void Enqueue(T data)
 *              Pushes its parameter onto the back of the cqueue
 *      T Dequeue()
 *              Removes and returns the data from the front of the cqueue
 *********************************************************************************************************/

template<typename T>
class CQueue
{
public:
    //constructor
    CQueue(int capacity);
    CQueue(const CQueue& copy);
    ~CQueue();

    //accessors
    T& Front();
    int Size() const;
    bool isEmpty() const;
    bool isFull() const;

    //mutators
    CQueue& operator=(const CQueue& rhs);
    void Enqueue(T data);
    T Dequeue();

private:
    Array<T> m_cqueue;      //circular queue (cqueue)
    int m_size;             //size of the cqueue
    int m_capacity;         //capacity of the cqueue
};

#include "cqueue.inc"

#endif // CQUEUE_H

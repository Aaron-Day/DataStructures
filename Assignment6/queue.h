/*********************************************************************************************************
* Author:                   Aaron Day
* Date Created:             10/21/2015
* Last Modification Date:   11/01/2015
* Assignment Number:        5
* Filename:                 queue.h
*
* Overview:     Interface for LinkedList class to use it like an array class
*
* Input:        Input is used to create custom error messages that can be thrown when an exception
*               criteria is met within a try/catch block
*
* Output:       Output stream with error message as a char array
 *********************************************************************************************************/
#ifndef QUEUE_H
#define QUEUE_H

#include "linkedlist.h"
#include "exception.h"

/*********************************************************************************************************
 * Class: Queue
 *
 * Constructors/Destructors:
 *      Queue(int capacity)
 *              1 arg constructor, creates a queue with a defined capacity
 *      Queue(const Queue& copy)
 *              Copy constructor, creates a new queue and copies all the data from the given array.
 *              The array's copy constructor is called to appropriately manage memory
 *      ~Queue()
 *              The array's destructor is called automatically when this object is destroyed to
 *              appropriately manage memory
 *
 * Accessors:
 *      T& Front()
 *              Returns, by reference, the first element in the queue but does not remove it
 *      int Size() const
 *              Returns the number of items currently on the queue
 *      bool isEmpty() const
 *              Returns true if the queue is empty
 *      bool isFull() const
 *              Returns true if the queue is full
 *
 * Mutators:
 *      Queue& operator=(const Queue& rhs)
 *              Empties the queue and turns it into a copy of another queue
 *      void Enqueue(T data)
 *              Pushes its parameter onto the back of the queue
 *      T Dequeue()
 *              Removes and returns the data from the front of the queue
 *********************************************************************************************************/

template<typename T>
class Queue
{
public:
    //constructor
    Queue(int capacity);
    Queue(const Queue& copy);
    ~Queue();

    //accessors
    T& Front();
    int Size() const;
    bool isEmpty() const;
    bool isFull() const;

    //mutators
    Queue& operator=(const Queue& rhs);
    void Enqueue(T data);
    T Dequeue();

private:
    LinkedList<T> m_queue;  //queue
    int m_size;             //size of the queue
    int m_capacity;         //capacity of the queue
};

#include "queue.inc"

#endif // QUEUE_H

/*********************************************************************************************************
* Author:                   Aaron Day
* Date Created:             10/21/2015
* Last Modification Date:   10/21/2015
* Assignment Number:        4
* Filename:                 stack.h
*
* Overview:     Interface for LinkedList class to use it like an array class
*
* Input:        Input is used to create custom error messages that can be thrown when an exception
*               criteria is met within a try/catch block
*
* Output:       Output stream with error message as a char array
 *********************************************************************************************************/
#ifndef STACK_H
#define STACK_H

#include "linkedlist.h"
#include "exception.h"

/*********************************************************************************************************
 * Class: Stack
 *
 * Constructors/Destructors:
 *      Stack(int capacity)
 *              1 arg constructor, creates a stack with a defined capacity
 *      Stack(const Stack& copy)
 *              Copy constructor, creates a new stack and copies all the data from the template into it
 *      ~Stack()
 *              Destructor, frees memory when the stack is destroyed
 *
 * Accessors:
 *      T Peek() const
 *              Returns the element on the top of the stack but does not remove it
 *      int Size() const
 *              Returns the number of items currently on the stack
 *      bool isEmpty() const
 *              Returns true if the stack is empty
 *      bool isFull() const
 *              Returns true if the stack is full
 *
 * Mutators:
 *      Stack& operator=(const Stack& rhs)
 *              Purges the current list and fills it with data from the rhs
 *      void Push(T data)
 *              Pushes its parameter onto the top of the stack
 *      T Pop()
 *              Removes and returns the data from the top of the stack
 *********************************************************************************************************/

template<typename T>
class Stack : LinkedList<T>
{
public:
    //constructor
    Stack(int capacity);
    Stack(const Stack& copy);
    ~Stack();

    //accessors
    T Peek() const;
    int Size() const;
    bool isEmpty() const;
    bool isFull() const;
    Iterator<T> Begin() const;
    Iterator<T> End() const;
    Iterator<T> Empty() const;

    //mutators
    Stack& operator=(const Stack& rhs);
    void Push(T data);
    T Pop();

private:
    LinkedList<T> m_stack;  //stack
    int m_size;             //size of the stack
    int m_capacity;         //capacity of the stack
};

#include "stack.inc"

#endif // STACK_H

/*********************************************************************************************************
* Author:                   Aaron Day
* Date Created:             10/21/2015
* Last Modification Date:   10/21/2015
* Assignment Number:        4
* Filename:                 stack.inc
 *********************************************************************************************************/
#include "stack.h"

//
//constructors
//

template<typename T>
Stack<T>::Stack(int capacity)
{
    //m_stack gets a default LinkedList constructor
    m_size = 0;
    m_capacity = capacity;
}
template<typename T>
Stack<T>::Stack(const Stack &copy)
    :m_stack(copy.m_stack), m_size(copy.m_size), m_capacity(copy.m_capacity)
{
}
template<typename T>
Stack<T>::~Stack()
{
    //not managing memory, other classes are and they have their own destructors
}

//
//accessors
//

/*********************************************************************************************************
 * template<typename T>
 * T Stack<T>::Peek() const
 *
 *  Purpose:    Returns the element on the top of the stack but does not remove it
 *
 *  Entry:      No entry
 *
 *  Exit:       Returns the element on the top of the stack
 *********************************************************************************************************/
template<typename T>
T Stack<T>::Peek() const
{
    return m_stack.Last().getData();
}
/*********************************************************************************************************
 * template<typename T>
 * int Stack<T>::Size() const
 *
 *  Purpose:    Get the current size of the stack
 *
 *  Entry:      No entry
 *
 *  Exit:       Returns m_size
 *********************************************************************************************************/
template<typename T>
int Stack<T>::Size() const
{
    return m_size;
}
/*********************************************************************************************************
 * template<typename T>
 * bool Stack<T>::isEmpty() const
 *
 *  Purpose:    Check if the stack is empty
 *
 *  Entry:      No entry
 *
 *  Exit:       Returns true if the size equals 0
 *********************************************************************************************************/
template<typename T>
bool Stack<T>::isEmpty() const
{
    return m_size == 0;
}
/*********************************************************************************************************
 * template<typename T>
 * bool Stack<T>::isFull() const
 *
 *  Purpose:    Check if the stack is full
 *
 *  Entry:      No entry
 *
 *  Exit:       Returns true if the size equals the capacity
 *********************************************************************************************************/
template<typename T>
bool Stack<T>::isFull() const
{
    return m_size == m_capacity;
}

//
//mutators
//

/*********************************************************************************************************
 * template<typename T>
 * Stack& Stack<T>::operator=(const Stack& rhs)
 *
 *  Purpose:    Pushes its parameter onto the top of the stack
 *
 *  Entry:      Data to add to the top of the stack
 *
 *  Exit:       Both stacks now contain the same data
 *********************************************************************************************************/
template<typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& rhs)
{
    m_stack = rhs.m_stack; //calls the LinkedList equal operator
    m_size = rhs.m_size;
    m_capacity = rhs.m_capacity;
    return *this;
}
/*********************************************************************************************************
 * template<typename T>
 * void Stack<T>::Push(T data)
 *
 *  Purpose:    Pushes its parameter onto the top of the stack
 *
 *  Entry:      Data to add to the top of the stack
 *
 *  Exit:       Data is added to the top of the stack and the size is increased
 *********************************************************************************************************/
template<typename T>
void Stack<T>::Push(T data)
{
    if(isFull())
    {
        char msg[] = "Error: stack full";
        throw Exception(msg);
    }
    else
    {
        m_stack.Append(data);
        ++m_size;
    }
}
/*********************************************************************************************************
 * template<typename T>
 * T Stack<T>::Pop()
 *
 *  Purpose:    Removes and returns the data from the top of the stack
 *
 *  Entry:      No entry
 *
 *  Exit:       Returns the data from the top of the stack
 *********************************************************************************************************/
template<typename T>
T Stack<T>::Pop()
{
    if(isEmpty())
    {
        char msg[] = "Error: stack empty";
        throw Exception(msg);
    }
    else
    {
        --m_size;
        return m_stack.Extract(*(m_stack.End())).getData();
    }
}

/*********************************************************************************************************
* Author:                   Aaron Day
* Date Created:             10/21/2015
* Last Modification Date:   11/01/2015
* Assignment Number:        5
* Filename:                 queue.inc
 *********************************************************************************************************/
#include "queue.h"

//
//constructors
//

/*********************************************************************************************************
 * template<typename T>
 * Queue<T>::Queue(int capacity)
 *
 *  Purpose:    Create a new queue  with a given capacity
 *
 *  Entry:      Capacity of new queue
 *
 *  Exit:       Created a new empty queue with the given capacity
 *********************************************************************************************************/
template<typename T>
Queue<T>::Queue(int capacity)
{
    //m_queue gets a default LinkedList constructor
    m_size = 0;
    m_capacity = capacity;
}
/*********************************************************************************************************
 * template<typename T>
 * Queue<T>::Queue(const Queue &copy)
 *
 *  Purpose:    Create a new queue with the same data as an existing queue
 *
 *  Entry:      Queue to copy
 *
 *  Exit:       Created a new queue identical to the passed queue
 *********************************************************************************************************/
template<typename T>
Queue<T>::Queue(const Queue &copy)
    :m_queue(copy.m_queue), m_size(copy.m_size), m_capacity(copy.m_capacity)
{
}
/*********************************************************************************************************
 * template<typename T>
 * Queue<T>::~Queue()
 *
 *  Purpose:    Safely destruct a queue
 *
 *  Entry:      No entry
 *
 *  Exit:       Frees memory allocated by the linked list. Calls the linked list destructor automatically
 *              to do this
 *********************************************************************************************************/
template<typename T>
Queue<T>::~Queue()
{
    //not managing memory, other classes are and they have their own destructors
}

//
//accessors
//

/*********************************************************************************************************
 * template<typename T>
 * T& Queue<T>::Front() const
 *
 *  Purpose:    Returns a reference to the element at the front of the queue but does not remove it
 *
 *  Entry:      No entry
 *
 *  Exit:       Returns the element at the front of the queue
 *********************************************************************************************************/
template<typename T>
T& Queue<T>::Front()
{
    return *m_queue.Begin();
}
/*********************************************************************************************************
 * template<typename T>
 * int Queue<T>::Size() const
 *
 *  Purpose:    Get the current size of the queue
 *
 *  Entry:      No entry
 *
 *  Exit:       Returns m_size
 *********************************************************************************************************/
template<typename T>
int Queue<T>::Size() const
{
    return m_size;
}
/*********************************************************************************************************
 * template<typename T>
 * bool Queue<T>::isEmpty() const
 *
 *  Purpose:    Check if the queue is empty
 *
 *  Entry:      No entry
 *
 *  Exit:       Returns true if the size equals 0
 *********************************************************************************************************/
template<typename T>
bool Queue<T>::isEmpty() const
{
    return m_size == 0;
}
/*********************************************************************************************************
 * template<typename T>
 * bool Queue<T>::isFull() const
 *
 *  Purpose:    Check if the queue is full
 *
 *  Entry:      No entry
 *
 *  Exit:       Returns true if the size equals the capacity
 *********************************************************************************************************/
template<typename T>
bool Queue<T>::isFull() const
{
    return m_size == m_capacity;
}

//
//mutators
//

/*********************************************************************************************************
 * template<typename T>
 * Queue& Queue<T>::operator=(const Queue& rhs)
 *
 *  Purpose:    Empties the queue and makes it a copy of another existing queue
 *
 *  Entry:      Queue to copy
 *
 *  Exit:       Both queues now contain the same data
 *********************************************************************************************************/
template<typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& rhs)
{
    m_queue = rhs.m_queue; //calls the LinkedList equal operator
    m_size = rhs.m_size;
    m_capacity = rhs.m_capacity;
    return *this;
}
/*********************************************************************************************************
 * template<typename T>
 * void Queue<T>::Push(T data)
 *
 *  Purpose:    Pushes its parameter onto the back of the queue
 *
 *  Entry:      Data to add to the back of the queue
 *
 *  Exit:       Data is added to the back of the queue and the size is increased
 *********************************************************************************************************/
template<typename T>
void Queue<T>::Enqueue(T data)
{
    if(isFull())
    {
        char msg[] = "Error: queue full";
        throw Exception(msg);
    }
    else
    {
        m_queue.Append(data);
        ++m_size;
    }
}
/*********************************************************************************************************
 * template<typename T>
 * T Queue<T>::Dequeue()
 *
 *  Purpose:    Removes and returns the data from the front of the queue
 *
 *  Entry:      No entry
 *
 *  Exit:       Returns the data from the front of the queue
 *********************************************************************************************************/
template<typename T>
T Queue<T>::Dequeue()
{
    if(isEmpty())
    {
        char msg[] = "Error: queue empty";
        throw Exception(msg);
    }
    else
    {
        --m_size;
        return m_queue.Extract(*(m_queue.Begin())).getData();
    }
}

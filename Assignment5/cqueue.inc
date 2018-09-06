/*********************************************************************************************************
* Author:                   Aaron Day
* Date Created:             10/21/2015
* Last Modification Date:   11/01/2015
* Assignment Number:        5
* Filename:                 cqueue.inc
 *********************************************************************************************************/
#include "cqueue.h"

//
//constructors
//

/*********************************************************************************************************
 * template<typename T>
 * CQueue<T>::CQueue(int capacity)
 *
 *  Purpose:    Create a new circular queue (cqueue) with a given capacity
 *
 *  Entry:      Capacity of new cqueue
 *
 *  Exit:       Created a new empty cqueue with the given capacity
 *********************************************************************************************************/
template<typename T>
CQueue<T>::CQueue(int capacity)
    :m_cqueue(capacity)
{
    m_size = 0;
    m_capacity = capacity;
}
/*********************************************************************************************************
 * template<typename T>
 * CQueue<T>::CQueue(const CQueue &copy)
 *
 *  Purpose:    Create a new cqueue with the same data as an existing cqueue
 *
 *  Entry:      CQueue to copy
 *
 *  Exit:       Created a new cqueue identical to the passed cqueue
 *********************************************************************************************************/
template<typename T>
CQueue<T>::CQueue(const CQueue &copy)
    :m_cqueue(copy.m_cqueue), m_size(copy.m_size), m_capacity(copy.m_capacity)
{
}
/*********************************************************************************************************
 * template<typename T>
 * CQueue<T>::~CQueue()
 *
 *  Purpose:    Safely destruct a cqueue
 *
 *  Entry:      No entry
 *
 *  Exit:       Frees memory allocated to store the array. Calls the array destructor automatically
 *              to do this
 *********************************************************************************************************/
template<typename T>
CQueue<T>::~CQueue()
{
    //not managing memory, other classes are and they have their own destructors
}

//
//accessors
//

/*********************************************************************************************************
 * template<typename T>
 * T& CQueue<T>::Front() const
 *
 *  Purpose:    Returns a reference to the element at the front of the cqueue but does not remove it
 *
 *  Entry:      No entry
 *
 *  Exit:       Returns the element at the front of the cqueue
 *********************************************************************************************************/
template<typename T>
T& CQueue<T>::Front()
{
    return m_cqueue[0];
}
/*********************************************************************************************************
 * template<typename T>
 * int CQueue<T>::Size() const
 *
 *  Purpose:    Get the current size of the cqueue
 *
 *  Entry:      No entry
 *
 *  Exit:       Returns the size of the cqueue
 *********************************************************************************************************/
template<typename T>
int CQueue<T>::Size() const
{
    return m_size;
}
/*********************************************************************************************************
 * template<typename T>
 * bool CQueue<T>::isEmpty() const
 *
 *  Purpose:    Check if the cqueue is empty
 *
 *  Entry:      No entry
 *
 *  Exit:       Returns true if the size ecquals 0
 *********************************************************************************************************/
template<typename T>
bool CQueue<T>::isEmpty() const
{
    return m_size == 0;
}
/*********************************************************************************************************
 * template<typename T>
 * bool CQueue<T>::isFull() const
 *
 *  Purpose:    Check if the cqueue is full
 *
 *  Entry:      No entry
 *
 *  Exit:       Returns true if the size ecquals the capacity
 *********************************************************************************************************/
template<typename T>
bool CQueue<T>::isFull() const
{
    return m_size == m_capacity;
}

//
//mutators
//

/*********************************************************************************************************
 * template<typename T>
 * CQueue& CQueue<T>::operator=(const CQueue& rhs)
 *
 *  Purpose:    Empty the cque and make it an exact copy of another existing cqueue
 *
 *  Entry:      CQueue to copy
 *
 *  Exit:       The cqueue is now identical to the passed cqueue
 *********************************************************************************************************/
template<typename T>
CQueue<T>& CQueue<T>::operator=(const CQueue<T>& rhs)
{
    m_cqueue = rhs.m_cqueue; //calls the Array ecqual operator
    m_size = rhs.m_size;
    m_capacity = rhs.m_capacity;
    return *this;
}
/*********************************************************************************************************
 * template<typename T>
 * void CQueue<T>::Enqueue(T data)
 *
 *  Purpose:    Pushes its parameter onto the back of the cqueue
 *
 *  Entry:      Data to add to the back of the cqueue
 *
 *  Exit:       Data is added to the back of the cqueue and the size is increased
 *********************************************************************************************************/
template<typename T>
void CQueue<T>::Enqueue(T data)
{
    if(isFull())
    {
        char msg[] = "Error: cqueue full";
        throw Exception(msg);
    }
    else
    {
        m_cqueue[m_size++] = data;
    }
}
/*********************************************************************************************************
 * template<typename T>
 * T CQueue<T>::Decqueue()
 *
 *  Purpose:    Removes and returns the data from the front of the cqueue
 *
 *  Entry:      No entry
 *
 *  Exit:       Returns the data from the front of the cqueue and the size is decreased
 *********************************************************************************************************/
template<typename T>
T CQueue<T>::Dequeue()
{
    if(isEmpty())
    {
        char msg[] = "Error: cqueue empty";
        throw Exception(msg);
    }
    else
    {
        T temp = m_cqueue[0];
        m_cqueue.setStartIndex(m_cqueue.getStartIndex() + 1);
        --m_size;
        return temp;
    }
}

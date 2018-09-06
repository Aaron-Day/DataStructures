/*********************************************************************************************************
* Author:                   Aaron Day
* Date Created:             10/16/2015
* Last Modification Date:   11/01/2015
* Assignment Number:        5
* Filename:                 node.inc
 *********************************************************************************************************/
#include "node.h"

//
//constructors
//

/*********************************************************************************************************
 * template<typename T>
 * Node<T>::Node(T data)
 *
 *  Purpose:    Create a new node with the given data
 *
 *  Entry:      Data of node
 *
 *  Exit:       Created a new node with the given data
 *********************************************************************************************************/
template<typename T>
Node<T>::Node(T data)
    :m_data(data)
{
    m_next = nullptr;
    m_prev = nullptr;
}
/*********************************************************************************************************
 * template<typename T>
 * Node<T>::Node(const Node& copy)
 *
 *  Purpose:    Create a new node with the same data as an existing node
 *
 *  Entry:      Node containing desired data
 *
 *  Exit:       Created a new node with the same data as the give node. New node is not assigned to an
 *              existing linked list so the pointers are null to prevent duplicating pointers to the same
 *              object
 *********************************************************************************************************/
template<typename T>
Node<T>::Node(const Node& copy)
    :m_data(copy.m_data)
{
    m_next = nullptr; //nulls the pointers so there are not multiple pointers to the same object
    m_prev = nullptr;
}
/*********************************************************************************************************
 * template<typename T>
 * Node<T>::~Node()
 *
 *  Purpose:    Safely destruct a node
 *
 *  Entry:      No entry
 *
 *  Exit:       Nulls the pointers to protect them when object is deleted
 *********************************************************************************************************/
template<typename T>
Node<T>::~Node()
{
    m_next = nullptr; //nulls the pointers prior to deletion so the other nodes remain safe
    m_prev = nullptr;
}

//
//accessors
//

/*********************************************************************************************************
 * template<typename T>
 * T& Node<T>::getData()
 *
 *  Purpose:    Get a reference to the value of m_data
 *
 *  Entry:      No entry
 *
 *  Exit:       Returns the value of the data in current node
 *********************************************************************************************************/
template<typename T>
T& Node<T>::getData()
{
    return m_data;
}
/*********************************************************************************************************
 * template<typename T>
 * T* Node<T>::getDataPtr() const
 *
 *  Purpose:    Get a pointer to the value of m_data
 *
 *  Entry:      No entry
 *
 *  Exit:       Returns a pointer to the value of the data in current node
 *********************************************************************************************************/
template<typename T>
T* Node<T>::getDataPtr() const
{
    return &m_data;
}
/*********************************************************************************************************
 * template<typename T>
 * Node<T>* Node<T>::getCurrent()
 *
 *  Purpose:    Get a pointer to the current node
 *
 *  Entry:      No entry
 *
 *  Exit:       Returns pointer to current node
 *********************************************************************************************************/
template<typename T>
Node<T>* Node<T>::getCurrent()
{
    return this;
}
/*********************************************************************************************************
 * template<typename T>
 * Node<T>* Node<T>::getNext() const
 *
 *  Purpose:    Get the pointer stored in m_next
 *
 *  Entry:      No entry
 *
 *  Exit:       Returns pointer to next node
 *********************************************************************************************************/
template<typename T>
Node<T>* Node<T>::getNext() const
{
    return m_next;
}
/*********************************************************************************************************
 * template<typename T>
 * Node<T>* Node<T>::getPrev() const
 *
 *  Purpose:    Get the pointer stored in m_prev
 *
 *  Entry:      No entry
 *
 *  Exit:       Returns pointer to previous node
 *********************************************************************************************************/
template<typename T>
Node<T>* Node<T>::getPrev() const
{
    return m_prev;
}
/*********************************************************************************************************
 * template<typename T>
 * bool Node<T>::isNextNull() const
 *
 *  Purpose:    Checks if m_next is null
 *
 *  Entry:      No entry
 *
 *  Exit:       Returns true or false
 *********************************************************************************************************/
template<typename T>
bool Node<T>::isNextNull() const
{
    return m_next == nullptr;
}
/*********************************************************************************************************
 * template<typename T>
 * bool Node<T>::isPrevNull() const
 *
 *  Purpose:    Checks if m_prev is null
 *
 *  Entry:      No entry
 *
 *  Exit:       Returns true or false
 *********************************************************************************************************/
template<typename T>
bool Node<T>::isPrevNull() const
{
    return m_prev == nullptr;
}

//
//mutators
//

/*********************************************************************************************************
 * template<typename T>
 * Node<T>& Node<T>::operator=(const Node<T>& rhs)
 *
 *  Purpose:    Sets the data in one node equal to the data in another node
 *
 *  Entry:      rhs is the node that has the data that you want to copy into the lhs
 *
 *  Exit:       lhs data now has the same data as the rhs
 *********************************************************************************************************/
template<typename T>
Node<T>& Node<T>::operator=(const Node<T>& rhs)
{
    m_data = rhs.m_data;
    return *this;
}
/*********************************************************************************************************
 * template<typename T>
 * void Node<T>::setData(T data)
 *
 *  Purpose:    Set m_data to a new value
 *
 *  Entry:      Value to set m_data to
 *
 *  Exit:       m_data is now set to a new value
 *********************************************************************************************************/
template<typename T>
void Node<T>::setData(T data)
{
    m_data = data;
}
/*********************************************************************************************************
 * template<typename T>
 * void Node<T>::setNext(Node* next)
 *
 *  Purpose:    Set m_next to a new pointer
 *
 *  Entry:      Pointer to set m_next to
 *
 *  Exit:       m_next is now pointed to a new pointer
 *********************************************************************************************************/
template<typename T>
void Node<T>::setNext(Node* next)
{
    m_next = next;
}
/*********************************************************************************************************
 * template<typename T>
 * void Node<T>::setPrev(Node* prev)
 *
 *  Purpose:    Set m_prev to a new pointer
 *
 *  Entry:      Pointer to set m_prev to
 *
 *  Exit:       m_prev is now pointed to a new pointer
 *********************************************************************************************************/
template<typename T>
void Node<T>::setPrev(Node* prev)
{
    m_prev = prev;
}

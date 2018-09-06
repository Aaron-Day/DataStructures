/*********************************************************************************************************
* Author:                   Aaron Day
* Date Created:             10/16/2015
* Last Modification Date:   11/01/2015
* Assignment Number:        5
* Filename:                 linkedlist.inc
 *********************************************************************************************************/
#include "linkedlist.h"

//
//constructors
//

/*********************************************************************************************************
 * template<typename T>
 * LinkedList<T>::LinkedList()
 *
 *  Purpose:    Create a new empty linked list
 *
 *  Entry:      No entry
 *
 *  Exit:       Created a new empty linked list
 *********************************************************************************************************/
template<typename T>
LinkedList<T>::LinkedList()
{
    m_head = nullptr;
    m_tail = nullptr;
}
/*********************************************************************************************************
 * template<typename T>
 * LinkedList<T>::LinkedList(const LinkedList& copy)
 *
 *  Purpose:    Create a new linked list with all the same data as an existing linked list
 *
 *  Entry:      Linked List to copy
 *
 *  Exit:       Created a new linked list with all the same data as the given linked list
 *********************************************************************************************************/
template<typename T>
LinkedList<T>::LinkedList(const LinkedList& copy)
{
    m_head = nullptr;
    m_tail = nullptr;
    for(Iterator<T> i(copy.Begin()); i.getNode() != copy.Empty().getNode(); ++i)
    {
        Append(i.getNode()->getData());
    }
}
/*********************************************************************************************************
 * template<typename T>
 * LinkedList<T>::~LinkedList()
 *
 *  Purpose:    Safely destruct a linked list
 *
 *  Entry:      No entry
 *
 *  Exit:       Purges all the nodes from the linked list and returns it to an empty linked list with
 *              null head and tail pointers which is safe when this object is destroyed
 *********************************************************************************************************/
template<typename T>
LinkedList<T>::~LinkedList()
{
    Purge();
}

//
//accessors
//

/*********************************************************************************************************
 * template<typename T>
 * bool LinkedList<T>::isEmpty() const
 *
 *  Purpose:    Check if a list is empty
 *
 *  Entry:      No entry
 *
 *  Exit:       Returns true if the head and tail pointers are null
 *********************************************************************************************************/
template<typename T>
bool LinkedList<T>::isEmpty() const
{
    return m_head == nullptr && m_tail == nullptr;
}
/*********************************************************************************************************
 * template<typename T>
 * const Node<T>& LinkedList<T>::First() const
 *
 *  Purpose:    Get the first node in the list by reference
 *
 *  Entry:      No entry
 *
 *  Exit:       Returns the first node in the list
 *********************************************************************************************************/
template<typename T>
const Node<T>& LinkedList<T>::First() const
{
    return *m_head;
}
/*********************************************************************************************************
 * template<typename T>
 * const Node<T>& LinkedList<T>::Last() const
 *
 *  Purpose:    Get the last node in the list by reference
 *
 *  Entry:      No entry
 *
 *  Exit:       Returns the last node in the list
 *********************************************************************************************************/
template<typename T>
const Node<T>& LinkedList<T>::Last() const
{
    return *m_tail;
}
/*********************************************************************************************************
 * template<typename T>
 * Iterator<T> LinkedList<T>::Begin() const
 *
 *  Purpose:    Get an iterator from the beginning of the list
 *
 *  Entry:      No entry
 *
 *  Exit:       Returns an iterator from the beginning of the list
 *********************************************************************************************************/
template<typename T>
Iterator<T> LinkedList<T>::Begin() const
{
    return Iterator<T>(m_head);
}
/*********************************************************************************************************
 * template<typename T>
 * Iterator<T> LinkedList<T>::End() const
 *
 *  Purpose:    Get an iterator from the end of the list
 *
 *  Entry:      No entry
 *
 *  Exit:       Returns an iterator from the end of the list
 *********************************************************************************************************/
template<typename T>
Iterator<T> LinkedList<T>::End() const
{
    return Iterator<T>(m_tail);
}
/*********************************************************************************************************
 * template<typename T>
 * Iterator<T> LinkedList<T>::End() const
 *
 *  Purpose:    Iterator to a null node, used as an endpoint for traversing a linked list
 *
 *  Entry:      No entry
 *
 *  Exit:       Returns an iterator to a null node
 *********************************************************************************************************/
template<typename T>
Iterator<T> LinkedList<T>::Empty() const
{
    return Iterator<T>(nullptr);
}

//
//mutators
//

/*********************************************************************************************************
 * template<typename T>
 * LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rhs)
 *
 *  Purpose:    Purge the current list then create new nodes with values equal to those from the nodes
 *              on the rhs list
 *
 *  Entry:      lhs = list to delete, rhs = list to copy into the lhs variable
 *
 *  Exit:       Each side is now a separate list with equal node values
 *********************************************************************************************************/
template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rhs)
{
    Purge();
    for(Iterator<T> i(rhs.Begin()); i.getNode() != rhs.Empty().getNode(); ++i)
    {
        Append(i.getNode()->getData());
    }
    return *this;
}
/*********************************************************************************************************
 * template<typename T>
 * void LinkedList<T>::Prepend(T* data)
 *
 *  Purpose:    Add a new node to the beginning of the list with m_data equal to the specified data
 *              reference
 *
 *  Entry:      reference to the data you wish to add
 *
 *  Exit:       New node with the specified data is added to the beginning of the list
 *********************************************************************************************************/
template<typename T>
void LinkedList<T>::Prepend(T* data)
{
    Node<T>* prepend = new Node<T>(*data);
    if(isEmpty())
    {
        m_tail = prepend;
    }
    else
    {
        m_head->setPrev(prepend);
        prepend->setNext(m_head);
    }
    m_head = prepend;
}
/*********************************************************************************************************
 * template<typename T>
 * void LinkedList<T>::Prepend(T data)
 *
 *  Purpose:    Add a new node to the beginning of the list with m_data equal to the specified data
 *
 *  Entry:      data you wish to add
 *
 *  Exit:       New node with the specified data is added to the beginning of the list
 *********************************************************************************************************/
template<typename T>
void LinkedList<T>::Prepend(T data)
{
    Node<T>* prepend = new Node<T>(data);
    if(isEmpty())
    {
        m_tail = prepend;
    }
    else
    {
        m_head->setPrev(prepend);
        prepend->setNext(m_head);
    }
    m_head = prepend;
}
/*********************************************************************************************************
 * template<typename T>
 * void LinkedList<T>::Append(T* data)
 *
 *  Purpose:    Add a new node to the end of the list with m_data equal to the specified data reference
 *
 *  Entry:      reference to the data you wish to add
 *
 *  Exit:       New node with specified data is added to the end of the list
 *********************************************************************************************************/
template<typename T>
void LinkedList<T>::Append(T* data)
{
    Node<T>* append = new Node<T>(*data);
    if(isEmpty())
    {
        m_head = append;
    }
    else
    {
        m_tail->setNext(append);
        append->setPrev(m_tail);
    }
    m_tail = append;
}
/*********************************************************************************************************
 * template<typename T>
 * void LinkedList<T>::Append(T data)
 *
 *  Purpose:    Add a new node to the end of the list with m_data equal to the specified data
 *
 *  Entry:      data you wish to add
 *
 *  Exit:       New node with specified data is added to the end of the list
 *********************************************************************************************************/
template<typename T>
void LinkedList<T>::Append(T data)
{
    Node<T>* append = new Node<T>(data);
    if(isEmpty())
    {
        m_head = append;
    }
    else
    {
        m_tail->setNext(append);
        append->setPrev(m_tail);
    }
    m_tail = append;
}
/*********************************************************************************************************
 * template<typename T>
 * void LinkedList<T>::Purge()
 *
 *  Purpose:    Delete all the nodes in a list
 *
 *  Entry:      No entry
 *
 *  Exit:       List is now empty with null pointers to head and tail
 *********************************************************************************************************/
template<typename T>
void LinkedList<T>::Purge()
{
    while(!isEmpty())       //while the list is not empty
    {
        if(m_head == m_tail && m_head != nullptr)   //if this is the last node
        {
            m_tail->setNext(nullptr);   //ensure the node pointers are null...
            m_tail->setPrev(nullptr);
            m_tail = nullptr;           //null the tail
            delete m_head;              //delete the head
            m_head = nullptr;           //set head to null so it can be reused later
        }
        else                                        //this is not the last node
        {
            Node<T>* cut = m_head;                  //duplicate pointer to head
            m_head->getNext()->setPrev(nullptr);    //set the next node's prev to null
            m_head = m_head->getNext();             //assign head to the next node
            cut->setNext(nullptr);                  //clear out the old head...
            delete cut->getNext();
            delete cut->getPrev();
            delete cut;
        }
    }
}
/*********************************************************************************************************
 * template<typename T>
 * Node<T>& LinkedList<T>::Extract(T value)
 *
 *  Purpose:    Removes a node from the list that has the specified value in m_data
 *
 *  Entry:      value = m_data value of node you want to return/remove
 *
 *  Exit:       Node is removed from the list and returned for further use.
 *********************************************************************************************************/
template<typename T>
Node<T>& LinkedList<T>::Extract(T value)
{
    for(Iterator<T> i(Begin()); i.getNode() != Empty().getNode(); ++i)
    {
        if(i.getNode()->getData() == value)     //when the node is found do this
        {
            //reassign head and tail pointers if necessary
            if(i.getNode()->isPrevNull())       //if the node is at the head
            {
                if(i.getNode()->isNextNull())       //if the node is both head and tail
                {
                    m_head = nullptr;
                    m_tail = nullptr;
                    return *(i.getNode());
                }
                else                                //node is head not tail
                {
                    m_head = i.getNode()->getNext();
                    i.getNode()->getNext()->setPrev(nullptr);
                    return *(i.getNode());
                }
            }
            else if(i.getNode()->isNextNull())  //node is only the tail
            {
                m_tail = i.getNode()->getPrev();
                i.getNode()->getPrev()->setNext(nullptr);
                return *(i.getNode());
            }
            else                                //node is in the middle (not head or tail)
            {
                i.getNode()->getPrev()->setNext(i.getNode()->getNext()); //set prev's next to this next
                i.getNode()->getNext()->setPrev(i.getNode()->getPrev()); //set next's prev to this prev
                i.getNode()->setNext(nullptr);  //clear this next ptr
                i.getNode()->setPrev(nullptr);  //clear this prev ptr
                return *(i.getNode());          //return this
            }
        }
    }
    //return empty node...should not reach this unless bad data was entered
    return *(Empty().getNode());
}
/*********************************************************************************************************
 * template<typename T>
 * void LinkedList<T>::InsertAfter(T value, T* data)
 *
 *  Purpose:    Insert data after a node with the specified value
 *
 *  Entry:      value = value of node to place new data after; data = the data you want to place behind
 *              the node
 *
 *  Exit:       New node is created after the node with the specified m_data value
 *********************************************************************************************************/
template<typename T>
void LinkedList<T>::InsertAfter(T value, T* data)
{
    bool added = false; //used to flag when the reference value is located and the data added
    for(Iterator<T> i(Begin()); i.getNode() != Empty().getNode(); ++i)
    {
        if(i.getNode()->getData() == value)
        {
            Node<T>* insert = new Node<T>(*data);
            if(m_tail == i.getNode())       //if the reference is the tail
            {
                insert->setPrev(i.getNode());
                insert->getPrev()->setNext(insert);
                m_tail = insert;
            }
            else                            //reference is at any other location
            {
                insert->setNext(i.getNode()->getNext());
                insert->setPrev(i.getNode());
                insert->getNext()->setPrev(insert);
                insert->getPrev()->setNext(insert);
            }
            added = true;
        }
    }
    //if the reference value was not found, add the new data to the end
    if(!added)
    {
        Append(data);
    }
}
/*********************************************************************************************************
 * template<typename T>
 * void LinkedList<T>::InsertBefore(T value, T* data)
 *
 *  Purpose:    Insert data before a node with the specified value
 *
 *  Entry:      value = value of node to place new data before; data = the data you want to place in
 *              front of the node
 *
 *  Exit:       New node is created before the node with the specified m_data value
 *********************************************************************************************************/
template<typename T>
void LinkedList<T>::InsertBefore(T value, T* data)
{
    bool added = false; //used to flag when the reference value is located and the data added
    for(Iterator<T> i(Begin()); i.getNode() != Empty().getNode(); ++i)
    {
        if(i.getNode()->getData() == value)
        {
            Node<T>* insert = new Node<T>(*data);
            if(m_head == i.getNode())       //if the reference is the head
            {
                insert->setNext(i.getNode());
                insert->getNext()->setPrev(insert);
                m_head = insert;
            }
            else                            //reference is at any other location
            {
                insert->setNext(i.getNode());
                insert->setPrev(i.getNode()->getPrev());
                insert->getNext()->setPrev(insert);
                insert->getPrev()->setNext(insert);
            }
            added = true;
        }
    }
    //if the reference value was not found, add the new data to the beginning
    if(!added)
    {
        Prepend(data);
    }
}

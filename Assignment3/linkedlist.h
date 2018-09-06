/*********************************************************************************************************
* Author:                   Aaron Day
* Date Created:             10/16/2015
* Last Modification Date:   10/21/2015
* Assignment Number:        3
* Filename:                 linkedlist.h
*
* Overview:     LinkedList class. Provides a method for storing data on the heap dynamically. Does not
*               require a contiguous block of memory for all of the data storage
*
* Input:        Inputs are the data that needs to be in the list.
*
* Output:       This class places the data inside of nodes with a pointer to the next and previous element
 *********************************************************************************************************/
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"
#include "iterator.h"

/*********************************************************************************************************
 * Class: LinkedList
 *
 * Constructors/Destructors:
 *      LinkedList()
 *              Default constructor, creates a new list with null head and tail pointers
 *      LinkedList(const LinkedList& copy)
 *              Copy constructor, copies an existing list into a new list
 *      ~LinkedList()
 *              Destructor, frees memory when lists are destroyed
 *
 * Accessors:
 *      bool isEmpty() const
 *              Returns true if m_head and m_tail are null pointers
 *      const Node<T>& First() const
 *              Returns the first node in the list
 *      const Node<T>& Last() const
 *              Returns the last node in the list
 *      Iterator<T> Begin() const
 *              Returns an iterator to the beginning of the list
 *      Iterator<T> End() const
 *              Returns an iterator to the end of the list
 *      Iterator<T> Empty() const
 *              Returns an iterator to a null node
 *
 * Mutators:
 *      LinkedList& operator=(const LinkedList& rhs)
 *              Purges the lhs list then creates new nodes and sets the data equal to the rhs nodes
 *      void Prepend(T* data)
 *              Adds data to the beginning of the list
 *      void Prepend(T data)
 *              Adds data to the beginning of the list
 *      void Append(T* data)
 *              Adds data to the end of the list
 *      void Append(T data)
 *              Adds data to the end of the list
 *      void Purge()
 *              Deletes all nodes from the list
 *      Node<T>& Extract(T value)
 *              Removes a node with a specified data value from the list. Returns a reference to the node
 *              for possible further use.
 *      void InsertAfter(T value, T* data)
 *              Inserts data after a specified value
 *      void InsertBefore(T value, T* data)
 *              Inserts data before a specified value
 *********************************************************************************************************/

template<typename T>
class LinkedList
{
public:
    LinkedList();
    LinkedList(const LinkedList& copy);
    ~LinkedList();

    bool isEmpty() const;
    const Node<T>& First() const;
    const Node<T>& Last() const;
    Iterator<T> Begin() const;
    Iterator<T> End() const;
    Iterator<T> Empty() const;

    LinkedList& operator=(const LinkedList& rhs);
    void Prepend(T* data);
    void Prepend(T data);
    void Append(T* data);
    void Append(T data);
    void Purge();
    Node<T>& Extract(T value);
    void InsertAfter(T value, T* data);
    void InsertBefore(T value, T* data);

private:
    Node<T>* m_head;    //Pointer to first node in list
    Node<T>* m_tail;    //Pointer to last node in list
};

#include "linkedlist.inc"

#endif // LINKEDLIST_H

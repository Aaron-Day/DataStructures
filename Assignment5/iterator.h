/*********************************************************************************************************
* Author:                   Aaron Day
* Date Created:             10/16/2015
* Last Modification Date:   11/01/2015
* Assignment Number:        5
* Filename:                 iterator.h
*
* Overview:     Iterator class that allows simple traversing of linked lists
*
* Input:        Node with next and previous pointers
*
* Output:       Moves forward and backward through a linked list using ++ and -- operators and is able
*               to dereference and return the data stored in the nodes
 *********************************************************************************************************/
#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"

/*********************************************************************************************************
 * Class: Iterator
 *
 * Constructors/Destructors:
 *      Iterator(Node<T>* node)
 *              1 arg constructor. Creates an iterator from a pointer to a node
 *      Iterator(const Iterator<T>& copy)
 *              Copy constructor, copies an existing iterator into a new iterator. Both iterators now
 *              point to the same node
 *      ~Iterator()
 *              Destructor, frees memory when iterators are destroyed
 *
 * Accessors:
 *      Node<T>* getNode() const
 *              Returns a pointer to the node used for iteration
 *      T& operator*()
 *              Returns a reference to the data in the node
 *
 * Mutators:
 *      Iterator& operator=(const Iterator& rhs)
 *              Makes one iterator's m_node point to the same node as another
 *      Iterator& operator++()
 *              makes the next node the current node when traversing a list; done before the
 *              current operation
 *      Iterator operator++(int)
 *              makes the next node the current node when traversing a list; done after the
 *              current operation
 *      Iterator& operator--()
 *              makes the prev node the current node when traversing a list; done before the
 *              current operation
 *      Iterator operator--(int)
 *              makes the prev node the current node when traversing a list; done after the
 *              current operation
 *********************************************************************************************************/

template<typename T>
class Iterator
{
public:
    //constructors
    Iterator(Node<T>* node);
    Iterator(const Iterator<T>& copy);
    ~Iterator();

    //accessors
    Node<T>* getNode() const;
    T& operator*();

    //mutators
    Iterator& operator=(const Iterator& rhs);
    Iterator& operator++();
    Iterator operator++(int);
    Iterator& operator--();
    Iterator operator--(int);

private:
    Node<T>* m_node;    //pointer to node storing data. contains pointers to next and prev nodes
};

#include "iterator.inc"

#endif // ITERATOR_H

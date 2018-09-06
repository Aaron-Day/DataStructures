/*********************************************************************************************************
* Author:                   Aaron Day
* Date Created:             10/16/2015
* Last Modification Date:   10/21/2015
* Assignment Number:        4
* Filename:                 node.h
*
* Overview: Node class to store data and a pointer to the previous node and next node. Used for linked
*           lists.
*
* Input:    Data to be stored
*
* Output:   Data is a variable in a node with a pointer to the next piece of data as well as the previous
 *********************************************************************************************************/
#ifndef NODE_H
#define NODE_H

/*********************************************************************************************************
 * Class: Node
 *
 * Constructors/Destructors:
 *      Node(T data)
 *              1 arg constructor, creates a node with null next and prev pointers and sets the data equal
 *              to the parameter that was passed in
 *      Node(const Node& copy)
 *              Copy constructor, creates a new node with null next and prev pointers and sets the data
 *              equal to the data from the copied node
 *      ~Node()
 *              Destructor, frees memory when node is destroyed
 *
 * Accessors:
 *      T getData() const
 *              Returns the value stored in m_data
 *      T* getDataPtr() const
 *              Returns a pointer to the value stored in m_data
 *      Node* getCurrent
 *              Returns the pointer to the current node
 *      Node* getNext() const
 *              Returns the pointer to the next node
 *      Node* getPrev() const
 *              Returns the pointer to the prev node
 *      bool isNextNull() const
 *              Checks if m_next is null
 *      bool isPrevNull() const
 *              Checks if m_prev is null
 *
 * Mutators:
 *      Node& operator=(const Node& rhs)
 *              Sets m_data equal to the rhs m_data
 *      void setData(T data)
 *              Sets a new value for m_data
 *      void setNext(Node* next)
 *              Sets a new pointer for m_next
 *      void setPrev(Node* prev)
 *              Sets a new pointer for m_prev
 *********************************************************************************************************/

template<typename T>
class Node
{
public:
    //constructors
    Node(T data);
    Node(const Node& copy);
    ~Node();

    //accessors
    T getData() const;
    T* getDataPtr() const;
    Node* getCurrent();
    Node* getNext() const;
    Node* getPrev() const;
    bool isNextNull() const;
    bool isPrevNull() const;

    //mutators
    Node& operator=(const Node& rhs);
    void setData(T data);
    void setNext(Node* next);
    void setPrev(Node* prev);

private:
    T m_data;           //Data value being stored
    Node* m_next;       //Pointer to next node
    Node* m_prev;       //Pointer to prev node
};

#include "node.inc"

#endif // NODE_H

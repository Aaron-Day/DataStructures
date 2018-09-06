/*********************************************************************************************************
* Author:                   Aaron Day
* Date Created:             10/04/2015
* Last Modification Date:   11/16/2015
* Assignment Number:        6
* Filename:                 bst.inc
*********************************************************************************************************/
#include "bst.h"
#include "queue.h"

//
//constructors
//

/*********************************************************************************************************
 * template<typename T>
 * BST<T>::BST()
 *
 *  Purpose:    Default constructor creates an empty binary tree with a null pointer to the root
 *
 *  Entry:      No entry
 *
 *  Exit:       Created a new BST with a null pointer to the root
 *********************************************************************************************************/
template<typename T>
BST<T>::BST()
{
    m_root = nullptr;
}

/*********************************************************************************************************
 * template<typename T>
 * BST<T>::~BST()
 *
 *  Purpose:    Purges all nodes before destroying
 *
 *  Entry:      No entry
 *
 *  Exit:       Safely deleted all nodes to free allocated memory
 *********************************************************************************************************/
template<typename T>
BST<T>::~BST()
{
    Purge();
}

//
//accessors
//

/*********************************************************************************************************
 * template<typename T>
 * int BST<T>::Height()
 *
 *  Purpose:    Returns the number of nodes in the maximum path length
 *
 *  Entry:      No entry
 *
 *  Exit:       Returned the height of the tree (root + each level thereafter)
 *********************************************************************************************************/
template<typename T>
int BST<T>::Height()
{
    return Height(m_root);
}

/*********************************************************************************************************
 * template<typename T>
 * int BST<T>::Height(Node<T>* p)
 *
 *  Purpose:    Helps the Height function by starting at the root
 *
 *  Entry:      Next node in recursion (m_root = first)
 *
 *  Exit:       Returned the height of the tree with the current node as the root (from this node down)
 *********************************************************************************************************/
template<typename T>
int BST<T>::Height(Node<T>* p)
{
    if(p == nullptr)
    {
        return 0;
    }
    else
    {
        int left = Height(p->getPrev());
        int right = Height(p->getNext());
        return 1 + (left > right ? left : right);
    }
}

/*********************************************************************************************************
 * template<typename T>
 * void BST<T>::Visit(Node<T>* p)
 *
 *  Purpose:    Does nothing, can be modified so that it does something to the nodes it searches
 *
 *  Entry:      Node visiting
 *
 *  Exit:       No output
 *********************************************************************************************************/
template<typename T>
void BST<T>::Visit(Node<T>* p)
{
    p; //do something when visited
}

/*********************************************************************************************************
 * template<typename T>
 * void BST<T>::TestVisit(Node<T>* p)
 *
 *  Purpose:    Visit function used for testing, outputs the data in the node to the screen in the order
 *				visited
 *
 *  Entry:      Node inside of a linked list
 *
 *  Exit:       Data is printed to screen in the order visited
 *********************************************************************************************************/
template<typename T>
void BST<T>::TestVisit(Node<T>* p)
{
	cout << p->getData() << " ";
}

/*********************************************************************************************************
 * template<typename T>
 * void BST<T>::InOrder(void(*function)(Node<T>*))
 *
 *  Purpose:    Processes left branch first, then the current node, then the right branch (LCR)
 *
 *  Entry:      Visit function to do something after it visits a node
 *
 *  Exit:       No output
 *********************************************************************************************************/
template<typename T>
void BST<T>::InOrder(void(*function)(Node<T>*))
{
    InOrder(function, m_root);
}

/*********************************************************************************************************
 * template<typename T>
 * void BST<T>::InOrder(void(*function)(Node<T>*), Node<T>* p)
 *
 *  Purpose:    Helps the InOrder function by starting at the root
 *
 *  Entry:      Visit function to do something after it visits a node. And starting point for search
 *
 *  Exit:       No output
 *********************************************************************************************************/
template<typename T>
void BST<T>::InOrder(void(*function)(Node<T>*), Node<T>* p)
{
    if(p != nullptr)
    {
        InOrder(function, p->getPrev());
        function(p);
        InOrder(function, p->getNext());
    }
}

/*********************************************************************************************************
 * template<typename T>
 * void BST<T>::PreOrder(void(*function)(Node<T>*))
 *
 *  Purpose:    Processes the current node first, then the left branch, then the right (CLR)
 *
 *  Entry:      Visit function to do something after it visits a node
 *
 *  Exit:       No output
 *********************************************************************************************************/
template<typename T>
void BST<T>::PreOrder(void(*function)(Node<T>*))
{
    PreOrder(function, m_root);
}

/*********************************************************************************************************
 * template<typename T>
 * void BST<T>::PreOrder(void(*function)(Node<T>*), Node<T> *p)
 *
 *  Purpose:    Helps the PreOrder function by starting at the root
 *
 *  Entry:      Visit function to do something after it visits a node. And starting point for search
 *
 *  Exit:       No output
 *********************************************************************************************************/
template<typename T>
void BST<T>::PreOrder(void(*function)(Node<T>*), Node<T> *p)
{
    if(p != nullptr)
    {
        function(p);
        PreOrder(function, p->getPrev());
        PreOrder(function, p->getNext());
    }
}

/*********************************************************************************************************
 * template<typename T>
 * void BST<T>::PostOrder(void(*function)(Node<T>*))
 *
 *  Purpose:    Processes left branch first, then the right, then the current node (LRC)
 *
 *  Entry:      Visit function to do something after it visits a node
 *
 *  Exit:       No output
 *********************************************************************************************************/
template<typename T>
void BST<T>::PostOrder(void(*function)(Node<T>*))
{
    PostOrder(function, m_root);
}

/*********************************************************************************************************
 * template<typename T>
 * void BST<T>::PostOrder(void(*function)(Node<T>*), Node<T>* p)
 *
 *  Purpose:    Helps the PostOrder function by starting at the root
 *
 *  Entry:      Visit function to do something after it visits a node. And starting point for search
 *
 *  Exit:       No output
 *********************************************************************************************************/
template<typename T>
void BST<T>::PostOrder(void(*function)(Node<T>*), Node<T>* p)
{
    if(p != nullptr)
    {
        PostOrder(function, p->getPrev());
        PostOrder(function, p->getNext());
        function(p);
    }
}

/*********************************************************************************************************
 * template<typename T>
 * void BST<T>::BreadthFirst(void(*function)(Node<T>*))
 *
 *  Purpose:    Processes nodes top to bottom, left to right
 *
 *  Entry:      Visit function to do something after it visits a node
 *
 *  Exit:       No output
 *********************************************************************************************************/
template<typename T>
void BST<T>::BreadthFirst(void(*function)(Node<T>*))
{
    BreadthFirst(function, m_root);
}

/*********************************************************************************************************
 * template<typename T>
 * void BST<T>::BreadthFirst(void(*function)(Node<T>*), Node<T>* p)
 *
 *  Purpose:    Helps the BreadthFirst function by starting at the root
 *
 *  Entry:      Visit function to do something after it visits a node. And starting point for search
 *
 *  Exit:       No output
 *********************************************************************************************************/
template<typename T>
void BST<T>::BreadthFirst(void(*function)(Node<T>*), Node<T>* p)
{
    Queue<Node<T>*> queue(100000);
    if(p != nullptr)
    {
        queue.Enqueue(p);
        while(!queue.isEmpty())
        {
            p = queue.Dequeue();
            function(p);
            if(p->getPrev() != nullptr)
            {
                queue.Enqueue(p->getPrev());
            }
            if(p->getNext() != nullptr)
            {
                queue.Enqueue(p->getNext());
            }
        }
    }
}

//
//mutators
//

/*********************************************************************************************************
 * template<typename T>
 * void BST<T>::Insert(const T& data)
 *
 *  Purpose:    Inserts an element into the proper place in a binary tree
 *
 *  Entry:      Data to be added to the tree
 *
 *  Exit:       Tree now contains a new node with the data in the proper order for a binary search tree
 *********************************************************************************************************/
template<typename T>
void BST<T>::Insert(const T& data)
{
    Insert(m_root, data);
}

/*********************************************************************************************************
 * template<typename T>
 * void BST<T>::Insert(Node<T>* parent, const T& data)
 *
 *  Purpose:    Helps the insert function by starting at the root
 *
 *  Entry:      Next node in recursion (m_root = first). And data to be added to the tree
 *
 *  Exit:       Tree now contains a new node with the data in the proper order for a binary search tree
 *********************************************************************************************************/
template<typename T>
void BST<T>::Insert(Node<T>* parent, const T& data)
{
    if(m_root == nullptr)
    {
        m_root = new Node<T>(data);
    }
    else if(parent->getData() > data)
    {
        if(parent->getPrev() != nullptr)
        {
            Insert(parent->getPrev(), data);
        }
        else
        {
            parent->setPrev(new Node<T>(data));
        }
    }
    else if(parent->getData() < data)
    {
        if(parent->getNext() != nullptr)
        {
            Insert(parent->getNext(), data);
        }
        else
        {
            parent->setNext(new Node<T>(data));
        }
    }
}

/*********************************************************************************************************
 * template<typename T>
 * void BST<T>::Delete(const T& data)
 *
 *  Purpose:    Finds and removes an element from the tree
 *
 *  Entry:      Data to be removed
 *
 *  Exit:       Node has been removed and tree has been properly relinked to compensate for the lost node
 *********************************************************************************************************/
template<typename T>
void BST<T>::Delete(const T& data)
{
    Delete(m_root, data);
}

/*********************************************************************************************************
 * template<typename T>
 * void BST<T>::Delete(Node<T>*& parent, const T& data)
 *
 *  Purpose:    Helps the Delete function by starting search at the root
 *
 *  Entry:      Next node in recursion (m_root = first). And data to be removed
 *
 *  Exit:       Node has been removed and tree has been properly relinked to compensate for the lost node
 *********************************************************************************************************/
template<typename T>
void BST<T>::Delete(Node<T>*& parent, const T& data)
{
    if(parent != nullptr)
    {
        if(parent->getData() == data)
        {
            Node<T>* temp = parent;
            if(parent->getNext() == nullptr)
            {
                parent = parent->getPrev();
            }
            else if(parent->getPrev() == nullptr)
            {
                parent = parent->getNext();
            }
            else
            {
                temp = parent->getPrev();
                while(temp->getNext() != nullptr)
                {
                    temp = temp->getNext();
                }
                temp->setNext(parent->getNext());
                temp = parent;
                parent = parent->getPrev();
            }
            delete temp;
        }
        else if(parent->getData() > data)
        {
            Node<T>* temp = parent->getPrev();
            Delete(temp, data);
            temp = nullptr;
        }
        else
        {
            Node<T>* temp = parent->getNext();
            Delete(temp, data);
            temp = nullptr;
        }
    }
}

/*********************************************************************************************************
 * template<typename T>
 * void BST<T>::Purge()
 *
 *  Purpose:    Safely removes all the nodes from the tree
 *
 *  Entry:      No entry
 *
 *  Exit:       All nodes are removed
 *********************************************************************************************************/
template<typename T>
void BST<T>::Purge()
{
    Purge(m_root);
    m_root = nullptr;
}

/*********************************************************************************************************
 * template<typename T>
 * void BST<T>::Purge(Node<T>* p)
 *
 *  Purpose:    Helps the Purge function by starting the purge at the root
 *
 *  Entry:      Next node in recursion (m_root = first)
 *
 *  Exit:       All nodes are removed
 *********************************************************************************************************/
template<typename T>
void BST<T>::Purge(Node<T>* p)
{
    if(p != nullptr)
    {
        Purge(p->getPrev());
        Purge(p->getNext());
        delete p;
    }
}

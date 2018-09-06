/*********************************************************************************************************
* Author:                   Aaron Day
* Date Created:             10/16/2015
* Last Modification Date:   10/21/2015
* Assignment Number:        3
* Filename:                 iterator.inc
 *********************************************************************************************************/
#include "iterator.h"

template<typename T>
Iterator<T>::Iterator(Node<T>* node)
    :m_node(node)
{

}

template<typename T>
Iterator<T>::Iterator(const Iterator<T>& copy)
    :m_node(copy.m_node)
{
    T* value =new T(copy.getNode()->getData());
    m_node = new Node<T>(*value);
    delete value;
}

template<typename T>
Iterator<T>::~Iterator()
{
    m_node = nullptr;
}

/*********************************************************************************************************
 * template<typename T>
 * Node<T>* Iterator<T>::getNode() const
 *
 *  Purpose:    get the pointer to the node stored in the iterator
 *
 *  Entry:      No entry
 *
 *  Exit:       Returns a pointer to the node stored in m_node
 *********************************************************************************************************/
template<typename T>
Node<T>* Iterator<T>::getNode() const
{
    return m_node;
}

/*********************************************************************************************************
 * template<typename T>
 * T Iterator<T>::operator*()
 *
 *  Purpose:    Get the data stored in the node this iterator stores
 *
 *  Entry:      No entry
 *
 *  Exit:       Returns the data stored in the node
 *********************************************************************************************************/
template<typename T>
T Iterator<T>::operator*() const
{
    return m_node->getData();
}

/*********************************************************************************************************
 * template<typename T>
 * Iterator<T>& Iterator<T>::operator=(const Iterator& rhs)
 *
 *  Purpose:    set m_node equal to another iterator's m_node
 *
 *  Entry:      second iterator for which a pointer to a node is needed
 *
 *  Exit:       Both Iterators now point to the same node
 *********************************************************************************************************/
template<typename T>
Iterator<T>& Iterator<T>::operator=(const Iterator& rhs)
{
    m_node = rhs.m_node;
    return *this;
}

/*********************************************************************************************************
 * template<typename T>
 * Iterator<T>& Iterator<T>::operator++()
 *
 *  Purpose:    increments the iterator before the current operation
 *
 *  Entry:      No entry
 *
 *  Exit:       Returns the iterator after it has been incremented
 *********************************************************************************************************/
template<typename T>
Iterator<T>& Iterator<T>::operator++()
{
    m_node = m_node->getNext();
    return *this;
}

/*********************************************************************************************************
 * template<typename T>
 * Iterator<T> Iterator<T>::operator++(int)
 *
 *  Purpose:    increments the iterator after the current operation
 *
 *  Entry:      No entry
 *
 *  Exit:       Returns the current iteration then increments it
 *********************************************************************************************************/
template<typename T>
Iterator<T> Iterator<T>::operator++(int)
{
    Iterator<T> temp(m_node);
    m_node = m_node->getNext();
    return temp;
}

/*********************************************************************************************************
 * template<typename T>
 * Iterator<T>& Iterator<T>::operator--()
 *
 *  Purpose:    decrements the iterator before the current operation
 *
 *  Entry:      No entry
 *
 *  Exit:       Returns the iteration after it has been decremented
 *********************************************************************************************************/
template<typename T>
Iterator<T>& Iterator<T>::operator--()
{
    m_node = m_node->getPrev();
    return *this;
}

/*********************************************************************************************************
 * template<typename T>
 * Iterator<T> Iterator<T>::operator--(int)
 *
 *  Purpose:    decrements the iterator after the current opperation
 *
 *  Entry:      No entry
 *
 *  Exit:       Returns the current iteration then decrements it
 *********************************************************************************************************/
template<typename T>
Iterator<T> Iterator<T>::operator--(int)
{
    Iterator<T> temp(m_node);
    m_node = m_node->getPrev();
    return temp;
}


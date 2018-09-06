/*********************************************************************************************************
* Author:                   Aaron Day
* Date Created:             11/15/2015
* Last Modification Date:   11/16/2015
* Assignment Number:        Lab 4
* Filename:                 AVLNode.h
 *********************************************************************************************************/
#ifndef AVLNODE_H
#define AVLNODE_H

#include "node.h"

template<typename T>
class AVLNode : public Node<T>
{
public:
    AVLNode(T data)
        :Node<T>(data)
    {
        m_height = 0;
    }

    int m_height;
};

#endif // AVLNODE_H

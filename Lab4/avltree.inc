/*********************************************************************************************************
* Author:                   Aaron Day
* Date Created:             11/15/2015
* Last Modification Date:   11/16/2015
* Assignment Number:        Lab 4
* Filename:                 AVLTree.inc
 *********************************************************************************************************/
#include "avltree.h"

//overrides from parent class
template<typename T>
void AVLTree<T>::Insert(const T &data)
{
    BST<T>::Insert(data);
    balancePath(data);
}

template<typename T>
void AVLTree<T>::Insert(Node<T>* parent, const T& data)
{
    BST<T>::Insert(parent, data);
    balancePath(data);
}

template<typename T>
void AVLTree<T>::Delete(const T& data)
{
    Delete(BST<T>::m_root, data);
}

template<typename T>
void AVLTree<T>::Delete(Node<T>*& treeRoot, const T& data)
{
    if(treeRoot == nullptr)
    {
        return;
    }
    Node<T>* parent = nullptr;
    Node<T>* current = treeRoot;
    while(current != nullptr)
    {
        if(data < current->getData())
        {
            parent = current;
            current = current->getPrev();
        }
        else if(data > current->getData())
        {
            parent = current;
            current = current->getNext();
        }
        else
        {
            break;
        }
    }
    if(current == nullptr)
    {
        return;
    }
    if(current->getPrev() == nullptr)
    {
        if(parent == nullptr)
        {
            BST<T>::m_root = current->getNext();
        }
        else
        {
            if(data < parent->getData())
            {
                parent->setPrev(current->getNext());
            }
            else
            {
                parent->setNext(current->getNext());
            }
        }
    }
    else
    {
        Node<T>* parentRight = current;
        Node<T>* right = current->getPrev();
        while(right->getNext() != nullptr)
        {
            parentRight = right;
            right = right->getNext();
        }
        current->setData(right->getData());
        if(parentRight->getNext() == right)
        {
            parentRight->setNext(right->getPrev());
        }
        else
        {
            parentRight->setPrev(right->getPrev());
        }
        balancePath(parentRight->getData());
    }
}

template<typename T>
void AVLTree<T>::show(AVLTree<T>* tree, AVLNode<T>* node)
{
    cout << "Data: " << node->getData() << " Height: " << node->m_height << " Balance: " << tree->balanceFactor(node) << endl;
}

template<typename T>
vector<Node<T>*>* AVLTree<T>::path(T data) const
{
    vector<Node<T>*>* p = new vector<Node<T>*>();
    Node<T>* current = BST<T>::m_root;
    while(current != nullptr)
    {
        p->push_back(current);
        if(data < current->getData())
        {
            current = current->getPrev();
        }
        else if(data > current->getData())
        {
            current = current->getNext();
        }
        else
        {
            break;
        }
    }
    return p;
}

template<typename T>
void AVLTree<T>::balancePath(T data)
{
    vector<Node<T>*>* p = path(data);
    for(int i = (int)(*p).size() - 1; i >= 0; --i)
    {
        AVLNode<T>* node = static_cast<AVLNode<T>*>((*p)[(size_t)i]);
        updateHeight(node);
        AVLNode<T>* parent = (node == BST<T>::m_root) ? nullptr : static_cast<AVLNode<T>*>((*p)[(size_t)i - 1]);

        switch(balanceFactor(node))
        {
        case -2:
            if(balanceFactor(static_cast<AVLNode<T>*>((*node).getPrev())) <= 0)
            {
                balanceLL(node, parent);
            }
            else
            {
                balanceLR(node, parent);
            }
            break;
        case 2:
            if(balanceFactor(static_cast<AVLNode<T>*>((*node).getNext())) >= 0)
            {
                balanceRR(node, parent);
            }
            else
            {
                balanceRL(node, parent);
            }
        }
    }
}

template<typename T>
void AVLTree<T>::updateHeight(AVLNode<T>* node)
{
    if(node->getPrev() == nullptr && node->getNext() == nullptr)
    {
        node->m_height = 0;
    }
    else if(node->getPrev() == nullptr)
    {
        node->m_height = 1 + (*static_cast<AVLNode<T>*>((node->getNext()))).m_height;
    }
    else if(node->getNext() == nullptr)
    {
        node->m_height = 1 + (*static_cast<AVLNode<T>*>((node->getPrev()))).m_height;
    }
    else
    {
        int left = (*static_cast<AVLNode<T>*>((node->getPrev()))).m_height;
        int right = (*static_cast<AVLNode<T>*>((node->getNext()))).m_height;
        node->m_height = 1 + ((left > right) ? left : right);
    }
}

template<typename T>
int AVLTree<T>::balanceFactor(AVLNode<T>* node)
{
    if(node->getNext() == nullptr)
    {
        return -node->m_height;
    }
    else if(node->getPrev() == nullptr)
    {
        return node->m_height;
    }
    else
    {
        return (*static_cast<AVLNode<T>*>((node->getNext()))).m_height - (*static_cast<AVLNode<T>*>((node->getPrev()))).m_height;
    }
}

template<typename T>
void AVLTree<T>::balanceLL(Node<T>* node, Node<T>* parent)
{
    Node<T>* left = node->getPrev();
    if(node == BST<T>::m_root)
    {
        BST<T>::m_root = left;
    }
    else
    {
        if(parent->getPrev() == node)
        {
            parent->setPrev(left);
        }
        else
        {
            parent->setNext(left);
        }
    }
    node->setPrev(left->getNext());
    left->setNext(node);
    updateHeight(static_cast<AVLNode<T>*>(node));
    updateHeight(static_cast<AVLNode<T>*>(left));
}

template<typename T>
void AVLTree<T>::balanceLR(Node<T>* node, Node<T>* parent)
{
    Node<T>* left = node->getPrev();
    Node<T>* leftRight = left->getNext();
    if(node == BST<T>::m_root)
    {
        BST<T>::m_root = leftRight;
    }
    else
    {
        if(parent->getPrev() == node)
        {
            parent->setPrev(leftRight);
        }
        else
        {
            parent->setNext(leftRight);
        }
    }
    node->setPrev(leftRight->getNext());
    left->setNext(leftRight->getPrev());
    leftRight->setPrev(left);
    leftRight->setNext(node);
    updateHeight(static_cast<AVLNode<T>*>(node));
    updateHeight(static_cast<AVLNode<T>*>(left));
    updateHeight(static_cast<AVLNode<T>*>(leftRight));
}

template<typename T>
void AVLTree<T>::balanceRR(Node<T>* node, Node<T>* parent)
{
    Node<T>* right = node->getNext();
    if(node == BST<T>::m_root)
    {
        BST<T>::m_root = right;
    }
    else
    {
        if(parent->getPrev() == node)
        {
            parent->setPrev(right);
        }
        else
        {
            parent->setNext(right);
        }
    }
    node->setNext(right->getPrev());
    right->setPrev(node);
    updateHeight(static_cast<AVLNode<T>*>(node));
    updateHeight(static_cast<AVLNode<T>*>(right));
}

template<typename T>
void AVLTree<T>::balanceRL(Node<T>* node, Node<T>* parent)
{
    Node<T>* right = node->getNext();
    Node<T>* rightLeft = right->getPrev();
    if(node == BST<T>::m_root)
    {
        BST<T>::m_root = rightLeft;
    }
    else
    {
        if(parent->getPrev() == node)
        {
            parent->setPrev(rightLeft);
        }
        else
        {
            parent->setNext(rightLeft);
        }
    }
    node->setNext(rightLeft->getPrev());
    right->setPrev(rightLeft->getNext());
    rightLeft->setPrev(node);
    rightLeft->setNext(right);
    updateHeight(static_cast<AVLNode<T>*>(node));
    updateHeight(static_cast<AVLNode<T>*>(right));
    updateHeight(static_cast<AVLNode<T>*>(rightLeft));
}
template<typename T>
void AVLTree<T>::Traverse(void(*function)(AVLTree<T>*,AVLNode<T>*))
{
    Traverse(function, static_cast<AVLNode<T>*>(BST<T>::m_root));
}

template<typename T>
void AVLTree<T>::Traverse(void(*function)(AVLTree<T>*,AVLNode<T>*), AVLNode<T>* p)
{
    if(p != nullptr)
    {
        Traverse(function, static_cast<AVLNode<T>*>(p->getPrev()));
        function(this, p);
        Traverse(function, static_cast<AVLNode<T>*>(p->getNext()));
    }
}


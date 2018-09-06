/*********************************************************************************************************
* Author:                   Aaron Day
* Date Created:             11/15/2015
* Last Modification Date:   11/16/2015
* Assignment Number:        Lab 4
* Filename:                 AVLTree.h
 *********************************************************************************************************/
#ifndef AVLTREE_H
#define AVLTREE_H

#include "bst.h"
#include "avlnode.h"
#include <vector>

template<typename T>
class AVLTree : public BST<T>
{
public:
    AVLTree(){}

    //overrides from parent class
    virtual void Insert(const T &data);
    virtual void Insert(Node<T>* parent, const T& data);
    virtual void Delete(const T& data);
    virtual void Delete(Node<T>*& treeRoot, const T& data);

    static void show(AVLTree<T>* tree, AVLNode<T>* node);
    vector<Node<T>*>* path(T data) const;
    void balancePath(T data);
    void updateHeight(AVLNode<T>* node);
    int balanceFactor(AVLNode<T>* node);
    void balanceLL(Node<T>* node, Node<T>* parent);
    void balanceLR(Node<T>* node, Node<T>* parent);
    void balanceRR(Node<T>* node, Node<T>* parent);
    void balanceRL(Node<T>* node, Node<T>* parent);
    void Traverse(void(*function)(AVLTree<T>*,AVLNode<T>*));
    void Traverse(void(*function)(AVLTree<T>*,AVLNode<T>*), AVLNode<T>* p);
};

#include "avltree.inc"

#endif // AVLTREE_H

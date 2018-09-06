/*********************************************************************************************************
* Author:                   Aaron Day
* Date Created:             10/04/2015
* Last Modification Date:   11/16/2015
* Assignment Number:        6
* Filename:                 bst.h
*
* Overview:     Used for storing nodes in a binary search tree pattern
*
* Input:        Inputs create new nodes in a proper binary search tree pattern
*
* Output:       No output, visit function may be modified to produce console output
*********************************************************************************************************/
#ifndef BST_H
#define BST_H

#include "node.h"
#include <vector>

using namespace std;

/*********************************************************************************************************
* Class: BST
*
* Constructors/Destructors:
*      BST()
*              Default constructor creates an empty binary tree with a null pointer to the root
*      ~BST()
*              Purges all nodes before destroying
*
* Accessors:
*		int Height()
*				Returns the number of nodes in the maximum path length
*		int Height(Node<T>* p)
*				Helps the Height function by starting at the root
*		static void Visit(Node<T>* p)
*				Does nothing, can be modified so that it does something to the nodes it searches
*		static void TestVisit(Node<T>* p)
*				Visit function used for testing, outputs the data in the node to the screen in the order visited
*		void InOrder(void(*function)(Node<T>*))
*				Processes left branch first, then the current node, then the right branch (LCR)
*		void InOrder(void(*function)(Node<T>*), Node<T> *p)
*				Helps the InOrder function by starting at the root
*		void PreOrder(void(*function)(Node<T>*))
*				Processes the current node first, then the left branch, then the right (CLR)
*		void PreOrder(void(*function)(Node<T>*), Node<T> *p)
*				Helps the PreOrder function by starting at the root
*		void PostOrder(void(*function)(Node<T>*))
*				Processes left branch first, then the right, then the current node (LRC)
*		void PostOrder(void(*function)(Node<T>*), Node<T> *p)
*				Helps the PostOrder function by starting at the root
*		void BreadthFirst(void(*function)(Node<T>*))
*				Processes nodes top to bottom, left to right
*		void BreadthFirst(void(*function)(Node<T>*), Node<T> *p)
*				Helps the BreadthFirst function by starting at the root
*
* Mutators:
*		void Insert(const T& data)
*				Inserts an element into the proper place in a binary tree
*		void Insert(Node<T>* parent, const T& data)
*				Helps the insert function by starting at the root
*		void Delete(const T& data)
*				Finds and removes an element from the tree
*		void Delete(Node<T>*& parent, const T& data)
*				Helps the Delete function by starting search at the root
*		void Purge()
*				Safely removes all the nodes from the tree
*		void Purge(Node<T>* p)
*				Helps the Purge function by starting the purge at the root
*********************************************************************************************************/

template<typename T>
class BST
{
public:
	//constructor
	BST();
	~BST();

	//accessors
	int Height();
    int Height(Node<T>* p);

    static void Visit(Node<T>* p);
	static void TestVisit(Node<T>* p);

	void InOrder(void(*function)(Node<T>*));
    void InOrder(void(*function)(Node<T>*), Node<T> *p);
	void PreOrder(void(*function)(Node<T>*));
    void PreOrder(void(*function)(Node<T>*), Node<T> *p);
	void PostOrder(void(*function)(Node<T>*));
    void PostOrder(void(*function)(Node<T>*), Node<T> *p);
	void BreadthFirst(void(*function)(Node<T>*));
    void BreadthFirst(void(*function)(Node<T>*), Node<T> *p);

	//mutators
    virtual void Insert(const T& data);
    virtual void Insert(Node<T>* parent, const T& data);
    virtual void Delete(const T& data);
    virtual void Delete(Node<T>*& parent, const T& data);
	void Purge();
    void Purge(Node<T>* p);


protected:
	Node<T>* m_root;
};

#include "bst.inc"

#endif // BST_H

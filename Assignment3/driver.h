/*********************************************************************************************************
* Author:                   Aaron Day
* Date Created:             10/16/2015
* Last Modification Date:   10/21/2015
* Assignment Number:        3
* Filename:                 driver.h
*
* Overview:     Driver file used for testing Node, Iterator, and LinkedList classes
 *********************************************************************************************************/
#ifndef DRIVER_H
#define DRIVER_H

#include <string>

using namespace std;

#include "linkedlist.h"
#include "node.h"
#include "iterator.h"

void display(bool pass, string test)
{
    if(pass)
    {
        cout << "PASS - ";
    }
    else
    {
        cout << "FAIL - ";
    }
    cout << test << endl;
}

//
//Test Node
//

//constructors
void testNode_ctor()
{
    int a = 1;
    Node<int> temp(a);
    bool pass = temp.getData() == 1;
    display(pass, "testNode_ctor()");
}
void testNode_cctor()
{
    int a = 1;
    Node<int> temp(a);
    Node<int> temp2(temp);
    bool pass = temp2.getData() == 1;
    display(pass, "testNode_cctor()");
}

//accessors
void testNode_getData()
{
    int a = 1;
    Node<int> temp(a);
    bool pass = temp.getData() == 1;
    display(pass, "testNode_getData()");
}
void testNode_getNext()
{
    int a = 1;
    int b = 2;
    Node<int> temp(a);
    Node<int> temp2(b);
    temp.setNext(&temp2);
    temp2.setPrev(&temp);
    bool pass = temp.getNext()->getData() == 2 && temp2.getPrev()->getData() == 1;
    display(pass, "testNode_getNext()");
}
void testNode_getPrev()
{
    int a = 1;
    int b = 2;
    Node<int> temp(a);
    Node<int> temp2(b);
    temp.setNext(&temp2);
    temp2.setPrev(&temp);
    bool pass = temp.getNext()->getData() == 2 && temp2.getPrev()->getData() == 1;
    display(pass, "testNode_getPrev()");
}
void testNode_isNextNull()
{
    int a = 1;
    Node<int> temp(a);
    bool pass = temp.isNextNull() == true;
    display(pass, "testNode_isNextNull()");
}
void testNode_isPrevNull()
{
    int a = 1;
    Node<int> temp(a);
    bool pass = temp.isPrevNull() == true;
    display(pass, "testNode_isPrevNull()");
}

//mutators
void testNode_equal_oper()
{
    int a = 1;
    int b = 2;
    Node<int> temp(a);
    Node<int> temp2(b);
    temp = temp2;
    bool pass = temp.getData() == 2;
    display(pass, "testNode_equal_oper()");
}
void testNode_setData()
{
    int a = 1;
    int b = 2;
    Node<int> temp(a);
    temp.setData(b);
    bool pass = temp.getData() == 2;
    display(pass, "testNode_setData()");
}
void testNode_setNext()
{
    int a = 1;
    int b = 2;
    Node<int> temp(a);
    Node<int> temp2(b);
    temp.setNext(&temp2);
    temp2.setPrev(&temp);
    bool pass = temp.getNext()->getData() == 2 && temp2.getPrev()->getData() == 1;
    display(pass, "testNode_setNext()");
}
void testNode_setPrev()
{
    int a = 1;
    int b = 2;
    Node<int> temp(a);
    Node<int> temp2(b);
    temp.setNext(&temp2);
    temp2.setPrev(&temp);
    bool pass = temp.getNext()->getData() == 2 && temp2.getPrev()->getData() == 1;
    display(pass, "testNode_setPrev()");
}

//
//Test Iterator
//

//constructors
void testIterator_ctor()
{
    int a = 1;
    Node<int> temp(a);
    Iterator<int> it(&temp);
    bool pass = it.getNode()->getData() == 1;
    display(pass, "testIterator_ctor()");
}
void testIterator_cctor()
{
    int a = 1;
    Node<int> temp(a);
    Iterator<int> it(&temp);
    Iterator<int> it2(it);
    bool pass = it2.getNode()->getData() == 1;
    display(pass, "testIterator_cctor()");
}

//accessors
void testIterator_getNode()
{
    int a = 1;
    Node<int> temp(a);
    Iterator<int> it(&temp);
    bool pass = it.getNode()->getData() == 1;
    display(pass, "testIterator_getNode()");
}
void testIterator_deref_oper()
{
    int a = 1;
    Node<int> temp(a);
    Iterator<int> it(&temp);
    bool pass = *it == 1;
    display(pass, "testIterator_deref_oper()");
}

//mutators
void testIterator_equal_oper()
{
    int a = 1;
    int b = 2;
    Node<int> temp(a);
    Node<int> temp2(b);
    Iterator<int> it(&temp);
    Iterator<int> it2(&temp2);
    it = it2;
    bool pass = it.getNode()->getData() == 2;
    display(pass, "testIterator_equal_oper()");
}
void testIterator_add_prefix_oper()
{
    int a = 1;
    int b = 2;
    Node<int> temp(a);
    Node<int> temp2(b);
    temp.setNext(&temp2);
    temp2.setPrev(&temp);
    Iterator<int> it(&temp);
    ++it;
    bool pass = it.getNode()->getData() == 2;
    display(pass, "testIterator_add_prefix_oper()");
}
void testIterator_add_postfix_oper()
{
    int a = 1;
    int b = 2;
    Node<int> temp(a);
    Node<int> temp2(b);
    temp.setNext(&temp2);
    temp2.setPrev(&temp);
    Iterator<int> it(&temp);
    it++;
    bool pass = it.getNode()->getData() == 2;
    display(pass, "testIterator_add_postfix_oper()");
}
void testIterator_sub_prefix_oper()
{
    int a = 1;
    int b = 2;
    Node<int> temp(a);
    Node<int> temp2(b);
    temp.setNext(&temp2);
    temp2.setPrev(&temp);
    Iterator<int> it(&temp2);
    --it;
    bool pass = it.getNode()->getData() == 1;
    display(pass, "testIterator_sub_prefix_oper()");
}
void testIterator_sub_postfix_oper()
{
    int a = 1;
    int b = 2;
    Node<int> temp(a);
    Node<int> temp2(b);
    temp.setNext(&temp2);
    temp2.setPrev(&temp);
    Iterator<int> it(&temp2);
    it--;
    bool pass = it.getNode()->getData() == 1;
    display(pass, "testIterator_sub_postfix_oper()");
}

//
//Test LinkedList
//

//constructors
void testLinkedList_ctor()
{
    LinkedList<int> list;
    bool pass = list.isEmpty();
    display(pass, "testLinkedList_ctor()");
}
void testLinkedList_cctor()
{
    int a = 1;
    int b = 2;
    LinkedList<int> list;
    list.Prepend(&b);
    list.Prepend(&a);
    LinkedList<int> list2(list);
    bool pass = list2.First().getData() == 1 && list2.Last().getData() == 2;
    display(pass, "testLinkedList_cctor()");
}

//accessors
void testLinkedList_isEmpty()
{
    LinkedList<int> list;
    bool pass = list.isEmpty();
    display(pass, "testLinkedList_isEmpty()");
}
void testLinkedList_Begin()
{
    int a = 1;
    int b = 2;
    LinkedList<int> list;
    list.Prepend(&b);
    list.Prepend(&a);
    bool pass = list.Begin().getNode()->getData() == 1;
    display(pass, "testLinkedList_Begin()");
}
void testLinkedList_End()
{
    int a = 1;
    int b = 2;
    LinkedList<int> list;
    list.Prepend(&b);
    list.Prepend(&a);
    bool pass = list.End().getNode()->getData() == 2;
    display(pass, "testLinkedList_End()");
}
void testLinkedList_Empty()
{
    LinkedList<int> list;
    bool pass = list.Empty().getNode() == nullptr;
    display(pass, "testLinkedList_Empty()");
}

//mutators
void testLinkedList_equal_oper()
{
    int a = 1;
    int b = 2;
    LinkedList<int> list;
    list.Prepend(&b);
    list.Prepend(&a);
    LinkedList<int> list2;
    list2 = list;
    bool pass = list2.First().getData() == 1 && list2.Last().getData() == 2;
    display(pass, "testLinkedList_equal_oper()");
}
void testLinkedList_First()
{
    int a = 1;
    LinkedList<int> list;
    list.Append(&a);
    bool pass = list.First().getData() == 1;
    display(pass, "testLinkedList_First()");
}
void testLinkedList_Last()
{
    int a = 1;
    LinkedList<int> list;
    list.Append(&a);
    bool pass = list.Last().getData() == 1;
    display(pass, "testLinkedList_Last()");
}
void testLinkedList_Prepend()
{
    int a = 1;
    int b = 2;
    LinkedList<int> list;
    list.Prepend(&b);
    list.Prepend(&a);
    bool pass = list.First().getData() == 1 && list.Last().getData() == 2;
    display(pass, "testLinkedList_Prepend()");
}
void testLinkedList_Append()
{
    int a = 1;
    int b = 2;
    LinkedList<int> list;
    list.Append(&a);
    list.Append(&b);
    bool pass = list.First().getData() == 1 && list.Last().getData() == 2;
    display(pass, "testLinkedList_Append()");
}
void testLinkedList_Purge()
{
    int a = 1;
    int b = 2;
    LinkedList<int> list;
    list.Prepend(&b);
    list.Prepend(&a);
    list.Purge();
    bool pass = list.isEmpty();
    display(pass, "testLinkedList_Purge()");
}
void testLinkedList_Extract()
{
    int a = 1;
    LinkedList<int> list;
    list.Append(&a);
    bool pass = list.Extract(a).getData() == 1 && list.isEmpty();
    display(pass, "testLinkedList_Extract()");
}
void testLinkedList_InsertAfter()
{
    int a = 1;
    int b = 2;
    int c = 3;
    LinkedList<int> list;
    list.Append(&a);
    list.Append(&c);
    list.InsertAfter(a, &b);
    bool pass = *(++(list.Begin())) == 2;
    display(pass, "testLinkedList_InsertAfter()");
}
void testLinkedList_InsertBefore()
{
    int a = 1;
    int b = 2;
    int c = 3;
    LinkedList<int> list;
    list.Append(&a);
    list.Append(&c);
    list.InsertBefore(c, &b);
    bool pass = *(++(list.Begin())) == 2;
    display(pass, "testLinkedList_InsertBefore()");
}

#endif // DRIVER_H


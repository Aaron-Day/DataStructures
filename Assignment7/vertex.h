/*********************************************************************************************************
* Author:                   Aaron Day
* Date Created:             11/13/2015
* Last Modification Date:   11/15/2015
* Assignment Number:        7
* Filename:                 vertex.h
*
* Overview:     Stores data related to a vertices in a graph. Contains a list of edges to
*               adjacent vertices
*
* Input:        Data to be stored
*
* Output:       Outputs the data when visited
 *********************************************************************************************************/
#ifndef VECTOR_H
#define VECTOR_H

#include "edge.h"

#include <list>
#include <string>

using namespace std;

template<typename T, typename R>
class Vertex
{
public:
    Vertex(T data);
    ~Vertex();

    void addEdge(Edge<T,R>* edgePtr);

    T getData() const;
    bool getVisited() const;
    list<Edge<T,R>*>& getEdges();

    void visit();
    void setData(T data);
    void setVisited(bool visited);

    //extra
    void listEdges();

private:
    T m_data;
    list<Edge<T,R>*> m_edges;   //heap memory
    bool m_visited;
};

/*********************************************************************************************************
 * template<typename T, typename R>
 * Vertex<T,R>::Vertex(T data)
 *
 *  Purpose:    Create a new vertex containing data
 *
 *  Entry:      Data to be stored
 *
 *  Exit:       New vertex created
 *********************************************************************************************************/
template<typename T, typename R>
Vertex<T,R>::Vertex(T data)
    :m_data(data), m_visited(false){}

/*********************************************************************************************************
 * template<typename T, typename R>
 * Vertex<T,R>::~Vertex()
 *
 *  Purpose:    Safely delete a vertex
 *
 *  Entry:      No entry
 *
 *  Exit:       Vertex deleted
 *********************************************************************************************************/
template<typename T, typename R>
Vertex<T,R>::~Vertex()
{
    for(typename list<Edge<T,R>*>::iterator i = m_edges.begin(); i != m_edges.end(); ++i)
    {
        delete *i;
    }
}

/*********************************************************************************************************
 * template<typename T, typename R>
 * void Vertex<T,R>::addEdge(Edge<T,R> *edgePtr)
 *
 *  Purpose:    Add an edge to the list of edges
 *
 *  Entry:      Pointer to edge to add
 *
 *  Exit:       New edge added to list
 *********************************************************************************************************/
template<typename T, typename R>
void Vertex<T,R>::addEdge(Edge<T,R> *edgePtr)
{
    m_edges.push_back(edgePtr);
}

/*********************************************************************************************************
 * template<typename T, typename R>
 * T Vertex<T,R>::getData() const
 *
 *  Purpose:    Return the data in the vertex
 *
 *  Entry:      No entry
 *
 *  Exit:       Return the data in the vertex
 *********************************************************************************************************/
template<typename T, typename R>
T Vertex<T,R>::getData() const
{
    return m_data;
}

/*********************************************************************************************************
 * template<typename T, typename R>
 * bool Vertex<T,R>::getVisited() const
 *
 *  Purpose:    Return true if the vertex has been visited
 *
 *  Entry:      No entry
 *
 *  Exit:       Return true if the vertex has been visited
 *********************************************************************************************************/
template<typename T, typename R>
bool Vertex<T,R>::getVisited() const
{
    return m_visited;
}

/*********************************************************************************************************
 * template<typename T, typename R>
 * void Vertex<T,R>::visit()
 *
 *  Purpose:    Do actions when a vertex is visited
 *
 *  Entry:      No entry
 *
 *  Exit:       Actions completed
 *********************************************************************************************************/
template<typename T, typename R>
void Vertex<T,R>::visit()
{
    cout << m_data << endl;
    m_visited = true;
}

/*********************************************************************************************************
 * template<typename T, typename R>
 * void Vertex<T,R>::setData(T data)
 *
 *  Purpose:    Modify the data of a vertex
 *
 *  Entry:      New data
 *
 *  Exit:       Data modified
 *********************************************************************************************************/
template<typename T, typename R>
void Vertex<T,R>::setData(T data)
{
    m_data = data;
}

/*********************************************************************************************************
 * template<typename T, typename R>
 * void Vertex<T,R>::setVisited(bool visited)
 *
 *  Purpose:    Modify if the vertex has been visited
 *
 *  Entry:      Value to set it to (true/false)
 *
 *  Exit:       New value set
 *********************************************************************************************************/
template<typename T, typename R>
void Vertex<T,R>::setVisited(bool visited)
{
    m_visited = visited;
}

/*********************************************************************************************************
 * template<typename T, typename R>
 * void Vertex<T,R>::listEdges()
 *
 *  Purpose:    Display the vertex and a list of all the edges
 *
 *  Entry:      No entry
 *
 *  Exit:       Console output
 *********************************************************************************************************/
template<typename T, typename R>
void Vertex<T,R>::listEdges()
{
    cout << m_data << " Edges: \n";
    for(typename list<Edge<T,R>*>::iterator i = m_edges.begin(); i != m_edges.end(); ++i)
    {
        if((*i)->getV1() != this)
        {
            cout << "\t" << (*i)->getV1()->getData() << " (" << (*i)->getWeight() << ", " << (*i)->getData() << ")" << endl;
        }
        else
        {
            cout << "\t" << (*i)->getV2()->getData() << " (" << (*i)->getWeight() << ", " << (*i)->getData() << ")" << endl;
        }
    }
}

/*********************************************************************************************************
 * template<typename T, typename R>
 * list<Edge<T,R>*>& Vertex<T,R>::getEdges()
 *
 *  Purpose:    Get the list of edges
 *
 *  Entry:      No entry
 *
 *  Exit:       Return the list of edges
 *********************************************************************************************************/
template<typename T, typename R>
list<Edge<T,R>*>& Vertex<T,R>::getEdges()
{
    return m_edges;
}

#endif // VECTOR_H

/*********************************************************************************************************
* Author:                   Aaron Day
* Date Created:             11/13/2015
* Last Modification Date:   11/15/2015
* Assignment Number:        7
* Filename:                 graph.h
*
* Overview:     Provides methods of creating vertices and edges for use in a graph as well as breadth
*               and depth first searches
*
* Input:        Creating vertices requires the data that will be stored in it. Creating edges requires
*               the data in the two vertices it will connect as well as an optional weight and data field
*
* Output:       Searches may output the data in the vertices when visited
 *********************************************************************************************************/
#ifndef GRAPH_H
#define GRAPH_H

#include "vertex.h"

#include <list>

using namespace std;

template<typename T, typename R>
class Graph
{
public:
    Graph(){}
    ~Graph();

    void addVertex(T data);
    Vertex<T,R>* getVertex(T data);

    void addEdge(T v1data, T v2data, int weight = 0, R data = 0);
    void resetVisited();

    void breadth(T start);
    void depth(T start);

    //extra
    void listEdges();

private:
    list<Vertex<T,R>> m_vertex; //stack memory
    list<Edge<T,R>*> m_edge;    //heap memory
};

/*********************************************************************************************************
 * template<typename T, typename R>
 * Graph<T,R>::~Graph()
 *
 *  Purpose:    Safely delete a graph
 *
 *  Entry:      No entry
 *
 *  Exit:       Graph deleted
 *********************************************************************************************************/
template<typename T, typename R>
Graph<T,R>::~Graph()
{
    for(typename list<Edge<T,R>*>::iterator i = m_edge.begin(); i != m_edge.end(); ++i)
    {
        delete *i;
    }
}

/*********************************************************************************************************
 * template<typename T, typename R>
 * void Graph<T,R>::addVertex(T data)
 *
 *  Purpose:    Add a new vertex to the graph
 *
 *  Entry:      Data to be stored in vertex
 *
 *  Exit:       New vertex created and added to graph
 *********************************************************************************************************/
template<typename T, typename R>
void Graph<T,R>::addVertex(T data)
{
    m_vertex.push_back(Vertex<T,R>(data));
}

/*********************************************************************************************************
 * template<typename T, typename R>
 * Vertex<T,R>* Graph<T,R>::getVertex(T data)
 *
 *  Purpose:    Get a pointer to the vertex matching the data
 *
 *  Entry:      Data to find
 *
 *  Exit:       Return pointer to vertex
 *********************************************************************************************************/
template<typename T, typename R>
Vertex<T,R>* Graph<T,R>::getVertex(T data)
{
    for(typename list<Vertex<T,R>>::iterator i = m_vertex.begin(); i != m_vertex.end(); ++i)
    {
        if((*i).getData() == data)
        {
            return &(*i);
        }
    }
    return nullptr; //if nothing was found
}

/*********************************************************************************************************
 * template<typename T, typename R>
 * void Graph<T,R>::addEdge(T v1data, T v2data, int weight, R data)
 *
 *  Purpose:    Create a new edge between two vertices
 *
 *  Entry:      Data for two vertices to connect as well as optional weight and data
 *
 *  Exit:       New edge created between two vertices
 *********************************************************************************************************/
template<typename T, typename R>
void Graph<T,R>::addEdge(T v1data, T v2data, int weight, R data)
{
    Edge<T,R>* edge = new Edge<T,R>(getVertex(v1data), getVertex(v2data), weight, data);
    m_edge.push_back(edge);
    getVertex(v1data)->addEdge(edge);
    getVertex(v2data)->addEdge(edge);
}

/*********************************************************************************************************
 * template<typename T, typename R>
 * void Graph<T,R>::resetVisited()
 *
 *  Purpose:    Reset all vertices visited flag to false
 *
 *  Entry:      No entry
 *
 *  Exit:       All vertices visited flag is false
 *********************************************************************************************************/
template<typename T, typename R>
void Graph<T,R>::resetVisited()
{
    for(typename list<Vertex<T,R>>::iterator i = m_vertex.begin(); i != m_vertex.end(); ++i)
    {
        (*i).setVisited(false);
    }
}

/*********************************************************************************************************
 * template<typename T, typename R>
 * void Graph<T,R>::breadth(T start)
 *
 *  Purpose:    Conduct a breadth first search from a given vertex. Vertex visit functions are called
 *              during traversal
 *
 *  Entry:      Data for the starting vertex
 *
 *  Exit:       Search performed
 *********************************************************************************************************/
template<typename T, typename R>
void Graph<T,R>::breadth(T start)
{
    list<Vertex<T, R>*> queue;
    queue.push_back(getVertex(start));
    while(!queue.empty())
    {
        if(!queue.front()->getVisited())
        {
            queue.front()->visit();
            for(typename list<Edge<T,R>*>::iterator i = queue.front()->getEdges().begin(); i != queue.front()->getEdges().end(); ++i)
            {
                if((*i)->getV1() != queue.front())
                {
                    if(!(*i)->getV1()->getVisited())
                    {
                        queue.push_back((*i)->getV1());
                    }
                }
                else
                {
                    if(!(*i)->getV2()->getVisited())
                    {
                        queue.push_back((*i)->getV2());
                    }
                }
            }
        }
        queue.pop_front();
    }
}

/*********************************************************************************************************
 * template<typename T, typename R>
 * void Graph<T,R>::breadth(T start)
 *
 *  Purpose:    Conduct a depth first search from a given vertex. Vertex visit functions are called
 *              during traversal
 *
 *  Entry:      Data for the starting vertex
 *
 *  Exit:       Search performed
 *********************************************************************************************************/
template<typename T, typename R>
void Graph<T,R>::depth(T start)
{
    getVertex(start)->visit();
    for(typename list<Edge<T,R>*>::iterator i = getVertex(start)->getEdges().begin(); i != getVertex(start)->getEdges().end(); ++i)
    {
        if((*i)->getV1() != getVertex(start))
        {
            if(!(*i)->getV1()->getVisited())
            {
                depth((*i)->getV1()->getData());
            }
        }
        else
        {
            if(!(*i)->getV2()->getVisited())
            {
                depth((*i)->getV2()->getData());
            }
        }
    }
}

/*********************************************************************************************************
 * template<typename T, typename R>
 * void Graph<T,R>::listEdges()
 *
 *  Purpose:    Display a list of edges
 *
 *  Entry:      No entry
 *
 *  Exit:       Console output
 *********************************************************************************************************/
template<typename T, typename R>
void Graph<T,R>::listEdges()
{
    for(typename list<Vertex<T,R>>::iterator i = m_vertex.begin(); i != m_vertex.end(); ++i)
    {
        (*i).listEdges();
    }
}

#endif // GRAPH_H

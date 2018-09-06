/*********************************************************************************************************
* Author:                   Aaron Day
* Date Created:             10/13/2015
* Last Modification Date:   11/15/2015
* Assignment Number:        7
* Filename:                 edge.h
*
* Overview:     Connection between two vertices in a graph
*
* Input:        Pointers to the two vertices it connects as well as optional weight and data
*
* Output:       No output
 *********************************************************************************************************/
#ifndef EDGE_H
#define EDGE_H

template<typename T, typename R>
class Vertex;

template<typename T, typename R>
class Edge
{
public:
    Edge(Vertex<T,R>* v1, Vertex<T,R>* v2, int weight = 0, R data = 0);
    ~Edge();

    Vertex<T,R>* getV1();
    Vertex<T,R>* getV2();
    int getWeight();
    R getData();

private:
    Vertex<T,R>* m_v1;
    Vertex<T,R>* m_v2;
    int m_weight;
    R m_data;
};

/*********************************************************************************************************
 * template<typename T, typename R>
 * Edge<T,R>::Edge(Vertex<T,R>* v1, Vertex<T,R>* v2, int weight, R data)
 *
 *  Purpose:    Create a new edge between two vertices
 *
 *  Entry:      Data of the two vertices it connects and an optional weight and data for the edge
 *
 *  Exit:       New edge created
 *********************************************************************************************************/
template<typename T, typename R>
Edge<T,R>::Edge(Vertex<T,R>* v1, Vertex<T,R>* v2, int weight, R data)
    :m_v1(v1), m_v2(v2), m_weight(weight), m_data(data){}

/*********************************************************************************************************
 * template<typename T, typename R>
 * Edge<T,R>::~Edge()
 *
 *  Purpose:    Safely delete an edge
 *
 *  Entry:      No entry
 *
 *  Exit:       Edge deleted
 *********************************************************************************************************/
template<typename T, typename R>
Edge<T,R>::~Edge()
{
    m_v1->getEdges().remove(this);
    m_v2->getEdges().remove(this);
    m_v1 = nullptr;
    m_v2 = nullptr;
}

/*********************************************************************************************************
 * template<typename T, typename R>
 * Vertex<T,R>* Edge<T,R>::getV1()
 *
 *  Purpose:    Return a pointer to the first vertex
 *
 *  Entry:      No entry
 *
 *  Exit:       Pointer to first vertex
 *********************************************************************************************************/
template<typename T, typename R>
Vertex<T,R>* Edge<T,R>::getV1()
{
    return m_v1;
}

/*********************************************************************************************************
 * template<typename T, typename R>
 * Vertex<T,R>* Edge<T,R>::getV2()
 *
 *  Purpose:    Return a pointer to the second vertex
 *
 *  Entry:      No entry
 *
 *  Exit:       Pointer to second vertex
 *********************************************************************************************************/
template<typename T, typename R>
Vertex<T,R>* Edge<T,R>::getV2()
{
    return m_v2;
}

/*********************************************************************************************************
 * template<typename T, typename R>
 * Vertex<T,R>* Edge<T,R>::getWeight()
 *
 *  Purpose:    Return the weight of the edge
 *
 *  Entry:      No entry
 *
 *  Exit:       Return weight
 *********************************************************************************************************/
template<typename T, typename R>
int Edge<T,R>::getWeight()
{
    return m_weight;
}

/*********************************************************************************************************
 * template<typename T, typename R>
 * Vertex<T,R>* Edge<T,R>::getData()
 *
 *  Purpose:    Return the data of the edge
 *
 *  Entry:      No entry
 *
 *  Exit:       Return data
 *********************************************************************************************************/
template<typename T, typename R>
R Edge<T,R>::getData()
{
    return m_data;
}

#endif // EDGE_H

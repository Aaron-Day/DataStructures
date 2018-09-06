/*********************************************************************************************************
* Author:                   Aaron Day
* Date Created:             10/15/2015
* Last Modification Date:   11/15/2015
* Assignment Number:        7
* Filename:                 driver.h
*
* Overview:     Used for testing the Graph, Vertex, and Edge classes
 *********************************************************************************************************/
#ifndef DRIVER_H
#define DRIVER_H

#include <string>
#include "graph.h"
#include "vertex.h"
#include "edge.h"

using namespace std;

void test_breadth()
{
    Graph<string,string> g;
    string A = "Vertex A";
    string B = "Vertex B";
    string C = "Vertex C";
    string D = "Vertex D";
    string E = "Vertex E";
    string AB = "Edge AB";
    string AC = "Edge AC";
    string AD = "Edge AD";
    string BE = "Edge BE";
    g.addVertex(A);
    g.addVertex(B);
    g.addVertex(C);
    g.addVertex(D);
    g.addVertex(E);
    g.addEdge(A, B, 5, AB);
    g.addEdge(A, C, 3, AC);
    g.addEdge(A, D, 5, AD);
    g.addEdge(B, E, 5, BE);
    g.breadth(A);
    cout << "Pass if order is: A B C D E" << endl;
}

void test_depth()
{
    Graph<string,string> g;
    string A = "Vertex A";
    string B = "Vertex B";
    string C = "Vertex C";
    string D = "Vertex D";
    string E = "Vertex E";
    string AB = "Edge AB";
    string AC = "Edge AC";
    string AD = "Edge AD";
    string BE = "Edge BE";
    g.addVertex(A);
    g.addVertex(B);
    g.addVertex(C);
    g.addVertex(D);
    g.addVertex(E);
    g.addEdge(A, B, 5, AB);
    g.addEdge(A, C, 3, AC);
    g.addEdge(A, D, 5, AD);
    g.addEdge(B, E, 5, BE);
    g.depth(A);
    cout << "Pass if order is: A B E C D" << endl;
}

#endif // DRIVER_H


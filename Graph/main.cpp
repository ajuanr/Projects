//
//  main.cpp
//  Graph
//
//  Created by Juan Ruiz on 6/21/18.
//  Copyright © 2018 Juan Ruiz. All rights reserved.
//

#include <iostream>
#include "Graph.hpp"

using namespace std;

void printEdge(const Edge& e);
void printEdges(const list<Edge>&);
void printGraph(const Graph&);

int main(int argc, const char * argv[]) {
    Vertex a("a");
    Vertex b("b");
    Vertex c("c");
    Vertex d("d");
    Vertex e("e");
    Vertex f("f");
    Vertex g("g");
    Vertex h("h");
    Vertex i("i");
    Vertex j("j");
    
    Graph graph;
    graph.addEdge(a, b, 3);
    graph.addEdge(a, e, 6);
    graph.addEdge(a, f, 8);
    graph.addEdge(b, c, 10);
    graph.addEdge(b, d, 2);
    graph.addEdge(b, e, 1);
    graph.addEdge(c, d, 3);
    graph.addEdge(c, i, 7);
    graph.addEdge(c, j, 8);
    graph.addEdge(d, g, 4);
    graph.addEdge(d, h, 5);
    graph.addEdge(e, g, 2);
    graph.addEdge(h, i, 6);
    
    printGraph(graph);
    
    Graph simple;
    simple.addEdge(a,b, 7);
    simple.addEdge(a,e, 4);
    simple.addEdge(b,e, 1);
    
    Edge t1(a,b);
    Edge t2(b,a);
    Edge t3(a,b);
    
    cout << graph.hasCycle() << endl;
    
    Graph simCpy(graph.MST());
    cout << endl;
    printGraph(simCpy);
    
    return 0;
}

void printEdge(const Edge& e) {
    cout << e.getVertex1().id << "-";
    if (e.getWeight() != 0) {
    cout << e.getWeight();
    }
    cout << "-" << e.getVertex2().id << endl;
}

void printEdges(const list<Edge> &edges) {
    for (list<Edge>::const_iterator iter = edges.begin();
         iter != edges.end(); ++iter) {
        printEdge(*iter);
    }
    cout << endl;
}

void printGraph(const Graph& graph) {
    printEdges(graph.getGraph());
}

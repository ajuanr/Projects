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
void printGraph(const list<Edge>&);

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
    graph.addEdge(a, b);
    graph.addEdge(a, e);
    graph.addEdge(a, f);
    graph.addEdge(b, c);
    graph.addEdge(b, d);
    graph.addEdge(b, e);
    graph.addEdge(c, d);
    graph.addEdge(c, i);
    graph.addEdge(c, j);
    graph.addEdge(d, g);
    graph.addEdge(e, g);
    graph.addEdge(f, a);
    graph.addEdge(h, i);
    
    //printGraph(graph.getGraph());
    
    Graph simple;
    simple.addEdge(a,b);
    simple.addEdge(a,e);
    //simple.addEdge(b,e);
    
    Edge t1(a,b);
    Edge t2(b,a);
    Edge t3(a,b);
    
    cout << simple.hasCycle() << endl;
    
    return 0;
}

void printEdge(const Edge& e) {
    cout << e.getVertex1().id << "---" << e.getVertex2().id << endl;
}

void printGraph(const list<Edge> &edges) {
    for (list<Edge>::const_iterator iter = edges.begin();
         iter != edges.end(); ++iter) {
        printEdge(*iter);
    }
    cout << endl;
}

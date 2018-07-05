//
//  Graph.hpp
//  Graph
//
//  Created by Juan Ruiz on 6/21/18.
//  Copyright © 2018 Juan Ruiz. All rights reserved.
//

#ifndef Graph_hpp
#define Graph_hpp

#include <list>
#include "Edge.hpp"

class Graph {
public:
    typedef std::list<Edge> EdgeLst;
    Graph() {}              // default constructor. Empty graph
    Graph(const Graph& g) {graph = g.graph;}
    void addEdge(const Edge& e);
    void addEdge(Vertex u, Vertex v, int weight = 0) {addEdge(Edge(u,v,weight));}
    void removeEdge(const Edge &e);
    
    const EdgeLst& getGraph() const {return graph;}
    void print() const;
    size_t size() const { return graph.size();}
    
    bool hasCycle() const; // returns true if graph has cycle
    Graph MST() const;
private:
    EdgeLst graph;
    
    bool hasCommonVertex(const Edge &e1, const Edge &e2) const;
    bool hasCycleUtil(const Edge&, EdgeLst&, const Edge&) const;
    
};

#endif /* Graph_hpp */

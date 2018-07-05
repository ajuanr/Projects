//
//  Graph.cpp
//  Graph
//
//  Created by Juan Ruiz on 6/21/18.
//  Copyright © 2018 Juan Ruiz. All rights reserved.
//

#include "Graph.hpp"
#include <algorithm>
#include <iostream>

void Graph::addEdge(const Edge &e) {
    // only add edge if it's not already in the graph
    if (std::find(graph.begin(), graph.end(), e) == graph.end()) {
        graph.push_back(e);
    }
}

void Graph::removeEdge(const Edge &e) {
    // check if edge is in graph
    std::list<Edge>::iterator edge = std::find(graph.begin(), graph.end(), e);
    // only remove edge if it was found in the graph
    if ( edge != graph.end()) {
        graph.remove(e);
    }
}

// e1 and e2 should not be the same edge
bool Graph::hasCommonVertex(const Edge &e1, const Edge &e2) const {
    return ( !(e1.getVertex1().id.compare(e2.getVertex1().id)) ||
             !(e1.getVertex1().id.compare(e2.getVertex2().id)) ||
             !(e1.getVertex2().id.compare(e2.getVertex1().id)) ||
             !(e1.getVertex2().id.compare(e2.getVertex2().id))
            );
}

bool Graph::hasCycle() const{
    EdgeLst::const_iterator iter;
    // go through all the edges in the graph
    for (iter = graph.begin(); iter != graph.end(); ++iter) {
        EdgeLst *edges = new EdgeLst();
        edges->push_back(*iter);
        if ( hasCycleUtil(*iter, *edges, *iter) ) {
            delete edges;
            return true;
        }
        delete edges;
    }
    return false;
}

bool Graph::hasCycleUtil(const Edge& e, EdgeLst& edges, const Edge& parent) const{
    const uint8_t minCycleSize = 3;
    EdgeLst::const_iterator iter;
    // go through all the edges in the graph
    for (iter = graph.begin(); iter != graph.end(); ++iter) {
        if (e == *iter) continue;
        if ( hasCommonVertex(e, *iter) ) {
            // check if edge *iter not already in list
            if (find(edges.begin(), edges.end(), *iter) == edges.end()) {
                edges.push_back(*iter);
                if (hasCycleUtil(*iter, edges, parent))
                    return true;
            }
            // back at start. Check if enough edges to form a cycle
            else if (edges.size() >= minCycleSize  && *iter == parent
                     && hasCommonVertex(*iter, parent)) {
                return true;
            }
            else {} // don't do anything
        }
    }
    return false;
}

void Graph::print() const {
    for (EdgeLst::const_iterator iter = graph.begin();
         iter != graph.end(); ++iter) {
        iter->print();
    }
    std::cout << std::endl;
}

// Create an MST using Kruskal's algorithm
Graph Graph::MST() const {
    Graph out;
    EdgeLst copy = graph;
    copy.sort();
    
    
    EdgeLst::const_iterator edge;
    for (edge=copy.begin(); edge != copy.end(); ++edge) {
        // add edge and make sure it does not create a cycle
        out.addEdge(*edge);
        if ( out.hasCycle() ) out.removeEdge(*edge);
    }
    return out;
}

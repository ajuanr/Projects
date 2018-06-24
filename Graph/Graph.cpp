//
//  Graph.cpp
//  Graph
//
//  Created by Juan Ruiz on 6/21/18.
//  Copyright © 2018 Juan Ruiz. All rights reserved.
//

#include "Graph.hpp"
#include <algorithm>

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
        graph.remove(*edge);
    }
}

// assumes e1 and e2 are not the same edge
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
        if ( hasCycleUtil(*iter, *edges, *iter) ) {
            delete edges;
            return true;
        }
        delete edges;
    }
    return false;
}

bool Graph::hasCycleUtil(const Edge& e, EdgeLst& edges, const Edge& parent) const{
    edges.push_back(e);
    const uint8_t minCycleSize = 3;
    EdgeLst::const_iterator iter;
    // go through all the edges in the graph
    for (iter = graph.begin(); iter != graph.end(); ++iter) {
        if (e == *iter) continue;
        if ( hasCommonVertex(e, *iter) ) {
            // check if edge *iter not already in list
            if (find(edges.begin(), edges.end(), *iter) == edges.end()) {
                if (hasCycleUtil(*iter, edges, parent))
                    return true;
            }
            // back at start. Check if enough edges to form a cycle
            else if (edges.size() >= minCycleSize  && *iter == parent) {
                return true;
            }
            else {} // don't do anything
        }
    }
    return false;
}

bool Graph::check() const {
    Edge e = *graph.begin();
    EdgeLst *edges = new EdgeLst();
    return hasCycleUtil(e, *edges, e);
}

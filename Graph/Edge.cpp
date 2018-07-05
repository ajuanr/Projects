//
//  Edge.cpp
//  Graph
//
//  Created by Juan Ruiz on 6/21/18.
//  Copyright © 2018 Juan Ruiz. All rights reserved.
//

#include "Edge.hpp"
#include <iostream>

bool Edge::operator==(const Edge& rhs) const {
    // check if first vertex matches the vertex we're comparing
    if (!(this->vertex1.id.compare(rhs.getVertex1().id)) ||
        !(this->vertex1.id.compare(rhs.getVertex2().id))) {
        // check if second vertex matches
        if (!(this->vertex2.id.compare(rhs.getVertex1().id)) ||
            !(this->vertex2.id.compare(rhs.getVertex2().id))) {
            return true;
        }
    }
    // both vertices did not match
    return false;
}

bool Edge::operator<(const Edge& rhs) const {
    return (this->weight < rhs.getWeight());
}

void Edge::print() const {
    std::cout << vertex1.id << "-";
    if (weight != 0) {
        std::cout << weight;
    }
    std::cout << "--" << vertex2.id << std::endl;
}

//
//  Edge.cpp
//  Graph
//
//  Created by Juan Ruiz on 6/21/18.
//  Copyright © 2018 Juan Ruiz. All rights reserved.
//

#include "Edge.hpp"

bool Edge::operator==(const Edge& rhs) const {
    // check if first vertex matches the vertex we're comparing
    if (!(this->vertex1.id.compare(rhs.getVertex1().id)) ||
        !(this->vertex1.id.compare(rhs.getVertex2().id))) {
        
        if (!(this->vertex2.id.compare(rhs.getVertex1().id)) ||
            !(this->vertex2.id.compare(rhs.getVertex2().id))) {
            return true;
        }
    }
    return false;
}

bool Edge::operator<(const Edge& rhs) const {
    return (weight < rhs.getWeight());
}

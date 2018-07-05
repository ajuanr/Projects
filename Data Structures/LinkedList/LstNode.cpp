//
//  LstNode.cpp
//  LnkedList
//
//  Created by Juan Ruiz on 7/5/18.
//  Copyright © 2018 Juan Ruiz. All rights reserved.
//

#include "LstNode.hpp"

LstNode::LstNode(const LstNode& listnode) {
    this->set(listnode.get());
    if (listnode.getNext()) {
        next = new LstNode(listnode.getNext()->get());
    }
}

//creates a new node and current node points to it if next doesn't exist
// else, update data in next
void LstNode::setNext(int data) {
    if (next) {
        next->set(data);
    }
    else {
        next = new LstNode(data);
    }
}

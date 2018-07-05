//
//  LstNode.hpp
//  LnkedList
//
//  Created by Juan Ruiz on 7/5/18.
//  Copyright © 2018 Juan Ruiz. All rights reserved.
//

// this class derives for the Node class.
// it adds a pointer to the next LstNode

#ifndef LstNode_hpp
#define LstNode_hpp

#include "Node.hpp"

class LstNode: public Node {
public:
    LstNode():Node() {}
    LstNode(int data):Node(data), next(0) {}
    LstNode(const LstNode&);
    
    void chain(LstNode *newLink) {this->next = newLink;} // point to exisiting node
    void unchain() { this->next = 0;}
    
    LstNode* getNext() {return next;}
    const LstNode* getNext() const {return next;}
    
private:
    LstNode *next;
};

#endif /* LstNode_hpp */

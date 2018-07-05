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
    ~LstNode() {delete next;}
    
    void setNext(LstNode *next) {this->next = next;} // point to exisiting node
    void setNext(int);
    
    LstNode* getNext() {return next;}
    LstNode* getNext() const {return next;}
    
    void removeNext() {deleteNext();}
    
private:
    LstNode *next;
    
    void deleteNext() {if (next) {delete next; next = 0;}}
};

#endif /* LstNode_hpp */

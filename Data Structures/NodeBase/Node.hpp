//
//  Node.hpp
//  
//
//  Created by Juan Ruiz on 7/5/18.
//
// This is a base class for a node, that will be used in creating other nodes,
// i.e, for lists, graphs, etc.

#ifndef Node_hpp
#define Node_hpp

class Node {
public:
    Node():data() {}
    Node(int data): data(data) {}
    virtual ~Node() {}
    
    void set(int data) {this->data = data;}
    int get() const {return data;}
private:
    int data;
};



#endif /* Node_hpp */

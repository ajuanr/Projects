//
//  LnkdLst.hpp
//  LnkedList
//
//  Created by Juan Ruiz on 7/5/18.
//  Copyright © 2018 Juan Ruiz. All rights reserved.
//

#ifndef LnkdLst_hpp
#define LnkdLst_hpp

#include "LstNode.hpp"

class LnkdLst {
public:
    LnkdLst():head(0) {}
    LnkdLst(int);
    ~LnkdLst();
    
    void append(int);
    void remove(int);
    void print() const;
    void sort();
    
private:
    LstNode *head;
    unsigned int size = 0;
    
    LstNode* create(int); // create a new node and return it
    void destroy(LstNode*);
    
    void removeHead();
    LstNode* sortUtil(LstNode*);
    void splitHalfs(LstNode*, int&, int&);
};

#endif /* LnkdLst_hpp */

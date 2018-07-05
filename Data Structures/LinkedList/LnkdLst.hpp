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
    
    void add(int);
    void remove(int);
    void print() const;
    
private:
    LstNode *head;
    
    LstNode* create(int); // create a new node and return it
    void destroy(LstNode*);
    
    void removeHead();
};

#endif /* LnkdLst_hpp */

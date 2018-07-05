//
//  LnkdLst.cpp
//  LnkedList
//
//  Created by Juan Ruiz on 7/5/18.
//  Copyright © 2018 Juan Ruiz. All rights reserved.
//

#include "LnkdLst.hpp"
#include <iostream>

LnkdLst::LnkdLst(int data) {
    head = create(data);
}

LnkdLst::~LnkdLst() {
    if (head) {
        LstNode *prev, *curr;
        prev = head;
        curr = prev->getNext();
        destroy(prev);
        while (curr) {
            prev = curr;
            destroy(prev);
            curr = curr->getNext();
        }
        destroy(prev);
    }
}

LstNode* LnkdLst::create(int data) {
    return new LstNode(data);
}

void LnkdLst::destroy(LstNode *node) {
    if (node) {
        delete node;
        node = 0;
    }
}

void LnkdLst::add(int data) {
    if (head) {
        LstNode* worker = head;
        while (worker->getNext()) {
            worker = worker->getNext();
        }
        worker->chain(new LstNode(data));
    }
    else {
        head = create(data);
    }
}

void LnkdLst::remove(int data) {
    if (head) {
        LstNode *previous = head;
        LstNode *current = head;
        while (current->get() != data && current->getNext()) {
            previous = current;
            current = current->getNext();
        }
        if (current == head) {
            removeHead();
        }
        else if (!current->getNext()) {
            previous->unchain();
            destroy(current);
        }
        else {
            previous->chain(current->getNext());
            destroy(current);
        }
        
    
    }
}

void LnkdLst::print() const {
    if (head) {
        LstNode* worker = head;
        std::cout << worker->get();
        while ( (worker = worker->getNext()) ) {
            std::cout << "->" << worker->get();
        }
        std::cout << std::endl;
    }
}

// utility function to remove head of list
void LnkdLst::removeHead() {
    if (head) {
        if (head->getNext()) {
            LstNode *temp = head;
            head = head->getNext();
            destroy(temp);
        }
        else {
            destroy(head);
        }
    }
}

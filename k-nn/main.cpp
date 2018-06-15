//
//  main.cpp
//  SimpleVec
//
//  Created by Juan Ruiz on 6/12/18.
//  Copyright © 2018 Juan Ruiz. All rights reserved.
//

#include <iostream>
#include "KNN_Classifier.hpp"
#include "Tuple.hpp"

#include <cstdlib>

using namespace std;

/* for testing */
vector<float> randVec() {
    vector<float> v;
    for (int i = 0; i != 10; ++i) {
        float num = float(rand() % 9 + 1);
        v.push_back(num);
    }
    return v;
}

Tuple makeTuple() {
    unsigned int label = rand() % 3 + 1;
    return Tuple(label, randVec());
}
/**************************/

template <class T>
void printDataset(const Dataset<T> &db) {
    for (size_t i = 0; i != db.numRows(); ++i) {
        for (size_t j = 0; j != db.numCols(); ++j) {
            cout << db.getTuple(i).getFeature(j) << " ";
        }
        cout << endl;
    }
}

int main(int argc, const char * argv[]) {
    vector<float> vec;
    vec.push_back(7);
    vec.push_back(4);
    vec.push_back(3);
    
    vector<float> vec2;
    vec2.push_back(17);
    vec2.push_back(6);
    vec2.push_back(2);
    Tuple t(2, vec2);
    cout << t.distance(vec, 2) << endl;
    
    Dataset<Tuple> db;
    db.addTuple(Tuple(1, vec));
    db.addTuple(Tuple(vec2));
    
    printDataset(db);
    
    return 0;
}

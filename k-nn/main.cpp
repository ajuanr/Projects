//
//  main.cpp
//  SimpleVec
//
//  Created by Juan Ruiz on 6/12/18.
//  Copyright © 2018 Juan Ruiz. All rights reserved.
//

#include <iostream>
#include "KNN_Classifier.hpp"

#include <cstdlib>

using namespace std;

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

int main(int argc, const char * argv[]) {
    Dataset db;
    for (int i = 0; i != 10; ++i) {
        db.addTuple(makeTuple());
    }
    
    for (int i = 0; i != db.numRows(); ++i) {
        for (int j = 0; j != db.numCols(); ++j) {
            cout << db.getTuple(i).getFeature(j) << " ";
        }
        cout << "  " << db.getTuple(i).getClass() << endl;
    }
    return 0;
}

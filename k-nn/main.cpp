//
//  main.cpp
//  SimpleVec
//
//  Created by Juan Ruiz on 6/12/18.
//  Copyright © 2018 Juan Ruiz. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include "KNN_Classifier.hpp"

#include <cstdlib>

using namespace std;

/* for testing */
vector<float> randVec() {
    vector<float> v;
    for (int i = 0; i != 20; ++i) {
        float num = float(rand() % 20 + 1);
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
            cout << setw(3) << db.getTuple(i).getFeature(j) << " ";
        }
        cout << "  " << db.getTuple(i).getClass() << endl;
    }
    cout << endl;
}

int main(int argc, const char * argv[]) {
    Dataset<Tuple> data;
    for (int i = 0; i != 20; ++i) {
        data.addTuple(makeTuple());
    }
    printDataset(data);
    
    cout << endl;
    
    KNN knn(data);
    knn.fillDistancesMatrix();
    Dataset<myQ> distances = knn.getDistances();
    //printDataset(distances);
    for (int i = 0; i != distances.numRows(); ++i) {
        for (int j = 0; j != 3; ++j) {
            //cout << setw(3) << distances.getTuple(i).top().getDist() << " ";
            cout << setw(3) << distances.getTuple(i).top().getLabel() << " ";
            distances.editTuple(i).pop();
        }
        cout << endl;
    }
    
    
    return 0;
}

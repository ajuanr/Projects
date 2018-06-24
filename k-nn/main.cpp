//
//  main.cpp
//  SimpleVec
//
//  Created by Juan Ruiz on 6/12/18.
//  Copyright © 2018 Juan Ruiz. All rights reserved.
//

#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "KNN_Classifier.hpp"
#include "common.hpp"

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

/****** Get Input from file ********/
// Parse a single line. Return a vector containing the feature data
Tuple parseLine(const string line) {
    stringstream features;
    features << line;
    Tuple output;
    float temp;
    if (features>>temp) {output.setClass(temp);}
    while(features>>temp) {output.addFeature(temp);}
    return output;
}

// Read the data and return a vector containing the data
Dataset<Tuple> readData(const string fileName){
    cout << "\nUsing: " << fileName << endl << endl;
    ifstream input;
    input.open(fileName, ifstream::in);
    Dataset<Tuple> output;
    if (!input.is_open()) {
        cout << "File failed to open\n";
        return output;
    }
    string line;
    while (getline (input,line) ) {
        output.addTuple(parseLine(line));
    }
    input.close();
    return output;
}


template <class T>
void printDataset(const Dataset<T> &db) {
    for (size_t i = 0; i != db.numRows(); ++i) {
        for (size_t j = 0; j != db.numCols(); ++j) {
            cout << setw(10) << db.getTuple(i).getFeature(j) << " ";
        }
        cout << "  " << db.getTuple(i).getClass() << endl;
    }
    cout << endl;
}

int main(int argc, const char * argv[]) {
    Dataset<Tuple> data(readData("CS170Smalltestdata__44.txt"));
    //Dataset<Tuple> data(readData("CS170BIGtestdata__4.txt"));
    data.normalize();
    KNN knn(data);
    knn.fillDistancesMatrix();
    
    for (int k = 1; k <=21; k += 2 ) {
        cout << "k: " << k << endl;
        std::vector<unsigned int> v(knn.classify(k));

        for (int i = 0; i != v.size(); ++i) {
            cout << v.at(i) << endl;
        }
        cout << endl;
    }
    return 0;
}

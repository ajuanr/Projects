//
//  dataSet.hpp
//  KNN
//
//  Created by Juan Ruiz on 6/14/18.
//  Copyright © 2018 Juan Ruiz. All rights reserved.
//

#ifndef dataSet_hpp
#define dataSet_hpp

#include "Tuple.hpp"

class Dataset {
private:
public:
    Dataset() {}                          // empty default constructor
    void addTuple(Tuple t) {dataSet.push_back(t);}
    void removeTuple(size_t tuple) {dataSet.erase(dataSet.begin()+tuple);}
    const Tuple& getTuple(size_t tuple) const {return dataSet.at(tuple);}
    const size_t numRows() { return dataSet.size();}
    const size_t numCols() { return numRows() ? dataSet.at(0).size() : 0;}
private:
    std::vector<Tuple> dataSet;
};

#endif /* dataSet_hpp */

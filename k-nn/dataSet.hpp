//
//  dataSet.hpp
//  KNN
//
//  Created by Juan Ruiz on 6/14/18.
//  Copyright © 2018 Juan Ruiz. All rights reserved.
//

#ifndef dataSet_hpp
#define dataSet_hpp

#include <vector>

template<class T>
class Dataset {
private:
public:
    Dataset() {}                          // empty default constructor
    void addTuple(T t) {data.push_back(t);}
    void removeTuple(size_t tuple) {data.erase(data.begin()+tuple);}
    const T& getTuple(size_t tuple) const {return data.at(tuple);}
    T& editTuple(size_t tuple) {return data.at(tuple);}
    const size_t numRows() const { return data.size();}
    const size_t numCols() const { return numRows() ? data.at(0).size() : 0;}
private:
    std::vector<T> data;
};

#endif /* dataSet_hpp */

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
#include "Tuple.hpp"

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
    void normalize();
private:
    std::vector<T> data;
    
    float stdDev() const;
    std::vector<float> mean() const;
};

template<class T>
void Dataset<T>::normalize() {
    std::vector<float> means = mean();
    
    std::vector<float> temp;
    std::vector<T> normalized;
    
    // perform the normalization
    for (int i = 0; i != numRows(); ++i) {
        for (int j = 0; j != numCols(); ++j) {
            float n = (data.at(i).getFeature(j) - means[j]) / (numRows() - 1);
            temp.push_back(n);
        }
        normalized.push_back(Tuple(data.at(i).getClass(), temp));
        temp.clear();
    }
    data = normalized;
}

template<class T>
std::vector<float> Dataset<T>::mean() const {
    // calculate the  mean
    std::vector<float> sums(numCols(), 0.0f);
    // calculate the sum of every feature
    for (size_t i = 0; i != numRows(); ++i) {         // iterate through the rows
        for (size_t j = 0; j != numCols(); ++j) {     // iterate through the features
            sums[j] += data.at(i).getFeature(j);
        }
    }
    // calculate the mean of the features
    for (int i = 0; i != sums.size(); ++i) {
        sums[i] /= numRows();
    }
    return sums;
}

#endif /* dataSet_hpp */

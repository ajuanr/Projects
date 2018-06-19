//
//  KNN_Classifier.cpp
//  SimpleVec
//
//  Created by Juan Ruiz on 6/14/18.
//  Copyright © 2018 Juan Ruiz. All rights reserved.
//

#include "KNN_Classifier.hpp"
#include <map>
#include <iostream>

void KNN::fillDistancesMatrix() {
    for (size_t i = 0; i != data.numRows(); ++i ) {
        // create a new tuple for the current row
        Tuple rowi(data.getTuple(i));
        myQ temp;
        for (size_t j = 0; j != data.numRows(); ++j) {
            if (i == j) continue; // don't compare row with itself
            const Tuple rowj(data.getTuple(j));
            // compare row i to row j and add the distance to the queue
            temp.emplace(rowj.getClass(), rowi.distance(rowj.getFeatures(), 2));
        }
        distancesMatrix.addTuple(temp);
    }
}

unsigned int KNN::vote(const labelsMap &m) const {
    unsigned int bestClass = 0;
    
    unsigned int max = 0;
    for (labelsMap::const_iterator iter = m.begin(); iter != m.end(); ++iter) {
        if (iter->second > bestClass) {
            bestClass =  iter->first;
            max = iter->second;
        }
    }
    return bestClass;
}

KNN::labelsVec KNN::getLabels(unsigned int k) const {
    Dataset<myQ> closestK = distancesMatrix;
    labelsVec predictedLabels;
    labelsMap m;
    
    for (size_t tuple = 0; tuple != closestK.numRows(); ++tuple) {
        unsigned int voteFor;
        for (unsigned int i = 0; i != k; ++i) {
            voteFor = closestK.getTuple(tuple).top().getLabel();
            closestK.editTuple(tuple).pop();
            m[voteFor]++;
        }
        predictedLabels.push_back(vote(m));
        m.clear();
    }
    return predictedLabels;
}

std::vector<unsigned int> KNN::classify(unsigned int k) const {
// 0 = number right
// 1 = number wrong
    labelsVec predictedLabels = getLabels(k);
    std::vector<unsigned int> ret(2,0);
    labelsVec labels = getLabels(k);
    for (size_t i = 0; i != data.numRows(); ++i) {
        if (data.getTuple(i).getClass() == predictedLabels.at(i))
            ++ret[0];
        else
            ++ret[1];
    }
    return ret;
}

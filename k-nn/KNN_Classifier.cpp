//
//  KNN_Classifier.cpp
//  SimpleVec
//
//  Created by Juan Ruiz on 6/14/18.
//  Copyright © 2018 Juan Ruiz. All rights reserved.
//

#include "KNN_Classifier.hpp"

void KNN::fillDistancesMatrix() {
    for (size_t i = 0; i != data.numRows(); ++i ) {
        // create a new tuple for the current row
        Tuple rowi(data.getTuple(i));
        myQ temp;
        for (size_t j = 0; j != data.numCols(); ++j) {
            if (i == j) continue; // don't compare row with itself
            const Tuple rowj(data.getTuple(j));
            // compare row i to row j and add the distance to the queue
            temp.emplace(rowj.getClass(), rowi.distance(rowj.getFeatures(), 2));
        }
        distancesMatrix.addTuple(temp);
    }
}

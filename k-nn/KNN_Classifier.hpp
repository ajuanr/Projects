//
//  KNN_Classifier.hpp
//  SimpleVec
//
//  Created by Juan Ruiz on 6/14/18.
//  Copyright © 2018 Juan Ruiz. All rights reserved.
//

#ifndef KNN_Classifier_hpp
#define KNN_Classifier_hpp

#include <queue>
#include "dataSet.hpp"
#include "Tuple.hpp"

/* This class holds the distance from tuple i to tuple j and the label of tuple j
 */
class classDist{
public:
    classDist(): label(0), dist(0) {}
    classDist(unsigned int label, float dist): label(label), dist(dist) {}
    unsigned int getLabel() const {return label;}
    float getDist() const {return dist;}
private:
    unsigned int label;
    float dist;
};

// this class is solely used for the comparison function of the priority queue
class Compare{
public:
    bool operator()(classDist &a, classDist &b) {
        return a.getDist() > b.getDist();
    }
};

typedef std::priority_queue<classDist, std::vector<classDist>, Compare> myQ;

class KNN{
public:
    KNN() {}
    KNN(Dataset<Tuple> data): data(data) {}
    const Dataset<myQ>& getDistances() const { return distancesMatrix;}
    void fillDistancesMatrix();
    
private:
    Dataset<Tuple> data;
    Dataset<myQ> distancesMatrix; // (tuple x tuple) distances
    
};

#endif /* KNN_Classifier_hpp */

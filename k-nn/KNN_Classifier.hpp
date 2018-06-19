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
#include <map>
#include "dataSet.hpp"
#include "Tuple.hpp"

/* This class holds the lp distance from tuple i to tuple j
 * and the label of tuple j
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
    typedef std::map<unsigned int, unsigned int> labelsMap;
    typedef std::vector<unsigned int> labelsVec;
public:
    KNN() {}
    KNN(Dataset<Tuple> data): data(data) {getLabels();}
    const Dataset<myQ>& getDistances() const { return distancesMatrix;}
    void fillDistancesMatrix();
    std::vector<unsigned int>& classLabels() const;
    labelsVec getLabels(unsigned int k=1) const;
    labelsVec classify(unsigned int k = 1) const;
    
private:
    Dataset<Tuple> data;            // features and class label
    Dataset<myQ> distancesMatrix;   // (tuple x tuple) distances
    
    unsigned int vote(const labelsMap&) const;
    
};

#endif /* KNN_Classifier_hpp */

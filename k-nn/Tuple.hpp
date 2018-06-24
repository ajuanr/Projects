//
//  Tuple.hpp
//  SimpleVec
//
//  Created by Juan Ruiz on 6/14/18.
//  Copyright © 2018 Juan Ruiz. All rights reserved.
//

/* Each tuple is a datapoint the dataset
 * Tuples correspond to the rows,
 * features correspond to the columns
 * Will need to specify the location of the class label.
 *  Usually the first or last attribute
 */

#ifndef Tuple_hpp
#define Tuple_hpp

#include <vector>
#include "common.hpp"

// defines a row in a database. The class label is optional
class Tuple{
private:
    typedef std::vector<float> vecFloat;
public:
    Tuple():classLabel(invalidClass) {}   
    Tuple(uint cl, vecFloat vf): classLabel(cl), features(vf) {}
    explicit Tuple(vecFloat vf): classLabel(invalidClass), features(vf) {}
    uint getClass() const {return classLabel;}
    float getFeature(size_t feature) const { return features.at(feature); }
    const vecFloat& getFeatures() const { return features; }
    
    void addFeature(const float feature) { features.push_back(feature); }
    void setClass(unsigned int label) {classLabel = label;}
    float distance(const vecFloat&, uint) const;
    size_t size() const { return features.size(); }
    
private:
    uint classLabel;
    vecFloat features;
};

#endif /* Tuple_hpp */

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

class Tuple{
private:
    typedef std::vector<float> vecFloat;
public:
    Tuple():classLabel(-1) {}           // -1 should not be a valid class label
    Tuple(size_t cl, vecFloat vf): classLabel(cl), features(vf) {}
    size_t getClass() const {return classLabel;}
    float getFeature(size_t feature) const { return features.at(feature); }
    const vecFloat& getFeatures() const { return features; }
    
    void addFeature(float feature) { features.push_back(feature); }
    size_t size() const { return features.size(); }
    
private:
    size_t classLabel;
    vecFloat features;
};

#endif /* Tuple_hpp */

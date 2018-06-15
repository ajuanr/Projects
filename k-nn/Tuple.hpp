//
//  Tuple.hpp
//  SimpleVec
//
//  Created by Juan Ruiz on 6/14/18.
//  Copyright © 2018 Juan Ruiz. All rights reserved.
//

#ifndef Tuple_hpp
#define Tuple_hpp

#include <vector>

class datapoint{
public:
    datapoint():classLabel(-1) {}
    unsigned int classLabel;
    std::vector<float> features;
};

#endif /* Tuple_hpp */

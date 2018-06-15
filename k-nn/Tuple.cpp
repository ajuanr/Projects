//
//  Tuple.cpp
//  SimpleVec
//
//  Created by Juan Ruiz on 6/14/18.
//  Copyright © 2018 Juan Ruiz. All rights reserved.
//

#include "Tuple.hpp"
#include <cmath>

/* returns manhattan distance if 1
 * return sum of squares if 2
 */
float Tuple::distance(const vecFloat &vec, uint lp) const {
    float dist= 0.0;
    for (size_t i = 0; i != features.size(); ++i) {
        if (lp == 1) {
            dist += abs(features.at(i) - vec.at(i));
        }
        else {
            dist += (features.at(i) - vec.at(i)) * (features.at(i) - vec.at(i));
        }
    }
    return dist;
}

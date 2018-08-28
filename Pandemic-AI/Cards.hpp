//
//  Cards.hpp
//  Pandemic-AI
//
//  /* This class holds the different playing cards that are part of the game */
//
//  Created by Juan Ruiz on 8/28/18.
//  Copyright © 2018 Juan Ruiz. All rights reserved.
//

#ifndef Cards_hpp
#define Cards_hpp

#include <string>

// astract base class
class Card {
public:
    Card(std::string name): name(name) {}
    std::string cardName() const {return name;}
private:
    std::string name;
};



#endif /* Cards_hpp */

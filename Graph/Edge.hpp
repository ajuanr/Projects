//
//  Edge.hpp
//  Graph
//
//  Created by Juan Ruiz on 6/21/18.
//  Copyright © 2018 Juan Ruiz. All rights reserved.
//

#ifndef Edge_hpp
#define Edge_hpp

#include <string>

struct Vertex {
    Vertex() {}
    explicit Vertex(std::string s):id(s) {}
    std::string id;
};

class Edge{
public:
    Edge(Vertex v1, Vertex v2, int w=0){vertex1=v1; vertex2=v2; weight=w;}
    
    const Vertex& getVertex1() const {return vertex1;}
    const Vertex& getVertex2() const {return vertex2;}
    int getWeight() const { return weight;}
    
    void setVertex1(Vertex& v) {vertex1 = v;}
    void setVertex2(Vertex& v) {vertex2 = v;}
    void setWeight(int w) { weight=w;}
    
    bool operator==(const Edge& rhs) const;
    bool operator!=(const Edge& rhs) const { return !(*this == rhs); }
    bool operator<(const Edge& rhs) const;
    
private:
    Vertex vertex1;
    Vertex vertex2;
    int weight;
};

#endif /* Edge_hpp */

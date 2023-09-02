#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <iostream>
#include <vector>
#include <list>
#include <utility>

struct Vertex {
    static inline int identificatorClass = 0; 
    int identificador;   
    std::list<Vertex*> adjacencys; 

    Vertex(): identificador(++Vertex::identificatorClass), adjacencys(0) {}
    
    bool operator == (const Vertex& vertex) { return this->identificador == vertex.identificador; }

    bool operator > (const Vertex& vertex) { return this->identificador > vertex.identificador; }

    bool operator >= (const Vertex& vertex) { return this->identificador >= vertex.identificador; }

    bool operator < (const Vertex& vertex) { return this->identificador < vertex.identificador; }

    bool operator <= (const Vertex& vertex) { return this->identificador <= vertex.identificador; }

    bool operator != (const Vertex& vertex) { return this->identificador != vertex.identificador; }

    friend std::ostream& operator<<(std::ostream& os, const Vertex& vertex) {
        if (vertex.adjacencys.empty())
            os << vertex.identificador;
        else {
            os << vertex.identificador << " -> ";    
            for (const auto& it : vertex.adjacencys)
                os << it->identificador << " ";
        }
        return os;
    }
};

#endif
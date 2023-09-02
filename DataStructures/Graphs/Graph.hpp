#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "Vertex.hpp"
#include <queue>
#include <stack>


class Graph {
private:
    int vertexesAmount;
    int edgesAmount;
    bool isDirected;
    std::list<Vertex*> vertexes;
    std::vector<std::pair<int, int>> edges;
    void configureEdges(std::vector<std::pair<int, int>> edges);
public:
    Graph(std::list<Vertex*> vertex,
        std::vector<std::pair<int, int>> edges, bool isDirected);
    Graph(const Graph& graph);

    Graph();

    ~Graph();
    
    int getAmountOfEdges() { return this->edgesAmount; }

    int getAmountOfVertexes() { return this->vertexesAmount; }

    std::list<Vertex*> getVertexes() { return this->vertexes; }

    void breadthFirstSearch(Vertex* start, Vertex* destiny);  

    void depthFirstSearch(Vertex* start);

    friend std::ostream& operator<< (std::ostream& os, const Graph& graph) {
        for (const auto& it: graph.vertexes)
            os << *it << std::endl;
        return os;
    }
};

#endif

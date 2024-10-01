#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "Vertex.hpp"
#include <queue>
#include <stack>
#include <random>
#include <algorithm>
#include <vector>
#include <list>

class Graph {
private:
    int order;
    int size;
    bool isDirected;

    std::vector<Vertex*> vertices;
    std::vector<std::list<int>> edges;

    void addEdge(int source, int destination);
    void sortEdges();
    void removeRedundantEdges();
   // void configureEdges(std::vector<std::pair<int, int>> edges);

public:	

    Graph(size_t order, bool isDirected);	
    Graph(const Graph& graph);
    Graph();
    ~Graph();
 
    int getSize();
    int getOrder();
    int getVertexDegree(Vertex* vertex);
    std::vector<Vertex*> getVertices();
    void getAdjacencyList(Vertex* vertex);	

    void breadthFirstSearch();  

    void depthFirstSearch();
    
    void deleteAdjacencyList(Vertex* vertex);
    

    friend std::ostream& operator<< (std::ostream& os, const Graph& graph) {
        for (size_t i = 0; i < graph.edges.size(); ++i) {
		std::cout << graph.vertices[i]->identificator << " ---> ";
		for (const auto& it: graph.edges[i])
			std::cout << it << " ";
		std::cout << std::endl;
	}
        return os;
    }
};

#endif

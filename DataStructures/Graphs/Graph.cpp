#include "Graph.hpp"

void Graph::removeRedundantEdges() {
	auto newVector = std::unique(this->edges.begin(), this->edges.end());
	this->edges.erase(newVector, this->edges.end());
}

Graph::Graph(size_t order, bool isDirected) {
    this->isDirected = isDirected;
    std::random_device randomNumber;
    std::mt19937 seed(randomNumber());
    std::uniform_int_distribution<int> gap(0, order - 1); 

    this->vertices = std::vector<Vertex*>(order);
    this->edges = std::vector<std::list<int>>(order);
    this->size = 0;
    

    for (size_t i = 0; i < order; ++i) 
        this->vertices[i] = new Vertex(i, gap(seed) % 4);
   
    for (size_t i = 1; i < order; ++i) 
    	this->addEdge(i - 1, i); 

    for (size_t i = 0; i < order * 2; ++i) { 
        int source = gap(seed);
        int destination = gap(seed);


        if (source != destination) {
            auto& adjList = edges[source];
            if (std::find(adjList.begin(), adjList.end(), destination) == adjList.end()) {
                this->addEdge(vertices[source]->identificator, vertices[destination]->identificator);
            }
        }
    }

}


Graph::Graph(const Graph& graph) {
    this->vertices = graph.vertices;
    this->edges = graph.edges;
    this->order = graph.order; 
    this->size = graph.size;
    this->isDirected = graph.isDirected;
}

Graph::Graph() {}

// Destructor

Graph::~Graph() {
    for (auto& it: vertices)
        delete it;
}

void Graph::addEdge(int source, int destination) {
    if (this->isDirected == false) {
        this->edges[source].push_back(destination);
        this->edges[destination].push_back(source);
        this->size += 2;  
    } else {
        this->edges[source].push_back(destination);
        this->size += 1;
    }
}


int Graph::getVertexDegree(Vertex* vertex) { return this->edges[vertex->identificator].size(); }

int Graph::getSize() { return this->size; }

int Graph::getOrder() { return this->order; }

std::vector<Vertex*> Graph::getVertices() { return this->vertices; }
	

// public methods

void Graph::breadthFirstSearch() {
    std::vector<bool> visited(this->order, false);
    std::queue<int> fila;
    visited[vertices[0]->identificator] = true;  // Marcar o vértice inicial como visitado
    fila.push(vertices[0]->identificator);
    
    while (!fila.empty()) {
        int temp = fila.front();
        fila.pop();
        std::cout << temp << std::endl;  // Imprimir o vértice visitado

        for (const auto& it : edges[temp]) {
            if (!visited[it]) {
                visited[it] = true;  // Marcar como visitado antes de adicionar à fila
                fila.push(it);
            }
        }
    }
}

void Graph::depthFirstSearch() {
    std::vector<bool> visited(this->order, false);
    std::stack<int> stack;
    stack.push(vertices[0]->identificator); 

    while (!stack.empty()) {
        int temp = stack.top();
        stack.pop();

        if (!visited[temp]) {
            visited[temp] = true;  // Marcar como visitado
            std::cout << temp << std::endl;  // Imprimir o vértice visitado

            for (const auto& neighbor : edges[temp]) {
                if (!visited[neighbor])  
                    stack.push(neighbor);          
            }
        }
    }
}

void Graph::getAdjacencyList(Vertex* vertex) {
	if (!edges[vertex->identificator].empty())
		for (auto it: edges[vertex->identificator])
			std::cout << it << " ";
	else
		std::cout << "There is no adjacencies!" << std::endl;
}


void Graph::deleteAdjacencyList(Vertex* vertex) {
	this->edges[vertex->identificator].clear();
}

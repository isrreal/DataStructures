#include "Graph.hpp"

// Constructors 

Graph::Graph(std::list<Vertex*> vertexes,
    std::vector<std::pair<int, int>> edges, bool isDirected): 
        vertexes(vertexes),
        edges(edges),
        vertexesAmount(vertexes.size()),
        edgesAmount(0),
        isDirected(isDirected) {
            this->configureEdges(edges);
            for (const auto& it: vertexes) 
                edgesAmount += it->adjacencys.size();           
}

Graph::Graph(const Graph& graph) {
    this->vertexes = graph.vertexes;
    this->edges = graph.edges;
    this->vertexesAmount = graph.vertexesAmount; 
    this->edgesAmount = graph.edgesAmount;
    this->isDirected = graph.isDirected;
}

Graph::Graph() {}

// Destructor

Graph::~Graph() {
    for (auto& it: vertexes)
        delete it;
}

void Graph::configureEdges(std::vector<std::pair<int, int>> edges) {
    for (const auto& ponta: edges) {
        int fonte = ponta.first;
        int destino = ponta.second;
        Vertex* v1 = nullptr;
        Vertex* v2 = nullptr;
        for (const auto& it: vertexes) {
            if (it->identificador == fonte) {
                v1 = it;
                break;
            }
        }

        for (const auto& it : vertexes) {
            if (it->identificador == destino) {
                v2 = it;
                break;
            }
        }

        if (this->isDirected) {
            if (v1 && v2) 
                v1->adjacencys.push_back(v2);
        }

        else {
            if (v1 && v2) { 
                v1->adjacencys.push_back(v2);
                v2->adjacencys.push_back(v1);
            }     
        }   

    }
}

// public methods

void Graph::breadthFirstSearch(Vertex* start, Vertex* destiny) {
    std::vector<bool> visited(this->vertexesAmount, false);
    std::queue<Vertex*> fila;
    fila.push(start);
    Vertex* temp = nullptr;
    while (!fila.empty()) {
        temp = fila.front();
        fila.pop();   
        for (const auto& it: temp->adjacencys) {
            if (!visited[it->identificador]) {
                visited[it->identificador] = true;
                fila.push(it);
            }    
        }        
    }
}

void Graph::depthFirstSearch(Vertex* start) {
    std::vector<bool> visited(this->vertexesAmount, false);
    int cycles = 0;
    std::stack<Vertex*> stack;
    visited[start->identificador] = true;
    stack.push(start);
    Vertex* temp = nullptr;
    while (!stack.empty()) {
        temp = stack.top();        
        std::cout << *temp << std::endl;
        stack.pop();    

        if (!visited[temp->identificador])             
            visited[temp->identificador] = true;       
        
        for (const auto& it: temp->adjacencys) {
            if (!visited[it->identificador]) 
                stack.push(it);          
        }
    }
}

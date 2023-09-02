#include "Graph.hpp"

#include <sstream>
#include <fstream>
#include <random>

// // Lê todas as informções dos grafos dados no arquivo "grafo.txt"

// std::vector<Grafo*> lerGrafos() {
//     std::vector<Grafo*> grafos;
//     std::list<Vertice*> vertices;
//     std::vector<std::pair<int, int>> configuracao;
//     std::string linha;
//     int quantidadeDeVertices = 0;
//     int quantidadeDeArestas = 0;
//     int fonte = 0;
//     int destino = 0;
//     std::ifstream arquivo("grafo.txt", std::fstream::in);
//     if (!arquivo) {
//         std::cerr << "Erro ao abrir arquivo" << std::endl;
//         return {};
//     }

//     while (std::getline(arquivo, linha)) {
//         std::stringstream ss(linha);
//         ss >> quantidadeDeVertices >> quantidadeDeArestas;

//         for (size_t i = 0; i < quantidadeDeVertices; ++i)
//             vertices.push_back(new Vertice(i));

//         while (configuracao.size() < quantidadeDeArestas) {
//             std::getline(arquivo, linha);
//             std::stringstream ssArestas(linha);

//             while (configuracao.size() < quantidadeDeArestas && ssArestas >> fonte >> destino)
//                 configuracao.push_back({fonte, destino});
//         }
        
//         grafos.push_back(new Grafo(vertices, configuracao));

//         vertices.clear();
//         configuracao.clear();
//     }
//     return grafos;
// }


int main() {
    std::list<Vertex*> vertexes;
    std::vector<std::pair<int, int>> edgesConfiguration;
    Graph* graph = nullptr;
    std::random_device randomNumber;
    std::mt19937 randomSeed(randomNumber());
    std::uniform_int_distribution<int> gap(0, 100);   
    for (size_t i = 0; i < 100; ++i)
        vertexes.push_back(new Vertex);
    // for (size_t i = 0; i < 100; ++i)
    //     edgesConfiguration.push_back({gap(randomSeed), gap(randomSeed)});  
    edgesConfiguration = {{1, 2}, {1, 3}, {2, 4}, {3, 1}, {3, 5}, {4, 1}, {5, 3}, {5, 1}};
    graph = new Graph(vertexes, edgesConfiguration, true);  
    graph->depthFirstSearch(graph->getVertexes().front());
    // std::cout << *graph;
    delete graph;
}
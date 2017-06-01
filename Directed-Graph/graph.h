#ifndef GRAPH_H
#define GRAPH_H
#include "vertex.h"


class Graph
{
public:
    Graph();
    void AddVertex(int key);
    void AddEdge(char to, char from, int weight);

    Vertex* GetVertex(char label);

    bool IsAdjacent(char from, char to);
    void PrintNeighbors(char vertex);

private:
    int num_vertexes_ = 0;
    std::vector<Vertex *> vertex_list_;
};

#endif // GRAPH_H

#ifndef VERTEX_H
#define VERTEX_H

#include "edge.h"
#include <vector>

class Vertex
{
public:
    Vertex();
    Vertex(int key);

    char GetKey();
    int GetNumEdges();
    Edge* GetEdge(char to);
    Edge* GetEdge(int index);

    void AddEdge(Vertex *to, int key);
    bool HasEdge(char to);
private:
    char key_ = '?';
    int num_edges_ = 0;
    std::vector<Edge *> edges_;
};

#endif // NODE_H

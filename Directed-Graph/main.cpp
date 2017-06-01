#include <iostream>
#include "graph.h"

int main()
{
    Graph my_graph;

    my_graph.AddEdge('A', 'B', 5);
    my_graph.AddEdge('B', 'C', 3);
    my_graph.AddEdge('A', 'C', 7);

    //Should return 1
    std::cout<<my_graph.IsAdjacent('A', 'B')<<std::endl;
    //Should return 1
    std::cout<<my_graph.IsAdjacent('A', 'C')<<std::endl;
    //Should return 0
    std::cout<<my_graph.IsAdjacent('B', 'A')<<std::endl;
    //Should return 0
    std::cout<<my_graph.IsAdjacent('A', 'D')<<std::endl;

    //Should print "Neighbors of A: B, C"
    my_graph.PrintNeighbors('A');
    std::cout<<std::endl;
    //Should print "Neighbors of B: C"
    my_graph.PrintNeighbors('B');
    std::cout<<std::endl;
    //Should print "Neighbors of C:"
    my_graph.PrintNeighbors('C');

}

#include "Graph.h"
#include <iostream>

int main()
{
    my::Graph g(10);
    g.AddEdge(0, 1);
    g.AddEdge(0, 2);
    g.AddEdge(1, 3);
    g.AddEdge(1, 5);
    g.AddEdge(1, 4);
    g.AddEdge(2, 4);
    g.AddEdge(2, 9);
    g.AddEdge(3, 5);
    g.AddEdge(5, 6);
    g.AddEdge(6, 7);
    g.AddEdge(7, 8);
    g.AddEdge(8, 9);
    g.AddEdge(5, 6);
    g.AddEdge(4, 7);
    g.Print();
    for (const auto& e : g.GetShortestPath(0, 9))
        std::cout << e << ' ';
    std::cout << std::endl;
    return 0;
}

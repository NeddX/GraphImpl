#ifndef MY_GRAPH_H
#define MY_GRAPH_H

#include <vector>
#include <cstdint>
#include <unordered_set>
#include <algorithm>

namespace my {
	class Graph
	{
	private:
		std::vector<std::vector<int>> m_Vec;
	
	public:
		Graph() = default;
		Graph(const size_t len);

	public:
		void AddVertex(const int vertex);
		void AddEdge(const int srcVertex, const int destVertex);
        void Print() const;
        void DFS(const int currentVertex, const int destVertex, std::unordered_set<int>& visited,
                    std::vector<int>& path, std::vector<int>& shortest_path) const;
        std::vector<int> GetShortestPath(const int srcVertex, const int destVertex) const;
	};
} // namespace my

#endif // MY_GRAPH_H

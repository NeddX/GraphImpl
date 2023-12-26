#include "Graph.h"

#include <iostream>
#include <algorithm>

namespace my {
	Graph::Graph(const size_t len) : m_Vec(len, std::vector<int>())
	{
	}

	void Graph::AddVertex(const int vertex)
	{
		if (vertex < m_Vec.size())
			return;
		m_Vec.emplace_back(std::vector<int>());
	}

	void Graph::AddEdge(const int srcVertex, const int destVertex)
	{
		if (srcVertex < 0 || srcVertex >= m_Vec.size()
				|| destVertex < 0 || destVertex >= m_Vec.size())
			return;

        auto it = std::find(m_Vec[srcVertex].begin(), m_Vec[srcVertex].end(), destVertex);
        if (it == m_Vec[srcVertex].end())
		    m_Vec[srcVertex].push_back(destVertex);
	}

    void Graph::DFS(const int currentVertex, const int destVertex, std::unordered_set<int>& visited,
                    std::vector<int>& path, std::vector<int>& shortest_path) const
    {
        visited.insert(currentVertex);
        path.push_back(currentVertex);
        if (currentVertex == destVertex)
        {
            if (shortest_path.empty() || shortest_path.size() > path.size())
                shortest_path = path;
        }
        else
        {
            for (const auto& e : m_Vec[currentVertex])
            {
                if (visited.find(e) == visited.end())
                    DFS(e, destVertex, visited, path, shortest_path);
            }
        }
        path.pop_back();
        visited.clear();
    }

    std::vector<int> Graph::GetShortestPath(const int srcVertex, const int destVertex) const
    {
        std::unordered_set<int> visited;
        std::vector<int> path;
        std::vector<int> shortest_path;
        DFS(srcVertex, destVertex, visited, path, shortest_path);
        return shortest_path;
    }

    void Graph::Print() const
    {
        for (auto i = 0; i < m_Vec.size(); ++i)
        {
            std::cout << "[" << i << "]: { ";
            for (auto j = 0; j < m_Vec[i].size(); ++i)
                std::cout << m_Vec[i][j] << ", ";
            std::cout << " }" << std::endl;
        }
    }
} // namespace my

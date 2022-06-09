/*
* @file kruskal.h
*
* Author: Ilya Khlyustov
* Create: 6/9/2022
* Notes:
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#ifndef DEVTOOLS_COURSE_PRACTICE_KRUSKAL_H
#define DEVTOOLS_COURSE_PRACTICE_KRUSKAL_H

#include <vector>
#include <numeric>
#include <stdexcept>

struct Edge {
    Edge(size_t src_, size_t dst_, int weight_);

    bool operator <(const Edge& rhs) const;

    size_t src, dst;
    int weight;
};

class Graph {
public:

    explicit Graph(size_t nodesCount);

    Graph(size_t nodesCount, std::vector<Edge> edges);

    std::vector<Edge> getMST();

    size_t getNodesCount();

    size_t getEdgesCount();

    void addEdge(const Edge& newEdge);

private:
    size_t _nodesCount;
    std::vector<size_t> _parent, _rank;
    std::vector<Edge> _edges;

    bool unite(size_t a, size_t b);

    size_t getRepresentativeParent(size_t src);
};

#endif //DEVTOOLS_COURSE_PRACTICE_KRUSKAL_H

/*
* @file kruskal.cpp
*
* Author: Ilya Khlyustov
* Create: 6/9/2022
* Notes:
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#include <vector>
#include <stdexcept>
#include <algorithm>

#include "include/kruskal.h"

bool Edge::operator <(const Edge& rhs) const {
    return weight < rhs.weight;
}

Edge::Edge(size_t src_, size_t dst_, int weight_): src(src_), dst(dst_), weight(weight_) {}

Graph::Graph(size_t nodesCount): _parent(nodesCount), _rank(nodesCount, 0) {
    iota(_parent.begin(), _parent.end(), 0);
}

Graph::Graph(size_t nodesCount, std::vector<Edge> edges): Graph(nodesCount) {
    for (const auto& edge : edges) {
        if (edge.src >= nodesCount || edge.dst >= nodesCount) {
            throw std::runtime_error("Edge endpoint out of range");
        }
    }
    _edges = edges;
}

bool Graph::unite(size_t a, size_t b) {
    a = getRepresentativeParent(a);
    b = getRepresentativeParent(b);
    if (a == b) {
        return false;
    }

    if (_rank[a] < _rank[b])
        std::swap(a, b);

    _parent[b] = a;
    _rank[a] += _rank[a] == _rank[b];

    return true;
}

size_t Graph::getRepresentativeParent(size_t src) {
    if (_parent.at(src) == src)
        return src;
    return _parent.at(src) = getRepresentativeParent(_parent.at(src));
}

std::vector<Edge> Graph::getMST() {
    std::sort(_edges.begin(), _edges.end());
    std::vector<Edge> mst;

    for (const auto& edge : _edges) {
        if (unite(edge.dst, edge.src)) {
            mst.push_back(edge);
        }
    }

    if (mst.size() + 1 != _nodesCount)
        throw std::runtime_error("Not enough edges for build MST");

    return mst;
}

size_t Graph::getNodesCount() {
    return _nodesCount;
}

size_t Graph::getEdgesCount() {
    return _edges.size();
}

void Graph::addEdge(const Edge &newEdge) {
    if (newEdge.dst >= _nodesCount || newEdge.src >= _nodesCount) {
        throw std::runtime_error("Edge endpoint out of range");
    }

    _edges.push_back(newEdge);
}
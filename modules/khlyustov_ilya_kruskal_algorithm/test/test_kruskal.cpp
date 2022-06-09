// Copyright 2022 Khlyustov Ilya


#include <gtest/gtest.h>
#include <vector>

#include "include/kruskal.h"

TEST(Kruskal, OutOfRangeVertexException) {
    size_t nodes = 3;
    Edge edge(0, 100, 123);
    EXPECT_ANY_THROW(Graph(nodes, {edge}));
}

TEST(Kruskal, TreeCase) {
    size_t nodes = 3;
    std::vector<Edge> edges = {
            Edge(1, 2, 123),
            Edge(0, 1, 456),
    };
    Graph testGraph(nodes, edges);
    EXPECT_EQ(edges, testGraph.getMST());
}

TEST(Kruskal_Algorithm, ClassicalCase1) {
    size_t nodes = 5;
    std::vector<Edge> edges = {
            Edge(1, 2, 1),
            Edge(0, 1, 2),
            Edge(2, 3, 3),
            Edge(2, 4, 4),
            Edge(4, 3, 5),
            Edge(1, 4, 6),
    };

    std::vector<Edge> expectedResult = {
            Edge(1, 2, 1),
            Edge(0, 1, 2),
            Edge(2, 3, 3),
            Edge(2, 4, 4),
    };

    Graph testGraph(nodes, edges);

    EXPECT_EQ(expectedResult, testGraph.getMST());
}

TEST(Kruskal_Algorithm, ClassicalCase2) {
    size_t nodes = 5;
    std::vector<Edge> edges = {
            Edge(1, 2, 1),
            Edge(0, 1, 2),
            Edge(0, 2, 3),
            Edge(2, 4, 4),
            Edge(4, 3, 5),
            Edge(1, 4, 6),
    };

    std::vector<Edge> expectedResult = {
            Edge(1, 2, 1),
            Edge(0, 1, 2),
            Edge(2, 4, 4),
            Edge(4, 3, 5),
    };

    Graph testGraph(nodes, edges);

    EXPECT_EQ(expectedResult, testGraph.getMST());
}

TEST(Kruskal_Algorithm, NotEnoughEdgesException) {
    size_t nodes = 4;
    std::vector<Edge> edges = {
            Edge(1, 2, 1),
            Edge(0, 1, 2),
            Edge(0, 2, 3),
    };

    Graph testGraph(nodes, edges);

    EXPECT_ANY_THROW(testGraph.getMST());
}

TEST(Kruskal_Algorithm, CountOfEdgesFunctionality) {
    size_t nodes = 5;
    std::vector<Edge> edges = {
            Edge(1, 2, 1),
            Edge(0, 1, 2),
            Edge(0, 2, 3),
            Edge(2, 4, 4),
            Edge(4, 3, 5),
            Edge(1, 4, 6),
    };

    Graph testGraph(nodes, edges);

    EXPECT_EQ(6, testGraph.getMST());
}

TEST(Kruskal_Algorithm, CountOfNodesFunctionality) {
    size_t nodes = 5;
    std::vector<Edge> edges = {
            Edge(1, 2, 1),
            Edge(0, 1, 2),
            Edge(0, 2, 3),
            Edge(2, 4, 4),
            Edge(4, 3, 5),
            Edge(1, 4, 6),
    };

    Graph testGraph(nodes, edges);

    EXPECT_EQ(5, testGraph.getMST());
}

TEST(Kruskal_Algorithm, AddEdgeFunctionality) {
    size_t nodes = 5;

    Graph testGraph(nodes);

    for (auto edge : {
        Edge(1, 2, 1),
        Edge(0, 1, 2),
        Edge(0, 2, 3),
        Edge(2, 4, 4),
        Edge(4, 3, 5),
        Edge(1, 4, 6)}) {
        testGraph.addEdge(edge);
    }

    EXPECT_EQ(6, testGraph.getMST());
}

TEST(Kruskal, OutOfRangeVertexExceptionViaAdding) {
    size_t nodes = 3;
    Graph testGraph(nodes);
    Edge edge(0, 100, 123);
    EXPECT_ANY_THROW(testGraph.addEdge(edge));
}

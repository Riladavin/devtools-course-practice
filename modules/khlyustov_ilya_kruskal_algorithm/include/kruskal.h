/*
* @file Kruskal.h
*
* Copyright (C) Huawei Technologies Co., Ltd. 2022. All rights reserved.
* Description: inference process
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

struct Edge {
private:
    size_t src;
    size_t dst;
    int weight;

    Edge();
    Edge(const size_t src_, const size_t dst_, const int weight_);

    friend Graph;
};

class Graph {
public:

    Graph(size_t nodesCount) {
        
    }

    Graph(size_t nodesCount, vector<) {
    }



private:
    vector<size_t> parent;

    void unite(size_t src, size_t dst);

    void getParent(size_t src);
};

#endif //DEVTOOLS_COURSE_PRACTICE_KRUSKAL_H

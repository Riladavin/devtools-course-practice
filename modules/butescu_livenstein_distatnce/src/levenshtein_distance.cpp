// Copyright 2022 Butescu Vladimir

#include <array>
#include <string>
#include <vector>
#include <utility>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sstream>
#include <algorithm>
#include <random>
#include <iostream>

#include "include/levenshtein_distance.h"

uint32_t Levenshtein::LevenshteinDistance(
    const std::string& source,
    const std::string& target) {
    std::vector<std::vector<uint32_t>> lev_dist(source.length() + 1,
        std::vector<uint32_t>(target.length() + 1));

    iota(lev_dist[i].begin(), lev_dist[i].end(), 0);

    for (size_t i = 0; i < source.length(); ++i) {
        lev_dist[i + 1][0] = lev_dist[i][0] + 1;

        for (std::size_t j = 0; j < target.length(); ++j) {
            lev_dist[i + 1][j + 1] = std::min(std::min(
                lev_dist[i + 1][j] + 1,
                lev_dist[i][j + 1] + 1,
                lev_dist[i][j] + !equals(source[i], target[j]));
        }
    }

    return lev_dist[source.length()][target.length()];
}

// Copyright 2022 Butescu Vladimir
#ifndef MODULES_BUTESCU_LIVENSTEIN_DISTATNCE_INCLUDE_LEVENSHTEIN_DISTANCE_H_
#define MODULES_BUTESCU_LIVENSTEIN_DISTATNCE_INCLUDE_LEVENSHTEIN_DISTANCE_H_

#include <array>
#include <string>
#include <vector>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <random>
#include <iostream>

class Levenshtein {
 public:
    static uint32_t LevenshteinDistance(
        std::string const& source,
        std::string const& target);
};

#endif  // MODULES_BUTESCU_LIVENSTEIN_DISTATNCE_INCLUDE_LEVENSHTEIN_DISTANCE_H_

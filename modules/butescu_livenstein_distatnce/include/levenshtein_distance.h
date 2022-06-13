// Copyright 2022 Butescu Vladimir
#ifndef MODULES_BUTESCU_LIVENSTEIN_DISTATNCE_INCLUDE_LEVENSHTEIN_DISTANCE_H_
#define MODULES_BUTESCU_LIVENSTEIN_DISTATNCE_INCLUDE_LEVENSHTEIN_DISTANCE_H_

#include <algorithm>
#include <vector>
#include <string>
#include <random>

class Levenshtein {
 public:
    static uint32_t LevenshteinDistance(
        std::string const& source,
        std::string const& target);
};

#endif  // MODULES_BUTESCU_LIVENSTEIN_DISTATNCE_INCLUDE_LEVENSHTEIN_DISTANCE_H_

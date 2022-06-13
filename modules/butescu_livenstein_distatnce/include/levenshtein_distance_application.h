// Copyright 2022 Khlyustov Ilya

#ifndef MODULES_BUTESCU_LIVENSTEIN_DISTATNCE_INCLUDE_LEVENSHTEIN_DISTANCE_APPLICATION_H_
#define MODULES_BUTESCU_LIVENSTEIN_DISTATNCE_INCLUDE_LEVENSHTEIN_DISTANCE_APPLICATION_H_

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

class LevenshteinDistanceApp {
 public:
  LevenshteinDistanceApp();
  std::string operator()(int argc, const char** argv);
};

#endif  // MODULES_BUTESCU_LIVENSTEIN_DISTATNCE_INCLUDE_LEVENSHTEIN_DISTANCE_APPLICATION_H_

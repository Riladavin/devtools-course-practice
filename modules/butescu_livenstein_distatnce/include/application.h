// Copyright 2022 Khlyustov Ilya

#ifndef MODULES_KHLYUSTOV_ILYA_LEVENSHTEIN_DISTANCE_INCLUDE_APPLICATION_H_
#define MODULES_KHLYUSTOV_ILYA_LEVENSHTEIN_DISTANCE_INCLUDE_APPLICATION_H_

#include <array>
#include <string>
#include <vector>
#include <utility>

class LevenshteinDistanceApp {
 public:
  LevenshteinDistanceApp();
  std::string operator()(int argc, const char** argv);
};

#endif  // MODULES_KHLYUSTOV_ILYA_LEVENSHTEIN_DISTANCE_INCLUDE_APPLICATION_H_

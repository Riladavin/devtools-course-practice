// Copyright 2022 Khlyustov Ilya

#include <array>
#include <string>
#include <vector>
#include <utility>
#include <sstream>
#include <algorithm>
#include <random>
#include <iostream>

#include "include/levenshtein_distance_application.h"
#include "include/levenshtein_distance.h"

LevenshteinDistanceApp::LevenshteinDistanceApp() {}

std::string help() {
  std::string result = "This is an application to count levenshtein";
  result += " distance of two strings.\n";
  result += "You need to input two strings\n";
  return result;
}

std::string error() {
  return "invalid arguments!";
}

std::string LevenshteinDistanceApp::operator()(int argc, const char** argv) {
  if (argc == 2) {
    return (std::string(argv[1]) == "-h" || std::string(argv[1]) == "--help")
    ?
    help()
    :
    error();
  } else if (argc != 3) {
    return error();
  }

  return std::to_string(Levenshtein::LevenshteinDistance(
    std::string(argv[1]),
    std::string(argv[2])));
}



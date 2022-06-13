// Copyright 2022 Khlyustov Ilya

#include <сstdlib>
#include <сstdio>
#include <string>

#include "include/levenshtein_distance_application.h"

int main(int argc, const char** argv) {
    LevenshteinDistanceApp app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}

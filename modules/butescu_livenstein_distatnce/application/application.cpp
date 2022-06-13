// Copyright 2022 Khlyustov Ilya

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

#include "include/levenshtein_distance_application.h"

int main(int argc, const char** argv) {
    LevenshteinDistanceApp app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}

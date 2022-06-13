// Copyright 2022 Butescu Vladimir

#include <gtest/gtest.h>
#include <array>
#include <string>
#include <vector>
#include <utility>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>
#include <algorithm>
#include <random>
#include <iostream>

#include "include/levenshtein_distance.h"

TEST(Butescu_levenshtein_distance, test_zero_value) {
     std::string src = "";
     std::string dst = "";
     uint32_t distance =
     Levenshtein::LevenshteinDistance(src, dst);

     ASSERT_EQ(distance, 0u);
}

TEST(Butescu_levenshtein_distance, test_one_value) {
    std::string src = "1";
    std::string dst = "1";
    uint32_t distance =
        Levenshtein::LevenshteinDistance(src, dst);

    ASSERT_EQ(distance, 0u);
}

TEST(Butescu_levenshtein_distance, test_number) {
     std::string src = "125";
     std::string dst = "521";
     uint32_t distance =
     Levenshtein::LevenshteinDistance(src, dst);

     ASSERT_EQ(distance, 2u);
}

TEST(Butescu_levenshtein_distance, test_big_number) {
    std::string
        src = "3245254252413124";
    std::string
        dst = "124456767453";
    uint32_t distance =
        Levenshtein::LevenshteinDistance(src, dst);

    ASSERT_EQ(distance, 11u);
}

TEST(Butescu_levenshtein_distance, test_word) {
     std::string src = "string";
     std::string dst = "dog";
     uint32_t distance =
     Levenshtein::LevenshteinDistance(src, dst);

     ASSERT_EQ(distance, 5u);
}

TEST(Butescu_levenshtein_distance, test_big_word) {
    std::string
    src = "Floccinaucinihilipilification";
    std::string
    dst = "Antidisestablishmentarianism";
    uint32_t distance =
    Levenshtein::LevenshteinDistance(src, dst);

    ASSERT_EQ(distance, 25u);
}

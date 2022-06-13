// Copyright 2022 Khlyustov Ilya

#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "include/application.h"

using ::testing::internal::RE;


class LevenshteinDistanceAppTest : public ::testing::Test {
 protected:
  void Act(std::vector<std::string> args_) {
    std::vector<const char*> options;

    options.push_back("levenshtein");
    for (std::size_t i = 0; i < args_.size(); ++i) {
      options.push_back(args_[i].c_str());
    }

    const char** argv = &options.front();
    int argc = static_cast<int>(args_.size()) + 1;

    output_ = app_(argc, argv);
  }

  void Assert(std::string expected) {
    EXPECT_EQ(expected, output_);
  }

 private:
  LevenshteinDistanceApp app_;
  std::string output_;
};



TEST_F(LevenshteinDistanceAppTest, InvalidArguments) {
  std::vector<std::string> args = {};

  Act(args);

  Assert("invalid arguments!");
}

TEST_F(LevenshteinDistanceAppTest, Help) {
  std::vector<std::string> args = { "-h" };

  Act(args);

  Assert(
    "This is an application to count levenshtein distance of two strings.\n" +
    "You need to input two strings\n");
}

TEST_F(LevenshteinDistanceAppTest, ClassicalCase1) {
  std::vector<std::string> args = { "qwerty", "qwe" };

  Act(args);

  Assert("3");
}

TEST_F(LevenshteinDistanceAppTest, ClassicalCase2) {
  std::vector<std::string> args = { "qwerty", "qweryy" };

  Act(args);

  Assert("1");
}

TEST_F(LevenshteinDistanceAppTest, OneWordEmpty) {
  std::vector<std::string> args = { "qwe", "" };

  Act(args);

  Assert("3");
}

// Copyright 2022 a.m.moisenovich@mail.ru

#include <gtest/gtest.h>
#include <unordered_map.hpp>

#include <algorithm>
#include <vector>
TEST(unordered_map, Construct) {
  // initializer list constructor
  unordered_map<std::string, int> ans1;
  ans1 = {"hello", 2};
  unordered_map<std::string> first({"world", "hello"});
  EXPECT_EQ(first, ans1);
  // empty constructor
  unordered_map<int> ans2, second;
  EXPECT_EQ(second, ans2);
  // copy constructor
  unordered_map<int> ans3({1, 2, 33, 44, 55, -6}), third(ans3);
  EXPECT_EQ(third, ans3);
}
TEST(unordered_map, Assign) {
  // assign
  unordered_map<int> ans, first({-1, 44, -3, 9}), l(first);
  ans = l;
  EXPECT_EQ(first, ans);
}
TEST(unordered_map, Size) {
  // size
  unordered_map<char> first;
  EXPECT_EQ(first.size(), 0);
  first.insert({1, 2, 3, 0, -9});
  EXPECT_EQ(first.size(), 5);
}
TEST(unordered_map, Empty) {
  // empty
  unordered_map<char> first;
  EXPECT_TRUE(first.empty());
  first.insert(69);
  EXPECT_FALSE(first.empty());
}
TEST(unordered_map, Has) {
  // has
  unordered_map<int> first = {1, 2, 3};
  EXPECT_FALSE(first.has(99));
  first.insert(99);
  EXPECT_TRUE(first.has(99));
}
TEST(unordered_map, Insert) {
  unordered_map<int> ans = {-1, 3, 5, 7, 8, -2}, ans2 = {-1, 3, 5, 9, 7, 8, -2},
                     ans3 = {-1, 3, 5, 7, 8, -2, 9, 111, 222, 333}, first;
  unordered_map<std::string> ans4 = {"hello", "world", "[24 hour cinderella]"},
                             second;
  std::vector<std::string> v1 = {"hello", "world", "[24 hour cinderella]"};
  // insert with iterators range
  first.insert(ans.begin(), ans.end());
  EXPECT_EQ(first, ans);
  // insert an existing value -> no changes
  first.insert(5);
  EXPECT_EQ(first, ans);
  // insert new value
  first.insert(9);
  EXPECT_EQ(first, ans2);
  // insert with initializer list
  first.insert({111, 222, 333});
  EXPECT_EQ(first, ans3);
  // insert with iterators range, different iterator type
  second.insert(v1.begin(), v1.end());
  EXPECT_EQ(second, ans4);
}
TEST(unordered_map, Erase) {
  unordered_map<int> first = {-1, 3, 5, 7, 8, -2};
  // erase by value
  EXPECT_TRUE(first.has(-2));
  first.erase(-2);
  EXPECT_FALSE(first.has(-2));
  // erase by iterator
  EXPECT_TRUE(first.has(8));
  first.erase(first.find(8));
  EXPECT_FALSE(first.has(8));
}
TEST(unordered_map, Clear) {
  // clear
  unordered_map<int> first = {-1, 3, 5, 7, 8, -2};
  EXPECT_FALSE(first.empty());
  first.clear();
  EXPECT_TRUE(first.empty());
}
TEST(unordered_map, Swap) {
  // swap
  unordered_map<int> first = {-1, 3, 5, 7, 8, -2}, second(first), ans(first);
  second.insert({99, 101});
  swap(first, second);
  EXPECT_EQ(second, ans);
}
TEST(unordered_map, Find) {
  // find
  unordered_map<int> first = {1, 2, 3};
  EXPECT_EQ(first.find(101), first.end());
  EXPECT_EQ(*first.find(2), 2);
  first.insert(101);
  EXPECT_EQ(*first.find(101), 101);
}

TEST(unordered_map, STL) {
  unordered_map<int> first = {1, 11, 3, 5, 4, 7, 9};
  EXPECT_EQ(*std::find_if(first.begin(), first.end(),
                          [](int val) { return val % 2 == 0; }),
            4);
}
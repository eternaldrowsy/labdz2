//
// Created by eternaldrowsy on 14.06.2022.
//

#ifndef TEMPLATE_HASH_HPP
#define TEMPLATE_HASH_HPP
#include <iostream>
#include <vector>
#include <unordered_map.hpp>
#include <algorithm>
#define p 32321
class HashTable
{
 public:
  HashTable()
  {}
  HashTable(int _key, int _value)
  {
    incert(_key, _value);
  }
  void incert(int key, int value)
  {
    std::pair<int, int> new_pair(key, value);
    new_list.emplace_front(new_pair);
    auto it = table.begin() + hash_funk(key);
    table.insert(it, new_list);
    //std::forward_list<std::pair<int, int>> new_list;
    //new_list.emplace_front(new_pair);
    //auto it = table.begin() + hash_funk(key);
    //table.insert(it, new_list);
  }
  void print(int key)
  {
    auto it = table[hash_funk(key)].begin();
    for (it; it != table[hash_funk(key)].end(); ++it)
    {
      std::pair<int, int> newPair = *it;

      std::cout << it->second << std::endl;
    }

  }
  int search(int key)
  {
    auto it = table[hash_funk(key)].begin();
    std::pair<int, int> newPair = *it;
    return it->second;

  }
  void erase(int key)
  {
    auto pos = table.begin() + hash_funk(key); // указатель на лист
    auto it = table[hash_funk(key)].begin(); // указатель на пару
    std::pair<int, int> newPair = *it;
    while (it->first != key)
    {
      it++;
    }
    new_list.remove(*it);


  }
 private:

  int key = 0;
  int value = 0;
  std::forward_list<std::pair<int,int>> new_list {4};
  std::vector<std::forward_list<std::pair<int, int>>> table {4};
  int hash_funk(int key)
  {
    return key % p;
  }
};

#endif  // TEMPLATE_HASH_HPP

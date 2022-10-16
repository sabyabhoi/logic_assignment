#pragma once
#include <cstdio>

#define NULL_INT -1

struct HashTable {
private:
  unsigned int size;
  int* table;

  unsigned int hash(char);

public:
  HashTable(unsigned int s);
  ~HashTable();
  
  bool insert(char);
  int at(char);

  void print_table();
};

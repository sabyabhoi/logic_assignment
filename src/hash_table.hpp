#pragma once
#include <cstdio>

#define NULL_INT -1

namespace hash_table {

/*!
 * @brief Hash table data structure implementation
 *
 * This is a simple implementation of a hash table, which will
 * take a character as a key, and an integer as a value, and map the
 * character to the integer using a hash function.
 */
struct HashTable {
private:
  /// @brief size of the hash table
  unsigned int size;
  /// @brief the actual table where the data will be stored
  int* table;

  unsigned int hash(char);

public:
  HashTable(unsigned int s);
  ~HashTable();
  
  bool insert(char, int);
  int at(char);

  void print_table();
};
}

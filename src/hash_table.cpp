#include "hash_table.hpp"

HashTable::HashTable(unsigned int s) : size(s) {
  table = new int[size]; 
  for (unsigned int i = 0; i < size; ++i) {
    table[i] = NULL_INT;
  }
}
HashTable::~HashTable() { delete table; }

unsigned int HashTable::hash(char c) {
  unsigned int val = 5381;
  val = ((val << 5) + val) + c;
  return val % size;
}

bool HashTable::insert(char c) {
  if(c == '\0') return false;

  unsigned int i = hash(c);

  if(table[i] != NULL_INT) return false;
  table[i] = c;

  return true;
}

int HashTable::at(char c) {
  if(c == '\0') return NULL_INT;
  return table[hash(c)];
}

void HashTable::print_table() {
  for (unsigned int i = 0; i < size; ++i) {
	if(table[i] == NULL_INT)
	  printf("%d\t__\n", i);
	else 
	  printf("%d\t%c\n", i, table[i]);
  }
}

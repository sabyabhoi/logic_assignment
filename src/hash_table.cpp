#include "hash_table.hpp"

namespace hash_table {
/*!
 * @brief initialize the internal table by allocating memory for it on the
 * heap.
 * @param s size of the hash table
 */
HashTable::HashTable(unsigned int s) : size(s) {
  table = new int[size]; 
  for (unsigned int i = 0; i < size; ++i) {
    table[i] = NULL_INT;
  }
}
/// @brief we deallocate the internal table.
HashTable::~HashTable() { delete table; }

/*!
 * @brief Here we employ the djb2 hash function.
 * @param c the character we're going to hash
 * @return index in the hash table for the corresponding character
*/
unsigned int HashTable::hash(char c) {
  unsigned int val = 5381;
  val = ((val << 5) + val) + c;
  return val % size;
}

/*!
 * @brief try to insert a key-value pair into the table
 * @param c the key we're trying to insert
 * @param val the value we're trying to insert
 * @return true if the insertion was successful
 */
bool HashTable::insert(char c, int val) {
  if (c == '\0')
	return false;

  unsigned int i = hash(c);
  printf("hash = %d\n", i);

  if(table[i] != NULL_INT) return false;
  table[i] = val;

  return true;
}

/*!
 * @brief return the value of a given key.
 * @param c the key for which we wish to retrieve the value
 * @return the value in the hash table corresponding to the given key
 */
int HashTable::at(char c) {
  if(c == '\0') return NULL_INT;
  return table[hash(c)];
}

void HashTable::print_table() {
  for (unsigned int i = 0; i < size; ++i) {
	if(table[i] == NULL_INT)
	  printf("%d\t__\n", i);
	else 
	  printf("%d\t%d\n", i, table[i]);
  }
}
}

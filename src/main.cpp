#include "parse_tree.hpp"
#include <cstring>

using namespace parse_tree;
int main() {
  Node *head = prefixToTree("+AB", 0, 2).first;
  int vals[26];
  deleteTree(head);
  return 0;
}

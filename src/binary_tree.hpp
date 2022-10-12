#pragma once

namespace binary_tree {
struct Node {
  char data;
  Node *left;
  Node *right;

  Node(char);
};

void deleteTree(Node *);
} // namespace binary_tree

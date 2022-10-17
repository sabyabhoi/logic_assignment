#pragma once

namespace binary_tree {
/// Binary tree node structure

struct Node {
  /// actual data contained in the node
  char data;
  /// pointer to left subtree
  Node *left; 
  /// pointer to right subtree
  Node *right; 

  Node(char);
};

void deleteTree(Node *);
} // namespace binary_tree
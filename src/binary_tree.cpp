#include "binary_tree.hpp"

namespace binary_tree {
Node::Node(char x) : data(x), left(nullptr), right(nullptr) {}

void deleteTree(Node *head) {
  if (head == nullptr)
    return;

  deleteTree(head->left);
  deleteTree(head->right);
  delete head;
}
} // namespace binary_tree

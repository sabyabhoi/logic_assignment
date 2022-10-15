#include "binary_tree.hpp" 

namespace binary_tree {
/// Constructor for the struct Node
Node::Node(char x) : data(x), left(nullptr), right(nullptr) {} 
/// @brief function deleteTree for recursively deleteing nodes from bottom to top

/// @param head For a given subtree head is the parent node for that particular subtree

void deleteTree(Node *head) {
  /// checks whether the head is a null node
  if (head == nullptr) 
    /// if it is , then it moves out of the if loop
    return;

  /// if the head is not a null pointer the deleteTree functions recursively goes on deleting the nodes
  ///

  /// moves to the bottom to left child and deletes the node
  deleteTree(head->left); 
  
  /// after left child, moves to the right child and deletes it
  deleteTree(head->right); 
  /// finally deletes the parent "head" node
  delete head; 
}
} // namespace binary_tree
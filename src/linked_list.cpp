#include "linked_list.hpp"

namespace list
{
  /// @brief A constuctor for the struct Node which is used to initialize the Node
  /// @param x It is the character data input that will be stored in the Node
  Node::Node(char x) : data(x), next(nullptr), prev(nullptr) {}

} // namespace list

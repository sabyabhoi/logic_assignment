#pragma once
/// @brief List is a data structure made up of nodes which is used to store data
namespace list
{
  /// @brief  Node is an element of list which contains data and the next and prev pointers
  struct Node
  {

    /// @brief Data is the information stored in the current node
    char data;

    /// @brief This is the pointer to the Next Node of the list.
    Node *next;
    /// @brief This is the pointer to the Previous Node of the list.
    Node *prev;
    /// @brief  A constuctor for the struct Node which is used to initialize the Node
    /// @param x It is the character data input that will be stored in the Node
    Node(char);
  };
} // namespace list

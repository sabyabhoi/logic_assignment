#pragma once

#include "linked_list.hpp"
/// @brief namespace stack is defined to declare the scope of the methods and variables contained in it.
namespace stack {
/// @brief It is the structure used to implement stack functionality.
struct Stack {

  Stack();
  ~Stack();

  list::Node* topVar;
  unsigned int size;

  void push(char);
  /// @brief this method is used to remove the topmost element of the stack stored in topVar.
  void pop();
  /// @brief this method is used to check if the stack is empty or not.
  /// @return true if the integer value stored in the variable size is >0. false in all other cases.
  bool empty();
  /// @brief this method is used to check the value stored in topVar.
  /// @return the value stored in topVar.
  char top();
};
} // namespace stack

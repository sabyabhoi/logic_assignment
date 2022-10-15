#pragma once

#include "linked_list.hpp"
/// @brief namespace stack is defined to declare the scope of the methods and variables contained in it.
namespace stack {
/// @brief It is the structure used to implement stack functionality.
struct Stack {
  /// @brief it is a node of type doubly linked list which stores the topmost element of the stack.
  list::Node* topVar; 
  /// @brief stores an integer value which equal to the size of the stack.
  int size;
  /// @brief this method is defined to push a character onto the top of the stack. sets the value of topVar.
  /// @param c this parameter takes a character value. This value is pushed on the top of the stack using push.
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

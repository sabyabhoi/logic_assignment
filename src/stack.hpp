#pragma once

#include "linked_list.hpp"
/// @brief namespace stack is defined to declare the scope of the methods and variables contained in it.
namespace stack {
/// @brief It is the structure used to implement stack functionality.
struct Stack {
  /// @brief constructor for the struct stack which is used to to initialize the stack. 
  Stack();

  /// @brief destructor of the struct stack which is used to deallocate the memory used by stack and also by the doubly linked list used within it.
  ~Stack();

  /// @brief used to store the address of the topmost element which is of the type doubly linked list.
  list::Node* topVar;
  /// @brief it stores an integer value which is equal to the size of the stack.
  unsigned int size;
  /// @brief this method is used to push the value in the topmost position of the stack by changing the value of topVar to the value passed.
  /// @param c it is of the type character. it is the value which will be stored in topVar using push method.
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

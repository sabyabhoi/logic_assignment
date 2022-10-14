#pragma once

#include "linked_list.hpp"

namespace stack {
struct Stack {

  Stack();
  ~Stack();

  list::Node* topVar;
  unsigned int size;

  void push(char);
  void pop();
  bool empty();
  char top();
};
} // namespace stack

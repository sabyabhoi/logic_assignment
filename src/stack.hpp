#pragma once

#include "linked_list.hpp"

namespace stack {
struct Stack {
  list::Node* topVar;
  int size;

  void push(char);
  void pop();
  bool empty();
  char top();
};
} // namespace stack

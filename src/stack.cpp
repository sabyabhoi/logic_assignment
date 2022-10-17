#include "stack.hpp"
#include "linked_list.hpp"
#include <iostream>

namespace stack {

Stack::Stack() : topVar(nullptr), size(0) {}

Stack::~Stack() {
  list::Node *prev;
  while (size-- > 0) {
    prev = topVar->prev;
    delete topVar;
    topVar = prev;
  }
}

void Stack::push(char c) {
  if (topVar == nullptr) {
    topVar = new list::Node(c);
    size = 1;
  } else {
    topVar->next = new list::Node(c);
    topVar->next->prev = topVar;
    topVar = topVar->next;
    ++size;
  }
}

void Stack::pop() {
  if (topVar == nullptr)
    return;
  auto prev = topVar->prev;
  delete topVar;
  topVar = prev;
  --size;
}

bool Stack::empty() { return size == 0; }

char Stack::top() {
  if (topVar == nullptr)
    return '\0';
  return topVar->data;
}
} // namespace stack

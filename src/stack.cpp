#include "stack.hpp"

namespace stack {
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
  topVar = topVar->prev;
  delete topVar->next;
  --size;
}

bool Stack::empty() { return size > 0; }

char Stack::top() {
  if (topVar == nullptr)
	return '\0';
  return topVar->data;
}
} // namespace stack

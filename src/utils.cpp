#include "utils.hpp"

namespace binary_tree {
Node::Node(char x) : data(x), left(nullptr), right(nullptr) {}

void deleteTree(Node *head) {
  if (head == nullptr)
    return;

  deleteTree(head->left);
  deleteTree(head->right);
  delete head;
}
} // namespace binary_tree

namespace list {
Node::Node(char x) : data(x) {}
} // namespace list

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
	return '$';
  return topVar->data;
}
} // namespace stack

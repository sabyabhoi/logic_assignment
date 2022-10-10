#pragma once

namespace binary_tree {
struct Node {
  char data;
  Node *left;
  Node *right;

  Node(char);
};

void deleteTree(Node *);
} // namespace binary_tree

namespace list {
struct Node {
  char data;
  Node *next, *prev;

  Node(char);
};
} // namespace list

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

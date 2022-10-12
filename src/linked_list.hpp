#pragma once

namespace list {
struct Node {
  char data;
  Node *next, *prev;

  Node(char);
};
} // namespace list

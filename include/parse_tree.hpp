#pragma once

#include <iostream>
#include <string>
#include "utils.hpp"
#include "stack.hpp"

using namespace std;

namespace parse_tree {
/// Parse tree node structure

struct Node {
  /// actual data contained in the node
  char data;
  /// pointer to left subtree
  Node *left; 
  /// pointer to right subtree
  Node *right; 

  Node(char);
};

string infixToPrefix(string s);
pair<Node *, int> prefixToTree(const string &, int, int);
void printInorder(Node *);
int height(Node *);
bool evaluate(Node *, const int *);
void deleteTree(Node *);
} // namespace parse_tree

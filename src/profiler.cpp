#include "parse_tree.hpp"

using namespace parse_tree;

int main() {
  
  // Task 1: Infix to prefix
  string infix;
  getline(cin, infix);

  string prefix = infixToPrefix(infix);

  // Task 2: Prefix to Parse Tree
  Node* head = prefixToTree(prefix, 0, prefix.size() - 1).first;

  // Task 3: Inorder traversal 
  printInorder(head);
  cout << "\n";

  // Task 4: Height of parse tree
  int _ = height(head);

  // Task 5: Evaluating the expression
  bool* atomsPresent = new bool[26];
  for(int i = 0; i < 26; ++i) atomsPresent[i] = 0;
  int* atoms = new int[26];
  getAtoms(head, atomsPresent);
  for (int i = 0; i < 26; ++i) {
    if(atomsPresent[i]) {
	  cin >> atoms[i];
	}
  }
  cout << evaluate(head, atoms) << "\n";

  // Clean up code
  // Delete the parse tree (since it was allocated on the heap) 
  deleteTree(head);
  // Free the list of atoms
  delete[] atomsPresent;
  delete[] atoms;
  return 0;
}

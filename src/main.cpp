/*! \mainpage proParser Documentation
 * \section time_complexity Time and Space Complexity Analysis
 * \subsection task Task 1
 * For converting the given string from <b>infix to prefix</b> form we have defined a function infixToPrefix()
 * \subsubsection time  Time Complexity -> O(n)
 * Because we traverse it through every single node of the parse tree so, the time complexity of the function is O(n).
 * \subsubsection space Space Complexity -> O(n)
 * Because it stores data from every single node thus, the time complexity is O(n).
 * 
 * \subsection task2 Task 2
 * For converting the given <b>prefix string to parse tree</b> form we have defined a function prefixToTree()
 * \subsubsection time Time Complexity -> O(n)
 * Assuming the worst case possibility, traversal through a skewed tree will have a time complexity of O(n).
 * \subsubsection space
 * Because it stores data from every single node thus, the time complexity is O(n).
 * 
 * \subsection task3 Task 3
 * For <b>in-order traversal</b> of the parse tree to output the infix expression we have defined the function 
 * printInorder() 
 * 
 * \subsubsection time
 * In worst case, we are traversing every node of the parse tree the time complexity is O(n).
 * \subsubsection space
 * Because it stores data from every single node thus, the time complexity is O(n).
 * 
 * \subsection task4 Task 4
 * For calculating the <b>height of the parse tree</b> we have defined the function height()
 * \subsubsection time
 * Because we traverse it through every single node of the parse tree so, the time complexity of the function is O(n).
 * \subsubsection space1 Space Complexity -> O(1)
 * Since, we are not storing anything.
 * 
 * \subsection task5 Task 5
 * For <b>evaluating the truth value</b> of the expression we have defined the function getAtoms()
 * \subsubsection time 
 * Because we traverse it through every single node of the parse tree so, the time complexity of the function is O(n).
 * \subsubsection space
*/



#include "parse_tree.hpp"

using namespace parse_tree;

int main() {
  
  // Task 1: Infix to prefix
  cout << "Enter infix expression: ";
  string infix;
  getline(cin, infix);

  string prefix = infixToPrefix(infix);
  cout << "Corresponding prefix expression: " << prefix << "\n";

  // Task 2: Prefix to Parse Tree
  Node* head = prefixToTree(prefix, 0, prefix.size() - 1).first;

  // Task 3: Inorder traversal 
  cout << "Inorder traversal of the binary tree: ";
  printInorder(head);

  // Task 4: Height of parse tree
  cout << "\nHeight of parse tree: " << height(head) << '\n';

  // Task 5: Evaluating the expression
  bool* atomsPresent = new bool[26];
  int* atoms = new int[26];
  getAtoms(head, atomsPresent);
  cout << "Enter value of each propositional atom (0 or 1): \n";
  for (int i = 0; i < 26; ++i) {
    if(atomsPresent[i]) {
	  cout << (char)('A' + i) << " = ";
	  cin >> atoms[i];
	}
  }
  cout << "Final evaluation: " << evaluate(head, atoms) << '\n';

  // Clean up code
  // Delete the parse tree (since it was allocated on the heap) 
  deleteTree(head);
  // Free the list of atoms
  delete[] atomsPresent;
  delete[] atoms;
  return 0;
}

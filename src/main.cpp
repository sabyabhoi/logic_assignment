/*! \mainpage proParser Documentation
 * \section time_complexity Time and Space Complexity Analysis
 *
 * \subsection task Task 1
 * For converting the given string from <b>infix to prefix</b> form we have
 * defined a function infixToPrefix()
 *
 * \subsubsection time  Time Complexity: O(n)
 * Since we're traversing the entire infix string once, the time complexity is
 * O(n).
 *
 * \subsubsection space Space Complexity: O(n)
 * Since we're storing the final output in a new string and returning it, the
 * space complexity is O(n).
 *
 * \subsection task2 Task 2
 * For converting the given <b>prefix string to parse tree</b> form we have
 * defined a function prefixToTree()
 *
 * \subsubsection time Time Complexity: O(n)
 * Since we have to traverse the entire prefix expression of length n, the time
 * complexity is O(n).
 *
 * \subsubsection space
 * Because it stores data from every single node thus, the time complexity is
 * O(n).
 *
 * \subsection task3 Task 3
 * For <b>in-order traversal</b> of the parse tree to output the infix
 * expression we have defined the function printInorder()
 *
 * \subsubsection time
 * We are traversing every node of the parse tree. Hence, the time complexity is
 * O(n).
 *
 * \subsubsection spaceh Space Complexity: O(h)
 * The space complexity is given by O(h), where h is the height of the parse
 * tree. This is due to the fact that a new recursive call is pushed onto the
 * function call stack when moving down a single sub-tree.
 * In the worst case, this height will be equal to number of nodes = n.
 *
 * \subsection task4 Task 4
 * For calculating the <b>height of the parse tree</b> we have defined the
 * function height()
 *
 * \subsubsection time
 * Because we traverse it through every single node of the parse tree so, the
 * time complexity of the function is O(n).
 *
 * \subsubsection spaceh
 * Again the space of the implicit function call stack is considered to conclude
 * that the space complexity is O(h). In the worst case, h = n.
 *
 * \subsection task5 Task 5
 * For <b>evaluating the truth value</b> of the expression we have defined the
 * evaluate() function.
 *
 * \subsubsection time
 * Because we traverse it through every single node of the parse tree so, the
 * time complexity of the function is O(n).
 *
 * \subsubsection spaceh
 * Again the space of the implicit function call stack is considered to conclude
 * that the space complexity is O(h). In the worst case, h = n.
 * 
 */

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

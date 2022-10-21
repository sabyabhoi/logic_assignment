#include "parse_tree.hpp"

namespace parse_tree {
/// Constructor for the Node struct
Node::Node(char x) : data(x), left(nullptr), right(nullptr) {}

/*!
 * @brief For recursively deleting nodes from bottom to top. If the head is not
 * a null pointer, recursively deletes the nodes. After deleting the left
 * child, deletes the right child and then finally deletes the head node.
 * @param head For a given subtree head is the parent node for that particular
 * subtree
 */
void deleteTree(Node *head) {
  if (head == nullptr)
    return;

  deleteTree(head->left);

  deleteTree(head->right);

  delete head;
}

/*!
 * @brief Used to retrieve the number edges from the root to the most distant
 * leaf node
 * @param root pointer to the root of the tree
 * @return height of the node
 */
int height(Node *root) {
  if (root == nullptr)
    return 0;
  int l = height(root->left), r = height(root->right);
  return (l > r ? l : r) + 1;
}

/// @brief Traverse the parse tree in an in-order fashion and print the contents
/// of each node
/// @param root pointer to the root of the tree
void printInorder(Node *root) {
  if (root == nullptr)
    return;

  printInorder(root->left);
  cout << root->data << ' ';
  printInorder(root->right);
}

/*!
 * @brief Convert an infix logical expression to a prefix expression.
 * @param s the infix expression
 * @return the prefix expression
 */
string infixToPrefix(string s) {
  stack::Stack st;
  reverse(s);

  string ans = "";

  for (char c : s) {
    if (c == ' ')
      continue;
    if (precedence(c) != -1) {
      if (st.empty() || st.top() == ')' ||
          precedence(c) > precedence(st.top())) {
        st.push(c);
      } else {
        while (!st.empty() && st.top() != ')' &&
               precedence(c) < precedence(st.top())) {
          ans.push_back(st.top());
          st.pop();
        }
        st.push(c);
      }
    } else if (c == ')') {
      st.push(c);
    } else if (c == '(') {
      while (st.top() != ')') {
        ans.push_back(st.top());
        st.pop();
      }
      st.pop();
    } else
      ans.push_back(c);
  }

  while (!st.empty()) {
    ans.push_back(st.top());
    st.pop();
  }

  reverse(ans);
  return ans;
}

/*!
 * @brief Retrieves all the propositional atoms from a given parse tree.
 * @param head the root of the parse tree
 * @param atoms a boolean array of size 26; The atoms which exist in the parse
 * tree are going to have a value of 1 at their respective numerical index in
 * this array
 */
void getAtoms(Node *head, bool *atoms) {
  if (head == nullptr)
    return;
  if (char_index(head->data) != -1) {
    atoms[char_index(head->data)] = true;
    return;
  }
  getAtoms(head->left, atoms);
  getAtoms(head->right, atoms);
}

/*!
 * @brief Takes a prefix expression and returns a parse tree for the expression
 * @param s the actual prefix expression
 * @param l the starting index of the expression
 * @param r the ending index of the expression
 * @return A pair containing the pointer to the root of the parse tree and an
 * integer which is required for internal processing.
 */
pair<Node *, int> prefixToTree(const string &s, int l, int r) {
  if (l > r)
    return {nullptr, l};
  else if (l == r)
    return {new Node(s[l]), l};

  Node *curr = new Node(s[l]);

  if (s[l] == '~') {
    auto right = prefixToTree(s, l + 1, r);
    curr->right = right.first;

    return {curr, right.second};
  } else if (s[l] == '*' || s[l] == '+' || s[l] == '>') {
    auto left = prefixToTree(s, l + 1, r);
    curr->left = left.first;

    auto right = prefixToTree(s, left.second + 1, r);
    curr->right = right.first;

    return {curr, right.second};
  }
  return {curr, l};
}

/*!
 * @brief Evaluate the given parse tree by passing in truth values for
 * individual propositional atom
 * @param head pointer to the root of the parse tree
 * @param vals an array of size 26, containing truth values for all the
 * propositional atoms. An important point to note here is that the
 * propositional atoms can only be case-insensitive english alphabets
 * @return true or false depending on the evaluation of the logical expression
 */
bool evaluate(Node *head, const int *vals) {
  if (head == nullptr)
    return false;
  if (char_index(head->data) != -1 && vals[char_index(head->data)] != -1)
    return vals[char_index(head->data)];

  bool l = evaluate(head->left, vals), r = evaluate(head->right, vals);
  switch (head->data) {
  case '~':
    return !r;
    break;
  case '+':
    return l || r;
    break;
  case '*':
    return l && r;
    break;
  case '>':
    return !l || r;
    break;
  default:
    return false;
    break;
  }
}
} // namespace parse_tree

#include <bits/stdc++.h>

using namespace std;

struct Node {
  char data;
  Node *left;
  Node *right;

  Node(char x) : data(x), left(nullptr), right(nullptr) {}
  Node(char x, Node *l, Node *r) : data(x), left(l), right(r) {}
};

int height(Node *root) {
  if (root == nullptr)
    return 0;
  return max(height(root->left), height(root->right)) + 1;
}

void deleteTree(Node *head) {
  if (head == nullptr)
    return;

  deleteTree(head->left);
  deleteTree(head->right);
  delete head;
}

void printInorder(Node* root) {
	if(root == nullptr) return;

	printInorder(root->left);
	cout << root->data << ' ';
	printInorder(root->right);
}

string infixToPrefix(string s) {
  stack<char> st;
  reverse(s.begin(), s.end());

  const unordered_map<char, int> operators = {{'>', 1}, {'+', 2}, {'*', 3}, {'~', 4}};
  string ans = "";

  for (char c : s) {
    if (c == ' ')
      continue;
    if (operators.find(c) != operators.end()) {
	  if (st.empty() || st.top() == ')' || operators.at(c) > operators.at(st.top())) {
        st.push(c);
      } else {
        while (!st.empty() && operators.at(c) < operators.at(st.top())) {
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
    } else ans.push_back(c);
  }

  while (!st.empty()) {
    ans.push_back(st.top());
    st.pop();
  }

  reverse(ans.begin(), ans.end());
  return ans;
}

pair<Node *, int> prefixToTree(const string& s, int l, int r) {
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

bool evaluate(Node* head, const unordered_map<char, bool>& vals) {
  if(head == nullptr) return false;
  if(vals.find(head->data) != vals.end())
	return vals.at(head->data);

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

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  string prefix = infixToPrefix(s);
  Node *root = prefixToTree(prefix, 0, prefix.size() - 1).first;

  cout << "Prefix: " << prefix << "\n";
  cout << "Inorder: " << '\n';
  printInorder(root);
  cout << "\nHeight: " << height(root) << "\n";

  unordered_map<char, bool> vals;
  for (int i = 0; i < n; ++i) {
	char c;
	cin >> c;
	int a;
	cin >> a;
	vals[c] = a;
  }
  cout << "Evaluate: " << evaluate(root, vals) << '\n';

  deleteTree(root);
  return 0;
}

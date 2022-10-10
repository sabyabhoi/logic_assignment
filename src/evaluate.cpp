#include <bits/stdc++.h>

#define deb(x) cout << #x << " = " << x << endl

#define MOD 1000000007

#define REP(i, n) for(int i = 0; i < (n); ++i)
#define FOR(i, s, n) for(int i = (s); i < (n); ++i)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;

template<typename T>
void print_vec(const vector<T>& v) {
  for(const T& i : v) cout << i << ' ';
  cout << '\n';
}

struct Node {
 char data;
  struct Node *left;
  struct Node *right;
  
  Node (char x) : data(x), left(nullptr), right(nullptr) {}
  Node (char x, Node *l, Node *r) : data(x), left(l), right(r) {}
};

int height(Node *root) {
  if(root == nullptr) return 0;
  return max(height(root->left), height(root->right)) + 1;
}

void deleteTree(Node* head) {
  if(head == nullptr) return;

  deleteTree(head->left);
  deleteTree(head->right);
  delete head;
}

pair<Node*, int> prefixToTree(const string& s, int l, int r) {
  if(l > r) return {nullptr, l};
  else if(l == r) 
	return {new Node(s[l]), l};

  Node* curr = new Node(s[l]);

  if(s[l] == '~') {
	auto right = prefixToTree(s, l + 1, r);
	curr->right = right.first;

	return {curr, right.second};
  }
  else if(s[l] == '*' || s[l] == '+' || s[l] == '>') {
	auto left = prefixToTree(s, l + 1, r);
	curr->left = left.first;

	auto right = prefixToTree(s, left.second + 1, r);
	curr->right = right.first;

	return {curr, right.second};
  }
  return {curr, l};
}

bool evaluate(Node* head, const unordered_map<char, bool>& vals) {
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

void solve() {

}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
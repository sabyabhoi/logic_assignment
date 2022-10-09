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

string infixToPrefix(string s) {
  stack<char> st;
  reverse(s.begin(), s.end());

  unordered_map<char, int> operators = {{'>', 1}, {'+', 2}, {'*', 3}, {'~', 4}};
  string ans = "";

  for(char c : s) {
	if(c == ' ') continue;
	if(operators.find(c) != operators.end()) {
	  if(st.empty() || operators[c] > operators[st.top()]) st.push(c);
	  else {
		ans.push_back(st.top());
		st.pop();
		st.push(c);
	  }
	}
	else if(c == ')') st.push(c);
	else if(c == '(') {
	  while(st.top() != ')') {
		ans.push_back(st.top());
		st.pop();
	  }
	  st.pop();
	}
	else ans.push_back(c);
  }

  while(!st.empty()) {
	ans.push_back(st.top());
	st.pop();
  }

  reverse(ans.begin(), ans.end());
  return ans;
}

void solve() {
  string s; cin >> s;
  cout << infixToPrefix(s) << '\n';
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

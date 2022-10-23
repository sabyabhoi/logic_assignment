#include "parse_tree.hpp"
#include "gtest/gtest.h"

TEST(ParseTreeTest, InfixToPrefix) {
  using namespace parse_tree;
  EXPECT_EQ(infixToPrefix("A+B"), "+AB");
  EXPECT_EQ(infixToPrefix("(A+B)"), "+AB");
  EXPECT_EQ(infixToPrefix("A+B*C"), "+A*BC");
  EXPECT_EQ(infixToPrefix("(A+B)*C"), "*+ABC");
}

TEST(ParseTreeTest, HeightAndRoot) {
  using namespace parse_tree;
  auto test_expression = [](const string &s, int h, char root) {
    Node *head = prefixToTree(s, 0, s.size() - 1).first;
	EXPECT_EQ(head->data, root) << head->data << " != " << root;
	EXPECT_EQ(height(head), h) << height(head) << " != " << h;
	deleteTree(head);
  };
  test_expression("+AB", 2, '+');
  test_expression("+A*BC", 3, '+');
}

TEST(ParseTreeTest, OrEval) {
  using namespace parse_tree;
  Node *head = prefixToTree("+AB", 0, 2).first;
  int vals[26];
  for(int i = 0; i < 26; ++i) {
	vals[i] = -1;
  }
  vals[char_index('A')] = 0;
  vals[char_index('B')] = 0;
  EXPECT_EQ(evaluate(head, vals), 0);
  vals[char_index('A')] = 1;
  vals[char_index('B')] = 0;
  EXPECT_EQ(evaluate(head, vals), 1);
  vals[char_index('A')] = 0;
  vals[char_index('B')] = 1;
  EXPECT_EQ(evaluate(head, vals), 1);
  vals[char_index('A')] = 1;
  vals[char_index('B')] = 1;
  EXPECT_EQ(evaluate(head, vals), 1);
  deleteTree(head);
}

TEST(ParseTreeTest, ImplicationEval) {
  using namespace parse_tree;
  Node *head = prefixToTree(">AB", 0, 2).first;
  int vals[26];
  for(int i = 0; i < 26; ++i) {
	vals[i] = -1;
  }
  vals[char_index('A')] = 0;
  vals[char_index('B')] = 0;
  EXPECT_EQ(evaluate(head, vals), 1);
  vals[char_index('A')] = 1;
  vals[char_index('B')] = 0;
  EXPECT_EQ(evaluate(head, vals), 0);
  vals[char_index('A')] = 0;
  vals[char_index('B')] = 1;
  EXPECT_EQ(evaluate(head, vals), 1);
  vals[char_index('A')] = 1;
  vals[char_index('B')] = 1;
  EXPECT_EQ(evaluate(head, vals), 1);
  deleteTree(head);
}


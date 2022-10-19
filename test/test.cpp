#include "parse_tree.hpp"
#include "stack.hpp"
#include "utils.hpp"
#include "gtest/gtest.h"

TEST(StackTest, PushPopValues) {
  stack::Stack st;

  st.push('A');
  EXPECT_EQ(st.top(), 'A');
  st.push('B');
  EXPECT_EQ(st.top(), 'B');
  st.push('C');
  EXPECT_EQ(st.top(), 'C');
  EXPECT_EQ(st.size, 3);

  st.pop();
  st.pop();
  st.pop();
  EXPECT_EQ(st.empty(), true);
}

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

TEST(ParseTreeTest, Evaluation) {
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

TEST(UtilsTest, CharIndex) {
  EXPECT_EQ(char_index('A'), 0);
  EXPECT_EQ(char_index('B'), 1);
  EXPECT_EQ(char_index('Z'), 25);
  EXPECT_EQ(char_index('a'), 0);
  EXPECT_EQ(char_index('b'), 1);
  EXPECT_EQ(char_index('z'), 25);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

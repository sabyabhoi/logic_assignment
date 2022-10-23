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

TEST(UtilsTest, CharIndex) {
  EXPECT_EQ(char_index('A'), 0);
  EXPECT_EQ(char_index('B'), 1);
  EXPECT_EQ(char_index('Z'), 25);
  EXPECT_EQ(char_index('a'), 0);
  EXPECT_EQ(char_index('b'), 1);
  EXPECT_EQ(char_index('z'), 25);
}

TEST(UtilsTest, Precedence) {
	EXPECT_EQ(precedence('>'), 1);
	EXPECT_EQ(precedence('+'), 2);
	EXPECT_EQ(precedence('*'), 3);
	EXPECT_EQ(precedence('~'), 4);
	EXPECT_EQ(precedence('<'), -1);
}
int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

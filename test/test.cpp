#include "stack.hpp"
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

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

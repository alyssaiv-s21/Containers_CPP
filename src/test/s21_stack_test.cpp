#include "../s21_stack.hpp"

#include <stack>

using namespace s21;

TEST(StackTest, test_1) {
  stack<int> int_stack{1, 2, 3, 4, 5, 6};
  EXPECT_TRUE(int_stack.empty() == false);
  EXPECT_TRUE(int_stack.size() == 6);
  EXPECT_TRUE(int_stack.top() == 6);
  int_stack.push(16);
  int_stack.push(17);
  EXPECT_TRUE(int_stack.top() == 17);
  int_stack.pop();
  EXPECT_TRUE(int_stack.top() == 16);
  int_stack.pop();
  int_stack.pop();
  int_stack.pop();
  int_stack.pop();
  EXPECT_TRUE(int_stack.size() == 3);
  EXPECT_TRUE(int_stack.top() == 3);
  int_stack.pop();
  int_stack.pop();
  int_stack.pop();
  EXPECT_TRUE(int_stack.empty() == true);
}

TEST(StackTest, test_2) {
  stack<char> char_stack{'a', 'b', 'c', 'd', 'e', 'f'};
  EXPECT_TRUE(char_stack.empty() == false);
  EXPECT_TRUE(char_stack.size() == 6);
  EXPECT_TRUE(char_stack.top() == 'f');
  char_stack.push('w');
  char_stack.push('o');
  EXPECT_TRUE(char_stack.top() == 'o');
  char_stack.pop();
  EXPECT_TRUE(char_stack.top() == 'w');
  char_stack.pop();
  char_stack.pop();
  char_stack.pop();
  char_stack.pop();
  EXPECT_TRUE(char_stack.size() == 3);
  EXPECT_TRUE(char_stack.top() == 'c');
  char_stack.pop();
  char_stack.pop();
  char_stack.pop();
  EXPECT_TRUE(char_stack.empty() == true);
}

TEST(StackTest, test_3) {
  stack<std::string> str_one{"to", "too", "tooo", "toooo"};
  stack<std::string> str_copy_one(str_one);
  EXPECT_TRUE(str_one.empty() == str_copy_one.empty());
  EXPECT_TRUE(str_one.size() == str_copy_one.size());
  EXPECT_TRUE(str_copy_one.top() == "toooo");
}

TEST(StackTest, test_4) {
  stack<std::string> str_one{"to", "too", "tooo", "toooo"};
  stack<std::string> str_move_one(std::move(str_one));
  EXPECT_TRUE(str_move_one.empty() == false);
  EXPECT_TRUE(str_move_one.size() == 4);
  EXPECT_TRUE(str_move_one.top() == "toooo");
}

TEST(StackTest, test_5) {
  stack<int> int_one{1, 2, 3, 4};
  stack<int> int_copy_one;
  int_copy_one = int_one;
  EXPECT_TRUE(int_copy_one.empty() == false);
  EXPECT_TRUE(int_copy_one.size() == 4);
  EXPECT_TRUE(int_copy_one.top() == 4);
}

TEST(StackTest, test_6) {
  stack<int> int_one{1, 2, 3, 4};
  stack<int> int_move_one;
  int_move_one = std::move(int_one);
  EXPECT_TRUE(int_move_one.empty() == false);
  EXPECT_TRUE(int_move_one.size() == 4);
  EXPECT_TRUE(int_move_one.top() == 4);
}

TEST(StackTest, test_7) {
  stack<int> emp;
  EXPECT_TRUE(emp.empty() == true);
  EXPECT_TRUE(emp.size() == 0);
}

TEST(StackTest, test_8) {
  const stack<int> c_int{3, 4, 5};
  EXPECT_TRUE(c_int.top() == 5);
}

TEST(StackTest, test_9) {
  stack<std::string> str_one{"to", "too", "tooo", "toooo"};
  stack<std::string> str_two{"in", "inn"};
  str_one.swap(str_two);
  EXPECT_TRUE(str_one.size() == 2);
  EXPECT_TRUE(str_two.size() == 4);
  EXPECT_TRUE(str_one.top() == "inn");
  EXPECT_TRUE(str_two.top() == "toooo");
  str_two.swap(str_one);
  EXPECT_TRUE(str_one.size() == 4);
  EXPECT_TRUE(str_two.size() == 2);
  EXPECT_TRUE(str_one.top() == "toooo");
  EXPECT_TRUE(str_two.top() == "inn");
}

TEST(StackTest, bonus2) {
  stack<int> int_stack{1, 2, 3, 4, 5, 6};
  int_stack.emplace_front(101, 102);
  EXPECT_TRUE(int_stack.top() == 102);
  int_stack.pop();
  EXPECT_TRUE(int_stack.top() == 101);
}

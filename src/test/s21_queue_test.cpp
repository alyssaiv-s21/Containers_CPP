#include "../s21_queue.hpp"

#include <queue>

using namespace s21;

TEST(QueueTest, test_1) {
  queue<int> int_queue{1, 2, 3, 4, 5, 6};
  EXPECT_TRUE(int_queue.empty() == false);
  EXPECT_TRUE(int_queue.size() == 6);
  EXPECT_TRUE(int_queue.back() == 6);
  int_queue.push(16);
  int_queue.push(17);
  EXPECT_TRUE(int_queue.back() == 17);
  int_queue.pop();
  EXPECT_TRUE(int_queue.front() == 2);
  int_queue.pop();
  int_queue.pop();
  int_queue.pop();
  int_queue.pop();
  EXPECT_TRUE(int_queue.front() == 6);
  EXPECT_TRUE(int_queue.size() == 3);
  EXPECT_TRUE(int_queue.back() == 17);
  int_queue.pop();
  int_queue.pop();
  int_queue.pop();
  EXPECT_TRUE(int_queue.empty() == true);
}

TEST(QueueTest, test_2) {
  queue<char> char_queue{'a', 'b', 'c', 'd', 'e', 'f'};
  EXPECT_TRUE(char_queue.empty() == false);
  EXPECT_TRUE(char_queue.size() == 6);
  EXPECT_TRUE(char_queue.back() == 'f');
  char_queue.push('w');
  char_queue.push('o');
  EXPECT_TRUE(char_queue.back() == 'o');
  char_queue.pop();
  EXPECT_TRUE(char_queue.front() == 'b');
  char_queue.pop();
  char_queue.pop();
  char_queue.pop();
  char_queue.pop();
  EXPECT_TRUE(char_queue.size() == 3);
  EXPECT_TRUE(char_queue.front() == 'f');
  char_queue.pop();
  EXPECT_TRUE(char_queue.front() == 'w');
  char_queue.pop();
  char_queue.pop();
  EXPECT_TRUE(char_queue.empty() == true);
}

TEST(QueueTest, test_3) {
  queue<std::string> str_one{"to", "too", "tooo", "toooo"};
  queue<std::string> str_copy_one(str_one);
  EXPECT_TRUE(str_one.empty() == str_copy_one.empty());
  EXPECT_TRUE(str_one.size() == str_copy_one.size());
  EXPECT_TRUE(str_copy_one.back() == "toooo");
  EXPECT_TRUE(str_copy_one.front() == "to");
}

TEST(QueueTest, test_4) {
  queue<std::string> str_one{"to", "too", "tooo", "toooo"};
  queue<std::string> str_move_one(std::move(str_one));
  EXPECT_TRUE(str_move_one.empty() == false);
  EXPECT_TRUE(str_move_one.size() == 4);
  EXPECT_TRUE(str_move_one.back() == "toooo");
  EXPECT_TRUE(str_move_one.front() == "to");
}

TEST(QueueTest, test_5) {
  queue<int> int_one{1, 2, 3, 4};
  queue<int> int_copy_one;
  int_copy_one = int_one;
  EXPECT_TRUE(int_copy_one.empty() == false);
  EXPECT_TRUE(int_copy_one.size() == 4);
  EXPECT_TRUE(int_copy_one.back() == 4);
}

TEST(QueueTest, test_6) {
  queue<int> int_one{1, 2, 3, 4};
  queue<int> int_move_one;
  int_move_one = std::move(int_one);
  EXPECT_TRUE(int_move_one.empty() == false);
  EXPECT_TRUE(int_move_one.size() == 4);
  EXPECT_TRUE(int_move_one.back() == 4);
}

TEST(QueueTest, test_7) {
  queue<int> emp;
  EXPECT_TRUE(emp.empty() == true);
  EXPECT_TRUE(emp.size() == 0);
}

TEST(QueueTest, test_8) {
  const queue<int> c_int{3, 4, 5};
  EXPECT_TRUE(c_int.back() == 5);
  EXPECT_TRUE(c_int.front() == 3);
}

TEST(QueueTest, test_9) {
  queue<std::string> str_one{"to", "too", "tooo", "toooo"};
  queue<std::string> str_two{"in", "inn"};
  str_one.swap(str_two);
  EXPECT_TRUE(str_one.size() == 2);
  EXPECT_TRUE(str_two.size() == 4);
  EXPECT_TRUE(str_one.back() == "inn");
  EXPECT_TRUE(str_two.back() == "toooo");
  str_two.swap(str_one);
  EXPECT_TRUE(str_one.size() == 4);
  EXPECT_TRUE(str_two.size() == 2);
  EXPECT_TRUE(str_one.back() == "toooo");
  EXPECT_TRUE(str_two.back() == "inn");
}

TEST(QueueTest, test_10) {
  queue<int> q_int{2, 6, 5};
  q_int.emplace_back(45, 23, 16);
  EXPECT_TRUE(q_int.back() == 16);
  q_int.pop();
  q_int.pop();
  q_int.pop();
  EXPECT_TRUE(q_int.front() == 45);
}

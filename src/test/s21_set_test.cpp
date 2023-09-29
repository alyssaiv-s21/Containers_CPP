#include "../s21_set.hpp"

#include <set>

class SetTest : public ::testing::Test {
 protected:
  s21::set<int> set_int{5, 3, 14, 6, 78, 23, 65};
  std::set<int> std_set_int{5, 3, 14, 6, 78, 23, 65};
  s21::set<std::string> set_str{"standard", "template", "library"};
  std::set<std::string> std_set_str{"standard", "template", "library"};
  s21::set<char> set_char{'c', 'b', 'w', 'd', 'a'};
  std::set<char> std_set_char{'c', 'b', 'w', 'd', 'a'};
  const s21::set<int> cset_int{5, 2, 1, 7, 18};
  const std::set<int> std_cset_int{5, 2, 1, 7, 18};
};

TEST_F(SetTest, init_list) {
  EXPECT_TRUE(set_int.size() == std_set_int.size());
  EXPECT_TRUE(set_int.empty() == std_set_int.empty());
  auto int_iter = set_int.begin();
  auto std_int_iter = std_set_int.begin();
  for (size_t i = 0; i < set_int.size(); ++i) {
    EXPECT_TRUE(*int_iter == *std_int_iter);
    ++int_iter;
    ++std_int_iter;
  }
  EXPECT_TRUE(set_str.size() == std_set_str.size());
  auto str_iter = set_str.begin();
  auto std_str_iter = std_set_str.begin();
  for (size_t i = 0; i < set_str.size(); ++i) {
    EXPECT_TRUE(*str_iter == *std_str_iter);
    ++str_iter;
    ++std_str_iter;
  }
  EXPECT_TRUE(set_char.size() == std_set_char.size());
  auto char_iter = set_char.begin();
  auto std_char_iter = std_set_char.begin();
  for (size_t i = 0; i < set_char.size(); ++i) {
    EXPECT_TRUE(*char_iter == *std_char_iter);
    ++char_iter;
    ++std_char_iter;
  }

  EXPECT_TRUE(cset_int.size() == std_cset_int.size());
  auto int_citer = cset_int.begin();
  auto std_int_citer = std_cset_int.begin();
  for (size_t i = 0; i < cset_int.size(); ++i) {
    EXPECT_TRUE(*int_citer == *std_int_citer);
    ++int_citer;
    ++std_int_citer;
  }
}

TEST(SetTestPlus, empty_init) {
  s21::set<int> set_int{};
  std::set<int> std_set_int{};
  EXPECT_TRUE(set_int.size() == std_set_int.size());
  EXPECT_TRUE(set_int.empty() == std_set_int.empty());
  ASSERT_FLOAT_EQ(set_int.max_size(), std_set_int.max_size());
}

TEST_F(SetTest, copy_constr) {
  s21::set<int> copy_int(set_int);
  std::set<int> copy_std_int(std_set_int);
  EXPECT_TRUE(copy_int.size() == copy_std_int.size());
  auto int_iter = copy_int.begin();
  auto std_int_iter = copy_std_int.begin();
  for (size_t i = 0; i < set_int.size(); ++i) {
    EXPECT_TRUE(*int_iter == *std_int_iter);
    ++int_iter;
    ++std_int_iter;
  }
}

TEST_F(SetTest, move_constr) {
  s21::set<int> move_int(std::move(set_int));
  std::set<int> move_std_int(std::move(std_set_int));
  EXPECT_TRUE(move_int.size() == move_std_int.size());
  auto int_iter = move_int.begin();
  auto std_int_iter = move_std_int.begin();
  for (size_t i = 0; i < move_int.size(); ++i) {
    EXPECT_TRUE(*int_iter == *std_int_iter);
    ++int_iter;
    ++std_int_iter;
  }
}

TEST_F(SetTest, copy_asign) {
  s21::set<int> copy_int;
  copy_int = set_int;
  std::set<int> copy_std_int;
  copy_std_int = std_set_int;
  EXPECT_TRUE(copy_int.size() == copy_std_int.size());
  auto int_iter = copy_int.begin();
  auto std_int_iter = copy_std_int.begin();
  for (size_t i = 0; i < set_int.size(); ++i) {
    EXPECT_TRUE(*int_iter == *std_int_iter);
    ++int_iter;
    ++std_int_iter;
  }
}

TEST_F(SetTest, move_asign) {
  s21::set<int> move_int;
  move_int = std::move(set_int);
  std::set<int> move_std_int;
  move_std_int = std::move(std_set_int);
  EXPECT_TRUE(move_int.size() == move_std_int.size());
  auto int_iter = move_int.begin();
  auto std_int_iter = move_std_int.begin();
  for (size_t i = 0; i < move_int.size(); ++i) {
    EXPECT_TRUE(*int_iter == *std_int_iter);
    ++int_iter;
    ++std_int_iter;
  }
}

TEST_F(SetTest, erase_test) {
  set_int.erase(++set_int.begin());
  std_set_int.erase(++std_set_int.begin());
  EXPECT_TRUE(set_int.size() == std_set_int.size());
  EXPECT_TRUE(set_int.empty() == std_set_int.empty());
  auto int_iter = set_int.begin();
  auto std_int_iter = std_set_int.begin();
  for (size_t i = 0; i < set_int.size(); ++i) {
    EXPECT_TRUE(*int_iter == *std_int_iter);
    ++int_iter;
    ++std_int_iter;
  }

  set_str.erase(set_str.begin());
  std_set_str.erase(std_set_str.begin());
  EXPECT_TRUE(set_str.size() == std_set_str.size());
  auto str_iter = set_str.begin();
  auto std_str_iter = std_set_str.begin();
  for (size_t i = 0; i < set_str.size(); ++i) {
    EXPECT_TRUE(*str_iter == *std_str_iter);
    ++str_iter;
    ++std_str_iter;
  }

  set_char.erase(--set_char.end());
  std_set_char.erase(--std_set_char.end());
  EXPECT_TRUE(set_char.size() == std_set_char.size());
  auto char_iter = set_char.begin();
  auto std_char_iter = std_set_char.begin();
  for (size_t i = 0; i < set_char.size(); ++i) {
    EXPECT_TRUE(*char_iter == *std_char_iter);
    ++char_iter;
    ++std_char_iter;
  }
}

TEST_F(SetTest, erase_test2) {
  auto my_iter = set_int.end();
  set_int.erase(my_iter);
  EXPECT_TRUE(set_int.size() == std_set_int.size());
  EXPECT_TRUE(set_int.empty() == std_set_int.empty());
  auto int_iter = set_int.begin();
  auto std_int_iter = std_set_int.begin();
  for (size_t i = 0; i < set_int.size(); ++i) {
    EXPECT_TRUE(*int_iter == *std_int_iter);
    ++int_iter;
    ++std_int_iter;
  }
}

TEST_F(SetTest, insert_test3) {
  set_char.insert('a');
  std_set_char.insert('a');
  set_char.insert('w');
  std_set_char.insert('w');
  set_char.insert('l');
  std_set_char.insert('l');
  EXPECT_TRUE(set_char.size() == std_set_char.size());
  auto char_iter = set_char.begin();
  auto std_char_iter = std_set_char.begin();
  for (size_t i = 0; i < set_char.size(); ++i) {
    EXPECT_TRUE(*char_iter == *std_char_iter);
    ++char_iter;
    ++std_char_iter;
  }
}

TEST_F(SetTest, merge_test) {
  s21::set<char> set_char_two{'e', 'f', 'g', 'a', 'd'};
  std::set<char> std_set_char_two{'e', 'f', 'g', 'a', 'd'};
  set_char.merge(set_char_two);
  std_set_char.merge(std_set_char_two);
  EXPECT_TRUE(set_char.size() == std_set_char.size());
  EXPECT_TRUE(set_char.empty() == std_set_char.empty());
  auto char_iter = set_char.begin();
  auto std_char_iter = std_set_char.begin();
  for (size_t i = 0; i < set_char.size(); ++i) {
    EXPECT_TRUE(*char_iter == *std_char_iter);
    ++char_iter;
    ++std_char_iter;
  }
}

TEST_F(SetTest, find_test) {
  auto set_iter = set_int.find(14);
  auto set_std_iter = std_set_int.find(14);
  EXPECT_TRUE(*set_iter == *set_std_iter);
}

TEST_F(SetTest, contains_test) {
  bool if_find = set_int.contains(14);
  EXPECT_TRUE(if_find == true);
  if_find = set_char.contains('n');
  EXPECT_TRUE(if_find == false);
}

TEST_F(SetTest, test) {
  auto citer(cset_int.end());
  auto citer_std(std_cset_int.end());
  EXPECT_TRUE(*(--citer) == *(--citer_std));
  EXPECT_TRUE(*(--citer) == *(--citer_std));
  EXPECT_TRUE(*(--citer) == *(--citer_std));
  EXPECT_TRUE(*(--citer) == *(--citer_std));
  EXPECT_TRUE(*(--citer) == *(--citer_std));
  EXPECT_TRUE(citer == cset_int.begin());
  auto copy_citer(citer);
  EXPECT_TRUE(citer == copy_citer);
}

TEST(SetTestPlus, test2) {
  const s21::set<int> cset_int{15, 26, 7, 4, 6, 8, 20, 48, 21};
  auto citer(cset_int.end());
  EXPECT_TRUE(*(--citer) == 48);
  EXPECT_TRUE(*(--citer) == 26);
  EXPECT_TRUE(*(--citer) == 21);
  EXPECT_TRUE(*(--citer) == 20);
  EXPECT_TRUE(*(--citer) == 15);
  EXPECT_TRUE(*(--citer) == 8);
  EXPECT_TRUE(*(--citer) == 7);
  EXPECT_TRUE(*(--citer) == 6);
  EXPECT_TRUE(*(--citer) == 4);
  EXPECT_TRUE(citer == cset_int.begin());
  auto copy_citer(citer);
  EXPECT_TRUE(citer == copy_citer);
}

TEST_F(SetTest, emplace2) {
  set_int.emplace(101, 13);
  bool if_find = set_int.contains(101);
  EXPECT_TRUE(if_find == true);
  if_find = set_int.contains(13);
  EXPECT_TRUE(if_find == true);
}

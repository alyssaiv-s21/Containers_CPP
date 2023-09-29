#include "../s21_multiset.hpp"

#include <set>

class MultisetTest : public ::testing::Test {
 protected:
  s21::multiset<int> multiset_int{5, 3, 65, 14, 6, 78, 23, 65};
  std::multiset<int> std_multiset_int{5, 3, 65, 14, 6, 78, 23, 65};
  s21::multiset<std::string> multiset_str{"standard", "template", "library",
                                          "standard"};
  std::multiset<std::string> std_multiset_str{"standard", "template", "library",
                                              "standard"};
  s21::multiset<char> multiset_char{'c', 'b', 'w', 'd', 'a'};
  std::multiset<char> std_multiset_char{'c', 'b', 'w', 'd', 'a'};
  const s21::multiset<int> cmultiset_int{5, 2, 1, 7, 18};
  const std::multiset<int> std_cmultiset_int{5, 2, 1, 7, 18};
};

TEST_F(MultisetTest, init_list) {
  EXPECT_TRUE(multiset_int.size() == std_multiset_int.size());
  EXPECT_TRUE(multiset_int.empty() == std_multiset_int.empty());
  auto int_iter = multiset_int.begin();
  auto std_int_iter = std_multiset_int.begin();
  for (size_t i = 0; i < multiset_int.size(); ++i) {
    EXPECT_TRUE(*int_iter == *std_int_iter);
    ++int_iter;
    ++std_int_iter;
  }
  EXPECT_TRUE(multiset_str.size() == std_multiset_str.size());
  auto str_iter = multiset_str.begin();
  auto std_str_iter = std_multiset_str.begin();
  for (size_t i = 0; i < multiset_str.size(); ++i) {
    EXPECT_TRUE(*str_iter == *std_str_iter);
    ++str_iter;
    ++std_str_iter;
  }
  EXPECT_TRUE(multiset_char.size() == std_multiset_char.size());
  auto char_iter = multiset_char.begin();
  auto std_char_iter = std_multiset_char.begin();
  for (size_t i = 0; i < multiset_char.size(); ++i) {
    EXPECT_TRUE(*char_iter == *std_char_iter);
    ++char_iter;
    ++std_char_iter;
  }

  EXPECT_TRUE(cmultiset_int.size() == std_cmultiset_int.size());
  auto int_citer = cmultiset_int.begin();
  auto std_int_citer = std_cmultiset_int.begin();
  for (size_t i = 0; i < cmultiset_int.size(); ++i) {
    EXPECT_TRUE(*int_citer == *std_int_citer);
    ++int_citer;
    ++std_int_citer;
  }
}

TEST(MultisetTestPlus, empty_init) {
  s21::multiset<int> multiset_int{};
  std::multiset<int> std_multiset_int{};
  EXPECT_TRUE(multiset_int.size() == std_multiset_int.size());
  EXPECT_TRUE(multiset_int.empty() == std_multiset_int.empty());
  ASSERT_FLOAT_EQ(multiset_int.max_size(), std_multiset_int.max_size());
}

TEST_F(MultisetTest, copy_constr) {
  s21::multiset<int> copy_int(multiset_int);
  std::multiset<int> copy_std_int(std_multiset_int);
  EXPECT_TRUE(copy_int.size() == copy_std_int.size());
  auto int_iter = copy_int.begin();
  auto std_int_iter = copy_std_int.begin();
  for (size_t i = 0; i < multiset_int.size(); ++i) {
    EXPECT_TRUE(*int_iter == *std_int_iter);
    ++int_iter;
    ++std_int_iter;
  }
}

TEST_F(MultisetTest, move_constr) {
  s21::multiset<int> move_int(std::move(multiset_int));
  std::multiset<int> move_std_int(std::move(std_multiset_int));
  EXPECT_TRUE(move_int.size() == move_std_int.size());
  auto int_iter = move_int.begin();
  auto std_int_iter = move_std_int.begin();
  for (size_t i = 0; i < move_int.size(); ++i) {
    EXPECT_TRUE(*int_iter == *std_int_iter);
    ++int_iter;
    ++std_int_iter;
  }
}

TEST_F(MultisetTest, copy_asign) {
  s21::multiset<int> copy_int;
  copy_int = multiset_int;
  std::multiset<int> copy_std_int;
  copy_std_int = std_multiset_int;
  EXPECT_TRUE(copy_int.size() == copy_std_int.size());
  auto int_iter = copy_int.begin();
  auto std_int_iter = copy_std_int.begin();
  for (size_t i = 0; i < multiset_int.size(); ++i) {
    EXPECT_TRUE(*int_iter == *std_int_iter);
    ++int_iter;
    ++std_int_iter;
  }
}

TEST_F(MultisetTest, move_asign) {
  s21::multiset<int> move_int;
  move_int = std::move(multiset_int);
  std::multiset<int> move_std_int;
  move_std_int = std::move(std_multiset_int);
  EXPECT_TRUE(move_int.size() == move_std_int.size());
  auto int_iter = move_int.begin();
  auto std_int_iter = move_std_int.begin();
  for (size_t i = 0; i < move_int.size(); ++i) {
    EXPECT_TRUE(*int_iter == *std_int_iter);
    ++int_iter;
    ++std_int_iter;
  }
}

TEST_F(MultisetTest, erase_test) {
  multiset_int.erase(++multiset_int.begin());
  std_multiset_int.erase(++std_multiset_int.begin());
  EXPECT_TRUE(multiset_int.size() == std_multiset_int.size());
  EXPECT_TRUE(multiset_int.empty() == std_multiset_int.empty());
  auto int_iter = multiset_int.begin();
  auto std_int_iter = std_multiset_int.begin();
  for (size_t i = 0; i < multiset_int.size(); ++i) {
    EXPECT_TRUE(*int_iter == *std_int_iter);
    ++int_iter;
    ++std_int_iter;
  }

  multiset_str.erase(multiset_str.begin());
  std_multiset_str.erase(std_multiset_str.begin());
  EXPECT_TRUE(multiset_str.size() == std_multiset_str.size());
  auto str_iter = multiset_str.begin();
  auto std_str_iter = std_multiset_str.begin();
  for (size_t i = 0; i < multiset_str.size(); ++i) {
    EXPECT_TRUE(*str_iter == *std_str_iter);
    ++str_iter;
    ++std_str_iter;
  }

  multiset_char.erase(--multiset_char.end());
  std_multiset_char.erase(--std_multiset_char.end());
  EXPECT_TRUE(multiset_char.size() == std_multiset_char.size());
  auto char_iter = multiset_char.begin();
  auto std_char_iter = std_multiset_char.begin();
  for (size_t i = 0; i < multiset_char.size(); ++i) {
    EXPECT_TRUE(*char_iter == *std_char_iter);
    ++char_iter;
    ++std_char_iter;
  }
}

TEST_F(MultisetTest, erase_test2) {
  auto my_iter = multiset_int.end();
  multiset_int.erase(my_iter);
  EXPECT_TRUE(multiset_int.size() == std_multiset_int.size());
  EXPECT_TRUE(multiset_int.empty() == std_multiset_int.empty());
  auto int_iter = multiset_int.begin();
  auto std_int_iter = std_multiset_int.begin();
  for (size_t i = 0; i < multiset_int.size(); ++i) {
    EXPECT_TRUE(*int_iter == *std_int_iter);
    ++int_iter;
    ++std_int_iter;
  }
}

TEST_F(MultisetTest, insert_test3) {
  multiset_char.insert('a');
  std_multiset_char.insert('a');
  multiset_char.insert('w');
  std_multiset_char.insert('w');
  multiset_char.insert('l');
  std_multiset_char.insert('l');
  EXPECT_TRUE(multiset_char.size() == std_multiset_char.size());
  auto char_iter = multiset_char.begin();
  auto std_char_iter = std_multiset_char.begin();
  for (size_t i = 0; i < multiset_char.size(); ++i) {
    EXPECT_TRUE(*char_iter == *std_char_iter);
    ++char_iter;
    ++std_char_iter;
  }
}

TEST_F(MultisetTest, merge_test) {
  s21::multiset<char> multiset_char_two{'e', 'f', 'g', 'a', 'd'};
  std::multiset<char> std_multiset_char_two{'e', 'f', 'g', 'a', 'd'};
  multiset_char.merge(multiset_char_two);
  std_multiset_char.merge(std_multiset_char_two);
  EXPECT_TRUE(multiset_char.size() == std_multiset_char.size());
  EXPECT_TRUE(multiset_char.empty() == std_multiset_char.empty());
  auto char_iter = multiset_char.begin();
  auto std_char_iter = std_multiset_char.begin();
  for (size_t i = 0; i < multiset_char.size(); ++i) {
    EXPECT_TRUE(*char_iter == *std_char_iter);
    ++char_iter;
    ++std_char_iter;
  }
}

TEST_F(MultisetTest, test) {
  auto citer(cmultiset_int.end());
  auto citer_std(std_cmultiset_int.end());
  EXPECT_TRUE(*(--citer) == *(--citer_std));
  EXPECT_TRUE(*(--citer) == *(--citer_std));
  EXPECT_TRUE(*(--citer) == *(--citer_std));
  EXPECT_TRUE(*(--citer) == *(--citer_std));
  EXPECT_TRUE(*(--citer) == *(--citer_std));
  EXPECT_TRUE(citer == cmultiset_int.begin());
  auto copy_citer(citer);
  EXPECT_TRUE(citer == copy_citer);
}

TEST(MultisetTestPlus, test2) {
  const s21::multiset<int> cmultiset_int{15, 26, 7, 4, 6, 8, 21, 48, 21};
  auto citer(cmultiset_int.end());
  EXPECT_TRUE(*(--citer) == 48);
  EXPECT_TRUE(*(--citer) == 26);
  EXPECT_TRUE(*(--citer) == 21);
  EXPECT_TRUE(*(--citer) == 21);
  EXPECT_TRUE(*(--citer) == 15);
  EXPECT_TRUE(*(--citer) == 8);
  EXPECT_TRUE(*(--citer) == 7);
  EXPECT_TRUE(*(--citer) == 6);
  EXPECT_TRUE(*(--citer) == 4);
  EXPECT_TRUE(citer == cmultiset_int.begin());
  auto copy_citer(citer);
  EXPECT_TRUE(citer == copy_citer);
}

TEST_F(MultisetTest, emplace2) {
  multiset_int.emplace(101, 13);
  bool if_find = multiset_int.contains(101);
  EXPECT_TRUE(if_find == true);
  if_find = multiset_int.contains(13);
  EXPECT_TRUE(if_find == true);
}

TEST_F(MultisetTest, find_test) {
  auto multiset_iter = multiset_int.find(14);
  auto multiset_std_iter = std_multiset_int.find(14);
  EXPECT_TRUE(*multiset_iter == *multiset_std_iter);
}

TEST_F(MultisetTest, contains_test) {
  bool if_find = multiset_int.contains(14);
  EXPECT_TRUE(if_find == true);
  if_find = multiset_char.contains('n');
  EXPECT_TRUE(if_find == false);
}

TEST_F(MultisetTest, count_test) {
  size_t qty = multiset_int.count(65);
  EXPECT_TRUE(qty == 2);
}

TEST(MultisetTestPlus, low_bound) {
  s21::multiset<int> multiset_int{5, 3, 2, 3, 6, 3, 1};
  std::multiset<int> std_multiset_int{5, 3, 2, 3, 6, 3, 1};
  auto int_iter = multiset_int.lower_bound(3);
  auto std_int_iter = std_multiset_int.lower_bound(3);
  --int_iter;
  --std_int_iter;
  EXPECT_TRUE(*int_iter == *std_int_iter);
}

TEST(MultisetTestPlus, up_bound) {
  s21::multiset<int> multiset_int{5, 3, 2, 3, 6, 3, 1};
  std::multiset<int> std_multiset_int{5, 3, 2, 3, 6, 3, 1};
  auto int_iter = multiset_int.upper_bound(3);
  auto std_int_iter = std_multiset_int.upper_bound(3);
  EXPECT_TRUE(*int_iter == *std_int_iter);
}

TEST(MultisetTestPlus, low_up_bound) {
  s21::multiset<int> multiset_int{5, 3, 2, 3, 6, 3, 1};
  std::multiset<int> std_multiset_int{5, 3, 2, 3, 6, 3, 1};
  auto int_iter = multiset_int.equal_range(3);
  auto std_int_iter = std_multiset_int.equal_range(3);
  EXPECT_TRUE(*(int_iter.second) == *(std_int_iter.second));
  EXPECT_TRUE(*(int_iter.first) == *(std_int_iter.first));
}

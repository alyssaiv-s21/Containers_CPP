#include "../s21_list.hpp"

#include <list>

#include "../s21_listNode.hpp"

class ListTest : public ::testing::Test {
 protected:
  s21::list<int> l_int{1, 2, 3, 4, 5, 6, 7};
  std::list<int> std_l_int{1, 2, 3, 4, 5, 6, 7};
  s21::list<std::string> l_str{"standard", "template", "library"};
  std::list<std::string> std_l_str{"standard", "template", "library"};
  s21::list<char> l_char{'a', 'b', 'c', 'd'};
  std::list<char> std_l_char{'a', 'b', 'c', 'd'};
  const s21::list<int> cl_int{1, 2};
  const std::list<int> std_cl_int{1, 2};
};

TEST(ListTestPlus, init_empty) {
  s21::list<int> my_emp{};
  std::list<int> std_emp{};
  EXPECT_TRUE(my_emp.size() == std_emp.size());
  EXPECT_TRUE(my_emp.max_size() == std_emp.max_size());
  EXPECT_TRUE(my_emp.empty() == std_emp.empty());
}

TEST(ListTestPlus, init_size) {
  s21::list<int> my_size(5);
  std::list<int> std_size(5);
  EXPECT_TRUE(my_size.size() == std_size.size());
  EXPECT_TRUE(my_size.max_size() == std_size.max_size());
  EXPECT_TRUE(my_size.empty() == std_size.empty());
}

TEST_F(ListTest, init_list_normal) {
  EXPECT_TRUE(l_int.size() == std_l_int.size());
  EXPECT_TRUE(l_int.front() == std_l_int.front());
  EXPECT_TRUE(l_int.back() == std_l_int.back());
  EXPECT_TRUE(*l_int.begin() == *std_l_int.begin());
  EXPECT_TRUE(*(--l_int.end()) == *(--std_l_int.end()));

  EXPECT_TRUE(l_str.size() == std_l_str.size());
  EXPECT_TRUE(l_str.front() == std_l_str.front());
  EXPECT_TRUE(l_str.back() == std_l_str.back());
  EXPECT_TRUE(l_str.empty() == std_l_str.empty());

  EXPECT_TRUE(l_char.size() == std_l_char.size());
  EXPECT_TRUE(l_char.front() == std_l_char.front());
  EXPECT_TRUE(l_char.back() == std_l_char.back());

  EXPECT_TRUE(cl_int.size() == std_cl_int.size());
  EXPECT_TRUE(cl_int.front() == std_cl_int.front());
  EXPECT_TRUE(cl_int.back() == std_cl_int.back());
  EXPECT_TRUE(*cl_int.begin() == *std_cl_int.begin());
  EXPECT_TRUE(*(--cl_int.end()) == *(--std_cl_int.end()));
  EXPECT_TRUE(cl_int.begin() == cl_int.begin());
}

TEST_F(ListTest, copy_init) {
  s21::list<int> copy_int(l_int);
  EXPECT_TRUE(l_int.size() == copy_int.size());
  EXPECT_TRUE(l_int.front() == copy_int.front());
  EXPECT_TRUE(l_int.back() == copy_int.back());
  EXPECT_TRUE(*l_int.begin() == *copy_int.begin());
  EXPECT_TRUE(*(--l_int.end()) == *(--copy_int.end()));
  s21::list<std::string> copy_str(l_str);
  EXPECT_TRUE(l_str.size() == copy_str.size());
  EXPECT_TRUE(l_str.front() == copy_str.front());
  EXPECT_TRUE(l_str.back() == copy_str.back());
  EXPECT_TRUE(l_str.empty() == copy_str.empty());
  EXPECT_TRUE(*l_str.begin() == *copy_str.begin());
  EXPECT_TRUE(*(--l_str.end()) == *(--copy_str.end()));
}

TEST_F(ListTest, move_init) {
  s21::list<int> copy_int(l_int);
  s21::list<int> move_int(std::move(l_int));
  EXPECT_TRUE(move_int.size() == copy_int.size());
  EXPECT_TRUE(move_int.front() == copy_int.front());
  EXPECT_TRUE(move_int.back() == copy_int.back());
  EXPECT_TRUE(*move_int.begin() == *copy_int.begin());
  EXPECT_TRUE(*(--move_int.end()) == *(--copy_int.end()));
  s21::list<std::string> copy_str(l_str);
  s21::list<std::string> move_str(std::move(l_str));
  EXPECT_TRUE(move_str.size() == copy_str.size());
  EXPECT_TRUE(move_str.front() == copy_str.front());
  EXPECT_TRUE(move_str.back() == copy_str.back());
  EXPECT_TRUE(move_str.empty() == copy_str.empty());
  EXPECT_TRUE(*move_str.begin() == *copy_str.begin());
  EXPECT_TRUE(*(--move_str.end()) == *(--copy_str.end()));
}

TEST_F(ListTest, copy_asign) {
  s21::list<int> copy_int;
  copy_int = l_int;
  EXPECT_TRUE(l_int.size() == copy_int.size());
  EXPECT_TRUE(l_int.front() == copy_int.front());
  EXPECT_TRUE(l_int.back() == copy_int.back());
  EXPECT_TRUE(*l_int.begin() == *copy_int.begin());
  EXPECT_TRUE(*(--l_int.end()) == *(--copy_int.end()));
  s21::list<std::string> copy_str;
  copy_str = l_str;
  EXPECT_TRUE(l_str.size() == copy_str.size());
  EXPECT_TRUE(l_str.front() == copy_str.front());
  EXPECT_TRUE(l_str.back() == copy_str.back());
  EXPECT_TRUE(l_str.empty() == copy_str.empty());
  EXPECT_TRUE(*l_str.begin() == *copy_str.begin());
  EXPECT_TRUE(*(--l_str.end()) == *(--copy_str.end()));
}

TEST_F(ListTest, move_asign) {
  s21::list<int> copy_int(l_int);
  s21::list<int> move_int{2222, 22, 2};
  move_int = std::move(l_int);
  EXPECT_TRUE(move_int.size() == copy_int.size());
  EXPECT_TRUE(move_int.front() == copy_int.front());
  EXPECT_TRUE(move_int.back() == copy_int.back());
  EXPECT_TRUE(*move_int.begin() == *copy_int.begin());
  EXPECT_TRUE(*(--move_int.end()) == *(--copy_int.end()));
  s21::list<std::string> copy_str(l_str);
  s21::list<std::string> move_str;
  move_str = std::move(l_str);
  EXPECT_TRUE(move_str.size() == copy_str.size());
  EXPECT_TRUE(move_str.front() == copy_str.front());
  EXPECT_TRUE(move_str.back() == copy_str.back());
  EXPECT_TRUE(move_str.empty() == copy_str.empty());
  EXPECT_TRUE(*move_str.begin() == *copy_str.begin());
  EXPECT_TRUE(*(--move_str.end()) == *(--copy_str.end()));
}

TEST_F(ListTest, fn_clear) {
  l_int.clear();
  std_l_int.clear();
  EXPECT_TRUE(l_int.size() == std_l_int.size());
  l_str.clear();
  std_l_str.clear();
  EXPECT_TRUE(l_str.size() == std_l_str.size());
  l_char.clear();
  std_l_char.clear();
  EXPECT_TRUE(l_char.size() == std_l_char.size());
}

TEST_F(ListTest, fn_pop) {
  l_int.pop_front();
  std_l_int.pop_front();
  l_int.pop_front();
  std_l_int.pop_front();
  EXPECT_TRUE(l_int.size() == std_l_int.size());
  EXPECT_TRUE(l_int.front() == std_l_int.front());
  EXPECT_TRUE(l_int.back() == std_l_int.back());
  EXPECT_TRUE(*l_int.begin() == *std_l_int.begin());
  EXPECT_TRUE(*(--l_int.end()) == *(--std_l_int.end()));
  l_str.pop_front();
  std_l_str.pop_front();
  l_str.pop_back();
  std_l_str.pop_back();
  EXPECT_TRUE(l_str.size() == std_l_str.size());
  EXPECT_TRUE(l_str.front() == std_l_str.front());
  EXPECT_TRUE(l_str.back() == std_l_str.back());
  EXPECT_TRUE(*l_str.begin() == *std_l_str.begin());
  EXPECT_TRUE(*(--l_str.end()) == *(--std_l_str.end()));
  l_char.pop_front();
  std_l_char.pop_front();
  l_char.pop_front();
  std_l_char.pop_front();
  EXPECT_TRUE(l_char.size() == std_l_char.size());
  EXPECT_TRUE(l_char.front() == std_l_char.front());
  EXPECT_TRUE(l_char.back() == std_l_char.back());
  EXPECT_TRUE(*l_char.begin() == *std_l_char.begin());
  EXPECT_TRUE(*(--l_char.end()) == *(--std_l_char.end()));
}

TEST_F(ListTest, fn_erase) {
  l_int.erase(++l_int.begin());
  std_l_int.erase(++std_l_int.begin());
  EXPECT_TRUE(l_int.size() == std_l_int.size());
  EXPECT_TRUE(l_int.front() == std_l_int.front());
  l_int.pop_front();
  std_l_int.pop_front();
  EXPECT_TRUE(l_int.size() == std_l_int.size());
  EXPECT_TRUE(l_int.front() == std_l_int.front());
  EXPECT_TRUE(l_int.back() == std_l_int.back());
  EXPECT_TRUE(*l_int.begin() == *std_l_int.begin());
  EXPECT_TRUE(*(--l_int.end()) == *(--std_l_int.end()));
}

TEST_F(ListTest, fn_push) {
  l_int.push_front(15);
  std_l_int.push_front(15);
  EXPECT_TRUE(l_int.size() == std_l_int.size());
  EXPECT_TRUE(l_int.front() == std_l_int.front());
  EXPECT_TRUE(l_int.back() == std_l_int.back());
  EXPECT_TRUE(*l_int.begin() == *std_l_int.begin());
  EXPECT_TRUE(*(--l_int.end()) == *(--std_l_int.end()));
}

TEST_F(ListTest, fn_splice) {
  s21::list<int> one{1, 2, 3};
  std::list<int> std_one{1, 3, 3};
  l_int.splice(l_int.begin(), one);
  std_l_int.splice(std_l_int.begin(), std_one);
  EXPECT_TRUE(l_int.size() == std_l_int.size());
  EXPECT_TRUE(l_int.front() == std_l_int.front());
  EXPECT_TRUE(l_int.back() == std_l_int.back());
  EXPECT_TRUE(*l_int.begin() == *std_l_int.begin());
  EXPECT_TRUE(*(--l_int.end()) == *(--std_l_int.end()));
}

TEST_F(ListTest, splice2) {
  s21::list<int> one{1, 2, 3};
  std::list<int> std_one{1, 3, 3};
  l_int.splice(++l_int.begin(), one);
  std_l_int.splice(++std_l_int.begin(), std_one);
  EXPECT_TRUE(l_int.size() == std_l_int.size());
  EXPECT_TRUE(l_int.front() == std_l_int.front());
  EXPECT_TRUE(l_int.back() == std_l_int.back());
  EXPECT_TRUE(*l_int.begin() == *std_l_int.begin());
  EXPECT_TRUE(*(--l_int.end()) == *(--std_l_int.end()));
}

TEST(ListTestPlus, fn_unique) {
  s21::list<int> l_int{1, 2, 3, 3, 3};
  std::list<int> std_l_int{1, 2, 3, 3, 3};
  l_int.unique();
  std_l_int.unique();
  EXPECT_TRUE(l_int.size() == std_l_int.size());
  EXPECT_TRUE(l_int.front() == std_l_int.front());
  EXPECT_TRUE(l_int.back() == std_l_int.back());
  EXPECT_TRUE(*l_int.begin() == *std_l_int.begin());
  EXPECT_TRUE(*(--l_int.end()) == *(--std_l_int.end()));
}

TEST(ListTestPlus, fn_unique2) {
  s21::list<int> l_int{1, 1, 1, 2, 3, 3, 3};
  std::list<int> std_l_int{1, 1, 1, 2, 3, 3, 3};
  l_int.unique();
  std_l_int.unique();
  EXPECT_TRUE(l_int.size() == std_l_int.size());
  EXPECT_TRUE(l_int.front() == std_l_int.front());
  EXPECT_TRUE(l_int.back() == std_l_int.back());
  EXPECT_TRUE(*l_int.begin() == *std_l_int.begin());
  EXPECT_TRUE(*(--l_int.end()) == *(--std_l_int.end()));
}

TEST(ListTestPlus, fn_unique3) {
  s21::list<int> l_int{1, 1, 1};
  std::list<int> std_l_int{1, 1, 1};
  l_int.unique();
  std_l_int.unique();
  EXPECT_TRUE(l_int.size() == std_l_int.size());
  EXPECT_TRUE(l_int.front() == std_l_int.front());
  EXPECT_TRUE(l_int.back() == std_l_int.back());
  EXPECT_TRUE(*l_int.begin() == *std_l_int.begin());
  EXPECT_TRUE(*(--l_int.end()) == *(--std_l_int.end()));
}

TEST(ListTestPlus, fn_unique4) {
  s21::list<int> l_int{};
  std::list<int> std_l_int{};
  l_int.unique();
  std_l_int.unique();
  EXPECT_TRUE(l_int.size() == std_l_int.size());
}

TEST(ListTestPlus, fn_merge) {
  s21::list<int> l_int{1, 5, 6};
  std::list<int> std_l_int{1, 5, 6};
  s21::list<int> l_int_two{2};
  std::list<int> std_l_int_two{2};
  l_int.merge(l_int_two);
  std_l_int.merge(std_l_int_two);
  EXPECT_TRUE(l_int.size() == std_l_int.size());
  EXPECT_TRUE(l_int.front() == std_l_int.front());
  EXPECT_TRUE(l_int.back() == std_l_int.back());
  EXPECT_TRUE(*l_int.begin() == *std_l_int.begin());
  EXPECT_TRUE(*(--l_int.end()) == *(--std_l_int.end()));
}

TEST(ListTestPlus, fn_merge2) {
  s21::list<int> l_int{1, 5, 6};
  std::list<int> std_l_int{1, 5, 6};
  s21::list<int> l_int_two{2, 3, 5};
  std::list<int> std_l_int_two{2, 3, 5};
  l_int.merge(l_int_two);
  std_l_int.merge(std_l_int_two);
  EXPECT_TRUE(l_int.size() == std_l_int.size());
  EXPECT_TRUE(l_int.back() == std_l_int.back());
  EXPECT_TRUE(*l_int.begin() == *std_l_int.begin());
  EXPECT_TRUE(*(--l_int.end()) == *(--std_l_int.end()));
  auto my_it = l_int.begin();
  auto std_it = std_l_int.begin();
  for (; std_it != std_l_int.end(); ++std_it, ++my_it) {
    EXPECT_TRUE(*my_it == *std_it);
  }
}

TEST(ListTestPlus, fn_merge3) {
  s21::list<int> l_int{1, 5, 6};
  std::list<int> std_l_int{1, 5, 6};
  s21::list<int> l_int_two{2, 3, 5, 15};
  std::list<int> std_l_int_two{2, 3, 5, 15};
  l_int.merge(l_int_two);
  std_l_int.merge(std_l_int_two);
  EXPECT_TRUE(l_int.size() == std_l_int.size());
  EXPECT_TRUE(l_int.back() == std_l_int.back());
  EXPECT_TRUE(*l_int.begin() == *std_l_int.begin());
  EXPECT_TRUE(*(--l_int.end()) == *(--std_l_int.end()));
  auto my_it = l_int.begin();
  auto std_it = std_l_int.begin();
  for (; std_it != std_l_int.end(); ++std_it, ++my_it) {
    EXPECT_TRUE(*my_it == *std_it);
  }
}

TEST(ListTestPlus, fn_merge4) {
  s21::list<int> l_int{};
  std::list<int> std_l_int{};
  s21::list<int> l_int_two{2, 3, 5, 15, 28};
  std::list<int> std_l_int_two{2, 3, 5, 15, 28};
  l_int.merge(l_int_two);
  std_l_int.merge(std_l_int_two);
  EXPECT_TRUE(l_int.size() == std_l_int.size());
  EXPECT_TRUE(l_int.back() == std_l_int.back());
  EXPECT_TRUE(*l_int.begin() == *std_l_int.begin());
  EXPECT_TRUE(*(--l_int.end()) == *(--std_l_int.end()));
  auto my_it = l_int.begin();
  auto std_it = std_l_int.begin();
  for (; std_it != std_l_int.end(); ++std_it, ++my_it) {
    EXPECT_TRUE(*my_it == *std_it);
  }
}

TEST_F(ListTest, reverce) {
  l_int.reverse();
  std_l_int.reverse();
  EXPECT_TRUE(l_int.size() == std_l_int.size());
  EXPECT_TRUE(l_int.front() == std_l_int.front());
  EXPECT_TRUE(l_int.back() == std_l_int.back());
  EXPECT_TRUE(*l_int.begin() == *std_l_int.begin());
  EXPECT_TRUE(*(--l_int.end()) == *(--std_l_int.end()));
}

TEST(ListTestPlus, fn_sort1) {
  s21::list<int> l_int{1, 2, 4, 3, 5, 6, 7};
  std::list<int> std_l_int{1, 2, 4, 3, 5, 6, 7};
  l_int.sort();
  std_l_int.sort();
  EXPECT_TRUE(l_int.size() == std_l_int.size());
  EXPECT_TRUE(l_int.back() == std_l_int.back());
  EXPECT_TRUE(*l_int.begin() == *std_l_int.begin());
  EXPECT_TRUE(*(--l_int.end()) == *(--std_l_int.end()));
  auto my_it = l_int.begin();
  auto std_it = std_l_int.begin();
  for (; std_it != std_l_int.end(); ++std_it, ++my_it) {
    EXPECT_TRUE(*my_it == *std_it);
  }
}

TEST(ListTestPlus, fn_sort2) {
  s21::list<int> l_int{1, 3, 6, 5};
  std::list<int> std_l_int{1, 3, 6, 5};
  l_int.sort();
  std_l_int.sort();
  EXPECT_TRUE(l_int.size() == std_l_int.size());
  EXPECT_TRUE(l_int.back() == std_l_int.back());
  EXPECT_TRUE(*l_int.begin() == *std_l_int.begin());
  EXPECT_TRUE(*(--l_int.end()) == *(--std_l_int.end()));
  auto my_it = l_int.begin();
  auto std_it = std_l_int.begin();
  for (; std_it != std_l_int.end(); ++std_it, ++my_it) {
    EXPECT_TRUE(*my_it == *std_it);
  }
}

TEST(ListTestPlus, fn_sort3) {
  s21::list<int> l_int{2, 3, 1, 6, 5};
  std::list<int> std_l_int{2, 3, 1, 6, 5};
  l_int.sort();
  std_l_int.sort();
  EXPECT_TRUE(l_int.size() == std_l_int.size());
  EXPECT_TRUE(l_int.back() == std_l_int.back());
  EXPECT_TRUE(*l_int.begin() == *std_l_int.begin());
  EXPECT_TRUE(*(--l_int.end()) == *(--std_l_int.end()));
  auto my_it = l_int.begin();
  auto std_it = std_l_int.begin();
  for (; std_it != std_l_int.end(); ++std_it, ++my_it) {
    EXPECT_TRUE(*my_it == *std_it);
  }
}

TEST(ListTestPlus, emplace) {
  s21::list<int> l_int{2, 3, 1, 6, 5};
  l_int.emplace(++l_int.begin(), 45, 23, 16);
  EXPECT_TRUE(l_int.front() == 2);
  l_int.pop_front();
  EXPECT_TRUE(l_int.front() == 45);
  l_int.pop_front();
  EXPECT_TRUE(l_int.front() == 23);
  l_int.pop_front();
  EXPECT_TRUE(l_int.front() == 16);
  l_int.pop_front();
  EXPECT_TRUE(l_int.front() == 3);
}

TEST(ListTestPlus, emplace2) {
  s21::list<int> l_int{2, 3, 1, 6, 5};
  l_int.emplace_front(45, 23, 16);
  EXPECT_TRUE(l_int.front() == 45);
  l_int.pop_front();
  EXPECT_TRUE(l_int.front() == 23);
  l_int.pop_front();
  EXPECT_TRUE(l_int.front() == 16);
  l_int.pop_front();
  EXPECT_TRUE(l_int.front() == 2);
}

TEST(ListTestPlus, emplace3) {
  s21::list<int> l_int{2, 3, 1, 6, 5};
  l_int.emplace_back(45, 23, 16);
  EXPECT_TRUE(l_int.back() == 16);
  l_int.pop_back();
  EXPECT_TRUE(l_int.back() == 23);
  l_int.pop_back();
  EXPECT_TRUE(l_int.back() == 45);
  l_int.pop_back();
  EXPECT_TRUE(l_int.back() == 5);
}

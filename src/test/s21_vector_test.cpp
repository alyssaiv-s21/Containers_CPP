#include "../s21_vector.hpp"

#include <vector>

class VectorTest : public ::testing::Test {
 protected:
  s21::vector<int> v_int{1, 2, 3, 4, 5, 6, 7};
  std::vector<int> std_v_int{1, 2, 3, 4, 5, 6, 7};
  s21::vector<std::string> v_str{"standard", "template", "library"};
  std::vector<std::string> std_v_str{"standard", "template", "library"};
  s21::vector<char> v_char{'a', 'b', 'c', 'd'};
  std::vector<char> std_v_char{'a', 'b', 'c', 'd'};
  const s21::vector<int> cv_int{1, 2};
  const std::vector<int> std_cv_int{1, 2};
};

TEST_F(VectorTest, init_list_normal) {
  for (size_t i = 0; i < 7; ++i) {
    EXPECT_TRUE(v_int[i] == std_v_int[i]);
  };
  for (size_t i = 0; i < 3; ++i) {
    EXPECT_TRUE(v_str[i] == std_v_str[i]);
  };
  for (size_t i = 0; i < 4; ++i) {
    EXPECT_TRUE(v_char[i] == std_v_char[i]);
  };
  for (size_t i = 0; i < 2; ++i) {
    EXPECT_TRUE(cv_int[i] == std_cv_int[i]);
  };
}

TEST(VectorTestPlus, empty_vector) {
  std::vector<int> std_emp;
  s21::vector<int> my_emp;
  EXPECT_TRUE(my_emp.size() == std_emp.size());
  EXPECT_TRUE(my_emp.capacity() == std_emp.capacity());
  EXPECT_TRUE(my_emp.data() == std_emp.data());
}

TEST(VectorTestPlus, null_vector) {
  std::vector<int> std_null(0);
  s21::vector<int> my_null(0);
  EXPECT_TRUE(my_null.size() == std_null.size());
  EXPECT_TRUE(my_null.capacity() == std_null.capacity());
  EXPECT_TRUE(my_null.data() == std_null.data());
}

TEST(VectorTestPlus, size_vector) {
  std::vector<int> std_size(7);
  s21::vector<int> my_size(7);
  for (size_t i = 0; i < 7; ++i) {
    EXPECT_TRUE(std_size[i] == my_size[i]);
  };
  std::vector<std::string> std_size1(7);
  s21::vector<std::string> my_size1(7);
  for (size_t i = 0; i < 7; ++i) {
    EXPECT_TRUE(std_size1[i] == my_size1[i]);
  };
}

TEST_F(VectorTest, copy_const) {
  s21::vector<int> copy_v_int(v_int);
  for (size_t i = 0; i < 7; ++i) {
    EXPECT_TRUE(v_int[i] == copy_v_int[i]);
  };
  s21::vector<std::string> copy_v_str(v_str);
  for (size_t i = 0; i < 3; ++i) {
    EXPECT_TRUE(v_str[i] == copy_v_str[i]);
  };
  s21::vector<char> copy_v_char(v_char);
  for (size_t i = 0; i < 4; ++i) {
    EXPECT_TRUE(v_char[i] == copy_v_char[i]);
  };
  const s21::vector<int> copy_cv_int(cv_int);
  for (size_t i = 0; i < 2; ++i) {
    EXPECT_TRUE(cv_int[i] == copy_cv_int[i]);
  };
}

TEST_F(VectorTest, move_const) {
  s21::vector<int> move_v_int(std::move(v_int));
  for (size_t i = 0; i < 7; ++i) {
    EXPECT_TRUE(move_v_int[i] == std_v_int[i]);
  };
  s21::vector<std::string> move_v_str(std::move(v_str));
  for (size_t i = 0; i < 3; ++i) {
    EXPECT_TRUE(move_v_str[i] == std_v_str[i]);
  };
  s21::vector<char> move_v_char(std::move(v_char));
  for (size_t i = 0; i < 4; ++i) {
    EXPECT_TRUE(move_v_char[i] == std_v_char[i]);
  };
  const s21::vector<int> move_cv_int(std::move(cv_int));
  for (size_t i = 0; i < 2; ++i) {
    EXPECT_TRUE(move_cv_int[i] == std_cv_int[i]);
  };
}

TEST_F(VectorTest, copy_assign) {
  s21::vector<int> copy_v_int{5, 5, 5};
  copy_v_int = v_int;
  for (size_t i = 0; i < 7; ++i) {
    EXPECT_TRUE(v_int[i] == copy_v_int[i]);
  };
  s21::vector<std::string> copy_v_str{"hello"};
  copy_v_str = v_str;
  for (size_t i = 0; i < 3; ++i) {
    EXPECT_TRUE(v_str[i] == copy_v_str[i]);
  };
  s21::vector<char> copy_v_char = v_char;
  for (size_t i = 0; i < 4; ++i) {
    EXPECT_TRUE(v_char[i] == copy_v_char[i]);
  };
  const s21::vector<int> copy_cv_int = cv_int;
  for (size_t i = 0; i < 2; ++i) {
    EXPECT_TRUE(cv_int[i] == copy_cv_int[i]);
  };
}

TEST_F(VectorTest, move_assign) {
  s21::vector<int> move_v_int = std::move(v_int);
  for (size_t i = 0; i < 7; ++i) {
    EXPECT_TRUE(move_v_int[i] == std_v_int[i]);
  };
  s21::vector<std::string> move_v_str = std::move(v_str);
  for (size_t i = 0; i < 3; ++i) {
    EXPECT_TRUE(move_v_str[i] == std_v_str[i]);
  };
  s21::vector<char> move_v_char{'t', 'y', 't'};
  move_v_char = std::move(v_char);
  for (size_t i = 0; i < 4; ++i) {
    EXPECT_TRUE(move_v_char[i] == std_v_char[i]);
  };
  const s21::vector<int> move_cv_int = std::move(cv_int);
  for (size_t i = 0; i < 2; ++i) {
    EXPECT_TRUE(move_cv_int[i] == std_cv_int[i]);
  };
}

TEST_F(VectorTest, operator_index) {
  EXPECT_TRUE(v_int[4] == std_v_int[4]);
  EXPECT_TRUE(v_str[0] == std_v_str[0]);
  EXPECT_TRUE(v_char[3] == std_v_char[3]);
  EXPECT_TRUE(cv_int[1] == std_cv_int[1]);
}

TEST_F(VectorTest, operator_at) {
  EXPECT_TRUE(v_int.at(4) == std_v_int.at(4));
  EXPECT_TRUE(v_str.at(0) == std_v_str.at(0));
  EXPECT_TRUE(v_char.at(3) == std_v_char.at(3));
  EXPECT_TRUE(cv_int.at(1) == std_cv_int.at(1));
}

TEST_F(VectorTest, operator_at_throw) {
  EXPECT_ANY_THROW(v_int.at(12));
  EXPECT_ANY_THROW(cv_int.at(12));
}

TEST_F(VectorTest, operator_front) {
  EXPECT_TRUE(v_int.front() == std_v_int.front());
  EXPECT_TRUE(v_str.front() == std_v_str.front());
  EXPECT_TRUE(v_char.front() == std_v_char.front());
  EXPECT_TRUE(cv_int.front() == std_cv_int.front());
}

TEST_F(VectorTest, operator_back) {
  EXPECT_TRUE(v_int.back() == std_v_int.back());
  EXPECT_TRUE(v_str.back() == std_v_str.back());
  EXPECT_TRUE(v_char.back() == std_v_char.back());
  EXPECT_TRUE(cv_int.back() == std_cv_int.back());
}

TEST_F(VectorTest, it_data) {
  EXPECT_TRUE(*(v_int.data()) == *(std_v_int.data()));
  EXPECT_TRUE(*(v_str.data()) == *(std_v_str.data()));
  EXPECT_TRUE(*(v_char.data()) == *(std_v_char.data()));
  EXPECT_TRUE(*(cv_int.data()) == *(std_cv_int.data()));
}

TEST_F(VectorTest, it_begin) {
  EXPECT_TRUE(*(v_int.begin()) == *(std_v_int.begin()));
  EXPECT_TRUE(*(v_str.begin()) == *(std_v_str.begin()));
  EXPECT_TRUE(*(v_char.begin()) == *(std_v_char.begin()));
  EXPECT_TRUE(*(cv_int.begin()) == *(std_cv_int.begin()));
}

TEST_F(VectorTest, it_end) {
  EXPECT_TRUE(*(v_int.end() - 1) == *(std_v_int.end() - 1));
  EXPECT_TRUE(*(v_str.end() - 1) == *(std_v_str.end() - 1));
  EXPECT_TRUE(*(v_char.end() - 1) == *(std_v_char.end() - 1));
  EXPECT_TRUE(*(cv_int.end() - 1) == *(std_cv_int.end() - 1));
}

TEST_F(VectorTest, fn_empty) {
  EXPECT_TRUE(v_int.empty() == std_v_int.empty());
  EXPECT_TRUE(v_str.empty() == std_v_str.empty());
  EXPECT_TRUE(v_char.empty() == std_v_char.empty());
  EXPECT_TRUE(cv_int.empty() == std_cv_int.empty());
}

TEST(VectorTestPlus, fn_empty) {
  std::vector<int> std_emp;
  s21::vector<int> my_emp;
  EXPECT_TRUE(my_emp.empty() == std_emp.empty());
  const std::vector<char> std_emp1(0);
  const s21::vector<char> my_emp1(0);
  EXPECT_TRUE(my_emp1.empty() == std_emp1.empty());
}

TEST_F(VectorTest, fn_max_size) {
  EXPECT_TRUE(v_int.max_size() == std_v_int.max_size());
  EXPECT_TRUE(v_str.max_size() == std_v_str.max_size());
  EXPECT_TRUE(v_char.max_size() == std_v_char.max_size());
  EXPECT_TRUE(cv_int.max_size() == std_cv_int.max_size());
}

TEST_F(VectorTest, fn_reserve) {
  v_int.reserve(20);
  std_v_int.reserve(20);
  EXPECT_TRUE(v_int.size() == std_v_int.size());
  EXPECT_TRUE(v_int.capacity() == std_v_int.capacity());
  v_str.reserve(1);
  std_v_str.reserve(1);
  EXPECT_TRUE(v_str.size() == std_v_str.size());
  EXPECT_TRUE(v_str.capacity() == std_v_str.capacity());
  v_str.reserve(30);
  std_v_str.reserve(30);
  EXPECT_TRUE(v_str.size() == std_v_str.size());
  EXPECT_TRUE(v_str.capacity() == std_v_str.capacity());
  v_char.reserve(4);
  std_v_char.reserve(4);
  EXPECT_TRUE(v_char.size() == std_v_char.size());
  EXPECT_TRUE(v_char.capacity() == std_v_char.capacity());
}

TEST_F(VectorTest, fn_shrink_to_fit) {
  v_int.reserve(20);
  std_v_int.reserve(20);
  v_int.shrink_to_fit();
  std_v_int.shrink_to_fit();
  EXPECT_TRUE(v_int.size() == std_v_int.size());
  EXPECT_TRUE(v_int.capacity() == std_v_int.capacity());
  v_str.shrink_to_fit();
  std_v_str.shrink_to_fit();
  EXPECT_TRUE(v_str.size() == std_v_str.size());
  EXPECT_TRUE(v_str.capacity() == std_v_str.capacity());
  v_char.push_back('e');
  std_v_char.push_back('e');
  v_char.shrink_to_fit();
  std_v_char.shrink_to_fit();
  EXPECT_TRUE(v_char.size() == std_v_char.size());
  EXPECT_TRUE(v_char.capacity() == std_v_char.capacity());
}

TEST_F(VectorTest, fn_clear) {
  v_int.clear();
  std_v_int.clear();
  EXPECT_TRUE(v_int.size() == std_v_int.size());
  v_str.clear();
  std_v_str.clear();
  EXPECT_TRUE(v_str.size() == std_v_str.size());
  v_char.clear();
  std_v_char.clear();
  EXPECT_TRUE(v_char.size() == std_v_char.size());
}

TEST_F(VectorTest, fn_insert) {
  auto std_it = std_v_int.begin() + 1;
  auto my_it = v_int.begin() + 1;
  std_it = std_v_int.insert(std_it, 14);
  my_it = v_int.insert(my_it, 14);
  EXPECT_TRUE(v_int.at(1) == std_v_int.at(1));
  EXPECT_TRUE(v_int.at(0) == std_v_int.at(0));
  EXPECT_TRUE(v_int.at(4) == std_v_int.at(4));
  EXPECT_TRUE(v_int.size() == std_v_int.size());
  EXPECT_TRUE(v_int.capacity() == std_v_int.capacity());
  EXPECT_TRUE(*(my_it) == *(std_it));
}

TEST_F(VectorTest, fn_erase) {
  auto std_it = std_v_int.begin() + 1;
  auto my_it = v_int.begin() + 1;
  std_it = std_v_int.erase(std_it);
  my_it = v_int.erase(my_it);
  EXPECT_TRUE(v_int.at(1) == std_v_int.at(1));
  EXPECT_TRUE(v_int.at(0) == std_v_int.at(0));
  EXPECT_TRUE(v_int.at(4) == std_v_int.at(4));
  EXPECT_TRUE(v_int.size() == std_v_int.size());
  EXPECT_TRUE(v_int.capacity() == std_v_int.capacity());
  EXPECT_TRUE(*(my_it) == *(std_it));
}

TEST_F(VectorTest, fn_push_back) {
  std_v_int.push_back(22);
  v_int.push_back(22);
  EXPECT_TRUE(v_int.at(7) == std_v_int.at(7));
  EXPECT_TRUE(v_int.size() == std_v_int.size());
  EXPECT_TRUE(v_int.capacity() == std_v_int.capacity());
  std_v_int.push_back(42);
  v_int.push_back(42);
  EXPECT_TRUE(v_int.at(8) == std_v_int.at(8));
  EXPECT_TRUE(v_int.size() == std_v_int.size());
  EXPECT_TRUE(v_int.capacity() == std_v_int.capacity());
}

TEST_F(VectorTest, fn_pop_back) {
  std_v_int.pop_back();
  v_int.pop_back();
  EXPECT_TRUE(v_int.back() == std_v_int.back());
  EXPECT_TRUE(v_int.size() == std_v_int.size());
  EXPECT_TRUE(v_int.capacity() == std_v_int.capacity());
  std_v_int.pop_back();
  v_int.pop_back();
  EXPECT_TRUE(v_int.back() == std_v_int.back());
  EXPECT_TRUE(v_int.size() == std_v_int.size());
  EXPECT_TRUE(v_int.capacity() == std_v_int.capacity());
}

TEST_F(VectorTest, swap_fn) {
  std::vector<int> std_two{9, 8};
  s21::vector<int> my_two{9, 8};
  std_v_int.swap(std_two);
  v_int.swap(my_two);
  EXPECT_TRUE(v_int.size() == std_v_int.size());
  EXPECT_TRUE(v_int.capacity() == std_v_int.capacity());
  for (size_t i = 0; i < 2; ++i) {
    EXPECT_TRUE(v_int[i] == std_v_int[i]);
  };
  EXPECT_TRUE(my_two.size() == std_two.size());
  EXPECT_TRUE(my_two.capacity() == std_two.capacity());
  for (size_t i = 0; i < 2; ++i) {
    EXPECT_TRUE(my_two[i] == std_two[i]);
  };
}

TEST_F(VectorTest, bonus_test) {
  v_int.emplace(v_int.begin() + 2, 34, 25, 12);
  EXPECT_TRUE(v_int[2] == 34);
  EXPECT_TRUE(v_int[3] == 25);
  EXPECT_TRUE(v_int[4] == 12);
}

TEST_F(VectorTest, bonus2) {
  v_int.emplace_back(101, 102);
  EXPECT_TRUE(v_int[7] == 101);
  EXPECT_TRUE(v_int[8] == 102);
}

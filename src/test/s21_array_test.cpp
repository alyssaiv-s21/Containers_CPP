
#include "../s21_array.hpp"

#include <array>

class ArrayTest : public ::testing::Test {
 protected:
  s21::array<int, 7> ar_int{1, 2, 3, 4, 5, 6};
  std::array<int, 7> std_ar_int{1, 2, 3, 4, 5, 6};
  s21::array<std::string, 3> ar_str{"standard", "template", "library"};
  std::array<std::string, 3> std_ar_str{"standard", "template", "library"};
  s21::array<char, 4> ar_char{'a', 'b', 'c', 'd'};
  std::array<char, 4> std_ar_char{'a', 'b', 'c', 'd'};
  const s21::array<int, 2> car_int{1, 2};
  const std::array<int, 2> std_car_int{1, 2};
};

TEST_F(ArrayTest, init_list_normal) {
  for (size_t i = 0; i < 7; ++i) {
    EXPECT_TRUE(ar_int[i] == std_ar_int[i]);
  };
  for (size_t i = 0; i < 3; ++i) {
    EXPECT_TRUE(ar_str[i] == std_ar_str[i]);
  };
  for (size_t i = 0; i < 4; ++i) {
    EXPECT_TRUE(ar_char[i] == std_ar_char[i]);
  };
  for (size_t i = 0; i < 2; ++i) {
    EXPECT_TRUE(car_int[i] == std_car_int[i]);
  };
}

// // only without CFLAGS because ISO C++ forbids zero-size array
// TEST (Array_Test, init_list_empty) {
//     s21::array<char, 0> ar_ch();
//     s21::array<int, 0> ar_emp {};
//     std::array<int, 0> std_ar_emp {};
//     EXPECT_TRUE(ar_emp.size() == std_ar_emp.size());
//     EXPECT_TRUE(ar_emp.empty() == std_ar_emp.empty());
//     EXPECT_TRUE(ar_emp.begin() == ar_emp.end());
//     EXPECT_TRUE(ar_emp.data() == nullptr);
//     const s21::array<int, 0> car_emp {};
//     EXPECT_TRUE(car_emp.begin() == car_emp.end());
// }

TEST(ArrayTestThrow, init_list_throw) {
  EXPECT_ANY_THROW((s21::array<int, 7>{1, 2, 3, 4, 5, 6, 7, 8, 0}));
}

TEST_F(ArrayTest, copy_const) {
  s21::array<int, 7> copy_ar_int(ar_int);
  for (size_t i = 0; i < 7; ++i) {
    EXPECT_TRUE(ar_int[i] == copy_ar_int[i]);
  };
  s21::array<std::string, 3> copy_ar_str(ar_str);
  for (size_t i = 0; i < 3; ++i) {
    EXPECT_TRUE(ar_str[i] == copy_ar_str[i]);
  };
  s21::array<char, 4> copy_ar_char(ar_char);
  for (size_t i = 0; i < 4; ++i) {
    EXPECT_TRUE(ar_char[i] == copy_ar_char[i]);
  };
  const s21::array<int, 2> copy_car_int(car_int);
  for (size_t i = 0; i < 2; ++i) {
    EXPECT_TRUE(car_int[i] == copy_car_int[i]);
  };
}

TEST_F(ArrayTest, move_const) {
  s21::array<int, 7> move_ar_int(std::move(ar_int));
  for (size_t i = 0; i < 7; ++i) {
    EXPECT_TRUE(move_ar_int[i] == std_ar_int[i]);
  };
  s21::array<std::string, 3> move_ar_str(std::move(ar_str));
  for (size_t i = 0; i < 3; ++i) {
    EXPECT_TRUE(move_ar_str[i] == std_ar_str[i]);
  };
  s21::array<char, 4> move_ar_char(std::move(ar_char));
  for (size_t i = 0; i < 4; ++i) {
    EXPECT_TRUE(move_ar_char[i] == std_ar_char[i]);
  };
  const s21::array<int, 2> move_car_int(std::move(car_int));
  for (size_t i = 0; i < 2; ++i) {
    EXPECT_TRUE(move_car_int[i] == std_car_int[i]);
  };
}

TEST_F(ArrayTest, copy_assign) {
  s21::array<int, 7> copy_ar_int{5, 5, 5};
  copy_ar_int = ar_int;
  for (size_t i = 0; i < 7; ++i) {
    EXPECT_TRUE(ar_int[i] == copy_ar_int[i]);
  };
  s21::array<std::string, 3> copy_ar_str{"hello"};
  copy_ar_str = ar_str;
  for (size_t i = 0; i < 3; ++i) {
    EXPECT_TRUE(ar_str[i] == copy_ar_str[i]);
  };
  s21::array<char, 4> copy_ar_char = ar_char;
  for (size_t i = 0; i < 4; ++i) {
    EXPECT_TRUE(ar_char[i] == copy_ar_char[i]);
  };
  const s21::array<int, 2> copy_car_int = car_int;
  for (size_t i = 0; i < 2; ++i) {
    EXPECT_TRUE(car_int[i] == copy_car_int[i]);
  };
}

TEST_F(ArrayTest, move_assign) {
  s21::array<int, 7> move_ar_int = std::move(ar_int);
  for (size_t i = 0; i < 7; ++i) {
    EXPECT_TRUE(move_ar_int[i] == std_ar_int[i]);
  };
  s21::array<std::string, 3> move_ar_str = std::move(ar_str);
  for (size_t i = 0; i < 3; ++i) {
    EXPECT_TRUE(move_ar_str[i] == std_ar_str[i]);
  };
  s21::array<char, 4> move_ar_char{'t', 'y', 't'};
  move_ar_char = std::move(ar_char);
  for (size_t i = 0; i < 4; ++i) {
    EXPECT_TRUE(move_ar_char[i] == std_ar_char[i]);
  };
  const s21::array<int, 2> move_car_int = std::move(car_int);
  for (size_t i = 0; i < 2; ++i) {
    EXPECT_TRUE(move_car_int[i] == std_car_int[i]);
  };
}

TEST_F(ArrayTest, operator_index) {
  EXPECT_TRUE(ar_int[4] == std_ar_int[4]);
  EXPECT_TRUE(ar_str[0] == std_ar_str[0]);
  EXPECT_TRUE(ar_char[3] == std_ar_char[3]);
  EXPECT_TRUE(car_int[1] == std_car_int[1]);
}

TEST_F(ArrayTest, operator_at) {
  EXPECT_TRUE(ar_int.at(4) == std_ar_int.at(4));
  EXPECT_TRUE(ar_str.at(0) == std_ar_str.at(0));
  EXPECT_TRUE(ar_char.at(3) == std_ar_char.at(3));
}

TEST_F(ArrayTest, operator_at_const) {
  EXPECT_TRUE(car_int.at(0) == std_car_int.at(0));
  EXPECT_TRUE(car_int.at(1) == std_car_int.at(1));
}

TEST_F(ArrayTest, operator_at_const_throw) { EXPECT_ANY_THROW(car_int.at(12)); }

TEST_F(ArrayTest, operator_at_throw) { EXPECT_ANY_THROW(ar_int.at(12)); }

TEST_F(ArrayTest, operator_size) {
  EXPECT_TRUE(ar_int.size() == std_ar_int.size());
  EXPECT_TRUE(ar_str.size() == std_ar_str.size());
  EXPECT_TRUE(ar_char.size() == std_ar_char.size());
  EXPECT_TRUE(car_int.size() == std_car_int.size());
}

TEST_F(ArrayTest, operator_max_size) {
  EXPECT_TRUE(ar_int.max_size() == std_ar_int.max_size());
  EXPECT_TRUE(ar_str.max_size() == std_ar_str.max_size());
  EXPECT_TRUE(ar_char.max_size() == std_ar_char.max_size());
  EXPECT_TRUE(car_int.max_size() == std_car_int.max_size());
}

TEST_F(ArrayTest, fill_fn) {
  ar_int.fill(455);
  for (size_t i = 0; i < 7; ++i) {
    EXPECT_TRUE(ar_int[i] == 455);
  };
  ar_str.fill("my");
  for (size_t i = 0; i < 3; ++i) {
    EXPECT_TRUE(ar_str[i] == "my");
  };
  ar_char.fill('w');
  for (size_t i = 0; i < 4; ++i) {
    EXPECT_TRUE(ar_char[i] == 'w');
  };
}

TEST_F(ArrayTest, swap_fn) {
  s21::array<char, 4> sw_ar_char;
  sw_ar_char.swap(ar_char);
  for (size_t i = 0; i < 4; ++i) {
    EXPECT_TRUE(sw_ar_char[i] == std_ar_char[i]);
  };
  s21::array<int, 7> sw_ar_int;
  sw_ar_int.swap(ar_int);
  for (size_t i = 0; i < 7; ++i) {
    EXPECT_TRUE(sw_ar_int[i] == std_ar_int[i]);
  };
  s21::array<std::string, 3> sw_ar_str;
  sw_ar_str.swap(ar_str);
  for (size_t i = 0; i < 3; ++i) {
    EXPECT_TRUE(sw_ar_str[i] == std_ar_str[i]);
  };
}

TEST_F(ArrayTest, operator_empty) {
  EXPECT_TRUE(ar_int.empty() == std_ar_int.empty());
  EXPECT_TRUE(ar_str.empty() == std_ar_str.empty());
  EXPECT_TRUE(ar_char.empty() == std_ar_char.empty());
  EXPECT_TRUE(car_int.empty() == std_car_int.empty());
}

TEST_F(ArrayTest, it_begin) {
  EXPECT_TRUE(*(ar_int.begin()) == *(std_ar_int.begin()));
  EXPECT_TRUE(*(ar_str.begin()) == *(std_ar_str.begin()));
  EXPECT_TRUE(*(ar_char.begin()) == *(std_ar_char.begin()));
  EXPECT_TRUE(*(car_int.begin()) == *(std_car_int.begin()));
}

TEST_F(ArrayTest, it_end) {
  EXPECT_TRUE(*(ar_int.end() - 1) == *(std_ar_int.end() - 1));
  EXPECT_TRUE(*(ar_str.end() - 1) == *(std_ar_str.end() - 1));
  EXPECT_TRUE(*(ar_char.end() - 1) == *(std_ar_char.end() - 1));
  EXPECT_TRUE(*(car_int.end() - 1) == *(std_car_int.end() - 1));
}

TEST_F(ArrayTest, operator_front) {
  EXPECT_TRUE(ar_int.front() == std_ar_int.front());
  EXPECT_TRUE(ar_str.front() == std_ar_str.front());
  EXPECT_TRUE(ar_char.front() == std_ar_char.front());
}

TEST_F(ArrayTest, operator_back) {
  EXPECT_TRUE(ar_int.back() == std_ar_int.back());
  EXPECT_TRUE(ar_str.back() == std_ar_str.back());
  EXPECT_TRUE(ar_char.back() == std_ar_char.back());
}

TEST_F(ArrayTest, it_data) {
  EXPECT_TRUE(*(ar_int.data()) == *(std_ar_int.data()));
  EXPECT_TRUE(*(ar_str.data()) == *(std_ar_str.data()));
  EXPECT_TRUE(*(ar_char.data()) == *(std_ar_char.data()));
}
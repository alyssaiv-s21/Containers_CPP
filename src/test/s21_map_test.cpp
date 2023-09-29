#include "../s21_map.hpp"

#include <map>

class MapTest : public ::testing::Test {
 protected:
  s21::map<int, int> map_int{{5, 100},  {3, 101},  {14, 102}, {6, 103},
                             {78, 104}, {23, 105}, {65, 106}};
  std::map<int, int> std_map_int{{5, 100},  {3, 101},  {14, 102}, {6, 103},
                                 {78, 104}, {23, 105}, {65, 106}};
  s21::map<int, std::string> map_str{
      {2, "standard"}, {1, "template"}, {3, "library"}};
  std::map<int, std::string> std_map_str{
      {2, "standard"}, {1, "template"}, {3, "library"}};
  s21::map<char, int> map_char{
      {'c', 711}, {'b', 822}, {'w', 716}, {'d', 501}, {'a', 799}};
  std::map<char, int> std_map_char{
      {'c', 711}, {'b', 822}, {'w', 716}, {'d', 501}, {'a', 799}};
  const s21::map<int, int> cmap_int{{5, 100},  {5, 101},  {14, 102}, {6, 103},
                                    {78, 104}, {23, 105}, {65, 106}};
  const std::map<int, int> std_cmap_int{
      {5, 100}, {5, 101}, {14, 102}, {6, 103}, {78, 104}, {23, 105}, {65, 106}};
};

TEST_F(MapTest, init_list) {
  EXPECT_TRUE(map_int.size() == std_map_int.size());
  EXPECT_TRUE(map_int.empty() == std_map_int.empty());
  EXPECT_TRUE(map_int.at(5) == std_map_int.at(5));
  EXPECT_TRUE(map_int.at(78) == std_map_int.at(78));
  EXPECT_TRUE(map_int.at(65) == std_map_int.at(65));

  EXPECT_TRUE(map_str.size() == std_map_str.size());
  EXPECT_TRUE(map_str[1] == std_map_str[1]);
  EXPECT_TRUE(map_str[2] == std_map_str[2]);
  EXPECT_TRUE(map_str[3] == std_map_str[3]);

  EXPECT_TRUE(map_char.size() == std_map_char.size());
  auto char_iter = map_char.begin();
  auto std_char_iter = std_map_char.begin();
  for (size_t i = 0; i < map_char.size(); ++i) {
    EXPECT_TRUE((*char_iter).second == (*std_char_iter).second);
    ++char_iter;
    ++std_char_iter;
  }

  EXPECT_TRUE(cmap_int.size() == std_cmap_int.size());
  auto int_citer = cmap_int.begin();
  auto std_int_citer = std_cmap_int.begin();
  for (size_t i = 0; i < cmap_int.size(); ++i) {
    EXPECT_TRUE((*int_citer).second == (*std_int_citer).second);
    ++int_citer;
    ++std_int_citer;
  }
}

TEST(MapTestPlus, empty_init) {
  s21::map<int, char> map_int{};
  std::map<int, char> std_map_int{};
  EXPECT_TRUE(map_int.size() == std_map_int.size());
  EXPECT_TRUE(map_int.empty() == std_map_int.empty());
  ASSERT_FLOAT_EQ(map_int.max_size(), std_map_int.max_size());
}

TEST_F(MapTest, copy_constr) {
  s21::map<int, int> copy_int(map_int);
  std::map<int, int> copy_std_int(std_map_int);
  EXPECT_TRUE(copy_int.size() == copy_std_int.size());
  auto int_iter = copy_int.begin();
  auto std_int_iter = copy_std_int.begin();
  for (size_t i = 0; i < map_int.size(); ++i) {
    EXPECT_TRUE((*int_iter).second == (*std_int_iter).second);
    ++int_iter;
    ++std_int_iter;
  }
}

TEST_F(MapTest, move_constr) {
  s21::map<int, int> move_int(std::move(map_int));
  std::map<int, int> move_std_int(std::move(std_map_int));
  EXPECT_TRUE(move_int.size() == move_std_int.size());
  auto int_iter = move_int.begin();
  auto std_int_iter = move_std_int.begin();
  for (size_t i = 0; i < move_int.size(); ++i) {
    EXPECT_TRUE((*int_iter).second == (*std_int_iter).second);
    ++int_iter;
    ++std_int_iter;
  }
}

TEST_F(MapTest, at_throw) { EXPECT_ANY_THROW(map_int.at(1200)); }

TEST_F(MapTest, braces_throw) {
  map_int[1200];
  EXPECT_TRUE(map_int.at(1200) == 0);
}

TEST_F(MapTest, copy_asign) {
  s21::map<int, int> copy_int;
  copy_int = map_int;
  std::map<int, int> copy_std_int;
  copy_std_int = std_map_int;
  EXPECT_TRUE(copy_int.size() == copy_std_int.size());
  auto int_iter = --copy_int.end();
  auto std_int_iter = --copy_std_int.end();
  for (size_t i = map_int.size(); i > 0; --i) {
    EXPECT_TRUE((*int_iter).second == (*std_int_iter).second);
    --int_iter;
    --std_int_iter;
  }
}

TEST_F(MapTest, move_asign) {
  s21::map<int, int> move_int;
  move_int = std::move(map_int);
  std::map<int, int> move_std_int;
  move_std_int = std::move(std_map_int);
  EXPECT_TRUE(move_int.size() == move_std_int.size());
  auto int_iter = move_int.begin();
  auto std_int_iter = move_std_int.begin();
  for (size_t i = 0; i < move_int.size(); ++i) {
    EXPECT_TRUE((*int_iter).second == (*std_int_iter).second);
    ++int_iter;
    ++std_int_iter;
  }
}

TEST_F(MapTest, insert_copy) {
  map_int.insert(44, 12345);
  EXPECT_TRUE(map_int.at(44) == 12345);
  map_int.insert(3, 1515);
  EXPECT_TRUE(map_int.at(3) == 101);
}

TEST_F(MapTest, insert_copy2) {
  map_int.insert_or_assign(4, 1515);
  EXPECT_TRUE(map_int.at(4) == 1515);
  map_int.insert_or_assign(4, 2323);
  EXPECT_TRUE(map_int.at(4) == 2323);
}

TEST_F(MapTest, erase_test) {
  map_int.erase(++map_int.begin());
  std_map_int.erase(++std_map_int.begin());
  EXPECT_TRUE(map_int.size() == std_map_int.size());
  EXPECT_TRUE(map_int.empty() == std_map_int.empty());
  auto int_iter = map_int.begin();
  auto std_int_iter = std_map_int.begin();
  for (size_t i = 0; i < map_int.size(); ++i) {
    EXPECT_TRUE((*int_iter).second == (*std_int_iter).second);
    ++int_iter;
    ++std_int_iter;
  }

  map_str.erase(map_str.begin());
  std_map_str.erase(std_map_str.begin());
  EXPECT_TRUE(map_str.size() == std_map_str.size());
  auto str_iter = map_str.begin();
  auto std_str_iter = std_map_str.begin();
  for (size_t i = 0; i < map_str.size(); ++i) {
    EXPECT_TRUE((*str_iter).first == (*std_str_iter).first);
    ++str_iter;
    ++std_str_iter;
  }

  map_char.erase(--map_char.end());
  std_map_char.erase(--std_map_char.end());
  EXPECT_TRUE(map_char.size() == std_map_char.size());
  auto char_iter = map_char.begin();
  auto std_char_iter = std_map_char.begin();
  for (size_t i = 0; i < map_char.size(); ++i) {
    EXPECT_TRUE((*char_iter).second == (*std_char_iter).second);
    ++char_iter;
    ++std_char_iter;
  }
}

TEST_F(MapTest, erase_test2) {
  auto my_iter = map_int.end();
  map_int.erase(my_iter);
  EXPECT_TRUE(map_int.size() == std_map_int.size());
  EXPECT_TRUE(map_int.empty() == std_map_int.empty());
  auto int_iter = map_int.begin();
  auto std_int_iter = std_map_int.begin();
  for (size_t i = 0; i < map_int.size(); ++i) {
    EXPECT_TRUE((*int_iter).first == (*std_int_iter).first);
    ++int_iter;
    ++std_int_iter;
  }
}

TEST_F(MapTest, merge_test) {
  s21::map<char, int> map_char_two{
      {'e', 712}, {'f', 815}, {'g', 740}, {'a', 803}, {'d', 714}};
  std::map<char, int> std_map_char_two{
      {'e', 712}, {'f', 815}, {'g', 740}, {'a', 803}, {'d', 714}};
  map_char.merge(map_char_two);
  std_map_char.merge(std_map_char_two);
  EXPECT_TRUE(map_char.size() == std_map_char.size());
  EXPECT_TRUE(map_char_two.size() == std_map_char_two.size());
  EXPECT_TRUE(map_char.empty() == std_map_char.empty());
  auto char_iter = map_char.begin();
  auto std_char_iter = std_map_char.begin();
  for (size_t i = 0; i < map_char.size(); ++i) {
    EXPECT_TRUE((*char_iter).first == (*std_char_iter).first);
    ++char_iter;
    ++std_char_iter;
  }
}

TEST_F(MapTest, test_const_iter) {
  auto const_iter(cmap_int.end());
  EXPECT_TRUE((*(--const_iter)).first == 78);
  EXPECT_TRUE((*(--const_iter)).first == 65);
  EXPECT_TRUE((*(--const_iter)).first == 23);
  EXPECT_TRUE((*(--const_iter)).first == 14);
  auto copy_citer(const_iter);
  EXPECT_TRUE((*(--copy_citer)).first == 6);
  EXPECT_TRUE((*(--copy_citer)).first == 5);
}

TEST_F(MapTest, contains_test) {
  bool if_find = map_int.contains(14);
  EXPECT_TRUE(if_find == true);
  if_find = map_char.contains('n');
  EXPECT_TRUE(if_find == false);
}

TEST_F(MapTest, emplace2) {
  map_int.emplace(std::pair<int, int>(101, 13), std::pair<int, int>(13, 101));
  bool if_find = map_int.contains(101);
  EXPECT_TRUE(if_find == true);
  if_find = map_int.contains(13);
  EXPECT_TRUE(if_find == true);
}

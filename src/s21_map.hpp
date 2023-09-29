#ifndef CPP_S21_CONTAINERS_S21_MAP_HPP
#define CPP_S21_CONTAINERS_S21_MAP_HPP

#include "s21_tree.hpp"

namespace s21 {

template <class Key, class T>
struct map_compare {
  using value_type = std::pair<Key, T>;
  bool operator()(const value_type &x, const value_type &y) const {
    return x.first < y.first;
  }
};

template <class Key, class T>
class map : public tree<std::pair<Key, T>, map_compare<Key, T>> {
 public:
  using tree<std::pair<Key, T>, map_compare<Key, T>>::tree;
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<key_type, mapped_type>;
  using compare = map_compare<Key, T>;
  using node = typename map<Key, T>::treeNode;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = typename tree<value_type, compare>::treeIterator;
  using const_iterator = typename tree<value_type, compare>::treeConstIterator;
  using size_type = std::size_t;

  // element access
  T &at(const key_type &key) {
    auto *res = find_by_key(key);
    if (res == nullptr) {
      throw std::out_of_range("This key is not in the map");
    }
    return res->data_.second;
  }
  T &operator[](const Key &key) {
    try {
      at(key);
    } catch (...) {
      insert(key, mapped_type());
    }
    return at(key);

    // auto *res = find_by_key(key);
    // if (res == nullptr) {
    //   insert(key, mapped_type());
    // }
    // return res->data_.second;
  }

  // modifiers
  std::pair<iterator, bool> insert(const Key &key, const T &obj) {
    std::pair<Key, T> new_val(key, obj);
    return this->unique_insert(new_val);
  }
  std::pair<iterator, bool> insert_or_assign(const Key &key, const T &obj) {
    node *if_exist = find_by_key(key);
    if (if_exist) {
      if_exist->data_.second = obj;
      return std::make_pair(iterator(if_exist), true);
    } else {
      std::pair<Key, T> new_val(key, obj);
      return this->unique_insert(new_val);
    }
  }

  // lookup
  bool contains(const Key &key) {
    node *res = find_by_key(key);
    return ((res) ? true : false);
  }

 private:
  node *find_by_key(const key_type &key) {
    if (this->size_ > 0) {
      node *res = this->root_;
      while (res != nullptr && res != this->last_) {
        if (key < res->data_.first) {
          res = res->left_;
        } else if (key > res->data_.first) {
          res = res->right_;
        } else {
          return res;
        }
      }
    }
    return nullptr;
  }
};

}  // namespace s21
#endif  // CPP_S21_CONTAINERS_S21_MAP_HPP
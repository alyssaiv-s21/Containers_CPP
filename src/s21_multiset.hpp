#ifndef CPP_S21_CONTAINERS_S21_MULTISET_HPP
#define CPP_S21_CONTAINERS_S21_MULTISET_HPP

#include "s21_tree.hpp"

namespace s21 {

template <class T>
struct multiset_compare {
  using value_type = T;
  bool operator()(const value_type &x, const value_type &y) const {
    return x <= y;
  }
};

template <class T>
class multiset : public tree<T, multiset_compare<T>> {
 public:
  using tree<T, multiset_compare<T>>::tree;
  using key_type = T;
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = typename tree<T, multiset_compare<T>>::treeIterator;
  using const_iterator =
      typename tree<T, multiset_compare<T>>::treeConstIterator;
  using size_type = std::size_t;

  // lookup
  size_type count(const key_type &key) {
    size_type result = 0;
    auto iter = this->find(key);
    while (iter.it_ != nullptr && iter.it_->data_ == key) {
      ++result;
      --iter;
    }
    return result;
  }
  iterator lower_bound(const key_type &key) {
    iterator res = this->begin();
    while (res != this->end() && *res < key) {
      ++res;
    }
    return res;
  }
  iterator upper_bound(const key_type &key) {
    iterator res = this->begin();
    while (res != this->end() && *res <= key) {
      ++res;
    }
    return res;
  }
  std::pair<iterator, iterator> equal_range(const key_type &key) {
    iterator low = lower_bound(key);
    iterator up = upper_bound(key);
    return std::make_pair(low, up);
  }
};

}  // namespace s21
#endif  // CPP_S21_CONTAINERS_S21_MULTISET_HPP
#ifndef CPP_S21_CONTAINERS_S21_SET_HPP
#define CPP_S21_CONTAINERS_S21_SET_HPP

#include "s21_tree.hpp"

namespace s21 {

template <class T>
class set : public tree<T> {
 public:
  using tree<T>::tree;
  using key_type = T;
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = typename tree<T>::treeIterator;
  using const_iterator = typename tree<T>::treeConstIterator;
  using size_type = std::size_t;
};

}  // namespace s21
#endif  // CPP_S21_CONTAINERS_S21_SET_HPP
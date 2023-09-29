#ifndef CPP_S21_CONTAINERS_S21_TREE_HPP
#define CPP_S21_CONTAINERS_S21_TREE_HPP

#include <algorithm>
#include <functional>
#include <initializer_list>
#include <iostream>
#include <utility>

namespace s21 {
template <class T, class Compare = std::less<T>>
struct tree {
  struct treeNode;
  struct treeIterator;
  struct treeConstIterator;
  treeNode *last_;
  size_t size_;
  treeNode *root_;

  using key_type = T;
  using value_type = T;
  using node = treeNode;
  using reference = T &;
  using const_reference = const T &;
  using iterator = treeIterator;
  using const_iterator = treeConstIterator;
  using size_type = std::size_t;

  // member functions
  tree() : last_(new node(value_type())), size_(0), root_(nullptr) {}
  explicit tree(std::initializer_list<value_type> const &items) : tree() {
    for (auto elem : items) {
      insert(elem);
    }
  }
  tree(const tree &other) : tree() {
    for (auto iter = other.begin(); iter != other.end(); ++iter) {
      insert(*iter);
    }
  }
  tree(tree &&other) : tree() { swap(other); }
  ~tree() {
    clear();
    delete last_;
  }
  tree<T, Compare> &operator=(const tree &other) {
    clear();
    for (auto iter = other.begin(); iter != other.end(); ++iter) {
      insert(*iter);
    }
    size_ = other.size_;
    return *this;
  }
  tree<T, Compare> &operator=(tree &&other) {
    swap(other);
    return *this;
  }

  // iterators
  iterator begin() {
    node *res = root_->first();
    return iterator(res);
  }
  const_iterator begin() const {
    node *res = root_->first();
    return const_iterator(res);
  }
  iterator end() { return iterator(last_); }
  const_iterator end() const { return const_iterator(last_); }
  // capacity
  bool empty() const { return size_ == 0; }
  size_type size() const { return size_; }
  size_type max_size() const {
    return std::numeric_limits<size_type>::max() / sizeof(node) / 2.5;
  }

  // modifiers
  void clear() noexcept {
    while (size_) {
      erase(iterator(root_->first()));
    }
  }
  std::pair<iterator, bool> insert(const value_type &data) {
    return unique_insert(data);
  }

  std::pair<iterator, bool> unique_insert(const value_type &data) {
    if (size_ == 0) {
      root_ = new node(data);
      root_->right_ = last_;
      last_->parent_ = root_;
      ++size_;
      return std::pair<iterator, bool>(root_, true);
    }
    iterator current(root_);
    iterator place(nullptr);
    Compare comparator;
    while (current.it_ != nullptr && current != iterator(last_)) {
      place = current;
      if (comparator(data, *current)) {
        current = iterator(current->left_);
      } else if (comparator(*current, data)) {
        current = iterator(current->right_);
      } else {
        return std::pair<iterator, bool>(place, false);
      }
    }
    node *res = new node(data, place.it_);
    if (comparator(data, *place)) {
      place->left_ = res;
    } else {
      place->right_ = res;
      if (root_->last() != last_) {
        res->right_ = last_;
        last_->parent_ = res;
      }
    }
    ++size_;
    return std::pair<iterator, bool>(res, true);
  }

  void erase(iterator pos) {
    if (pos == iterator(last_)) return;
    node *first = nullptr;
    node *second = nullptr;
    if (pos.it_->left_ == nullptr || pos.it_->right_ == nullptr ||
        pos.it_->right_ == last_) {
      second = pos.it_;
    } else {
      second = pos.it_->right_;
      while (second->left_ != nullptr) {
        second = second->left_;
      }
    }
    if (second->left_ != nullptr) {
      first = second->left_;
    } else {
      first = second->right_;
    }
    if (first != nullptr && first != last_) {
      first->parent_ = second->parent_;
    }
    if (second->parent_) {
      if (second == second->parent_->left_) {
        second->parent_->left_ = first;
      } else {
        second->parent_->right_ = first;
      }
    } else {
      root_ = first;
    }
    if (pos != iterator(second)) {
      pos.it_->data_ = second->data_;
    }
    delete second;
    --size_;
  }

  void swap(tree &other) noexcept {
    std::swap(last_, other.last_);
    std::swap(size_, other.size_);
    std::swap(root_, other.root_);
  }

  void merge(tree &other) {
    s21::tree<value_type, Compare> temp{};
    for (size_type i = 0, j = other.size(); i < j; ++i) {
      iterator iter = other.begin();
      std::pair<iterator, bool> result = insert(iter.it_->data_);
      if (result.second == true) {
        other.erase(iter);
      } else {
        temp.insert(iter.it_->data_);
        other.erase(iter);
      }
    }
    other.swap(temp);
  }

  iterator find(const key_type &data) {
    if (size_ > 0) {
      iterator res(root_);
      while (res.it_ != nullptr && res != iterator(last_)) {
        if (data < *res) {
          res = iterator(res.it_->left_);
        } else if (data > *res) {
          res = iterator(res.it_->right_);
        } else {
          return res;
        }
      }
    }
    return end();
  }

  bool contains(const value_type &data) {
    auto iter = find(data);
    if (iter == end()) {
      return false;
    }
    return true;
  }

  template <class... Args>
  std::vector<std::pair<iterator, bool>> emplace(Args &&...args) {
    std::vector<std::pair<iterator, bool>> res{};
    for (auto elem : {std::forward<Args>(args)...}) {
      std::pair<iterator, bool> a = insert(elem);
      res.push_back(a);
    }
    return res;
  }

  struct treeNode {
    T data_;
    treeNode *parent_;
    treeNode *left_;
    treeNode *right_;
    treeNode(const T &data = T(), treeNode *p = nullptr, treeNode *l = nullptr,
             treeNode *r = nullptr)
        : data_(data), parent_(p), left_(l), right_(r) {}
    ~treeNode() {}

    treeNode *next() {
      treeNode *res = this;
      if (res->right_) {
        res = res->right_;
        while (res->left_) {
          res = res->left_;
        }
      } else {
        while (res->parent_ && (res->parent_->right_ == res)) {
          res = res->parent_;
        }
        res = res->parent_;
      }
      return res;
    }

    treeNode *prev() {
      treeNode *res = this;
      if (res->left_) {
        res = res->left_;
        while (res->right_) {
          res = res->right_;
        }
      } else {
        while (res->parent_ && (res->parent_->left_ == res)) {
          res = res->parent_;
        }
        res = res->parent_;
      }
      return res;
    }

    treeNode *first() {
      treeNode *res = this;
      while (res->left_) {
        res = res->left_;
      }
      return res;
    }
    treeNode *last() {
      treeNode *res = this;
      while (res->right_) {
        res = res->right_;
      }
      return res;
    }
  };

  struct treeIterator {
    treeNode *it_;
    explicit treeIterator(treeNode *it) noexcept : it_(it) {}
    treeIterator(const treeIterator &other) { *this = other; }
    ~treeIterator() {}
    treeIterator &operator=(const treeIterator &other) {
      it_ = other.it_;
      return *this;
    }
    T &operator*() const noexcept { return it_->data_; }
    treeNode *operator->() { return it_; }
    bool operator==(const treeIterator &other) const noexcept {
      return it_ == other.it_;
    }
    bool operator!=(const treeIterator &other) const noexcept {
      return it_ != other.it_;
    }
    treeIterator &operator++() {
      it_ = it_->next();
      return *this;
    }
    treeIterator &operator--() {
      it_ = it_->prev();
      return *this;
    }
  };

  struct treeConstIterator {
    treeNode *it_;
    explicit treeConstIterator(treeNode *it) noexcept : it_(it) {}
    treeConstIterator(const treeConstIterator &other) : it_(other.it_) {}
    ~treeConstIterator() {}
    const T &operator*() const noexcept { return it_->data_; }
    bool operator==(const treeConstIterator &other) const noexcept {
      return it_ == other.it_;
    }
    bool operator!=(const treeConstIterator &other) const noexcept {
      return it_ != other.it_;
    }
    treeConstIterator &operator++() {
      it_ = it_->next();
      return *this;
    }
    treeConstIterator &operator--() {
      if (it_) {
        it_ = it_->prev();
      }
      return *this;
    }
  };
};

}  // namespace s21
#endif  // CPP_S21_CONTAINERS_S21_TREE_HPP

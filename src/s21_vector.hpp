#ifndef CPP_S21_CONTAINERS_S21_VECTOR_HPP
#define CPP_S21_CONTAINERS_S21_VECTOR_HPP

#include <algorithm>
#include <initializer_list>
#include <limits>

namespace s21 {

template <class T>
class vector {
 private:
  size_t size_;
  size_t capacity_;
  T *data_;

 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = std::size_t;

  // member functions
  vector() noexcept : size_(0), capacity_(0), data_(nullptr) {}
  explicit vector(size_type n)
      : size_(n), capacity_(n), data_(n ? new value_type[n]() : nullptr) {}
  explicit vector(std::initializer_list<value_type> const &items)
      : size_(items.size()), capacity_(items.size()) {
    data_ = new value_type[capacity_];
    for (size_type i = 0; i < size_; ++i) {
      data_[i] = *(items.begin() + i);
    }
  }
  vector(const vector &other) : size_(other.size_), capacity_(other.capacity_) {
    data_ = new value_type[size_];
    for (size_type i = 0; i < size_; ++i) {
      data_[i] = other.data_[i];
    }
  }
  vector(vector &&other) noexcept
      : size_(other.size_), capacity_(other.capacity_), data_(other.data_) {
    other.size_ = other.capacity_ = 0;
    other.data_ = nullptr;
  }
  ~vector() {
    size_ = capacity_ = 0;
    delete[] data_;
  }
  vector &operator=(vector &&other) noexcept {
    if (this != &other) {
      size_ = other.size_;
      capacity_ = other.capacity_;
      delete[] data_;
      data_ = other.data_;
      other.size_ = other.capacity_ = 0;
      other.data_ = nullptr;
    }
    return *this;
  }
  vector &operator=(const vector &other) {
    if (this != &other) {
      delete[] data_;
      size_ = other.size_;
      capacity_ = other.capacity_;
      data_ = (size_ ? new value_type[size_] : nullptr);
      for (size_type i = 0; i < size_; ++i) {
        data_[i] = other.data_[i];
      }
    }
    return *this;
  }

  // element access
  reference at(size_type pos) {
    if (pos >= size_) throw "Pos should not be more than vector size";
    return data_[pos];
  }
  const_reference at(size_type pos) const {
    if (pos >= size_) throw "Pos should not be more than vector size";
    return data_[pos];
  }
  reference operator[](size_type pos) { return data_[pos]; }
  const_reference operator[](size_type pos) const { return data_[pos]; }
  reference front() { return *data_; }
  const_reference front() const { return *data_; }
  reference back() { return data_[size_ - 1]; }
  const_reference back() const { return data_[size_ - 1]; }
  iterator data() noexcept { return data_; }
  const_iterator data() const noexcept { return data_; }

  // iterators
  iterator begin() noexcept { return data_; };
  const_iterator begin() const noexcept { return data_; }
  iterator end() noexcept { return data_ + size_; };
  const_iterator end() const noexcept { return data_ + size_; };

  // capacity
  bool empty() const noexcept { return size_ == 0; }
  size_type size() const noexcept { return size_; }
  size_type max_size() const noexcept {
    return (std::numeric_limits<size_type>::max() / sizeof(value_type) / 2);
  }
  void reserve(size_type new_cap) {
    if (new_cap > capacity_) change_capacity(new_cap);
  }
  size_type capacity() const noexcept { return capacity_; }
  void shrink_to_fit() {
    if (capacity_ > size_) change_capacity(size_);
  }

  // modifiers
  void clear() noexcept { size_ = 0; }
  iterator insert(const_iterator pos, const_reference value) {
    size_type diff = pos - begin();
    if (size_ == capacity_) change_capacity(size_ * 2);
    ++size_;
    std::move(begin() + diff, end(), begin() + diff + 1);
    *(begin() + diff) = value;
    return (begin() + diff);
  }
  iterator erase(const_iterator pos) {
    iterator temp = begin() + (pos - begin());
    if (temp >= begin() && temp < end()) {
      std::move(temp + 1, end(), temp);
      --size_;
    }
    return temp;
  }
  void push_back(const_reference value) {
    if (size_ == capacity_) change_capacity(size_ * 2);
    ++size_;
    data_[size_ - 1] = value;
  }
  void pop_back() { --size_; }
  void swap(vector &other) noexcept {
    std::swap(size_, other.size_);
    std::swap(capacity_, other.capacity_);
    std::swap(data_, other.data_);
  }

  template <class... Args>
  iterator emplace(const_iterator pos, Args &&...args) {
    size_type diff = pos - begin();
    size_type i = 0;
    for (auto elem : {std::forward<Args>(args)...}) {
      insert(begin() + diff + i, elem);
      ++i;
    }
    return begin() + diff;
  }

  template <class... Args>
  void emplace_back(Args &&...args) {
    emplace(end(), args...);
  }

 private:
  void change_capacity(size_type new_cap) {
    iterator new_vec = new value_type[new_cap];
    for (size_type i = 0; i < size_; ++i) {
      new_vec[i] = data_[i];
    }
    delete[] data_;
    data_ = new_vec;
    capacity_ = new_cap;
  }
};
}  // namespace s21

#endif  // CPP_S21_CONTAINERS_S21_VECTOR_HPP
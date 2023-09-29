#ifndef CPP_S21_CONTAINERS_S21_ARRAY_HPP
#define CPP_S21_CONTAINERS_S21_ARRAY_HPP

namespace s21 {
template <class T, std::size_t N>
class array {
 private:
  T array_[N];

 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = std::size_t;

  // member functions
  array() noexcept = default;
  explicit array(std::initializer_list<value_type> const &items) {
    if (items.size() > N) throw "Init list is too big";
    for (size_type i = 0; i < N; ++i) {
      if (i < items.size()) {
        array_[i] = *(items.begin() + i);
      } else {
        array_[i] = value_type();
      }
    }
  }
  array(const array &other) {
    for (size_type i = 0; i < N; ++i) array_[i] = other.array_[i];
  }
  array(array &&other) { *this = std::move(other); }
  array &operator=(const array &other) {
    for (size_type i = 0; i < N; ++i) array_[i] = other.array_[i];
    return *this;
  }
  array &operator=(array &&other) {
    if (this != &other) {
      for (size_type i = 0; i < N; ++i) array_[i] = std::move(other.array_[i]);
    }
    return *this;
  }
  ~array() {}

  // element access
  reference at(size_type pos) {
    if (pos >= N) throw "Pos should not be more than array size";
    return array_[pos];
  }
  const_reference at(size_type pos) const {
    if (pos >= N) throw "Pos should not be more than array size";
    return array_[pos];
  }
  reference operator[](size_type pos) { return array_[pos]; }
  const_reference operator[](size_type pos) const { return array_[pos]; }
  const_reference front() const { return *array_; }
  const_reference back() const { return array_[N - 1]; }
  iterator data() noexcept { return N ? array_ : nullptr; }

  // iterators
  iterator begin() noexcept { return N ? array_ : end(); }
  const_iterator begin() const noexcept { return N ? array_ : end(); }
  iterator end() noexcept { return array_ + N; }
  const_iterator end() const noexcept { return array_ + N; }

  // capacity
  bool empty() const noexcept { return (N == 0) ? true : false; }
  size_type size() const noexcept { return N; }
  size_type max_size() const noexcept { return N; }

  // modifiers
  void swap(array &other) noexcept {
    for (size_type i = 0; i < N; ++i) std::swap(array_[i], other.array_[i]);
  }

  void fill(const_reference value) {
    for (size_type i = 0; i < N; ++i) array_[i] = value;
  }
};
}  // namespace s21

#endif  // CPP_S21_CONTAINERS_S21_ARRAY_HPP
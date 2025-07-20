/*
Stack implemented in C++
*/

#include <iostream>
#include <stdexcept>

template <typename T>
class StackCustom
{
private:
  T *data;
  size_t length;
  size_t capacity;
  T top;

  void resize(size_t new_capacity)
  {
    T *new_data = new T[new_capacity];
    for (size_t i = 0; i < length; i++)
    {
      new_data[i] = data[i];
    }

    delete[] data;
    data = new_data;
    capacity = new_capacity;
  }

public:
  StackCustom() : data(nullptr), capacity(0), length(0) {}

  ~StackCustom()
  {
    delete[] data;
  }

  void push(T element)
  {
    if (length == capacity)
    {
      resize(capacity == 0 ? 1 : capacity * 2);
    }
    top = element;
    data[length++] = element;
  }

  void pop()
  {
    if (length == 0)
    {
      throw std::out_of_range("Array is empty");
    }

    length--;
  }

  T &operator[](size_t index)
  {
    size_t prev_length = length;
    if (index >= length)
    {
      throw std::out_of_range("Index out of range");
    }
    if (index == length - 1)
    {
      return data[index];
    }
    else
    {
      for (int i = length; i > index; i--)
      {
        prev_length--;
      }
      return data[prev_length];
    }
  }

  size_t size()
  {
    return length;
  }

  T get_top() {
    return top;
  }

  bool is_empty() const
  {
    return length == 0;
  }
};

int main()
{
  StackCustom<int> stc;
  stc.push(1);
  stc.push(2);
  stc.push(3);

  for (size_t i = 0; i < stc.size(); i++) {
    std::cout << stc[i] << " ";
  }
  std::cout << std::endl;

  stc.pop();

  for (size_t i = 0; i < stc.size(); i++) {
    std::cout << stc[i] << " ";
  }
  std::cout << std::endl;

}
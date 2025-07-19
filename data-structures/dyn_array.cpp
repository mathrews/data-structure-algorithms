#include <iostream>
#include <stdexcept>

template <typename T>
class DynamicArray
{
private:
  T *data;
  size_t capacity;
  size_t length;

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
  DynamicArray() : data(nullptr), capacity(0), length(0) {}

  ~DynamicArray()
  {
    delete[] data;
  }

  void push_back(const T &value)
  {
    if (length == capacity)
    {
      resize(capacity == 0 ? 1 : capacity * 2);
    }
    data[length++] = value;
  }

  void pop_back()
  {
    if (length == 0)
    {
      throw std::out_of_range("Array is empty");
    }
    length--;
  }

  T &operator[](size_t index)
  {
    if (index >= length)
    {
      throw std::out_of_range("Index out of range");
    }
    return data[index];
  }

  size_t size() const
  {
    return length;
  }

  bool is_empty() const
  {
    return length == 0;
  }
};

int main()
{
  DynamicArray<int> arr;
  arr.push_back(1);
  arr.push_back(2);
  arr.push_back(3);

  for (size_t i = 0; i < arr.size(); i++)
  {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;

  arr.pop_back();

  for (size_t i = 0; i < arr.size(); i++)
  {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;

  return 0;
}
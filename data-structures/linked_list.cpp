/*
Linked List Implementation in C++
*/

#include <iostream>
#include <stdexcept>

template <typename T>
class Node
{
public:
  T data;
  Node *next;

  Node(const T &data) : data(data), next(nullptr) {}
};

template <typename T>
class LinkedList
{
private:
  Node<T> *head;
  Node<T> *tail;
  size_t length;

public:
  LinkedList() : head(nullptr), tail(nullptr), length(0) {}

  ~LinkedList()
  {
    clear();
  }

  void push_back(const T &value)
  {
    Node<T> *new_node = new Node<T>(value);
    if (tail)
    {
      tail->next = new_node;
    }
    tail = new_node;
    if (!head)
    {
      head = tail;
    }
    length++;
  }

  void pop_back()
  {
    if (!head)
    {
      throw std::out_of_range("List is empty");
    }
    if (head == tail)
    {
      delete head;
      head = tail = nullptr;
    }
    else
    {
      Node<T> *current = head;
      while (current->next != tail)
      {
        current = current->next;
      }
      delete tail;
      tail = current;
      tail->next = nullptr;
    }
    length--;
  }

  T &operator[](size_t index)
  {
    if (index >= length)
    {
      throw std::out_of_range("Index out of range");
    }
    Node<T> *current = head;
    for (size_t i = 0; i < index; i++)
    {
      current = current->next;
    }
    return current->data;
  }

  size_t size() const
  {
    return length;
  }

  bool is_empty() const
  {
    return length == 0;
  }

  void clear()
  {
    while (head)
    {
      Node<T> *temp = head;
      head = head->next;
      delete temp;
    }
    tail = nullptr;
    length = 0;
  }
};

int main()
{
  LinkedList<int> list;
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);

  for (size_t i = 0; i < list.size(); i++)
  {
    std::cout << list[i] << " ";
  }
  std::cout << std::endl;

  list.pop_back();

  for (size_t i = 0; i < list.size(); i++)
  {
    std::cout << list[i] << " ";
  }
  std::cout << std::endl;

  return 0;
}
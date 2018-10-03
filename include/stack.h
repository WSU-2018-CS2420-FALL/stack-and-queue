#ifndef _STACK_H_
#define _STACK_H_
#include <stdexcept>
template <typename T>
class StackADT {
public:
  virtual bool full() const = 0;
  virtual bool empty() const = 0;
  virtual void push(T e) = 0;
  virtual T top() const = 0;
  virtual void pop() = 0;
  virtual ~StackADT(){}
};

template <typename T>
class Stack : public StackADT<T> {
public:
  Stack(unsigned capacity = 1000);
  Stack(const Stack<T>& s);
  Stack<T>& operator=(const Stack<T>& s);
  bool full() const;
  bool empty() const;
  void push(T e);
  T top() const;
  void pop();
  ~Stack();

private:
  unsigned capacity;
  unsigned topE;
  T* elements = nullptr;

  Stack<T>& copy(const Stack<T>& s);
};

template <typename T>
struct Node {
  T info;
  Node* link;
  Node(T info): info(info), link(nullptr){}
};

template <typename T>
class LinkedStack : public StackADT<T> {
public:
  LinkedStack();
  LinkedStack(const LinkedStack<T>& s);
  LinkedStack<T>& operator=(const LinkedStack<T>& s);
  bool full() const;
  bool empty() const;
  void push(T e);
  T top() const;
  void pop();
  ~LinkedStack();

private:
  Node<T>* first;
  LinkedStack<T>& copy(const LinkedStack<T>& s);
  void destroy();
};

#endif
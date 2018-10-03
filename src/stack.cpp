#include <iostream>
#include "stack.h"
using namespace std;

int main(){
  Stack<int> s;

  s.push(5);
  s.push(10);
  s.push(15);
  s.push(20);
  s.push(25);

  Stack<int> t;
  t = s;
  cout << s.top() << endl; s.pop();
  cout << s.top() << endl; s.pop();
  cout << s.top() << endl; s.pop();
  cout << s.top() << endl; s.pop();
  cout << s.top() << endl; s.pop();


  cout << t.top() << endl; t.pop();
  cout << t.top() << endl; t.pop();
  cout << t.top() << endl; t.pop();
  cout << t.top() << endl; t.pop();
  cout << t.top() << endl; t.pop();
  
  return 0;
}
// Implementation
template <typename T>
LinkedStack<T>::LinkedStack(): first(nullptr){}

template <typename T>
LinkedStack<T>::LinkedStack(const LinkedStack<T>& s){
  copy(s);
}

template <typename T>
LinkedStack<T>& LinkedStack<T>::operator=(const LinkedStack<T>& s){
  destroy();
  return copy(s);
}

template <typename T>
LinkedStack<T>& LinkedStack<T>::copy(const LinkedStack<T>& s){
  first = nullptr;
  Node<T>* last = nullptr;
  auto current = s.first;
  while(current){
    auto newNode = new Node<T>(current->info);
    if(first == nullptr){ // empty list
      first = newNode;
    } else {
      last->link = newNode;
    }
    last = newNode;
    current = current->link;
  }

  return *this;
}

template <typename T>
void LinkedStack<T>::destroy(){
  auto current = first;
  while(current){
    auto temp = current;
    current = current->link;
    delete temp;
  }
}

template <typename T>
bool LinkedStack<T>::full() const{
  return false;
}

template <typename T>
bool LinkedStack<T>::empty() const{
  return first == nullptr;
}

template <typename T>
void LinkedStack<T>::push(T e){
  auto node = new Node<T>(e);
  node->link = first;
  first = node;
}

template <typename T>
T LinkedStack<T>::top() const {
  if(empty()){
    throw std::runtime_error("Stack is empty");
  }
  return first->info;
}

template <typename T>
void LinkedStack<T>::pop(){
  if(empty()){
    throw std::runtime_error("Stack is empty");
  }

  auto tmp = first;
  first = first->link;
  delete tmp;
}

template <typename T>
LinkedStack<T>::~LinkedStack() {
  destroy();
}

// Stack: array based implementation
template <typename T>
Stack<T>::Stack(unsigned capacity): capacity(capacity){
  elements = new T[capacity]();
}

template <typename T>
Stack<T>::Stack(const Stack<T>& s): capacity(s.capacity), topE(s.topE){
  copy(s);
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& s){
  return copy(s);
}

template <typename T>
Stack<T>& Stack<T>::copy(const Stack<T>& s){
  delete[] elements;
  capacity = s.capacity;
  topE = s.topE;
  elements = new T[capacity]();
  for(int i = 0; i < topE; i++){
    elements[i] = s.elements[i];
  }

  return *this;
}

template <typename T>
bool Stack<T>::full() const{
  return topE == capacity;
}

template <typename T>
bool Stack<T>::empty() const{
  return topE == 0;
}

template <typename T>
void Stack<T>::push(T e){
  if(full()){
    throw std::runtime_error("Stack is full");
  }

  elements[topE++] = e;
}

template <typename T>
T Stack<T>::top() const {
  if(empty()){
    throw std::runtime_error("Stack is empty");
  }

  return elements[topE - 1];
}

template <typename T>
void Stack<T>::pop(){
  if(empty()){
    throw std::runtime_error("Stack is empty");
  }

  topE--;
}

template <typename T>
Stack<T>::~Stack() {
  delete[] elements;
  elements = nullptr;
}
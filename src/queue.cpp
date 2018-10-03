#include <iostream>
#include "queue.h"
#include <string>
using namespace std;

int main(){
  LinkedQueue<int> q;

  q.enqueue(5);
  q.enqueue(10);
  q.enqueue(15);
  q.enqueue(20);
  q.enqueue(25);

  LinkedQueue<int> p;
  p = q;
  cout << q.peekFront() << endl; q.dequeue();
  cout << q.peekFront() << endl; q.dequeue();
  cout << q.peekFront() << endl; q.dequeue();
  cout << q.peekFront() << endl; q.dequeue();
  cout << q.peekFront() << endl; q.dequeue();


  cout << p.peekFront() << endl; p.dequeue();
  cout << p.peekFront() << endl; p.dequeue();
  cout << p.peekFront() << endl; p.dequeue();
  cout << p.peekFront() << endl; p.dequeue();
  cout << p.peekFront() << endl; p.dequeue();


  return 0;
}
// LinkedStack: linked list based implementation
template <typename T>
LinkedQueue<T>::LinkedQueue(): front(nullptr), rear(nullptr){}

template <typename T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& q){
  copy(q);
}

template <typename T>
LinkedQueue<T>& LinkedQueue<T>::operator=(const LinkedQueue<T>& q){
  destroy();
  return copy(q);
}

template <typename T>
LinkedQueue<T>& LinkedQueue<T>::copy(const LinkedQueue<T>& q){
  front = nullptr;
  rear = nullptr;
  auto current = q.front;
  while(current){
    auto newNode = new Node<T>(current->info);
    if(front == nullptr){ // empty list
      front = newNode;
    } else {
      rear->link = newNode;
    }
    rear = newNode;
    current = current->link;
  }

  return *this;
}

template <typename T>
void LinkedQueue<T>::destroy(){
  auto current = front;
  while(current){
    auto temp = current;
    current = current->link;
    delete temp;
  }
}

template <typename T>
bool LinkedQueue<T>::full() const{
  return false;
}

template <typename T>
bool LinkedQueue<T>::empty() const{
  return front == nullptr;
}

template <typename T>
void LinkedQueue<T>::enqueue(T e){
  auto node = new Node<T>(e);
  if(front == nullptr){
    front = node;
  }else{
    rear->link = node;
  }

  rear = node;
}

template <typename T>
T LinkedQueue<T>::peekFront() const {
  if(empty()){
    throw std::runtime_error("Queue is empty");
  }
  return front->info;
}

template <typename T>
T LinkedQueue<T>::peekRear() const {
  if(empty()){
    throw std::runtime_error("Queue is empty");
  }
  return rear->info;
}

template <typename T>
void LinkedQueue<T>::dequeue(){
  if(empty()){
    throw std::runtime_error("Queue is empty");
  }

  auto tmp = front;
  front = front->link;
  delete tmp;
}

template <typename T>
LinkedQueue<T>::~LinkedQueue() {
  destroy();
}

// Stack: array based implementation
template <typename T>
Queue<T>::Queue(unsigned capacity): capacity(capacity){ 
  front = 0;
  rear = capacity - 1;
  elements = new T[capacity]();
}

template <typename T>
Queue<T>::Queue(const Queue<T>& q){
  copy(q);
}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& q){
  return copy(q);
}

template <typename T>
Queue<T>& Queue<T>::copy(const Queue<T>& q){
  delete[] elements;

  capacity = q.capacity;
  front = q.front;
  rear = q.rear;
  count = q.count;
  elements = new T[capacity]();
  for(int i = 0; i < capacity; i++){
    elements[i] = q.elements[i];
  }

  return *this;
}

template <typename T>
bool Queue<T>::full() const{
  return count == capacity;
}

template <typename T>
bool Queue<T>::empty() const{
  return count == 0;
}

template <typename T>
void Queue<T>::enqueue(T e){
  if(full()){
    throw std::runtime_error("Queue is full");
  }

  rear = (rear + 1) % capacity;
  elements[rear] = e;
  count++;
}

template <typename T>
T Queue<T>::peekFront() const {
  if(empty()){
    throw std::runtime_error("Queue is empty");
  }

  return elements[front];
}

template <typename T>
T Queue<T>::peekRear() const {
  if(empty()){
    throw std::runtime_error("Queue is empty");
  }

  return elements[rear];
}

template <typename T>
void Queue<T>::dequeue(){
  if(empty()){
    throw std::runtime_error("Queue is empty");
  }

  front = (front + 1) % capacity;
  count--;
}

template <typename T>
Queue<T>::~Queue() {
  delete[] elements;
  elements = nullptr;
}
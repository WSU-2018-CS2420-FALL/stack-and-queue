#ifndef _QUEUE_H_
#define _QUEUE_H_

template <typename T>
class QueueADT {
public:
  virtual bool full() const = 0;
  virtual bool empty() const = 0;
  virtual void enqueue(T e) = 0;
  virtual T peekFront() const = 0;
  virtual T peekRear() const = 0;
  virtual void dequeue() = 0;
  virtual ~QueueADT(){}
};

template <typename T>
class Queue : public QueueADT<T> {
public:
  Queue(unsigned capacity = 1000);
  Queue(const Queue<T>& q);
  Queue<T>& operator=(const Queue<T>& q);
  bool full() const;
  bool empty() const;
  void enqueue(T e);
  T peekFront() const;
  T peekRear() const;
  void dequeue();
  ~Queue();

private:
  unsigned capacity;
  unsigned front;
  unsigned rear;
  unsigned count;
  T* elements = nullptr;

  Queue<T>& copy(const Queue<T>& q);
};

template <typename T>
struct Node {
  T info;
  Node* link;
  Node(T info): info(info), link(nullptr){}
};

template <typename T>
class LinkedQueue : public QueueADT<T> {
public:
  LinkedQueue();
  LinkedQueue(const LinkedQueue<T>& q);
  LinkedQueue<T>& operator=(const LinkedQueue<T>& q);
  bool full() const;
  bool empty() const;
  void enqueue(T e);
  T peekFront() const;
  T peekRear() const;
  void dequeue();
  ~LinkedQueue();

private:
  Node<T>* front;
  Node<T>* rear;
  LinkedQueue<T>& copy(const LinkedQueue<T>& q);
  void destroy();
};

#endif
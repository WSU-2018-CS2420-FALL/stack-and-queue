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


#endif
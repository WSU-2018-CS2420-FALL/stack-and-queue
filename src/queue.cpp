#include <iostream>
#include "queue.h"
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
// Implementation

#include <iostream>
#include <string>

template <typename T>
struct Node {
  // private:
    T value;
    Node *next;
    Node(T value, Node<T> *next = nullptr) 
    : value(value), next(next) {};
    // template <typename T>
    // friend class Queue;
};

template <typename T>
class Queue {
  private: 
    Node<T> *front;
    Node<T> *rear;
  public: 
    Queue() : front(nullptr), rear(nullptr) {};
    void enqueue(T value);
    void dequeue();
    T& getFront() const;
    bool isEmpty() const;
    void display() const;
};


int main() {

  // std::cout << "C++ is running\n";
  Queue<const double> q;
  q.enqueue(4);
  q.enqueue(4.5);
  q.display();
  q.dequeue();
  q.display();

  return 0;
}

template <typename T>
bool Queue<T>::isEmpty() const {
  return front == nullptr;
}

template <typename T>
void Queue<T>::enqueue(T value) {
  Node<T> *newNode = new Node<T>(value);

  if (isEmpty()) {
    front = rear = newNode;
  } else {
    rear->next = newNode;
    rear = newNode;
  }
}

template <typename T>
void Queue<T>::dequeue() {
  if (isEmpty()) {
    std::cout << "The queue is empty!\n";
    return;
  }
  Node<T> *temp = front;
  front = front->next;
  delete temp;
  if (!front) rear = nullptr;
}

template <typename T>
T& Queue<T>::getFront() const {
  if (isEmpty()) {
    std::cout << "The queue is empty!\n";
    return;
  }
  return front;
}

template <typename T>
void Queue<T>::display() const {
  if (isEmpty()) {
    std::cout << "The queue is empty!\n";
    return;
  }
  Node<T> *temp = front;
  while (temp->next != nullptr) {
    std::cout << temp->value << std::endl;
    temp = temp->next;
  }
}
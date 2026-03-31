#include <iostream>
#include <string>
#include <stdexcept>

template <typename T>
class Queue;

template <typename T>
struct Node {
  private:
    T value;
    Node *next;
    Node(T value, Node<T> *next = nullptr) 
    : value(value), next(next) {};
    friend class Queue<T>;
};

template <typename T>
class Queue {
  private: 
  
    Node<T> *front;
    Node<T> *rear;
    
  public: 
    Queue() : front(nullptr), rear(nullptr) {};
    ~Queue();
    void enqueue(T value);
    void dequeue();
    T& getFront() const;
    bool isEmpty() const;
    void display() const;
};

void demo();
template <typename T>
void runMenu(std::string &choice);

int main() {

  demo();

  return 0;
}

template <typename T>
Queue<T>::~Queue() {
  while (!isEmpty()) {
    this->dequeue();
  }
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
    throw std::out_of_range("Queue is empty");
  }
  return front->value;
}

template <typename T>
void Queue<T>::display() const {
  if (isEmpty()) {
    std::cout << "The queue is empty!\n";
    return;
  }
  Node<T> *temp = front;
  
  std::cout << "\n⬇ FRONT\n";
  while (temp != nullptr) {
    std::cout << temp->value << std::endl;
    temp = temp->next;
  }
  std::cout << "⬆ REAR\n\n";
}

void demo() {
  std::string choice;
  std::cout << "\n=======Queue=======\n";
  std::cout << "Choose queue data type (str, int, short, double, char): ";
  std::cin >> choice;

  if (choice == "str") {
    runMenu<std::string>(choice);
  } else if (choice == "int") {
    runMenu<int>(choice);
  } else if (choice == "double") {
    runMenu<double>(choice);
  } else if (choice == "char") {
    runMenu<char>(choice);
  } else if (choice == "short") {
    runMenu<short>(choice);
  } else {
    std::cout << "Invalid input!\n";
    std::cout << "\n===================\n";
    exit(-1);
  }
  std::cout << "\n===================\n";
}

template <typename T>
void runMenu(std::string &choice) {
  Queue<T> queue;
  T value;
  do {
    std::cout << "Choose an operation (enq, deq, getF, isEm): ";
    std::cin >> choice;
    
    if (choice == "enq") {
      std::cout << "Enter your value: ";
      std::cin >> value;
      queue.enqueue(value);
      queue.display();
    } else if (choice == "deq") {
      queue.dequeue();
      queue.display();
    } else if (choice == "getF") {
      try {
        std::cout << "Front element: " << queue.getFront() << std::endl;
      } catch (std::out_of_range &e) {
        std::cout << e.what() << std::endl;
      }
    } else if (choice == "isEm") {
      std::cout << (queue.isEmpty() ? "true" : "false") << std::endl;
    }

    std::cout << "Continue/exit (c/e): ";
    std::cin >> choice;
  } while (choice == "c");
}
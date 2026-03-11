#include <iostream>
#include <stdexcept>

void demo();

struct Node {
  private:
    int value;
    Node *next;
    void print() const;
    Node(const int value, Node *next);
    friend class Stack;
};

class Stack {
  private: 
    Node *top;
  public: 
    Stack() { top = nullptr; };
    ~Stack();
    void push(const int value);
    void pop();
    void printStack() const;
};

int main() {
  demo();
  return 0;
}

Node::Node(const int value, Node *next) : value(value), next(next) {};

void Node::print() const {
  std::cout << "Value: " << this->value << std::endl;
}

void Stack::push(const int value) {
  Node *temp = new Node(value, top);
  top = temp;
}

void Stack::pop() {
  if (!top) throw std::underflow_error("Stack is empty!");

  Node *temp = top;
  top = top->next;
  delete temp;
}

void Stack::printStack() const {
  if (!top) throw std::underflow_error("Stack is empty!");

  Node *current = top;
  std::cout << std::endl << "⬇ TOP\n";
  while (current) {
    current->print();
    current = current->next;
  }
  std::cout << std::endl;
}

Stack::~Stack() {
  while (top) {
    Node *temp = top;
    top = top->next;
    delete temp;
  }
}

void demo() {
  Stack stackOfNodes;
  std::string choice;
  std::cout << "\n===Stack exceptions===\n";
  do {
    std::cout << "Choose an operation to perform with the stack (push/pop): ";
    std::cin >> choice;

    if (choice == "push") {
      int value(0);
      std::cout << "Enter an integer value: ";
      std::cin >> value;
      stackOfNodes.push(value);
    }

    else if (choice == "pop") {
      try {
        stackOfNodes.pop();
      }
      catch (std::underflow_error& e) {
        std::cout << e.what() << std::endl;
      }
    }

    try {
      stackOfNodes.printStack();
    }
    catch (std::underflow_error& e) {
      std::cout << e.what() << std::endl;
    }
    std::cout << "Continue or exit? (c/e): ";
    std::cin >> choice;
  } while (choice == "c");
  std::cout << "======================\n\n";
                
}
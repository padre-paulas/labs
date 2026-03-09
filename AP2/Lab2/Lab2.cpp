#include <iostream>

struct Node {
  private:
    int value;
    Node *next;
  public:
    Node(const int value, Node *next);
    void print() const;
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
    void sort();
    void printStack() const;
};

int main() {
  Stack stackOfNodes;
  stackOfNodes.push(4993);
  stackOfNodes.push(44);
  stackOfNodes.push(4);
  stackOfNodes.push(5);
  stackOfNodes.push(459);
  stackOfNodes.sort();
  stackOfNodes.printStack();
  stackOfNodes.pop();

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
  if (!top) {
    std::cout << "Stack is empty!\n";
    return;
  }
  Node *temp = top;
  top = top->next;
  delete temp;
}

void Stack::sort() {
  Stack sorted;
  while (top != nullptr) {
    int tempValue = top->value;
    pop();
    while (sorted.top != nullptr && sorted.top->value < tempValue) {
      push(sorted.top->value);
      sorted.pop();
    }
    sorted.push(tempValue);
  }
  while (sorted.top != nullptr) {
    push(sorted.top->value);
    sorted.pop();
  }
}

void Stack::printStack() const {
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
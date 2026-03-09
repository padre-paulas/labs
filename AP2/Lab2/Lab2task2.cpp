#include <iostream>
#include <string>

struct Node {
  private:
    std::string phoneName;
    double price;
    Node *next;
  public:
    Node(
      const std::string phoneName, 
      const double price,
       Node *next
      );
    void print() const;
    friend class Stack;
};

class Stack {
  private: 
    Node *top;
  public: 
    Stack() { top = nullptr; };
    ~Stack() { clearStack(); };
    void push(std::string phoneName, double price);
    void pop();
    void deleteBottom();
    void printStack() const;
    void clearStack();
};

int main() {
  Stack stackOfNodes;

  stackOfNodes.push("Iphone 13", 400);
  stackOfNodes.push("Iphone 14", 600);
  stackOfNodes.push("Iphone 15", 700);
  stackOfNodes.push("Iphone 17", 1000);
  stackOfNodes.push("Iphone 17 Pro", 1100);
  // stackOfNodes.clearStack();
  // stackOfNodes.deleteFirst();
  stackOfNodes.printStack();

  return 0;
}

Node::Node(const std::string phoneName, const double price, Node *next)
: phoneName(phoneName), price(price), next(next) {};

void Node::print() const {
  std::cout << "Phone name: " << phoneName 
  << ", price: " << price << "$" << std::endl;
}

void Stack::push(const std::string phoneName, const double price) {
  Node *temp = new Node(phoneName, price, top);
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

void Stack::printStack() const {
  Node *current = top;

  std::cout << std::endl << "⬇ TOP\n";
  while (current) {
    current->print();
    current = current->next;
  }
  std::cout << std::endl;
}

void Stack::clearStack() {
  while (top) pop();
}

void Stack::deleteBottom() {
  if (!top) {
    std::cout << "Stack is empty!\n";
    return;   
  }

  Stack buffer;
  while (top->next) {
    buffer.push(top->phoneName, top->price);
    this->pop();
  }
  this->pop();

  while (buffer.top) {
    this->push(buffer.top->phoneName, buffer.top->price);
    buffer.pop();
  }
}
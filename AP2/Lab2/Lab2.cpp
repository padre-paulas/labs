#include <iostream>

struct Node {
  private:
    int value;
    Node *next;
  public:
    Node(int value, Node *next);
    void print();
    friend class Stack;
};

class Stack {
  private: 
    Node *top;
  public: 
    Stack() { top = nullptr; };
    ~Stack();
    void push(int value);
    Node* pop();
   
};

int main() {

  Stack stackOfNodes;
  stackOfNodes.push(43);
  stackOfNodes.push(44);
  stackOfNodes.push(45);
  Node *popped = stackOfNodes.pop();
  popped->print();

  return 0;
}

Node::Node(int value, Node *next) : value(value), next(next) {};

void Node::print() {
  std::cout << "Value: " << this->value << std::endl;
}

void Stack::push(int value) {
  Node *temp = new Node(value, top);
  Node *elementPtr = top;
  while (temp->value > elementPtr->next->value) {
    elementPtr = elementPtr->next;
  }
  elementPtr->next = temp;
  temp->next = elementPtr->next->next;

  // top = temp;
  // delete temp;
  // std::cout << "We just pushed " << top->value;
}

Node* Stack::pop() {
  if (!top) {
    std::cout << "Stack is empty!\n";
    return nullptr;
  }
  Node *temp = top;
  top = top->next;
  // std::cout << "THE VALUE: " << temp->value;
  return temp;
}

Stack::~Stack() {
  while (top) {
    Node *temp = top;
    top = top->next;
    delete temp;
  }
}
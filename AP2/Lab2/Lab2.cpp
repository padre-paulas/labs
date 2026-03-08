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
    Stack* sort();
};

int main() {
  Stack stackOfNodes;
  stackOfNodes.push(4993);
  stackOfNodes.push(44);
  stackOfNodes.push(4);
  stackOfNodes.push(5);
  stackOfNodes.push(459);
  Node *popped = stackOfNodes.pop();
  popped->print();
  stackOfNodes.sort();
  stackOfNodes.pop();

  return 0;
}

Node::Node(int value, Node *next) : value(value), next(next) {};

void Node::print() {
  std::cout << "Value: " << this->value << std::endl;
}

void Stack::push(int value) {
  Node *temp = new Node(value, top);
  top = temp;
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

Stack* Stack::sort() {
  Stack copy = *this;
  Stack *sorted = new Stack;
  while (copy.top != nullptr) {
    int tempValue = copy.top->value;
    copy.pop();
    while (sorted->top != nullptr) {
      if (sorted->top->value > tempValue) {
      copy.push(sorted->top->value);
      sorted->pop();
      }
      break;
    }
    sorted->push(tempValue);
  }
  return sorted;
}

Stack::~Stack() {
  while (top) {
    Node *temp = top;
    top = top->next;
    delete temp;
  }
}
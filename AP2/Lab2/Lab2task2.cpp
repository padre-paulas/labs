#include <iostream>
#include <string>

struct Node {
  private:
    std::string phoneName;
    double price;
    Node *next;
  public:
    Node(std::string phoneName, double price, Node *next);
    void print();
    friend class Stack;
};

class Stack {
  private: 
  public: // to be returned to private!!
    Node *top;
  public: 
    Stack() { top = nullptr; };
    // ~Stack();
    void push(std::string phoneName, double price);
    void pop();
    void deleteFirst();
    void printStack();
    void clearStack();
    // Stack* sort();
};

int main() {
  Stack stackOfNodes;
  stackOfNodes.push("Iphone 13", 500);
  stackOfNodes.push("Iphone 14", 500);
  stackOfNodes.push("Iphone 15", 600);
  stackOfNodes.push("Iphone 17", 1000);
  stackOfNodes.top->print();
  stackOfNodes.clearStack();
  stackOfNodes.printStack();

  return 0;
}

// int main() {
//   Stack stackOfNodes;
//   stackOfNodes.push(4993);
//   stackOfNodes.push(44);
//   stackOfNodes.push(4);
//   stackOfNodes.push(5);
//   stackOfNodes.push(459);
//   Node *popped = stackOfNodes.pop();
//   popped->print();
//   stackOfNodes.sort();
//   stackOfNodes.pop();

//   return 0;
// }

Node::Node(std::string phoneName, double price, Node *next)
: phoneName(phoneName), price(price), next(next) {};

void Node::print() {
  std::cout << "Phone name: " << phoneName 
  << ", price: " << price << "$" << std::endl;
}

void Stack::push(std::string phoneName, double price) {
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

void Stack::printStack() {
  Node *current = top;
  while (current) {
    current->print();
    current = current->next;
  }
}

void Stack::clearStack() {
  while (top) pop();
}

void Stack::deleteFirst() {

}

// // Stack* Stack::sort() {
// //   Stack copy = *this;
// //   Stack *sorted = new Stack;
// //   while (copy.top != nullptr) {
// //     int tempValue = copy.top->value;
// //     copy.pop();
// //     while (sorted->top != nullptr) {
// //       if (sorted->top->value > tempValue) {
// //       copy.push(sorted->top->value);
// //       sorted->pop();
// //       }
// //       break;
// //     }
// //     sorted->push(tempValue);
// //   }
// //   return sorted;
// // }

// Stack::~Stack() {
//   while (top) {
//     Node *temp = top;
//     top = top->next;
//     delete temp;
//   }
// }
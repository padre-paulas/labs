#include <iostream> 
#include <cstring>
#include <typeinfo>

struct Node {
  char letter;
  Node *next;
  Node(char letter, Node *next) {
    this->letter = letter;
    this->next = next;
  }
  void setNext(Node *next) {
    this->next = next;
  }
};

class CircularLL {
  public: 
    // CircularLL(char headLetter);
    void insert(char letter);
    void delElem(char letter);
    void print();
  // private: 
    Node *head = nullptr;
};

int main() {

  // Node *alphabet = nullptr;
  CircularLL list;
  list.insert('A');
  std::cout << list.head->letter << std::endl;

  list.insert('B');
  list.insert('C');

  list.delElem('C');


  std::cout << list.head->next->letter << std::endl;

  return 0;
}

// CircularLL::CircularLL(char headLetter) {
//   *head = Node(headLetter, nullptr);
// }

void CircularLL::insert(char letter) {
  Node *newNode = new Node(letter, nullptr);
  if (!head) {
    head = newNode;
  } else {
    Node *temp = head;
    while (temp->next) {
      temp = temp->next;
    }
    temp->next = newNode;
  }
}

void CircularLL::delElem(char letter) {
  if (!head) return;
  Node *temp = head;
  std::cout << typeid(temp->letter).name() << " and " << typeid(letter).name() << std::endl;
  // std::cout << temp->letter != letter;
  // while (!(temp->letter == letter)) {
  //   temp = temp->next;
  // }
  // temp->next = nullptr;
}

void CircularLL::print() {

}


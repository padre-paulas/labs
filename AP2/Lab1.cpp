#include <iostream> 

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
    void append(char letter);
    void delElem(char letter);
    void delLast();
    void print();
  private: 
    Node *head = nullptr;
};

int main() {
  CircularLL list;
  list.append('A');
  list.append('B');
  list.append('C');
  list.delLast();
  list.print();
  
  return 0;
}

void CircularLL::append(char letter) {
  Node *newNode = new Node(letter, nullptr);
  if (!head) {
    head = newNode;
    head->next = head;
  } else {
    Node *temp = head;
    while (temp->next != head) {
      temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
  }
  std::cout << "Appended " << newNode->letter << std::endl;
}

void CircularLL::delElem(char letter) {
  if (!head) {
    std::cout << "The list is empty!\n";
    return;
  }
  Node *temp = head;
  if (temp->letter == letter) {
    if (temp == temp->next) {
      head = nullptr;
      delete temp;
      return;
    }
    while (temp->next != head) {
      temp = temp->next;
    } 
    Node *toDelete = temp->next;
    temp->next = head->next;
    head = temp->next;
    delete toDelete;
    return;
  }
  while (temp->next->letter != letter && temp->next->next != head) {
    temp = temp->next;
  }
  if (temp->next->letter != letter) {
    std::cout << "The list doesn't contain letter " << letter << std::endl;
    return;
  }
  Node *toDelete = temp->next;
  temp->next = temp->next->next;
  delete toDelete;
}

void CircularLL::print() {
  if (!head) {
    std::cout << "The list is empty!\n"; 
    return;
  }
  Node *temp = head;
  std::cout << "\nList:\n";
  do {
    std::cout << temp->letter << std::endl;
    temp = temp->next;
  } while (temp != head);
}

void CircularLL::delLast() {
   if (!head) {
    std::cout << "The list is empty!\n"; 
    return;
  }
  Node *temp = head;
 
  if (temp->next == head) {
    delete temp;
    head = nullptr;
    return;
  }
  while (temp->next->next != head) {
    temp = temp->next;
  }
  Node *toDelete = temp->next;
  temp->next = temp->next->next;
  delete toDelete;
}


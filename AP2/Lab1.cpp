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
    void prepend(char letter);
    void delElem(char letter);
    void delLast();
    void print();
    void fillAlphabet();
    ~CircularLL() { deleteList(); };
  private: 
    void deleteList();
    Node *head = nullptr;
};

int main() {
  CircularLL list;
  list.fillAlphabet();
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

void CircularLL::prepend(char letter) {
  Node *newNode = new Node(letter, nullptr);
  if (!head) {
    head = newNode;
    head->next = head;
  } else {
    Node *temp = head;
    while (temp->next != head) {
      temp = temp->next;
    }
    newNode->next = head;
    temp->next = newNode;
    head = newNode;
  }
  std::cout << "Prepended " << letter << std::endl;
}

void CircularLL::delElem(char letter) {
  if (!head) {
    std::cout << "The list is empty!\n";
    return;
  }
  Node *temp = head;
  if (temp->letter == letter) {
    if (temp == temp->next) {
      std::cout << "Deleted " << letter << std::endl;
      head = nullptr;
      delete temp;
      return;
    }
    while (temp->next != head) {
      temp = temp->next;
    } 
    std::cout << "Deleted " << letter << std::endl;
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
  std::cout << "Deleted " << letter << std::endl;
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
    std::cout << temp->letter << "  ";
    temp = temp->next;
  } while (temp != head);
  std::cout << std::endl;
}

void CircularLL::delLast() {
  if (!head) {
    std::cout << "The list is empty!\n"; 
    return;
  }
  Node *temp = head;
 
  if (temp->next == head) {
    std::cout << "Deleted " << temp->letter << std::endl;
    delete temp;
    head = nullptr;
    return;
  }
  while (temp->next->next != head) {
    temp = temp->next;
  }
  std::cout << "Deleted " << temp->next->letter << std::endl;
  Node *toDelete = temp->next;
  temp->next = temp->next->next;
  delete toDelete;
}

void CircularLL::deleteList() {
  if (!head) return;
  Node *temp = head->next;
  while (temp != head) {
    Node *toDelete = temp;
    temp = temp->next;
    delete toDelete;
  }
  delete head;
  head = nullptr;
}

void CircularLL::fillAlphabet() {
  for (char ch = 'A'; ch <= 'Z'; ch++) {
    append(ch);
  }
}
#include <iostream>
#include <string>

class Tree {
  private: 
    struct Node {
      std::string word;
      int key = 0;
      Node *left = nullptr;
      Node *right = nullptr;

      Node(std::string word, int key) :
        word(word), key(key) {};
    };

    Node *root = nullptr;
    void printInnerNode(Node *node);
    void printInner(Node *root, int space);
    void removeNodeInner(Node *node, int key);
  public:
    void insert(std::string word, int key);
    void print();
    void removeNode(int key);
};

void demo();

int main() {
  demo();

  return 0;
}

void demo() {
  Tree tree;
  tree.insert("IF (1 < 2) { say \"hi\" }", 1);
  tree.insert("THEN IF (4 > 2) { \"say \"what\" }", 2);
  tree.insert("ELSE { say \"hello\" }", 0);
  tree.insert("THEN IF (2 > 0) { say \"never\" }", 3);
  tree.insert("ELSE { say \"stop\" }", 3);
  tree.print();
  tree.removeNode(0);
  tree.print();
}

void Tree::printInnerNode(Node *node) {
  std::cout << "Data: " << node->word;
}

void Tree::insert(std::string word, int key) {
  if (root == nullptr) {
    root = new Node(word, key);
    return;
  }
  Node *current = root;
  while (true) {
    if (current->key < key) {
      if (current->right == nullptr) {
        current->right = new Node(word, key);
        return;
      }
      current = current->right;
    } else {
      if (current->left == nullptr) {
        current->left = new Node(word, key);
        return;
      }
      current = current->left;
    }
  }
}

void Tree::print() {
  std::cout << "-----------------\n";
  printInner(root, 0);
  std::cout << "-----------------\n";
}

void Tree::printInner(Node *current, int space) {
  if (current == nullptr) return;
  printInner(current->right, space + 10);
  for (int i = 0; i < space; i++) std::cout << " ";
  std::cout << current->word << std::endl;
  printInner(current->left, space + 10);
}

void Tree::removeNode(int key) {
  removeNodeInner(root, key);
}

void Tree::removeNodeInner(Node *node, int key) {
  if (node->left->key == key) {
    Node *temp = node->left;
    node->left = nullptr;
    delete temp;
    return;
  } else if (node->right->key == key) {
    Node *temp = node->right;
    node->right = nullptr;
    delete temp;
    return;
  } else if (node->key < key) {
    if (node->right == nullptr) return;
    removeNodeInner(node->right, key);
  } else {
    if (node->left == nullptr) return;
    removeNodeInner(node->left, key);
  }
}
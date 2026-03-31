#include <iostream>
#include <string>

class Tree {
  private: 
    struct Node {
      int info = 0;
      int count = 1;
      Node *left = nullptr;
      Node *right = nullptr;

      Node(int info) :
        info(info) {};
    };

    Node *root = nullptr;
    void printNode(Node *node);
    void findByKeyInner(Node *root, int key);
    void printPostOrderInner(Node *root, int space);
  public:
    void findByKey(int key);
    void insert(int info);
    void printPostOrder();
    void printPreOrder();
    void remove();
};

void demo();

int main() {
  demo();

  return 0;
}

void demo() {
  Tree tree;
  tree.insert(5);
  tree.insert(2);
  tree.insert(14);
  tree.insert(4);
  tree.insert(8);
  tree.insert(7);
  tree.insert(4);
  tree.insert(1);
  tree.insert(15);
  tree.insert(17);
  tree.insert(0);
  // tree.findByKey(1);
  // tree.findByKey(11);
  // tree.findByKey(0);
  // tree.findByKey(23);
  // tree.findByKey(9);
  // tree.findByKey(-7);
  // tree.findByKey(10);
  // tree.findByKey(4);
  tree.printPostOrder();
}

void Tree::printNode(Node *node) {
  std::cout << "Data: " << node->info;
  std::cout << "    Count: " << node->count << "\n";
}

void Tree::findByKey(int key) {
  if (root == nullptr) return;
  findByKeyInner(root, key);
}

void Tree::findByKeyInner(Node *root, int key) {
  if (root->info == key) {
    printNode(root);
    return;
  } else if (root->info < key) {
    if (root->right == nullptr) return;
    findByKeyInner(root->right, key);
  } else {
    if (root->left == nullptr) return;
    findByKeyInner(root->left, key);
  }
}

void Tree::insert(int info) {
  if (root == nullptr) {
    root = new Node(info);
    return;
  }
  Node *current = root;
  while (true) {
    if (current->info == info) {
      current->count++;
      return;
    } else if (current->info < info) {
      if (current->right == nullptr) {
        current->right = new Node(info);
        return;
      }
      current = current->right;
    } else {
      if (current->left == nullptr) {
        current->left = new Node(info);
        return;
      }
      current = current->left;
    }
  }
}

void Tree::printPostOrder() {
  printPostOrderInner(root, 0);
}

void Tree::printPostOrderInner(Node *current, int space) {
  if (current == nullptr) return;
  printPostOrderInner(current->right, space + 4);
  for (int i = 0; i < space; i++) std::cout << " ";
  std::cout << current->info << std::endl;
  printPostOrderInner(current->left, space + 4);
}
#include <algorithm>
#include <iostream>
#include <string>

class AVLTree {
 private:
  struct Node {
    std::string word;
    int key, height;
    Node *left, *right;
    Node(std::string w, int k);
  };

  Node* root = nullptr;

  int height(Node* n);
  Node* rotateRight(Node* y);
  Node* rotateLeft(Node* x);
  Node* rebalance(Node* n);
  Node* insert(Node* n, std::string word, int key);
  Node* remove(Node* n, int key);
  void print(Node* n, int space);
  int findCountByCharInner(Node *n, char ch, int count);

 public:
  AVLTree();
  void insert(std::string word, int key);
  void remove(int key);
  void print();
  int findCountByChar(char ch);
};

AVLTree::Node::Node(std::string w, int k)
    : word(w), key(k), height(1), left(nullptr), right(nullptr) {}

AVLTree::AVLTree() : root(nullptr) {}

int AVLTree::height(Node* n) { return n ? n->height : 0; }

AVLTree::Node* AVLTree::rotateRight(Node* y) {
  Node* x = y->left;
  y->left = x->right;
  x->right = y;
  y->height = 1 + std::max(height(y->left), height(y->right));
  x->height = 1 + std::max(height(x->left), height(x->right));
  return x;
}

AVLTree::Node* AVLTree::rotateLeft(Node* x) {
  Node* y = x->right;
  x->right = y->left;
  y->left = x;
  x->height = 1 + std::max(height(x->left), height(x->right));
  y->height = 1 + std::max(height(y->left), height(y->right));
  return y;
}

AVLTree::Node* AVLTree::rebalance(Node* n) {
  n->height = 1 + std::max(height(n->left), height(n->right));
  int bf = height(n->left) - height(n->right);

  if (bf > 1) {
    if (height(n->left->left) < height(n->left->right))
      n->left = rotateLeft(n->left);
    return rotateRight(n);
  }
  if (bf < -1) {
    if (height(n->right->right) < height(n->right->left))
      n->right = rotateRight(n->right);
    return rotateLeft(n);
  }
  return n;
}

AVLTree::Node* AVLTree::insert(Node* n, std::string word, int key) {
  if (!n) return new Node(word, key);
  if (key < n->key)
    n->left = insert(n->left, word, key);
  else if (key > n->key)
    n->right = insert(n->right, word, key);
  return rebalance(n);
}

AVLTree::Node* AVLTree::remove(Node* n, int key) {
  if (!n) return nullptr;
  if (key < n->key)
    n->left = remove(n->left, key);
  else if (key > n->key)
    n->right = remove(n->right, key);
  else {
    if (!n->left || !n->right) {
      Node* child = n->left ? n->left : n->right;
      delete n;
      return child;
    }
    Node* s = n->right;
    while (s->left) s = s->left;
    n->key = s->key;
    n->word = s->word;
    n->right = remove(n->right, s->key);
  }
  return rebalance(n);
}

void AVLTree::print(Node* n, int space) {
  if (!n) return;
  print(n->right, space + 5);
  std::cout << std::string(space, ' ') << "[" << n->key << "] " << n->word
            << "\n";
  print(n->left, space + 5);
}

void AVLTree::insert(std::string word, int key) {
  root = insert(root, word, key);
}
void AVLTree::remove(int key) { root = remove(root, key); }
void AVLTree::print() { print(root, 0); }

int main() {
  AVLTree tree;

  tree.insert("banana", 30);
  tree.insert("apple", 10);
  tree.insert("apricot", 100);
  tree.insert("cherry", 20);
  tree.insert("date", 40);
  tree.insert("strawberry", 50);
  tree.insert("fig", 25);

  tree.print();

  tree.remove(30);
  std::cout << "\n";
  tree.print();

  char ch;
  std::cout << "Enter a char: ";
  std::cin >> ch;

  std::cout << "Count of nodes whose word starts with " << ch
  << ": " << tree.findCountByChar(ch) << std::endl;

  return 0;
}

int AVLTree::findCountByCharInner(Node *n, char ch, int count) {
  if (n == nullptr) return 0;
  count = findCountByCharInner(n->left, ch, count) +
  findCountByCharInner(n->right, ch, count);
  if (n->word[0] == ch) count++;
  return count;
}

int AVLTree::findCountByChar(char ch) {
  return findCountByCharInner(root, ch, 0);
}
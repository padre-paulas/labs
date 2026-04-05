#include <iostream>
#include <queue>
#include <set>
#include <iterator>
#include <algorithm>
#include <string>
#include <concepts> // C++20
// Only works with C++20 and up.
// Run clang++ -std=c++20 Lab6task2-2.cpp -o Lab6task2-2 && ./Lab6task2-2

struct Client {
  private:
    std::string name = "";
    double payment = 0;
  public:
    std::string getName() const { return name; }
    double getPayment() const { return payment; }
    Client(std::string name, double payment) 
      : name(name), payment(payment) {};
};

class ShopQueue {
  protected:
    int maxQueueSize = 1;
    bool shopClosed = true;
    double totalCash = 0;

    struct Owner {
      std::string name = "John Johnski";
      double fortune = 1000000;
    };
    Owner owner;

    void print() const;
    std::deque<Client> queue;
  public:
    void openShop();
    void closeShop();
    void goOnBreak(bool startBreak);
    void setMaxQueueSize(int size);
    virtual void addClient(std::string name, double payment);
    void processClient();
};

class ShopPriorityQueue: public ShopQueue {
  public:
    void addClient(std::string name, double payment) override;
};

void demo();

template <typename T> 
concept IsAnyShopQueue = 
std::same_as<T, ShopQueue> || std::same_as<T, ShopPriorityQueue>;

template <IsAnyShopQueue T>
void doQueueOperations(T& queue);

int main() {
  demo();
  return 0;
}

void ShopQueue::setMaxQueueSize(int size) {
  maxQueueSize = size;
}

void ShopQueue::openShop() {
  shopClosed = false;

}

void ShopQueue::goOnBreak(bool startBreak) {
  startBreak ? shopClosed = true : shopClosed = false;
}

void ShopQueue::addClient(std::string name, double payment) {
  if (!shopClosed) {
    if (queue.size() >= maxQueueSize) {
      std::cout << "Can't add to queue, max size exceeded\n";
      return;
    }
    Client client(name, payment);
    queue.push_back(client);
  } else {
    std::cout << "Can't add to queue, shop is closed!\n";
  }
  print();
}

void ShopQueue::processClient() {
  if (shopClosed) {
    std::cout << "Can't process the client, shop is closed!\n";
    return;
  }
  if (!shopClosed && !queue.empty()) {
    totalCash += queue.front().getPayment();
    std::cout << "Processed " << queue.front().getName()
    << ". Received: $" << queue.front().getPayment()
    << ". Total: $" << totalCash << std::endl;
    queue.pop_front();
  }
  print();
}

void ShopQueue::closeShop() {
  shopClosed = true;
  owner.fortune += totalCash;
  queue.clear();
  std::cout << "Shop is closed. "
  << owner.name << " got richer by $"
  << totalCash << ". \n";
  totalCash = 0;
}

void ShopQueue::print() const {
  if (queue.empty()) {
    std::cout << "\nQueue is empty!\n\n";
    return;
  }
  std::cout << "\n-- QUEUE STATUS --\n";
  std::cout << "First ⬇\n\n";
  for (auto it = queue.begin(); it != queue.end(); it++) {
    std::cout << "Name: " << it->getName()
    << ", payment: " << it->getPayment() << "\n";
  }
  std::cout << "\nLast ⬆\n\n";
}

void ShopPriorityQueue::addClient(std::string name, double payment) {
  if (!shopClosed) {

    if (queue.size() >= maxQueueSize) {
      std::cout << "Can't add to the queue, max size exceeded!\n";
      return;
    }
    Client newClient(name, payment);
    if (queue.size() == 0) queue.push_front(newClient);
    else {
      auto it = std::find_if(queue.begin(), queue.end(), [&](const Client& c) {
        return payment > c.getPayment();
      });
      queue.insert(it, newClient);
    }
  } else {
    std::cout << "Can't add to queue, shop is closed!\n";
  }
  print();
}

void demo() { 
  std::string choice;
  int maxSize;
  std::cout << "||||||||||| SHOP QUEUE MANAGEMENT |||||||||||\n"
  << "Do you want to use regular or priority queue? (reg/pri): ";
  std::cin >> choice;
  std::cout << "Enter max queue size: ";
  std::cin >> maxSize;

  if (choice == "reg") {
    ShopQueue shopQueue;
    shopQueue.setMaxQueueSize(maxSize);
    doQueueOperations(shopQueue);
  } else if (choice == "pri") {
    ShopPriorityQueue shopPriorityQueue;
    shopPriorityQueue.setMaxQueueSize(maxSize);
    doQueueOperations(shopPriorityQueue);
  } 
  std::cout << "|||||||||||||||||||||||||||||||||||||||||||||\n";
}

template <IsAnyShopQueue T>
void doQueueOperations(T& queue) {
  std::string choice;
  do {
    std::cout << "Choose an operation: (open, break, endBreak, add, process, close): ";
    std::cin >> choice;
    if (choice == "open") queue.openShop();
    else if (choice == "break") queue.goOnBreak(true);
    else if (choice == "endBreak") queue.goOnBreak(false);
    else if (choice == "process") queue.processClient();
    else if (choice == "close") queue.closeShop();
    else if (choice == "add") {
      std::string name;
      double payment;
      std::cout << "Enter client name: ";
      std::cin >> name;
      std::cout << "Enter client payment: ";
      std::cin >> payment;
      queue.addClient(name, payment);
    }

    std::cout << "Do you want to continue? (c/e): ";
    std::cin >> choice;
  } while (choice == "c");
}

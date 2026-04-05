#include <iostream>
#include <queue>
#include <set>
#include <iterator>
#include <algorithm>
#include <string>

class ShopQueue {
  protected:
    struct Client {
      std::string name = "";
      double payment = 0;
      Client(std::string name, double payment) 
        : name(name), payment(payment) {};
    };
    int maxQueueSize = 1;
    bool shopClosed = true;
    double totalCash = 0;

    struct Owner {
      std::string name = "John Johnski";
      double fortune = 1000000;
    };
    Owner owner;

    void print();
  private:
    std::deque<Client> queue;
  public:
    void openShop();
    virtual void closeShop();
    void goOnBreak(bool startBreak);
    void setMaxQueueSize(int size);
    virtual void addClient(std::string name, double payment);
    virtual void processClient();
};

class ShopPriorityQueue: public ShopQueue {
  private:
    struct Client: public ShopQueue::Client {
      int priority = 1;
      Client(std::string name, double payment, int priority)
        : ShopQueue::Client(name, payment), priority(priority) {};
      bool operator < (const Client& client) const {
        return this->priority < client.priority;
      }
    };
    std::multiset<Client> queue;
  public:
    void addClient(std::string name, double payment, int priority);
    void processClient();
    void closeShop();
    void print();
};

void demo();

int main() {

  // ShopQueue shopQueue;
  // shopQueue.setMaxQueueSize(30);
  // shopQueue.openShop();
  // shopQueue.addClient("Harry", 10.5);
  // shopQueue.addClient("Harry2", 10.5);
  // shopQueue.print();
  // shopQueue.processClient();
  // shopQueue.closeShop();

  // ShopPriorityQueue spq;
  // spq.setMaxQueueSize(20);
  // // spq.print();
  // spq.openShop();
  // spq.goOnBreak(true);
  // spq.addClient("harry3", 20, 2);
  // // spq.print();
  // spq.processClient();
  // spq.closeShop();
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
  if (!shopClosed) {
    totalCash += queue.front().payment;
    std::cout << "Processed " << queue.front().name
    << ". Received: $" << queue.front().payment
    << ". Total: $" << totalCash << std::endl;
    queue.pop_front();
  } else {
    std::cout << "Can't process the client, shop is closed!\n";
  }
  print();
}

void ShopQueue::closeShop() {
  shopClosed = true;
  owner.fortune += totalCash;
  while (queue.size() > 0) {
    queue.pop_back();
  }
  std::cout << "Shop is closed. "
  << owner.name << " got richer by $"
  << totalCash << ". \n";
  totalCash = 0;
}

void ShopQueue::print() {
  if (queue.size() < 1) {
    std::cout << "Queue is empty!\n";
    return;
  }
  std::cout << "-- QUEUE STATUS --:\n";
  std::deque<Client>::iterator it;
  std::cout << "First ⬇\n";
  for (it = queue.begin(); it < queue.end(); it++) {
    std::cout << "Name: " << it->name 
    << ", payment: " << it->payment << "\n\n";
  }
  std::cout << "Last ⬆\n\n";
}

void ShopPriorityQueue::print() {
  if (queue.size() < 1) {
    std::cout << "Queue is empty!\n";
    return;
  }
  std::cout << "-- QUEUE STATUS --:\n";
  std::multiset<Client>::iterator it;
  std::cout << "First ⬇\n";
  for (it = queue.begin(); *it < *queue.end(); it++) {
    std::cout << "Name: " << it->name 
    << ", payment: " << it->payment << "\n\n";
  }
  std::cout << "Last ⬆\n\n";
}

void ShopPriorityQueue::addClient(
  std::string name, 
  double payment, 
  int priority
) {
  if (!shopClosed) {
    if (queue.size() >= maxQueueSize) {
      std::cout << "Can't add to queue, max size exceeded\n";
      return;
    }
    Client client(name, payment, priority);
    queue.insert(client);
  } else {
    std::cout << "Can't add to queue, shop is closed!\n";
  }
  print();
}

void ShopPriorityQueue::processClient() {
  if (!shopClosed) {
    totalCash += queue.begin()->payment;
    std::cout << "Processed " << queue.begin()->name
    << ". Received: $" << queue.begin()->payment
    << ". Total: $" << totalCash << std::endl;
    queue.erase(*queue.rbegin());
  } else {
    std::cout << "Can't process the client, shop is closed!\n";
  }
  print();
}

void ShopPriorityQueue::closeShop() {
  shopClosed = true;
  owner.fortune += totalCash;
  while (queue.size() > 0) {
    queue.erase(queue.end());
  }
  std::cout << "Shop is closed. "
  << owner.name << " got richer by $"
  << totalCash << ". \n";
  totalCash = 0;
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
    ShopQueue queue;
    queue.setMaxQueueSize(maxSize);
    do {
      std::cout << "Choose an operation: (open, break, endBreak, add, setMax, process, close): ";
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

  } else if (choice == "pri") {
    ShopPriorityQueue queue;
    queue.setMaxQueueSize(maxSize);
    do {
      std::cout << "Choose an operation: (open, break, endBreak, add, setMax, process, close): ";
      std::cin >> choice;
      if (choice == "open") queue.openShop();
      else if (choice == "break") queue.goOnBreak(true);
      else if (choice == "endBreak") queue.goOnBreak(false);
      else if (choice == "process") queue.processClient();
      else if (choice == "close") queue.closeShop();
      else if (choice == "add") {
        std::string name;
        double payment;
        int priority;
        std::cout << "Enter client name: ";
        std::cin >> name;
        std::cout << "Enter client payment: ";
        std::cin >> payment;
        std::cout << "Enter client priority: ";
        std::cin >> priority;
        queue.addClient(name, payment, priority);
      }

      std::cout << "Do you want to continue? (c/e): ";
      std::cin >> choice;
    } while (choice == "c");
  }
  std::cout << "|||||||||||||||||||||||||||||||||||||||||||||\n";
}
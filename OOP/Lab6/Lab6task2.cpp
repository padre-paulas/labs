#include <iostream>
#include <queue>
#include <iterator>
#include <algorithm>
#include <string>

class ShopQueue {
  protected:
    struct Client {
      std::string name = "";
      double payment = 0;
      Client(std::string name, double payment) :
        name(name), payment(payment) {};
    };
    std::deque<Client> queue;
    int maxQueueSize = 1;
    bool shopClosed = true;
    double totalCash = 0;

    struct Owner {
      std::string name = "John Johnski";
      double fortune = 1000000;
    };
    Owner owner;

  public:
    void openShop();
    void closeShop();
    void goOnBreak(bool startBreak);
    void setMaxQueueSize(int size);
    void print();
    void addClient(std::string name, double payment);
    void processClient();
};

class ShopPriorityQueue: public ShopQueue {

};


int main() {

  ShopQueue shopQueue;
  shopQueue.setMaxQueueSize(30);
  shopQueue.openShop();
  shopQueue.addClient("Harry", 10.5);
  shopQueue.addClient("Harry2", 10.5);
  shopQueue.print();
  shopQueue.processClient();
  shopQueue.closeShop();


  return 0;
}

// ShopQueue::ShopQueue() 

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
  if (!shopClosed && queue.size() < maxQueueSize) {
    Client client(name, payment);
    queue.push_back(client);
  } else {
    std::cout << "Can't add to queue, shop is closed!\n";
  }
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
  std::deque<Client>::iterator it;
  std::cout << "First ⬇\n";
  for (it = queue.begin(); it < queue.end(); it++) {
    std::cout << "Name: " << it->name 
    << ", payment: " << it->payment << "\n\n";
  }
  std::cout << "Last ⬆\n";
}
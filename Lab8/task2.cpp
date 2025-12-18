#include <iostream>
#include <fstream>
#include <vector>

void readFile();
void addOrder();
void searchOrders();

struct Order
{
  std::string client;
  std::string language;
  int pageQuantity;
  std::string translator;
  std::string date;
  double price;
};
std::vector<Order> orders;

int main()
{

  readFile();
  addOrder();

  return 0;
}

void readFile()
{
  std::string fileName = "order.txt";
  std::ifstream file(fileName);

  if (!file)
  {
    std::cout << "File not found\n";
    return;
  }

  Order ord;

  while (file >> ord.client >> ord.language >> ord.pageQuantity >> ord.translator >> ord.date >> ord.price)
  {
    orders.push_back(ord);
  }

  for (const Order &o : orders)
  {
    std::cout << o.client << std::endl;
  }
}

void optionSwitch()
{
  int option;

  std::cout << "What would you like to do?" << std::endl;
  std::cout << "1 - add new order\n2 - search for an order\n3 - list the orders\n4 - modify order\n5 - sort orders" << std::endl;

  std::cin >> option;

  switch (option)
  {
  case 1:
    addOrder();
  case 2:
    searchOrders();
  // case 3:
  //   printOrders();
  // case 4:
  //   modifyOrder();
  // case 5:
  //   sortOrders();
  default:
    std::cout << "Invalid!\n";
  }
}

void addOrder()
{
  std::ofstream file("order.txt", std::ios::app);

  Order ord;

  std::cout << "Enter client name: ";
  std::cin >> ord.client;
  std::cout << "Enter language: ";
  std::cin >> ord.language;
  std::cout << "Enter page quantity: ";
  std::cin >> ord.pageQuantity;
  std::cout << "Enter translator name: ";
  std::cin >> ord.translator;
  std::cout << "Enter date: ";
  std::cin >> ord.date;
  std::cout << "Enter price: ";
  std::cin >> ord.price;

  file << " " << ord.client << " " << ord.language << " " << ord.pageQuantity << " " << ord.translator << " " << ord.date << " " << ord.price;
}

void searchOrders()
{
  int option;
  bool found = false;

  std::cout << "What would you like to search by?\n";
  std::cout << "1 - client name\n2 - language\n3 - page quantity\n4 - translator name\n5 - date\n6 - price\n";

  std::cin >> option;

  switch (option)
  {
  case 1:
  {
    std::string value;
    std::cout << "Enter client name: ";
    std::cin >> value;

    for (const Order &o : orders)
    {
      if (o.client == value)
      {
        std::cout << o.client << " " << o.language << " " << o.pageQuantity
                  << " " << o.translator << " " << o.date << " " << o.price << '\n';
        found = true;
      }
    }
    break;
  }

  case 2:
  {
    std::string value;
    std::cout << "Enter language: ";
    std::cin >> value;

    for (const Order &o : orders)
    {
      if (o.language == value)
      {
        std::cout << o.client << " " << o.language << " " << o.pageQuantity
                  << " " << o.translator << " " << o.date << " " << o.price << '\n';
        found = true;
      }
    }
    break;
  }

  case 3:
  {
    int pages;
    std::cout << "Enter page quantity: ";
    std::cin >> pages;

    for (const Order &o : orders)
    {
      if (o.pageQuantity == pages)
      {
        std::cout << o.client << " " << o.language << " " << o.pageQuantity
                  << " " << o.translator << " " << o.date << " " << o.price << '\n';
        found = true;
      }
    }
    break;
  }

  case 4:
  {
    std::string value;
    std::cout << "Enter translator name: ";
    std::cin >> value;

    for (const Order &o : orders)
    {
      if (o.translator == value)
      {
        std::cout << o.client << " " << o.language << " " << o.pageQuantity
                  << " " << o.translator << " " << o.date << " " << o.price << '\n';
        found = true;
      }
    }
    break;
  }

  case 5:
  {
    std::string value;
    std::cout << "Enter date: ";
    std::cin >> value;

    for (const Order &o : orders)
    {
      if (o.date == value)
      {
        std::cout << o.client << " " << o.language << " " << o.pageQuantity
                  << " " << o.translator << " " << o.date << " " << o.price << '\n';
        found = true;
      }
    }
    break;
  }

  case 6:
  {
    double price;
    std::cout << "Enter price: ";
    std::cin >> price;

    for (const Order &o : orders)
    {
      if (o.price == price)
      {
        std::cout << o.client << " " << o.language << " " << o.pageQuantity
                  << " " << o.translator << " " << o.date << " " << o.price << '\n';
        found = true;
      }
    }
    break;
  }

  default:
    std::cout << "Invalid option\n";
    return;
  }

  if (!found)
  {
    std::cout << "No matching orders found\n";
  }
}

#include <iostream>
#include <fstream>
#include <vector>

void readFile();
void addOrder();
void searchOrders();
void printOrders();

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
  optionSwitch();

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
  std::cout << "1 - add new order\n2 - search for an order\n3 - list the orders\n4 - modify order\n5 - delete order\n6 - sort orders" << std::endl;

  std::cin >> option;

  switch (option)
  {
  case 1:
    addOrder();
    break;
  case 2:
    searchOrders();
    break;
  case 3:
    printOrders();
    break;
  case 4:
    modifyOrder();
    break;
  case 5:
    deleteOrder();
    break;
  case 6:
    sortOrders();
    break;
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

void printOrders()
{
  std::ifstream file("order.txt");
  std::string output;

  while (file >> output)
  {
    std::cout << output;
  }
  std::cout << std::endl;
}

void modifyOrder()
{
  if (orders.empty())
  {
    std::cout << "No orders to modify\n";
    return;
  }

  int index;
  std::cout << "Enter order number (starting from 1): ";
  std::cin >> index;

  if (index < 1 || index > orders.size())
  {
    std::cout << "Invalid order number\n";
    return;
  }

  Order &o = orders[index - 1]; // reference to real order

  int option;
  std::cout << "What would you like to modify?\n";
  std::cout << "1 - client name\n"
            << "2 - language\n"
            << "3 - page quantity\n"
            << "4 - translator name\n"
            << "5 - date\n"
            << "6 - price\n";

  std::cin >> option;

  switch (option)
  {
  case 1:
    std::cout << "Enter new client name: ";
    std::cin >> o.client;
    break;
  case 2:
    std::cout << "Enter new language: ";
    std::cin >> o.language;
    break;
  case 3:
    std::cout << "Enter new page quantity: ";
    std::cin >> o.pageQuantity;
    break;
  case 4:
    std::cout << "Enter new translator name: ";
    std::cin >> o.translator;
    break;
  case 5:
    std::cout << "Enter new date: ";
    std::cin >> o.date;
    break;
  case 6:
    std::cout << "Enter new price: ";
    std::cin >> o.price;
    break;
  default:
    std::cout << "Invalid option\n";
    return;
  }

  std::ofstream file("order.txt");
  for (const Order &ord : orders)
  {
    file << ord.client << " "
         << ord.language << " "
         << ord.pageQuantity << " "
         << ord.translator << " "
         << ord.date << " "
         << ord.price << '\n';
  }

  std::cout << "Order updated successfully\n";
}

void deleteOrder() {

}

void sortOrders() {
  std::cout << "What would you like to sort by?\n";
  std::cout << "1 - client name\n"
            << "2 - language\n"
            << "3 - page quantity\n"
            << "4 - translator name\n"
            << "5 - date\n"
            << "6 - price\n";
}
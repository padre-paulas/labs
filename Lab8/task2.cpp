#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

void readFile();
void addOrder();
void searchOrders();
void printOrders();
void modifyOrder();
void deleteOrder();
void sortOrders();
void optionSwitch();
void saveToFile();

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
  
  while (true)
  {
    optionSwitch();
    
    char cont;
    std::cout << "\nContinue? (y/n): ";
    std::cin >> cont;
    if (cont != 'y' && cont != 'Y')
      break;
  }

  return 0;
}

void readFile()
{
  std::string fileName = "order.txt";
  std::ifstream file(fileName);

  if (!file)
  {
    std::cout << "No existing orders file found. Starting fresh.\n";
    return;
  }

  Order ord;

  while (file >> ord.client >> ord.language >> ord.pageQuantity >> ord.translator >> ord.date >> ord.price)
  {
    orders.push_back(ord);
  }

  std::cout << "Loaded " << orders.size() << " orders from file.\n\n";
}

void saveToFile()
{
  std::ofstream file("order.txt");
  
  if (!file)
  {
    std::cout << "Error: Could not save to file\n";
    return;
  }

  for (const Order &ord : orders)
  {
    file << ord.client << " "
         << ord.language << " "
         << ord.pageQuantity << " "
         << ord.translator << " "
         << ord.date << " "
         << ord.price << '\n';
  }
}

void optionSwitch()
{
  int option;

  std::cout << "\n=== ORDER MANAGEMENT SYSTEM ===\n";
  std::cout << "What would you like to do?\n";
  std::cout << "1 - Add new order\n";
  std::cout << "2 - Search for an order\n";
  std::cout << "3 - List all orders\n";
  std::cout << "4 - Modify order\n";
  std::cout << "5 - Delete order\n";
  std::cout << "6 - Sort orders\n";
  std::cout << "Choice: ";

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
    std::cout << "Invalid option!\n";
  }
}

void addOrder()
{
  Order ord;

  std::cout << "\n--- Add New Order ---\n";
  std::cout << "Enter client name: ";
  std::cin >> ord.client;
  std::cout << "Enter language: ";
  std::cin >> ord.language;
  std::cout << "Enter page quantity: ";
  std::cin >> ord.pageQuantity;
  std::cout << "Enter translator name: ";
  std::cin >> ord.translator;
  std::cout << "Enter date (YYYY-MM-DD): ";
  std::cin >> ord.date;
  std::cout << "Enter price: ";
  std::cin >> ord.price;

  orders.push_back(ord);
  saveToFile();
  
  std::cout << "Order added successfully!\n";
}

void searchOrders()
{
  if (orders.empty())
  {
    std::cout << "No orders available\n";
    return;
  }

  int option;
  bool found = false;

  std::cout << "\n--- Search Orders ---\n";
  std::cout << "Search by:\n";
  std::cout << "1 - Client name\n";
  std::cout << "2 - Language\n";
  std::cout << "3 - Page quantity\n";
  std::cout << "4 - Translator name\n";
  std::cout << "5 - Date\n";
  std::cout << "6 - Price\n";
  std::cout << "Choice: ";

  std::cin >> option;

  switch (option)
  {
  case 1:
  {
    std::string value;
    std::cout << "Enter client name: ";
    std::cin >> value;

    for (size_t i = 0; i < orders.size(); i++)
    {
      if (orders[i].client == value)
      {
        std::cout << "\n[" << (i + 1) << "] " << orders[i].client << " | " << orders[i].language << " | " 
                  << orders[i].pageQuantity << " pages | " << orders[i].translator << " | " 
                  << orders[i].date << " | $" << orders[i].price << '\n';
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

    for (size_t i = 0; i < orders.size(); i++)
    {
      if (orders[i].language == value)
      {
        std::cout << "\n[" << (i + 1) << "] " << orders[i].client << " | " << orders[i].language << " | " 
                  << orders[i].pageQuantity << " pages | " << orders[i].translator << " | " 
                  << orders[i].date << " | $" << orders[i].price << '\n';
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

    for (size_t i = 0; i < orders.size(); i++)
    {
      if (orders[i].pageQuantity == pages)
      {
        std::cout << "\n[" << (i + 1) << "] " << orders[i].client << " | " << orders[i].language << " | " 
                  << orders[i].pageQuantity << " pages | " << orders[i].translator << " | " 
                  << orders[i].date << " | $" << orders[i].price << '\n';
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

    for (size_t i = 0; i < orders.size(); i++)
    {
      if (orders[i].translator == value)
      {
        std::cout << "\n[" << (i + 1) << "] " << orders[i].client << " | " << orders[i].language << " | " 
                  << orders[i].pageQuantity << " pages | " << orders[i].translator << " | " 
                  << orders[i].date << " | $" << orders[i].price << '\n';
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

    for (size_t i = 0; i < orders.size(); i++)
    {
      if (orders[i].date == value)
      {
        std::cout << "\n[" << (i + 1) << "] " << orders[i].client << " | " << orders[i].language << " | " 
                  << orders[i].pageQuantity << " pages | " << orders[i].translator << " | " 
                  << orders[i].date << " | $" << orders[i].price << '\n';
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

    for (size_t i = 0; i < orders.size(); i++)
    {
      if (orders[i].price == price)
      {
        std::cout << "\n[" << (i + 1) << "] " << orders[i].client << " | " << orders[i].language << " | " 
                  << orders[i].pageQuantity << " pages | " << orders[i].translator << " | " 
                  << orders[i].date << " | $" << orders[i].price << '\n';
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
  if (orders.empty())
  {
    std::cout << "No orders to display\n";
    return;
  }

  std::cout << "\n=== ALL ORDERS ===\n";
  for (size_t i = 0; i < orders.size(); i++)
  {
    std::cout << "[" << (i + 1) << "] " << orders[i].client << " | " << orders[i].language << " | " 
              << orders[i].pageQuantity << " pages | " << orders[i].translator << " | " 
              << orders[i].date << " | $" << orders[i].price << '\n';
  }
}

void modifyOrder()
{
  if (orders.empty())
  {
    std::cout << "No orders to modify\n";
    return;
  }

  printOrders();

  int index;
  std::cout << "\nEnter order number to modify: ";
  std::cin >> index;

  if (index < 1 || index > static_cast<int>(orders.size()))
  {
    std::cout << "Invalid order number\n";
    return;
  }

  Order &o = orders[index - 1];

  int option;
  std::cout << "\nWhat would you like to modify?\n";
  std::cout << "1 - Client name\n";
  std::cout << "2 - Language\n";
  std::cout << "3 - Page quantity\n";
  std::cout << "4 - Translator name\n";
  std::cout << "5 - Date\n";
  std::cout << "6 - Price\n";
  std::cout << "Choice: ";

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

  saveToFile();
  std::cout << "Order updated successfully!\n";
}

void deleteOrder()
{
  if (orders.empty())
  {
    std::cout << "No orders to delete\n";
    return;
  }

  printOrders();

  int index;
  std::cout << "\nEnter order number to delete: ";
  std::cin >> index;

  if (index < 1 || index > static_cast<int>(orders.size()))
  {
    std::cout << "Invalid order number\n";
    return;
  }

  char confirm;
  std::cout << "Are you sure you want to delete this order? (y/n): ";
  std::cin >> confirm;

  if (confirm == 'y' || confirm == 'Y')
  {
    orders.erase(orders.begin() + index - 1);
    saveToFile();
    std::cout << "Order deleted successfully!\n";
  }
  else
  {
    std::cout << "Deletion cancelled\n";
  }
}

void sortOrders()
{
  if (orders.empty())
  {
    std::cout << "No orders to sort\n";
    return;
  }

  int option;
  std::cout << "\n--- Sort Orders ---\n";
  std::cout << "Sort by:\n";
  std::cout << "1 - Client name\n";
  std::cout << "2 - Language\n";
  std::cout << "3 - Page quantity\n";
  std::cout << "4 - Translator name\n";
  std::cout << "5 - Date\n";
  std::cout << "6 - Price\n";
  std::cout << "Choice: ";

  std::cin >> option;

  switch (option)
  {
  case 1:
    std::sort(orders.begin(), orders.end(), 
              [](const Order &a, const Order &b) { return a.client < b.client; });
    break;
  case 2:
    std::sort(orders.begin(), orders.end(), 
              [](const Order &a, const Order &b) { return a.language < b.language; });
    break;
  case 3:
    std::sort(orders.begin(), orders.end(), 
              [](const Order &a, const Order &b) { return a.pageQuantity < b.pageQuantity; });
    break;
  case 4:
    std::sort(orders.begin(), orders.end(), 
              [](const Order &a, const Order &b) { return a.translator < b.translator; });
    break;
  case 5:
    std::sort(orders.begin(), orders.end(), 
              [](const Order &a, const Order &b) { return a.date < b.date; });
    break;
  case 6:
    std::sort(orders.begin(), orders.end(), 
              [](const Order &a, const Order &b) { return a.price < b.price; });
    break;
  default:
    std::cout << "Invalid option\n";
    return;
  }

  saveToFile();
  std::cout << "Orders sorted successfully!\n";
  printOrders();
}
#include <iostream>
#include <sstream>
#include <fstream>
#include "queue.h"

void readFile(Product &, Queue &);
void check(Product &, Queue &);
void addProduct(Product &, Queue &);
void saleProduct(Product &, Queue &);


int main() {
  Queue prod;
  Product data;
  readFile(data, prod);
  int key;
  
  do {
    std::cout << "----------------MENU----------------" << std::endl;
    std::cout << "(1) - Add products to the warehouse" << std::endl;
    std::cout << "(2) - Sale products" << std::endl;
    std::cout << "(3) - Check the warehouse" << std::endl;
    std::cout << "(4) - Info" << std::endl;
    std::cout << "(0) - Escape" << std::endl;
    std::cout << "------------------------------------" << std::endl;

    std::cout << "--->  ";
    std::cin >> key;
    std::cout << std::endl;

    switch(key) {
      case 1: addProduct(data, prod); break;
      case 2: saleProduct(data, prod); break;
      case 3: check(data, prod); break;
      case 4: prod.info(); break;
      default: std::cout << "Error! Try again!" << std::endl;
      case 0: return 0;
    }
  } while (key);
}

void readFile(Product &data, Queue &prod) {
  std::ifstream file("whdata");
  std::string line;

  while (getline(file, line)) {
    std::istringstream fileLine(line);
    fileLine >> data.amount >> data.price;
    prod.push(data);
  }
  file.close();
}

void check(Product &data, Queue &prod) {
  if(!prod.first) {
    std::cout << "The warehouse is empty!" << std::endl;
  }
  else{
    Queue tempQueue;
    long tempAmount{};
    double tempPrice{};
    while(prod.count) {
      prod.pop(data);
      tempAmount += data.amount;
      tempPrice += data.price * data.amount;
      tempQueue.push(data);
    }
    std::cout << ">-------------------------<" << std::endl;
    std::cout << "Total number of products: " << tempAmount << std::endl;
    std::cout << "Total price of products: " << tempPrice << std::endl;
    std::cout << "Profit: " << prod.profit << std::endl;
    std::cout << ">-------------------------<\n" << std::endl;
    while (tempQueue.count) {
      tempQueue.pop(data);
      prod.push(data);
    }
  }
}

void addProduct(Product &data, Queue &prod) {
  std::cout << std::endl;
  std::cout << "New product amount: ";
  std::cin >> data.amount;
  std::cout << std::endl; 
  std::cout << "New product price: "; 
  std::cin >> data.price;
  std::cout << std::endl;

  prod.push(data);

  std::cout << "Products added" << std::endl;
}

void saleProduct(Product &data, Queue &prod) {
  int productAmount = prod.first->data.amount;
  double extraCharge;

  std::cout << "Ammount of product for sale: " << productAmount;
  std::cout << std::endl;

  std::cout << "Enter extra charge: ";
  std::cin >> extraCharge;

  double salePrice = prod.first->data.price + extraCharge;
  std::cout << "Sale price per unit: " << salePrice;
  std::cout << std::endl;

  int request;
  std::cout << "Enter number of prudects for sale: ";
  std::cin >> request;
  std::cout << std::endl;

  if (request < productAmount) {
    prod.first->data.amount -= request;
    prod.profit += request * extraCharge;    
  } 
  else {
    std::cout << "WARNING!" << std::endl;
    std::cout << "You have requested a quantity equal to or greater" << 
    " than the available quantity" << "\nAll products will be sold!" << std::endl;
    std::cout << "->n - cancel\n->y - continue" << std::endl;
    char w;
    std::cin >> w;
    if(w == 'y') {
      
      prod.profit += prod.first->data.amount * extraCharge;
      prod.first->data.amount = 0;
      prod.pop(data);
      if (prod.count) {
        data = prod.first->data;
      }
      std::cout << "This product group was completely sold out!" << std::endl;
    }
    else {
      std::cout << "\n\t\tThe operation was canceled.\n" << std::endl;
    }
  }
}


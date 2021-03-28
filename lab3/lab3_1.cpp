#include <iostream>
#include <fstream>
#include <sstream>
#include "stack.h"

void readFile(Ball &, Stack &);
void addBall(Ball &, Stack &);
void removeBall(Ball &, Stack &);
void clearStack(Ball &, Stack &);
void viewCart (Ball &, Stack &);

int main() {
  Ball data;
  Stack balls;
  readFile(data, balls);
  
  int key;
  
  do {
    std::cout << "----------------MENU----------------" << std::endl;
    std::cout << "(1) - Add ball to the cart" << std::endl;
    std::cout << "(2) - Remove ball from the catr" << std::endl;
    std::cout << "(3) - Clear the cart" << std::endl;
    std::cout << "(4) - View the cart" << std::endl;
    std::cout << "(0) - Escape" << std::endl;
    std::cout << "------------------------------------" << std::endl;

    std::cout << "--->  ";
    std::cin >> key;
    std::cout << std::endl;

    switch(key) {
      case 1: addBall(data, balls); break;
      case 2: removeBall(data, balls); break;
      case 3: clearStack(data, balls); break;
      case 4: viewCart(data, balls); break;
      default: std::cout << "Error! Try again!" << std::endl;
      case 0: return 0;
    }
  } while (key);

}

void readFile(Ball &data, Stack &S) {
  std::ifstream file("balls");
  std::string line;

  while (getline(file, line)) {
    std::istringstream fileLine(line);
    fileLine >> data.man >> data.sportType >> data.color >> data.size;
    S.push(data);
  }
  file.close();
}

void addBall(Ball &data, Stack &balls) {
  std::cout << "Enter ball specifications: " << std::endl;
  std::cout << "Manufacturer --> ";
  std::cin >> data.man;
  std::cout << "Sport type --> ";
  std::cin >> data.sportType;
  std::cout << "Color --> ";
  std::cin >> data.color;
  std::cout << "Size --> ";
  std::cin >> data.size;

  balls.push(data);
}

void removeBall(Ball &data, Stack &balls) {
  Stack tempStack;
  Ball tempData;

  std::cout << "Enter ball specifications: " << std::endl;
  std::cout << "Manufacturer --> ";
  std::cin >> tempData.man;
  std::cout << "Sport type --> ";
  std::cin >> tempData.sportType;
  std::cout << "Color --> ";
  std::cin >> tempData.color;
  std::cout << "Size --> ";
  std::cin >> tempData.size;

  bool flag = false;

  while (balls.count) {
    balls.pop(data);
    
    if (data.man != tempData.man || data.sportType != tempData.sportType ||
    data.color != tempData.color || data.size != tempData.size) {
      tempStack.push(data);
    }
    else {
      std::cout << "Ball is removed" << std::endl;
      flag = true;
    }
  }

  if(flag) {
    while (tempStack.count) {
      tempStack.pop(data);
      balls.push(data);
    } 
  }
  else {
    std::cout << "No such ball found" << std::endl;
  }
}

void clearStack(Ball &data, Stack &balls) {
  if (balls.count) {
    while (balls.count) {
      balls.pop(data);
    }
    std::cout << "Now cart is empty" << std::endl;
  } 
  else {
    std::cout << "Cart is already empty!" << std::endl; 
  }
}

void viewCart (Ball &data, Stack &balls) {
  Stack tempStack;
  if (balls.count) {
    int count_l = 1;
    while (balls.count) {
      balls.pop(data);
      std::cout << "\n------------(" << count_l << ")------------" << std::endl;
      std::cout << "Manufacturer:" << data.man << std::endl;
      std::cout << "Sport type:" << data.sportType << std::endl;
      std::cout << "Color:" << data.color << std::endl;
      std::cout << "Size:" << data.size << std::endl;
      std::cout << "---------------------------" << std::endl;
      tempStack.push(data);
      count_l++;
    }
    while(tempStack.count) {
      tempStack.pop(data);
      balls.push(data);
    }
  }
  else {
    std::cout << "The cart is empty!" << std::endl;
  }
}
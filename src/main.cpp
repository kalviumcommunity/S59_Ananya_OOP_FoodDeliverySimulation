#include <iostream>
#include <string>
#include "User.cpp"
#include "Order.cpp"
using namespace std;

int main() { 
  string u, p;
  int n;

  cout << "Welcome to this food delivery simulation!" << endl << "Enter your user details" << endl;

  cout << "Username: ";
  cin >> u;
  cout << "Password: ";
  cin >> p;

  User user1(u, p);
  user1.displayUserDetails();

  cout << "Enter the number of orders: ";
  cin >> n;
  cin.ignore(); 

  Order* orders = new Order[n];

  for (int i = 0; i < n; ++i) {
    string o;
    cout << "Enter details for order " << (i + 1) << endl;
    cout << "Order Details: ";
    getline(cin, o);
    orders[i] = Order(i + 1, o);
  }

  cout << endl << "Order Details:" << endl;
  for (int i = 0; i < n; ++i) {
    orders[i].displayOrderDetails();
  }

  return 0;
}

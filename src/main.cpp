#include <iostream>
#include <string>
#include "User.cpp"
#include "Order.cpp"
using namespace std;

int main() { 
  int n, role;

  cout << "Welcome to this food delivery simulation!\nCreate an account to access all features" << endl;

  //this is to know who is trying to enter (customer or owner)
  cout << "Choose your role:\n 1. Customer\n 2. Restaurant Owner\nEnter your choice: ";
  cin >> role;

  //if they are a customer
  if (role == 1) {
    string user, pass;
    cout << "Enter username for Customer: ";
    cin >> user;
    cout << "Enter password for Customer: ";
    cin >> pass;

    //dynamically allocating memory
    Customer* customer = new Customer(user, pass);
    customer -> login();
    customer -> displayUserDetails();
    
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

    //erasing memory
    delete[] orders;
    delete customer;
  }

  //if they are an owner
  else if (role == 2) {
    string user, pass, restaurant;
    int secret;
    cout << "Enter username for Restaurant Owner: ";
    cin >> user;
    cout << "Enter password for Restaurant Owner: ";
    cin >> pass;
    cin.ignore();
    cout << "Enter your restaurant name: ";
    getline(cin, restaurant);
    cout << "Enter your secret code: ";
    cin >> secret;

    //dynamically alloting memory
    RestaurantOwner* owner = new RestaurantOwner(user, pass, restaurant, secret);
    owner -> login();
    owner -> displayUserDetails();

    //erasing memory
    delete owner;
  }

  return 0;
}

#include <iostream>
#include <string>
using namespace std;

class User {
  private:
    string username;
    string password;

  public:
    User(string u, string p) {
      username = u;
      password = p;
    }

    void setPassword(string p) {
      password = p;
    }

    string getUsername() {
      return username;
    }

    string getPassword() {
      return password;
    }

    void displayUserDetails() {
      cout << "Username: " << username << endl;
    }
};

class Order {
  private:
    int orderId;
    string orderDetails;
    string status;

  public:
    Order(int id, string details) {
      orderId = id;
      orderDetails = details;
      status = "Placed";
    }

    void updateStatus(string newStatus) {
      status = newStatus;
    }

    string getOrderDetails() {
      return orderDetails;
    }

    string getStatus() {
      return status;
    }

    int getOrderId() {
      return orderId;
    }

    void displayOrderDetails() {
      cout << "Order ID: " << orderId << endl;
      cout << "Order Details: " << orderDetails << endl;
      cout << "Order Status: " << status << endl;
    }
};

int main() {

  string u, p, o;

  cout << "Welcome to this food delivery simulation !" << endl << "Enter your user details" << endl;

  cout << "Username: ";
  cin >> u;
  cout << endl;

  cout << "Password: ";
  cin >> p;
  cout << endl;        

  User user1(u, p);
  user1.displayUserDetails();

  cout << "Place an order !" << endl;
  cin.ignore();
  cout << "Order Details: ";
  getline(cin, o);

  Order order1(1, o);  
  order1.displayOrderDetails();

  return 0;
}

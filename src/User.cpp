#include <iostream>
#include <string>
using namespace std;

class User {
protected:
    string username;
    string password;
    string role;

public:
    User(string username, string password, string role) {
        this -> username = username;
        this -> password = password;
        this -> role = role;
    }
    //destructor
    virtual ~User() {}

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

    void login() {
        string user, pass;
        cout << "Enter username to login: ";
        cin >> user;
        cout << "Enter password for verification: ";
        cin >> pass;

        if (user == getUsername() && pass == getPassword()) {
            cout << "Login successful! Logged in as " << role << endl;
        } 
        else {
            cout << "Login failed! Incorrect credential(s)" << endl;
            exit(0);
        }
    }
};

class Customer : public User {
private:
    static int orderCounter;
    static int numberOfOrders;
public:
    Customer(string username, string password) : User(username, password, "Customer") {}
    //destructor
    ~Customer() {}

    static int getTotalOrders() { return numberOfOrders; }

    void placeOrder() {
        orderCounter++;
        numberOfOrders++;
        cout << "Order placed successfully! Total orders by all customers: " << getTotalOrders() << endl;
    }
};

int Customer :: orderCounter = 0;
int Customer :: numberOfOrders = 0;

class RestaurantOwner : public User {
private:
    int secretCode;
    string restaurantName;

public:
    RestaurantOwner(string username, string password, string restaurant, int secret) : User(username, password, "RestaurantOwner"), restaurantName(restaurant), secretCode(secret) {}
    //destructor
    ~RestaurantOwner() {}
};
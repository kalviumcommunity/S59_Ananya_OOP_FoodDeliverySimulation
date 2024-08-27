#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include "Order.cpp"
using namespace std;

class User {
protected:
    string username;
    string password;
    string role;

public:
    //example of polymorphism - constructor overloading
    User(){} //default constructor
    User(string uname, string pwd, string r) : username(uname), password(pwd), role(r) {} //parameterized
    ~User(){} //destructor

    virtual void login() {
        string inputUsername, inputPassword;
        cout << "Enter username to login: ";
        cin >> inputUsername;
        cout << "Enter password to login: ";
        cin >> inputPassword;

        if (inputUsername == username && inputPassword == password) cout << "Login successful! Logged in as: " << role << endl;
        else {
            cout << "Login failed! Incorrect username or password." << endl;
            exit(0);
        }
    }
    //accessors (getter methods)
    string getRole() {return role;}
    string getUsername() {return username;}
};

//hierarchial inheritance where multiple classes inherit from one class
class Customer : public User {  //first class customer in herits from user
private:
    vector<Order> orderHistory;
    static int orderCounter; //static member variable declaration

public:
    Customer(string uname, string pwd) : User(uname, pwd, "Customer") {}

    void browseMenu(map<string, vector<string>>& arr) {
        cout << "Available Restaurants and their menus:" << endl;
        int i = 1;
        for (auto& a : arr) {
            cout << i++ << ". " << a.first << "'s Menu:" << endl;
            int j = 1;
            for (auto& foodchoice : a.second) {
                cout << "   " << j++ << ". " << foodchoice << endl;
            }
            cout << endl;
        }
    }

    void placeOrder(map<string, vector<string>>& restaurants) {
        int rest, foodchoice;
        cout << "Choose a restaurant by number: ";
        cin >> rest;

        if (rest < 1 || rest > restaurants.size()) {
            cout << "Invalid choice" << endl;
            return;
        }

        int j = 1;
        string restaurant;
        for (auto& i : restaurants) {
            if (j == rest) {
                restaurant = i.first;
                break;
            }
            j++;
        }

        cout << "Choose a food item by number from " << restaurant << "'s menu: ";
        cin >> foodchoice;

        if (foodchoice < 1 || foodchoice > restaurants[restaurant].size()) {
            cout << "Invalid menu item choice" << endl;
            return;
        }

        string item = restaurants[restaurant][foodchoice - 1];
        cout << "Order placed for " << item << " from " << restaurant << endl;

        Order newOrder(orderCounter++, username, restaurant, item);
        orderHistory.push_back(newOrder);
    }

    void trackOrderStatus() {
        if (orderHistory.empty()) {
            cout << "No orders placed yet" << endl;
            return;
        }

        cout << "Your Order History:" << endl;
        for (auto& o : orderHistory) {
            cout << "Order ID: " << o.getOrderId() << ", Restaurant: " << o.getRestaurantName() << ", Item: " << o.getFoodItem() << ", Status: " << o.getStatus() << endl;
        }
    }
};

int Customer::orderCounter = 0; //static member initialization

//example of hierarchial inheritance, second class inheriting from the same base class
class RestaurantOwner : public User { //second class restaurant owner inherits from the user class
private:
    string restaurantName;
    int secretCode;

public:
    RestaurantOwner(string uname, string pwd, string restName, int sCode) : User(uname, pwd, "RestaurantOwner"), restaurantName(restName), secretCode(sCode) {}

    bool verifySecretCode() {
        int code;
        cout << "Enter secret code: ";
        cin >> code;
        return code == secretCode;
    }

    void viewMenuItems(map<string, vector<string>>& restaurants) {
        cout << "Menu items for " << restaurantName << ":" << endl;
        int j = 1;
        for (const auto& item : restaurants[restaurantName]) {
            cout << j++ << ". " << item << endl;
        }
        if (restaurants.size() == 0) {
            cout << "No items were found" << endl;
        }
    }

    void addMenuItem(map<string, vector<string>>& restaurants) {
        if (verifySecretCode()) {
            string item;
            cout << "Enter menu item to add: ";
            cin.ignore();
            getline(cin, item);
            restaurants[restaurantName].push_back(item);
            cout << "Menu item " << item << " added to " << restaurantName << "'s menu" << endl;
        } 
        
        else cout << "Secret code incorrect, can't add menu item" << endl;
    }
};

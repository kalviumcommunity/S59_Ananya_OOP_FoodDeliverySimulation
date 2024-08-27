#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class Order {
private:
    int orderId;
    string customerName;
    string foodItem;
    string restaurantName;
    string status;

public:
    Order(){} //default constructor
    //parameterised constructor
    Order(int id, string cname, string rname, string item) : orderId(id), customerName(cname), restaurantName(rname), foodItem(item), status("Placed") {}
    ~Order(){} //destructor

    void updateOrderStatus(string newStatus) {
        status = newStatus;
        cout << "Order " << orderId << " status updated to: " << status << endl;
    }
    //accessors(getter methods)
    string getStatus() { return status; }
    int getOrderId() { return orderId; }
    string getFoodItem() { return foodItem; }
    string getRestaurantName() { return restaurantName; }
    void displayOrderDetails() {
        cout << "Order ID: " << getOrderId() << endl;
        cout << "Order Details: " << getFoodItem() << endl;
        cout << "Order Status: " << getStatus() << endl;
    }
};

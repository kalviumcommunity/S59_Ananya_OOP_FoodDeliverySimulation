#include <iostream>
#include <string>
using namespace std;

class Order {
private:
    int orderId;
    string orderDetails;
    string status;

public:
    Order() {}
    Order(int orderId, string orderDetails) {
        this->orderId = orderId;
        this->orderDetails = orderDetails;
        this->status = "Placed";
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

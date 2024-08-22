#include <iostream>
#include <string>
using namespace std;

class Order {
private: //private access specifier used
    int orderId;

protected: //protected access specifier usedd
    string orderDetails;
    string status;

public: //public access specifier used

    //default constructor
    Order() {}
    //parameterized constructor
    Order(int orderId, string orderDetails) {
        this->orderId = orderId;
        this->orderDetails = orderDetails;
        this->status = "Placed";
    }
    //destructor
    ~Order() {}

    //mutator(setter methods)
    void updateStatus(string newStatus) {
        status = newStatus;
    }

    void setOrderDetails(string details) {
        orderDetails = details;
    }

    //accessors(getter methods))
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
        cout << "Order ID: " << getOrderId() << endl;
        cout << "Order Details: " << getOrderDetails() << endl;
        cout << "Order Status: " << getStatus() << endl;
    }
};

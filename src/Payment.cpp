#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class Payment {
public:
    virtual void processPayment() {
        int choice;
        cout << "Choose payment method:\n1. Cash on Delivery\n2. Online Payment\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Payment method selected: Cash on Delivery" << endl;
            cout << "Payment successful! Your order is on the way" << endl;
            break;
        case 2:
            processOnlinePayment();
            break;
        default:
            cout << "Invalid payment choice" << endl;
        }
    }
    virtual void processOnlinePayment() { }
};

//example of single inheritance
class OnlinePayment : public Payment { //OnlinePayment class inherits from Payment class single handedly
public:
    void processOnlinePayment() override {
        int choice;
        cout << "Choose online payment method:\n1. Debit Card\n2. PayPal\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Processing payment through: Debit Card" << endl;
            break;
        case 2:
            cout << "Processing payment through: PayPal" << endl;
            break;
        default:
            cout << "Invalid payment choice" << endl;
            return;
        }
        cout << "Payment successful! Your order is on the way" << endl;
    }
};
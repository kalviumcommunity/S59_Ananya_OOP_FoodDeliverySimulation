#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

//has use of SOLID principle 2
//payment class is open to extension but closed to modification
//if I need to add more methods, I can simply extend more classes from it without modifying the current one
class Payment {
public:
    virtual void processPayment(int choice) {
        if (choice == 1) {
            cout << "Payment method selected: Cash on Delivery" << endl;
            cout << "Payment successful! Your order is on the way" << endl;
        } 
        else if (choice == 2) processOnlinePayment();
        else cout << "Invalid payment choice" << endl;
    }

    virtual void processOnlinePayment() {
        cout << "Processing online payment.." << endl;
    }
};

class OnlinePayment : public Payment {
public:
    void processOnlinePayment() override {
        int choice;
        cout << "Choose online payment method:\n1. Debit Card\n2. Google Pay\nEnter choice: ";
        cin >> choice;

        if (choice == 1) cout << "Processing payment through: Debit Card" << endl;
        else if (choice == 2) cout << "Processing payment through: Google Pay" << endl;
        else {
            cout << "Invalid payment choice" << endl;
            return;
        }
        cout << "Payment successful! Your order is on the way" << endl;
    }
};
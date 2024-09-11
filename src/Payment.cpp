#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

//payment class shows SOLID-3 LSP principle that talks about a superclass being replaceable with its subclass
//this replacement shouldn't affect the functioning of the program in any way

//the class OnlinePayment(derived) can be substituted wherever the Payment class (base) is expected
//this won't negatively affect the program hence also demonstrating the presence of LSP in the code
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
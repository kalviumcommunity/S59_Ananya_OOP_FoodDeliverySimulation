#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include "User.cpp"
#include "Payment.cpp"
using namespace std;

int main() { 
    map<string, vector<string>> restaurants = { //list of all
        {"Pasta Palace", {"Spaghetti", "Lasagne", "Macaroni Cheese"}},
        {"Burger King", {"Classic Burger", "Cheese Burger", "Spicy Paneer Burger"}},
        {"Pizza Hut", {"Margherita", "Pepperoni", "Paneer and Onion"}},
        {"Sushi Town", {"Sashimi", "Temaki", "Salmon Nigiri"}},
        {"Taco Bell", {"Classic Taco", "Paneer Taco", "Vegan Taco"}}
    };

    //welcome message 
    cout << "Welcome to the Virtual Food Delivery System! Create an account to access all features" << endl;
    cout << "Choose your role:\n1. Customer\n2. Restaurant Owner\nEnter your choice: ";
    int role; //to know who is trying to enter
    cin >> role;

    if (role == 1) {//for customer
        string user, pass;
        cout << "Create a username: ";
        cin >> user;
        cout << "Create a password: ";
        cin >> pass;
        Customer customer1(user, pass); //creating an account
        customer1.login(); //verifying credentials

        while (true) {
            int choice;
            cout << "\n1. Browse Menu\n2. Place Order\n3. Track Order Status\n4. Exit\nEnter your choice: ";
            cin >> choice;

            if (choice == 1) customer1.browseMenu(restaurants);
            else if (choice == 2) {
                customer1.placeOrder(restaurants);
                Payment payment1;
                payment1.processPayment();
            } 
            else if (choice == 3) customer1.trackOrderStatus();
            else if (choice == 4) break; //end
            else cout << "Invalid choice, please try again" << endl;//error
        }
    } 
    
    else if (role == 2) { //for restaurant owner
        string user, pass, rest;
        int code;
        cout << "Create username for Restaurant Owner: "; //creating an account
        cin >> user;
        cout << "Create password for Restaurant Owner: ";
        cin >> pass;
        cout << "Enter your restaurant name: ";
        cin.ignore();
        getline(cin, rest);
        cout << "Enter your secret code: "; //code for verification
        cin >> code;
        RestaurantOwner owner1(user, pass, rest, code);//creating an account
        owner1.login(); //verifying credentials

        while (true) {
            int choice;
            cout << "\n1. View Menu \n2. Add Menu Item\n3. Exit\nEnter your choice: ";
            cin >> choice;

            if (choice == 1) owner1.viewMenuItems(restaurants);
            else if (choice == 2) owner1.addMenuItem(restaurants);
            else if (choice == 3) break; //ending here
            else cout << "Invalid choice, please try again" << endl; //error
        }
    } 

    else {
        cout << "Invalid role choice" << endl;
    }

  return 0;
}

#include <iostream>
#include <string>

class User {
private:
    string username;
    string password;

public:
    User(string username, string password) {
        this->username = username;
        this->password = password;
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

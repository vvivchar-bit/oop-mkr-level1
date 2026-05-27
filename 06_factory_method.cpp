#include <iostream>
#include <memory>
#include <string>
using namespace std;

class User {
public:
    virtual void showInfo() const = 0;
    virtual ~User() {}
};

class Admin : public User {
public:
    void showInfo() const override {
        cout << "Created object: Admin" << endl;
        cout << "Access level: Can manage hotel rooms and users" << endl;
    }
};

class Client : public User {
public:
    void showInfo() const override {
        cout << "Created object: Client" << endl;
        cout << "Access level: Can book hotel rooms" << endl;
    }
};

class Manager : public User {
public:
    void showInfo() const override {
        cout << "Created object: Manager" << endl;
        cout << "Access level: Can check bookings and reports" << endl;
    }
};

class UserFactory {
public:
    static unique_ptr<User> createUser(const string& userType) {
        if (userType == "admin") {
            return unique_ptr<User>(new Admin());
        }
        else if (userType == "client") {
            return unique_ptr<User>(new Client());
        }
        else if (userType == "manager") {
            return unique_ptr<User>(new Manager());
        }
        else {
            return nullptr;
        }
    }
};

int main() {
    cout << "Task 6: Factory Method example" << endl;
    cout << "------------------------------" << endl;

    string userType;

    cout << "Enter user type: admin, client or manager: ";
    cin >> userType;

    unique_ptr<User> user = UserFactory::createUser(userType);

    if (user != nullptr) {
        cout << endl;
        cout << "Factory created the required object." << endl;
        user->showInfo();
    }
    else {
        cout << endl;
        cout << "Unknown user type. Object was not created." << endl;
    }

    cout << "------------------------------" << endl;
    cout << "Client code does not create Admin, Client or Manager directly." << endl;
    cout << "It asks the factory to create the required object." << endl;

    return 0;
}
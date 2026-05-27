#include <iostream>
using namespace std;

int main() {
    cout << "Task 1: try, catch and throw demonstration" << endl;
    cout << "------------------------------------------" << endl;

    try {
        cout << "1. Program entered the try block." << endl;
        cout << "2. The try block contains code where an exception may occur." << endl;

        bool errorExists = true;

        if (errorExists) {
            cout << "3. Error situation detected." << endl;
            throw "Exception was thrown by throw operator";
        }

        cout << "This line will not be executed if exception occurs." << endl;
    }
    catch (const char* errorMessage) {
        cout << "4. Program entered the catch block." << endl;
        cout << "5. Exception was handled successfully." << endl;
        cout << "Error message: " << errorMessage << endl;
    }

    cout << "------------------------------------------" << endl;
    cout << "6. Program continues after exception handling." << endl;

    return 0;
}
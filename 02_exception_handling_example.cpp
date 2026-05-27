#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
    cout << "Task 2: Joint work of try, catch and throw" << endl;
    cout << "------------------------------------------" << endl;

    int a = 10;
    int b = 0;

    try {
        cout << "1. Program entered the try block." << endl;
        cout << "2. Trying to divide " << a << " by " << b << "." << endl;

        if (b == 0) {
            throw runtime_error("Division by zero is not allowed");
        }

        int result = a / b;
        cout << "Result: " << result << endl;
    }
    catch (const runtime_error& error) {
        cout << "3. Program entered the catch block." << endl;
        cout << "4. Exception was handled successfully." << endl;
        cout << "Error message: " << error.what() << endl;
    }

    cout << "------------------------------------------" << endl;
    cout << "5. Program continues after exception handling." << endl;

    return 0;
}
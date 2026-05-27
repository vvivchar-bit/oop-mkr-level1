#include <iostream>
#include <stdexcept>
#include <exception>
#include <cstdlib>
using namespace std;

void customTerminateHandler() {
    cout << "4. std::terminate was called because exception was not caught." << endl;
    cout << "5. Program stopped due to unhandled exception." << endl;
    exit(1);
}

int main() {
    set_terminate(customTerminateHandler);

    cout << "Task 3: Using throw without try block" << endl;
    cout << "------------------------------------" << endl;

    cout << "1. Program does not enter any try block." << endl;
    cout << "2. The throw operator is used directly in main()." << endl;
    cout << "3. Because there is no catch block, the exception will not be handled." << endl;

    throw runtime_error("Throw was used outside try block");

    cout << "This line will not be executed." << endl;

    return 0;
}
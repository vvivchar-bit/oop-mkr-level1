#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double price = 1234.56789;
    int roomNumber = 7;
    bool isAvailable = true;

    cout << "Task 5: Format parameters in C++" << endl;
    cout << "--------------------------------" << endl;

    cout << "1. setprecision(n): controls number precision" << endl;
    cout << "Without fixed: " << setprecision(4) << price << endl;
    cout << "With fixed: " << fixed << setprecision(2) << price << endl;

    cout << endl;

    cout << "2. setw(n): sets field width" << endl;
    cout << setw(15) << "Room" << setw(15) << "Price" << endl;
    cout << setw(15) << roomNumber << setw(15) << price << endl;

    cout << endl;

    cout << "3. left and right: control alignment" << endl;
    cout << left << setw(15) << "Left text" << right << setw(15) << "Right text" << endl;

    cout << endl;

    cout << "4. setfill(char): fills empty space with selected symbol" << endl;
    cout << setfill('*') << setw(10) << roomNumber << endl;
    cout << setfill(' ');

    cout << endl;

    cout << "5. boolalpha: prints boolean values as words" << endl;
    cout << "Room available: " << boolalpha << isAvailable << endl;

    cout << endl;

    cout << "6. showpos: shows plus sign for positive numbers" << endl;
    cout << showpos << 25 << endl;
    cout << noshowpos;

    cout << endl;

    cout << "7. scientific: prints number in scientific notation" << endl;
    cout << scientific << setprecision(3) << price << endl;

    cout << "--------------------------------" << endl;
    cout << "Conclusion: format manipulators make output clearer and more readable." << endl;

    return 0;
}
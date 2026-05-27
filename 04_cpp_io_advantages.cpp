#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
using namespace std;

class HotelRoom {
private:
    int number;
    string type;
    double price;

public:
    HotelRoom(int roomNumber, string roomType, double roomPrice) {
        number = roomNumber;
        type = roomType;
        price = roomPrice;
    }

    friend ostream& operator<<(ostream& out, const HotelRoom& room) {
        out << "Room number: " << room.number << endl;
        out << "Room type: " << room.type << endl;
        out << "Price per night: " << fixed << setprecision(2) << room.price << " UAH" << endl;
        return out;
    }
};

int main() {
    int rooms = 25;
    double rating = 4.756;
    string hotelName = "Hotel Ukraine";

    cout << "Task 4: Advantages of C++ input-output system" << endl;
    cout << "---------------------------------------------" << endl;

    cout << "1. C-style output with printf():" << endl;
    printf("Hotel: %s, rooms: %d, rating: %.2f\n", hotelName.c_str(), rooms, rating);

    cout << endl;

    cout << "2. C++ output with cout:" << endl;
    cout << "Hotel: " << hotelName
         << ", rooms: " << rooms
         << ", rating: " << fixed << setprecision(2) << rating << endl;

    cout << endl;

    cout << "3. C++ streams can work with objects:" << endl;
    HotelRoom room(101, "Standard", 1200.50);
    cout << room;

    cout << endl;

    cout << "4. C++ output formatting with manipulators:" << endl;
    cout << left << setw(15) << "Hotel"
         << right << setw(10) << "Rooms"
         << setw(12) << "Rating" << endl;

    cout << left << setw(15) << hotelName
         << right << setw(10) << rooms
         << setw(12) << fixed << setprecision(2) << rating << endl;

    cout << "---------------------------------------------" << endl;
    cout << "Conclusion: C++ input-output is more convenient for OOP." << endl;

    return 0;
}
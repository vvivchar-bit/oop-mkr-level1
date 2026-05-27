#include <iostream>
#include <string>
using namespace std;

// Interface for notification service
class INotificationService {
public:
    virtual void send(const string& message) = 0;
    virtual ~INotificationService() {}
};

// Concrete dependency 1
class EmailNotificationService : public INotificationService {
public:
    void send(const string& message) override {
        cout << "Email notification: " << message << endl;
    }
};

// Concrete dependency 2
class SmsNotificationService : public INotificationService {
public:
    void send(const string& message) override {
        cout << "SMS notification: " << message << endl;
    }
};

// Example without Dependency Injection
class BookingServiceWithoutDI {
private:
    EmailNotificationService emailService;

public:
    void bookRoom() {
        cout << "Room was booked without Dependency Injection." << endl;
        emailService.send("Booking confirmation was sent.");
    }
};

// Example with Dependency Injection
class BookingServiceWithDI {
private:
    INotificationService& notificationService;

public:
    BookingServiceWithDI(INotificationService& service)
        : notificationService(service) {}

    void bookRoom() {
        cout << "Room was booked with Dependency Injection." << endl;
        notificationService.send("Booking confirmation was sent.");
    }
};

int main() {
    cout << "Task 7: Dependency Injection example" << endl;
    cout << "------------------------------------" << endl;

    cout << "1. Without Dependency Injection:" << endl;
    BookingServiceWithoutDI serviceWithoutDI;
    serviceWithoutDI.bookRoom();

    cout << endl;

    cout << "2. With Dependency Injection using Email service:" << endl;
    EmailNotificationService emailService;
    BookingServiceWithDI bookingWithEmail(emailService);
    bookingWithEmail.bookRoom();

    cout << endl;

    cout << "3. With Dependency Injection using SMS service:" << endl;
    SmsNotificationService smsService;
    BookingServiceWithDI bookingWithSms(smsService);
    bookingWithSms.bookRoom();

    cout << "------------------------------------" << endl;
    cout << "Conclusion: dependency was transformed from a concrete class";
    cout << " to an abstraction and injected from outside." << endl;

    return 0;
}
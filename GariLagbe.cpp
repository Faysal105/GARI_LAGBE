
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

// Function to validate Bangladeshi phone numbers
bool isValidPhoneNumber(const string& phone) {
    return phone.length() == 11 && (phone.substr(0, 2) == "01");
}

// Function to validate a strong password (minimum 8 characters)
bool isValidPassword(const string& password) {
    return password.length() >= 8;
}

// User Class
class User {
public:
    string name, phone, password;
    User(string name, string phone, string password) : name(name), phone(phone), password(password) {}
};

// Vehicle Class
class Vehicle {
public:
    string type;
    double farePerKm;
    Vehicle(string type, double farePerKm) : type(type), farePerKm(farePerKm) {}
};

// Payment Options
enum PaymentMethod { BKASH, NAGAD, VISA, CASH };

// Function for payment processing
void processPayment(PaymentMethod method) {
    switch (method) {
        case BKASH:
            cout << "Enter bKash number: ";
            break;
        case NAGAD:
            cout << "Enter Nagad number: ";
            break;
        case VISA:
            cout << "Enter Visa card number: ";
            break;
        case CASH:
            cout << "Pay with cash on delivery.\n";
            return;
    }
    string details;
    cin >> details;
    cout << "Payment successful using " << (method == BKASH ? "bKash" : method == NAGAD ? "Nagad" : "Visa") << "!\n";
}

int main() {
    // Registration phase
    string name, phone, password;
    cout << "Register your account:\n";
    cout << "Enter name: ";
    cin >> name;
    do {
        cout << "Enter Bangladeshi phone number: ";
        cin >> phone;
        if (!isValidPhoneNumber(phone)) {
            cout << "Invalid phone number. Try again.\n";
        }
    } while (!isValidPhoneNumber(phone));

    do {
        cout << "Enter a strong password (min 8 characters): ";
        cin >> password;
        if (!isValidPassword(password)) {
            cout << "Password too weak. Try again.\n";
        }
    } while (!isValidPassword(password));

    User user(name, phone, password);
    cout << "Registration successful!\n";

    // Login phase
    string enteredName, enteredPassword;
    do {
        cout << "Login:\n";
        cout << "Enter name: ";
        cin >> enteredName;
        cout << "Enter password: ";
        cin >> enteredPassword;
        if (enteredName != user.name || enteredPassword != user.password) {
            cout << "Invalid credentials. Try again.\n";
        }
    } while (enteredName != user.name || enteredPassword != user.password);

    cout << "Login successful!\n";

    // Vehicle selection and fare calculation
    vector<Vehicle> vehicles = {Vehicle("Car", 30.0), Vehicle("CNG", 15.0), Vehicle("Bike", 10.0)};
    cout << "Available vehicles:\n";
    for (size_t i = 0; i < vehicles.size(); i++) {
        cout << i + 1 << ". " << vehicles[i].type << " - " << vehicles[i].farePerKm << " BDT per km\n";
    }

    int vehicleChoice;
    cout << "Select a vehicle by number: ";
    cin >> vehicleChoice;

    if (vehicleChoice < 1 || vehicleChoice > vehicles.size()) {
        cout << "Invalid choice. Exiting...\n";
        return 0;
    }

    double distance;
    cout << "Enter distance in kilometers: ";
    cin >> distance;
    double totalFare = distance * vehicles[vehicleChoice - 1].farePerKm;
    cout << "Total fare: " << totalFare << " BDT\n";

    // Payment section
    cout << "Select payment method:\n1. bKash\n2. Nagad\n3. Visa\n4. Cash on Delivery\n";
    int paymentChoice;
    cin >> paymentChoice;

    if (paymentChoice < 1 || paymentChoice > 4) {
        cout << "Invalid payment option. Exiting...\n";
        return 0;
    }

    processPayment(static_cast<PaymentMethod>(paymentChoice - 1));
    cout << "Thank you for using Gari Lagbe!\n";

    return 0;
}


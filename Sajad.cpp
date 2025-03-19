#include <iostream>
#include <vector>
#include <string>
using namespace std;


struct Customer {
    int id;
    string name;
    string email;
    string subscriptionType;  
    double subscriptionCost;
    bool isActive;

    Customer(int id, string name, string email, string subscriptionType, double subscriptionCost, bool isActive)
        : id(id), name(name), email(email), subscriptionType(subscriptionType), subscriptionCost(subscriptionCost), isActive(isActive) {}
};

class ISPManagementSystem {
private:
    vector<Customer> customers; 

public:
   
    void addCustomer() {
        int id;
        string name, email, subscriptionType;
        double subscriptionCost;
        bool isActive;

        cout << "Enter Customer ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Customer Name: ";
        getline(cin, name);
        cout << "Enter Customer Email: ";
        getline(cin, email);
        cout << "Enter Subscription Type (Basic, Premium, Advanced): ";
        getline(cin, subscriptionType);
        cout << "Enter Subscription Cost: ";
        cin >> subscriptionCost;
        cout << "Is the subscription active? (1 for Yes, 0 for No): ";
        cin >> isActive;

        Customer newCustomer(id, name, email, subscriptionType, subscriptionCost, isActive);
        customers.push_back(newCustomer);
        cout << "Customer added successfully!\n";
    }


    void displayCustomers() {
        if (customers.empty()) {
            cout << "No customers available in the system.\n";
            return;
        }

        cout << "\nCustomer List:\n";
        cout << "ID\tName\t\tEmail\t\t\tSubscription Type\tCost\tActive\n";
        for (const auto& customer : customers) {
            cout << customer.id << "\t" << customer.name << "\t" << customer.email << "\t" << customer.subscriptionType << "\t" << customer.subscriptionCost << "\t" << (customer.isActive ? "Yes" : "No") << endl;
        }
    }


    void updateSubscription() {
        int id;
        cout << "Enter Customer ID to update subscription: ";
        cin >> id;

        for (auto& customer : customers) {
            if (customer.id == id) {
                string newSubscriptionType;
                double newSubscriptionCost;
                bool newStatus;

                cout << "Enter new Subscription Type (Basic, Premium, Advanced): ";
                cin.ignore(); 
                getline(cin, newSubscriptionType);
                cout << "Enter new Subscription Cost: ";
                cin >> newSubscriptionCost;
                cout << "Is the subscription active? (1 for Yes, 0 for No): ";
                cin >> newStatus;

                customer.subscriptionType = newSubscriptionType;
                customer.subscriptionCost = newSubscriptionCost;
                customer.isActive = newStatus;

                cout << "Subscription updated successfully!\n";
                return;
            }
        }
        cout << "Customer not found!\n";
    }


    void generateBill() {
        int id;
        cout << "Enter Customer ID to generate bill: ";
        cin >> id;

        for (const auto& customer : customers) {
            if (customer.id == id) {
                if (customer.isActive) {
                    cout << "Bill for Customer ID: " << customer.id << "\n";
                    cout << "Name: " << customer.name << "\n";
                    cout << "Subscription Type: " << customer.subscriptionType << "\n";
                    cout << "Subscription Cost: " << customer.subscriptionCost << "\n";
                    cout << "Total Bill: " << customer.subscriptionCost << "\n";
                } else {
                    cout << "Customer's subscription is not active. Cannot generate a bill.\n";
                }
                return;
            }
        }
        cout << "Customer not found!\n";
    }


    void exitSystem() {
        cout << "Thank you for using the ISP Management System! Goodbye.\n";
    }
};

int main() {
    ISPManagementSystem system;
    int choice;

    while (true) {
        cout << "\nISP Management System\n";
        cout << "1. Add New Customer\n";
        cout << "2. Display All Customers\n";
        cout << "3. Update Subscription\n";
        cout << "4. Generate Bill\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                system.addCustomer();
                break;
            case 2:
                system.displayCustomers();
                break;
            case 3:
                system.updateSubscription();
                break;
            case 4:
                system.generateBill();
                break;
            case 5:
                system.exitSystem();
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}

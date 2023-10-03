////////////////// Banking System ////////////////////////

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Customer {
public:
    Customer(int id, string name) : customerId(id), customerName(name) {}

    int getCustomerId() const {
        return customerId;
    }

    string getCustomerName() const {
        return customerName;
    }

private:
    int customerId;
    string customerName;
};

class Account {
public:
    Account(int accNumber, Customer customer) : accountNumber(accNumber), balance(0.0), owner(customer) {}

    int getAccountNumber() const {
        return accountNumber;
    }

    double getBalance() const {
        return balance;
    }

    Customer getOwner() const {
        return owner;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited $" << amount << " into Account #" << accountNumber << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn $" << amount << " from Account #" << accountNumber << endl;
        } else {
            cout << "Invalid withdrawal amount or insufficient balance." << endl;
        }
    }

    void transfer(Account &toAccount, double amount) {
        if (amount > 0 && amount <= balance) {
            withdraw(amount);
            toAccount.deposit(amount);
            cout << "Transferred $" << amount << " from Account #" << accountNumber << " to Account #" << toAccount.getAccountNumber() << endl;
        } else {
            cout << "Invalid transfer amount or insufficient balance." << endl;
        }
    }

private:
    int accountNumber;
    double balance;
    Customer owner;
};

int main() {
    vector<Customer> customers;
    vector<Account> accounts;

    // Create some customers
    customers.push_back(Customer(1, "Alice"));
    customers.push_back(Customer(2, "Bob"));

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Create New Account\n";
        cout << "2. View Balance\n";
        cout << "3. Deposit\n";
        cout << "4. Withdraw\n";
        cout << "5. Transfer\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int customerId;
                cout << "Enter Customer ID: ";
                cin >> customerId;
                bool customerExists = false;
                for (const Customer &customer : customers) {
                    if (customer.getCustomerId() == customerId) {
                        customerExists = true;
                        break;
                    }
                }
                if (customerExists) {
                    int accountNumber = accounts.empty() ? 101 : accounts.back().getAccountNumber() + 1;
                    accounts.push_back(Account(accountNumber, customers[customerId - 1]));
                    cout << "Account created successfully. Account Number: " << accountNumber << endl;
                } else {
                    cout << "Customer not found. Please enter a valid Customer ID." << endl;
                }
                break;
            }
            case 2: {
                int accountNumber;
                cout << "Enter Account Number: ";
                cin >> accountNumber;
                bool accountFound = false;
                for (const Account &account : accounts) {
                    if (account.getAccountNumber() == accountNumber) {
                        accountFound = true;
                        cout << "Account Balance: $" << account.getBalance() << endl;
                        break;
                    }
                }
                if (!accountFound) {
                    cout << "Account not found. Please enter a valid Account Number." << endl;
                }
                break;
            }
            case 3: {
                int accountNumber;
                double amount;
                cout << "Enter Account Number: ";
                cin >> accountNumber;
                bool accountFound = false;
                for (Account &account : accounts) {
                    if (account.getAccountNumber() == accountNumber) {
                        accountFound = true;
                        cout << "Enter deposit amount: $";
                        cin >> amount;
                        account.deposit(amount);
                        break;
                    }
                }
                if (!accountFound) {
                    cout << "Account not found. Please enter a valid Account Number." << endl;
                }
                break;
            }
            case 4: {
                int accountNumber;
                double amount;
                cout << "Enter Account Number: ";
                cin >> accountNumber;
                bool accountFound = false;
                for (Account &account : accounts) {
                    if (account.getAccountNumber() == accountNumber) {
                        accountFound = true;
                        cout << "Enter withdrawal amount: $";
                        cin >> amount;
                        account.withdraw(amount);
                        break;
                    }
                }
                if (!accountFound) {
                    cout << "Account not found. Please enter a valid Account Number." << endl;
                }
                break;
            }
            case 5: {
                int fromAccountNumber, toAccountNumber;
                double amount;
                cout << "Enter Source Account Number: ";
                cin >> fromAccountNumber;
                cout << "Enter Destination Account Number: ";
                cin >> toAccountNumber;
                bool sourceAccountFound = false, destAccountFound = false;
                Account *sourceAccount = nullptr, *destAccount = nullptr;
                for (Account &account : accounts) {
                    if (account.getAccountNumber() == fromAccountNumber) {
                        sourceAccountFound = true;
                        sourceAccount = &account;
                    }
                    if (account.getAccountNumber() == toAccountNumber) {
                        destAccountFound = true;
                        destAccount = &account;
                    }
                }
                if (sourceAccountFound && destAccountFound) {
                    cout << "Enter transfer amount: $";
                    cin >> amount;
                    sourceAccount->transfer(*destAccount, amount);
                } else {
                    if (!sourceAccountFound) {
                        cout << "Source Account not found. Please enter a valid Source Account Number." << endl;
                    }
                    if (!destAccountFound) {
                        cout << "Destination Account not found. Please enter a valid Destination Account Number." << endl;
                    }
                }
                break;
            }
            case 6:
                cout << "Exiting Banking. Thank you!" << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 6);

    return 0;
}

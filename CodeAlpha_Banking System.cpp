#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Transaction Class
class Transaction {
private:
    string type;
    double amount;

public:
    Transaction(string type, double amount) {
        this->type = type;
        this->amount = amount;
    }

    void displayTransaction() {
        cout << type << " : Rs." << amount << endl;
    }
};

// Account Class
class Account {
private:
    int accountNumber;
    double balance;
    vector<Transaction> transactionHistory;

public:
    Account(int accNo, double initialBalance) {
        accountNumber = accNo;
        balance = initialBalance;
        transactionHistory.push_back(Transaction("Account Created", initialBalance));
    }

    int getAccountNumber() {
        return accountNumber;
    }

    double getBalance() {
        return balance;
    }

    // Deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            transactionHistory.push_back(Transaction("Deposit", amount));
            cout << "Rs." << amount << " deposited successfully.\n";
        }
    }

    // Withdraw money
    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance!\n";
        }
        else {
            balance -= amount;
            transactionHistory.push_back(Transaction("Withdrawal", amount));
            cout << "Rs." << amount << " withdrawn successfully.\n";
        }
    }

    // Transfer money
    void transfer(Account &receiver, double amount) {
        if (amount > balance) {
            cout << "Transfer failed! Insufficient balance.\n";
        }
        else {
            balance -= amount;
            receiver.balance += amount;

            transactionHistory.push_back(
                Transaction("Transferred to Account " + to_string(receiver.accountNumber), amount));

            receiver.transactionHistory.push_back(
                Transaction("Received from Account " + to_string(accountNumber), amount));

            cout << "Rs." << amount << " transferred successfully.\n";
        }
    }

    // Display account information
    void displayAccountInfo() {
        cout << "\nAccount Number : " << accountNumber << endl;
        cout << "Current Balance : Rs." << balance << endl;
    }

    // View transaction history
    void viewTransactions() {
        cout << "\nTransaction History for Account " << accountNumber << ":\n";
        for (Transaction t : transactionHistory) {
            t.displayTransaction();
        }
    }
};

// Customer Class
class Customer {
private:
    int customerID;
    string name;
    string address;
    vector<Account> accounts;

public:
    Customer(int id, string name, string address) {
        customerID = id;
        this->name = name;
        this->address = address;
    }

    void addAccount(Account acc) {
        accounts.push_back(acc);
    }

    void displayCustomerInfo() {
        cout << "\nCustomer ID : " << customerID << endl;
        cout << "Name : " << name << endl;
        cout << "Address : " << address << endl;

        for (Account acc : accounts) {
            acc.displayAccountInfo();
        }
    }
};

// Main Function
int main() {
    // Create customers
    Customer c1(101, "Rahul", "Delhi");
    Customer c2(102, "Priya", "Mumbai");

    // Create accounts
    Account a1(1001, 5000);
    Account a2(1002, 3000);

    // Add accounts to customers
    c1.addAccount(a1);
    c2.addAccount(a2);

    // Perform transactions
    a1.deposit(2000);
    a1.withdraw(1000);
    a1.transfer(a2, 1500);

    // Display account information
    a1.displayAccountInfo();
    a2.displayAccountInfo();

    // Display transaction history
    a1.viewTransactions();
    a2.viewTransactions();

    return 0;
}
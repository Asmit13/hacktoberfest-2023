// File Name: BankingSystem.cpp

#include <iostream>
#include <vector>
#include <string>

class Account {
private:
    std::string accountNumber;
    std::string accountHolder;
    double balance;

public:
    Account(const std::string& number, const std::string& holder, double initialBalance)
        : accountNumber(number), accountHolder(holder), balance(initialBalance) {
    }

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            std::cout << "Insufficient funds." << std::endl;
        }
    }

    void display() const {
        std::cout << "Account Number: " << accountNumber << std::endl;
        std::cout << "Account Holder: " << accountHolder << std::endl;
        std::cout << "Balance: $" << balance << std::endl;
    }
};

class Bank {
private:
    std::vector<Account> accounts;

public:
    void addAccount(const std::string& number, const std::string& holder, double initialBalance) {
        Account newAccount(number, holder, initialBalance);
        accounts.push_back(newAccount);
    }

    void displayAllAccounts() const {
        for (const Account& account : accounts) {
            account.display();
            std::cout << "===================" << std::endl;
        }
    }
};

int main() {
    Bank bank;

    bank.addAccount("A12345", "John Doe", 1000.0);
    bank.addAccount("B67890", "Alice Smith", 2500.0);

    int choice;
    do {
        std::cout << "Banking System Menu" << std::endl;
        std::cout << "1. Display All Accounts" << std::endl;
        std::cout << "2. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                bank.displayAllAccounts();
                break;
            case 2:
                std::cout << "Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Try again." << std::endl;
        }
    } while (choice != 2);

    return 0;
}

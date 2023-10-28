//Bank Data Management: 

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class BankAccount {
private:
    string accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount(string accNumber, string accHolderName) {
        accountNumber = accNumber;
        accountHolderName = accHolderName;
        balance = 0.0;
    }

    string getAccountNumber() {
        return accountNumber;
    }

    string getAccountHolderName() {
        return accountHolderName;
    }

    double getBalance() {
        return balance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit of $" << amount << " successful." << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal of $" << amount << " successful." << endl;
        } else {
            cout << "Invalid withdrawal amount or insufficient balance." << endl;
        }
    }

    void displayAccountDetails() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Balance: $" << balance << endl;
    }
};

class Bank {
private:
    vector<BankAccount> accounts;

public:
    void addAccount(string accountNumber, string accountHolderName) {
        BankAccount account(accountNumber, accountHolderName);
        accounts.push_back(account);
        cout << "Account added successfully." << endl;
    }

    BankAccount* findAccount(string accountNumber) {
        for (auto& account : accounts) {
            if (account.getAccountNumber() == accountNumber) {
                return &account;
            }
        }
        return nullptr;
    }
};

int main() {
    Bank bank;
    int choice;

    do {
        cout << "----- Bank Data Management -----" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Display Account Details" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 0:
                cout << "Exiting..." << endl;
                break;
            case 1: {
                string accountNumber, accountHolderName;
                cout << "Enter Account Number: ";
                cin >> accountNumber;
                cout << "Enter Account Holder Name: ";
                cin >> accountHolderName;
                bank.addAccount(accountNumber, accountHolderName);
                break;
            }
            case 2: {
                string accountNumber;
                double amount;
                cout << "Enter Account Number: ";
                cin >> accountNumber;
                BankAccount* account = bank.findAccount(accountNumber);
                if (account) {
                    cout << "Enter Deposit Amount: $";
                    cin >> amount;
                    account->deposit(amount);
                } else {
                    cout << "Account not found." << endl;
                }
                break;
            }
            case 3: {
                string accountNumber;
                double amount;
                cout << "Enter Account Number: ";
                cin >> accountNumber;
                BankAccount* account = bank.findAccount(accountNumber);
                if (account) {
                    cout << "Enter Withdrawal Amount: $";
                    cin >> amount;
                    account->withdraw(amount);
                } else {
                    cout << "Account not found." << endl;
                }
                break;
            }
            case 4: {
                string accountNumber;
                cout << "Enter Account Number: ";
                cin >> accountNumber;
                BankAccount* account = bank.findAccount(accountNumber);
                if (account) {
                    account->displayAccountDetails();
                } else {
                    cout << "Account not found." << endl;
                }
                break;
            }
            default:
                cout << "Invalid choice. Try again." << endl;
                break;
        }

        cout << endl;

    } while (choice != 0);

    return 0;
}
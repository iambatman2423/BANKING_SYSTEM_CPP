#include <iostream>
using namespace std;

// Base Class
class BankAccount {
protected:
    int accountNumber;
    string accountHolderName;

private:
    double balance;

public:
    BankAccount(int accNo, string name, double bal) {
        accountNumber = accNo;
        accountHolderName = name;
        balance = bal;
    }

    // Encapsulation
    double getBalance() {
        return balance;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Amount Deposited Successfully.\n";
    }

    virtual void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawal Successful.\n";
        } else {
            cout << "Insufficient Balance.\n";
        }
    }

    virtual void calculateInterest() {
        cout << "No Interest for Basic Account.\n";
    }

    virtual void displayAccountInfo() {
        cout << "\nAccount Number : " << accountNumber;
        cout << "\nAccount Holder : " << accountHolderName;
        cout << "\nBalance        : " << balance << endl;
    }

    virtual ~BankAccount() {}
};

// Savings Account
class SavingsAccount : public BankAccount {
    double interestRate;

public:
    SavingsAccount(int accNo, string name, double bal, double rate)
        : BankAccount(accNo, name, bal) {
        interestRate = rate;
    }

    void calculateInterest() override {
        double interest = getBalance() * interestRate / 100;
        cout << "Savings Interest = " << interest << endl;
    }
};

// Checking Account
class CheckingAccount : public BankAccount {
    double overdraftLimit;

public:
    CheckingAccount(int accNo, string name, double bal, double limit)
        : BankAccount(accNo, name, bal) {
        overdraftLimit = limit;
    }

    void withdraw(double amount) override {
        if (amount <= getBalance() + overdraftLimit) {
            cout << "Withdrawal Successful.\n";
        } else {
            cout << "Overdraft Limit Exceeded.\n";
        }
    }

    void calculateInterest() override {
        cout << "No Interest for Checking Account.\n";
    }
};

// Fixed Deposit Account
class FixedDepositAccount : public BankAccount {
    int term;

public:
    FixedDepositAccount(int accNo, string name, double bal, int t)
        : BankAccount(accNo, name, bal) {
        term = t;
    }

    void calculateInterest() override {
        double interest = (getBalance() * 7 * term) / (100 * 12);
        cout << "Fixed Deposit Interest = " << interest << endl;
    }
};

// Main Function
int main() {
    BankAccount* acc;

    int choice;

    do {
        cout << "\n===== BANKING SYSTEM =====";
        cout << "\n1. Savings Account";
        cout << "\n2. Checking Account";
        cout << "\n3. Fixed Deposit Account";
        cout << "\n4. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice) {

        case 1: {
            SavingsAccount s(101, "Aayush", 10000, 5);

            acc = &s;

            acc->displayAccountInfo();
            acc->deposit(2000);
            acc->withdraw(3000);
            acc->calculateInterest();

            break;
        }

        case 2: {
            CheckingAccount c(102, "Rahul", 5000, 2000);

            acc = &c;

            acc->displayAccountInfo();
            acc->deposit(1000);
            acc->withdraw(6000);
            acc->calculateInterest();

            break;
        }

        case 3: {
            FixedDepositAccount f(103, "Priya", 20000, 12);

            acc = &f;

            acc->displayAccountInfo();
            acc->calculateInterest();

            break;
        }

        case 4:
            cout << "Thank You!\n";
            break;

        default:
            cout << "Invalid Choice.\n";
        }

    } while (choice != 4);

    return 0;
}
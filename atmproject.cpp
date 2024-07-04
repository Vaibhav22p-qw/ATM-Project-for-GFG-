#include <iostream>
#include <string>
using namespace std;

class Bank {
private:
    string name; // Variable to store account holder's name
    long long accnumber; // Variable to store account number
    string type; // Variable to store account type (e.g., savings, checking)
    long long amount = 0; // Variable to store the amount for deposit or withdrawal
    long long tot = 0; // Variable to store the total balance

public:
    // Function to set the account holder's data
    void setvalue() {
        cout << "Enter name\n";
        cin.ignore(); // To ignore any newline characters left in the buffer
        getline(cin, name); // To get the full name including spaces
        cout << "Enter Account number\n";
        cin >> accnumber;
        cout << "Enter Account type\n";
        cin >> type;
        cout << "Enter Balance\n";
        cin >> tot;
    }

    // Function to display account holder's data
    void showdata() {
        cout << "Name: " << name << endl;
        cout << "Account No: " << accnumber << endl;
        cout << "Account type: " << type << endl;
        cout << "Balance: " << tot << endl;
    }

    // Function to deposit an amount into the account
    void deposit() {
        cout << "\nEnter amount to be Deposited\n";
        cin >> amount;
        tot += amount; // Update the total balance after deposit
        amount = 0; // Reset the amount to 0 after deposit
    }

    // Function to display the total balance
    void showbal() {
        cout << "\nTotal balance is: " << tot << endl;
    }

    // Function to withdraw an amount from the account
    void withdrawl() {
        long long withdrawAmount;
        cout << "Enter amount to withdraw\n";
        cin >> withdrawAmount;
        if (withdrawAmount > tot) { // Check if the withdraw amount is greater than the total balance
            cout << "Insufficient balance\n";
        } else {
            tot -= withdrawAmount; // Update the total balance after withdrawal
            cout << "Available Balance is: " << tot << endl;
        }
    }
};

int main() {
    Bank b; // Create an object of the Bank class
    int choice; // Variable to store the user's choice

    // Infinite loop to provide menu options to the user
    while (1) {
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~"
             << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
             << "~~~WELCOME~~~~~~~~~~~~~~~~~~"
             << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
             << "~~~~~~~~~\n\n";
        cout << "Enter Your Choice\n";
        cout << "\t1. Enter name, Account number, Account type\n";
        cout << "\t2. Balance Enquiry\n";
        cout << "\t3. Deposit Money\n";
        cout << "\t4. Show Total balance\n";
        cout << "\t5. Withdraw Money\n";
        cout << "\t6. Cancel\n";
        cin >> choice;

        // Switch case to handle user's choice
        switch (choice) {
        case 1:
            b.setvalue(); // Set account holder's data
            break;
        case 2:
            b.showdata(); // Display account holder's data
            break;
        case 3:
            b.deposit(); // Deposit money into the account
            break;
        case 4:
            b.showbal(); // Show the total balance
            break;
        case 5:
            b.withdrawl(); // Withdraw money from the account
            break;
        case 6:
            exit(0); // Exit the program
            break;
        default:
            cout << "\nInvalid choice\n"; // Handle invalid choices
        }
    }
}

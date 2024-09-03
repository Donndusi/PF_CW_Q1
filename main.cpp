#include <iostream> // Include the input/output stream library
using namespace std; // Use the standard namespace

int main() {

    int id, password, savedID, savedPass; // Variables for user id and password
    char choice, choice2; // Variables for menu choices
    double balance = 0; // Variable to hold the account balance, initialized to 0

    cout << "Hi! Welcome to the ATM Machine! \n\n"; // Display welcome message

    do {
        // Display the main menu options
        cout << "Please select an option from the menu below: \n\n";
        cout << "l -> Login \n";
        cout << "c -> Create New Account \n";
        cout << "q -> Quit\n";
        cin >> choice; // Get the user's choice

        switch (choice) {
            case 'c': // Option to create a new account
                cout << "Please enter your user id: ";
                cin >> savedID; // Input and save user id
                cout << "Please enter your password: ";
                cin >> savedPass; // Input and save password
                cout << "Thank You! Your account has been created!\n";
                break;

            case 'q': // Option to quit the program
                cout << "Thanks for visiting!";
                break;

            case 'l': // Option to log in
                cout << "Please enter your user id: ";
                cin >> id; // Input user id for login
                cout << "Please enter your password: ";
                cin >> password; // Input password for login

                // Check if the entered credentials match the saved credentials
                if (id == savedID && password == savedPass) {
                    cout << "Access Granted! \n";

                    // Start of the account menu loop
                    while (choice2 != 'q') {
                        // Display the account menu options
                        cout << "d -> Deposit Money \n";
                        cout << "w -> Withdraw Money \n";
                        cout << "r -> Request Balance\n";
                        cout << "q -> Quit \n";
                        cin >> choice2; // Get the user's choice for the account menu

                        switch (choice2) {
                            case 'd': // Option to deposit money
                                int deposit;
                                cout << "Amount of deposit: $ ";
                                cin >> deposit; // Input deposit amount
                                balance += deposit; // Add deposit amount to balance
                                break;

                            case 'w': // Option to withdraw money
                                int withdraw;
                                cout << "Amount of withdrawal: $ ";
                                cin >> withdraw; // Input withdrawal amount

                                // Check if there is sufficient balance for withdrawal
                                if (withdraw <= balance) {
                                    balance -= withdraw; // Deduct withdrawal amount from balance
                                } else {
                                    cout << "Your account is too low! \n"; // Notify insufficient balance
                                }
                                break;

                            case 'r': // Option to request balance
                                cout << "Your balance is: $" << balance << "\n"; // Display current balance
                                break;

                            case 'q': // Option to quit the account menu
                                cout << "\n";
                                break;

                            default: // Handle invalid choices
                                cout << "Invalid choice! \n";
                                break;
                        }
                    }
                } else {
                    cout << "*** LOGIN FAILED! *** \n"; // Notify login failure
                }
                break;

            default: // Handle invalid menu choices
                cout << "Invalid choice! \n";
                break;
        }
    } while (choice != 'q'); // Continue until the user chooses to quit

    return 0; // Exit the program
}
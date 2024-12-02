//0.0.2

#include <iostream>
#include <iomanip>
using namespace std;


int main() {

    //sign up / login 
    string regUsername;
    int regPin;
    string loginUser;
    int logPin;

    //locks after 3 tries
    int passLock = 4;

    //system Run
    bool logRunning = true;
    bool mainRunning = true;
    char reset;

    int choice;

    //cash count
    float amount = 0;
    float cash = 0;

    //Register UI
    cout << "\n=======================================\n"
        << "\n\t    Register/Sign Up\n"
        << "\n=======================================\n";

    cout << "Enter Username: ";
    cin >> regUsername;

    cout << "Enter PIN: ";
    cin >> regPin;

    system("cls");

    //Login UI
    while (logRunning) {

        system("cls");
        cout << "\n=======================================\n";
        cout << "\n\t\tLogin\n";
        cout << "\n=======================================\n";

        cout << "Enter your username: ";
        cin >> loginUser;
        
        //If username doesnt match the registered one, Loop back
        if (loginUser != regUsername) {

            cout << "\nWrong username! Please try again.\n";
            system("pause");
            system("cls");
            continue;
        }
        system("cls");

        do {
            //Login PIN
            cout << "\n=======================================\n";
            cout << "\n\t\tLogin\n";
            cout << "\n=======================================\n";
            cout << "Username: " << loginUser << endl;
            cout << "Enter your PIN: ";
            cin >> logPin;
            system("cls");

            //if PIN doesnt match the username's PIN then Loop back with 3 tries
            if (logPin != regPin) {
                passLock--;
                cout << "Remaining tries left: " << passLock << endl;
                cout << "\nWrong PIN! Please try again.\n";
                continue;
            }

        } while (logPin != regPin && passLock != 0);

        //Locks account after 3 wrong tries
        if (passLock == 0) {
            system("cls");
            cout << "\n===============================================\n";
            cout << "\nYour account has been locked due to many tries.\n";
            cout << "\n===============================================\n";
            mainRunning = false;
        }

        logRunning = false;
        

    }

    

    // Main backing loop
    while (mainRunning) {

        // Check INPUT PIN if correct
        cout << "\n=======================================\n";
        cout << "\n\tWelcome to bank! " << loginUser << "!\n";
        cout << "\n=======================================\n";
        cout << "\nRemaining cash: $" << fixed << setprecision(2) << cash <<
            "\n\n";
        cout << "-[1] Withdraw\n"
            << "-[2] Deposit\n"
            << "-[3] Exit\n";
        cout << "\n=======================================\n";

        // ask user 1-3
        cout << "What would you like to do: ";
        cin >> choice;

        system("cls");

        switch (choice) {
        case 1: // user chose 1
            cout << "\nRemaining cash: $" << fixed << setprecision(2) << cash <<
                "\n\n";
            cout << "\n - How much would you like to withdraw: ";
            cin >> amount;
            if (cash < amount) {
                cout << "\n==============================================\n"
                    << "| Insufficient Wallet. Please deposit first. |\n"
                    << "==============================================\n";
                continue;
            }
            else if (cash >= amount) {
                cash -= amount; // subtracts withdrawn cash
                cout << "\n==============================================\n"
                    << "\nHello " << loginUser << ", You have now a total of $" << cash << ".\n"
                    << "\nYou have withdrawn the amount of $" << amount << ".\n"
                    << "\n==============================================\n";
            }
            else { // Invalid Input
                cout << "\nInvalid Response. Please try again.\n";
                continue;
            }
            break;
        case 2: // user chose 2
            cout << "\n - How much would you like to deposit: $";
            cin >> amount;
            if(amount > 0){
            cash += amount; // adds deposited cash
            cout << "\nHello " << loginUser << ", You have now a total of $" << cash << ".\n";
            cout << "\nYou have deposited the amount of $" << amount << ".\n";
            }
            else{ // Invalid Input
                cout << "\nInvalid response! Pleaes try again\n";
                continue;
            }
            break;
                
        case 3: // user chose 3
            cout << "\nThank you for banking with us today, " << loginUser << ", Goodbye!\n";
            mainRunning = false;
            break;
        default: // default option 
            cout << "\nInvalid response! Please try again.\n";
            continue;
            
        }

        // check if the user would do another transaction
        if (mainRunning && choice != 3) {
            cout << "\nWould you like to do another transaction?(Y/N): ";
            cin >> reset;

            if (reset == 'Y' || reset == 'y') {
                system("cls");
                continue; // Loop back
            }
            else if (reset == 'N' || reset == 'n') {
                system("cls");
                cout << "\nThank you for banking with us today, "<< loginUser  << ", Goodbye!\n";
                mainRunning = false; // Exits the system
                
            }
            
            
        }
    }


    return 0;
}


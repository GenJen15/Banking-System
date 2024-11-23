#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    
    // Banking System 
    string name;
    int pin, choice;
    const int correctPin = 71506;
    float cash = 0.00;
    char reset;
    bool running = true;
    float amount;
    
    // START
    
    cout << "\n=======================================\n"
         << "|\t\t\tWelcome to bank!          |\n"
         << "=======================================\n\n";
         
        cout << "Enter your name: ";
        cin >> name;
        system("cls");
    
        cout << "Enter your PIN: ";
        cin >> pin;
        
        if(pin != correctPin){
            cout << "Incorrect PIN! Please try again.\n";
            return 0;
        }

    // Main backing loop
    while(running){
    
        // Check INPUT PIN if correct
        cout << "\n=======================================\n";
        cout << "Welcome " << name << "!\n";
        cout << "\nRemaining cash: $" << fixed << setprecision(2) << cash <<
            endl;
        cout << "-[1] Withdraw\n"
             << "-[2] Deposit\n"
             << "-[3] Exit\n";
        cout << "\n=======================================\n";
        
        // ask user 1-3
        cout << "What would you like to do: ";
        cin >> choice;
        
        system("cls");
        
        switch(choice){
            case 1: // user chose 1
                cout << "\n - How much would you like to withdraw: ";
                cin >> amount;
                if(cash < amount){
                    cout << "\n==============================================\n"
                         << "| Insufficient Wallet. Please deposit first. |\n"
                         << "==============================================\n";
                }
                else if(cash >= amount){
                    cash -= amount; // subtracts withdrawn cash
                    cout << "\nHello " << name << "You have now a total of $" << cash << ".\n";
                    cout << "\nYou have withdrawn the amount of $" << amount << ".\n"; 
                }
                else{ // Invalid Input
                    cout << "\nInvalid Response. Please try again.\n";
                }
                break;
            case 2: // user chose 2
                cout << "\n - How much would you like to deposit: ";
                cin >> amount;
                cash += amount; // adds deposited cash
                cout << "\nHello " << name << "You have now a total of $" << cash << ".\n";
                cout << "\nYou have deposited the amount of $" << amount << ".\n"; 
                break;
            case 3: // user chose 3
                cout << "\nExiting...\n";
                running = false;
                break;
            default: // default option 
                cout << "\nInvalid response! Please try again.\n";
                break;
        }
        
        // check if the user would do another transaction
        if(running && choice != 3){
            cout << "\nWould you like to do another transaction?(Y/N): ";
            cin >> reset;
        
            if(reset == 'Y' || reset == 'y'){
                running = true; // Loop back
            }
            else{
                cout << "Thank you for banking with us today, Goobye!\n";
                running = false; // Exits the system
            }
            system("cls");
        }
    }   

    return 0;
}

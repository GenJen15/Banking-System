#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    
    // Banking System 
    string name;
    int pin, choice, correctPIN = 071506;
    float cash = 0.00;
    char reset;
    bool running = true;
    float switchChoice;
    
    // START
    
    cout << "\n=======================================\n"
         << "|\t\t\tWelcome to bank!          |\n"
         << "=======================================\n\n";
         
        cout << "Enter your name: ";
        cin >> name;
        system("cls");
    
        cout << "Enter your PIN: ";
        cin >> pin;
        system("pause");
        system("cls");
    
    while(choice != 3 && running == true){
    
        // Check INPUT PIN if correct
        cout << "\n=======================================\n";
        if(pin == correctPIN){
            cout << "Welcome " << name << "!\n";
            cout << "\nRemaining cash: $" << fixed << setprecision(2) << cash <<
            endl;
            cout << "-[1] Withdraw\n"
                 << "-[2] Deposit\n"
                 << "-[3] Exit\n";
        }
        else{ 
            cout << "Invalid PIN! Please try again.\n";
        }
        cout << "\n=======================================\n";
        
        // ask user 1-3
        cout << "What would you like to do: ";
        cin >> choice;
        
        system("cls");
        
        switch(choice){
            case 1: // user chose 1
                cout << "\n - How much would you like to withdraw: ";
                cin >> switchChoice;
                if(cash < switchChoice){
                    cout << "\n==============================================\n"
                         << "| Insufficient Wallet. Please deposit first. |\n"
                         << "==============================================\n";
                }
                else if(cash >= switchChoice){
                    cash -= switchChoice; // subtracts withdrawn cash
                    cout << "\nHello " << name << "You have now a total of $" << cash << ".\n";
                    cout << "\nYou have withdrawn the amount of $" << switchChoice << ".\n"; 
                }
                else{
                    cout << "\nInvalid Response. Please try again.\n";
                }
                break;
            case 2: // user chose 2
                cout << "\n - How much would you like to deposit: ";
                cin >> switchChoice;
                cash += switchChoice; // adds deposited cash
                cout << "\nHello " << name << "You have now a total of $" << cash << ".\n";
                cout << "\nYou have deposited the amount of $" << switchChoice << ".\n"; 
                break;
            case 3: // user chose 3
                cout << "\nExiting...\n";
                break;
            default: // default option 
                cout << "\nInvalid response! Please try again.\n";
                break;
        }
        
        system("cls");
        
        // check if the user would do another transaction
        if(choice == 1 || choice == 2){
            cout << "\nWould you like to do another transaction?(Y/N): ";
            cin >> reset;
        
            if(reset == 'Y' || reset == 'y'){
                running = true; // Loop back
            }
            else{
                running = false; // Exits the system
            }
        }
        else{
            running == false; // Exits the system
        }
        
        system("cls");
    }   

    return 0;
}

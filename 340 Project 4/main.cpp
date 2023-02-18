#include <iostream>
#include <iomanip>
#include <string>
#include "Fraction.h"
using namespace std;

void PrintMenu() {
    Fraction num1;
    Fraction num2;
    Fraction result;
    char menuOp = ' ';

    // Output menu option, prompt users for valid selection
    while (menuOp != 'e') {
        cout << "MENU" << endl;
        cout << "a. Input fraction A" << endl;
        cout << "b. Input fraction B" << endl << endl;
        cout << "For menu items 1-9, you must have entered a fraction A and B" << endl << endl;
        cout << "1. A + B" << endl;
        cout << "2. A - B" << endl;
        cout << "3. B - A" << endl;
        cout << "4. A * B" << endl;
        cout << "5. A < B" << endl;
        cout << "6. A > B" << endl;
        cout << "7. A == B" << endl;
        cout << "8. A = B" << endl;
        cout << "9. A / B" << endl;
        cout << "p - Print A and B" << endl;
        cout << "e - Exit" << endl << endl;
        cout << "Choose an option: ";
        cin >> menuOp;

        if (menuOp != 'e') {
            while (menuOp != 'a' && menuOp != 'b' && menuOp != '1' &&
                menuOp != '2' && menuOp != '3' && menuOp != '4' && menuOp != '5' &&
                menuOp != '6' && menuOp != '7' && menuOp != '8' && menuOp != '9' &&
                menuOp != 'e' && menuOp != 'p') {
                cout << "Choose an option: ";
                cin >> menuOp;
            }
            switch (menuOp) {
            case 'a':
                cin.ignore();
                cout << "Enter the numerator followed by the denominator, separated by a" <<
                    " space for Fraction A" << endl;
                cin >> num1;
                cout << endl;
                break;
            case 'b':
                // Output playlist messaging
                cin.ignore();
                cout << "Enter the numerator followed by the denominator, separated by a" <<
                    " space for Fraction B" << endl;
                cin >> num2;
                cout << endl;
                break;
            case '1':
                cin.ignore();
                if (!(num1.isDefault() || num2.isDefault())) {
                    result = num1 + num2;
                    cout << endl << endl << num1 << " + " << num2 << " = " << result << endl << endl;
                }
                else  cout << "You have not entered the two fractions A and B." << endl;
                break;
            case '2':
                cin.ignore();
                if (!(num1.isDefault() || num2.isDefault())) {
                    result = num1 - num2;
                    cout << endl << endl << num1 << " - " << num2 << " = " << result << endl << endl;
                }
                else  cout << "You have not entered the two fractions A and B." << endl;
                break;
            case '3':
                cin.ignore();
                if (!(num1.isDefault() || num2.isDefault())) {
                    result = num2 - num1;
                    cout << endl << endl << num2 << " - " << num1 << " = " << result << endl << endl;

                }
                else  cout << "You have not entered the two fractions A and B." << endl;
                break;
            case '4':
                cin.ignore();
                if (!(num1.isDefault() || num2.isDefault())) {
                    result = num1 * num2;
                    cout << endl << endl << num1 << " * " << num2 << " = " << result << endl << endl;
                }
                else  cout << "You have not entered the two fractions A and B." << endl;
                break;
            case '5':
                cin.ignore();
                if (!(num1.isDefault() || num2.isDefault())) {
                    cout << endl << endl << "A=" << num1 << " B=" << num2 << endl;
                    cout << "A < B is: ";
                    if (num1 < num2) cout << "true" << endl << endl;
                    else cout << "false" << endl << endl;
                }
                else  cout << "You have not entered the two fractions A and B." << endl;
                break;
            case '6':
                cin.ignore();
                if (!(num1.isDefault() || num2.isDefault())) {
                    cout << endl << endl << "A=" << num1 << " B=" << num2 << endl;
                    cout << "A > B is: ";
                    if (num2 < num1) cout << "true" << endl << endl;
                    else cout << "false" << endl << endl;
                }
                else  cout << "You have not entered the two fractions A and B." << endl;
                break;
            case '7':
                cin.ignore();
                if (!(num1.isDefault() || num2.isDefault())) {
                    cout << endl << endl << "A=" << num1 << " B=" << num2 << endl;
                    cout << "A == B is: ";
                    if (num1 == num2) cout << "true" << endl << endl;
                    else cout << "false" << endl << endl;
                }
                else  cout << "You have not entered the two fractions A and B." << endl;
                break;
            case '8':
                cin.ignore();
                if (!(num1.isDefault() || num2.isDefault())) {
                    cout << endl << endl << "A=" << num1 << " B=" << num2 << endl;
                    num1 = num2;
                    cout << "A = B: A=" << num1 << " B=" << num2 << endl << endl;

                }
                else  cout << "You have not entered the two fractions A and B." << endl;
                break;

            case '9':
                cin.ignore();
                if (!(num1.isDefault() || num2.isDefault())) {
                    cout << endl << endl << "A=" << num1 << " B=" << num2 << endl;
                    result = num1 / num2;
                    cout << endl << endl << num1 << " / " << num2 << " = " << result << endl << endl;

                }
                else  cout << "You have not entered the two fractions A and B." << endl;
                break;

            case 'p':
                cin.ignore();
                if (!(num1.isDefault() || num2.isDefault())) {
                    cout << endl << endl << "A=" << num1 << " B=" << num2 << endl << endl;
                }
                else  cout << "You have not entered the two fractions A and B." << endl;
                break;

            default:
                cout << "You have entered an invalid option" << endl;
            }
        }

    }
}// end of PrintMenu


int main() {

    // Output play list menu options
    PrintMenu();

    return 0;
}
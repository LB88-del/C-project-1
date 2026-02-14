#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>

using namespace std;

int main() {
    char again = 'y';

    while (true) {  
        int Z, ni, nf;

        while (true) {
            cout << "Give your Z value (must be a positive integer): ";
            cin >> Z;

            if (cin.fail() || Z <= 0) {
                cout << "Invalid input. Please enter a positive integer." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                break;
            }
        }

        while (true) {
            while (true) {
                cout << "Give your ni value (must be a positive integer): ";
                cin >> ni;

                if (cin.fail() || ni <= 0) {
                    cout << "Invalid input. Please enter a positive integer." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } else {
                    break;
                }
            }
            while (true) {
                cout << "Give your nf value (must be a positive integer): ";
                cin >> nf;

                if (cin.fail() || nf <= 0) {
                    cout << "Invalid input. Please enter a positive integer." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } else {
                    break;
                }
            }

            if (ni > nf) {
                break; 
            } else {
                cout << "ni must be greater than nf for an emission transition. Try again.\n";
            }
        }

        double E = 13.6 * pow(Z, 2) * (1.0 / ni - 1.0 / nf);

        char unit;
        while (true) {
            cout << "Do you want the answer in eV or joules? (e/J): ";
            cin >> unit;

            if (unit == 'e' || unit == 'J') {
                break;
            } else {
                cout << "Invalid input, try again.\n";
            }
        }

        if (unit == 'e') {
            cout << "Energy = " << E << " eV\n";
        } else {
            double E_J = E * 1.602e-19;
            cout << "Energy = " << E_J << " J\n";
        }


        while (true) {
            cout << "Go again? (y/n): ";
            cin >> again;

            if (again == 'y' || again == 'n') {
                break;
            } else {
                cout << "Invalid input, only enter 'y' or 'n'.\n";
            }
        }

        if (again == 'n') {
            cout << "Programme terminated\n";
            return 0;
        }
    }
}

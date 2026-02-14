#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>

using namespace std;

//function used to make sure input is positive
int getPositiveInt(const string& prompt) {
    int value;

    while (true) {
        cout << prompt;
        cin >> value;
        //if input is less than zero display error message and redo step
        if (cin.fail() || value <= 0) {
            cout << "Invalid input. Please enter a positive integer." << endl; 
            cin.clear(); // clear error flag to stop infinite loop
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore all of invalid input 
        } else {
            return value; // valid input
        }
    }
}

int main() {
    const double eV = 1.602e-19; // 1eV in J
    string again = "y"; //Inially again = "y" so that loop can start

    while (true) {  // main loop
        int Z, ni, nf;

        Z = getPositiveInt("Give your Z value (must be a positive integer): "); //Call getPositiveInt for Z value

        // validation loop for ni and nf, in a separate loop so you don't have to reinput Z if ni < nf
        while (true) {
            ni = getPositiveInt("Give your ni value (must be a positive integer): "); //Call getPositiveInt for Z value
            nf = getPositiveInt("Give your nf value (must be a positive integer): "); //Call getPositiveInt for Z value

            if (ni > nf) {
                break;  // valid transition
            } else {
                cout << "ni must be greater than nf. Try again." << endl; //ni < nf not valid, so repeats
            }
        }

        double E = 13.6 * pow(Z, 2) * (1.0 / pow(nf,2)- 1.0 / pow(ni,2)); //calculation of energy in eV

        string unit;

        while (true) {
            cout << "Do you want the answer in eV or joules? (e/J): "; //asks what unit user wants in
            cin >> unit;

            if (unit.length() == 1 && unit == "e" || unit == "J") {
                break; //if input is e or J then it is valid
            } else {
                cout << "Invalid input, try again." << endl; //otherwise the user is asked again
            }
        }

        if (unit == "e") {
            cout << "Energy = " << E << " eV" << endl; //calculation already done in eV
        } else {
            double E_J = E * eV; //convert from eV to J
            cout << scientific << setprecision(3); //sets precision to 3dp
            cout << "Energy = " << E_J << " J" << endl; //prints answer in J
        }

        while (true) {
            cout << "Go again? (y/n): "; //asks user if they want to repeat
            cin >> again;


            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore all of invalid input 

            if (again.length() == 1 && (again == "y" || again == "n")) { 
                break; //'y' and 'n' are the only valid inputs. If again == y, main is repeated
            } else {
                cout << "Invalid input, only enter 'y' or 'n'." << endl; //ignore invalid inputs and ask again
            }
        }

        if (again == "n") {
            cout << "Programme terminated" << endl; //if again == n chosen terminate programme
            return 0; //ends script
        }
    }
}


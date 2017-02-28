#include <iostream>

#include "polynomial.h"

using namespace std;


int main()
{
    Polynomial poly1;
    Polynomial poly2;
    Polynomial result;
    // run the main menu until the user exits
    while (true)
    {
        // print out the main menu
        cout << "******Main Menu******" << endl;
        cout << "Enter Polynomial 1 (1)" << endl;
        cout << "Enter Polynomial 2 (2)" << endl;
        cout << "Add Polynomials (3)" << endl;
        cout << "Exit (4)" << endl;
        cout << "Select One (1-4): " << flush;
        // read the choice
        int choice = -1;
        cin >> choice;
        // ignore the new line character so the polynomials read correctly
        cin.clear();
        cin.ignore(10000, '\n');
        // switch for the selected choice
        switch(choice)
        {
        case 1:
            try
            {
                // ask the user to enter their first polynomial
                cout << "Enter your first polynomial: " << flush;
                cin >> poly1;
            }
            catch(TermException e)
            {
                // print out the error message if we couldn't read the polynomial
                cout << "Invalid Polynomial: \"" << e.what() << '"' << endl;
            }
            break;
        case 2:
            try
            {
                // ask the user to enter their second polynomial
                cout << "Enter your second polynomial: " << flush;
                cin >> poly2;
            }
            catch(TermException e)
            {
                // print out the error message if we couldn't read the polynomial
                cout << "Invalid Polynomial: \"" << e.what() << '"' << endl;
            }
            break;
        case 3:
            // clear the result then add the two polynomials into it
            result.clear();
            result += poly1;
            result += poly2;
            cout << "Adding: " << poly1 << " added to " << poly2 << " is " << result << endl;
            break;
        case 4:
            // exit the program
            return 1;
        default:
            // tell the user that that is not a choice
            cout << "Invalid Choice" << endl;
            break;
        }
    }
}

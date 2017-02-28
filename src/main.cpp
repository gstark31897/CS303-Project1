#include <iostream>

#include "polynomial.h"

using namespace std;


int main()
{
    Polynomial poly1;
    Polynomial poly2;
    Polynomial result;

    while (true)
    {
        cout << "******Main Menu******" << endl;
        cout << "Enter Polynomial 1 (1)" << endl;
        cout << "Enter Polynomial 2 (2)" << endl;
        cout << "Add Polynomials (3)" << endl;
        cout << "Exit (4)" << endl;
        cout << "Select One (1-4): " << flush;

        int choice = -1;
        cin >> choice;

        cin.clear();
        cin.ignore(10000, '\n');

        switch(choice)
        {
        case 1:
            try
            {
                cout << "Enter your first polynomial: " << flush;
                cin >> poly1;
            }
            catch(TermException e)
            {
                cout << "Invalid Polynomial: \"" << e.what() << '"' << endl;
            }
            break;
        case 2:
            try
            {
                cout << "Enter your second polynomial: " << flush;
                cin >> poly2;
            }
            catch(TermException e)
            {
                cout << "Invalid Polynomial: \"" << e.what() << '"' << endl;
            }
            break;
        case 3:
            result = poly1;
            result += poly2;
            cout << "Adding: " << poly1 << " added to " << poly2 << " is " << result << endl;
            break;
        case 4:
            return 1;
        default:
            cout << "Invalid Choice" << endl;
            break;
        }
    }
}

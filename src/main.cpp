#include <iostream>

#include "polynomial.h"

using namespace std;


int main()
{
    Polynomial poly1;
    Polynomial poly2;

    while (true)
    {
        cout << "Main Menu (select one)" << endl;
        cout << "Enter Polynomial 1 (1)" << endl;
        cout << "Enter Polynomial 2 (2)" << endl;
        cout << "Add Polynomials (3)" << endl;
        cout << "Exit (4)" << endl;

        int choice = -1;
        cin >> choice;

        cin.clear();
        cin.ignore(10000, '\n');

        if (choice == 1)
        {
            cout << "Enter your polynomial: " << endl;
            cin >> poly1;
        }
        else if (choice == 2)
        {
            cout << "Enter your second polynomial: ";
            cin >> poly2;
        }
        else if (choice == 3)
        {
            Polynomial result = poly1;
            result += poly2;
            cout << poly1 << " added to " << poly2 << " is " << result << endl;;
        }
        else if (choice == 4)
        {
            return 0;
        }
        else
        {
            cout << "Invalid Choice" << endl;
        }
    }
}

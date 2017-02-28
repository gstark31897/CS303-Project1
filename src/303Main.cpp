#include <iostream>

#include "polynomial.h"

using namespace std;


int main()
{
    Polynomial poly1;
    Polynomial poly2;
    
    int choice = -1;
    bool choice1 = true;

    while (choice1)
    {
        cout << "Main Menu (select one)" << endl;
        cout << "Enter Polynomial 1 (1)" << endl;
        cout << "Enter Polynomial 2 (2)" << endl;
        cout << "Add Polynomials (3)" << endl;
        cout << "Exit (4)" << endl;

        //int choice = -1;
        cin >> choice;

        //gavin these two lines are the problem.  when they are in, it gets stuck on whatever menu choice you make
        //when they are commented out it doesnt let you enter polynomials.
        
        cin.clear();
        cin.ignore(10000, '\n');

        //if else if is more memory efficient than a switch then we can use else if
        //i just like swtiches.
        switch(choice)
        {
            case 1: 
            {
                cout << "Enter your polynomial: " << endl;
                cin >> poly1;
                //choice1 = true;
                break;
            }
            
            case 2:
            {
                cout << "Enter your second polynomial" << endl;
                cin >> poly2;
                //choice1 = true;
                break;
            }

            case 3: 
            {
                Polynomial result = poly1;
                result += poly2;
                cout << poly1 << " added to " << poly2 << " is " << result << endl;
                //choice1 = true;
                break;
            }

            case 4:
            {
                choice1 = false;
                break;
            }
            
            default:
            {
                cout << "Invalid Choice" << endl;
                //choice1 = true; 
                break;
            }
        }
                
        /*if (choice == 1)
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
        }*/
    }
}

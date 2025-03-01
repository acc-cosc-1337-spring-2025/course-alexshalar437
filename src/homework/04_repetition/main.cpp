//write include statements
#include <iostream>
#include "repetition.h"
//write using statements
using namespace std;
//write code
int main() {
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1 - Factorial\n";
        cout << "2 - Greatest Common Divisor\n";
        cout << "3 - Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int num;
            cout << "Enter a number: ";
            cin >> num;
            cout << "Factorial of " << num << " is " << factorial(num) << endl;
        } 
        else if (choice == 2) {
            int num1, num2;
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;
            cout << "GCD of " << num1 << " and " << num2 << " is " << gcd(num1, num2) << endl;
        } 
        else if (choice == 3) {
            char confirm;
            cout << "Are you sure you want to exit? (y/n): ";
            cin >> confirm;
            if (confirm == 'y' || confirm == 'Y') {
                break;
            }
        } 
        else {
            cout << "Invalid choice. Please try again.\n";
        }
    } while (true);

    return 0;
}
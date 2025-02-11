//write include statements

#include <iostream>
#include "hwexpressions.h"
#include "hwexpressions.cpp"


//write namespace using statement for cout

using namespace std;

int main() {
    double meal_amount, tip_rate, tip_amount, tax_amount, total;

    // Get meal amount from user
    cout << "Enter meal amount: ";
    cin >> meal_amount;

    // Calculate sales tax
    tax_amount = get_sales_tax_amount(meal_amount);

    // Get tip rate from user
    cout << "Enter tip percentage (e.g., enter 15 for 15%): ";
    cin >> tip_rate;
     tip_rate/= 100; // Convert percentage to decimal

    // Calculate tip amount
    tip_amount = get_tip_amount(meal_amount, tip_rate);

    // Calculate total cost
    total = meal_amount + tax_amount + tip_amount;

    // Display the receipt
    cout << "\nReceipt:\n";
    cout << "Meal Amount:   $" << meal_amount << endl;
    cout << "Sales Tax:     $" << tax_amount << endl;
    cout << "Tip Amount:    $" << tip_amount << endl;
    cout << "Total:         $" << total << endl;

    return 0;
}

#include "hwexpressions.h"

//example
int add_numbers(int num1, int num2)
{
	return num1 + num2;
}

//write function code here

double get_sales_tax_amount(double meal_amount);
const double TAX_RATE = 0.0675;
double get_sales_tax_amount(double meal_amount) {
    return meal_amount * TAX_RATE;
}
double get_tip_amount(double meal_amount, double tip_rate) {
	return meal_amount * tip_rate; 
}

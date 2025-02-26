//write include statements
#include <iostream>
#include "decisions.h"

int main() {
    int choice;
    std::cout << "MAIN MENU\n";
    std::cout << "1 - Letter grade using if\n";
    std::cout << "2 - Letter grade using switch\n";
    std::cout << "3 - Exit\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    if (choice == 1 || choice == 2) {
        int grade;
        std::cout << "Enter a numerical grade (0-100): ";
        std::cin >> grade;

        if (grade < 0 || grade > 100) {
            std::cout << "The number is out of range.\n";
        } else {
            std::string result = (choice == 1) ? get_letter_grade_using_if(grade) 
                                               : get_letter_grade_using_switch(grade);
            std::cout << "The letter grade is: " << result << "\n";
        }
    } else if (choice == 3) {
        std::cout << "Exiting program...\n";
    } else {
        std::cout << "Invalid choice.\n";
    }

    return 0;
}
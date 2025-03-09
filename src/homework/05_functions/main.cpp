
#include <iostream>
#include "func.h"

int main() {
    int choice;
    std::string dna;

    do {
        std::cout << "Menu\n";
        std::cout << "1- Get GC Content\n";
        std::cout << "2- Get DNA Complement\n";
        std::cout << "3- Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        if (choice == 1) {
            std::cout << "Enter DNA string: ";
            std::cin >> dna;
            std::cout << "GC Content: " << get_gc_content(dna) << std::endl;
        } 
        else if (choice == 2) {
            std::cout << "Enter DNA string: ";
            std::cin >> dna;
            std::cout << "DNA Complement: " << get_dna_complement(dna) << std::endl;
        }

    } while (choice != 3);

    return 0;
}

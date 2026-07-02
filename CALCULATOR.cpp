#include <iostream>

int main() {
    double num1, num2;
    char op;
    char choice = 'y';

    while (choice == 'y' || choice == 'Y') {
        std::cout << "=================================\n";
        std::cout << "        SIMPLE CALCULATOR        \n";
        std::cout << "=================================\n";

        std::cout << "Enter first number: ";
        std::cin >> num1;
        std::cout << "Enter an operator (+, -, *, /): ";
        std::cin >> op;
        std::cout << "Enter second number: ";
        std::cin >> num2;

        std::cout << "\nResult: ";
        switch (op) {
            case '+':
                std::cout << num1 << " + " << num2 << " = " << num1 + num2 << "\n";
                break;
            case '-':
                std::cout << num1 << " - " << num2 << " = " << num1 - num2 << "\n";
                break;
            case '*':
                std::cout << num1 << " * " << num2 << " = " << num1 * num2 << "\n";
                break;
            case '/':
                if (num2 != 0) {
                    std::cout << num1 << " / " << num2 << " = " << num1 / num2 << "\n";
                } else {
                    std::cout << "Error! Division by zero is undefined.\n";
                }
                break;
            default:
                std::cout << "Invalid operator choice.\n";
                break;
        }

        std::cout << "\nDo you want to perform another calculation? (y/n): ";
        std::cin >> choice;
        std::cout << "\n";
    }

    std::cout << "Exiting calculator. Goodbye!\n";
    return 0;
}
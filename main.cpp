#include <iostream>
#include <string>
#include <map>
#include <stdexcept>

#include "utils.hpp"

int main() {
    std::map<std::string, std::string> users;
    bool logged_in = false;
    std::string current_user;
    int choice;

    while (true) {
        std::cout << "\nMenu\n";

        if (!logged_in) {
            std::cout << "1. Sign up\n";
            std::cout << "2. Login\n";
            std::cout << "3. Exit\n";
        } else {
            std::cout << "1. Logout\n";
            std::cout << "2. Exit\n";
        }

        std::string input;
        std::cout << "Enter choice: ";
        std::getline(std::cin, input);

        try {
            choice = std::stoi(input);
        } catch (...) {
            std::cout << "Invalid choice.\n";
            continue;
        }

        if (!logged_in) {
            if (choice == 1) {
                std::string email;
                std::string password;

                while (true) {
                    std::cout << "Enter email: ";
                    std::getline(std::cin, email);

                    try {
                        check_email(email);
                        break;
                    } catch (const std::invalid_argument& e) {
                        std::cout << e.what() << "\n";
                        std::cout << "Please try again.\n";
                    }
                }

                std::cout << "Enter password: ";
                std::getline(std::cin, password);

                users[email] = password;
                std::cout << "Sign up successful.\n";
            }
            else if (choice == 2) {
                std::string email;
                std::string password;

                std::cout << "Enter email: ";
                std::getline(std::cin, email);

                std::cout << "Enter password: ";
                std::getline(std::cin, password);

                if (users.find(email) != users.end() && users[email] == password) {
                    logged_in = true;
                    current_user = email;
                    std::cout << "Login successful.\n";
                } else {
                    std::cout << "Invalid email or password.\n";
                }
            }
            else if (choice == 3) {
                std::cout << "Exiting program.\n";
                break;
            }
            else {
                std::cout << "Invalid choice.\n";
            }
        } else {
            if (choice == 1) {
                logged_in = false;
                current_user = "";
                std::cout << "Logged out successfully.\n";
            }
            else if (choice == 2) {
                std::cout << "Exiting program.\n";
                break;
            }
            else {
                std::cout << "Invalid choice.\n";
            }
        }
    }

    return 0;
}

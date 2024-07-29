#include <iostream>
#include <string>
#include "encryptor.h"
#include "storage.h"

void showMenu() {
    std::cout << "Password Manager CLI\n";
    std::cout << "1. Save Password\n";
    std::cout << "2. Load Password\n";
    std::cout << "3. Exit\n";
    std::cout << "Choose an option: ";
}

int main() {
    int choice;
    std::string username, password;

    while (true) {
        showMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter username: ";
                std::cin >> username;
                std::cout << "Enter password: ";
                std::cin >> password;
                Storage::savePassword(username, Encryptor::encrypt(password));
                std::cout << "Password saved successfully.\n";
                break;

            case 2:
                std::cout << "Enter username: ";
                std::cin >> username;
                password = Storage::loadPassword(username);
                if (!password.empty()) {
                    std::cout << "Password: " << Encryptor::decrypt(password) << "\n";
                } else {
                    std::cout << "No password found for the given username.\n";
                }
                break;

            case 3:
                std::cout << "Exiting...\n";
                return 0;

            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    }

    return 0;
}

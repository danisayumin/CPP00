#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>

bool isNumber(const std::string& str) {
    for (size_t i = 0; i < str.length(); i++) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

int main() {
    PhoneBook phoneBook;
    std::string command;

    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);

        if (command == "ADD") {
            Contact contact;
            std::string input;

            std::cout << "Enter first name: ";
            std::getline(std::cin, input);
            contact.setFirstName(input);

            std::cout << "Enter last name: ";
            std::getline(std::cin, input);
            contact.setLastName(input);

            std::cout << "Enter nickname: ";
            std::getline(std::cin, input);
            contact.setNickname(input);

            std::cout << "Enter phone number: ";
            std::getline(std::cin, input);
            contact.setPhoneNumber(input);

            std::cout << "Enter darkest secret: ";
            std::getline(std::cin, input);
            contact.setDarkestSecret(input);

            phoneBook.addContact(contact);
        } else if (command == "SEARCH") {
            phoneBook.displayContacts();

            std::string indexInput;
            std::cout << "Enter index: ";
            std::getline(std::cin, indexInput);

            if (!isNumber(indexInput)) {
                std::cout << "Invalid index! Please enter a number." << std::endl;
                continue;
            }

            int index = atoi(indexInput.c_str());

            if (index >= 0 && index < phoneBook.getContactCount()) {
                phoneBook.displayContactDetails(index);
            } else {
                std::cout << "Invalid index!" << std::endl;
            }
        } else if (command == "EXIT") {
            break;
        } else {
            std::cout << "Invalid command!" << std::endl;
        }
    }

    return 0;
}

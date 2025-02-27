#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <cstdlib>  // Para usar atoi

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

            // Usar atoi para converter a string em um inteiro
            int index = atoi(indexInput.c_str());

            // Verificar se o índice é válido
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
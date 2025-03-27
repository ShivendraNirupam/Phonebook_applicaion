#include <bits/stdc++.h>
#include "backend.cpp"

class user_interface : public perform_Task {

public:
    int selection;

    void print() {
        std::cout << "Welcome User.... \n";
    }

    void addContact() {
        while (true) {
            std::cout << "--------------------------------------- \n";
    
            std::cout << "Enter the name: ";
            std::string nameUser;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, nameUser);
    
            while (isNameInFile(nameUser)) {
                std::cout << "Name already exists in the contacts file, try a new name: ";
                std::getline(std::cin, nameUser);
            }
    
            std::cout << "Enter the email: ";
            std::string email;
            std::getline(std::cin, email);
    
            std::cout << "Enter the User number: ";
            long long number;
            std::cin >> number;
    
            std::cout << "Enter the country code: ";
            int countryCode;
            std::cin >> countryCode;
    
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input! Please enter valid details.\n";
                continue;
            }
    
            process_adding(nameUser, number, countryCode, email);
    
            char val;
            std::cout << "Do you want to add more users? (Y/N): ";
            std::cin >> val;
    
            if (std::tolower(val) != 'y') {
                std::cout << "Back to the main menu.\n";
                userInterface();
                break;
            }
        }
        std::cout << "--------------------------------------- \n";
    }
    

    void searchContact() {
        std::cout << "Let's find the user number\n";
        std::string nameSearch;
        std::cout << "Enter the User Name: ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, nameSearch);
        process_searching(nameSearch);
    }

    void deleteContact() {
        std::cout << "Deleting the contact\n";
        std::string nameSearch;
        std::cout << "Enter the contact name to be deleted: ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, nameSearch);
        process_deleting(nameSearch);
    }

    void displayContacts(){
        process_display();
    }
    
    void sendEmailvia() {
        process_email();
    }

    void performTask(int select) {
        switch (select) {
            case 1:
                addContact();
                break;
            case 2:
                searchContact();
                break;
            case 3:
                deleteContact();
                break;
            case 4:
                displayContacts();
                break;
            case 5:
                sendEmailvia();  
                break;
            case 6:
                std::cout << "Exiting the application. Goodbye!\n";
                exit(0);
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                userInterface();
                break;
        }
    }

    void userInterface() {
        while (true) {
            std::cout << "--------------------------------------- \n";
            std::cout << "Enter the number for the following options: \n";
            std::cout << "1. Add contact\n";
            std::cout << "2. Search contact\n";
            std::cout << "3. Delete contact\n";
            std::cout << "4. Display all contacts\n";
            std::cout << "5. Send mail\n";
            std::cout << "6. Exit\n";
            std::cout << "--------------------------------------- \n";
            std::cout << "Your choice: ";
            std::cin >> selection;

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a valid number.\n";
                continue;
            }

            performTask(selection);
        }
    }
};

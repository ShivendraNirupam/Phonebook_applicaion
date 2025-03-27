#include <bits/stdc++.h>
#include <fstream>
#include <regex>

class manage_Data {
public:
    std::map<std::string, std::map<int, std::map<std::string, std::pair<long long, std::string>>>> userData; 
    std::map<std::string, std::map<int, int>> countryCheck; 

    manage_Data() {
        countryCheck["United States"] = {{1, 10}};
        countryCheck["Canada"] = {{1, 10}};
        countryCheck["India"] = {{91, 10}};
        countryCheck["United Kingdom"] = {{44, 10}};
        countryCheck["Australia"] = {{61, 9}};
        countryCheck["China"] = {{86, 11}};
        countryCheck["Japan"] = {{81, 10}};
        countryCheck["Germany"] = {{49, 11}};
        countryCheck["France"] = {{33, 9}};
        countryCheck["Italy"] = {{39, 10}};
        countryCheck["Brazil"] = {{55, 11}};
        countryCheck["Russia"] = {{7, 10}};
        countryCheck["South Africa"] = {{27, 9}};
        countryCheck["Spain"] = {{34, 9}};
        countryCheck["South Korea"] = {{82, 11}};
        countryCheck["Mexico"] = {{52, 10}};
        countryCheck["Indonesia"] = {{62, 11}};
        countryCheck["Argentina"] = {{54, 10}};
        countryCheck["Turkey"] = {{90, 10}};
        countryCheck["Saudi Arabia"] = {{966, 9}};
        countryCheck["Nigeria"] = {{234, 10}};
        countryCheck["Egypt"] = {{20, 10}};
        countryCheck["UAE"] = {{971, 9}};
        countryCheck["Iran"] = {{98, 10}};
        countryCheck["Pakistan"] = {{92, 10}};

        loadFromFile();
    }
    bool isNameInFile(const std::string& nameUser) {
      std::ifstream file("Contacts.txt");
      if (!file) {
          std::cerr << "Error opening the file.\n";
          return false;
      }
  
      std::string countryName, userName, email;
      int countryCode;
      long long number;
  
      while (file >> countryName >> countryCode >> userName >> number >> email) {
          if (userName == nameUser) {
              file.close();
              return true; 
          }
      }
  
      file.close();
      return false; 
  }
  

    void saveToFile() {
        std::ofstream file("Contacts.txt");
        if (!file) {
            std::cerr << "Error opening the file.\n";
            return;
        }

        for (const auto& [countryName, countryData] : userData) {  
            for (const auto& [countryCode, users] : countryData) {
                for (const auto& [name, data] : users) {
                    file << countryName << " " << countryCode << " " << name << " " << data.first << " " << data.second << "\n";
                }
            }
        }

        file.close();
    }

    void loadFromFile() {
        std::ifstream file("Contacts.txt");
        if (!file) {
            std::cerr << "Error opening the file.\n";
            return;
        }

        std::string countryName, userName, email;
        int countryCode;
        long long number;

        while (file >> countryName >> countryCode >> userName >> number >> email) {
            userData[countryName][countryCode][userName] = {number, email};
        }

        file.close();
    }

    bool isValidEmail(const std::string& email) {
        const std::regex pattern(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");
        return std::regex_match(email, pattern);
    }
    

  
};

class perform_Task : public manage_Data {
public:
 void process_adding(std::string userName, long long number, int countryCode, std::string email) {
  std::string countryName;

  for (const auto& [name, codeData] : countryCheck) {
      if (codeData.count(countryCode)) {
          countryName = name;
          break;
      }
  }

  if (countryName.empty()) {
      std::cout << "Invalid country code!\n";
      return;
  }

  while (userData[countryName][countryCode].find(userName) != userData[countryName][countryCode].end()) {
      std::cout << "Name already exists, try a new name: ";
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::getline(std::cin, userName);
  }

  int maxDigits = countryCheck[countryName][countryCode];
  int numberLength = std::to_string(number).length();
  if (numberLength != maxDigits) {
      std::cout << "Error: Phone number must be exactly " << maxDigits << " digits for this country!\n";
      return;
  }

  if (!isValidEmail(email)) {
      std::cout << "Invalid email format! Please enter a valid email.\n";
      return;
  }

  userData[countryName][countryCode][userName] = {number, email};
  std::cout << "User added: " << countryName << " +" << countryCode << " " << number << " (" << userName << ") " << email << "\n";

  manage_Data::saveToFile();
 }


    void process_searching(const std::string& userName) {
        bool found = false;

        for (const auto& [countryName, countryData] : userData) {
            for (const auto& [countryCode, users] : countryData) {
                auto it = users.find(userName);
                if (it != users.end()) {
                    std::cout << "Contact found: " << userName << "\n";
                    std::cout << "Country: " << countryName << "\n";
                    std::cout << "Number: +" << countryCode << " " << it->second.first << "\n";
                    std::cout << "Email: " << it->second.second << "\n";
                    found = true;
                    break;
                }
            }
            if (found) break;
        }

        if (!found) {
            std::cout << "Contact not found.\n";
        }
    }
    void process_deleting(const std::string& userName) {
      bool found = false;
  
      for (auto& [countryName, countryData] : userData) {
          for (auto& [countryCode, users] : countryData) {
              auto it = users.find(userName);
              if (it != users.end()) {
                  users.erase(it);
                  std::cout << "Contact deleted: " << userName << "\n";
                  found = true;
  
                  if (users.empty()) {
                      countryData.erase(countryCode);
                  }
  
                  if (countryData.empty()) {
                      userData.erase(countryName);
                  }
  
                  saveToFile();
                  return;
              }
          }
      }
  
      if (!found) {
          std::cout << "Contact not found.\n";
      }
  }

  void process_display(){
    std::cout << "--------------------------------------- \n";
        std::cout << "Displaying all contacts:\n";
        
        if (userData.empty()) {
            std::cout << "No contacts available.\n";
        } else {
            for (const auto& [countryName, countryData] : userData) {
                for (const auto& [countryCode, users] : countryData) {
                    for (const auto& [name, data] : users) {
                        std::cout << "Name: " << name << "\n";
                        std::cout << "Country: " << countryName << "\n";
                        std::cout << "Number: +" << countryCode << " " << data.first << "\n";
                        std::cout << "Email: " << data.second << "\n";
                        std::cout << "--------------------------------------- \n";
                    }
                }
            }
        }
  }

  void process_email(){
    std::cout << "--------------------------------------- \n";
        std::cout << "Sending an email\n";
        std::string nameSearch;
        std::cout << "Enter the contact name to send email to: ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, nameSearch);

        bool found = false;
        std::string email;
        
        for (const auto& [countryName, countryData] : userData) {
            for (const auto& [countryCode, users] : countryData) {
                auto it = users.find(nameSearch);
                if (it != users.end()) {
                    email = it->second.second;
                    found = true;
                    break;
                }
            }
            if (found) break;
        }

        if (!found) {
            std::cout << "Contact not found.\n";
            return;
        }

        std::string message;
        std::cout << "Enter the message to send to " << nameSearch << " (" << email << "): ";
        std::getline(std::cin, message);

        std::cout << "Simulating email send...\n";
        std::cout << "To: " << email << "\n";
        std::cout << "Message: " << message << "\n";
        std::cout << "Email sent successfully (simulated).\n";
  }
};

#Phone_Book
##Overview
This project is a Contact Management System that allows users to store, search, delete, and display contact information, as well as simulate sending emails to contacts. The system supports contacts from various countries with validation for phone numbers and email addresses.

##Features
Add Contacts: Store contact details including name, phone number, country code, and email.

Search Contacts: Find contacts by name and display their details.

Delete Contacts: Remove contacts from the system.

Display All Contacts: View all stored contacts in an organized manner.

Send Email: Simulate sending an email to a contact.

Data Persistence: Contacts are saved to and loaded from a file (Contacts.txt).

##Requirements
C++ compiler (supporting C++11 or later)

Standard Library headers (<bits/stdc++.h>, <fstream>, <regex>, etc.)

#Usage
Compile the Program:

bash
Copy
g++ main.cpp -o contact_manager
Run the Program:

bash
Copy
./contact_manager
Menu Options:

1. Add Contact: Enter the contact's name, email, phone number, and country code. The system validates the input and ensures uniqueness.

2. Search Contact: Enter a name to search for the contact's details.

3. Delete Contact: Enter a name to delete the contact.

4. Display All Contacts: View all stored contacts.

5. Send Email: Enter a contact's name and compose a message to simulate sending an email.

6. Exit: Close the application.

##File Structure
main.cpp: Entry point of the program, initializes the interface.

interface.cpp: Handles user interactions and menu navigation.

backend.cpp: Implements core functionalities like adding, searching, deleting contacts, and file operations.

##Data Storage
Contacts are stored in Contacts.txt with the following format:

Copy
CountryName CountryCode UserName PhoneNumber Email
Validation Rules
Phone Numbers: Validated based on country-specific digit lengths.

Emails: Validated using a regex pattern to ensure correct format.

Unique Names: Ensures no duplicate contact names are allowed.

Supported Countries
The system supports phone numbers from various countries, including:

United States, Canada, India, United Kingdom, Australia, China, Japan, Germany, France, Italy, Brazil, Russia, and more.

##Example Usage
Add a contact:

Copy
Name: John Doe
Email: john@example.com
Phone Number: 1234567890
Country Code: 1 (for United States)
Search for "John Doe" to view details.

Send an email to "John Doe" with a custom message.

##Notes
The email sending feature is simulated and does not actually send emails.

The program handles invalid inputs gracefully and prompts the user to re-enter data if necessary.

##License
This project is open-source and available for free use. Modify and distribute as needed.

# Contact Management System  

A C++ application to manage contacts with phone/email validation and file storage.  

---

## Features  

### Core Functions  
- **Add Contacts**: Store name, phone number, country code, and email.  
- **Search Contacts**: Find contacts by name.  
- **Delete Contacts**: Remove entries permanently.  
- **Display All Contacts**: View all saved contacts.  
- **Send Email (Simulated)**: Pretend to email a contact.  

### Validation  
- ✅ Phone numbers: Country-specific digit checks.  
- ✅ Emails: Regex format validation.  
- ✅ Unique names: No duplicates allowed.  

---

## How to Use  

### Compile and Run  
- Go to the phonebook directory.
- Type the following command in the terminal.
- g++ main.cpp interface.cpp backend.cpp -o {write your output file name replacing the bracket}.
- then run it using main.exe or ./main.exe

---


## File structure
.
### Program entry point
├── main.cpp 
### User menus and input
├── interface.cpp 
### Core logic and file handling
├── backend.cpp   
### Auto-generated contact database
└── Contacts.txt      

---

### Data Storage
CountryName CountryCode UserName PhoneNumber Email

---

## Notes
-- The email is simulated and not really send the email.




# Phonebook Project
The Phonebook Project is a simple command-line application written in C that allows users to manage a list of contacts. It provides functionality for adding, editing, deleting, searching, and saving contacts to a CSV file. Additionally, it includes features for preventing duplicate entries and user authentication.

## Features
- **Add Contacts**: Users can add new contacts by providing a name and phone number.
- **Edit Contacts**: Existing contacts can be edited to update their name or phone number.
- **Delete Contacts**: Users can delete unwanted contacts from the phonebook.
- **Search Contacts**: A search function allows users to find contacts by name or phone number.
- **Prevent Duplicate Entries**: The application prevents the addition of duplicate contacts.
- **User Authentication**: User authentication ensures that only authorized users can access and modify the phonebook.
- **Save Data**: The phonebook data is stored in a CSV file on the local host for persistence.

## Installation
### Windows
1. Install [MinGW](https://sourceforge.net/projects/mingw/) and [git](https://git-scm.com/downloads).
2. Clone this repository: `git clone https://github.com/JellyFishJuggler/Phone-book`
3. Open the directory: `cd Phone-book`
4. Compile: `gcc .\src\constants.c .\src\functions.c .\src\main.c -o .\main.exe`
5. Run: `.\main.exe`

### Ubuntu/Debian/Arch Linux
1. Clone this repository: `git clone https://github.com/JellyFishJuggler/Phone-book`
2. Compile and run: `cd Phone-book && make run`

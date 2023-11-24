#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "constants.h"
#define MAX_LEN 100
#define MAX_CONTACT_LEN 30

// multiplies the given character "count" times
void multiplyChar(char character, int count, char *prefix, char *suffix) {
  printf("%s", prefix);
  for (int i = 0; i < count; i++)
    printf("%c", character);
  printf("%s", suffix);
}

// prints a nice box around text
void printBox(char *text) {
  int length = strlen(text);
  multiplyChar('-', length+2, "+", "+");
  printf("\n| %s |\n", text);
  multiplyChar('-', length+2, "+", "+");
  printf("\n");
}

char *removeNewline(char *str) {
  for (int i = 0; i < strlen(str); i++) {
    if (str[i] == '\n') str[i] = ' ';
  }
  return str;
}

// lists all contacts
void addContact() {
  // declarations
  char contactName[MAX_CONTACT_LEN];
  char contactNumber[11];
  FILE *file = fopen(filePath,"a");
  
  printBox("Add Contact");
  printf("Enter contact's name (or cancel): ");
  scanf("\n%[^\n]s", contactName);
  if (strcmp(contactName, "cancel") == 0) return;

  printf("Enter contact's number: ");
  scanf("\n%[^\n]s", contactNumber);
  
  fprintf(file, "%s,%s\n", contactName, contactNumber);
  fclose(file);

  printBox("Contact Saved!");
}

// View Contacts
void listContacts() {
  printBox("List Contacts");

  FILE *file = fopen(filePath, "r");

  if (!file) {
  notFound:
    printf("No Contacts Found!\n");
    return;
  }

  char fileRow[MAX_LEN];
  int row = 1, totalRowLength = 32+MAX_CONTACT_LEN;
  bool contactsFound = false;
  
  while(fgets(fileRow,MAX_LEN,file) != NULL) {
    multiplyChar('-', totalRowLength-2, "+", "+");
    printf("\n| %d | ", row);
    char *value = strtok(fileRow, ",");
    int column = 1;
    contactsFound = true;

    while (value != NULL) {
      switch(column) {
      case 1:
	printf("Name: %s", value);
	multiplyChar(' ', MAX_CONTACT_LEN-strlen(value)-2, "", "");
	break;
      case 2:
	printf(" | Phone: %s|\n", removeNewline(value));
	break;
      default:
	break;
      }
      value = strtok(NULL, ",");
      column++;
    }
    row++;
  }

  if (!contactsFound) goto notFound;
  else multiplyChar('-', totalRowLength-2, "+", "+");
  fclose(file);
  printf("\n");
}

// edits a contact
void editContact() {
  printBox("Edit a Contact");
  char line[100], contactName[MAX_CONTACT_LEN];
  printf("Enter name of the contact to be edited: ");
  scanf("\n%[^\n]s", contactName);

  FILE *file = fopen(filePath, "r");
  FILE *file2 = fopen(tempFilePath, "w");

  if (!file || !file2) {
    printf("Error opening files!\n");
    return;
  }

  bool contactFound = false;
  while(fgets(line,sizeof(line), file)){
      if(strstr(line,contactName) == NULL){
	  fputs(line,file2);
      } else {
	char newName[MAX_CONTACT_LEN];
	char newNumber[11];
	printf("Enter new name: ");
	scanf("\n%[^\n]s", newName);
	printf("Enter new number: ");
	scanf("\n%[^\n]s", newNumber);
	char newString[MAX_CONTACT_LEN+15];
	sprintf(newString, "%s,%s\n", newName, newNumber);
	fputs(newString, file2);
	contactFound = true;
      }
  }

  if (!contactFound) {
    printf("Contact not found!\n");
  }

  fclose(file);
  fclose(file2);
  remove(filePath);
  rename(tempFilePath, filePath);
}

// removes a contact
void removeContact() {
  printBox("Remove a Contact");
  char line[100], contactName[MAX_CONTACT_LEN];
  printf("Enter name of the contact to be deleted: ");
  scanf("\n%[^\n]s", (char *) &contactName);

  FILE *file = fopen(filePath, "r");
  FILE *file2 = fopen(tempFilePath, "w");

  bool contactFound = false;
  while(fgets(line,sizeof(line), file)){
      if(strstr(line,contactName) == NULL){
	  fputs(line,file2);
      } else {
	contactFound = true;
      }
  }

  if (contactFound) {
    printf("Contact deleted successfully!\n");
  } else {
    printf("Contact not found!\n");
  }

  fclose(file);
  fclose(file2);
  remove(filePath);
  rename(tempFilePath, filePath);
}

// clears the screen
void clear() {
  if (isWindows) system("cls");
  else system("clear");
}

// exits the program
void quitProgram() {
  printBox("Have a nice day :)");
  exit(0);
}

void handleMenu() {
  bool running = true;
  char userInput[MAX_LEN];
  while (running) {
    printBox("The Kinky PhoneBook");
    for (int i = 0; i < menuOptionCount; i++) {
      printf("%d. %s\n", i+1, menuOptions[i]);
    }
    printf("Enter your choice → ");
    scanf("\n%[^\n]s", (char *) &userInput);
    if (!((int) userInput[0] > 48 && (int) userInput[0] < menuOptionCount + 49)) {
      printBox("Your Input is Sus");
      continue;
    }
    clear();
    switch(atoi(userInput)) {
    case 1:
      listContacts();
      break;
    case 2:
      addContact();
      break;
    case 3:
      editContact();
      break;
    case 4:
      removeContact();
      break;
    case 5:
      quitProgram();
      break;
    }
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
    printf("Press Enter To Continue...\n");
    getchar();
    clear();
  }
}

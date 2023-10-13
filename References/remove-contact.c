/*isme 2 file ka use hai - already created vali aur dusri jisme naya data add hoga
    */

#include<stdio.h>
#include<string.h>

// Function to delete a contact from the CSV file
int main() {
    char entryToDelete[100]; // Adjust the size as needed

    FILE *originalFile = fopen("C:\\Users\\srija\\OneDrive\\Documents\\GitHub\\Phone-book\\contacts.csv", "r");
    FILE *tempFile = fopen("D:\\Phone-book\\temp.csv", "w");

    if (originalFile == NULL || tempFile == NULL) {
        printf("Error opening files.");
        return 1;
    }

    printf("Enter the contact to delete (Name,Phone): ");
    scanf("%s", entryToDelete);

    char line[1000]; // Adjust the size as needed

    while (fgets(line, sizeof(line), originalFile)) {
        if (strstr(line, entryToDelete) == NULL) {
            // If the line does not contain the entry to delete, write it to the temporary file
            fputs(line, tempFile);
        }
    }

    fclose(originalFile);
    fclose(tempFile);

    remove("contacts.csv"); // Delete the original file
    rename("temp.csv", "contacts.csv"); // Rename the temporary file to the original file name

    printf("Contact deleted successfully.\n");

    return 0;
}
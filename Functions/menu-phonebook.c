// Menu 💀
#include <stdio.h>
#include <string.h>
// #include "add-contact.h"
// #include "read-contact.h"
// #include "remove-contact.h"
int main() {
    int x = 10; // Initialize variables for password and loop control
    char pass[15],riyalpass[15]="123"; 
    while (x != 0)
    {   
        printf("\nInput the password: ");
        scanf("%s", &pass); // Read the password input
        if (strcmp(pass, "Pass") == 0)
        {
            printf("Access granted. Correct password !! Authenticated 🫡😎😼\n\n\n"); // If the password is correct, print a success message        
            x = 0;
            int choice = -1;
            printf("*Contacts*\n");//Thoda innovative sochna padega gaich ☠️🐅
            printf("MENU:\nPress\n1. View all contacts\n2. Add a new contact\n3. Modify an old contact\n4.Search for a contact\n5.Delete a contact\n6.Exit");  
            // Infinite Loop for choice input
            // while(1)
            // {
            //     printf("\nEnter your choice:");
            //     scanf("%d", &choice);
            //     // If-else ladder
            //     if(choice == 1){
            //         //View all contacts
            //     }
            //     else if (choice == 2){
            //      //Add a new contact
            //     }
            //     else if (choice == 3){
            //     //Modify a old contact
            //     }
            //     else if (choice == 4){  
            //      //Search for a contac
            //     }
            //     else if (choice == 5){
            //     //Delete a contact
            //     }
            //     else if (choice == 6){
            //         printf("BYE!!!\n");
            // // Termination of the Loop hehe
            //         break;
            //     }
            //     else{
            //         printf("> Invalid Input\n");
            //     }
            // }
            int choice;
            printf("Enter your choice:");
            scanf("%d",&choice);

            switch (choice > 0)
            {
            case 1:
                read_contact();
                break;
            case 2:
                addcontact();
                break;
            case 3:
                //Edit Function missing
                break;
            case 4:
                //Search Function missing
                break;
            case 5:
                remove_contact();
                break;
            case 6:
                printf("Exited.");
                break;
            default:
                printf("Invalid Choice.");
                break;
            }
        }
        else {
            printf("Pretty sus 🤨. Wrong password, try another"); // If the password is incorrect, prompt for another attempt
        }

        printf("\n");
    }

    return 0;
}

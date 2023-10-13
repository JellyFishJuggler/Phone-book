// Menu 💀
#include <stdio.h>
/*
    switch use krna chahiye tha if-else ke bhjye but thik haii.
    yhi main file hai apni, issi me baki ke saare functions ko link krdenge.
    #include "add-contact.c" aur fir function ko call mar denge.
*/
int main() {
    int choice = -1;
    printf("Contacts");//Thoda innovative sochna padega gaich ☠️🐅
    printf("MENU:\nPress\n1. View all contacts\n2. Add a new contact\n3. Modify an old contact\n4.Search for a contact\n5.Delete a contact\n6. Exit");
    
    // Infinite Loop for choice input
    while(1){
        printf("\nEnter your choice:");
        scanf("%d", &choice);
        
        // If-else ladder
        if(choice == 1){
            //View all contacts
        }
        else if (choice == 2){
            //Add a new contact
        }
        else if (choice == 3){
            //Modify a old contact
        }
        else if (choice == 4){
            //Search for a contact
        }
        else if (choice == 5){
            //Delete a contact
        }
        else if (choice == 6){
            printf("BYE!!!\n");
            // Termination of the Loop hehe
            break;
        }
        else{
            printf("> Invalid Input\n");
        }
    }
    return 0;
}


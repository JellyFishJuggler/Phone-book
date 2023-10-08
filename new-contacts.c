#include<stdio.h>
#include<string.h>

int main(){
    char names[100];            // an array of size of 100
    char phoneNumber[100];      //an array of size of 100

    FILE *file = fopen("contacts.csv","w");     //creates a file and writes it.
    if(file == NULL){
        printf("Error no file found.");
        return 1;
    }

    while (1)                               //always true loop
    {
        printf("Enter the name:");
        scanf("%s",names);

        if(strcmp(names,"exit")==0){        //compares whether the value in 'names' is same as 'exit' or not
            break;
        }

        printf("Enter the contact number:");
        scanf("%s",phoneNumber);

        if (strcmp(phoneNumber,"exit")==0)      //compares whether the value in 'phoneNumber' is same as 'exit' or not
        {
            break;
        }

        fprintf(file,"%s,%s\n",names,phoneNumber);     //stores the data in the created.

        int a;
        printf("You want to enter more? Presss 1 for yes 'n' 2 for no.");
        scanf("%d",&a);

        if(a == 2){
            break;
        }

        fclose(file);         //closing the file is a must.
        printf("Contacts saved.");
        
    }

    return 0;
    
}
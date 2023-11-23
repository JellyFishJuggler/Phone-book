#include<stdio.h>
#include<string.h>

int read_contact(){
    int rows = 0;
    int column = 0;
    
    FILE *file=fopen("C:\\Users\\srija\\Downloads\\github_com\\Phone-book-main\\Phone-book-main\\contacts.csv","r");
    if(file == NULL){
        printf("Fuck off lil nigga");
        return 1;
    }
    char arr[100];
    printf("*************************\n");
    printf("       Contacts   \n");
    printf("*************************\n");

    while(fgets(arr,sizeof(arr),file) != NULL){
        column = 0;
        rows++;
        if(column==1)
            continue;
        char* value = strtok(arr,",");
        while(value){
            if(column==0){
                printf("Name: ");
            }
            if(column==1){
                printf("Contact No.: ");
            }
            printf("%s\n",value);
            value = strtok(NULL,",");
            column++;
        }
        printf("\n");
    }
    fclose(file);
    return 0;
}
#include<stdio.h>
#include<string.h>
int remove_contact(){
    char remov[100];
    FILE* file = fopen("C:\\Users\\srija\\Downloads\\github_com\\Phone-book-main\\Phone-book-main\\contacts.csv","r");
    FILE* file_2 = fopen("C:\\Users\\srija\\Downloads\\github_com\\Phone-book-main\\Phone-book-main\\d_contact.csv","a+");
    
    if(file == NULL || file_2 == NULL){
        printf("Gaand Mara bsdk");
        return 1;
    }

    char line[100];
    printf("Enter the entry to be deleted: ");
    scanf("%s",remov);

    while(fgets(line,sizeof(line),file)){
        if(strstr(line,remov) == NULL){
            fputs(line,file_2);
        }
    }

    fclose(file);
    fclose(file_2);

    remove("C:\\Users\\srija\\Downloads\\github_com\\Phone-book-main\\Phone-book-main\\contacts.csv");
    rename("C:\\Users\\srija\\Downloads\\github_com\\Phone-book-main\\Phone-book-main\\d_contact.csv","C:\\Users\\srija\\Downloads\\github_com\\Phone-book-main\\Phone-book-main\\contacts.csv");   
    return 0;
}

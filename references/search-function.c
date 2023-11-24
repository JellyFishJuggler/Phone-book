#include<stdio.h>
#include<string.h>
int main(){
    char arr[100];
    FILE* file = fopen("C:\\Users\\srija\\Downloads\\github_com\\Phone-book-main\\Phone-book-main\\contacts.csv","r+");
    if(file == NULL){
        printf("File not found.");
    }
    char _searchitem;
    printf("Enter the detail to search. :");
    scanf("%s",_searchitem);
    char result = searchcontact(file,_searchitem);
    return 0;
}

int searchcontact(file,_searchitem){
    
    return 0;
}
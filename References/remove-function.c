/*Create a function to delete a contact from the csv file
Create an array of any size
Open the 'example.txt' file in read mode.
    Just make sure the file exists or not.
Make a new csv file which will contain all entries except the deleted one.
Make a loop which will first get the entry from user, either the name or the phone no, and check that whether the provided entry is in the original csv or not.
    If its found then ignore it and add the rest of the entries in the new csv.
Now, just remove the old file 'n' rename the new file with the same name as of the previous one.
    If we wont be doing this then the whole project will have insane amount of csv files 'n' would be taking a lot of memory.
Just close the files(both of them for obv reasons.)*/

#include<stdio.h>
#include<string.h>

int removefunc(){
    char entryTodelete[500];  //entries aayengi yaha joh delete krni hogi

    FILE *og_file = fopen("example.txt","r");  //file joh hmne add-function me bnyi thi voh open kr rhe hai.
    FILE *n_file = fopen("examples.txt","a+"); //ek nyi temp. file bana rhe hai joh baad me example se replace ho jayegi

    if(og_file==NULL || n_file == NULL){
        printf("Error!");
        return 1;
    }

    char line[1000];    //yeh basically content read krke temp. apne store kr rha hai.
    printf("Enter the entry to be deleted.");
    scanf("%s",entryTodelete);

    while (fgets(line,sizeof(line), og_file)) //fgets bas files ko le rha hai og_file se aur line array me store kr rha hai.
    {
        if(strstr(line,entryTodelete) == NULL){  //strstr pta lgta hai ki first occurence kaha hui h. aur yadi usse nhi milti hai tab voh n_file me add krdeta hai.
            fputs(line,n_file);                      // yaha actually me voh check krta hai ki line array me joh store hua hai, voh agr entrytodelete me hai toh usse ignore krke baki sb ko n_file me add kar deta hai.
        }
    }

// koi bhi file ko open krne ke baad usse close bhi krna hota hai. RUle hai.

    fclose(og_file);
    fclose(n_file);
// yaha hm original file ko remove kr rhe hai aur joh hmne new file bnayi thi usko rename krke original ka naam de rhe hai.
// isse yeh benefit hua hai ki multiple files nhi bn rhi hogyi aur hmesha previouse wali delete hoti rhegi.
    remove("example.txt");
    rename("examples.txt","example.txt");

    printf("Entry Deleted!");

    return 0;
    
}

int main(){
    removefunc();
    return 0;
}
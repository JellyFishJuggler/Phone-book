/* for reference this is how a new document is created.
    'w' is used for creating a new file. aur isme joh data aayega voh last wale se replace hoga hmesha.
    reason being ki yeh hr baar ek file create kr rha hai.
    'a' is used for adding new datas in the already created file.
    'w+' bhi use kr skte hai, yeh hota hai agr hme file ko read bhi krna ho.
    (reading ka smjhna hai toh todha google krlena else maine reading func me dala hai tohda sa)

    same tarike se 'a+' bhi hota hai. jisme hm new data to add karte ja rhe hai but usko phir read bhi
    karpayenge end me ya jab mann kare

    aur finally 'r' jo read karta hai. same tarike se 'r+' bhi hogya jisme read + writing hota hai. 

    'r+' aur 'w+' me kya difference yeh google krlena mai nhi dekh rha ab. T-T
    */
#include <stdio.h>

int addfunc() {
    // Open a file for writing (if it doesn't exist, it will be created)
    FILE *file = fopen("example.txt", "w");

    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    // Write data to the file
    fprintf(file, "Hello\nthis is a sample text.\n");
    fprintf(file, "You can add more text here.\n");

    // Close the file when done
    fclose(file);

    printf("File created and written successfully.\n");
    return 0;
}

int main(){
    addfunc();
    return 0;
}

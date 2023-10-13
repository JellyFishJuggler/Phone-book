/*
    reading ke baare me todha baht jaan lo
    yadi koi file hoti hai hmare paas toh use load karke user ko show karane keliye read use hota hai
    bht hee basic stuff haina....
    bas yhi hai yeh

    aur bhi kuch hote hai jaise rb,wb,ab aur unke '+' variations. inka abhi kaam nhi hai toh chill kro.
*/
#include <stdio.h>

int readfunc() {
    // Open a file for reading
    FILE *file = fopen("example.txt", "r");

    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    char buffer[100]; // Buffer to store read data

    // Read and print data from the file
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }

    // Close the file when done
    fclose(file);

    return 0;
}

int main(){
    readfunc();
    return 0;
}

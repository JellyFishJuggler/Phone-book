#include <stdio.h>

int main() {
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

#include <stdio.h>

int main() {
    // Open a file for writing (if it doesn't exist, it will be created)
    FILE *file = fopen("example.txt", "w");

    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    // Write data to the file
    fprintf(file, "Hello, this is a sample text.\n");
    fprintf(file, "You can add more text here.\n");

    // Close the file when done
    fclose(file);

    printf("File created and written successfully.\n");
    return 0;
}

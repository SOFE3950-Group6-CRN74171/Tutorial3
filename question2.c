#include <stdio.h>

#define ARRAY_SIZE 10

int main() {
    
    FILE *file;
    int numbers[ARRAY_SIZE];

    // Open the file for reading
    file = fopen("question2.txt", "r");

    // Check if the file was opened successfully
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1; // Exit with an error code
    }

    // Read ten integers from the file and store them in the array
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        fscanf(file, "%d", &numbers[i]);
    }

    // Close the file
    fclose(file);

    // Print the contents of the array
    printf("Array contents: ");
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}
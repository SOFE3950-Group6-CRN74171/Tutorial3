#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declare character pointer
    char *professor;
    // Declare integer pointer
    int *student_ids, *grades;

    // Using Calloc to allocate memory {ptr = (cast-type*)calloc(n, element-size);}
    professor = (char *)calloc(256, sizeof(char));

    // Check if memory allocation is successful
    if (professor == NULL) {
        printf("Memory allocation for professor failed.\n");
        return 1;
    }

    // Prompt the professor for their name
    printf("Enter professor's name: ");
    scanf("%255s", professor);  // Limit input to 255 characters to avoid buffer overflow

    // Prompt the professor for the number of students to mark
    int num_students;
    printf("Enter the number of students to mark: ");
    scanf("%d", &num_students);

    // Using malloc to allocate the memory to the number of students and their grade
    // {ptr = (cast-type*) malloc(byte-size)}
    student_ids = (int *)malloc(num_students * sizeof(int));
    grades = (int *)malloc(num_students * sizeof(int));

    // Check if memory allocation is successful
    if (student_ids == NULL)
        printf("Memory allocation for student_ids failed.\n");
    if (grades == NULL) {
        printf("Memory allocation for grades failed.\n");

        // Free previously allocated memory
        free(professor);

        // Free any allocated memory before terminating
        if (student_ids != NULL) {
            free(student_ids);
        }
        if (grades != NULL) {
            free(grades);
        }

        return 1;
    }

    // Free allocated memory before terminating
    free(professor);
    free(student_ids);
    free(grades);

    return 0;
}


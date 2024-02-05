#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the grade struct
struct Grade {
    int student_id;
    int mark;
};

// Function to grade students and calculate statistics
void grade_students(struct Grade *grades, int num_students) {
    // Open the file grades.txt in write mode
    FILE *file = fopen("grades.txt", "w");

    // Check if the file is opened successfully
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    // Initialize variables for sum, mean, and standard deviation
    double sum = 0.0;
    double mean, variance = 0.0, standard_deviation;

    // Write student id and mark to the file and calculate sum
    for (int i = 0; i < num_students; ++i) {
        fprintf(file, "%d %d\n", grades[i].student_id, grades[i].mark);
        sum += grades[i].mark;
    }

    // Calculate mean
    mean = sum / num_students;

    // Calculate variance
    for (int i = 0; i < num_students; ++i) {
        variance += pow(grades[i].mark - mean, 2);
    }
    variance /= num_students;

    // Calculate standard deviation
    standard_deviation = sqrt(variance);

    // Write mean and standard deviation to the file
    fprintf(file, "Average: %.2f\n", mean);
    fprintf(file, "Standard Deviation: %.2f\n", standard_deviation);

    // Close the file
    fclose(file);
}

int main() {
    // Declare pointers
    char *professor;
    struct Grade *grades;

    // Allocate memory for the professor pointer using calloc
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

    // Allocate memory for the grades pointer using malloc
    grades = (struct Grade *)malloc(num_students * sizeof(struct Grade));

    // Check if memory allocation is successful
    if (grades == NULL) {
        printf("Memory allocation for grades failed.\n");

        // Free previously allocated memory
        free(professor);

        return 1;
    }

    // Prompt the professor for student ids and marks
    for (int i = 0; i < num_students; ++i) {
        printf("Enter student id for student %d: ", i + 1);
        scanf("%d", &grades[i].student_id);

        printf("Enter mark for student %d: ", i + 1);
        scanf("%d", &grades[i].mark);
    }

    // Call the function to grade students, calculate statistics, and store results
    grade_students(grades, num_students);

    // Free allocated memory before terminating
    free(professor);
    free(grades);

    return 0;
}
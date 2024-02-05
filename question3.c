#include <stdio.h>

// Student Struct
struct Student {
    //Student struct needs ID, Age, and Start year.
    int student_id;
    int age;
    int start_year;
};

// Function returns void and takes Student struct as an argument
void save_student(struct Student student) {
    // Open the file "student.txt" in append mode
    FILE *file = fopen("students.txt", "a");

    // Check if the file is opened successfully
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    // Save student data to the file
    fprintf(file, "%d,%d,%d\n", student.student_id, student.age, student.start_year);

    // Close the file
    fclose(file);
}

int main() {
    // Create a structure type of student
    struct Student student;

    // Prompt user for input
    printf("Enter student id: ");
    scanf("%d", &student.student_id);

    printf("Enter age: ");
    scanf("%d", &student.age);

    printf("Enter the year started at UOIT: ");
    scanf("%d", &student.start_year);
    //run the function to save input
    save_student(student);

    printf("Done!\n");

    return 0;
}
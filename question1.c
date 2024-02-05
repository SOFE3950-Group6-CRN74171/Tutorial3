#include <stdio.h>

int main() {
    char firstName[50]; 
    int age;
    float height;

    printf("Enter your first name: ");
    scanf("%s", firstName);

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your height (in meters): ");
    scanf("%f", &height);

    printf("\nFirst Name: %s\n", firstName);
    printf("Age: %d\n", age);
    printf("Height: %.2f meters\n", height);

    return 0;
}
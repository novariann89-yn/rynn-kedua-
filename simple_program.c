#include <stdio.h>

int main(void)
{
    // Declare a constant limit and variables to hold input and counter
    const int LIMIT = 3;
    int number = 0;
    int count = 0;

    // Ask the user for a number and read it from the keyboard
    printf("Enter a number: ");
    scanf("%d", &number);

    // Conditional statement: check if the number is even or odd
    if (number % 2 == 0) {
        printf("%d is even.\n", number);
    } else {
        printf("%d is odd.\n", number);
    }

    // Loop statement: repeat until count reaches the limit
    do {
        count++;
        // If this is the second iteration, skip the rest of the loop
        if (count == 2) {
            continue;
        }
        printf("Loop iteration %d\n", count);
    } while (count < LIMIT);

    // Exit the program successfully
    return 0;
}

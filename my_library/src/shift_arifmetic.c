#include <stdio.h>
#include <my_functions.h>

// Function to print the value of the port in binary
void printBinary(unsigned char port) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (port >> i) & 1); // Extract each bit
    }
    printf("\n");
}
// Main logic of the program
void run_shift_arifmetic() {
    unsigned char port = 0x00; // Initial value of the port
    int choice, shift;

    // Print the initial state of the port
    printf("Initial port state:\n");
    printf("Binary form: ");
    printBinary(port);
    printf("Hexadecimal form: 0x%02X\n", port);

    while (1) {
        // Menu for selecting an operation
        printf("\nSelect an operation:\n");
        printf("1. Shift left\n");
        printf("2. Shift right\n");
        printf("3. Set new port value\n");
        printf("4. Exit\n");
        printf("Your choice: ");
        scanf_s("%d", &choice);

        if (choice == 4) {
            printf("Program terminated.\n");
            break;
        }

        switch (choice) {
        case 1: // Shift left
            printf("Enter the number of positions to shift left (0-7): ");
            scanf_s("%d", &shift);
            if (shift < 0 || shift > 7) {
                printf("Error: The number of positions must be in the range 0-7.\n");
                break;
            }
            port = port << shift;
            printf("Result after left shift:\n");
            printf("Binary form: ");
            printBinary(port);
            printf("Hexadecimal form: 0x%02X\n", port);
            break;

        case 2: // Shift right
            printf("Enter the number of positions to shift right (0-7): ");
            scanf_s("%d", &shift);
            if (shift < 0 || shift > 7) {
                printf("Error: The number of positions must be in the range 0-7.\n");
                break;
            }
            port = port >> shift;
            printf("Result after right shift:\n");
            printf("Binary form: ");
            printBinary(port);
            printf("Hexadecimal form: 0x%02X\n", port);
            break;

        case 3: // Set new port value
            printf("Enter the new port value (0-255): ");
            int new_value;
            scanf_s("%d", &new_value);
            if (new_value < 0 || new_value > 255) {
                printf("Error: The value must be in the range 0-255.\n");
                break;
            }
            port = (unsigned char)new_value;
            printf("New port state:\n");
            printf("Binary form: ");
            printBinary(port);
            printf("Hexadecimal form: 0x%02X\n", port);
            break;

        default:
            printf("Error: Invalid operation choice.\n");
            break;
        }
    }
}

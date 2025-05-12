#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <unistd.h>
#include <time.h>

#define ROWS 9
#define COLS 9
#define PASSWORD "2025"
#define MAX_TRIES 3

// Function to display a personalized screen
void displayPersonalScreen() {
printf("************************************\n");
printf("* *\n");
printf("* *\n");
printf("* *\n");
printf("* programming homework 3\n");
printf("* *\n");
printf("* *\n");
printf("* *\n");
printf("* Welcome to My Booking System\n");
printf("* *\n");
printf("* *\n");
printf("* Developed with C Language\n");
printf("* *\n");
printf("* *\n");
printf("* *\n");
printf("* Enjoy the experience!\n");
printf("* *\n");
printf("* *\n");
printf("* *\n");
printf("************************************\n");
    printf("\nPlease enter the 4-digit password (default: %s): ", PASSWORD);
}

// Function to clear the screen
void clearScreen() {
    system("cls");
}

// Function to display the main menu
void displayMainMenu() {
    printf("----------[Booking System]----------\n");
    printf("| a. Available seats             |\n");
    printf("| b. Arrange for you             |\n");
    printf("| c. Choose by yourself          |\n");
    printf("| d. Exit                        |\n");
    printf("------------------------------------\n");
    printf("Enter your choice: ");
}

// Function to display the seating chart
void displaySeats(char seats[ROWS][COLS]) {
    printf("  ");
    for (int j = 1; j <= COLS; j++) {
        printf("%d", j);
    }
    printf("\n");
    for (int i = ROWS - 1; i >= 0; i--) {
        printf("%d ", i + 1);
        for (int j = 0; j < COLS; j++) {
            printf("%c", seats[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Initialize seats array with all seats as empty
    char seats[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            seats[i][j] = '-'; // Initialize all seats as empty with ASCII hyphen character
        }
    }

    // Password authentication
    int tries = 0;
    while (tries < MAX_TRIES) {
        displayPersonalScreen();
        char enteredPassword[5];
        if (scanf("%4s", enteredPassword) == 1) {
            // Consume the newline character
            while (getchar() != '\n');
            if (strcmp(enteredPassword, PASSWORD) == 0) {
                clearScreen();
                printf("Welcome!\n");
                break; // Password correct, proceed to the main menu
            } else {
                tries++;
                printf("Incorrect password. %d tries remaining.\n", MAX_TRIES - tries);
                // Wait for a short time before the next attempt
                usleep(500000); // delay
            }
        } else {
            printf("Invalid input.\n");
            while (getchar() != '\n'); // Clear buffer
            tries++;
        }
        clearScreen();
    }

    if (tries == MAX_TRIES) {
        printf("Too many incorrect attempts. Program terminated.\n");
        return 1; // Indicate an error
    }

    // Main menu loop
    char choice;
    do {
        displayMainMenu();
        choice = getchar();
        while (getchar() != '\n'); // Clear buffer
        if (tolower(choice) == 'd') {
            printf("Exiting program.\n");
            break;
        } else {
            printf("Invalid choice. Press any button to continue.\n");
            fflush(stdin);
            getchar(); // Wait for key press
        }
        clearScreen();
    } while (1);

    return 0;
}
/*建立了程式的基本骨架。顯示歡迎畫面、清除螢幕、顯示主選單和顯示座位的函式。
  main 函式中包含了座位表的初始化，密碼驗證流程。
  此階段的主選單僅有d選項能用。 */
  

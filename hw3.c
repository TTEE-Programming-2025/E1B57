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

// Function to clear the screen (platform-dependent)
void clearScreen() {
    system("cls");
}

// Function to display the main menu
void displayMainMenu() {
    printf("----------[Booking System]----------\n");
    printf("| a. Available seats                 |\n");
    printf("| b. Arrange for you                 |\n");
    printf("| c. Choose by yourself            |\n");
    printf("| d. Exit                            |\n");
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

// Function to randomly initialize some booked seats
void initializeBookedSeats(char seats[ROWS][COLS]) {
    srand(time(NULL));
    int bookedCount = 0;
    while (bookedCount < 10) {
        int row = rand() % ROWS;
        int col = rand() % COLS;
        if (seats[row][col] == '-') {
            seats[row][col] = '*';
            bookedCount++;
        }
    }
}

// Function to handle displaying available seats
void viewAvailableSeats(char seats[ROWS][COLS]) {
    clearScreen();
    printf("----------[Available Seats]----------\n");
    displaySeats(seats);
    printf("\nPress any key to return to the main menu...\n");
    fflush(stdin);
    getchar(); // Wait for the user to press a key
}

int main() {
    // Initialize seats array with all seats as empty
    char seats[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            seats[i][j] = '-'; // Initialize all seats as empty with '-' 
        }
    }
    initializeBookedSeats(seats);

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
                usleep(500000); // Delay for 0.5 seconds
            }
        } else {
            printf("Invalid input. Please enter a 4-digit password.\n");
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
        switch (tolower(choice)) {
            case 'a':
                viewAvailableSeats(seats);
                break;
            case 'd':
                printf("Exiting program.\n");
                exit(0); // Correctly exit the program
            default:
                printf("Invalid choice. Press any key to continue.\n");
                fflush(stdin);
                getchar(); // Wait for key press
        }
        clearScreen();
    } while (1);

    return 0;
}
/*讓程式能夠隨機產生10個已預訂的座位。
  並完成主選單的a選項，提供查看目前座位狀況的功能。 */ 

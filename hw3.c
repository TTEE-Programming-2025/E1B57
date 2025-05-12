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
    getchar(); // Wait for the user to press a key
}

// Function to find consecutive empty seats
int findConsecutiveEmpty(char seats[ROWS][COLS], int numSeats, int *startRow, int *startCol, int direction) {
    // direction: 0 for horizontal, 1 for vertical
    if (direction == 0) { // Horizontal
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j <= COLS - numSeats; j++) {
                int emptyCount = 0;
                for (int k = 0; k < numSeats; k++) {
                    // Debug the character we're checking
                    // printf("Checking seat [%d][%d]: '%c'\n", i, j+k, seats[i][j+k]);
                    if (seats[i][j + k] == '-') {
                        emptyCount++;
                    }
                }
                if (emptyCount == numSeats) {
                    *startRow = i;
                    *startCol = j;
                    return 1;
                }
            }
        }
    } else { // Vertical
        for (int j = 0; j < COLS; j++) {
            for (int i = 0; i <= ROWS - numSeats; i++) {
                int emptyCount = 0;
                for (int k = 0; k < numSeats; k++) {
                    if (seats[i + k][j] == '-') {
                        emptyCount++;
                    }
                }
                if (emptyCount == numSeats) {
                    *startRow = i;
                    *startCol = j;
                    return 1;
                }
            }
        }
    }
    return 0;
}

// Function to handle automatic seat arrangement
void arrangeSeats(char seats[ROWS][COLS]) {
    int numSeats;
    printf("Enter the number of seats needed (1-4): ");
    if (scanf("%d", &numSeats) != 1) {
        printf("Invalid input. Please enter a number between 1 and 4.\n");
        // Consume the invalid input
        while (getchar() != '\n');
        return;
    }
    
    // Consume the newline character after reading the number
    while (getchar() != '\n');
    
    if (numSeats < 1 || numSeats > 4) {
        printf("Invalid number of seats. Please enter a number between 1 and 4.\n");
        return;
    }

    char suggestedSeats[ROWS][COLS];
    // Copy the seats array correctly
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            suggestedSeats[i][j] = seats[i][j];
        }
    }
    
    int found = 0;
    int startRow, startCol;

    if (numSeats >= 1 && numSeats <= 3) {
        // Try horizontal arrangement
        if (findConsecutiveEmpty(suggestedSeats, numSeats, &startRow, &startCol, 0)) {
            for (int i = 0; i < numSeats; i++) {
                suggestedSeats[startRow][startCol + i] = '@';
            }
            found = 1;
        } else if (findConsecutiveEmpty(suggestedSeats, numSeats, &startRow, &startCol, 1)) { // Try vertical
            for (int i = 0; i < numSeats; i++) {
                suggestedSeats[startRow + i][startCol] = '@';
            }
            found = 1;
        }
    } else if (numSeats == 4) {
        // Try horizontal in the same row
        if (findConsecutiveEmpty(suggestedSeats, numSeats, &startRow, &startCol, 0)) {
            for (int i = 0; i < numSeats; i++) {
                suggestedSeats[startRow][startCol + i] = '@';
            }
            found = 1;
        } else {
            // Try two seats in two adjacent rows
            for (int i = 0; i < ROWS - 1; i++) {
                for (int j = 0; j <= COLS - 2; j++) {
                    if (suggestedSeats[i][j] == '-' && suggestedSeats[i][j + 1] == '-' &&
                        suggestedSeats[i + 1][j] == '-' && suggestedSeats[i + 1][j + 1] == '-') {
                        suggestedSeats[i][j] = '@';
                        suggestedSeats[i][j + 1] = '@';
                        suggestedSeats[i + 1][j] = '@';
                        suggestedSeats[i + 1][j + 1] = '@';
                        found = 1;
                        goto arranged; // Break out of all loops
                    }
                }
            }
        }
    }

arranged:
    clearScreen();
    printf("----------[Suggested Seats]----------\n");
    if (found) {
        displaySeats(suggestedSeats);
        char choice;
        printf("\nDo you accept this arrangement? (y/n): ");
        choice = getchar();
        // Consume the newline
        while (getchar() != '\n');
        
        if (tolower(choice) == 'y') {
            for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLS; j++) {
                    if (suggestedSeats[i][j] == '@') {
                        seats[i][j] = '*'; // Mark as booked
                    }
                }
            }
            printf("Seats booked successfully. Press any key to return to the main menu...\n");
        } else {
            printf("Arrangement rejected. Press any key to return to the main menu...\n");
        }
        getchar(); // Wait for key press
    } else {
        printf("Could not find suitable seats for %d people. Press any key to return to the main menu...\n", numSeats);
        getchar(); // Wait for key press
    }
}

// Function to handle manual seat selection
void chooseSeats(char seats[ROWS][COLS]) {
    int numSeats = 0;
    char input[10];
    char tempSeats[ROWS][COLS];
    
    // Create a correct copy of the original seats matrix
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            tempSeats[i][j] = seats[i][j];
        }
    }
    
    int selected[4][2]; // Store selected row and col

    // Debug: Print the current state of seats before selection
    printf("Current seats status:\n");
    displaySeats(seats);
    printf("\n");

    printf("Enter the seats you want to choose (e.g., 1-2, 2-9). Enter 'done' when finished (max 4 seats):\n");

    while (numSeats < 4) {
        printf("Enter seat %d (or 'done'): ", numSeats + 1);
        if (scanf("%s", input) != 1) {
            printf("Invalid input.\n");
            while (getchar() != '\n'); // Clear buffer
            continue;
        }

        // Consume the newline character after input
        while (getchar() != '\n');

        if (strcmp(input, "done") == 0) {
            break;
        }

        int row, col;
        if (sscanf(input, "%d-%d", &row, &col) == 2) {
            if (row >= 1 && row <= ROWS && col >= 1 && col <= COLS) {
                // Debug: Print what we're checking
                printf("Checking seat [%d-%d]: Current status is '%c'\n", 
                       row, col, seats[row-1][col-1]);
                
                if (seats[row-1][col-1] == '-') {
                    tempSeats[row-1][col-1] = '@';
                    selected[numSeats][0] = row - 1;
                    selected[numSeats][1] = col - 1;
                    numSeats++;
                    printf("Seat [%d-%d] selected successfully.\n", row, col);
                } else {
                    printf("Seat [%d-%d] is already booked or selected. Please choose another.\n", row, col);
                }
            } else {
                printf("Invalid seat number. Row must be 1-%d, Column must be 1-%d.\n", ROWS, COLS);
            }
        } else {
            printf("Invalid format. Please use the format row-column (e.g., 1-2).\n");
        }
    }

    clearScreen();
    printf("----------[Your Selection]----------\n");
    displaySeats(tempSeats);
    printf("\nPress any key to confirm your selection...\n");
    getchar(); // Wait for key press

    // Mark selected seats as booked in the original seats array
    for (int i = 0; i < numSeats; i++) {
        seats[selected[i][0]][selected[i][1]] = '*'; // Mark selected seats as booked
    }

    printf("Seats confirmed. Press any key to return to the main menu...\n");
    getchar(); // Wait for key press
}

// Function to handle the exit option
void exitProgram(char seats[ROWS][COLS]) {
    char choice;
    printf("Continue? (y/n): ");
    
    choice = getchar();
    
    // Clear the input buffer
    while (getchar() != '\n');
    
    if (tolower(choice) == 'y') {
        clearScreen();
        // Program will loop back to the main menu
    } else if (tolower(choice) == 'n') {
        printf("Exiting program. Thank you!\n");
        exit(0);
    } else {
        printf("Invalid input. Please enter 'y' or 'n'.\n");
        getchar(); // Wait for key press
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
                // Wait for a short time before the next attempt
                usleep(500000); // Delay for 0.5 seconds
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
        // Read a single character
        choice = getchar();
        
        // Clear the input buffer
        while (getchar() != '\n');
        
        switch (tolower(choice)) {
            case 'a':
                viewAvailableSeats(seats);
                break;
            case 'b':
                arrangeSeats(seats);
                break;
            case 'c':
                chooseSeats(seats);
                break;
            case 'd':
                exitProgram(seats);
                break;
            default:
                printf("Invalid choice. Please enter 'a', 'b', 'c', or 'd'.\n");
                getchar(); // Wait for key press
        }
        clearScreen();
    } while (1); // Continue until explicit exit from exitProgram()

    return 0; // Indicate successful execution
}
/*優化選項c的顯示介面，並將格式修正成題目要的 */

/*心得:
  認識了更多方便的函式庫。用二維陣列來管理座位資訊也讓我更熟悉陣列。 
  學會使用 srand 和 rand 來隨機初始化已預訂的座位。還學會寫尋找連續空位的演算法，對之後寫程式應該很有幫助。*/ 
   

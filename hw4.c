#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 

#define PASSWORD "2025"     
#define MAX_TRIES 3         
#define MAX_STUDENTS 10    
#define MIN_STUDENTS 5     

// 學生結構
typedef struct {
    char name[50];         
    int studentId;       
    int math;             
    int physics;         
    int english;       
    float average;    
} Student;

// 全域變數
Student students[MAX_STUDENTS];  
int studentCount = 0;           

// 清除螢幕的函式
void clearScreen() {
    system("cls");
}

// 檢查字串是否為空或只包含空白字元
int isEmptyOrWhitespace(char *str) {
    if (str == NULL || strlen(str) == 0) {
        return 1; // 空字串
    }
    
    // 檢查是否只包含空白字元
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isspace(str[i])) {
            return 0; // 找到非空白字元
        }
    }
    return 1; // 只包含空白字元
}

// 顯示個人風格的歡迎畫面（至少20行）
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
}

// 顯示主選單
void displayMainMenu() {
    printf("------------[Grade System]----------\n");
    printf("| a. Enter student grades        |\n");
    printf("| b. Display student grades      |\n");
    printf("| c. Search for student grades   |\n");
    printf("| d. Grade ranking               |\n");
    printf("| e. Exit system                 |\n");
    printf("------------------------------------\n");
    printf("請輸入您的選擇: ");
}

// 密碼驗證函式
int authenticateUser() {
    char enteredPassword[10];
    int tries = 0;
    
    while (tries < MAX_TRIES) {
        printf("\n請輸入4位數密碼 (預設: %s): ", PASSWORD);
        
        if (scanf("%s", enteredPassword) == 1) {
            // 清除輸入緩衝區
            while (getchar() != '\n');
            
            if (strcmp(enteredPassword, PASSWORD) == 0) {
                printf("密碼正確！歡迎使用系統！\n");
                return 1;  // 密碼正確
            } else {
                tries++;
                if (tries < MAX_TRIES) {
                    printf("密碼錯誤！還剩 %d 次機會。\n", MAX_TRIES - tries);
                }
            }
        } else {
            printf("輸入格式錯誤！\n");
            while (getchar() != '\n'); // 清除輸入緩衝區
            tries++;
        }
    }
    
    printf("密碼錯誤次數過多，程式即將結束！\n");
    return 0;  // 密碼錯誤
}

// 計算學生平均成績
void calculateAverage(Student *student) {
    student->average = (student->math + student->physics + student->english) / 3.0;
}

// 功能a: 輸入學生成績
void enterStudentGrades() {
    clearScreen();
    int n;
    
    // 輸入學生數量
    do {
        printf("請輸入學生數量 (%d~%d): ", MIN_STUDENTS, MAX_STUDENTS);
        if (scanf("%d", &n) != 1) {
            printf("輸入格式錯誤！請輸入整數。\n");
            while (getchar() != '\n'); // 清除輸入緩衝區
            continue;
        }
        if (n < MIN_STUDENTS || n > MAX_STUDENTS) {
            printf("學生數量必須在 %d 到 %d 之間！\n", MIN_STUDENTS, MAX_STUDENTS);
        }
    } while (n < MIN_STUDENTS || n > MAX_STUDENTS);
    
    studentCount = n;
    while (getchar() != '\n'); // 清除輸入緩衝區
    
    // 輸入每個學生的資料
    for (int i = 0; i < n; i++) {
        printf("\n--- 輸入第 %d 位學生資料 ---\n", i + 1);
        
        // 輸入姓名（加入空白檢查）
        do {
            printf("姓名: ");
            fgets(students[i].name, sizeof(students[i].name), stdin);
            students[i].name[strcspn(students[i].name, "\n")] = 0; // 移除換行符
            
            if (isEmptyOrWhitespace(students[i].name)) {
                printf("姓名不能為空白！請重新輸入。\n");
            }
        } while (isEmptyOrWhitespace(students[i].name));
        
        // 輸入學號（6位數）
        do {
            printf("學號 (6位數): ");
            if (scanf("%d", &students[i].studentId) != 1) {
                printf("輸入格式錯誤！請輸入6位數字。\n");
                while (getchar() != '\n');
                continue;
            }
            if (students[i].studentId < 100000 || students[i].studentId > 999999) {
                printf("學號必須是6位數！\n");
            }
        } while (students[i].studentId < 100000 || students[i].studentId > 999999);
        
        // 輸入數學成績
        do {
            printf("數學成績 (0~100): ");
            if (scanf("%d", &students[i].math) != 1) {
                printf("輸入格式錯誤！請輸入0~100的整數。\n");
                while (getchar() != '\n');
                continue;
            }
            if (students[i].math < 0 || students[i].math > 100) {
                printf("成績必須在0~100之間！\n");
            }
        } while (students[i].math < 0 || students[i].math > 100);
        while (getchar() != '\n'); // 清除輸入緩衝區
        
        // 輸入物理成績
        do {
            printf("物理成績 (0~100): ");
            if (scanf("%d", &students[i].physics) != 1) {
                printf("輸入格式錯誤！請輸入0~100的整數。\n");
                while (getchar() != '\n');
                continue;
            }
            if (students[i].physics < 0 || students[i].physics > 100) {
                printf("成績必須在0~100之間！\n");
            }
        } while (students[i].physics < 0 || students[i].physics > 100);
        while (getchar() != '\n'); // 清除輸入緩衝區
        
        // 輸入英文成績
        do {
            printf("英文成績 (0~100): ");
            if (scanf("%d", &students[i].english) != 1) {
                printf("輸入格式錯誤！請輸入0~100的整數。\n");
                while (getchar() != '\n');
                continue;
            }
            if (students[i].english < 0 || students[i].english > 100) {
                printf("成績必須在0~100之間！\n");
            }
        } while (students[i].english < 0 || students[i].english > 100);
        while (getchar() != '\n'); // 清除輸入緩衝區
        
        // 計算平均成績
        calculateAverage(&students[i]);
        
        printf("第 %d 位學生資料輸入完成！\n", i + 1);
    }
    
    printf("\n所有學生資料輸入完成！按任意鍵返回主選單...");
    while (getchar() != '\n'); // 清除輸入緩衝區
    getchar(); // 等待使用者按鍵
}



// 主程式
int main() {
    // 顯示個人風格畫面
    displayPersonalScreen();
    
    // 進行密碼驗證
    if (!authenticateUser()) {
        printf("按任意鍵結束程式...");
        getchar();
        return 1; // 密碼驗證失敗，結束程式
    }
    
    char choice;
    
    // 主選單迴圈
    while (1) {
        clearScreen();
        displayMainMenu();
        
        scanf(" %c", &choice);
        while (getchar() != '\n'); // 清除輸入緩衝區
        
        switch (choice) {
            case 'a':
            case 'A':
                enterStudentGrades();
                break;
                

        }
    }
    
    return 0;
}

/*修正程式接受空白姓名輸入的問題*/

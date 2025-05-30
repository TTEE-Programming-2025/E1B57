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

// 功能b: 顯示所有學生成績
void displayStudentGrades() {
    clearScreen();
    
    if (studentCount == 0) {
        printf("目前沒有學生資料！請先輸入學生成績。\n");
        printf("按任意鍵返回主選單...");
        getchar();
        return;
    }
    
    printf("========== 所有學生成績 ==========\n");
    printf("%-15s %-8s %-6s %-6s %-6s %-8s\n", 
           "姓名", "學號", "數學", "物理", "英文", "平均");
    printf("------------------------------------------------\n");
    
    for (int i = 0; i < studentCount; i++) {
        printf("%-15s %-8d %-6d %-6d %-6d %-8.1f\n", 
               students[i].name, students[i].studentId,
               students[i].math, students[i].physics, 
               students[i].english, students[i].average);
    }
    
    printf("================================================\n");
    printf("按任意鍵返回主選單...");
    getchar();
}

// 功能c: 搜尋學生成績
void searchStudentGrades() {
    clearScreen();
    
    if (studentCount == 0) {
        printf("目前沒有學生資料！請先輸入學生成績。\n");
        printf("按任意鍵返回主選單...");
        getchar();
        return;
    }
    
    char searchName[50];
    
    // 加入空白檢查的搜尋姓名輸入
    do {
        printf("請輸入要搜尋的學生姓名: ");
        fgets(searchName, sizeof(searchName), stdin);
        searchName[strcspn(searchName, "\n")] = 0; // 移除換行符
        
        if (isEmptyOrWhitespace(searchName)) {
            printf("搜尋姓名不能為空白！請重新輸入。\n");
        }
    } while (isEmptyOrWhitespace(searchName));
    
    int found = 0;
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].name, searchName) == 0) {
            printf("\n========== 搜尋結果 ==========\n");
            printf("姓名: %s\n", students[i].name);
            printf("學號: %d\n", students[i].studentId);
            printf("數學成績: %d\n", students[i].math);
            printf("物理成績: %d\n", students[i].physics);
            printf("英文成績: %d\n", students[i].english);
            printf("平均成績: %.1f\n", students[i].average);
            printf("============================\n");
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("\n找不到姓名為 '%s' 的學生資料！\n", searchName);
    }
    
    printf("按任意鍵返回主選單...");
    getchar();
}

// 功能d: 成績排名（使用氣泡排序法）
void gradeRanking() {
    clearScreen();
    
    if (studentCount == 0) {
        printf("目前沒有學生資料！請先輸入學生成績。\n");
        printf("按任意鍵返回主選單...");
        getchar();
        return;
    }
    
    // 建立一個暫時陣列來排序，避免影響原始資料
    Student tempStudents[MAX_STUDENTS];
    for (int i = 0; i < studentCount; i++) {
        tempStudents[i] = students[i];
    }
    
    // 氣泡排序法（依平均成績由高到低排序）
    for (int i = 0; i < studentCount - 1; i++) {
        for (int j = 0; j < studentCount - 1 - i; j++) {
            if (tempStudents[j].average < tempStudents[j + 1].average) {
                Student temp = tempStudents[j];
                tempStudents[j] = tempStudents[j + 1];
                tempStudents[j + 1] = temp;
            }
        }
    }
    
    printf("========== 成績排名 ==========\n");
    printf("%-4s %-15s %-8s %-8s\n", "排名", "姓名", "學號", "平均成績");
    printf("----------------------------------------\n");
    
    for (int i = 0; i < studentCount; i++) {
        printf("%-4d %-15s %-8d %-8.1f\n", 
               i + 1, tempStudents[i].name, 
               tempStudents[i].studentId, tempStudents[i].average);
    }
    
    printf("==================================\n");
    printf("按任意鍵返回主選單...");
    getchar();
}

// 功能e: 確認離開系統
int confirmExit() {
    char choice;
    while (1) {
        printf("確定離開？ (y/n): ");
        scanf(" %c", &choice);
        while (getchar() != '\n'); // 清除輸入緩衝區
        
        if (choice == 'y' || choice == 'Y') {
            return 1; // 確定離開
        } else if (choice == 'n' || choice == 'N') {
            return 0; // 不離開，返回主選單
        } else {
            printf("請輸入 'y' 或 'n'！\n");
        }
    }
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
                
            case 'b':
            case 'B':
                displayStudentGrades();
                break;
                
            case 'c':
            case 'C':
                searchStudentGrades();
                break;
                
            case 'd':
            case 'D':
                gradeRanking();
                break;
                
            case 'e':
            case 'E':
                if (confirmExit()) {
                    printf("感謝使用簡易成績系統！再見！\n");
                    return 0; // 正常結束程式
                }
                break;
                
            default:
                printf("無效的選擇！請輸入 a-e 之間的選項。\n");
                printf("按任意鍵繼續...");
                getchar();
                break;                
        }
    }
    
    return 0;
}

/*完成d和e選項*/

/*程式心得：更熟悉使用結構來儲存學生資料，也學到使用全域變數來儲存學生陣列和學生數量， 
            並且對原本只在範例上看到的氣泡排序法有更實際的理解，讓我的基本功變得更加扎實*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 

#define PASSWORD "2025"     
#define MAX_TRIES 3         
#define MAX_STUDENTS 10    
#define MIN_STUDENTS 5     

// �ǥ͵��c
typedef struct {
    char name[50];         
    int studentId;       
    int math;             
    int physics;         
    int english;       
    float average;    
} Student;

// �����ܼ�
Student students[MAX_STUDENTS];  
int studentCount = 0;           

// �M���ù����禡
void clearScreen() {
    system("cls");
}

// �ˬd�r��O�_���ũΥu�]�t�ťզr��
int isEmptyOrWhitespace(char *str) {
    if (str == NULL || strlen(str) == 0) {
        return 1; // �Ŧr��
    }
    
    // �ˬd�O�_�u�]�t�ťզr��
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isspace(str[i])) {
            return 0; // ���D�ťզr��
        }
    }
    return 1; // �u�]�t�ťզr��
}

// ��ܭӤH���檺�w��e���]�ܤ�20��^
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

// ��ܥD���
void displayMainMenu() {
    printf("------------[Grade System]----------\n");
    printf("| a. Enter student grades        |\n");
    printf("| b. Display student grades      |\n");
    printf("| c. Search for student grades   |\n");
    printf("| d. Grade ranking               |\n");
    printf("| e. Exit system                 |\n");
    printf("------------------------------------\n");
    printf("�п�J�z�����: ");
}

// �K�X���Ҩ禡
int authenticateUser() {
    char enteredPassword[10];
    int tries = 0;
    
    while (tries < MAX_TRIES) {
        printf("\n�п�J4��ƱK�X (�w�]: %s): ", PASSWORD);
        
        if (scanf("%s", enteredPassword) == 1) {
            // �M����J�w�İ�
            while (getchar() != '\n');
            
            if (strcmp(enteredPassword, PASSWORD) == 0) {
                printf("�K�X���T�I�w��ϥΨt�ΡI\n");
                return 1;  // �K�X���T
            } else {
                tries++;
                if (tries < MAX_TRIES) {
                    printf("�K�X���~�I�ٳ� %d �����|�C\n", MAX_TRIES - tries);
                }
            }
        } else {
            printf("��J�榡���~�I\n");
            while (getchar() != '\n'); // �M����J�w�İ�
            tries++;
        }
    }
    
    printf("�K�X���~���ƹL�h�A�{���Y�N�����I\n");
    return 0;  // �K�X���~
}

// �p��ǥͥ������Z
void calculateAverage(Student *student) {
    student->average = (student->math + student->physics + student->english) / 3.0;
}

// �\��a: ��J�ǥͦ��Z
void enterStudentGrades() {
    clearScreen();
    int n;
    
    // ��J�ǥͼƶq
    do {
        printf("�п�J�ǥͼƶq (%d~%d): ", MIN_STUDENTS, MAX_STUDENTS);
        if (scanf("%d", &n) != 1) {
            printf("��J�榡���~�I�п�J��ơC\n");
            while (getchar() != '\n'); // �M����J�w�İ�
            continue;
        }
        if (n < MIN_STUDENTS || n > MAX_STUDENTS) {
            printf("�ǥͼƶq�����b %d �� %d �����I\n", MIN_STUDENTS, MAX_STUDENTS);
        }
    } while (n < MIN_STUDENTS || n > MAX_STUDENTS);
    
    studentCount = n;
    while (getchar() != '\n'); // �M����J�w�İ�
    
    // ��J�C�Ӿǥͪ����
    for (int i = 0; i < n; i++) {
        printf("\n--- ��J�� %d ��ǥ͸�� ---\n", i + 1);
        
        // ��J�m�W�]�[�J�ť��ˬd�^
        do {
            printf("�m�W: ");
            fgets(students[i].name, sizeof(students[i].name), stdin);
            students[i].name[strcspn(students[i].name, "\n")] = 0; // ���������
            
            if (isEmptyOrWhitespace(students[i].name)) {
                printf("�m�W���ର�ťաI�Э��s��J�C\n");
            }
        } while (isEmptyOrWhitespace(students[i].name));
        
        // ��J�Ǹ��]6��ơ^
        do {
            printf("�Ǹ� (6���): ");
            if (scanf("%d", &students[i].studentId) != 1) {
                printf("��J�榡���~�I�п�J6��Ʀr�C\n");
                while (getchar() != '\n');
                continue;
            }
            if (students[i].studentId < 100000 || students[i].studentId > 999999) {
                printf("�Ǹ������O6��ơI\n");
            }
        } while (students[i].studentId < 100000 || students[i].studentId > 999999);
        
        // ��J�ƾǦ��Z
        do {
            printf("�ƾǦ��Z (0~100): ");
            if (scanf("%d", &students[i].math) != 1) {
                printf("��J�榡���~�I�п�J0~100����ơC\n");
                while (getchar() != '\n');
                continue;
            }
            if (students[i].math < 0 || students[i].math > 100) {
                printf("���Z�����b0~100�����I\n");
            }
        } while (students[i].math < 0 || students[i].math > 100);
        while (getchar() != '\n'); // �M����J�w�İ�
        
        // ��J���z���Z
        do {
            printf("���z���Z (0~100): ");
            if (scanf("%d", &students[i].physics) != 1) {
                printf("��J�榡���~�I�п�J0~100����ơC\n");
                while (getchar() != '\n');
                continue;
            }
            if (students[i].physics < 0 || students[i].physics > 100) {
                printf("���Z�����b0~100�����I\n");
            }
        } while (students[i].physics < 0 || students[i].physics > 100);
        while (getchar() != '\n'); // �M����J�w�İ�
        
        // ��J�^�妨�Z
        do {
            printf("�^�妨�Z (0~100): ");
            if (scanf("%d", &students[i].english) != 1) {
                printf("��J�榡���~�I�п�J0~100����ơC\n");
                while (getchar() != '\n');
                continue;
            }
            if (students[i].english < 0 || students[i].english > 100) {
                printf("���Z�����b0~100�����I\n");
            }
        } while (students[i].english < 0 || students[i].english > 100);
        while (getchar() != '\n'); // �M����J�w�İ�
        
        // �p�⥭�����Z
        calculateAverage(&students[i]);
        
        printf("�� %d ��ǥ͸�ƿ�J�����I\n", i + 1);
    }
    
    printf("\n�Ҧ��ǥ͸�ƿ�J�����I�����N���^�D���...");
    while (getchar() != '\n'); // �M����J�w�İ�
    getchar(); // ���ݨϥΪ̫���
}



// �D�{��
int main() {
    // ��ܭӤH����e��
    displayPersonalScreen();
    
    // �i��K�X����
    if (!authenticateUser()) {
        printf("�����N�䵲���{��...");
        getchar();
        return 1; // �K�X���ҥ��ѡA�����{��
    }
    
    char choice;
    
    // �D���j��
    while (1) {
        clearScreen();
        displayMainMenu();
        
        scanf(" %c", &choice);
        while (getchar() != '\n'); // �M����J�w�İ�
        
        switch (choice) {
            case 'a':
            case 'A':
                enterStudentGrades();
                break;
                

        }
    }
    
    return 0;
}

/*�ץ��{�������ťթm�W��J�����D*/

#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    /*步驟1 顯示個人風格的畫面*/ 
	int i;
	for(i=0;i<4;i++)
	 {
		 printf("********************\n");
		 printf("*\n");
		 printf("程式設計作業一\n"); 
		 printf("*\n");
		 printf("********************\n");
	 } 
	printf("\n");
	printf("按Enter鍵繼續...\n");
	getchar();
	fflush(stdin);
	system("cls");
	
	/*步驟2 驗證密碼*/ 
	int pass=2024,inpass;
	
	printf("請輸入4位數字密碼:\n");
	scanf("%d",&inpass);
	
	if(inpass==pass)
	{
		printf("歡迎!\n");
		/*步驟3 顯示主選單*/
		system("cls");
		printf("--------------------------\n");
		printf("| 'A'...'Z' : Uppercase  |\n");
		printf("| 'a'...'z' : Lowercase  |\n");
		printf("| '0'...'9' : Digit      |\n");
		printf("| Otherwise : E1B57陳逸安|\n");
		printf("--------------------------\n");
		/*步驟4 處理字元輸入*/
		char inch;
		printf("請輸入一個字元\n");
		scanf(" %c",&inch);   /*雙引號前面加上一個空格避免讀到\n*/
		if(inch>='A' && inch<='Z')
		 printf("Uppercase\n");
		else if(inch>='a' && inch<='z')
	  	 printf("Lowercase\n");
		else if(inch>='0' && inch<='9')   /*輸入是字元所以0和9要加上單引號*/
	  	 printf("Digit\n");
	  	else
	  	 printf("E1B57陳逸安\n");

	}
	else
	{
		printf("密碼錯誤\a\n");
	}
	system("pause");
	return 0;
}
//心得
//這次作業讓我更熟悉輸入指令還有一些形態上的運用
//但最重要的還是學習到了github使用的基本知識 





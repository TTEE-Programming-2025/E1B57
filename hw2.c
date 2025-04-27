#include<stdio.h>
#include<stdlib.h>
#define password 2025
#define maxpasswordtry 3
int main(void)
{
	//輸出至少20行個人風格的畫面 
	printf("************************************\n");
	printf("* *\n");
	printf("* *\n");
	printf("* *\n");
	printf("* 歡迎來到我的程式作業二\n");
	printf("* *\n");
	printf("* *\n");	
	printf("* *\n");
	printf("* 歡迎來到我的程式作業二\n");
	printf("* *\n");
	printf("* *\n");
	printf("* 歡迎來到我的程式作業二\n");
	printf("* *\n");
	printf("* *\n");
	printf("* *\n");
	printf("* 歡迎來到我的程式作業二\n");
	printf("* *\n");
	printf("* *\n");
	printf("* *\n");
	printf("************************************\n");
	//輸入密碼
	int inputpass,i;
	printf("請輸入4個數字的密碼 (預設: %d):\n",password);
	scanf(" %d",&inputpass);
	for(i=1;i<maxpasswordtry;i++)
	{
		if(inputpass==password)
		 {
			printf("密碼正確!\n");
			
			
			
			break;
		 }	
		 
	    printf("還有%d次機會\n",(3-i));
		printf("請再輸入密碼 (預設: %d):\n",password);
	    scanf(" %d",&inputpass);
	    
	    if(inputpass==password)
	     {
	    	i=1;
	    	continue;
		 }
	}
	
    if(inputpass!=password)
    { 
	printf("密碼錯誤太多次\a\n");
	printf("程式將結束\n");
	} 
	
	
	system("pause");
	return 0;
}

//修正前兩次密碼錯誤，第三次正確時，不會顯示"密碼正確"的問題 

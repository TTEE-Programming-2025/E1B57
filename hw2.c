#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#define password 2025
#define maxpasswordtry 3
void menu(void);
void funcA(void);
int main(void)
{ 
	//步驟一  輸出至少20行個人風格的畫面 
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
			//步驟二 螢幕出現主選單 
			usleep(500000);
			system("cls");
			
			while(1)
			{ 
			    menu();
			    char choice;
	            printf("請輸入您的選擇 (A,a/B,b/C,c): \n");
            	scanf(" %c",&choice);
		        //步驟三 直角三角形
		     	switch(choice)
		    	{
			    	case 'A':
			    	case 'a':
			    	 funcA(); 
			    	 break; 

		    	}
			} 
			
			
			
			
			
			
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

void menu(void)
{
	printf("*****************主選單*****************\n");
	printf("| a. 畫出直角三角形\n");
	printf("| b. 顯示乘法表\n");
	printf("| c. 結束\n");
	printf("*****************主選單*****************\n");
	printf("\n");
}

void funcA(void)
{
	int i,j,k;
	char input;
	system("cls");
	printf("請輸入一個 'a' 到 'n' 的字元\n");
	scanf(" %c",&input);
	int height=(input-'a'+1);
	while(1)
	{
		if((input>='a')&&(input<='n'))
	    {
		    for(i=1;i<=height;i++)
		    {
		        for(j=1;j<=(height-i);j++)
		        {
		            printf(" ");
		        }
		  
		        for(j=1;j<=i;j++)
		        {
		            printf("%c",input-i+j);
		        }
		        printf("\n");
	   	    } 
		    printf("按下任意鍵回到主選單\n");
		    fflush(stdin);
	        getchar();
	        system("cls");
	        return;
        }
         
	    else
	    {
	 	    printf("輸入字元不在 'a' 到 'n' 之間\n");
	 	    printf("請重新輸入\n");
	    }
    }
}
//把直角三角形改成abc，結束後回到主選單，並把主選單做成函式 

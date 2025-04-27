#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#define password 2025
#define maxpasswordtry 3
void menu(void);
void funcA(void);
void funcB(void);
int funcC(void);
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
		        //步驟四 九九乘法表
				//步驟五 continue 
		     	switch(choice)
		    	{
			    	case 'A':
			    	case 'a':
			    	    funcA(); 
			    	    break; 
			    	case 'B':
			    	case 'b':
			            funcB();
			            break;
			        case 'C':
			        case 'c':
			        	if(funcC()==1)
			            {
			            	system("pause");
			            	return 0;
						}
			        	break;
			        default:
			        	printf("無效的選項，請重新輸入\n");
		    	}
			} 
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
	
	while(1)
	{
	    scanf(" %c",&input);
	    int height=(input-'a'+1);
	    
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
	 	    printf("不在 'a' 到 'n' 之間\n");
	 	    printf("請重新輸入一個 'a' 到 'n' 的字元\n");
	    }
    }
}

void funcB(void)
{
	int n,i,j;
	printf("請輸入一個 1 到 9 的整數 n\n");
	while(1)
	{ 
	    scanf(" %d",&n);
	    if((n>=1)&&(n<=9))
	    {
		    printf("----------------------\n");
		    for(i=1;i<=n;i++)
		    {
			    for(j=1;j<=n;j++)
			    {
			        printf(" %d * %d = %d",i,j,i*j);
			        printf("\n");
		    	}
		    }
		    printf("----------------------\n");
		    printf("按下任意鍵回到主選單\n");
		    fflush(stdin);
	        getchar();
	        system("cls");
	        return;
	    }
     	else
	    {
		    printf("不在 1 到 9 之間\n");
	 	    printf("請重新輸入一個 1 到 9 的整數 n\n");
	 	    fflush(stdin);
	    }
	} 
}

int funcC(void)
{
	char input;
	printf("Continue? (Y,y/N,n)\n");
	while(1)
	{ 
	    scanf(" %c",&input);
	    if((input=='Y')||(input=='y'))
	    	return 0;
	    if((input=='N')||(input=='n'))
	        return 1;
	    else
	    {
		    printf("不是 Y,y/N,n \n");
	 	    printf("請重新輸入一次\n");
	    }
	} 
} 

//修正funcA函式裡else的輸出錯誤，完成funcB和funcC函式 ，撰寫心得 

/*心得 : 
        這次作業讓我對於函式的運用更加熟悉了。原本想說能不用就不用，
         結果發現程式有點太複雜了，後面把程式拆開來才稍微比較便於閱讀， 
		 原本短短的程式沒什麼感覺，打長一點之後才深刻體認到函式的重要性。*/  

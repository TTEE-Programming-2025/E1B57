#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#define password 2025
#define maxpasswordtry 3
void funcA(void);
int main(void)
{ 
	//�B�J�@  ��X�ܤ�20��ӤH���檺�e�� 
	printf("************************************\n");
	printf("* *\n");
	printf("* *\n");
	printf("* *\n");
	printf("* �w��Ө�ڪ��{���@�~�G\n");
	printf("* *\n");
	printf("* *\n");	
	printf("* *\n");
	printf("* �w��Ө�ڪ��{���@�~�G\n");
	printf("* *\n");
	printf("* *\n");
	printf("* �w��Ө�ڪ��{���@�~�G\n");
	printf("* *\n");
	printf("* *\n");
	printf("* *\n");
	printf("* �w��Ө�ڪ��{���@�~�G\n");
	printf("* *\n");
	printf("* *\n");
	printf("* *\n");
	printf("************************************\n");
	//��J�K�X
	int inputpass,i;
	printf("�п�J4�ӼƦr���K�X (�w�]: %d):\n",password);
	scanf(" %d",&inputpass);
	for(i=1;i<maxpasswordtry;i++)
	{
		if(inputpass==password)
		 {
			printf("�K�X���T!\n");
			//�B�J�G �ù��X�{�D��� 
			usleep(500000);
			system("cls");
			printf("*****************�D���*****************\n");
			printf("| a. �e�X�����T����\n");
			printf("| b. ��ܭ��k��\n");
			printf("| c. ����\n");
			printf("*****************�D���*****************\n");
			printf("\n");
			//�B�J�T �����T����
			char choice;
			printf("�п�J�z����� (a/b/c): \n");
			scanf(" %c",&choice);
			switch(choice)
			{
				case 'A':
				case 'a':
				 funcA(); 
				 break; 

			}
			
			
			
			
			
			
			
			break;
		 }	
		 
	    printf("�٦�%d�����|\n",(3-i));
		printf("�ЦA��J�K�X (�w�]: %d):\n",password);
	    scanf(" %d",&inputpass);
	    
	    if(inputpass==password)
	     {
	    	i=1;
	    	continue;
		 }
	}
	
    if(inputpass!=password)
    { 
	printf("�K�X���~�Ӧh��\a\n");
	printf("�{���N����\n");
	} 
	
	
	system("pause");
	return 0;
}

void funcA(void)
{
	int i,j,k;
	char input;
	system("cls");
	printf("�п�J�@�� 'a' �� 'n' ���r��\n");
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
		  printf("*");
		  }
		  printf("\n");
		}
		 
		
	}
}
//�����D���A�ÿ�X*�����������T���� 

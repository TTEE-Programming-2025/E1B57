#include<stdio.h>
#include<stdlib.h>
#define password 2025
#define maxpasswordtry 3
int main(void)
{
	//��X�ܤ�20��ӤH���檺�e�� 
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

//�ץ��e�⦸�K�X���~�A�ĤT�����T�ɡA���|���"�K�X���T"�����D 

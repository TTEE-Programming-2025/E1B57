#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    /*�B�J1 ��ܭӤH���檺�e��*/ 
	int i;
	for(i=0;i<4;i++)
	 {
		 printf("********************\n");
		 printf("*\n");
		 printf("�{���]�p�@�~�@\n"); 
		 printf("*\n");
		 printf("********************\n");
	 } 
	printf("\n");
	printf("��Enter���~��...\n");
	getchar();
	fflush(stdin);
	system("cls");
	
	/*�B�J2 ���ұK�X*/ 
	int pass=2024,inpass;
	
	printf("�п�J4��Ʀr�K�X:\n");
	scanf("%d",&inpass);
	
	if(inpass==pass)
	{
		printf("�w��!\n");
		/*�B�J3 ��ܥD���*/
		system("cls");
		printf("--------------------------\n");
		printf("| 'A'...'Z' : Uppercase  |\n");
		printf("| 'a'...'z' : Lowercase  |\n");
		printf("| '0'...'9' : Digit      |\n");
		printf("| Otherwise : E1B57���h�w|\n");
		printf("--------------------------\n");
		/*�B�J4 �B�z�r����J*/
		char inch;
		printf("�п�J�@�Ӧr��\n");
		scanf(" %c",&inch);   /*���޸��e���[�W�@�ӪŮ��קKŪ��\n*/
		if(inch>='A' && inch<='Z')
		 printf("Uppercase\n");
		else if(inch>='a' && inch<='z')
	  	 printf("Lowercase\n");
		else if(inch>='0' && inch<='9')   /*��J�O�r���ҥH0�M9�n�[�W��޸�*/
	  	 printf("Digit\n");
	  	else
	  	 printf("E1B57���h�w\n");

	}
	else
	{
		printf("�K�X���~\a\n");
	}
	system("pause");
	return 0;
}
//�߱o
//�o���@�~���ڧ���x��J���O�٦��@�ǧκA�W���B��
//���̭��n���٬O�ǲߨ�Fgithub�ϥΪ��򥻪��� 





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
			
			while(1)
			{ 
			    menu();
			    char choice;
	            printf("�п�J�z����� (A,a/B,b/C,c): \n");
            	scanf(" %c",&choice);
		        //�B�J�T �����T����
		        //�B�J�| �E�E���k��
				//�B�J�� continue 
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
			        	printf("�L�Ī��ﶵ�A�Э��s��J\n");
		    	}
			} 
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

void menu(void)
{
	printf("*****************�D���*****************\n");
	printf("| a. �e�X�����T����\n");
	printf("| b. ��ܭ��k��\n");
	printf("| c. ����\n");
	printf("*****************�D���*****************\n");
	printf("\n");
}

void funcA(void)
{
	int i,j,k;
	char input;
	system("cls");
	printf("�п�J�@�� 'a' �� 'n' ���r��\n");
	
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
		    printf("���U���N��^��D���\n");
		    fflush(stdin);
	        getchar();
	        system("cls");
	        return;
        }
         
	    else
	    {
	 	    printf("���b 'a' �� 'n' ����\n");
	 	    printf("�Э��s��J�@�� 'a' �� 'n' ���r��\n");
	    }
    }
}

void funcB(void)
{
	int n,i,j;
	printf("�п�J�@�� 1 �� 9 ����� n\n");
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
		    printf("���U���N��^��D���\n");
		    fflush(stdin);
	        getchar();
	        system("cls");
	        return;
	    }
     	else
	    {
		    printf("���b 1 �� 9 ����\n");
	 	    printf("�Э��s��J�@�� 1 �� 9 ����� n\n");
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
		    printf("���O Y,y/N,n \n");
	 	    printf("�Э��s��J�@��\n");
	    }
	} 
} 

//�ץ�funcA�禡��else����X���~�A����funcB�MfuncC�禡 �A���g�߱o 

/*�߱o : 
        �o���@�~���ڹ��禡���B�Χ�[���x�F�C�쥻�Q���ण�δN���ΡA
         ���G�o�{�{�����I�ӽ����F�A�᭱��{����}�Ӥ~�y�L����K��\Ū�A 
		 �쥻�u�u���{���S����Pı�A�����@�I����~�`����{��禡�����n�ʡC*/  

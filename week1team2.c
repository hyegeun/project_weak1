#include <stdio.h> 
#include <stdlib.h> // srand, rand�Լ���  ���Ե� ������� 
#include <time.h> // time�Լ���  ���Ե� ������� 
#include <string.h> // strcpy, strcmp�Լ��� ���Ե� ������� 
#include <locale.h> // �ѱ� �Է� �ޱ� ���� ������� 
#include <windows.h> // Sleep, system�Լ��� ���Ե� ������� 
// Sleep�Լ��� �Ű������� ������ 1000���� 1��, �� 1�и��� 
// system("cls"); // ȭ���� ����� ��� 
 
struct Information { // ��  �Լ��� ���� ����, ����ü ��  ��� ���� 

// �Է� ���� ������ ���� �ִ� 20���� ����(�ִ� �ο� ��������)
// ���ڿ�(char)�� 2�� �迭�� ���� ���� ���� 
	char Name[100][20];
	char Address[100][50];
	char PhoneNumber[100][20];
	int Birthday[100];
	int Year[100];
	int Deposit[100];
	int AccountMoney[100];
	int ID[100];
	char AccountType[100][15];
	int Loan[100];
};

struct Information newacc; // �������ι����࿡�� �� ����ü ���� ����  

// ���� ����
int count= 0;
int i;
int AccountPasswd= 1016; //������ ��й�ȣ 

void new_acc(); // ���� ���� �Լ� 
void edit(); // �ּ�, �ڵ��� ��ȣ ���� �Լ�  
void transact(); //�����, �۱� �Լ�  
void view_list(); //���� �� ���� �Լ�  
void loan_money(); //���� �ѵ� ��ȸ �Լ�  
void erase(); //���� ���� �Լ�  
void see(); //��� ���� ���� ��ȸ �Լ�  
void stillmoney_otherbank(); //����, �鸸�� �Լ�  

int main(void) { //�����Լ� 
	
	menu();
	printf("\n��������ý����� ����Ǿ����ϴ�.\n");
	printf("�������ι� ������ �̿����ּż� �����մϴ�.\n"); 
	Sleep(10000);
    system("cls");

	return 0;
}

void menu() { //�޴��Լ� 
	
	int exitnum = 1; //���� ���� ���ѷ����� ������ ���ؼ�  
	while( exitnum == 1 ){
		
		int a;
	    for (a= 0; a < 40 ; a++) {
		    printf("~");
	    }
	    printf("\n�������ι� ���࿡ ���Ű� ȯ���մϴ�\n");
	
        for (a = 0; a < 40 ; a++) {
	        printf("~");
	    }
	
	    printf("\n\n������: ������\n��: ������");
	    printf("\n\n\n\n"); 
	    printf("�ѱ��� ����ϴ� �츮 �������ι� ������ �ѱ��ε鿡�� ����޴� �� 1������ �����Դϴ�.\n");
	    printf("����, �������ι� ������ ������ ����� ������ �����ϰ� �ֽ��ϴ�!\n");
	    printf("� �������ι� ���� ���¸� �����Ͽ� ������ ����������~\n");
		
		int t;	// ���밣�� ���м��� ���� ���ؼ� 
		for ( t=0; t<25; t++){
			printf("��");}
			
		int Number;  
	    printf("\n1. ���� ����\n");
	    printf("2. �ڵ��� ��ȣ, �ּ� ����\n");
	    printf("3. �����, �۱�\n");
	    printf("4. ���� �� ����\n");
	    printf("5. ���� �ѵ� ��ȸ\n");
	    printf("6. ���� ����\n");
	    printf("7. �� �������� Ȯ��(������ ����)\n");
	    printf("8. ����, �鸸��!\n");
	    printf("9. ������\n");
	    printf("\n���� ���� ��ȣ�� �Է����ּ���.\n");
	    scanf("%d", &Number);
	    
	    Sleep(500); 
        system("cls");
        
	    switch(Number) {
		    case 1:
			    new_acc();
			    break;
			    
			case 2:
				edit();
				break;
				
			case 3:
				transact();
				break;
				
			case 4: 
			    view_list();
				break; 
			
			case 5:
			    loan_money();
			    break;
					
			case 6:
				erase();
				break;
				
			case 7:
				see();
				break;		
		    
		    case 8:
			    stillmoney_otherbank();
				break;	
				
			case 9:
				exitnum++; //exitnum�� ���� �����Ͽ� ���ѷ������� ����� �� 
				break;
			
			default: // �߸������� �� 
				break;
			}	
	} 
	Sleep(500);
    system("cls");
}

void new_acc() { //���� ���� �Լ�  
	srand(time(NULL)); //�������� �ð��� ���� ��� ���ϰ� �ϱ� ���ؼ�  
	
	i = count;

	printf("\n�̸��� 'ȫ�浿'ó�� ��ĭ���� �����ּ���.\n");
	scanf("%s", newacc.Name[i]);
	fflush(stdin); // �Է� ���� ����� 

	printf("�ּҸ� �����ּ���.\n");
	scanf("%[^\t\n]s", newacc.Address[i]); 	// ������ ������ �Է��� �ޱ� ���ؼ�  
	fflush(stdin);
	

	printf("��������� YYYYMMDD�� �����ּ���.\n");
	scanf("%d", &newacc.Birthday[i]);
	fflush(stdin);
	
	printf("�ڵ��� ��ȣ�� �����ּ���.\n");
	scanf("%[^\t\n]s", newacc.PhoneNumber[i]);
	fflush(stdin); 
	
	int Num;
	int numbernumber = 1; //while�� ���ѷ����� ����
	
	while ( numbernumber == 1) {
		
		printf("Saving ���¸� ���Ͻø� 1��, Current ���¸� ���Ͻø� 0�� �Է����ּ���.\n");
	    scanf("%d", &Num);
	
	    if( Num == 1 ){
		    printf("������� �Ͻðڽ��ϱ�?(1��, 2��, 3��)\n");
		    scanf("%d", &newacc.Year[i]);
		    strcpy(newacc.AccountType[i], "Saving");
		
		    printf("��ġ������ ���� �ݾ��� �Է����ּ���.\n");
		    scanf("%d", &newacc.Deposit[i]);	
		    newacc.AccountMoney[i] = newacc.Deposit[i];	
		    numbernumber++; //���ѷ����� ���������� ���ؼ� 
	    }
    	else if (Num == 0){
		    printf("��ġ������ ���� �ݾ��� �Է����ּ���.\n");
		    scanf("%d", &newacc.Deposit[i]);
		    strcpy(newacc.AccountType[i], "Current");
		    newacc.AccountMoney[i] = newacc.Deposit[i];
		    numbernumber++;
	    }
	    else {
		    printf("�����Դϴ�. �ٽ� �õ����ּ���.\n\n");
	    }
		
	}



	if(i==0) { // ó�� �ڵ� �����ϸ� i=count == 0�̶� ���� 
        newacc.ID[i] = rand() % 100000000; // ���� ��, ���� 8�ڸ����� ������  100000000���� ����
        printf("������ ID�� %08d�Դϴ�.\n\n", newacc.ID[i]);
    }  // count++�Ǽ� i=1�� ���¶� �������ʹ� else������ ��
    else {  
        
        int number=1;
		 
        while(number == 1) { // ���� ��, ���� 8�ڸ����� ������  100000000���� ����

            int j;
            
            for(j=0; j<i; j++) { // id�迭 0������  id�迭 (i-1)������ id�迭 i���̶� ��
            
                if(newacc.ID[j]!=newacc.ID[i]) { 
                    
                    if ( j== i-1 ) {
                    	printf("������ ID�� %08d�Դϴ�.\n\n", newacc.ID[i]); // j�� i-1�� ������ i�� �� ��� 
                        number++; //while���� ���ѷ�����  
                        break;  // for�� Ż��
					}
					else continue; //�ٽ� for������ 
                    
                }
                else {
                	newacc.ID[i] = rand() % 100000000; //���� ������ �������� �ٽ� ���� 
                	continue; 
				}
            } 
        }
    }	
    
    count++;
    
    Sleep(10000); 
    system("cls");
    
}

void edit(){ //���� ���� �Լ�  
	int IDnumber;
	int j=0;

	printf("\n������ ID�� �Է����ּ���.\n");
	scanf("%08d", &IDnumber);
	
	while(IDnumber != newacc.ID[j]) {
		
		if (j >= count) { // ���� ���� ũ�⸦ �Ѿ�� �������� �����Ƿ� 
			printf("��ġ�ϴ� ID�� �����ϴ�.\n\n");
			Sleep(1000); 
            system("cls");
			menu();
		}
		else{
			j++;
		}
		
	}
	
	int EditNumber; 
	printf("�ڵ��� ��ȣ�� �����ϰ� �����ø� 1��, �ּҸ� �����ϰ� �����ø� 2��, �� �� �����ϰ� �����ø� 3�� �Է����ּ���.\n");
	scanf("%d", &EditNumber); 
	fflush(stdin);	
	
	
	switch(EditNumber) {
		case 1:
			printf("\n�����Ͻ� �ڵ��� ��ȣ�� �Է����ּ���.\n");
			scanf("%[^\t\n]s", newacc.PhoneNumber[j]); //���� ������ ���� ���� ��� 
			printf("\n����� �ڵ��� ��ȣ�� %s �Դϴ�.\n\n", newacc.PhoneNumber[j]);
			break;
			
		case 2:
			printf("�����Ͻ� �ּҸ� �Է����ּ���.\n");
			scanf("%[^\t\n]s", newacc.Address[j]);
			printf("\n����� �ּҴ� %s �Դϴ�.\n\n", newacc.Address[j]);
			break;
			
		case 3:
			printf("�����Ͻ� �ڵ��� ��ȣ�� �Է����ּ���.\n\n");
			scanf("%[^\t\n]s", newacc.PhoneNumber[j]);
			fflush(stdin);
			printf("�����Ͻ� �ּҸ� �Է����ּ���.\n\n");
			scanf("%[^\t\n]s", newacc.Address[j]);
			fflush(stdin);
			printf("\n����� �ڵ��� ��ȣ�� %s �Դϴ�.\n", newacc.PhoneNumber[j]);
			printf("\n����� �ּҴ� %s �Դϴ�.\n\n", newacc.Address[j]);
			break;
			
		default: //�Է��� �߸����� �� 
			printf("�����Դϴ�.\n");
			menu();
			Sleep(1000); 
            system("cls");
			break;
	}
	Sleep(5000); 
    system("cls");
}

void transact() {
	int senderid; //senderid�� ������ ��� id 
	int getterid; //getterid�� �޴� ��� id 
	int sender=0, getter=0;  // sender�� ������ ��� ������ ��ġ�� ��, getter�� �޴� ��� ������ ��ġ�� ��. 
	int GetMoney, OutMoney; // getmoney�� �Աݾ�, outmoney�� ��ݾװ� �۱ݾ� 
	
	printf("\n������ ID�� �Է����ּ���.\n");
	scanf("%08d", &senderid);

	while( senderid != newacc.ID[sender]) { // �Է� ���� id�� ��ȸ�� id�� ã�� ����
		
		if ( sender >= count) {
			printf("��ġ�ϴ� ID�� �����ϴ�.\n\n");
			Sleep(1000); 
            system("cls");
			menu();
		}
		else{
			sender++;
		}
		
	}
	
	// ��ȸ�� ���� Ȯ�� 
	printf("\nID: %08d\n", newacc.ID[sender]);
	printf("���� �ܾ�: %d��\n", newacc.AccountMoney[sender]);
	printf("���� Ÿ��: %s\n", newacc.AccountType[sender]);
	
	int SelectMoney;
	printf("\n�Ա��� ���Ͻø� 1����, ����� ���Ͻø� 2����, �۱��� ���Ͻø� 3��, ��Ҵ� 4���� �Է����ּ���.\n");
	scanf("%d", &SelectMoney);
	 
	switch (SelectMoney) {
		
		case 1: //�Ա�  
			printf("\n�Ա��Ͻ� �ݾ��� �Է����ּ���.\n");
			scanf("%d", &GetMoney);
			newacc.AccountMoney[sender] += GetMoney;
			printf("\n�Ա� �� �ܾ�: %d��\n\n", newacc.AccountMoney[sender]);
			break;
			
		case 2: //���  
		    // ���� Ÿ�� ��ġ ���� Ȯ�� 
			if (strcmp(newacc.AccountType[sender], "Current") == 0) {
				printf("\n����Ͻ� �ݾ��� �Է����ּ���.\n");
				scanf("%d", &OutMoney);
				
				if (newacc.AccountMoney[sender] >= OutMoney) {
					
					newacc.AccountMoney[sender] -=OutMoney;
				    printf("\n��� �� �ܾ�: %d��\n\n", newacc.AccountMoney[sender]);	
				}
				
				else {
					
					printf("\n�ܾ��� �����մϴ�.\n");
					Sleep(1000); 
                    system("cls");
					menu(); 
				}
			
						
			}
			else {
				printf("\nSaving ���´� ����Ͻ� �� �����ϴ�.\n");
				Sleep(1000); 
                system("cls");
				menu();
			}
			break;
			
		case 3: //�۱�  
			
			if (strcmp(newacc.AccountType[sender], "Current") == 0) {
				printf("\n�޴� ����� ID�� �����ּ���.\n");
				scanf("%08d", &getterid);
				
				while ( getterid != newacc.ID[getter]){
					
					if (getter >= count) {
			            printf("��ġ�ϴ� ����� �����ϴ�.\n\n");
			            Sleep(1000); 
                        system("cls");
			            menu();
		                }
		            
					else{
			            getter++;
		            }
						
				}
				
				int num;
				printf("\n�޴� ����� ã�ҽ��ϴ�.");
				printf("\n %s %d�� �½��ϱ�?", newacc.Name[getter], newacc.Birthday[getter]);
				printf("\n ������ 1��, �ƴϸ� 2�� �Է����ּ���.\n"); 
				scanf("%d", &num);
				
				switch (num) {
					case 1:
						printf("\n������ �ݾ��� �Է����ּ���.\n");
						scanf("%d", &OutMoney);
						
						if (newacc.AccountMoney[sender] >= OutMoney) {
							
							newacc.AccountMoney[sender] -= OutMoney;
						    newacc.AccountMoney[getter] += OutMoney;
						    printf("\n�۱� �� ���� �ܾ�: %d��\n\n", newacc.AccountMoney[sender]);
						}
						
						else {
							printf("\n�ܾ��� �����մϴ�.\n");
							Sleep(1000); 
                            system("cls");
							menu();
						}
					
						break;
						
					case 2:
						printf("\n �����մϴ�.\n");
						Sleep(1000); 
                        system("cls");
						menu();
						break;
					
					default:
						printf("\n �����Դϴ�. ó������ �ٽ� �õ����ּ���.\n");
						Sleep(1000); 
                        system("cls");
						menu();
						break;
				}
			}
			else {
				printf("\nSaving ���´� �۱��Ͻ� �� �����ϴ�.\n");
				Sleep(1000); 
                system("cls");
				menu();			
			}
			break;
		
		case 4:
			Sleep(1000); 
            system("cls");
			menu();
			break;
					
		default:
			printf("\n�����Դϴ�.\n");
			Sleep(1000); 
            system("cls");
			menu();
			break;
			
	}
	Sleep(4000); 
    system("cls");
}

void view_list() {
	int IDnumber; // �� ID ��ȣ  
	int j=0;  

	printf("\n������ ID�� �Է����ּ���.\n");
	scanf("%d", &IDnumber);
	
	while(IDnumber != newacc.ID[j]) { //id ���� ���� Ȯ��  
		
		if ( j > count) {
			printf("��ġ�ϴ� ID�� �����ϴ�.\n\n"); // ���� ���� ũ�⸦ �Ѿ�� �������� �����Ƿ� 
			Sleep(1000); 
            system("cls");
			menu();
		}
		else{
			j++;
		}
		
	}
	
	printf("\n������ ��������\n\n");
	printf("�̸�: %s\n", newacc.Name[j]);
	printf("�ּ�: %s\n", newacc.Address[j]);
	printf("�������: %d\n", newacc.Birthday[j]);
	printf("�ڵ��� ��ȣ: %s\n", newacc.PhoneNumber[j]);
	printf("���� ����: %s\n", newacc.AccountType[j]);
	printf("��ġ��: %d��\n", newacc.Deposit[j]);
	printf("���� �ܾ�: %d��\n", newacc.AccountMoney[j]);
	printf("ID: %08d\n\n", newacc.ID[j]);
	
	Sleep(6000); 
    system("cls");
}

void loan_money() { //�̽��Ϳ���1 -> ����� �ѵ� ��ȸ �Լ� 
	int IDnumber; //���̵� Ȯ�� 
	int j = 0;
	int num = 1;
	
	while (num == 1) { //���ѷ��� ��� 
		
		printf("\n������ ID�� �Է����ּ���.\n");
	    scanf("%08d", &IDnumber);
	
	    while(IDnumber != newacc.ID[j]) { //id ���� ���� Ȯ��  
		
		    if (j >= count) { // ���� ���� �Ѿ�� �ʿ䰡 �����Ƿ� 
			    printf("��ġ�ϴ� ID�� �����ϴ�.\n\n");
			    menu();
		   }
		    else{
			    j++;
		    }
		
       	}
       	
       	if (strcmp(newacc.AccountType[j], "Saving") == 0) { //���°� saving�� �� 

            if (newacc.Deposit[j] <= 2000000) {
               
			    switch (newacc.Year[j]) { //���� �⵵�� ���� 
                	
                	case 1: 
					    newacc.Loan[j] = 3*newacc.Deposit[j];
						break;
						
                    case 2: 
					    newacc.Loan[j] = 5*newacc.Deposit[j];
						break;
                    case 3:
                    	newacc.Loan[j] = 6*newacc.Deposit[j];
						break;
				}
            }
            
            else if (2000000 < newacc.Deposit[j] <= 5000000) {  
                switch (newacc.Year[j]) {
            	
            	    case 1: 
				        newacc.Loan[j] = 5*newacc.Deposit[j];
					    break;
                    case 2:
                    	newacc.Loan[j] = 7*newacc.Deposit[j];
						break;
                    case 3:
                    	newacc.Loan[j] = 8*newacc.Deposit[j];
						break;
			    }
        
            }
            
            else {
                switch (newacc.Year[j]) {
                	
                	case 1: 
                        newacc.Loan[j] = 7*newacc.Deposit[j];
						break;
                    case 2:
                    	newacc.Loan[j] = 8*newacc.Deposit[j];
						break;
						
                    case 3:
                    	newacc.Loan[j] = 10*newacc.Deposit[j];
						break;
				}
                    
            }  

        } //Saving �߰�ȣ
		
		else if (strcmp(newacc.AccountType[j], "Current") == 0) { //���°� current�� �� 
			
            if (newacc.AccountMoney[j] <= 4000000)
			    newacc.Loan[j] = newacc.AccountMoney[j];
			    
            else if (4000000 < newacc.AccountMoney[j] <= 8000000)
			    newacc.Loan[j] = 2*newacc.AccountMoney[j];
			    
            else if (8000000 < newacc.AccountMoney[j] <= 12000000)
			    newacc.Loan[j] = 4*newacc.AccountMoney[j];
			    
            else newacc.Loan[j] = 6*newacc.AccountMoney[j];
        } //Current �߰�ȣ 
		
		printf("\n���� ��ȸ�Ͻ� ���� ����\n");
        printf("ID : %08d\n", newacc.ID[j]);
        printf("�̸� : %s\n", newacc.Name[j]);
        printf("����� �ִ� �ѵ� : %d��\n", newacc.Loan[j]);

        int number;
		printf("�޴��� ���ư��÷��� 1��, �ٽ� ��ȸ�Ͻ÷��� 0�� �Է����ּ���. \n");
        scanf("%d", &number);

        if (number == 0)
		    continue;
		    
        else if (number == 1) {
        	Sleep(500); 
            system("cls");
        	menu();
			break;
		}
			
        else {
        	printf("�����Դϴ�.\n");
        	menu();
		}
		
		
	} //while�� �߰�ȣ 
    
}

void erase(){ //���� ���� �Լ�  
	
	int IDnumber; //�� ID 
	int j=0; 
	
	printf("\n�����Ͻ� ������ ID�� �Է����ּ���.\n");
	scanf("%d", &IDnumber);
	
	while(IDnumber != newacc.ID[j]) { //ã�� ID�� �ٸ��ٸ� �ٸ� ID�� ã�ƺ����ϹǷ� 
		
		if (j >= count) { // ���� ���� ũ�⸦ �Ѿ�� �������� �����Ƿ� 
			printf("��ġ�ϴ� ID�� �����ϴ�.\n\n");
			Sleep(1000); 
            system("cls");
			menu();
		}
		else{
			j++;
		}	
	}
	
	printf("\n�̸�: %s\n", newacc.Name[j]);
    printf("�ּ�: %s\n", newacc.Address[j]);
	printf("�������: %d\n", newacc.Birthday[j]);
	printf("�ڵ��� ��ȣ: %s\n", newacc.PhoneNumber[j]);
	printf("���� ����: %s\n", newacc.AccountType[j]);
	printf("��ġ��: %d��\n", newacc.Deposit[j]);
	printf("���� �ܾ�: %d��\n", newacc.AccountMoney[j]);
	printf("ID: %08d\n\n", newacc.ID[j]);
	
	
	int erasernum;
	
	printf("\n������ ���Ͻø� 1��, �׷��� ������ 0�� �Է��ϼ���.\n");
	scanf("%d", &erasernum);
	
	if (erasernum == 1) { 
		strcpy(newacc.Name[j], "0");
		strcpy(newacc.Address[j], "0");
		newacc.Birthday[j] = 0;
		strcpy(newacc.PhoneNumber[j], "0");
		strcpy(newacc.AccountType[j], "0");
		newacc.Deposit[j] = 0;
		newacc.AccountMoney[j] = 0;
		newacc.Year[j] = 0;
		newacc.ID[j] = -1; // ���°� �������� �ʰ� �ϱ� ���ؼ�, see()�Լ��� ���ϰ� �ϱ� ���ؼ� 
		printf("\n������ ID�� ���������� �����Ǿ����ϴ�.\n\n");
		
		}
	else if (erasernum == 0) {
		Sleep(500); 
        system("cls");
		menu();
	}
	else {
		printf("�����Դϴ�.\n");
		Sleep(1000); 
        system("cls");
		menu();
	}
	Sleep(3000); 
    system("cls");
}

void see() { //��� ���� ���� ��ȸ �Լ�  
	
	int Passwd;
	
	printf("\n������ ��й�ȣ�� �Է��ϼ���.\n"); //������ ��й�ȣ�� �𸣸� �� �� ���� 
	scanf("%d", &Passwd);
	
	if (Passwd == AccountPasswd){
				
	    int j;
	    int num = 0;
	    for (j=0; j < count; j++) {
	    	
	    	if(newacc.ID[j] != -1) { //������ ���´� print���� �ʵ��� �ϱ� ���� 
	    		printf("\n%d �� ȸ�� ����\n", ++num );
	            printf("�̸�: %s\n", newacc.Name[j]);
	            printf("�ּ�: %s\n", newacc.Address[j]);
	            printf("�������: %d\n", newacc.Birthday[j]);
	            printf("�ڵ��� ��ȣ: %s\n", newacc.PhoneNumber[j]);
	            printf("���� ����: %s\n", newacc.AccountType[j]);
	            printf("��ġ��: %d��\n", newacc.Deposit[j]);
	            printf("���� �ܾ�: %d��\n", newacc.AccountMoney[j]);
	            printf("ID: %08d\n\n", newacc.ID[j]);
				}
			}
		    
			}
	
	else {
		printf("\n��й�ȣ�� Ʋ�Ƚ��ϴ�.\n\n");
		Sleep(1000); 
        system("cls");
		menu();
	}
	Sleep(10000); 
    system("cls");
}

void stillmoney_otherbank() { // �̽��Ϳ���2 -> ����, �鸸�� �Լ�  
	
	struct Information samsung; // ����ü ������ �����Ͽ� Ÿ����� ������ �޸��� 
	samsung.AccountMoney[1] = 100000000; //Ÿ����¿� �ִ� �������� ���� �ܾ�  
	 
	
	int number;
	int whatnumber; // ���� ������ ��ȣ 
	int luckeynumber; //��ǻ�Ͱ� ������ ��ȣ 
	luckeynumber = rand() % 3; //�Ź� ��ȣ�� �޸� �� �ζǰ��� ������ �� 
	srand(time(NULL)); 
	
	int IDnumber; //�� id �˻� 
	int j=0;

	printf("\n������ ID�� �Է����ּ���.\n");
	scanf("%08d", &IDnumber);
	
	while(IDnumber != newacc.ID[j]) {
		
		if (j >= count) { // ���� ���� ũ�⸦ �Ѿ�� �������� �����Ƿ� 
			printf("��ġ�ϴ� ID�� �����ϴ�.\n\n");
			Sleep(1000); 
            system("cls");
			menu();
		}
		else{
			j++;
		}
		
	}
	
	printf("\n���� ��������� Ÿ����°� �ֽ��ϴ�.\n");
	printf("\n 0, 1, 2, 3�� �� �ϳ��� �����ϸ� �������� Ÿ����¿��� �鸸���� ���Ŀ� �� �ֽ��ϴ�.\n");
	printf("�����Ͻðڽ��ϱ�?\n");
	printf("������ ���Ͻø� 1, �޴��� ���÷��� 0�� �Է����ּ���.\n");
	scanf("%d", &number);
	
	if (number == 1) { //���� 
		printf("\n\n0, 1, 2, 3���� �ϳ��� �Է����ּ���.\n");
		scanf("%d", &whatnumber);
		
		if (whatnumber == luckeynumber) { //��÷  
				
			printf("\n�����մϴ�! �������� Ÿ����¿��� �鸸���� ���ĿԽ��ϴ�!\n");
			newacc.AccountMoney[j] += 1000000;
			samsung.AccountMoney[1] -= 10000000;
			printf("\n���� �ܾ�: %d", newacc.AccountMoney[j]);
			Sleep(5000);
            system("cls");
		}
		
		else { //�� 
			printf("�ƽ��Ե� �����ϼ̽��ϴ�. ���� ��ȸ�� ���������!");
			Sleep(500);
            system("cls");
			menu(); 
		}
    }
		
	else if (number == 0) { //�������� �ʰ� �޴��� ���ư� 
		printf("�޴��� ���ư��ϴ�.");
		Sleep(500);
        system("cls");
		menu();
	}
	
	else {
		printf("�߸� �Է��ϼ̽��ϴ�. �޴��� ���ư��ϴ�.");
		Sleep(500);
        system("cls");
		menu();
	}

}

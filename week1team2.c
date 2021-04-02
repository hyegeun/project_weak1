#include <stdio.h> 
#include <stdlib.h> // srand, rand함수가  포함된 헤더파일 
#include <time.h> // time함수가  포함된 헤더파일 
#include <string.h> // strcpy, strcmp함수가 포함된 헤더파일 
#include <locale.h> // 한글 입력 받기 위한 헤더파일 
#include <windows.h> // Sleep, system함수가 포함된 헤더파일 
// Sleep함수의 매개변수는 단위가 1000분의 1초, 즉 1밀리초 
// system("cls"); // 화면을 지우는 기능 
 
struct Information { // 각  함수에 사용될 변수, 구조체 및  멤버 정의 

// 입력 받을 계좌의 수를 최대 20으로 제한(최대 인원 수정가능)
// 문자열(char)은 2차 배열로 열에 정보 저장 
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

struct Information newacc; // 나랏말싸미은행에서 쓸 구조체 변수 선언  

// 전역 변수
int count= 0;
int i;
int AccountPasswd= 1016; //관리자 비밀번호 

void new_acc(); // 계좌 생성 함수 
void edit(); // 주소, 핸드폰 번호 변경 함수  
void transact(); //입출금, 송금 함수  
void view_list(); //계좌 상세 정보 함수  
void loan_money(); //대출 한도 조회 함수  
void erase(); //계좌 삭제 함수  
void see(); //모든 계좌 정보 조회 함수  
void stillmoney_otherbank(); //도전, 백만원 함수  

int main(void) { //메인함수 
	
	menu();
	printf("\n은행관리시스템이 종료되었습니다.\n");
	printf("나랏말싸미 은행을 이용해주셔서 감사합니다.\n"); 
	Sleep(10000);
    system("cls");

	return 0;
}

void menu() { //메뉴함수 
	
	int exitnum = 1; //때에 따라 무한루프를 만들어내기 위해서  
	while( exitnum == 1 ){
		
		int a;
	    for (a= 0; a < 40 ; a++) {
		    printf("~");
	    }
	    printf("\n나랏말싸미 은행에 오신걸 환영합니다\n");
	
        for (a = 0; a < 40 ; a++) {
	        printf("~");
	    }
	
	    printf("\n\n은행장: 김혜근\n상무: 이형석");
	    printf("\n\n\n\n"); 
	    printf("한글을 사랑하는 우리 나랏말싸미 은행은 한국인들에게 사랑받는 제 1금융권 은행입니다.\n");
	    printf("또한, 나랏말싸미 은행은 무이자 대출금 제도를 시행하고 있습니다!\n");
	    printf("어서 나랏말싸미 은행 계좌를 생성하여 혜택을 누려보세요~\n");
		
		int t;	// 내용간의 구분선을 짓기 위해서 
		for ( t=0; t<25; t++){
			printf("ㅡ");}
			
		int Number;  
	    printf("\n1. 계좌 생성\n");
	    printf("2. 핸드폰 번호, 주소 변경\n");
	    printf("3. 입출금, 송금\n");
	    printf("4. 계좌 상세 정보\n");
	    printf("5. 대출 한도 조회\n");
	    printf("6. 계좌 삭제\n");
	    printf("7. 전 계좌정보 확인(관리자 전용)\n");
	    printf("8. 도전, 백만원!\n");
	    printf("9. 나가기\n");
	    printf("\n들어가고 싶은 번호를 입력해주세요.\n");
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
				exitnum++; //exitnum의 값을 변경하여 무한루프에서 벗어나게 함 
				break;
			
			default: // 잘못눌렀을 때 
				break;
			}	
	} 
	Sleep(500);
    system("cls");
}

void new_acc() { //계좌 생성 함수  
	srand(time(NULL)); //랜덤값이 시간에 따라 계속 변하게 하기 위해서  
	
	i = count;

	printf("\n이름을 '홍길동'처럼 빈칸없이 적어주세요.\n");
	scanf("%s", newacc.Name[i]);
	fflush(stdin); // 입력 버퍼 지우기 

	printf("주소를 적어주세요.\n");
	scanf("%[^\t\n]s", newacc.Address[i]); 	// 공백을 포함한 입력을 받기 위해서  
	fflush(stdin);
	

	printf("생년월일을 YYYYMMDD로 적어주세요.\n");
	scanf("%d", &newacc.Birthday[i]);
	fflush(stdin);
	
	printf("핸드폰 번호를 적어주세요.\n");
	scanf("%[^\t\n]s", newacc.PhoneNumber[i]);
	fflush(stdin); 
	
	int Num;
	int numbernumber = 1; //while문 무한루프를 위해
	
	while ( numbernumber == 1) {
		
		printf("Saving 계좌를 원하시면 1을, Current 계좌를 원하시면 0을 입력해주세요.\n");
	    scanf("%d", &Num);
	
	    if( Num == 1 ){
		    printf("몇년으로 하시겠습니까?(1년, 2년, 3년)\n");
		    scanf("%d", &newacc.Year[i]);
		    strcpy(newacc.AccountType[i], "Saving");
		
		    printf("예치금으로 넣을 금액을 입력해주세요.\n");
		    scanf("%d", &newacc.Deposit[i]);	
		    newacc.AccountMoney[i] = newacc.Deposit[i];	
		    numbernumber++; //무한루프를 빠져나오기 위해서 
	    }
    	else if (Num == 0){
		    printf("예치금으로 넣을 금액을 입력해주세요.\n");
		    scanf("%d", &newacc.Deposit[i]);
		    strcpy(newacc.AccountType[i], "Current");
		    newacc.AccountMoney[i] = newacc.Deposit[i];
		    numbernumber++;
	    }
	    else {
		    printf("오류입니다. 다시 시도해주세요.\n\n");
	    }
		
	}



	if(i==0) { // 처음 코드 진입하면 i=count == 0이라 실행 
        newacc.ID[i] = rand() % 100000000; // 난수 들어감, 난수 8자리까지 나오게  100000000으로 수정
        printf("고객님의 ID는 %08d입니다.\n\n", newacc.ID[i]);
    }  // count++되서 i=1인 상태라 다음부터는 else문으로 들어감
    else {  
        
        int number=1;
		 
        while(number == 1) { // 난수 들어감, 난수 8자리까지 나오게  100000000으로 수정

            int j;
            
            for(j=0; j<i; j++) { // id배열 0번부터  id배열 (i-1)번까지 id배열 i번이랑 비교
            
                if(newacc.ID[j]!=newacc.ID[i]) { 
                    
                    if ( j== i-1 ) {
                    	printf("고객님의 ID는 %08d입니다.\n\n", newacc.ID[i]); // j가 i-1과 같으면 i번 이 출력 
                        number++; //while문의 무한루프를  
                        break;  // for문 탈출
					}
					else continue; //다시 for문으로 
                    
                }
                else {
                	newacc.ID[i] = rand() % 100000000; //만약 같으면 랜덤으로 다시 실행 
                	continue; 
				}
            } 
        }
    }	
    
    count++;
    
    Sleep(10000); 
    system("cls");
    
}

void edit(){ //정보 변경 함수  
	int IDnumber;
	int j=0;

	printf("\n고객님의 ID를 입력해주세요.\n");
	scanf("%08d", &IDnumber);
	
	while(IDnumber != newacc.ID[j]) {
		
		if (j >= count) { // 고객들 수의 크기를 넘어가면 존재하지 않으므로 
			printf("일치하는 ID가 없습니다.\n\n");
			Sleep(1000); 
            system("cls");
			menu();
		}
		else{
			j++;
		}
		
	}
	
	int EditNumber; 
	printf("핸드폰 번호를 변경하고 싶으시면 1을, 주소를 변경하고 싶으시면 2를, 둘 다 변경하고 싶으시면 3을 입력해주세요.\n");
	scanf("%d", &EditNumber); 
	fflush(stdin);	
	
	
	switch(EditNumber) {
		case 1:
			printf("\n변경하실 핸드폰 번호를 입력해주세요.\n");
			scanf("%[^\t\n]s", newacc.PhoneNumber[j]); //기존 변수에 값을 새로 덮어씀 
			printf("\n변경된 핸드폰 번호는 %s 입니다.\n\n", newacc.PhoneNumber[j]);
			break;
			
		case 2:
			printf("변경하실 주소를 입력해주세요.\n");
			scanf("%[^\t\n]s", newacc.Address[j]);
			printf("\n변경된 주소는 %s 입니다.\n\n", newacc.Address[j]);
			break;
			
		case 3:
			printf("변경하실 핸드폰 번호를 입력해주세요.\n\n");
			scanf("%[^\t\n]s", newacc.PhoneNumber[j]);
			fflush(stdin);
			printf("변경하실 주소를 입력해주세요.\n\n");
			scanf("%[^\t\n]s", newacc.Address[j]);
			fflush(stdin);
			printf("\n변경된 핸드폰 번호는 %s 입니다.\n", newacc.PhoneNumber[j]);
			printf("\n변경된 주소는 %s 입니다.\n\n", newacc.Address[j]);
			break;
			
		default: //입력을 잘못했을 때 
			printf("오류입니다.\n");
			menu();
			Sleep(1000); 
            system("cls");
			break;
	}
	Sleep(5000); 
    system("cls");
}

void transact() {
	int senderid; //senderid는 보내는 사람 id 
	int getterid; //getterid는 받는 사람 id 
	int sender=0, getter=0;  // sender는 보내는 사람 정보가 위치한 곳, getter는 받는 사람 정보가 위치한 곳. 
	int GetMoney, OutMoney; // getmoney는 입금액, outmoney는 출금액과 송금액 
	
	printf("\n고객님의 ID를 입력해주세요.\n");
	scanf("%08d", &senderid);

	while( senderid != newacc.ID[sender]) { // 입력 받은 id와 조회한 id를 찾는 구문
		
		if ( sender >= count) {
			printf("일치하는 ID가 없습니다.\n\n");
			Sleep(1000); 
            system("cls");
			menu();
		}
		else{
			sender++;
		}
		
	}
	
	// 조회한 계좌 확인 
	printf("\nID: %08d\n", newacc.ID[sender]);
	printf("계좌 잔액: %d원\n", newacc.AccountMoney[sender]);
	printf("계좌 타입: %s\n", newacc.AccountType[sender]);
	
	int SelectMoney;
	printf("\n입금을 원하시면 1번을, 출금을 원하시면 2번을, 송금을 원하시면 3번, 취소는 4번을 입력해주세요.\n");
	scanf("%d", &SelectMoney);
	 
	switch (SelectMoney) {
		
		case 1: //입금  
			printf("\n입금하실 금액을 입력해주세요.\n");
			scanf("%d", &GetMoney);
			newacc.AccountMoney[sender] += GetMoney;
			printf("\n입금 후 잔액: %d원\n\n", newacc.AccountMoney[sender]);
			break;
			
		case 2: //출금  
		    // 계좌 타입 일치 여부 확인 
			if (strcmp(newacc.AccountType[sender], "Current") == 0) {
				printf("\n출금하실 금액을 입력해주세요.\n");
				scanf("%d", &OutMoney);
				
				if (newacc.AccountMoney[sender] >= OutMoney) {
					
					newacc.AccountMoney[sender] -=OutMoney;
				    printf("\n출금 후 잔액: %d원\n\n", newacc.AccountMoney[sender]);	
				}
				
				else {
					
					printf("\n잔액이 부족합니다.\n");
					Sleep(1000); 
                    system("cls");
					menu(); 
				}
			
						
			}
			else {
				printf("\nSaving 계좌는 출금하실 수 없습니다.\n");
				Sleep(1000); 
                system("cls");
				menu();
			}
			break;
			
		case 3: //송금  
			
			if (strcmp(newacc.AccountType[sender], "Current") == 0) {
				printf("\n받는 사람의 ID를 적어주세요.\n");
				scanf("%08d", &getterid);
				
				while ( getterid != newacc.ID[getter]){
					
					if (getter >= count) {
			            printf("일치하는 사람이 없습니다.\n\n");
			            Sleep(1000); 
                        system("cls");
			            menu();
		                }
		            
					else{
			            getter++;
		            }
						
				}
				
				int num;
				printf("\n받는 사람을 찾았습니다.");
				printf("\n %s %d가 맞습니까?", newacc.Name[getter], newacc.Birthday[getter]);
				printf("\n 맞으면 1을, 아니면 2를 입력해주세요.\n"); 
				scanf("%d", &num);
				
				switch (num) {
					case 1:
						printf("\n보내실 금액을 입력해주세요.\n");
						scanf("%d", &OutMoney);
						
						if (newacc.AccountMoney[sender] >= OutMoney) {
							
							newacc.AccountMoney[sender] -= OutMoney;
						    newacc.AccountMoney[getter] += OutMoney;
						    printf("\n송금 후 계좌 잔액: %d원\n\n", newacc.AccountMoney[sender]);
						}
						
						else {
							printf("\n잔액이 부족합니다.\n");
							Sleep(1000); 
                            system("cls");
							menu();
						}
					
						break;
						
					case 2:
						printf("\n 감사합니다.\n");
						Sleep(1000); 
                        system("cls");
						menu();
						break;
					
					default:
						printf("\n 오류입니다. 처음부터 다시 시도해주세요.\n");
						Sleep(1000); 
                        system("cls");
						menu();
						break;
				}
			}
			else {
				printf("\nSaving 계좌는 송금하실 수 없습니다.\n");
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
			printf("\n오류입니다.\n");
			Sleep(1000); 
            system("cls");
			menu();
			break;
			
	}
	Sleep(4000); 
    system("cls");
}

void view_list() {
	int IDnumber; // 고객 ID 변호  
	int j=0;  

	printf("\n고객님의 ID를 입력해주세요.\n");
	scanf("%d", &IDnumber);
	
	while(IDnumber != newacc.ID[j]) { //id 존재 여부 확인  
		
		if ( j > count) {
			printf("일치하는 ID가 없습니다.\n\n"); // 고객들 수의 크기를 넘어가면 존재하지 않으므로 
			Sleep(1000); 
            system("cls");
			menu();
		}
		else{
			j++;
		}
		
	}
	
	printf("\n고객님의 계좌정보\n\n");
	printf("이름: %s\n", newacc.Name[j]);
	printf("주소: %s\n", newacc.Address[j]);
	printf("생년월일: %d\n", newacc.Birthday[j]);
	printf("핸드폰 번호: %s\n", newacc.PhoneNumber[j]);
	printf("계좌 종류: %s\n", newacc.AccountType[j]);
	printf("예치금: %d원\n", newacc.Deposit[j]);
	printf("계좌 잔액: %d원\n", newacc.AccountMoney[j]);
	printf("ID: %08d\n\n", newacc.ID[j]);
	
	Sleep(6000); 
    system("cls");
}

void loan_money() { //이스터에그1 -> 대출금 한도 조회 함수 
	int IDnumber; //아이디 확인 
	int j = 0;
	int num = 1;
	
	while (num == 1) { //무한루프 사용 
		
		printf("\n고객님의 ID를 입력해주세요.\n");
	    scanf("%08d", &IDnumber);
	
	    while(IDnumber != newacc.ID[j]) { //id 존재 여부 확인  
		
		    if (j >= count) { // 고객들 수를 넘어가면 필요가 없으므로 
			    printf("일치하는 ID가 없습니다.\n\n");
			    menu();
		   }
		    else{
			    j++;
		    }
		
       	}
       	
       	if (strcmp(newacc.AccountType[j], "Saving") == 0) { //계좌가 saving일 때 

            if (newacc.Deposit[j] <= 2000000) {
               
			    switch (newacc.Year[j]) { //적금 년도에 따라 
                	
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

        } //Saving 중괄호
		
		else if (strcmp(newacc.AccountType[j], "Current") == 0) { //계좌가 current일 때 
			
            if (newacc.AccountMoney[j] <= 4000000)
			    newacc.Loan[j] = newacc.AccountMoney[j];
			    
            else if (4000000 < newacc.AccountMoney[j] <= 8000000)
			    newacc.Loan[j] = 2*newacc.AccountMoney[j];
			    
            else if (8000000 < newacc.AccountMoney[j] <= 12000000)
			    newacc.Loan[j] = 4*newacc.AccountMoney[j];
			    
            else newacc.Loan[j] = 6*newacc.AccountMoney[j];
        } //Current 중괄호 
		
		printf("\n대출 조회하신 고객님 정보\n");
        printf("ID : %08d\n", newacc.ID[j]);
        printf("이름 : %s\n", newacc.Name[j]);
        printf("대출금 최대 한도 : %d원\n", newacc.Loan[j]);

        int number;
		printf("메뉴로 돌아가시려면 1을, 다시 조회하시려면 0을 입력해주세요. \n");
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
        	printf("오류입니다.\n");
        	menu();
		}
		
		
	} //while문 중괄호 
    
}

void erase(){ //계좌 삭제 함수  
	
	int IDnumber; //고객 ID 
	int j=0; 
	
	printf("\n삭제하실 고객님의 ID를 입력해주세요.\n");
	scanf("%d", &IDnumber);
	
	while(IDnumber != newacc.ID[j]) { //찾는 ID와 다르다면 다른 ID를 찾아봐야하므로 
		
		if (j >= count) { // 고객들 수의 크기를 넘어가면 존재하지 않으므로 
			printf("일치하는 ID가 없습니다.\n\n");
			Sleep(1000); 
            system("cls");
			menu();
		}
		else{
			j++;
		}	
	}
	
	printf("\n이름: %s\n", newacc.Name[j]);
    printf("주소: %s\n", newacc.Address[j]);
	printf("생년월일: %d\n", newacc.Birthday[j]);
	printf("핸드폰 번호: %s\n", newacc.PhoneNumber[j]);
	printf("계좌 종류: %s\n", newacc.AccountType[j]);
	printf("예치금: %d원\n", newacc.Deposit[j]);
	printf("계좌 잔액: %d원\n", newacc.AccountMoney[j]);
	printf("ID: %08d\n\n", newacc.ID[j]);
	
	
	int erasernum;
	
	printf("\n삭제를 원하시면 1을, 그렇지 않으면 0을 입력하세요.\n");
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
		newacc.ID[j] = -1; // 계좌가 존재하지 않게 하기 위해서, see()함수를 편리하게 하기 위해서 
		printf("\n고객님의 ID가 정상적으로 삭제되었습니다.\n\n");
		
		}
	else if (erasernum == 0) {
		Sleep(500); 
        system("cls");
		menu();
	}
	else {
		printf("오류입니다.\n");
		Sleep(1000); 
        system("cls");
		menu();
	}
	Sleep(3000); 
    system("cls");
}

void see() { //모든 계좌 정보 조회 함수  
	
	int Passwd;
	
	printf("\n관리자 비밀번호를 입력하세요.\n"); //관리자 비밀번호를 모르면 볼 수 없음 
	scanf("%d", &Passwd);
	
	if (Passwd == AccountPasswd){
				
	    int j;
	    int num = 0;
	    for (j=0; j < count; j++) {
	    	
	    	if(newacc.ID[j] != -1) { //삭제된 계좌는 print하지 않도록 하기 위해 
	    		printf("\n%d 번 회원 정보\n", ++num );
	            printf("이름: %s\n", newacc.Name[j]);
	            printf("주소: %s\n", newacc.Address[j]);
	            printf("생년월일: %d\n", newacc.Birthday[j]);
	            printf("핸드폰 번호: %s\n", newacc.PhoneNumber[j]);
	            printf("계좌 종류: %s\n", newacc.AccountType[j]);
	            printf("예치금: %d원\n", newacc.Deposit[j]);
	            printf("계좌 잔액: %d원\n", newacc.AccountMoney[j]);
	            printf("ID: %08d\n\n", newacc.ID[j]);
				}
			}
		    
			}
	
	else {
		printf("\n비밀번호가 틀렸습니다.\n\n");
		Sleep(1000); 
        system("cls");
		menu();
	}
	Sleep(10000); 
    system("cls");
}

void stillmoney_otherbank() { // 이스터에그2 -> 도전, 백만원 함수  
	
	struct Information samsung; // 구조체 변수를 설정하여 타행과의 변수를 달리함 
	samsung.AccountMoney[1] = 100000000; //타행계좌에 있는 은행장의 계좌 잔액  
	 
	
	int number;
	int whatnumber; // 고객이 선택한 번호 
	int luckeynumber; //컴퓨터가 선택한 번호 
	luckeynumber = rand() % 3; //매번 번호를 달리 해 로또같은 느낌을 줌 
	srand(time(NULL)); 
	
	int IDnumber; //고객 id 검사 
	int j=0;

	printf("\n고객님의 ID를 입력해주세요.\n");
	scanf("%08d", &IDnumber);
	
	while(IDnumber != newacc.ID[j]) {
		
		if (j >= count) { // 고객들 수의 크기를 넘어가면 존재하지 않으므로 
			printf("일치하는 ID가 없습니다.\n\n");
			Sleep(1000); 
            system("cls");
			menu();
		}
		else{
			j++;
		}
		
	}
	
	printf("\n여기 은행장님의 타행계좌가 있습니다.\n");
	printf("\n 0, 1, 2, 3번 중 하나를 선택하면 은행장의 타행계좌에서 백만원을 훔쳐올 수 있습니다.\n");
	printf("도전하시겠습니까?\n");
	printf("도전을 원하시면 1, 메뉴로 가시려면 0을 입력해주세요.\n");
	scanf("%d", &number);
	
	if (number == 1) { //도전 
		printf("\n\n0, 1, 2, 3번중 하나를 입력해주세요.\n");
		scanf("%d", &whatnumber);
		
		if (whatnumber == luckeynumber) { //당첨  
				
			printf("\n축하합니다! 은행장의 타행계좌에서 백만원을 훔쳐왔습니다!\n");
			newacc.AccountMoney[j] += 1000000;
			samsung.AccountMoney[1] -= 10000000;
			printf("\n계좌 잔액: %d", newacc.AccountMoney[j]);
			Sleep(5000);
            system("cls");
		}
		
		else { //꽝 
			printf("아쉽게도 실패하셨습니다. 다음 기회를 노려보세요!");
			Sleep(500);
            system("cls");
			menu(); 
		}
    }
		
	else if (number == 0) { //도전하지 않고 메뉴로 돌아감 
		printf("메뉴로 돌아갑니다.");
		Sleep(500);
        system("cls");
		menu();
	}
	
	else {
		printf("잘못 입력하셨습니다. 메뉴로 돌아갑니다.");
		Sleep(500);
        system("cls");
		menu();
	}

}

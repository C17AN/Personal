#include <iostream>

using namespace std; 

void showMenu();
void createAccount();
void deposit();
void withdraw();
void printInfo();

typedef struct
{
	char name[20];
	int ID;
	int amountMoney;
} account;

account arr[100000];
int accountCnt;

void showMenu()
{
	int select;
	int cnt; 
	
	while(1)
	{
		cout << "----- Menu -----" << endl;
		cout << "1. 계좌개설" << endl;
		cout << "2. 입 금" << endl;
		cout << "3. 출 금" << endl;
		cout << "4. 계좌정보 전체 출력" << endl;
		cout << "5. 프로그램 종료" << endl;
		cout << " 선 택 : ";
		cin >> select;; 		
		cout << endl;
		
		switch(select)
		{
			case 1:
				createAccount();
				break;
				
			case 2:
				deposit();
				break;
			case 3:
				withdraw();
				break;
			case 4:
				printInfo();
				break;
			case 5:
				return;
			default:
				cout << "유효하지 않은 입력입니다." << endl;
		}
		
	}
}

void createAccount()
{
	cout << endl;
	cout << "[계좌개설]" << endl;
	cout << "ID는 1부터 999,999 사이의 숫자를 입력하세요." << endl;
	cout << "계좌 ID : "; cin >> arr[accountCnt].ID;
	cout << "이 름 : "; 
	cin.ignore();
	cin.getline(arr[accountCnt].name, 20);
	cout << "입금액 : "; cin >> arr[accountCnt].amountMoney;	
	
	cout << endl;
	accountCnt++;
}

void deposit()
{
	int id, depositMoney;
	cout << "[입   금]" << endl;
	cout << "계좌 ID : "; cin >> id;
	cout << "입금액 : "; cin >> depositMoney; 
	for(int i = 0; i < accountCnt; ++i)
	{
		if(arr[i].ID == id)
		{
			arr[i].amountMoney += depositMoney;
			cout << "입금 완료" << endl << endl;
		}
		else cout << "존재하지 않는 ID입니다." << endl;
	}
	
}

void withdraw()
{
	int id, withdrawalMoney;
	cout << "[출   금]" << endl;
	cout << "계좌 ID : "; cin >> id;
	cout << "출금액 : "; cin >> withdrawalMoney; 
	for(int i = 0; i < accountCnt; ++i)
	{
		if(arr[i].ID == id)
		{
			if(arr[i].amountMoney - withdrawalMoney > 0)
			{
				arr[i].amountMoney -= withdrawalMoney;
				cout << "출금 완료" << endl << endl;
			}
			else cout << "잔액이 부족합니다." << endl; 
		}
		else cout << "존재하지 않는 ID입니다." << endl;
	}
}

void printInfo()
{
	for(int i = 0; i < accountCnt; i++)
	{
		cout << "계좌 ID : " << arr[i].ID << endl;
		cout << "이 름 : " << arr[i].name << endl;
		cout << "잔 액 : " << arr[i].amountMoney << "원" << endl << endl;
	}
}

int main()
{	
	showMenu();
}

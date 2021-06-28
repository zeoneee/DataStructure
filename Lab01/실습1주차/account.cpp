// 컴퓨터공학과_2019112587_김지현
// 실습과제 1주차

#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

class bank 
{
	char name[20];
	int acno;
	char actype[4];
	float balance;

public : 
	void init();
	void deposit();
	void withdraw();
	void disp_det();
};
//member functions of bank class
void bank::init()
{
	cout << "New Account" << endl;
	cout << "Enter the Name of the depositor :";
	cin >> name;
	cout << "Enter the Account Number :";
	cin >> acno;
	cout << "Enter the Account Type :(CURR / SAVG / FD / RD / DMAT)";
	cin >> actype;
	cout << "Enter the Amount to Deposit :";
	cin >> balance;
}
void bank::deposit()
{
	float addbalance;
	cout << "Depositing" << endl;
	cout << "Enter the amount to deposit : ";
	cin >> addbalance;
	balance += addbalance;
}
void bank::withdraw()
{
	float minusbalance;
	cout << "Withdrawal" << endl;
	cout << "Enter the amount to withdraw : ";
	cin >> minusbalance;
	balance -= minusbalance;
}
void bank::disp_det()
{
	cout << "Account Details" << endl;
	cout << "Name of the depositor : " << name << endl;
	cout << "Account Number : " << acno << endl;
	cout << "Account type : " << actype << endl;
	cout << "Balance : $" << balance << endl;
}
// main function, exectution starts here
void main(void)
{
	// clrscr();
	bank obj;
	int choice = 1;
	while (choice != 0)
	{
		cout << endl << endl;
		cout << "Enter 0 to exit\n1. Initialize a new acc.\n2. Deposit\n3. Withdraw\n4. See A / c Status\n";
		cin >> choice;
		cin.ignore();
		switch (choice)
		{
		case 0:
			obj.disp_det();
			cout << "EXITING PROGRAM.";
			break;
		case 1:
			obj.init();
			break;
		case 2 :
			obj.deposit();
			break;
		case 3 :
			obj.withdraw();
			break;
		case 4:
			obj.disp_det();
			break;
		default:
			cout << "lllegal Option" << endl;
		}
	}
	_getch();
}
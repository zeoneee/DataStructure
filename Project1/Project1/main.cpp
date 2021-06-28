 // 2019112587_김지현

#include "list.h"
using namespace std;

void print() {
	cout << endl << "Commands:" << endl;
	cout << "  R: read from a file" << endl;
	cout << "  +: add a new entry" << endl;
	cout << "  -: remove an entry" << endl;
	cout << "  W: write to a file" << endl;
	cout << "  M: select a month" << endl;
	cout << "  Q: quit the Program" << endl;
	cout << endl;
 
}

void main()
{
	List testList(100);	// list
	string name; // 이름, 전화번호, 생일
	string phone; 
	string birth;
	string month;	// 입력받을 달
	string file;
	char cmd;	// input command

	do {
		print();
		cin >> cmd;
		switch (cmd) {
		case 'R': case 'r':
			cout << "Enter the name of the file: ";
			cin >> file;
			testList.read(file);
			break;

		case '+':
			cout << "Add an entry:" << endl;
			cin.ignore();
			cout << "Name: "; getline(cin, name, '\n');
			cout << "Phone: "; cin >> phone;
			cout << "Birthday: "; cin >> birth;
			testList.insert(name, phone, birth);
			break;
			
		case '-':
			cout << "Remove an entry:" << endl;
			cin.ignore();
			cout << "Name: "; getline(cin, name, '\n');;
			testList.remove(name);
			break;
			
		case 'W': case 'w':
			cout << "Enter the name of the file: ";
			cin >> file;
			testList.write(file);
			break;

		case 'M': case 'm':
			cout << "Enter the selected month: ";
			cin >> month;
			testList.search(month);
			break;

		case 'Q': case 'q':
			break;

		default:
			cout << "Inactive or invalid command" << endl;
		}

	} while (cmd != 'Q' && cmd != 'q');
}
// 2019112587 김지현

#include "list.h"

extern string smonth[12] = { "January","February","March","April","May","June","July","August","September","October","November" };
extern int monthcnt[12] = { 0,0,0,0,0,0,0,0,0,0,0,0 };

string datalist::getmonth() {
	string mon = birth.substr(0, 2);
	if (mon == "01") {
		month = smonth[0];
		monthcnt[0]++;
	}
	else if (mon == "02") {
		month = smonth[1];
		monthcnt[1]++;
	}
	else if (mon == "03") {
		month = smonth[2];
		monthcnt[2]++;
	}
	else if (mon == "04") {
		month = smonth[3];
		monthcnt[3]++;
	}
	else if (mon == "05") {
		month = smonth[4];
		monthcnt[4]++;
	}
	else if (mon == "06") {
		month = smonth[5];
		monthcnt[5]++;
	}
	else if (mon == "07") {
		month = smonth[6];
		monthcnt[6]++;
	}
	else if (mon == "08") {
		month = smonth[7];
		monthcnt[7]++;
	}
	else if (mon == "09") {
		month = smonth[8];
		monthcnt[8]++;
	}
	else if (mon == "10") {
		month = smonth[9];
		monthcnt[9]++;
	}
	else if (mon == "11") {
		month = smonth[10];
		monthcnt[10]++;
	}
	else if (mon == "12") {
		month = smonth[11];
		monthcnt[11]++;
	}
	return month;
}

List::List(int maxNumber)
	:maxSize(maxNumber), top(-1)
{
	element = new datalist[maxSize];
}

List::~List() {
	delete[] element;
}

void List::read(string file) {
	// 파일 datalist에 입력
	ifstream readFile;
	readFile.open(file);
	if (readFile.is_open()) {
		while (!readFile.eof()) {
			for (int i = 0; i < 3; i++) {
				top++;
				string str;
				getline(readFile, str);
				str= element[top].name;
				getline(readFile, str);
				str = element[top].phone;
				getline(readFile, str);
				str = element[top].birth;
				element[top].month = element[top].getmonth();
			}
		}
		readFile.close();
		showStructure();
	}
	else {
		cout << "Non-existent file" << endl;
	}
}

void List::write(string file) {
	if (isEmpty()) {
		cout << "Empty List" << endl;
	}
	else {
		ofstream writeFile;
		writeFile.open(file);
		for (int i = 0; i <= top; i++) {
			string str;
			str = element[i].name;
			str += "\n";
			writeFile.write(str.c_str(), str.size());
			str = element[i].phone;
			str += "\n";
			writeFile.write(str.c_str(), str.size());
			str = element[i].birth;
			if (!(i==top)) {
				str += "\n";
			}
			writeFile.write(str.c_str(), str.size());
		}
		writeFile.close();
		cout << "The list is written into " << file << endl;
	}
}

void List::insert (string _name, string _phone, string _birth) {
	if (isFull()) {
		cout << "Full List" << endl;
	}
	else {
		top++;
		element[top].name = _name;
		element[top].phone = _phone;
		element[top].birth = _birth;
		element[top].month = element[top].getmonth();
		showStructure();
	}
}

void List::remove(string _name) {
	if (isEmpty()) {
		cout << "Empty List" << endl;
	}
	else {
		int check = 0;
		for (int i = 0; i <= top; i++) {
			if (_name == element[i].name) {
				for (int j = 0; j < 12; j++) {
					if (smonth[j]==element[i].month) {
						monthcnt[j]--;
						break;
					}
				}
				for (int j = i; j < top; j++) {
					element[j] = element[j + 1];
				}
				check = 1;
				top--;
				break;
			}
		}
		if (check == 0) cout << "Non-existent name" << endl;
		showStructure();
	}
}

void List::search(string searchmonth) {
	if (isEmpty()) {
		cout << "Empty List" << endl;
	}
	else {
		for (int i = 0; i < 12; i++) {
			if (searchmonth == smonth[i]) {
				cout << "Total number of birthdays in " << smonth[i] << ": " << monthcnt[i] << endl;
				break;
			}
		}
		for (int i = 0; i <= top; i++) {
			if (searchmonth == element[i].month) {
				cout << element[i].name << endl;
				cout << element[i].phone << endl;
				cout << element[i].birth << endl << endl;
			}
		}
	}

	
}

void List::showStructure() {
	if (isEmpty()) {
		cout << "Empty List" << endl;
	}
	else {
		cout << "Total number of entries in the list : " << top+1 << endl;
		cout << "Number of birthdays in" << endl;
		for (int i = 0; i < 12; i++) {
			if (!(monthcnt[i] == 0))
				cout << "\t" << smonth[i] << ": " << monthcnt[i] << endl;
		}
	}
}

bool List::isFull() {
	return(top == maxSize - 1);
} 

bool List::isEmpty() {
	return(top==-1);
}

void List::clear() {
	top = -1;
	for (int i = 0; i < 12; i++) {
		monthcnt[i] = 0;
	}
}
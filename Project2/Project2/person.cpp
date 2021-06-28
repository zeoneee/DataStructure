// 2019112587 김지현

#include "listlnk.cpp"

class Person {
private:
	string name;
	List<string> friendlist;	// friend list (Person 객체는 따로)
public :
	Person(){

	}

	Person(string name) {
		this->name = name;
	}

	string getname() {
		return name;
	}

	void insertfriend(string name); // friendlist에 추가
	void delfriend(string name);
	bool isfriend(string name); // friendlist에 이름 존재하는지 검색
	void showfriend();	// friendlist 출력
};

void Person::insertfriend(string name) {
	friendlist.insert(name);
}

void Person::delfriend(string name) {
	friendlist.gotoBeginning();
	do {
		if (name == friendlist.getCursor()) {
			friendlist.remove();
			break;
		}
	} while (friendlist.gotoNext());
}


bool Person::isfriend(string name) {
	if (friendlist.isEmpty()) {
		return false;
	}
	else {
		friendlist.gotoBeginning();
		do {
			if (name == friendlist.getCursor()) {	// 이름이 있다
				return true;
			}
		} while (friendlist.gotoNext());
		return false;
	}
}

void Person::showfriend() {
	if (friendlist.isEmpty()) {
		cout << "Empty Friendlist" << endl;
	}
	else {
		friendlist.gotoBeginning();
		do {
			cout << friendlist.getCursor() << " ";
		} while (friendlist.gotoNext());
		cout << endl;
	}
}

void showPerson(List<Person>& list);
void addPerson(List<Person>* list, string name);
void addFriend(List<Person>* list, string name1, string name2);
void delFriend(List<Person>* list, string name1, string name2);
void showFriend(List<Person>* list, string name);
bool isFriend(List<Person>* list, string name1, string name2);
bool search(List<Person>* list, string name);
void gotocursur(List<Person>* list, string name);

void showPerson(List<Person>& list) {
	if (list.isEmpty()) {
		cout << "Empty PersonList" << endl;
	}
	else {
		list.gotoBeginning();
		cout << "[Person List] ";
		do {
			cout << list.getCursor().getname() << " ";
		} while (list.gotoNext());
	}
}

void addPerson(List<Person>* list, string name) {
	if (search(list, name)) {
		cout << "This name aleready exists." << endl;
	}
	else {
		Person* nperson;
		nperson = new Person(name);
		list->insert(*nperson);
	}
}

void addFriend(List<Person>* list, string name1, string name2) {
	if (search(list, name1) && search(list, name2)) {
		gotocursur(list,name1);
		list->getCursor().insertfriend(name2);
		gotocursur(list, name2);
		list->getCursor().insertfriend(name1);
		cout << "add friends" << endl;
	}
	else {
		cout << "Wrong name." << endl;
	}
}

void delFriend(List<Person>* list, string name1, string name2) {
	if (search(list, name1) && search(list, name2)) {
		if (isFriend(list, name1, name2)) {
			gotocursur(list, name1);
			list->getCursor().delfriend(name2);
			gotocursur(list, name2);
			list->getCursor().delfriend(name1);
			cout << "delete friends" << endl;
		}
		else {
			cout << "They are not friend." << endl;
		}
	}
	else {
		cout << "Wrong name." << endl;
	}
}


void showFriend(List<Person>* list, string name) {
	if (search(list,name)) {
		gotocursur(list, name);
		list->getCursor().showfriend();	// cursor를 알아내는게 문제
	}
	else {
		cout << "Wrong name." << endl;
	}
}


bool isFriend(List<Person>* list, string name1, string name2) {
	if (search(list,name1) && search(list,name2)) {
		gotocursur(list, name1);
		return list->getCursor().isfriend(name2); // name1이든, name2든 하나만 해도 ok일듯
	}
	else {
		cout << "Wrong name." << endl;
		return false;
	}
}

bool search(List<Person>* list, string name) {
	if (list->isEmpty()) {
		return false;
	}
	else {
		list->gotoBeginning();
		do {
			if (name == list->getCursor().getname()) {	// 이름이 있다
				return true;
			}
		} while (list->gotoNext());
		return false;
	}
}

// cursor가 해당 name을 갖는 Person객체를 가르키도록
void gotocursur(List<Person>* list, string name) {	
	list->gotoBeginning();
	do {
		if (name == list->getCursor().getname())
			return;
	} while (list->gotoNext());
}

/*-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------*/


void print() {
	cout << endl;
	cout << "P : Create person name" << endl;
	cout << "F : Record that the two specified people are friends" << endl;
	cout << "U : Record that the two specified people are no longer friends" << endl;
	cout << "L : Print out the friends of the specified person" << endl;
	cout << "Q : Check whether the two people are friends" << endl;
	cout << "X : terminate the program" << endl;
	cout << endl;
}

int main() {
	List<Person> personlist; // main에서 person객체 list 생성 
	string name1;			 // input name
	string name2;
	char cmd;				 // input command

	print();

	do {
		showPerson(personlist);

		cout << endl << endl << "Command: ";
		cin >> cmd;
		if (cmd == 'P' || cmd == 'p' || cmd == 'L' || cmd == 'l')
			cin >> name1;
		if (cmd == 'F' || cmd == 'f' ||
			cmd == 'U' || cmd == 'u' || cmd == 'Q' || cmd == 'q')
			cin >> name1 >> name2;

		switch (cmd) {
		case 'P': case 'p':
			addPerson(&personlist, name1);
			break;
		case 'F': case 'f':
			addFriend(&personlist, name1, name2);
			break;
		case 'U': case 'u':
			delFriend(&personlist, name1, name2);
			break;
		case 'L': case 'l':
			showFriend(&personlist, name1);
			break;
		case 'Q': case'q':
			if (isFriend(&personlist, name1, name2)) {
				cout << "Yes" << endl;
			}
			else {
				cout << "No" << endl;
			}
			break;
		case 'X': case 'x':
			break;
		default:
			cout << "Inactive or invalid command" << endl;
		}
	} while (cmd != 'X' && cmd != 'x');
}
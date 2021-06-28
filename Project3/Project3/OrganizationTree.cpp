// 2019112587 ������

#include "OrganizationTree.h"

// Member
Member::Member(string& name, Member* pre) {
	this->name = name;
	this->pre = pre;
	

	subhead = NULL; next = NULL;
}

// Tree
// constructor
Tree::Tree(int ignored) {
	head = NULL;
	cursor = NULL;
}

// destructor
Tree::~Tree() {
	clear();
}

// manipulation
void Tree::hire(string& newname) {	// CEO
	head = new Member(newname, NULL);
}

void Tree::hire(string& name, string& newname) {
	Member* p = retrieve(head, name);
	hiresub(p, newname);
}

void Tree::hiresub(Member* p, string& newname) {
	if (p->subhead == NULL) {
		p->subhead = new Member(newname, p);	// p is superior
	}
	else {
		Member* cursor = p->subhead;
		while (cursor->next != NULL) {
			cursor = cursor->next;
		}
		cursor->next = new Member(newname, cursor);
	}
}

void Tree::fire(string& name) {
	Member* p = retrieve(head, name);
	if (p->subhead != NULL) {
		firesub(p->subhead);	// p�� �ڸ��� sub�� ��ü�ϴ���, next�� ��ü�ϴ��� 
		if (p->pre != NULL) {
			if (p->pre->subhead == p) {
				p->pre->subhead = p->subhead;
				p->subhead->pre = p->pre;
			}
			else {
				p->pre->next = p->subhead;
				p->subhead->pre = p->pre;
			}
		}
		else { // p->pre == NULL (p�� ceo)
			head = p->subhead;
		}
		delete p;
	}
	else {	// p->subhead==NULL
		if (p->pre != NULL) {	// p�� CEO�� xx 
			if (p->next != NULL) {
				if (p->pre->subhead == p) {
					p->pre->subhead = p->next;
					p->next->pre = p->pre;
				}
				else {
					p->pre->next = p->next;
					p->next->pre = p->pre;
				}
			}
			else {
				// p.next == NULL;
				if (p->pre->subhead == p) {
					p->pre->subhead = NULL;
				}
				else {
					p->pre->next = NULL;
				}
			}
		}
		delete p;
	}
	
}

void Tree::firesub(Member* p) {	// p�� prenode�� ������ ����� ��� 
	if (p->subhead == NULL) {
		if (p->next != NULL) {
			p->subhead = p->next;
		}
		if (p->pre->next != NULL) {
			p->next = p->pre->next;
			p->next->pre = p;
		}
		else {
			p->next = NULL;
		}
		
	}
	else {
		firesub(p->subhead);
		if (p->pre->next != NULL) {
			p->next = p->pre->next;
			p->next->pre = p;
		}
		else {
			p->next = NULL;
		}
	}
}

// status
Member* Tree::retrieve(Member* p, string& name) {
	Member* found;
	if (p->name == name) {
		return p;
	}
	else {
		if (p->subhead != NULL) {
			found= retrieve(p->subhead, name);
			if (found->name == name) {
				return found;
			}
			else {
				found = p;
			}
		}
		if (p->next != NULL) {
			found= retrieve(p->next, name);
			if (found->name == name) {
				return found;
			}
			else {
				found = p;
			}
		}
	}
}

bool Tree::isEmpty() {
	return(head == NULL);
}

bool Tree::isFull() {
	Member* item;
	string newname;
	item = new Member(newname, NULL);
	if (item == NULL) {
		return true;
	}
	else {
		delete item;
		return false;
	}
}

void Tree::clear() {

}

// output
void Tree::print() {
	cout << endl;
	printsub(head, 0);
	cout << endl;
}

void Tree::printsub(Member* p, int level) {
	for (int i = 0; i < level; i++) {
		cout << "+";
	}
	cout << p->name << endl;
	if (p->subhead != NULL)
		printsub(p->subhead, level + 1);
	if (p->next != NULL)
		printsub(p->next, level);
}

int main() {
	Tree organization;
	string input, newname;

	do {
		cin >> input;
		if (input == "Fire" || input == "fire") {
			cin >> newname;
			organization.fire(newname);
		}
		else if (input == "Print" || input == "print") {
			organization.print();
		}
		else if (input == "quit" || input == "Quit") {
			break;
		}
		else {	// �̸��� ���� ĥ ��� 
			if (organization.isEmpty()) {
				organization.hire(input);
			}
			else {
				string hire;
				cin >> hire >> newname;
				organization.hire(input, newname);
			}
		}
	} while (input != "quit" || input != "Quit");
}



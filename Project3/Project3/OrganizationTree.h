// 2019112587 김지현

#include <iostream>
using namespace std;

class Member {
private:
	string name;

	// Constructor 
	Member(string& name, Member* pre); // *next는 항상 null

	Member* subhead; // sublist
	Member* next; // same level
	Member* pre;  // pre cursor


	friend class Tree;
};

class Tree {
public:
	// constructor
	Tree(int ignored = 0);

	// destructor
	~Tree();

	// manipulation
	void hire(string& newname);
	void hire(string& name, string& newname);
	void fire(string& name);

	// status
	Member* retrieve(Member* p, string& name);
	bool isEmpty();
	bool isFull();
	void clear();

	// output
	void print();

private:
	void hiresub(Member* p, string& newname);
	void firesub(Member* p);
	void printsub(Member* p, int level);
	Member* head, * cursor;
	int level;	// 해당 계급만큼 +출력
};

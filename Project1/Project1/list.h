// 2019112587_������

#include <iostream>
#include <string>
#include <fstream>


using namespace std;

const int defMaxListSize = 10; 
// Default maximum list size


class datalist {

	string name;
	string phone;
	string birth;
	string month;

	string getmonth();
	friend class List;
};

class List
{
public:

	// ������
	List(int maxNumber = defMaxListSize);
	~List();

	// ���� �����
	void read(string file);
	void write(string file);

	// add, remove, search
	void insert(string _name, string _phone, string _birth);
	void remove(string name);
	void search(string searchmonth);
	                             
    // list ���  
	void showStructure();

	bool isFull();
	bool isEmpty();
	void clear();

	


private:
	int maxSize;
	int top;
	

	datalist* element;
};

// 2019112587_김지현

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

	// 생성자
	List(int maxNumber = defMaxListSize);
	~List();

	// 파일 입출력
	void read(string file);
	void write(string file);

	// add, remove, search
	void insert(string _name, string _phone, string _birth);
	void remove(string name);
	void search(string searchmonth);
	                             
    // list 출력  
	void showStructure();

	bool isFull();
	bool isEmpty();
	void clear();

	


private:
	int maxSize;
	int top;
	

	datalist* element;
};

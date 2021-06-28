// 2019112587 김지현

#include "stackarr.h"
using namespace std;

//--------------------------------------------------------------------

// Constructor
template< class DT >
Stack<DT>::Stack(int maxNumber)
	:maxSize(maxNumber),
	top(-1)
{
	element = new DT[maxSize];
}

// Destructor
template< class DT >
Stack<DT>::~Stack() {
	delete[] element;
}

// Stack manipulation operations
template< class DT >
void Stack<DT>::push(const DT& newElement) {
	if (full()) {
		cout << "Stack is full" << endl;
	}
	else {
		top++;	// element 마지막 원소의 index
		element[top] = newElement;
	}
}

template< class DT >
DT Stack<DT> ::pop() {
	if (empty()) {
		cout << "Stack is empty" << endl;
	}
	else {
		top--;
		return element[top + 1];
	}
}

template< class DT >
void Stack<DT>::clear() {
	top = -1;
}

// Stack status operations
template< class DT >
bool Stack<DT>::empty() const {
	if (top == -1) {
		return 1;
	}
	else return 0;
}

template< class DT >
bool Stack<DT>::full()const {
	if (top == maxSize - 1) {
		return 1;
	}
	else return 0;
}

// Output the stack structure -- used in testing/debugging
template< class DT >
void Stack<DT>::showStructure() const{
	int i, j;
	if (empty()) {
		cout << "Empty Stack" << endl;
	}
	else {
		for (i = 0; i <= top; i++) {
			cout << "| " << element[i] << " |";
		}
		for (j = 0; j < maxSize - i; j++) {
			cout << "| Empty |";
		}
		cout << endl;
	}
}


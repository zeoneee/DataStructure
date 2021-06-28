//--------------------------------------------------------------------
//
//                                                       listarr.cpp
//
//  SOLUTION: Array implementation of the List ADT
//
//--------------------------------------------------------------------

// 2019112587 김지현

#include "listarr.h"

using namespace std;

//--------------------------------------------------------------------

List::List(int maxNumber)

// Creates an empty list. Allocates enough memory for maxNumber
// data items (defaults to defMaxListSize).
	: maxSize(maxNumber),
	size(0),
	cursor(-1)
{
	// pre-lab
	dataItems = new DataType[maxSize];
}

//--------------------------------------------------------------------

List:: ~List()
// Frees the memory used by a list.

{
	// pre-lab
	delete[] dataItems;
	
}

//--------------------------------------------------------------------

void List::insert(const DataType& newDataItem)
throw (logic_error)

// Inserts newDataItem after the cursor. If the list is empty, then
// newDataItem is inserted as the first (and only) data items in the
// list. In either case, moves the cursor to newDataItem.

{
	// pre-lab
	if (isFull()) {
		cout << "List is Full" << endl;
	}else{
		size++;
		cursor = size - 1;
		dataItems[size - 1] = newDataItem;
		/*
			dataItems[size]=newDataItem;
			cursor = size;
			size ++; 
			이 순서가 맞음
		*/
	}
}

//--------------------------------------------------------------------

void List::remove() throw (logic_error)

// Removes the data items  marked by the cursor from a list. Moves the
// cursor to the next data item item in the list. Assumes that the
// first list data items "follows" the last list data item.
{
	// pre-lab	
	if (isEmpty()) {
		cout << "There is no Data" << endl;
	}
	else if (cursor != size - 1) {
		dataItems[cursor] = dataItems[size - 1];
		dataItems[size - 1] = NULL;	// 이거 할 필요가 없음
		size--;
	}
	else {
		dataItems[cursor] = NULL;
		size--;
		cursor--;
	}
	
}

//--------------------------------------------------------------------

void List::replace(const DataType& newDataItem)
throw (logic_error)

// Replaces the item marked by the cursor with newDataItem and
// leaves the cursor at newDataItem.
{
	// Requires that the list is not empty
	// pre-lab
	if (isEmpty()||cursor>=size) {
		cout << "There is no Data" << endl;
	}
	else {
		dataItems[cursor] = newDataItem;
	}
	

}
//--------------------------------------------------------------------

void List::clear()
// Removes all the data items from a list.
{
	// pre-lab
	for (int i = 0; i < size; i++) {
		dataItems[i] = NULL;	// 이거를 할 필요가 없음
	}
	size = 0; cursor = -1; 
	
}

//--------------------------------------------------------------------

bool List::isEmpty() const
// Returns 1 if a list is empty. Otherwise, returns 0.
{
	// pre-lab
	if (size == 0) {
		return 1;
	}
	else return 0;
}

//--------------------------------------------------------------------

bool List::isFull() const
// Returns 1 if a list is full. Otherwise, returns 0.
{
	// pre-lab
	if (size == maxSize) {
		return 1;
	}
	else return 0;
}

//--------------------------------------------------------------------

bool List::gotoBeginning() throw (logic_error)
// Moves the cursor to the beginning of the list.
{
	// pre-lab
	if (!isEmpty()) {
		cursor = 0;
		return 1;
	}
	else return 0;
}

//--------------------------------------------------------------------

bool List::gotoEnd() throw (logic_error)

// Moves the cursor to the end of the list.

{
	// pre-lab
	if (!isEmpty()) {
		cursor = size - 1;
		return 1;
	}
	else return 0;
	

}

//--------------------------------------------------------------------

bool List::gotoNext() throw (logic_error)

// If the cursor is not at the end of a list, then moves the
// cursor to the next item in the list and returns true. Otherwise,
// returns false.
{
	// pre-lab
	if (isEmpty() || isFull()) {	// isFull() 이거 아니고 그냥 커서가 마지막일때
		return 0;
	}
	else {
		cursor++;
		return 1;
	}
	
}

//--------------------------------------------------------------------

bool List::gotoPrior() throw (logic_error)

// If the cursor is not at the beginning of a list, then moves the
// cursor to the preceeding item in the list and returns true.
// Otherwise, returns false.

{
	// pre-lab
	if (isEmpty()) { // + cursor==0이라면 
		return 0;
	}else{
		cursor--;
		return 1;
	}
	
}

//--------------------------------------------------------------------

DataType List::getCursor() const throw (logic_error)
// Returns the item marked by the cursor.

{
	// pre-lab
	if (cursor >=size) {	// isEmpty()
		cout << "There is no data" << endl;
	}
	else {
		return dataItems[cursor];
	}
}

//--------------------------------------------------------------------

void List::showStructure() const
// Outputs the data items in a list. If the list is empty, outputs
// "Empty list". This operation is intended for testing/debugging
// purposes only.

{
	// pre-lab
	if (size==0) {
		cout << "Empty list" << endl;
	}
	else {
		cout << "size = " << size << "   cursor = " << cursor << endl;
		for (int i = 0; i < maxSize; i++) {
			cout << "[ " << i << " ]   ";
		}
		cout << endl;
		for (int i = 0; i < size; i++) {	// size까지 출력, maxSize까지 ""출력
			cout << "  " << dataItems[i] << "     ";
		}
		cout << endl;
	}
	

}

//--------------------------------------------------------------------

//in-lab
void List::countBases(List& dnaSequence, int& aCount, int& cCount, int& tCount, int& gCount) {
	aCount = 0; cCount = 0; tCount = 0; gCount = 0;
	for (int i = 0; i < size; i++) {
		switch (dataItems[i])
		{
		case 'A': case 'a' :
			aCount++;
			break;
		case 'C': case 'c':
			cCount++;
			break;
		case'T': case 't':
			tCount++;
			break;
		case 'G': case 'g' :
			gCount++;
			break;
		default:
			break;
		}
	}
}
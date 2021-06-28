// 2019112587 김지현

#include <iostream>
#include <assert.h>
#include "listdbl.h"

using namespace std;

template < class DT >
ListNode<DT>::ListNode(const DT& data, ListNode* priorPtr, ListNode* nextPtr)
{
	dataItem = data;
	prior = priorPtr;
	next = nextPtr;
}

// Constructor
template < class DT >
List<DT>::List(int ignored)
{
	head = NULL;
	cursor = NULL;
}

// Destructor
template < class DT >
List<DT>::~List()
{
	clear();
}


//------------ List manipulation operations ------------------

// Insert after cursor
template < class DT >
void List<DT>::insert(const DT& newDataItem)
{
	if (isFull()) {
		cout << "Full List" << endl;
	}
	else {
		if (head == NULL) {
			head = new ListNode<DT>(newDataItem, NULL, NULL);
			cursor = head;
		}
		else {
			ListNode<DT>* newNode = new ListNode<DT>(newDataItem, cursor, cursor->next);
			if (cursor->next == NULL) {
				cursor->next = newNode;
				cursor = newNode;
			}
			else {
				cursor->next->prior = newNode;
				cursor->next = newNode;
				cursor = newNode;
			}
			
		}
	}
}

// Remove data item
template < class DT >
void List<DT>::remove()
{
	if (isEmpty()) {
		cout << "Empty List" << endl;
	}
	else {
		ListNode<DT>* tempPtr;
		tempPtr = cursor;
		if (cursor->prior == NULL) {
			if (cursor->next == NULL) {
				cursor = NULL;
				head = NULL;
			}
			else {
				head = cursor->next;
				cursor->next->prior = NULL;
				cursor = cursor->next;
			}
		}
		else {
			cursor->prior->next = cursor->next;
			if (cursor->next == NULL) {
				cursor = head;
			}
			else {
				cursor->next->prior = cursor->prior;
				cursor = cursor->next;
			}
		}
		delete tempPtr;
	}
}

// Replace data item
template < class DT >
void List<DT>::replace(const DT& newElement)
{
	if (isEmpty()) {
		cout << "Empty List" << endl;
	}
	else {
		cursor->dataItem = newElement;
	}
}

// Clear list
template < class DT >
void List<DT>::clear()
{
	if (isEmpty()) {
		cout << "Empty List" << endl;
	}
	else {
		while (!(head == NULL)) {
			ListNode<DT>* tempPtr;
			tempPtr = head;
			head = head->next;
			delete tempPtr;
		}
		cursor = NULL; // 확인
	}
}


//------------ List status operations ------------------

// List is empty
template < class DT >
bool List<DT>::isEmpty() const
{
	return (head == NULL);
}

// List is full
template < class DT >
bool List<DT>::isFull() const
{
	DT n;
	ListNode<DT>* location;
	location = new ListNode<DT>(n, NULL, NULL);
	if (location == NULL) {
		return true;
	}
	else {
		delete location;
		return false;
	}
}


//------------ List manipulation operations ------------------

// Go to beginning
template < class DT >
void List<DT>::gotoBeginning()
{
	if (isEmpty()) {
		cout << "Empty List" << endl;
	}
	else {
		cursor = head;
	}
}

// Go to end
template < class DT >
void List<DT>::gotoEnd()
{
	if (isEmpty()) {
		cout << "Empty List" << endl;
	}
	else {
		while (!(cursor->next == NULL)) {
			cursor = cursor->next;
		}
	}
}

// Go to next data item
template < class DT >
bool List<DT>::gotoNext()
{
	if (isEmpty()) {
		return false;
	}
	else if (cursor->next == NULL) {
		return false;
	}
	else {
		cursor = cursor->next;
		return true;
	}
}

// Go to prior data item
template < class DT >
bool List<DT>::gotoPrior(){
	if (isEmpty()) {
		return false;
	}
	else if (cursor->prior == NULL) {
		return false;
	}
	else {
		cursor = cursor->prior;
	}
}


template < class DT >
DT List<DT>::getCursor() const
{
	if (isEmpty()) {
		cout << "Empty List" << endl;
	}
	else {
		return cursor->dataItem;
	}
}


//-----------------------------------------------------------

template < class DT >
void List<DT>::showStructure() const
{
	ListNode<DT>* p;

	if (head == NULL)
		cout << "Empty list" << endl;
	else
	{
		p = head;	// 이런 location ptr을 하나 만듬
		do
		{
			if (p == cursor)
				cout << "[" << p->dataItem << "] ";
			else
				cout << p->dataItem << " ";
			p = p->next;
		} while (p != NULL);
		cout << endl;
	}
}


//-----------------------------------------------------------

// In-lab opertions
template < class DT >
void List<DT>::reverse()
{
	if (isEmpty()) {
		cout << "Empty List" << endl;
	}
	else {
		while (true) {
			ListNode<DT>* nextNode, * priorNode;
			nextNode = head->next;
			priorNode = head->prior;
			head->next = priorNode;
			head->prior = nextNode;
			if (nextNode == NULL) {
				break;
			}
			else {
				head = nextNode;
			}
		}
	}
}

//-----------------------------------------------------------


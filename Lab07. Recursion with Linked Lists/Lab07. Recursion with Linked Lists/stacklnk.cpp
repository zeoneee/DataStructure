// 2019112587 ±èÁöÇö

#include <iostream>
#include "stacklnk.h"

template < class DT >
StackNode<DT>::StackNode(const DT& nodeData, StackNode* nextPtr) {
	data = nodeData;
	next = nextPtr;
}

template < class DT >
Stack<DT>::Stack(int ignored) {
	top == NULL;
}

template < class DT >
Stack<DT>::~Stack() {
	clear();
}

template < class DT >
void Stack<DT>::push(const DT& newDataItem) {
	StackNode<DT>* newnode = new StackNode<DT>(newDataItem, top);
	top = newnode;
}

template < class DT >
DT Stack<DT>::pop() {
	DT data = top->data;
	StackNode<DT>* tempPtr;
	tempPtr = top;
	top = top->next;
	delete tempPtr;
	return data;
}

template < class DT >
void Stack<DT>::clear() {
	while (top != NULL) {
		StackNode<DT>* tempPtr;
		tempPtr = top;
		top = top->next;
		delete tempPtr;
	}
}


template < class DT >
bool Stack<DT>::isEmpty() const {
	return (top == NULL);
}


template < class DT >
bool Stack<DT>::isFull() const {
	DT data;
	StackNode<DT>* newnode;
	newnode = StackNode<DT>(data, NULL);
	if (newnode == NULL) {
		return true;
	}
	else {
		delete newnode;
		return false;
	}
}
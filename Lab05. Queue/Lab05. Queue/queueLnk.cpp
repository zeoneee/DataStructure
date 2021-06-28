// 2019112587_±èÁöÇö

#include "queueLnk.h"
#include <iostream>
#include <string>

using namespace std;

template < class DT >
QueueNode<DT>::QueueNode(const DT& nodeData, QueueNode* nextPtr) {
	dataItem = nodeData;
	next = nextPtr;
}

template < class DT >
Queue<DT>::Queue(int ignored) {
	front = NULL;
	rear = NULL;
}

template < class DT >
Queue<DT>::~Queue() {
	clear();
}

template < class DT >
void Queue<DT>::enqueue(const DT& newData) {
	if (isFull()) {
		cout << "Queue is Full, you can't Enqueue!" << endl;
	}
	else {
		QueueNode<DT>* newNode;
		newNode = new QueueNode<DT>(newData,NULL);
		if (rear == NULL) {
			front = newNode;
		}
		else {
			rear->next = newNode;
		}
		rear = newNode;
	}
}

template < class DT >
DT Queue<DT>::dequeue() {

	DT data = front->dataItem;
	QueueNode<DT>* tempPtr;
	tempPtr = front;
	front = front->next;
	if (front == NULL) {
		rear = NULL;
	}
	delete tempPtr;
	return data;
	
}

template < class DT >
void Queue<DT>::clear() {
	while (!(front == NULL)) {
		QueueNode<DT>* tempPtr;
		tempPtr = front;
		front = front->next;
		delete tempPtr;
	}
	rear = NULL;
}

template < class DT >
bool Queue<DT>::isEmpty() const {
	return(rear == NULL);
}

template < class DT >
bool Queue<DT>::isFull() const {
	DT data;
	QueueNode<DT>* newNode;
	newNode = new QueueNode<DT>(data,NULL);
	if (newNode == NULL) {
		return true;
	}
	else {
		delete newNode;
		return false;
	}
}

template < class DT >
void Queue<DT>::showStructure() const {
	if (isEmpty()) {
		cout << "Empty Queue" << endl;
	}
	else {
		QueueNode<DT>* cursor;
		cursor = front;
		while (!(cursor == NULL)) {
			cout << cursor->dataItem << "\t";
			cursor = cursor->next;
		}
	}
}

template < class DT >
void Queue<DT>::putFront(const DT& newDataItem) {
	QueueNode<DT>* newNode;
	newNode = new QueueNode<DT>(newDataItem, front);
	front = newNode;
	if (rear==NULL) {
		rear = front;
	}
}

template < class DT >
DT Queue<DT>::getRear() {
	DT data = rear->dataItem;
	if (front == rear) {
		front == NULL;
		rear == NULL;
	}
	else {
		QueueNode<DT>* tempPtr;
		tempPtr = rear;

		QueueNode<DT>* priorPtr;
		priorPtr = front;
		while (!(priorPtr->next == rear)) {
			priorPtr = priorPtr->next;
		}
		priorPtr->next = NULL;
		rear = priorPtr;
		delete tempPtr;
	}
	return data;
}
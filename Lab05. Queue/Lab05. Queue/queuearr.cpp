// 2019112587_김지현

#include "queuearr.h"
#include <iostream>
#include <string>

using namespace std;

template < class DT >
Queue<DT>::Queue(int maxNumber) 
{
	maxSize= maxNumber+1;
	front = maxSize - 1;
	rear = maxSize - 1;
	element = new DT[maxSize];
}

template < class DT >
Queue<DT>::~Queue() {
	delete[] element;
}

template < class DT >
void Queue<DT>::enqueue(const DT& newData) {	// rear값이 +1, 
		// rear은 원래 마지막원소를 가리키므로 elemente[rear]에 추가한 후, rear+1해주면 됨
	if (isFull()) {
		cout << "Queue is Full, you can't Enqueue!" << endl;
	}
	else {
		rear = (rear + 1) % maxSize;
		element[rear] = newData;
	}
}

template < class DT >
DT Queue<DT>::dequeue() {	// front값이 +1
		front = (front + 1) % maxSize;
		DT data = element[front];
		return data;
}

template < class DT >
void Queue<DT>::clear() {
	front = maxSize - 1;
	rear = maxSize - 1;
}

template < class DT >
bool Queue<DT>::isEmpty() const{
	return (rear==front);
}

template < class DT >
bool Queue<DT>::isFull() const {
	return ((rear + 1) % maxSize == front);
}

template < class DT >
void Queue<DT>::showStructure() const {
	if (isEmpty()) {
		cout << "Empty queue" << endl;
	}
	else {
		for (int i = 0; i < maxSize-1 ; i++) {
			cout << i << "\t";
		}cout << endl;
		if(front<rear){
			if (rear == maxSize - 1) {
				cout << element[rear] << "\t";
				for (int i = 0; i < front; i++) {
					cout << "\t";
				}for (int i = front + 1; i < rear; i++) {
					cout << element[i] << "\t";
				}for (int i = rear + 1; i < maxSize - 1; i++) {
					cout << "\t";
				}
			}
			else {
				for (int i = 0; i <= front; i++) {
					cout << "\t";
				}for (int i = front + 1; i <= rear; i++) {
					cout << element[i] << "\t";
				}for (int i = rear + 1; i < maxSize - 1; i++) {
					cout << "\t";
				}
			}
				
		}	// front < rear
		else {
			if (front == maxSize - 1) {
				for (int i = 0; i <= rear; i++) {
					cout << element[i] << "\t";
				}
				for (int i = rear + 1; i < front; i++) {
					cout << "\t";
				}
			}
			else {
				cout << element[maxSize - 1] << "\t";
				for (int i = 0; i <= rear; i++) {
					cout << element[i] << "\t";
				}for (int i = rear + 1; i < front; i++) {
					cout << "\t";
				}for (int i = front + 1; i < maxSize-1; i++) {
					cout << element[i] << "\t";
				}
			}
			
		}
	}
	
}

template < class DT >
void Queue<DT>::putFront(const DT& newDataItem) {
	element[front] = newDataItem;
	if (front == 0) {
		front = maxSize - 1;
	}
	else {
		front = front - 1;
	}
}

template < class DT >
DT Queue<DT>::getRear() {
	DT data = element[rear];
	if (rear == 0) {
		rear = maxSize - 1;
	}
	else {
		rear = rear - 1;
	}
	return data;
}


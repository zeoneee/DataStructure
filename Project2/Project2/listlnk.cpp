
// 2019112587_김지현

#include "listlnk.h"
#include <iostream>


template<class DT>
ListNode<DT>::ListNode(const DT& nodeData, ListNode* nextPtr)
{
    dataItem = nodeData;
    next = nextPtr;
}



template<class DT>
List<DT>::List(int ignored)
{
    cursor = NULL;
    head = NULL;
}


//------------------------------------------------

template<class DT>
List<DT>::~List()
{
    clear();
}

//------------------------------------------------


template<class DT>
void List<DT>::insert(const DT& newData)
{
    if (isFull()) {
        cout << "List if FUll" << endl;
    }
    else {
        if (head == NULL) {
            head = new ListNode<DT>(newData, NULL);
            cursor = head;
        }
        else {
            ListNode<DT>* tempPtr;
            tempPtr = cursor->next;
            cursor->next = new ListNode<DT>(newData, tempPtr);
            cursor = cursor->next;
        }
    }
}

//------------------------------------------------


template<class DT>
void List<DT>::remove()

{
    if (isEmpty()) {
        cout << "List is Empty" << endl;
    }
    else {
        // cursor가 head인 경우 고려 
        if (cursor == head) {
            if (head->next == NULL) {
                head = NULL, cursor = NULL;
            }
            else {
                ListNode<DT>* tempPtr;
                tempPtr = cursor;
                head = head->next;
                cursor = cursor->next;
                delete tempPtr;

            }

        }
        else {
            ListNode<DT>* priorPtr;
            priorPtr = head;
            while (!(priorPtr->next == cursor)) {
                priorPtr = priorPtr->next;
            }
            ListNode<DT>* tempPtr;
            tempPtr = cursor;
            priorPtr->next = cursor->next;
            if (cursor->next == NULL) {
                cursor = head;
            }
            else {
                cursor = cursor->next;
            }
            delete tempPtr;
        }
    }
}


//------------------------------------------------


template<class DT>
void List<DT>::replace(const DT& newData)
{
    if (isEmpty()) {
        cout << "List is Empty" << endl;
    }
    else {
        cursor->dataItem = newData;
    }
}

//------------------------------------------------


template<class DT>
void List<DT>::clear()
{
    // 전부삭제
    while (!(head == NULL)) {
        ListNode<DT>* tempPtr;
        tempPtr = head;
        head = head->next;
        delete tempPtr;
    }
}

//------------------------------------------------


template<class DT>
bool List<DT>::isEmpty() const
{
    return(head == NULL);
}

//------------------------------------------------


template<class DT>
bool List<DT>::isFull() const
{
    DT n;
    ListNode<DT>* location;
    location = new ListNode<DT>(n, NULL);
    if (location == NULL) {
        return true;
    }
    else {
        delete location;
        return false;
    }
}

//------------------------------------------------


template<class DT>
void List<DT>::gotoBeginning()
{
        cursor = head;
}

//------------------------------------------------


template<class DT>
void List<DT>::gotoEnd()
{

        while (!(cursor->next == NULL)) {
            cursor = cursor->next;
        }
}

//------------------------------------------------


template<class DT>
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

//------------------------------------------------


template<class DT>
bool List<DT>::gotoPrior()
{
    if (isEmpty()) {
        return false;
    }
    else {
        if (cursor == head) {
            return false;
        }
        else {
            ListNode<DT>* priorPtr;
            priorPtr = head;
            while (!(priorPtr->next == cursor)) {
                priorPtr = priorPtr->next;
            }
            cursor = priorPtr;
            return true;
        }
    }
}

//------------------------------------------------


template<class DT>
DT& List<DT>::getCursor() const
{
    if (isEmpty()) {
        cout << "List is Empty" << endl;
    }
    else {
        return(cursor->dataItem);
    }
}

template<class DT>
void List<DT>::showStructure() const
{
    if (isEmpty()) {
        cout << "List is Empty" << endl;
    }
    else {
        ListNode<DT>* printPtr;
        printPtr = head;
        while (!(printPtr == NULL)) {
            cout << printPtr->dataItem << "  ";
            printPtr = printPtr->next;
        }cout << endl;
        printPtr = head;
        while (!(printPtr == NULL)) {
            if (printPtr != cursor) {
                cout << "   ";
                printPtr = printPtr->next;
            }
            else if (printPtr == cursor) {
                cout << "^";
                break;
            }
        }
    }

}


//------------------------------------------------

//use in-lab
template<class DT>
void List<DT>::insertBefore(const DT& newElement) {
    if (cursor == head) {
        ListNode<DT>* node = new ListNode<DT>(newElement, head);
        head = node; cursor = node;
    }
    else {
        gotoPrior();
        insert(newElement);
    }
}


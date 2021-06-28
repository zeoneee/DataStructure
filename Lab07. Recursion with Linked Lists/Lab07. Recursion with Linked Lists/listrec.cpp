//--------------------------------------------------------------------
//
//  Laboratory 10                                         listrec.cs
//
//  (Shell) Partial linked list implementation of the List ADT with
//  additional recursive linked list functions
//
//--------------------------------------------------------------------

// 2019112587 김지현

#include <iostream>
#include "stacklnk.cpp"
#include "listrec.h"

using namespace std;

//--------------------------------------------------------------------
//
// Insert your singly linked list implementations (from Laboratory 7)
// of the following functions:
//
//   - The ListNode class constructor
//
//   - The List class constructor, destructor, insert(), clear(), and
//     showstructure() functions. You may also need to add empty()
//     full(), and others.
//
//--------------------------------------------------------------------

template<class DT>
ListNode<DT>::ListNode(const DT& nodeData, ListNode* nextPtr)
{
    data = nodeData;
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

template<class DT>
void List<DT>::showStructure() const
{
    if (isEmpty()) {
        cout << "List is Empty" << endl;
    }
    else {
        ListNode<DT>* p;
        p = head;
        while (!(p== NULL)) {
            if (p == head) {
                cout << p->data;
            }
            else {
                cout << "|" << p->data;
            }
            p = p->next;
        }cout << endl;
    }

}



//--------------------------------------------------------------------
//
// Recursively implemented linked list functions used in the Prelab
// Exercise
//
//--------------------------------------------------------------------

template < class DT >
void List<DT>::write() const

// Outputs the data in a list from beginning to end. Assumes that
// objects of type DT can be output to the cout stream.

{
    cout << "List : ";
    writeSub(head);
    cout << endl;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class DT >
void List<DT>::writeSub(ListNode<DT>* p) const

// Recursive partner of the write() function. Processes the sublist
// that begins with the node pointed to by p.

{
    if (p != 0)
    {
        cout << p->data;      // Output data
        writeSub(p->next);    // Continue with next node
    }
}

//--------------------------------------------------------------------

template < class DT >
void List<DT>::insertEnd(const DT& newDataItem)

// Inserts newDataItem at the end of a list. Moves the cursor to
// newDataItem.

{
    // list의 끝부분에 삽입
    insertEndSub(head, newDataItem);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class DT >
void List<DT>::insertEndSub(ListNode<DT>*& p,
    const DT& newDataItem)

    // Recursive partner of the insertEnd() function. Processes the
    // sublist that begins with the node pointed to by p.

{
    if (p != 0)
        insertEndSub(p->next, newDataItem);    // Continue searching for
    else                                     // end of list
    {
        p = new ListNode<DT>(newDataItem, 0);  // Insert new node
        cursor = p;                           // Move cursor
    }
}

//--------------------------------------------------------------------

template < class DT >
void List<DT>::writeMirror() const

// Outputs the data in a list from beginning to end and back
// again. Assumes that objects of type DT can be output to the cout
// stream.

{
    // 대칭으로 출력
    cout << "Mirror : ";
    writeMirrorSub(head);
    cout << endl;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class DT >
void List<DT>::writeMirrorSub(ListNode<DT>* p) const

// Recursive partner of the writeMirror() function. Processes the
// sublist that begins with the node pointed to by p.

{
    if (p != 0)
    {
        cout << p->data;           // Output data (forward)
        writeMirrorSub(p->next);   // Continue with next node
        cout << p->data;           // Output data (backward)
    }
}

//--------------------------------------------------------------------

template < class DT >
void List<DT>::reverse()

// Reverses the order of the data items in a list.

{
    // 반대로 출력(순서 바꾸는거)
    reverseSub(0, head);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class DT >
void List<DT>::reverseSub(ListNode<DT>* p, ListNode<DT>* nextP)

// Recursive partner of the reverse() function. Processes the sublist
// that begins with the node pointed to by nextP.

{
    if (nextP != 0)
    {
        reverseSub(nextP, nextP->next);   // Continue with next node
        nextP->next = p;                 // Reverse link
    }
    else
        head = p;                        // Move head to end of list
}

//--------------------------------------------------------------------

template < class DT >
void List<DT>::deleteEnd()

// Deletes the data at the end of a list. Moves the cursor to the
// beginning of the list.

{
    deleteEndSub(head);
    cursor = head;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class DT >
void List<DT>::deleteEndSub(ListNode<DT>*& p)

// Recursive partner of the deleteEnd() function. Processes the
// sublist that begins with the node pointed to by p.

{
    if (p->next != 0)
        deleteEndSub(p->next);   // Continue looking for the last node
    else
    {
        delete p;                // Delete node
        p = 0;                   // Set p (link or head) to null
    }
}

//--------------------------------------------------------------------

template < class DT >
int List<DT>::getLength() const

// Returns the number of data items in a list.

{
    return getLengthSub(head);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class DT >
int List<DT>::getLengthSub(ListNode<DT>* p) const

// Recursive partner of the length() function. Processes the sublist
// that begins with the node pointed to by p.

{
    int result;   // Result returned

    if (p == 0)
        result = 0;                            // End of list reached
    else
        result = (getLengthSub(p->next) + 1);   // Number of nodes after
                                               // this one + 1
    return result;
}

template < class DT >
void List<DT>::iterReverse() {
    ListNode<DT> *priornode, * nextnode;
    priornode = NULL; nextnode = head->next;
    while (nextnode != NULL) {
        head->next = priornode;
        priornode = head;
        head = nextnode;
        nextnode = head->next;
    }
    head->next = priornode;
}

template < class DT >
void List<DT>::stackWriteMirror() const{
    ListNode<DT>* p;
    p = head;
    Stack<DT>* stack = new Stack<DT>();
    while (p != NULL) {
        cout << p->data;
        stack->push(p->data);
        p = p->next;
    }
    while (!(stack->isEmpty())){
        cout << stack->pop();
    }
    cout << endl;
}
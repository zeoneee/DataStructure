//--------------------------------------------------------------------
//
//  Laboratory 13                                             heap.cpp
//
//  Actual implementation of class in the Heap ADT
//--------------------------------------------------------------------

// 2019112587 김지현

#include "heap.h"
#include <iostream>
using namespace std;
//--------------------------------------------------------------------


template<class DT>
Heap<DT>::Heap(int maxNumber) throw(bad_alloc)
{
    maxSize = maxNumber;
    size = 0;
    dataItems = new DT[maxSize];
}

template < class DT >
Heap<DT>::~Heap()
{
    delete[] dataItems;
}

//--------------------------------------------------------------------

template < class DT >
void Heap<DT>::insert(const DT& newElement)
{
    if (isFull()) {
        cout << "Full List" << endl;
    }
    else {
            dataItems[size] = newElement;
            int i = size;
            while (!(i == 0 || dataItems[i].pty() < dataItems[(i - 1) / 2].pty())) {
                // size가 0 이거나, 내가 부모노드보다 작으면 swqp x
                swap(dataItems[i], dataItems[(i - 1) /  2]);
                // 내가 부모노드보다 크면 swqp
                i = (i - 1) / 2;
                // 부모노드로 가서 다시 ㄱㄱ 
                // 밑에서부터 올라가는거 
            }
            size++;
    }
}

template < class DT >
DT Heap<DT>::removeMax()
{
    DT data = dataItems[0];
    dataItems[0] = dataItems[size-1];   // 밑에 있던 애를 위로 올려서 쭉 다시 내림 
    int i = 0;
    int max;
    while (!(2 * i + 1 > size)) {   // 자식노드가 사이즈보다 크면 내가 마지막이라는 것
        if (2 * i + 1 == size) {
            max = 2 * i + 1;
        }
        else { // 자식 두개
            if (dataItems[2 * i + 1].pty() < dataItems[2 * i + 2].pty())
                max = 2 * i + 2;
            else
                max = 2 * i + 1;
        }
        if (dataItems[i].pty() < dataItems[max].pty())
            swap(dataItems[i], dataItems[max]);
        else
            break;
    }
    size--;
    return data;    // 삭제되는 데이터 
}


template < class DT >
void Heap<DT>::clear()
{
    size = 0;
}

//--------------------------------------------------------------------

template < class DT >
bool Heap<DT>::isEmpty() const
{
    return (size == 0);
}

template < class DT >
bool Heap<DT>::isFull() const
{
    return (size == maxSize);
}

//--------------------------------------------------------------------

template < class HD >
void Heap<HD>::showStructure() const

// Outputs the priorities of the data in a heap in both array
// and tree form. If the heap is empty, outputs "Empty heap". This
// operation is intended for testing/debugging purposes only.

{
    int j;   // Loop counter

    cout << endl;
    if (size == 0)
        cout << "Empty heap" << endl;
    else
    {
        cout << "size = " << size << endl;       // Output array form
        for (j = 0; j < maxSize; j++)
            cout << j << "\t";
        cout << endl;
        for (j = 0; j < size; j++)
            cout << dataItems[j].pty() << "\t";
        cout << endl << endl;
        showSubtree(0, 0);                        // Output tree form
    }
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class DT >
void Heap<DT>::showSubtree(int index, int level) const

// Recursive partner of the showStructure() function. Outputs the
// subtree (subheap) whose root is stored in dataItems[index]. Argument
// level is the level of this dataItems within the tree.

{
    int j;   // Loop counter

    if (index < size)
    {
        showSubtree(2 * index + 2, level + 1);        // Output right subtree
        for (j = 0; j < level; j++)        // Tab over to level
            cout << "\t";
        cout << " " << dataItems[index].pty();   // Output dataItems's pty
        if (2 * index + 2 < size)                // Output "connector"
            cout << "<";
        else if (2 * index + 1 < size)
            cout << "\\";
        cout << endl;
        showSubtree(2 * index + 1, level + 1);        // Output left subtree
    }
}
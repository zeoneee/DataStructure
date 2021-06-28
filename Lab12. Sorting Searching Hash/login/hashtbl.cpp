#include <iostream>
#include "hashtbl.h"

template < class DT, class KF >
HashTbl<DT, KF>::HashTbl(int initTableSize) :tableSize(initTableSize) {
    dataTable = new List<DT>[tableSize];
}

template < class DT, class KF >
HashTbl<DT, KF>::~HashTbl() {
    delete[] dataTable;
}

template < class DT, class KF >
void HashTbl<DT, KF>::insert(const DT& newDataItem) throw (bad_alloc) {
    // key값을 구해 해시테이블에 삽입, 데이터가 있으면 노드간 연결
    int key = newDataItem.hash(newDataItem.getKey()) % tableSize;
    dataTable[key].insert(newDataItem);
}

template < class DT, class KF >
bool HashTbl<DT, KF>::remove(KF searchKey) {
    // key값에 따라 해시테이블에 접근, 연결된 노드를 탐색해 연결을 끊음
    DT temp;
    int index = temp.hash(searchKey) % tableSize;
    if (dataTable[index].isEmpty()) {
        return false;
    }
    else {
        dataTable[index].gotoBeginning();
        do {
            if (dataTable[index].getCursor().getKey() == searchKey) {
                dataTable[index].remove();
                return true;
            }
        } while (dataTable[index].gotoNext());
        return false;
    }
}

template < class DT, class KF >
bool HashTbl<DT, KF>::retrieve(KF searchKey, DT& dataItem) {
    DT temp;
    int index = temp.hash(searchKey) % tableSize;
    if (dataTable[index].isEmpty()) {
        return false;
    }
    else {
        dataTable[index].gotoBeginning();
        do {
            if (dataTable[index].getCursor().getKey() == searchKey) {
                dataItem.setKey(dataTable[index].getCursor().getKey());
                dataItem.password = dataTable[index].getCursor().password;
                return true;
            }
        } while (dataTable[index].gotoNext());
        return false;
    }
}

template < class DT, class KF >
void HashTbl<DT, KF>::clear() {
    for (int i = 0; i < tableSize; i++) {
        dataTable[i].clear();
    }
}

template < class DT, class KF >
bool HashTbl<DT, KF>::isEmpty() const {
    for (int i = 0; i < tableSize; i++) {
        if (dataTable[i].isEmpty() == false) {
            return false;
        }
    }
    return true;
}

template < class DT, class KF >
bool HashTbl<DT, KF>::isFull() const {
    for (int i = 0; i < tableSize; i++) {
        if (dataTable[i].isFull() == false) {
            return false;
        }
    }
    return true;
}

template < class DT, class KF >
void HashTbl<DT, KF>::showStructure() const
{
    for (int i = 0; i < tableSize; i++)
    {
        cout << i << ": ";
        if (dataTable[i].isEmpty())
            cout << "_";
        else
        {
            dataTable[i].gotoBeginning();
            do {
                cout << dataTable[i].getCursor().getKey() << " ";
            } while (dataTable[i].gotoNext());
        }
        cout << endl << endl;
    }
}

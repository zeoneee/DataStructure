//--------------------------------------------------------------------
//
//  Laboratory 11, In-lab Exercise 1                     database.cs
//
//  (Shell) Indexed accounts database program
//
//--------------------------------------------------------------------

// Builds a binary search tree index for the account records in the
// text file accounts.dat.

// 2019112587 ������

#include <iostream>
#include <fstream>
#include "bstree.cpp"

using namespace std;

//--------------------------------------------------------------------
//
// Declarations specifying the accounts database
//

const int nameLength = 11;   // Maximum number of characters in
                                  //   a name
const long bytesPerRecord = 38;   // Number of bytes used to store
                                  //   each record in the accounts
                                  //   database file

struct AccountRecord
{
    int acctID;                   // Account identifier
    char firstName[nameLength],   // Name of account holder
        lastName[nameLength];
    double balance;               // Account balance
};

//--------------------------------------------------------------------
//
// declaration specifying the database index
//

struct IndexEntry
{
    int acctID;              // (Key) Account identifier
    long recNum;             // Record number

    void setKey(int newkey) {
        acctID = newkey;
    }

    int key() const
    {
        return acctID;
    }   // Return key field
};


//--------------------------------------------------------------------

void main()
{
    ifstream acctFile("accounts.dat");   // Accounts database file
    AccountRecord acctRec;                // Account record
    BSTree<IndexEntry, int> index;         // Database index
    IndexEntry entry;                     // Index entry
    int searchID ;                         // User input account ID
    long recNum;                          // Record number

    // iterate through the database records. for each record, read the
    // account id and add the (account id, record number) pair to the
    // index.

    // file���� id�а� 
    recNum = 0;
    acctFile >> acctRec.acctID; // ������ �ߺ��ν�
    while (acctFile.good()) {
        acctFile >> acctRec.firstName 
            >> acctRec.lastName >> acctRec.balance;
        entry.setKey(acctRec.acctID);
        entry.recNum = recNum++;
        index.insert(entry);
        acctFile >> acctRec.acctID;
    }
    
    // output the account ids in ascending order.
    index.writeKeys();

    // clear the status flags for the database file.
    acctFile.clear();

    // read an account id from the keyboard and output the
    // corresponding record.
     // ���� �о ���

    while (true) {
        acctFile.close();
        acctFile.open("accounts.dat");
        cout << endl << endl << "Enter account ID: ";
        cin >> searchID;
        if (index.retrieve(searchID, entry)) {
            acctFile.seekg(entry.recNum * (bytesPerRecord-1));

            acctFile >> acctRec.acctID >> acctRec.firstName
                >> acctRec.lastName >> acctRec.balance;

            cout << entry.recNum << ": " << acctRec.acctID << " " <<
                acctRec.firstName << " " << acctRec.lastName << " " << acctRec.balance;
        }
        else {
            cout << "wrong id" << endl;
        }
    }
}

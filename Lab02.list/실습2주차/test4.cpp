//--------------------------------------------------------------------
//
//				                                          test4.cpp
//
//  Test program for the operations in the List ADT
//
//--------------------------------------------------------------------

// 2019112587 ������

#include <iostream>
#include "listarr.h"
using namespace std;

void main()
{
	List testList(8);		  // Test list
	char testElement;         // List element
	int n;                    // Position within list
	char cmd;                 // Input command

	int aCount, cCount, tCount, gCount;

	do
	{
		cout << endl << "Commands:" << endl;
		cout << "  +x  : Insert x after the cursor" << endl;
		cout << "  -   : Remove the element marked by the cursor" << endl;
		cout << "  =x  : Replace the element marked by the cursor with x"
			<< endl;
		cout << "  @   : Display the element marked by the cursor" << endl;
		cout << "  <   : Go to the beginning of the list" << endl;
		cout << "  >   : Go to the end of the list" << endl;
		cout << "  N   : Go to the next element" << endl;
		cout << "  P   : Go to the prior element" << endl;
		cout << "  C   : Clear the list" << endl;
		cout << "  E   : Empty list?" << endl;
		cout << "  F   : Full list?" << endl;
		cout << "  M n : Move element marked by cursor to pos. n "
			<< " (Inactive : In-lab Ex. 2)" << endl;
		cout << "  ?x  : Search rest of list for x               "
			<< " (Inactive : In-lab Ex. 3)" << endl;
		cout << "  Q   : Quit the test program" << endl;
		cout << "  S   : Show DNA base counts in the list" << endl;
		cout << endl;


		testList.showStructure();                     // Output list

		cout << endl << "Command: ";                  // Read command
		cin >> cmd;
		if (cmd == '+' || cmd == '=' || cmd == '?')
			cin >> testElement;
		else if (cmd == 'M' || cmd == 'm')
			cin >> n;

		switch (cmd)
		{
		case '+':                                  // insert
			cout << "Insert " << testElement << endl;
			testList.insert(testElement);
			break;

		case '-':                                  // remove
			cout << "Remove the element marked by the cursor"
				<< endl;
			testList.remove();
			break;

		case '=':                                  // replace
			cout << "Replace the element marked by the cursor "
				<< "with " << testElement << endl;
			testList.replace(testElement);
			break;

		case '@':                                  // getCursor
			cout << "Element marked by the cursor is "
				<< testList.getCursor() << endl;

			break;

		case '<':                                  // gotoBeginning
			if (testList.gotoBeginning())
				cout << "Go to the beginning of the list" << endl;
			else
				cout << "Failed -- list is empty" << endl;
			break;

		case '>':                                  // gotoEnd
			if (testList.gotoEnd())
				cout << "Go to the end of the list" << endl;
			else
				cout << "Failed -- list is empty" << endl;
			break;

		case 'N': case 'n':                       // gotoNext
			if (testList.gotoNext())
				cout << "Go to the next element" << endl;
			else
				cout << "Failed -- either at the end of the list "
				<< "or the list is empty" << endl;
			break;

		case 'P': case 'p':                       // gotoPrior
			if (testList.gotoPrior())
				cout << "Go to the prior element" << endl;
			else
				cout << "Failed -- either at the beginning of the "
				<< "list or the list is empty" << endl;
			break;

		case 'C': case 'c':                       // clear
			cout << "Clear the list" << endl;
			testList.clear();
			break;

		case 'E': case 'e':                       // empty
			if (testList.isEmpty())
				cout << "List is empty" << endl;
			else
				cout << "List is NOT empty" << endl;
			break;

		case 'F': case 'f':                       // full
			if (testList.isFull())
				cout << "List is full" << endl;
			else
				cout << "List is NOT full" << endl;
			break;

			//in-lab
		case 'S': case 's':
			testList.countBases(testList, aCount, cCount, tCount, gCount);
			cout << "aCount = " << aCount << endl;
			cout << "cCount = " << cCount << endl;
			cout << "tCount = " << tCount << endl;
			cout << "gCount = " << gCount << endl;

		case 'Q': case 'q':                   // Quit test program
			break;

		default:                               // Invalid command
			cout << "Inactive or invalid command" << endl;
		}
	} while (cmd != 'Q' && cmd != 'q');
}
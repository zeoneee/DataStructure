//--------------------------------------------------------------------
//
//  Laboratory 6                                           test6.cpp
//
//  Test program for the operations in the Queue ADT
//
//--------------------------------------------------------------------

#include <iostream>
#include "queuearr.cpp"
//#include "queueLnk.cpp"

using namespace std;


void main()
{
	Queue<char> testQueue(8);   // Test queue
	char testElement;           // Queue element
	char cmd;                   // Input command

	cout << endl << "Commands:" << endl;
	cout << "  +x : Enqueue x" << endl;
	cout << "  -  : Dequeue" << endl;
	cout << "  C  : Clear the queue" << endl;
	cout << "  E  : Empty queue?" << endl;
	cout << "  >  : put in front(In-Lab2)" << endl;
	cout << "  =  : get from rear(In-Lab2)" << endl;
	cout << "  Q  : Quit the test program" << endl;
	cout << endl;

	do
	{
		testQueue.showStructure();                    // Output queue

		cout << endl << "Command: ";                  // Read command
		cin >> cmd;
		if (cmd == '+' || cmd == '>')
			cin >> testElement;

		switch (cmd)
		{
		case '+':                                  // enqueue
			cout << "Enqueue " << testElement << endl;
			testQueue.enqueue(testElement);
			break;

		case '-':                                  // dequeue
			if (!testQueue.isEmpty()) {
				cout << "Dequeued " << testQueue.dequeue() << endl;
			}
			break;

		case 'C': case 'c':                       // clear
			cout << "Clear the queue" << endl;
			testQueue.clear();
			break;

		case 'E': case 'e':                       // empty
			if (testQueue.isEmpty())
				cout << "Queue is empty" << endl;
			else
				cout << "Queue is NOT empty" << endl;
			break;

		case 'F': case 'f':                       // empty
			if (testQueue.isFull())
				cout << "Queue is full" << endl;
			else
				cout << "Queue is NOT full" << endl;
			break;

		case '>':
			cout << "Enqueue " << testElement << " in the front" << endl;
			testQueue.putFront(testElement);
			break;

		case '=':
			if (!testQueue.isEmpty()) {
				cout << "get " << testQueue.getRear() << " from rear" << endl;
			}
			break;

		case 'Q': case 'q':                   // Quit test program
			break;

		default:                               // Invalid command
			cout << "Inactive or invalid command" << endl;
		}
	} while (cmd != 'Q' && cmd != 'q');

}
//--------------------------------------------------------------------
//
//  Laboratory 5                                          stacklnk.h
//
//  Class declarations for the linked list implementation of the
//  Stack ADT
//
//--------------------------------------------------------------------

#include <stdexcept>

using namespace std;

template < class DT >        // Forward declaration of the Stack class
class Stack;

template < class DT >
class StackNode              // Facilitator class for the Stack class
{
private:

    // Constructor
    StackNode(const DT& nodeData, StackNode* nextPtr);

    // Data members
    DT data;        // Stack data item
    StackNode* next;    // Pointer to the next data item

    friend class Stack<DT>;
};

//--------------------------------------------------------------------

template < class DT >
class Stack
{
public:

    // Constructor
    Stack(int ignored = 0);

    // Destructor
    ~Stack();

    // Stack manipulation operations
    void push(const DT& newDataItem)    // Push data item
        throw (bad_alloc);
    DT pop()                              // Pop data item
        throw (logic_error);
    void clear();                         // Clear stack

    // Stack status operations
    bool isEmpty() const;                 // Stack is empty
    bool isFull() const;                  // Stack is full

    // Output the stack structure -- used in testing/debugging
    void showStructure() const;

    // In-lab operation
   Stack(const Stack& valueStack)      // Copy constructor
        throw (bad_alloc);

private:

    // Data member
    StackNode<DT>* top;   // Pointer to the top data item
};

// 2019112587 ±èÁöÇö

class ExprTree;
class ExprTreeNode;
 class Stack;

using namespace std;
#include <iostream>
#include <assert.h>

class Stack 
{
public:

	// Constructor
	Stack(int maxNumber);

	// Destructor
	~Stack();

	// Stack manipulation operations
	void push(string newElement);    // Push element
	string pop();                             // Pop element

	// Stack status operations
	bool empty() const;                    // Stack is empty

private:

	// Data members
	int maxSize,   // Maximum number of elements in the stack
		top;       // Index of the top element
	string* element;   // Array containing the stack elements

	friend class ExprTree;
};

class ExprTreeNode         // Facilitator class for the ExprTree class
{
private:

	// Constructor
	ExprTreeNode(char elem,
		ExprTreeNode* leftPtr, ExprTreeNode* rightPtr);

	// Data members
	char element;           // Expression tree element
	ExprTreeNode* left,     // Pointer to the left child
		* right;    // Pointer to the right child

	friend class ExprTree;
};
 
//--------------------------------------------------------------------

class ExprTree
{
public:

	// Constructor
	ExprTree();
	// Destructor
	~ExprTree();

	// Expression tree manipulation operations
	void build(Stack& stack);              // Build tree from prefix expression
	void clear();              // Clear tree
	// Output the tree structure -- used in testing/debugging
	void showStructure() const;

private:

	// Recursive partners of the public member functions -- insert
	// prototypes of these functions here.
	void buildSub(ExprTreeNode*& p, char& newElement);
	void clearSub(ExprTreeNode* p);
	void showSub(ExprTreeNode* p) const;
	

	// Data member
	ExprTreeNode* root;   // Pointer to the root node
};


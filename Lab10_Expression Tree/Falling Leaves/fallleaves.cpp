
// 2019112587 ±èÁöÇö

#include "fallleaves.h"

//--------------------------------------------------------------------
//  stack

Stack::Stack(int maxNumber)
	:maxSize(maxNumber),
	top(-1)
{
	element = new string[maxSize];
}

// Destructor

Stack::~Stack() {
	delete[] element;
}

// Stack manipulation operations
void Stack::push(string newElement) {
		top++;	
		element[top] = newElement;
}

string Stack::pop() {
		top--;
		return element[top + 1];
}


// Stack status operations
bool Stack::empty() const {
	if (top == -1) {
		return 1;
	}
	else return 0;
}


//--------------------------------------------------------------------

ExprTreeNode::ExprTreeNode(char elem, ExprTreeNode* leftPtr, ExprTreeNode* rightPtr)
{
	element = elem;
	left = leftPtr;
	right = rightPtr;
}

//--------------------------------------------------------------------

ExprTree::ExprTree()
{
	root = 0;
}

ExprTree::~ExprTree()
{
	clear();
}

//--------------------------------------------------------------------

void ExprTree::build(Stack& stack) 
{
	while (!stack.empty()) {
		string elem = stack.pop();
		char* eleme = new char[elem.size() + 1];
		strcpy_s(eleme, elem.size() + 1, elem.c_str());
		for (int i = 0; i < elem.size(); i++) {
			buildSub(root, eleme[i]);
		}
	}
}

void ExprTree::buildSub(ExprTreeNode*& p, char& newElement)
{
	
	if (p == NULL) {
		p = new ExprTreeNode(newElement, NULL, NULL);
	}
	else if (newElement < p->element) {
		buildSub(p->left, newElement);
	}
	else {
		buildSub(p->right, newElement);
	}
}

//--------------------------------------------------------------------

void ExprTree::clear()
{
	clearSub(root);
	root = 0;
}

void ExprTree::clearSub(ExprTreeNode* p)
{
	if (!(p == 0)) {
		clearSub(p->left);
		clearSub(p->right);
		delete p;
	}
}

//--------------------------------------------------------------------

void ExprTree::showStructure() const
{
	if (root == 0)
		cout << "Empty tree" << endl;
	else {
		showSub(root);
		cout << endl;
	}	
}

void ExprTree::showSub(ExprTreeNode* p) const
{
	if (p != 0)
	{
		cout << p->element;
		showSub(p->left);
		showSub(p->right);
	}
}

int main() {
	ExprTree testExpression;
	Stack stack(20);
	string elem;

	do {
		cin >> elem;
		if (elem == "*" || elem == "$") {
			testExpression.build(stack);
			testExpression.showStructure();
			testExpression.clear();
		}
		else {
			stack.push(elem);
		}
	} while (elem != "$");
}
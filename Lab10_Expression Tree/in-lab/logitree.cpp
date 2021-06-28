//--------------------------------------------------------------------
//		Lab 12									logitree.cpp
//
//--------------------------------------------------------------------

// 2019112587 김지현

#include "logitree.h"
#include <assert.h>
#include <ctype.h>
#include <iostream>

using namespace std;
//--------------------------------------------------------------------


// prelab과 동일하지만 build에서 -일 때는 달라서 조금 바뀌고, evaluate부분만 바뀜
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

void ExprTree::build()
{
	buildSub(root);
}

void ExprTree::buildSub(ExprTreeNode*& p)
{
	char elem;
	cin >> elem;
	p = new ExprTreeNode(elem, NULL, NULL);
	if (!(isdigit(elem))) {
		if (elem == '+'||elem == '*') {
			buildSub(p->left);
			buildSub(p->right);
		}
		else if (elem == '-') {
			buildSub(p->right);
		}
	}
}

//--------------------------------------------------------------------

void ExprTree::expression() const
{
	exprSub(root);
}

void ExprTree::exprSub(ExprTreeNode* p) const
{

	if (!isdigit(p->element)) {	// 연산자라면
		cout << "(";
		if (!(p->element == '-'))
			exprSub(p->left);
		cout << p->element;
		exprSub(p->right);
		cout << ")";
	}
	else {
		cout << p->element;
	}
}

//--------------------------------------------------------------------

int ExprTree::evaluate() const	
{
	return evaluateSub(root);
}

int ExprTree::evaluateSub(ExprTreeNode* p) const
{
	if (!isdigit(p->element)) {
		switch (p->element) {
		case '+':
			return (evaluateSub(p->left) || evaluateSub(p->right));
		case '-':
			if (evaluateSub(p->right) == 1) {
				return 0;
			}
			else {
				return 1;
			}
		case '*':
			return (evaluateSub(p->left) && evaluateSub(p->right));
		}
	}
	else {
		return p->element - 48;	// 아스키코드 '1' = 49
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

// Outputs an expression tree. The tree is output rotated counter-
// clockwise 90 degrees from its conventional orientation using a
// "reverse" inorder traversal. This operation is intended for testing
// and debugging purposes only.

{
	if (root == 0)
		cout << "Empty tree" << endl;
	else
	{
		cout << endl;
		showSub(root, 1);
		cout << endl;
	}
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void ExprTree::showSub(ExprTreeNode* p, int level) const

// Recursive partner of the showStructure() function. Outputs the
// subtree whose root node is pointed to by p. Parameter level is the
// level of this node within the expression tree.

{
	int j;   // Loop counter

	if (p != 0)
	{
		showSub(p->right, level + 1);        // Output right subtree
		for (j = 0; j < level; j++)   // Tab over to level
			cout << "\t";
		cout << " " << p->element;       // Output data item
		if ((p->left != 0) &&          // Output "connector"
			(p->right != 0))
			cout << "<";
		else if (p->right != 0)
			cout << "/";
		else if (p->left != 0)
			cout << "\\";
		cout << endl;
		showSub(p->left, level + 1);         // Output left subtree
	}
}
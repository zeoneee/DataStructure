//--------------------------------------------------------------------
//		Lab 12									exprtree.cpp
//
//--------------------------------------------------------------------

// 2019112587 김지현

#include "exprtree.h"
#include <assert.h>
#include <ctype.h>
#include <iostream>

using namespace std;
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

void ExprTree::build() // 전위 표기법으로 입력받아서 트리를 구성(preorder)
{
	buildSub(root);
}

void ExprTree::buildSub(ExprTreeNode*& p)
{
	// if나 switch문을 사용하여 연산자인지 숫자인지 확인, isdigit()함수 이용
	// isdigit(x) x=숫자라면 true 아니면 false
	char elem;
	cin >> elem;
	p= new ExprTreeNode(elem, NULL, NULL);
	if (!(isdigit(elem))) {	// 숫자가 아니라면 -> 연산자라면
		buildSub(p->left);
		buildSub(p->right);
	}
}

//--------------------------------------------------------------------

void ExprTree::expression() const	// 중위표기법으로 출력 (inorder)
{
	exprSub(root);
}

void ExprTree::exprSub(ExprTreeNode* p) const
{
	if (!isdigit(p->element)) {	// 연산자라면
		cout << "(";
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

float ExprTree::evaluate() const	// 계산식을 계산하여 반환
{
	return evaluateSub(root);
}

float ExprTree::evaluateSub(ExprTreeNode* p) const
{
	if (!isdigit(p->element)) {
		switch (p->element) {
		case '+':
			return evaluateSub(p->left) + evaluateSub(p->right);
		case '-':
			return evaluateSub(p->left) - evaluateSub(p->right);
		case '*':
			return evaluateSub(p->left) * evaluateSub(p->right);
		case '/':
			return evaluateSub(p->left) / evaluateSub(p->right);
		}
	}
	else {
		return p->element - 48;	// 아스키코드 '1' = 49
	}
}

//--------------------------------------------------------------------

void ExprTree::clear()	// 트리의 노드들을 전부 제거
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
	else
	{
		cout << endl;
		showSub(root, 1);
		cout << endl;
	}
}

void ExprTree::showSub(ExprTreeNode* p, int level) const
{
	int j;

	if (p != 0)
	{
		showSub(p->right, level + 1);
		for (j = 0; j < level; j++)
			cout << "\t";
		cout << " " << p->element;
		if ((p->left != 0) &&
			(p->right != 0))
			cout << "<";
		else if (p->right != 0)
			cout << "/";
		else if (p->left != 0)
			cout << "\\";
		cout << endl;
		showSub(p->left, level + 1);
	}
}
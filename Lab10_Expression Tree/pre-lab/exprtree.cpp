//--------------------------------------------------------------------
//		Lab 12									exprtree.cpp
//
//--------------------------------------------------------------------

// 2019112587 ������

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

void ExprTree::build() // ���� ǥ������� �Է¹޾Ƽ� Ʈ���� ����(preorder)
{
	buildSub(root);
}

void ExprTree::buildSub(ExprTreeNode*& p)
{
	// if�� switch���� ����Ͽ� ���������� �������� Ȯ��, isdigit()�Լ� �̿�
	// isdigit(x) x=���ڶ�� true �ƴϸ� false
	char elem;
	cin >> elem;
	p= new ExprTreeNode(elem, NULL, NULL);
	if (!(isdigit(elem))) {	// ���ڰ� �ƴ϶�� -> �����ڶ��
		buildSub(p->left);
		buildSub(p->right);
	}
}

//--------------------------------------------------------------------

void ExprTree::expression() const	// ����ǥ������� ��� (inorder)
{
	exprSub(root);
}

void ExprTree::exprSub(ExprTreeNode* p) const
{
	if (!isdigit(p->element)) {	// �����ڶ��
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

float ExprTree::evaluate() const	// ������ ����Ͽ� ��ȯ
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
		return p->element - 48;	// �ƽ�Ű�ڵ� '1' = 49
	}
}

//--------------------------------------------------------------------

void ExprTree::clear()	// Ʈ���� ������ ���� ����
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
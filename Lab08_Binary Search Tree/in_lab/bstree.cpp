// 2019112587 김지현

#include <assert.h>
#include <iostream>
#include "bstree.h"

using namespace std;

template < class TE, class KF >
BSTreeNode<TE, KF>::BSTreeNode(const TE& elem, BSTreeNode* leftPtr, BSTreeNode* rightPtr)
{
	element = elem;
	left = leftPtr;
	right = rightPtr;
}

template < class TE, class KF >
BSTree<TE, KF>::BSTree()
{
	root = NULL;
}

template < class TE, class KF >
BSTree<TE, KF>::~BSTree()
{
	clear();
}

// Insert

template < class TE, class KF >
void BSTree<TE, KF>::insert(const TE& newElement)
{
	if (isFull())
		cout << "Tree is Full" << endl;
	else
		insertSub(root, newElement);
}

template < class TE, class KF >
void BSTree<TE, KF>::insertSub(BSTreeNode<TE, KF>*& p, const TE& newElement)
{
	if (p == NULL) {
		p = new BSTreeNode<TE, KF>(newElement, NULL, NULL);
	}
	else if (newElement.key() < p->element.key()) {
		insertSub(p->left, newElement);
	}
	else {
		insertSub(p->right, newElement);
	}
}

//--------------------------------------------------------------------

// Retrieve 

template < class TE, class KF >
bool BSTree<TE, KF>::retrieve(KF searchKey, TE& searchElement) const
{
	return retrieveSub(root, searchKey, searchElement);
}

template < class TE, class KF >
bool BSTree<TE, KF>::retrieveSub(BSTreeNode<TE, KF>* p, KF searchKey, TE& searchElement) const
{
	bool result;
	if (p == NULL) {
		result = false;
	}
	else if (searchKey == p->element.key()) {
		searchElement = p->element;
		// searchElement.setKey(searchKey);
		result = true;
	}
	else if (searchKey < p->element.key()) {
		result = retrieveSub(p->left, searchKey, searchElement);
	}
	else {
		// searchKey > p->element
		result = retrieveSub(p->right, searchKey, searchElement);
	}
	return result;
}

//--------------------------------------------------------------------

// Remove

template < class TE, class KF >
bool BSTree<TE, KF>::remove(KF deleteKey)
{
	return removeSub(root, deleteKey);
}

template < class TE, class KF >
bool BSTree<TE, KF>::removeSub(BSTreeNode<TE, KF>*& p, KF deleteKey)
{
	bool result;
	if (isEmpty()) {
		cout << "Tree is Empty" << endl;
		result = false;
	}
	else if (p == NULL) {
		result = false;
	}
	else if (deleteKey < p->element.key()) {
		result = removeSub(p->left, deleteKey);
	}
	else if (deleteKey > p->element.key()) {
		result = removeSub(p->right, deleteKey);
	}
	else {
		// deleteKey == p-> element
		BSTreeNode<TE, KF>* tempPtr;
		tempPtr = p;
		if (p->left == NULL) { // 왼쪽 자식노드가 비어있는 경우
			p = p->right;
			delete tempPtr;
			result = true;
		}
		else if (p->right == NULL) { // 오른쪽 자식노드가 비어있는 경우
			p = p->left;
			delete tempPtr;
			result = true;
		}
		else { // 둘다 차있는 경우
			cutRightmost(p->left, tempPtr);
			delete tempPtr;
			result = true;
		}
	}
	return result;
}

template < class TE, class KF >
void BSTree<TE, KF>::cutRightmost(BSTreeNode<TE, KF>*& r, BSTreeNode<TE, KF>*& delPtr)
{
	if (r->right != NULL) {
		cutRightmost(r->right, delPtr);
	}
	else {
		delPtr->element = r->element;
		delPtr = r;
		r = r->left;
	}
}

//--------------------------------------------------------------------

// Write Keys

template < class TE, class KF >
void BSTree<TE, KF>::writeKeys() const
{
	writeKeysSub(root);
}

template < class TE, class KF >
void BSTree<TE, KF>::writeKeysSub(BSTreeNode<TE, KF>* p) const
{
	if (p != NULL) {
		writeKeysSub(p->left);
		cout << p->element.key() << " ";
		writeKeysSub(p->right);
	}
}

//--------------------------------------------------------------------

// Clear

template < class TE, class KF >
void BSTree<TE, KF>::clear()
{
	clearSub(root);
	root = NULL;
}

template < class TE, class KF >
void BSTree<TE, KF>::clearSub(BSTreeNode<TE, KF>* p)
{
	if (p != NULL) {
		clearSub(p->left);
		clearSub(p->right);
		delete p;
	}
}

//--------------------------------------------------------------------

// Empty / Full

template < class TE, class KF >
bool BSTree<TE, KF>::isEmpty() const
{
	return (root == NULL);
}

template < class TE, class KF >
bool BSTree<TE, KF>::isFull() const
{
	TE element;
	BSTreeNode<TE, KF>* newtree = new BSTreeNode<TE, KF>(element, NULL, NULL);
	if (newtree == NULL) {
		return true;
	}
	else {
		delete newtree;
		return false;
	}
}

//--------------------------------------------------------------------

// Show Structure

template < class TE, class KF >
void BSTree<TE, KF>::showStructure() const

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

template < class TE, class KF >
void BSTree<TE, KF>::showSub(BSTreeNode<TE, KF>* p,
	int level) const

{
	int j;   // Loop counter

	if (p != 0)
	{
		showSub(p->right, level + 1);         // Output right subtree
		for (j = 0; j < level; j++)    // Tab over to level
			cout << "\t";
		cout << " " << p->element.key();   // Output key
		if ((p->left != 0) &&           // Output "connector"
			(p->right != 0))
			cout << "<";
		else if (p->right != 0)
			cout << "/";
		else if (p->left != 0)
			cout << "\\";
		cout << endl;
		showSub(p->left, level + 1);          // Output left subtree
	}
}
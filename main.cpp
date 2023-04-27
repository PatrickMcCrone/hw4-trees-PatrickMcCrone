#include <iostream>
#include "BinaryNode.h"

bool isEmpty(BinaryNode<int>*);
BinaryNode<int>* add(BinaryNode<int>*, int);
void printTree(BinaryNode<int>*);
BinaryNode<int>* remove(BinaryNode<int>*, int);
BinaryNode<int>* getInOrderSuccessor(BinaryNode<int>*);
bool contains(BinaryNode<int>*, int);
void printLeaves(BinaryNode<int>*);
int getTreeHeight(BinaryNode<int>*);

int main() {
	//line below creates a three node binary tree
	//BinaryNode<int>* root = new BinaryNode<int>(12, new BinaryNode<int>(5), new BinaryNode<int>(15));

	BinaryNode<int>* root = nullptr;

	root = add(root, 12);
	root = add(root, 5);
	root = add(root, 15);
	root = add(root, 7);
	root = add(root, 9);
	root = add(root, 20);

	std::cout << "\nTree: ";
	printTree(root);

	root = remove(root, 15);
	std::cout << "\nTree: ";
	printTree(root);


	std::cout << "\nLeaves: ";
	printLeaves(root);

	std::cout << "\nHeight: " << getTreeHeight(root);


	return 0;
}

bool isEmpty(BinaryNode<int>* root) {
	return root == nullptr;
}

BinaryNode<int>* add(BinaryNode<int>* root, int newEntry) {
	BinaryNode<int>* curr = root;
	BinaryNode<int>* parent = nullptr;

	if (isEmpty(root)) {
		root = new BinaryNode<int>(newEntry);
		return root;
	}

	//find location to insert new node
	while (curr != nullptr) {
		parent = curr;
		if (newEntry >= curr->getValue()) {
			curr = curr->getRightChildPtr();
		}
		else {
			curr = curr->getLeftChildPtr();
		}
	}

	//insert new node at location
	if (newEntry >= parent->getValue()) {
		parent->setRightChildPtr(new BinaryNode<int>(newEntry));
	}
	else {
		parent->setLeftChildPtr(new BinaryNode<int>(newEntry));
	}

	return root;
}


void printTree(BinaryNode<int>* curr) {
	if (curr != nullptr) { //stopcase

		printTree(curr->getLeftChildPtr());
		std::cout << curr->getValue() << " ";
		printTree(curr->getRightChildPtr());
	}
}

//find the successor and returns the address of the successor node
BinaryNode<int>* getInOrderSuccessor(BinaryNode<int>* curr) {
	std::cout << "Inside getInOrderSuccessor() starting --> " << curr->getValue() << endl;
	while (curr->getLeftChildPtr() != nullptr) {
		std::cout << curr->getValue() << " ";
		curr = curr->getLeftChildPtr();
	}
	std::cout << endl << "Successor: " << curr->getValue() << endl;
	return curr;
}

bool contains(BinaryNode<int>* root, int value) {
	//check if a node with value exists in the tree
	BinaryNode<int>* curr = root;
	//if tree is not empty
	if (!isEmpty(root)) {
		//stop-case
		if (curr->getValue() == value) {
			return true;
		}
		else if (value < curr->getValue()) {
			return contains(curr->getLeftChildPtr(), value);
		}
		else if (value > curr->getValue()) {
			return contains(curr->getRightChildPtr(), value);
		}
	}
	return false;
}

BinaryNode<int>* remove(BinaryNode<int>* curr, int removeValue) {
	std::cout << "\nat: " << curr->getValue() << "";
	//BinaryNode<int>* curr = root; //REMOVED
	if (!isEmpty(curr)) {
		if (contains(curr, removeValue)) {
			//- start recursive calls and delete the node when found
			//- if removeValue is less than curr
			if (removeValue < curr->getValue()) {
				std::cout << "\n" << removeValue << " is less than" << curr->getValue() << endl;
				curr->setLeftChildPtr(remove(curr->getLeftChildPtr(), removeValue));
			}
			//- if removeValue is greater than curr
			else if (removeValue > curr->getValue()) {
				std::cout << "\n" << removeValue << " is greater than" << curr->getValue() << endl;
				curr->setRightChildPtr(remove(curr->getRightChildPtr(), removeValue));
			}
			//- if curr matches value
			else {
				std::cout << "\nRemoving: " << curr->getValue();
				//if curr has right child only or no child
				if (curr->getLeftChildPtr() == nullptr) {
					//hold right ptr
					BinaryNode<int>* temp = curr->getRightChildPtr();
					delete(curr);
					return temp;
				}
				//if curr has left child only or no child
				else if (curr->getRightChildPtr() == nullptr) {
					//hold left ptr
					BinaryNode<int>* temp = curr->getLeftChildPtr();
					delete(curr);
					return temp;
				}
				//if curr has both left and right children
				//find in order successor (smallest value in right sub-tree)
				BinaryNode<int>* temp2 = getInOrderSuccessor(curr->getRightChildPtr());
				curr->setValue(temp2->getValue());
				curr->setRightChildPtr(remove(curr->getRightChildPtr(), temp2->getValue()));
			}
		}
	}
	else {
		std::cout << "Tree is empty!";
	}
	return curr;
}

void printLeaves(BinaryNode<int>* curr) {
	if (!isEmpty(curr)) {
		//processing
		if (curr->getLeftChildPtr() == nullptr && curr->getRightChildPtr() == nullptr)
			std::cout << curr->getValue() << " ";

		//traverse left sub-tree
		printLeaves(curr->getLeftChildPtr());
		//treverse right sub-tree
		printLeaves(curr->getRightChildPtr());

	}
}

int getTreeHeight(BinaryNode<int>* curr) {

	if (curr != nullptr) {
		int left_height = getTreeHeight(curr->getLeftChildPtr());
		int right_height = getTreeHeight(curr->getRightChildPtr());

		if (left_height > right_height)
			return left_height + 1;
		else
			return right_height + 1;
	}
	else {
		return 0;
	}

}
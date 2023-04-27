#include <iostream>
using namespace std;

template <class V>
class BinaryNode {
	V nodeValue;
	BinaryNode<V>* leftChildPtr;
	BinaryNode<V>* rightChildPtr;

public:
	BinaryNode() : nodeValue(V(0)), leftChildPtr(nullptr), rightChildPtr(nullptr) {}

	BinaryNode(const V& nValue) : nodeValue(nValue), leftChildPtr(nullptr), rightChildPtr(nullptr) {}

	BinaryNode(const V& nValue, BinaryNode<V>* L, BinaryNode<V>* R) : nodeValue(nValue), leftChildPtr(L), rightChildPtr(R) {}

	void setValue(const V& newValue) {
		nodeValue = newValue;
	}

	V getValue() const {
		return nodeValue;
	}

	bool isLeaf() const {
		return ((leftChildPtr == nullptr) && (rightChildPtr == nullptr));
	}

	void setLeftChildPtr(BinaryNode<V>* L) {
		leftChildPtr = L;
	}

	void setRightChildPtr(BinaryNode<V>* R) {
		rightChildPtr = R;
	}

	auto getLeftChildPtr() const {
		return leftChildPtr;
	}

	auto getRightChildPtr() const {
		return rightChildPtr;
	}
};
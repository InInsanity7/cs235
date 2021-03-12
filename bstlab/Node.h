#ifndef NODE_H
#define NODE_H

#include "NodeInterface.h"

class Node: public NodeInterface {
    Node() : key(-1), right(NULL), left(NULL) {}
    Node(int key) : key(key), right(NULL), left(NULL) {}
	~Node() {}

	/*
	* Returns the data that is stored in this node
	*
	* @return the data that is stored in this node.
	*/
	int getData() const;

	/*
	* Returns the left child of this node or null if it doesn't have one.
	*
	* @return the left child of this node or null if it doesn't have one.
	*/
	Node* getLeftChild() const;

	/*
	* Returns the right child of this node or null if it doesn't have one.
	*
	* @return the right child of this node or null if it doesn't have one.
	*/
	Node* getRightChild() const;

    private:
    int key;
    Node* right;
    Node* left;

    friend class BST;
};


#endif

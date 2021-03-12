#ifndef BST_H
#define BST_H

#include "Node.h"
#include "BSTInterface.h"


class BST: public BSTInterface {
    public:
        BST(): root(NULL), ptr(NULL), preptr(NULL) {}
        ~BST() {}

        //Please note that the class that implements this interface must be made
        //of objects which implement the NodeInterface

        /*
         * Returns the root node for this tree
         *
         * @return the root node for this tree.
         */
        Node* getRootNode() const;

        /*
         * Attempts to add the given int to the BST tree
         *
         * @return true if added
         * @return false if unsuccessful (i.e. the int is already in tree)
         */
        bool add(int value);

        /*
         * Attempts to remove the given int from the BST tree
         *
         * @return true if successfully removed
         * @return false if remove is unsuccessful(i.e. the int is not in the tree)
         */
        bool remove(int value);

        /*
         * Removes all nodes from the tree, resulting in an empty tree.
         */
        void clear();

        void callPrint();

    protected: 
        Node* root;
        Node* ptr;
        Node* preptr;

    private:
        //navigates ptr to closest leaf. True if identical
        bool find(int value, Node*& tree);
        void replaceParent(Node*& oldroot, Node*& newroot);
        void deleteTree(Node*& next);
        void printInorder(Node*& u);
};

#endif

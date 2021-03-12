#include "BST.h"
#include <iostream>

Node* BST::getRootNode() const {return root;}

//moves class pointer to item location
bool BST::find(int value, Node*& tree) {
    if (tree == NULL) {
        return false;
    }
    preptr = ptr;
    ptr = tree;
    if (ptr->key == value) {
        std::cout << value << "found" << std::endl;
        return true;
    }
    else if (ptr->key < value) {
        return this->find(value, ptr->right);
    }
    else {
        return this->find(value, ptr->left);
    }
}

bool BST::add(int value) {
    std::cout << "adding" << std::endl;

    if (this->find(value, root)) {
        std::cout << value << "already added" << std::endl;
        return false;
    }

    Node* toAdd = new Node(value);
    if (root == NULL) {
        root = toAdd;
        ptr = root;
    }
    else {
        if (ptr->key < value) {
            ptr->right = toAdd;
    std::cout << value << "added right" << std::endl;
        }
        else {
            ptr->left = toAdd;
    std::cout << value << "added left" << std::endl;
        }
    }

    return true;

}


bool BST::remove(int value) {
    if (root == NULL) {
        std::cout << "tree empty" << std::endl;
        return false;
    }
    if (!this->find(value, root)) {
        std::cout << value << "could not be deleted: not in tree" << std::endl;
        return false;
    }

    if (ptr->left == NULL) {
        if (preptr == NULL) {
            root = ptr->right;
        }
        else if (preptr->left == ptr) {
            preptr->left = ptr->right;
        }
        else {
            preptr->right = ptr->right;
        }
        delete ptr;
    }
    else{
    Node* old = ptr;
    this->replaceParent(old, old->left);
    }
    return true;
}

void BST::replaceParent(Node*& oldroot, Node*& newroot) {

    if (newroot->right != NULL) {
        ptr = newroot;
        replaceParent(oldroot, newroot->right);
    }
    else {
        oldroot->key = newroot->key;
        if (newroot->left == NULL) {
            if (ptr->right == newroot) {
                ptr->right = NULL;
            }
            else {
                ptr->left = NULL;
                    }
            delete newroot;
        }
        else {
            replaceParent(newroot, newroot->left);
        }
    }
}

void BST::deleteTree(Node*& next) {
    if (next = NULL) {
        return;
    }
    deleteTree(next->left);
    deleteTree(next->right);
    delete next;
    return;
}
void BST::clear() {    
    this->deleteTree(root);
    root = NULL;
    ptr = NULL;
}


void BST::printInorder(Node*& u) {
    if (u == NULL) {
        return;
    }
    printInorder(u->left);
    cout << u->key << ", ";
    printInorder(u->right);
}
void BST::callPrint() {
    ptr = root;
    printInorder(ptr);
}

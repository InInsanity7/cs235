//FIXME:
//this->
//clear

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <string>
#include <iostream>
#include <sstream>
#include "LinkedListInterface.h"

template<class T>
class LinkedList: public LinkedListInterface<T> {

    public:

        LinkedList(void) {
            mylist = NULL;
            num_items = 0;
            std::cout << "In constructor" << std::endl;
        };
        virtual ~LinkedList(void) {
            std::cout << "In destructor" << std::endl;

            while (mylist != NULL) {
                Node* ptr = NULL;
                ptr = mylist;
                mylist = mylist->next;
                delete ptr;
                num_items--;
            }
            if (num_items != 0) {
                std::cout << "clear ended before num_items 0" << std::endl;
            }
            else {
                std::cout << "cleared" << std::endl;
            }

            /* while (mylist != NULL) { */
            /*     Node* current = mylist; */
            /*     mylist = mylist->next; */
            /*     delete current; */
            /* } */
        };

        // is node in list?
        bool find(T value) {
            bool found = false;
            Node* ptr = mylist;

            if (mylist == NULL) {
                std::cout << "Not found, list empty" << std::endl;
            }
            else {
                if (ptr->data == value) {
                    std::cout << value << " found!" << std::endl;
                    return true;
                }
                while (ptr->next != NULL) {
                    ptr = ptr->next;
                    if (ptr->data == value) {
                        std::cout << value << " found!" << std::endl;
                        return true;
                    }
                }
                std::cout << value << " not found." << std::endl;

            }
            return false;
        }

        //insert at beginning
        virtual void insertHead(T value){
            std::cout << "In insertHead" << std::endl;
            //check for item in list - no duplicates
            if (this->find(value)) {
                std::cout << value << "already in the list" << std::endl;
                return;
            }

            Node *insertNode = new Node(value);
            if (mylist == NULL) {
                mylist = insertNode;
            }
            else {
                insertNode->next = mylist;
                mylist = insertNode; 
            }
            num_items++;
            std::cout << value << "added" << std::endl;
        }







        virtual void insertTail(T value){
            std::cout << "In inserTail" << std::endl;
            //check for item in list - no duplicates
            if (this->find(value)) {
                std::cout << value << "already in the list" << std::endl;
                return;
            }

            Node *ptr = mylist;
            Node *insertNode = new Node(value);
            if (mylist == NULL) {
                mylist = insertNode;
            }
            else {
                while (ptr->next != NULL) {
                    ptr = ptr->next;
                }
                ptr->next = insertNode;
            }
            num_items++;
            std::cout << value << "added" << std::endl;
        }

        virtual void insertAfter(T value, T insertionNode){
            std::cout << "In insertAfter" << std::endl;
            //check for item in list - no duplicates
            if (this->find(value)) {
                std::cout << value << "already in the list" << std::endl;
                return;
            }
            if (!this->find(insertionNode)) {
                std::cout << insertionNode << "is not in the list" << std::endl;
                return;
            }

            if (mylist == NULL || num_items == 0) {
                return;
            }
            Node* ptr = mylist;
            Node* insertNode = new Node(value);
            bool inserted = false;
            while (!inserted) {
                if (ptr->data == insertionNode) {
                    insertNode->next = ptr->next;
                    ptr->next = insertNode;
                    inserted = true;
                }
                else {
                    ptr = ptr->next;
                }
            }
            num_items++;
        }

        virtual void remove(T value){
            std::cout << "in remove()" << std::endl;

            //check for item in list
            if (!this->find(value)) {
                std::cout << value << "is not in the list. Cannot remove." << std::endl;
                return;
            }
            Node* ptr = mylist;
            Node* tmp = NULL;
            bool removed = false;
            //if removing first item
            if (ptr->data == value) {
                mylist = ptr->next;
                delete ptr;
                removed = true;
            }
            while (!removed) {
                tmp = ptr->next;
                if (tmp->data == value) {
                    ptr->next = tmp->next;
                    delete tmp;
                    removed = true;
                }
                ptr = ptr->next;
            }
            num_items--;
        }

        virtual void clear() {
            if (mylist == NULL) {
                std::cout << "already clear" << std::endl;
                return;
            }
            Node* ptr = NULL;
            while (mylist != NULL) {
                ptr = mylist;
                mylist = mylist->next;
                delete ptr;
                num_items--;
            }
            mylist = NULL;
            if (num_items != 0) {
                std::cout << "clear ended before num_items 0" << std::endl;
            }
            else {
                std::cout << "cleared" << std::endl;
            }
        } 

        virtual T at(int index){
            Node* ptr = mylist;
                if (index >= num_items || index < 0) {
                    throw std::out_of_range("out_of_range");
                }
                else {
                for (int i = 0; i < index; i++) {
                    ptr = ptr->next;
                }
                return ptr->data;
                }
        }

        virtual int size() {return num_items;}

        virtual string toString(){
            std::stringstream llstr;
            Node* ptr = mylist;

            if (num_items != 0) {
                llstr << ptr->data << " ";
                while (ptr->next != NULL) {
                    ptr = ptr->next;
                    llstr << ptr->data << " ";
                }
            }
            std::string formatting =  llstr.str();
            formatting = formatting.substr(0, formatting.length() - 1);
            return formatting;
        }

    private:
        struct Node {
            T data;
            Node* next;
            Node(const T& the_data, Node* next_val = NULL) :
                data(the_data) {next = next_val;}
        };

        Node *mylist;
        int num_items;
};

#endif /* LINKED_LIST_H */




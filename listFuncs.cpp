// Name: Jianan Gao
// USC NetID: 7450905127
// CSCI 455 PA5
// Fall 2018


#include <iostream>

#include <cassert>

#include "listFuncs.h"

using namespace std;

Node::Node(const string &theKey, int theValue) {
   key = theKey;
   value = theValue;
   next = NULL;
}

Node::Node(const string &theKey, int theValue, Node *n) {
   key = theKey;
   value = theValue;
   next = n;
}

//*************************************************************************
// put the function definitions for your list functions below
bool listRemove(ListType & list, string target){
	ListType ptr = list;
	ListType prev = NULL;
	while(ptr !=NULL){
		if(ptr->key == target){
			delete ptr;
			//cout << "deleted" << ptr->value << endl;
			if(prev == NULL){
				list = ptr->next;
			}else{
				prev->next = ptr->next;
			}
			
			return true;
		}else{
			prev = ptr;
			ptr = ptr->next;
		}
	}
	return false;
}

int * listLookUp(ListType & list, const string & target){
    
    Node * node = list;
    while(node != NULL){
        string str = node -> key;
        if(str == target){
            return &(node -> value);
        }
        node = node -> next;
    }

    return NULL;
}

void listInsert(ListType & list, ListType toInsert){
	ListType ptr = list;
		while(ptr -> next != NULL){
		ptr = ptr->next;
	}
	ptr->next = toInsert;
	return;
}

void listPrint(ListType & list){
	ListType ptr = list;
	while(ptr != NULL){
		cout << ptr->key <<" "<< ptr->value << endl;
		ptr = ptr->next;
	}
}





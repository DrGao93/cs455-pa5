// Name: Jianan Gao
// USC NetID: 7450905127
// CSCI 455 PA5
// Fall 2018

// Table.cpp  Table class implementation


#include "Table.h"

#include <iostream>
#include <string>
#include <cassert>

using namespace std;


// listFuncs.h has the definition of Node and its methods.  -- when
// you complete it it will also have the function prototypes for your
// list functions.  With this #include, you can use Node type (and
// Node*, and ListType), and call those list functions from inside
// your Table methods, below.

#include "listFuncs.h"


//*************************************************************************

Table::Table() {
	hashSize = HASH_SIZE;
	data = new ListType[hashSize]();
	num = 0;

}


Table::Table(unsigned int hSize) {
	hashSize = hSize;
	data = new ListType[hashSize]();
	num = 0;
}


int * Table::lookup(const string &key) {
   ListType foundList = data[hashCode(key)];
   if(foundList != NULL){
   	int* foundInt = listLookUp(foundList, key);

   		return foundInt;
   }
   return NULL;   
}

bool Table::remove(const string &key) {
	ListType foundList = data[hashCode(key)];
	if(foundList != NULL){
   		if(listRemove(foundList,key)){
        data[hashCode(key)] = foundList;
   			num --;
   			return true;
   		}
   }
   return false;  
}

bool Table::insert(const string &key, int value) {
	ListType newNode = new Node(key,value);
	if(lookup(key) != NULL){
		return false;
	}else{
		ListType list = data[hashCode(key)];
		if (list == NULL)
		{
			data[hashCode(key)] = new Node(key,value);
		}else{
			listInsert(data[hashCode(key)], newNode);
		}
		num ++;
		return true;
	}
   
}

int Table::numEntries() const {
   return num;      
}


void Table::printAll() const {
	for(int i=0;i<hashSize;i++){
		ListType list = data[i];
		if(list != NULL){
			listPrint(list);
		}
	}
}

void Table::hashStats(ostream &out) const {
  int nonEmpty = 0;
  int longest = 0;
  for(int i=0;i<hashSize;i++){
  	ListType list = data[i];
  	int newLongest = 0;
  	if(list != NULL){
  		nonEmpty ++;
  		while(list!=NULL){
  			newLongest ++;
  			list = list->next;
  		}
  		if(newLongest > longest){
  			longest = newLongest;
  		}
  	}
  }

  out << "number of buckets: "<< hashSize << endl;
  out << "number of entries: "<< num << endl;
  out << "number of non-empty buckets: "<< nonEmpty << endl;
  out << "longest chain: "<< longest << endl;
}


// add definitions for your private methods here

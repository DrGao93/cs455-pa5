// Name: Jianan Gao
// USC NetID: 7450905127
// CSCI 455 PA5
// Fall 2018


//*************************************************************************
// Node class definition 
// and declarations for functions on ListType

// Note: we don't need Node in Table.h
// because it's used by the Table class; not by any Table client code.

// Note2: it's good practice to not put "using" statement in header files.  Thus
// here, things from std libary appear as, for example, std::string

#ifndef LIST_FUNCS_H
#define LIST_FUNCS_H
  

struct Node {
   std::string key;
   int value;

   Node *next;

   Node(const std::string &theKey, int theValue);

   Node(const std::string &theKey, int theValue, Node *n);
};


typedef Node * ListType;

//*************************************************************************
//add function headers (aka, function prototypes) for your functions
//that operate on a list here (i.e., each includes a parameter of type
//ListType or ListType&).  No function definitions go in this file.

/*remove a node from the linked list with the same target
parameter: list, the list where you want to remove a node.
			target, the node with this target key is removed.
return : if the remove is successful.
*/
bool listRemove(ListType & list, std::string target);

/*look up a node from the linked list with the same target
parameter: list, the list where you want to look up a node.
			target: the node with this target key is removed.
return : a pointer to the target node's value.
*/
int * listLookUp(ListType & list, const std::string & target);

/*insert a node to the linked list with the given node
parameter: list: the list where you want to insert a node.
			target: the node you want to insert.
return : nothing.
*/
void listInsert(ListType & list, ListType node);


/*print out the content of the linked list, one for each line.
parameter: list, the list you want to print.
return: Nothing
*/
void listPrint(ListType & list);












// keep the following line at the end of the file
#endif

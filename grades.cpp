// Name: Jianan Gao  
// USC NetID: 7450905127
// CSCI 455 PA5
// Fall 2018

/*
 * grades.cpp
 * A program to test the Table class.
 * How to run it:
 *      grades [hashSize]
 * 
 * the optional argument hashSize is the size of hash table to use.
 * if it's not given, the program uses default size (Table::HASH_SIZE)
 *
 */

#include "Table.h"

// cstdlib needed for call to atoi
#include <cstdlib>

using namespace std;
/*
   print out the command summary to the user. called when user input help or wrong input.
*/
void printSummary(){
      cout<< "insert name score" << endl;
      cout<< "     Insert this name and score in the grade table. If this name was already present, print a message to that effect, and don't do the insert." << endl;
      cout<< "change name newscore" << endl;
      
      cout<< "     Change the score for name. Print an appropriate message if this name isn't present."<< endl;
      cout<< "lookup name" << endl;
      cout<< "     Lookup the name, and print out his or her score, or a message indicating that student is not in the table."<< endl;
      cout<< "remove name" << endl;
      cout<< "     Remove this student. If this student wasn't in the grade table, print a message to that effect."<< endl;
      cout<< "print" << endl;
      cout<< "     Prints out all names and scores in the table."<< endl;
      cout<< "size" << endl;
      cout<< "     Prints out the number of entries in the table."<< endl;
      cout<< "status"<< endl;
      cout<< "     Prints out statistics about the hash table at this point. (Calls hashStats() method)"<< endl;
      cout<< "help"<< endl;
      cout<< "     Prints out a brief command summary."<< endl;
      cout<< "quit"<< endl;
      cout<< "     exits the game"<< endl;
}

int main(int argc, char * argv[]) {

   // gets the hash table size from the command line

   int hashSize = Table::HASH_SIZE;

   Table * grades;  // Table is dynamically allocated below, so we can call
   // different constructors depending on input from the user.

   if (argc > 1) {
      hashSize = atoi(argv[1]);  // atoi converts c-string to int
      if (hashSize < 1) {
         cout << "Command line argument (hashSize) must be a positive number" 
              << endl;
         return 1;
      }
      grades = new Table(hashSize);

   }
   else {   // no command line args given -- use default table size
      grades = new Table();
   }


   grades->hashStats(cout);

  
   
   string cmd;
   bool done = false;
   while(!done){
      cout << "cmd> "; 
      cin >> cmd;
      //test for one word command
      if (cmd == "print"){
         grades->printAll();
      }
      else if (cmd == "size"){
        cout << grades->numEntries() <<endl;
      }
      else if (cmd == "stats"){
         grades->hashStats(cout);
      }
      else if (cmd == "help"){
         printSummary();
         
      }
      else if (cmd == "quit"){
         done = true;
      }
      else{
         //test for multiple word command.
         string name;
         int value;
         if(cmd == "insert"){
            cin >> name;
            cin >> value;
            if(!grades->insert(name,value)){
               cout << "name already present, insert failed." << endl;
            }

         }else if (cmd == "change"){
            cin >> name;
            cin >> value;
            if (!grades->remove(name)){
               cout << "name not present change failed." << endl;
            }else{
               grades->insert(name,value);
            }
         }else if (cmd == "lookup"){
            cin >> name;
            int* found = grades->lookup(name);
            if (found != NULL){
               cout << *found <<endl;
            }else{
               cout << "the student is no in the table." << endl;
            }
         }else if(cmd == "remove"){
               cin >> name;
               if(!grades->remove(name)){
                  cout << "The student isn't in the table" << endl;
               }
         }else{
            cout<< "ERROR: invalid command" << endl;
            printSummary();
         }
      }
      //clear the cin buffer for next command.
      cin.clear();
      cin.ignore(1000, '\n');

     
   }
   return 0;
}





























/*******************************************************************/
/*    Author:        Eve Collier                                   */
/*    Course:        CSC237                                        */
/*    Filename:      p1.cpp                                        */
/*    Description:   p1 is a program that completes three different*/
/*                   implementations of a text file that the       */
/*                   user can view through a functional menu       */
/*                                                                 */
/*                                                                 */
/*                                                                 */
/*                                                                 */
/*                                                                 */
/*******************************************************************/

#include <vector>
#include <utility>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "WordData.h"
using namespace std;
#define ARRAYSIZE 10
bool batchMode;
// prototypes:
int readDataFile(string &fname);
void mainMenu(string &fname);
void readingParallelArrayData(char selection, string &fname, string uniqueWords[ARRAYSIZE], int occurances[ARRAYSIZE], int counter);
void readingArrayOfObjectData(WordData items[ARRAYSIZE], char selection, string &fname);
void readingVectorData(vector<WordData> words, char selection, string &fname);
void printParallelIterative(int counter, string &fname, string uniqueWords[ARRAYSIZE], int occurances[ARRAYSIZE]);
void printParallelRecursive(int temp, int recursiveCounter, string &fname, string uniqueWords[ARRAYSIZE], int occurances[ARRAYSIZE]);
void printObjectArrayIterative(int counter, WordData items[ARRAYSIZE], string &fname);
void printObjectArrayRecursive(int temp,int recursiveCounter, WordData items[ARRAYSIZE], string &fname);
void printObjectArrayPointer(int pointerCounter, WordData *p, string &fname);
void printStlVectorForLoop(int counter, vector<WordData> words, string &fname);
void printStlVectorIterator(vector<WordData> words, string &fname);

/*****************************************************************/
  /*    Function name:   main()                                    */
  /*                                                               */
  /*    Description:     Our main function for p1.cpp. Where we    */
  /*                     will call functions to execute program.   */
  /*                                                               */
  /*                                                               */
  /*    Parameters:	 none                                      */
  /*                                                               */
  /*                                                               */
  /*    Member Type:     facilitator                                */
  /*                                                               */
  /*    Return Value:    int                                       */
  /*****************************************************************/
int main(int argc, char **argv){

  for (int idx=0;idx<argc;idx++){
    if (argc == 1){
      continue;
    }
    else if (argc == 2){
      // if argc is 2, batch mode is a thing. Execute entire program then terminate
         batchMode = true; 
      string fname;
      fname = argv[1];
      readDataFile(fname);
      mainMenu(fname);
    }
  }

  if (batchMode == false){
  // Firstly, we must prompt the user to enter a file and then read from it
  cout << "Please enter in a filename." << endl;
  string fname;     // file we are reading from
  cin >> fname;

  readDataFile(fname);

  // At this point, we know the user has a valid file. We can send them to the
  // menu function.
  mainMenu(fname);
}
} // END of main()

/*****************************************************************/
  /*    Function name:   readDataFile()                            */
  /*                                                               */
  /*    Description:     This helper function basically verifies   */
  /*                     that the entered file is valid to         */
  /*                     read/work with.                           */
  /*                                                               */
  /*    Parameters:	 fname  - import                           */
  /*                                                               */
  /*                                                               */
  /*    Member Type:     inspector                                 */
  /*                                                               */
  /*    Return Value:    int                                       */
  /*****************************************************************/

int readDataFile(string &fname){

  ifstream ifs;    
  ifs.open(fname);
  
  // if the entered file isn't valid, we will keep calling this function and
  // have the user continiously enter files until they enter a valid one
  if(ifs.fail()){
  cout << "Failed to open file " << fname << endl;
  cout << "Please enter in another file name and try again: ";
  cin >> fname;
  readDataFile(fname);
  }
ifs.close();
 
  return 0;
  
} // END of readDataFile()

/*****************************************************************/
  /*    Function name:   mainMenu()                                */
  /*                                                               */
  /*    Description:     This function displays the menu to the    */
  /*                     user and then sends them to another       */
  /*                     function based on their choice            */
  /*                                                               */
  /*    Parameters:	 fname -import and export                  */
  /*                                                               */
  /*                                                               */
  /*    Member Type:     facilitator                               */
  /*                                                               */
  /*    Return Value:    none                                      */
  /*****************************************************************/
void mainMenu(string &fname){

  char selection;    // the user input

  // from here we will create the various arrays that need to get passed to our various functions
  string uniqueWords[ARRAYSIZE];
  int occurances[ARRAYSIZE];
  int counter = 0; 

  WordData items[ARRAYSIZE];	  

  vector<WordData> words;

  if (batchMode == true){
    // the user has selected batch mode, meaning theres no point in displaying the menu 
    // instead...
    readingParallelArrayData(selection, fname, uniqueWords, occurances, counter);
    printParallelIterative(counter, fname, uniqueWords, occurances);
    int recursiveCounter;
    int temp;
    temp = counter;
    recursiveCounter = temp;
    // print top part of menu here. Recursion is used for the rest (duh)
    cout << "Parallel Recursive" << endl;
    cout << "------------------------------" << endl;
    cout << "Word           Occurrences    " << endl;
    cout << "------------------------------" << endl;
    printParallelRecursive(0, recursiveCounter, fname, uniqueWords, occurances);
    // a seg fault is happening. I wont bother writing the rest :(
    exit(0);
  
 }
  else if (batchMode == false){
  // Now we can print the menu
  cout << "Enter a number, 1-8, to choose from the menu below:" << endl;
  cout << "1. Parallel Iterative" << endl;
  cout << "2. Parallel Recursive" << endl;
  cout << "3. Object Array Iterative" << endl;
  cout << "4. Object Array Recursive" << endl;
  cout << "5. Object Array Pointer Recursive" << endl;
  cout << "6. STL Vector For Loop" << endl;
  cout << "7. STL Vector Iterator" << endl;
  cout << "8. Exit" << endl;
  cout << endl;
  cout << "Choice entered: ";
  cin >> selection;

  // we will go through and send the user to the appropriate function based on their choice
  if (selection == '1'){
    readingParallelArrayData(selection, fname, uniqueWords, occurances, counter); 
  }
    else if (selection == '2'){
      readingParallelArrayData(selection, fname, uniqueWords, occurances, counter);
    }
      else if (selection == '3'){
        readingArrayOfObjectData(items, selection,fname);
      }
        else if (selection == '4'){
         readingArrayOfObjectData(items, selection, fname);
        }
          else if (selection == '5'){
            readingArrayOfObjectData(items, selection, fname);
          }
            else if (selection == '6'){
              readingVectorData(words, selection, fname);
            }
              else if (selection == '7'){
                readingVectorData(words, selection, fname);
              }
                else if (selection == '8'){
                  exit(0);   // just exit the program
                }
                  else{
                    // if we reach this point, the user didn't enter a valid menu choice
                    cout << endl;
                    cout << "Please enter an integer between 1-8 to choose from the menu." << endl;
                    mainMenu(fname);      // allow the user to try again
                  }
}
} // END of mainMenu()


/*****************************************************************/
  /*    Function name:   readingParallelArrayData()                */
  /*                                                               */
  /*    Description:     this function reads a file and sorts      */
  /*                     its data into a parallel array            */
  /*                                                               */
  /*                                                               */
  /*    Parameters:      selection   - import                      */
  /*                     fmame       - import and export           */
  /*                     uniqueWords - import and export           */
  /*		         occurances  - import and export           */	
  /*                     counter     - export                      */
  /*								   */	   
  /*    Member Type:     mutator                                   */
  /*                                                               */
  /*    Return Value:    void                                      */
  /*****************************************************************/
void readingParallelArrayData(char selection, string &fname,string uniqueWords[ARRAYSIZE], int occurances[ARRAYSIZE], int counter){
  ifstream ifs; 
  ifs.open(fname);
  
  string temp;         // temp variable to hold contents of the file
  bool flag = false;   // this will help us later.
  int ocounter = 0;    // counter starts at 0
  ifs >> temp;         // load first val into temp var before entering while loop
  while(! ifs.eof()){
    flag = false; // the flag is only true if we find a duplicate
    for (int i = 0; i < counter; i++){
      if (uniqueWords[i] == temp){
        flag = true;    // we found a duplicate, so the flag is true
        occurances[i]++; 
      }
    }
      if (flag == false && temp != "" && counter < ARRAYSIZE){
        // this is not a duplicate, so, we can add the elt to our array 
        uniqueWords[counter] = temp; 
        occurances[counter] = 1;   // and since we found a new value, we can update our parallel ar
        counter++;  //since we added a value, our counter needs to increase
      }
      ifs >> temp;     // must read in the file again to get next val
      
  }  

  ifs.close();
  
 if (batchMode == true){
    mainMenu(fname);
 } 

  // Now all that needs to be done is to send the user to the appropriate print function
  if (selection == '1'){
    printParallelIterative(counter, fname, uniqueWords, occurances);
  } 
 else if (selection == '2'){
    int recursiveCounter;
    int temp;
    temp = counter;
    recursiveCounter = temp;
    // print top part of menu here. Recursion is used for the rest (duh)
    cout << "Parallel Recursive" << endl;
    cout << "------------------------------" << endl;
    cout << "Word           Occurrences    " << endl;
    cout << "------------------------------" << endl;
    printParallelRecursive(0, recursiveCounter, fname, uniqueWords, occurances);
  }
 
  
} // END of readingParallelArrayData


/*****************************************************************/
  /*    Function name:   readingArrayOfObjectData()                */
  /*                                                               */
  /*    Description:     reads info from a file then sorts it      */
  /*                     into an array of WordData objects         */
  /*                                                               */
  /*                                                               */
  /*    Parameters:	 selection   - import                      */
  /*                     fmame       - import and export           */
  /*                     items       - import and export           */
  /*	                                                           */
  /*    Member Type:    mutator                                    */
  /*                                                               */
  /*    Return Value:   void                                       */
  /*****************************************************************/
void readingArrayOfObjectData(WordData items[ARRAYSIZE],char selection, string &fname){
  ifstream ifs;
  ifs.open(fname);
   
  bool flag = false;   // helper for later
  string temp;         // temp variable- will hold contents of file
  int counter = 0;     // will keep track of how many elements we added

  // we will loop through the file and add it to our object
  while(! ifs.eof()){
    flag = false;     // will only be true once duplicate is found
    for(int i = 0; i < counter; i++){
      if (temp == items[i].getWord()){
        flag = true;   // we found a duplicate. Huzzah.
        items[i]++;
      }
    }
      if ( flag == false && temp != "" && counter < ARRAYSIZE){
        // this elt isn't a duplicate, an object can be created
        WordData item;
        item.setWordData(temp,1);
        items[counter] = item;
        counter++;   // a val was added to the object, counter must be updated
      }
      ifs >> temp;    // to get to the next val, we must read file again
  }
  
  ifs.close();

  // At this point, we just need to send the user to the appropriate print
  // method based off their input

  if (selection == '3'){
    printObjectArrayIterative(counter, items, fname);
  }
 else if (selection == '4'){
    int recursiveCounter;
    int temp;
    temp = counter;
    recursiveCounter = temp;
    // print top part of menu here. Recursion is used for the rest (duh)
    cout << "Object Array Recursive" << endl;
    cout << "------------------------------" << endl;
    cout << "Word           Occurrences    " << endl;
    cout << "------------------------------" << endl;
    printObjectArrayRecursive(0, recursiveCounter, items, fname);
  }
  else if (selection == '5'){
      int pointerCounter;
      pointerCounter = counter;

      WordData *p = items;
      // First half of menu will print here
      cout << "Object Array Pointer" << endl;
      cout << "------------------------------" << endl;
      cout << "Word           Occurrences    " << endl;
      cout << "------------------------------" << endl;
      printObjectArrayPointer(pointerCounter, p, fname);
  }


} // END of readingArrayOfObjectData


/*****************************************************************/
  /*    Function name:   readingVectorData()                       */
  /*                                                               */
  /*    Description:     reads info from file and sorts it into    */
  /*                     a vector. Data is put into WordData obj   */
  /*                     again                                     */
  /*                                                               */
  /*    Parameters:	 selection   - import                      */
  /*                     fmame       - import and export           */
  /*                     words       - import and export           */
  /*                                                               */
  /*    Member Type:     mutator				   */	
  /*                                                               */
  /*    Return Value:    void                                      */
  /*****************************************************************/
void readingVectorData(vector<WordData> words, char selection, string &fname){
  ifstream ifs;
  ifs.open(fname);

  bool flag = false;   // helper for later
  string temp;         // temp variable- will hold contents of file
  int counter = 0;     // will keep track of how many elements we added

  // we will loop through the file and add it to our object
  while(! ifs.eof()){
    flag = false;     // will only be true once duplicate is found
    for(int i = 0; i < counter; i++){
      if (temp == words.at(i).getWord()){
        flag = true;   // we found a duplicate. Huzzah.
        words[i]++;
      }
    }
      if ( flag == false && temp != "" && counter < ARRAYSIZE){
        // this elt isn't a duplicate, meaning each vector can be updated accordingly
        WordData item;
        item.setWordData(temp,1);
        words.push_back(item);
        counter++;   // a val was added to the object, counter must be updated
      }
      ifs >> temp;    // to get to the next val, we must read file again
  }

  ifs.close();
  

  // At this point, we just need to send the user to the corresponding print function
  // based off their selection
  if (selection == '6'){
    printStlVectorForLoop(counter, words, fname);
}
  else if (selection == '7'){
    printStlVectorIterator(words, fname);
  }
  
} // END of readingVectorData


/*****************************************************************/
  /*    Function name:   printParallelIterative()                  */
  /*                                                               */
  /*    Description:     prints the parallel arrays ITERATIVELY    */
  /*                                                        	   */
  /*                                                               */
  /*                                                               */
  /*    Parameters:	 counter     - import                      */
  /*                     fmame       - import and export           */
  /*                     uniqueWords - import                      */
  /*                     occurances  - import                      */
  /*                                                               */
  /*    Member Type:     facilitator                               */
  /*                                                               */
  /*    Return Value:    void                                      */
  /*****************************************************************/
void printParallelIterative(int counter, string &fname, string uniqueWords[ARRAYSIZE], int occurances[ARRAYSIZE]){
  // first we want to start with displaying the menu
  cout << "Parallel Iterative" << endl;
  cout << "------------------------------" << endl;
  cout << "Word           Occurrences    " << endl;
  cout << "------------------------------" << endl;
  for (int i = 0; i < counter; i++){
    cout << left << setw(20)<<  uniqueWords[i]; 
    cout << left << setw(7) << occurances[i] << endl;
  }
  cout << endl;

  mainMenu(fname);  // the user must be sent back to the main menu
  
} // END of printParallelIterative()



/*****************************************************************/
  /*    Function name:   printParallelRecursive()                  */
  /*                                                               */
  /*    Description:     prints the parallel array RECURSIVELY     */
  /*                                                         	   */
  /*                                                               */
  /*                                                               */
  /*    Parameters:      recusriveCounter     - import		   */	
  /*                     temp        - import                      */
  /*                     fmame       - import and export           */
  /*                     uniqueWords - impoty                      */
  /*                     occurances  - import                      */
  /*								   */
  /*    Member Type:     facilitator                               */
  /*                                                               */
  /*    Return Value:    void                                      */
  /*****************************************************************/
void printParallelRecursive(int temp, int recursiveCounter, string &fname, string uniqueWords[ARRAYSIZE], int occurances[ARRAYSIZE]){

  if (recursiveCounter == temp){
    cout << left << setw(20)<<  uniqueWords[recursiveCounter];
    cout << left << setw(7) << occurances[recursiveCounter] << endl;        
  }
  else{
    cout << left << setw(20)<<  uniqueWords[temp];
    cout << left << setw(7) << occurances[temp] << endl; 
    temp++;
    if (recursiveCounter!=temp){
      printParallelRecursive(temp, recursiveCounter, fname, uniqueWords, occurances);
    }  
  }  
  
  if (recursiveCounter != 1){
  cout << endl;     // we want some space between the table and menu (or at least I do)
  mainMenu(fname);  // the user must be sent back to the main menu
 }
} // END of printParallelRecusrive()


/*****************************************************************/
  /*    Function name:   printObjectArrayIterative()               */
  /*                                                               */
  /*    Description:     prints the array of WordData object       */
  /*                     ITERATIVELY                          	   */
  /*                                                               */
  /*                                                               */
  /*    Parameters:      fname - import and export                 */
  /*                     counter - import                          */
  /*			 items - import			           */
  /*                                                               */
  /*    Member Type:     facilitator                               */
  /*                                                               */
  /*    Return Value:    void                                      */
  /*****************************************************************/
void printObjectArrayIterative(int counter, WordData items[ARRAYSIZE], string &fname){
  // first we want to start with displaying the menu
  cout << "Object Array Iterative" << endl;
  cout << "------------------------------" << endl;
  cout << "Word           Occurrences    " << endl;
  cout << "------------------------------" << endl;
  for (int i = 0; i < counter; i++){
    cout << left << setw(20)<<  items[i].getWord();
    cout << left << setw(7) << items[i].getCount() << endl;
  }
  cout << endl;
  mainMenu(fname);  // the user must be sent back to the main menu
  
} //END of printObjectArrayIterative()


/*****************************************************************/
  /*    Function name:   printObjectArrayRecursive()               */
  /*                                                               */
  /*    Description:     prints the array of WordData object       */
  /*                     RECURSIVELY                         	   */
  /*                                                               */
  /*                                                               */
  /*    Parameters:      fname - import and export                 */
  /*			 temp  - import 			   */
  /*			 recursiveCounter - import		   */
  /*			 items - import			           */	
  /*                                                               */
  /*                                                               */
  /*    Member Type:     facilitator                               */
  /*                                                               */
  /*    Return Value:    void                                      */
  /*****************************************************************/
void printObjectArrayRecursive(int temp, int recursiveCounter, WordData items[ARRAYSIZE], string &fname){
  if (recursiveCounter == temp){
    cout << left << setw(20)<<  items[recursiveCounter].getWord();
    cout << left << setw(7) << items[recursiveCounter].getCount() << endl;
  }
  else{
    cout << left << setw(20)<<  items[temp].getWord();
    cout << left << setw(7) << items[temp].getCount() << endl;
    temp++;
    if (recursiveCounter!=temp){
      printObjectArrayRecursive(temp, recursiveCounter, items, fname);
    }
  }

  if (recursiveCounter != 1){
  cout << endl;     // we want some space between the table and menu (or at least I do)
  mainMenu(fname);  // the user must be sent back to the main menu
  }

} // END of printObjectArrayRecursive()


/*****************************************************************/
  /*    Function name:   printObjectArrayPointer()                 */
  /*                                                               */
  /*    Description:     prints the array of WordData object       */
  /*                     through pointer manipulation         	   */
  /*                                                               */
  /*                                                               */
  /*    Parameters:      fname - import and export                 */
  /*                     pointerCounter - import                   */
  /*			 *p    - import				   */
  /*                                                               */
  /*    Member Type:     facilitator                               */
  /*                                                               */
  /*    Return Value:    void                                      */
  /*****************************************************************/
void printObjectArrayPointer(int pointerCounter, WordData *p, string &fname){
   for(int i = 0; i < pointerCounter; i++){
        cout << *(p+i); 
    } 

  cout << endl;     // space between the table and the menu would be nice
  mainMenu(fname);  // the user must be sent back to the main menu
  
} // END of printObjectArrayPointer()


/*****************************************************************/
  /*    Function name:   printStlVectorForLoop()                   */
  /*                                                               */
  /*    Description:     prints a vector of WordData objects       */
  /*                     using a for-loop                   	   */
  /*                                                               */
  /*                                                               */
  /*    Parameters:      fname - import and export                 */
  /*                     words - import                            */
  /*                                                               */
  /*    Member Type:     facilitator                               */
  /*                                                               */
  /*    Return Value:    void                                      */
  /*****************************************************************/
void printStlVectorForLoop(int counter, vector<WordData> words, string &fname){
  // first we want to start with displaying the menu
  cout << "Vector For-Loop" << endl;
  cout << "------------------------------" << endl;
  cout << "Word           Occurrences    " << endl;
  cout << "------------------------------" << endl;

  for (int i = 0; i < counter; i++){
//    cout << left << setw(20)<<  words[i] << endl;
//    cout << words[i].getName() << endl;
     cout << left << setw(20)<<  words[i].getWord();
     cout << left << setw(7) << words[i].getCount() << endl;
  }
  
  
  cout << endl;     // for neatness
  mainMenu(fname);  // the user must be sent back to the main menu
  
} // END of printStlVectorForLoop()



/*****************************************************************/
  /*    Function name:   printStlVectorIterator()                  */
  /*                                                               */
  /*    Description:     prints a vector of WordData objects       */
  /*                     ITERATEVLY                           	   */
  /*                                                               */
  /*                                                               */
  /*    Parameters:      fname - import and export                 */
  /*                     words - import                            */
  /*                                                               */
  /*    Member Type:     facilitator                               */
  /*                                                               */
  /*    Return Value:    void                                      */
  /*****************************************************************/
void printStlVectorIterator(vector<WordData> words, string &fname){
  // first we want to start with displaying the menu
  cout << "Vector Iterative" << endl;
  cout << "------------------------------" << endl;
  cout << "Word           Occurrences    " << endl;
  cout << "------------------------------" << endl;
  cout << " ";

  for (auto i = words.begin(); i != words.end(); i++){
    cout << left << setw(20)<< *i << " ";
  }
  
  cout << endl;     // for neatness
  mainMenu(fname);  // the user must be sent back to the main menu 
  
} // END of printStlVectorIterator()

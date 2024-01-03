/*!	  \file testLL.cpp
*         \brief a test driver for LinkedList.h. Displays a fancy menu and allows the user to manipulate a circular linked list object.
*/


/*******************************************************************/
/*    Author:        Eve Collier                                   */
/*    Course:        CSC237                                        */
/*    Filename:      testLL.cpp                                     */
/*    Description:   test driver for LinkedList.h                  */
/*                                                                 */
/*                                                                 */
/*                                                                 */
/*                                                                 */
/*                                                                 */
/*                                                                 */
/*                                                                 */
/*******************************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include "CLinkedList.h"
using namespace std;

// prototypes:
int menu(CLinkedList<int>&);
void insert(CLinkedList<int>&);
void remove(CLinkedList<int>&);
void forwardPrint(CLinkedList<int>&);
void backwardPrint(CLinkedList<int>&);

/*!
 * main 
 * - the main method
 * facilitator
 */

/*****************************************************************/
  /*    Function name:   main()                                    */
  /*                                                               */
  /*    Description:     Our main function for testLL.cpp. Where   */
  /*                     we will call functions to carry program   */
  /*                     out                                       */
  /*                                                               */
  /*    Parameters:	 none                                      */
  /*                                                               */
  /*                                                               */
  /*    Member Type:     facilitator                               */
  /*                                                               */
  /*    Return Value:    int                                       */
  /*****************************************************************/
int main (){

  CLinkedList<int> cList;
  CLinkedList<int> cpy;
 
  menu(cList);
  return 0;
 
} // END of main()

/*!
 * menu 
 * - displays the menu to the user and calls the appropriate function based on user input
 * - Requires: cList, the imported CLinkedList object
 * - Returns:  int, so that we can use return statements where needed
 * - facilitator
 */
/*****************************************************************/
  /*    Function name:   menu()                                    */
  /*                                                               */
  /*    Description:     This function will display the menu and   */
  /*                     call the appropriate function based on    */
  /*                     the user's input                          */
  /*                                                               */
  /*    Parameters:	 cList - our linked list of eltType        */
  /*                           - imported                          */
  /*                                                               */
  /*    Member Type:     facilitator                               */
  /*                                                               */
  /*    Return Value:    int  - so that we can return 0            */
  /*****************************************************************/
int menu (CLinkedList<int>& cList){

  char selection;
  bool quit = false;

   do {
     cout << endl;
     cout << "Choose from the following:" << endl;
     cout << endl;
     cout << "I - Insert Integer" << endl;
     cout << "R - Remove Integer" << endl;
     cout << "F - Forward Print" << endl;
     cout << "B - Backward Print" << endl;
     cout << "E - Exit" << endl;
     cout << "*********************************" << endl;
     cin >> selection;

     switch(selection){
       case 'i':
       case 'I':
          insert(cList);
         break;
       case 'r':
       case 'R':
          remove(cList);
         break;
       case 'f':
       case 'F':
          forwardPrint(cList);
         break;
       case 'b':
       case 'B':
          backwardPrint(cList);
         break;
       case 'e':
       case 'E':  
        // return 0;
        exit (0);    // exit instead of return to avoid seg fault error
         break;
       default:
         cout << "Invalid menu choice :( please try again" << endl; 
     
     }
     
  } while(quit == false);
  return 0;
}

/*!
 * insert 
 * - inserts a new element (int entered by user) into the CLinkedList object
 * - Requires: cList, the imported CLinkedList object
 * - mutator
 */
/*****************************************************************/
  /*    Function name:   insert()                                  */
  /*                                                               */
  /*    Description:     This function will insert a new element   */
  /*                     into our circular linked list	           */
  /*                                                               */
  /*                                                               */
  /*    Parameters:	 cList - our linked list of eltType        */
  /*                           - imported                          */
  /*                                                               */
  /*    Member Type:     mutator                                   */
  /*                                                               */
  /*    Return Value:    void                                      */
  /*****************************************************************/
void insert (CLinkedList<int>& cList){
  int num;
  cout << "What number would you like to insert?: " << endl;
  cin >> num;

 
  cList.insert(num);

}

/*!
 * remove 
 * - removes a specified element (by the user) from the CLinkedList object   
 * - Requires: cList, the imported CLinkedList object
 * - mutator     
 */

/*****************************************************************/
  /*    Function name:   remove()                                 */
  /*                                                               */
  /*    Description:     This function will remove an element      */
  /*                     from our circular linked list             */
  /*                                                               */
  /*                                                               */
  /*    Parameters:	 cList - our linked list of eltType        */
  /*                           - imported                          */
  /*                                                               */
  /*    Member Type:     mutator                                   */
  /*                                                               */
  /*    Return Value:    void                                      */
  /*****************************************************************/
void remove (CLinkedList<int>& cList){
  int num;
  cout << "What number would you like to remove?: " << endl;
  cin >> num;

  cList.remove(num);
}

/*!
 * forwardPrint 
 * - displays the conents of the CLinkedList object forwards
 * - Requires: cList, the imported CLinkedList object
 * - facilitator
 */

/*****************************************************************/
  /*    Function name:   forwardPrint()                            */
  /*                                                               */
  /*    Description:     This function will print our circular	   */
  /*                     linked list FORWARDS                      */
  /*                                                               */
  /*                                                               */
  /*    Parameters:      cList - our linked list of eltType        */
  /*                           - imported                          */
  /*                                                               */
  /*    Member Type:     facilitator                               */
  /*                                                               */
  /*    Return Value:    void                                      */
  /*****************************************************************/
void forwardPrint (CLinkedList<int>& cList){
  // We will print the contents of cList using our iterator
  CListItr<int> clt(cList);

  if (clt.isEmpty() == true){
    cout << "The list is empty, nothing to print." << endl;
    menu(cList);
  }

  for (clt.begin(); clt.isLastNode() == false; clt++){
    cout << *clt << " ";
  }
  cout << *clt << endl;

} 

/*!
 * backwardPrint 
 * - displays the conents of the CLinkedList object backwards
 * - Requires: cList, the imported CLinkedList object
 * - facilitator
 */

/*****************************************************************/
  /*    Function name:   backwardPrint()                           */
  /*                                                               */
  /*    Description:     This function will print our circular     */
  /*                     linked list BACKWARDS                     */
  /*                                                               */
  /*                                                               */
  /*    Parameters:	 cList - our linked list of eltType        */
  /*                           - imported                          */
  /*                                                               */
  /*    Member Type:     facilitator                               */
  /*                                                               */
  /*    Return Value:    void                                      */
  /*****************************************************************/
void backwardPrint(CLinkedList<int>& cList){
  // We will print the contents of cList using our iterator
  CListItr<int> clt(cList);

  cList.reverse();  

  for (clt.begin(); clt.isLastNode() == false; clt++){
    cout << *clt << " ";
  }
  cout << *clt << endl;

  cList.reverse(); // reverse once more to put the list
		   // back to its original state
}


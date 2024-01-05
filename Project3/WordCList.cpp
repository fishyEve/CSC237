/*******************************************************************/
/*    Author:        Eve Collier                                   */
/*    Course:        CSC237                                        */
/*    Date:          3/26/23                                       */
/*    Filename:      WordCList.cpp                                 */
/*    Description:   WordCList.cpp is a cpp file containing the    */
/*                   implementation from our WordCList.h file      */
/*                                                                 */
/*                                                                 */
/*                                                                 */
/*                                                                 */
/*                                                                 */
/*                                                                 */
/*******************************************************************/
#include <iostream>
#include <sstream>
#include <assert.h>
#include "WordCList.h"

#include <chrono>
#include <cmath>

using namespace std;
/*!
          \file WordCList.cpp
          \brief a cpp containing the implementation for WordCList.h
          \class WordCList.cpp
          \brief a cpp containing the implementation for WordCList.h

 */


   //! WordCList()
   /*/
    */
WordCList::WordCList(){

   // CList = CLinkedList<WordData>();
 
}

   //! parseIntoList()
   /*!
      \brief Parses information from a file into a circular linked list
    */
void WordCList::parseIntoList(ifstream &inf){
    using namespace std::chrono;
    cout << " " << endl;
    std::cout << "Calculating time to parse words into the circular linked list...\n";

    auto begin = high_resolution_clock::now();

  string temp;
  bool flag = false;

  // CListItr<WordData> clt(CList);
  while (inf >> temp){
  CListItr<WordData> clt(CList);
 
  flag = false;
  clt.begin();
  if (clt.isEmpty()){ // if list is empty, manually enter first elt
     WordData data;
     data.setWordData(temp, 1);
     CList.insert(data);
     continue;
   }
  for(clt.begin(); clt.isLastNode()==false;clt++){ // we found a duplicate
    if ((*clt).getWord() == temp){
      WordData temp2 = *clt;
      //CList.remove(*clt);
      CList.remove(temp2);
      temp2.incCount(1);
      CList.insert(temp2); 
      flag = true;
      break;
    }
  }
  if ((*clt).getWord() == temp && !flag){  // we found a duplicate at the end of the file
      WordData temp2 = *clt;
      //CList.remove(*clt);
      CList.remove(temp2);
      temp2.incCount(1);
      CList.insert(temp2);
      flag = true;
    }
  if (flag == false){ // if the flag is false, this word is not a duplicate. Just add it into the list.
    WordData data;
    data.setWordData(temp, 1);
    CList.insert(data);
  } 

 }

    auto end = high_resolution_clock::now();
    auto ticks = duration_cast<microseconds>(end-begin);

    std::cout << "It took me " << ticks.count() << " microseconds to parse words into circular linked list.\n";

}


/*****************************************************************/
  /*    Function name:   printIteratively()                        */
  /*                                                               */
  /*    Description:     prints the items in our CLinkedList       */
  /*                     object ITERATIVELY	                   */
  /*                                                               */
  /*                                                               */
  /*    Parameters:	 none                                      */
  /*                                                               */
  /*                                                               */
  /*    Member Type:     facilitator                               */
  /*                                                               */
  /*    Return Value:    none                                      */
  /*****************************************************************/
   //! printIteratively() 
   /*!
      \brief Print the data iteratively
    */
void WordCList::printIteratively(){
    using namespace std::chrono;
    cout << " " << endl;
    std::cout << "Calculating time to print the circular linked list iteratively...\n";

    auto begin = high_resolution_clock::now();

    cout<<"--------------------------------"<<endl;
    cout<<"|Circular Linked List Iterative|"<<endl;
    cout<<"|Word         Occurences       |"<<endl;
    cout<<"--------------------------------"<<endl;
    
    CListItr<WordData> clt(CList);
 
    if (clt.isEmpty() == true){
    cout << "The list is empty, nothing to print." << endl;
  }

  for (clt.begin(); clt.isLastNode() == false; clt++){
    cout << *clt << endl;
  }
  cout << *clt << endl;

    auto end = high_resolution_clock::now();
    auto ticks = duration_cast<microseconds>(end-begin);

    std::cout << "It took me " << ticks.count() << " microseconds to print the circular linked list iteratively.\n";
    cout << " " << endl;
}


/*****************************************************************/
  /*    Function name:   printRecursively()                        */
  /*                                                               */
  /*    Description:     prints the items in our CLinkedList       */
  /*                     object RECURSIVELY                        */
  /*                                                               */
  /*                                                               */
  /*    Parameters:	 none                                      */
  /*                                                               */
  /*                                                               */
  /*    Member Type:     facilitator                               */
  /*                                                               */
  /*    Return Value:    none                                      */
  /*****************************************************************/
   //! printRecursively()  
   /*!
      \brief Calls helper function to print the data recursively
    */
void WordCList::printRecursively(){
    using namespace std::chrono;
    cout << " " << endl;
    std::cout << "Calculating time to print the circular linked list recursively...\n";

    auto begin = high_resolution_clock::now();

    cout<<"--------------------------------"<<endl;
    cout<<"|Circular Linked List Recursive|"<<endl;
    cout<<"|Word         Occurences       |"<<endl;
    cout<<"--------------------------------"<<endl;
  CListItr<WordData> clt(CList);
  clt.begin();
  printRecursivelyHelper(clt);

    auto end = high_resolution_clock::now();
    auto ticks = duration_cast<microseconds>(end-begin);

    std::cout << "It took me " << ticks.count() << " microseconds to print the circular linked list recursively.\n";
    cout << " " << endl;
}

   //! printRecursivelyHelper()
   /*!
      \brief Helper function that prints the data recursively
    */
void WordCList::printRecursivelyHelper(CListItr<WordData> &clt){

  if (clt.isLastNode() == true){
    cout << *clt << endl;
    return;
  }

  else{
    cout << *clt << endl;
    clt++;
    printRecursivelyHelper(clt);
  }

}

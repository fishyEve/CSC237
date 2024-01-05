/*******************************************************************/
/*    Author:        Eve Collier                                   */
/*    Course:        CSC237                                        */
/*    Date:          3/26/23                                       */
/*    Filename:      WordCList.h                                   */
/*    Description:   WordCList.h is a header file containing       */
/*                   a class definition for our WordCList object   */
/*                                                                 */
/*                                                                 */
/*                                                                 */
/*                                                                 */
/*                                                                 */
/*                                                                 */
/*******************************************************************/

#ifndef WordCList_h
#define WordCList_h


#include "CLinkedList.h"
#include "WordList.h"
#include <assert.h>
#include <iostream>

#include "WordData.h"


  /*! \file WordCList.h
      \brief Container of WordData objects
      \class WordCList
      \brief Container of WordData objects
   */

using namespace std;

class WordCList : public WordList { 

  public:

  /*! Constructor
      - constructs a circular linked list of word data objects
   */
    WordCList();

   
  /*! 
      - puts a string of strings into the list object
   */
    virtual void parseIntoList(ifstream &inf);

  /*! 
      - prints the data iteratively
   */
    virtual void printIteratively();

  /*! 
      - prints the data recursively
   */  
    virtual void printRecursively();

  /*! 
      - helper function that actually prints the data recursively 
   */
  void printRecursivelyHelper(CListItr<WordData> &clt);
 
 private:
  /*! Variable
      - the circular linked list of WordData type 
   */
    CLinkedList<WordData> CList;

};


#endif

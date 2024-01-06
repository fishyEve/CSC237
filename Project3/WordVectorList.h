/*******************************************************************/
/*    Author:        Eve Collier                                   */
/*    Course:        CSC237                                        */
/*    Date:          3/26/23                                       */
/*    Filename:      WordVectorList.h                              */
/*    Description:   WordVectorList.h is a header file containing  */
/*                   a class definition for our WordVectorList obj */
/*                                                                 */
/*                                                                 */
/*                                                                 */
/*                                                                 */
/*                                                                 */
/*                                                                 */
/*******************************************************************/
#ifndef WordVectorList_h
#define WordVectorList_h

#include <vector>
#include "WordList.h"
#include "WordData.h"
#include <assert.h>
#include <iostream>

  /*! \file WordVectorList.h
      \brief Container of WordData objects
      \class WordVectorList
      \brief Container of WordData objects
   */

using namespace std;

class WordVectorList : public WordList {
  public:
  /*! Constructor
      - constructs a default vector holding the word data objects
   */
    WordVectorList();
    
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
    void printRecursivelyHelper(vector<WordData> &VList);

    

  private:
  /*! Variable
      - the vector of WordData type
   */
    vector<WordData> VList;
   

};


#endif

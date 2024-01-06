  /*! \file WordDataList.h
      \brief Container of WordData objects
      \class WordDataList
      \brief Container of WordData objects
   */

#ifndef WORDDATALIST_H
#define WORDDATALIST_H

#include <string>
#include "WordList.h"
#include "WordData.h"
//#include "WordCList.h"

using namespace std;

class WordDataList : public WordList {
public:
  /*! Constructor
      - constructs a word data object list, which hold WordData objects which contain  a string (holding a word)
      and an int (holding the number of occurances the word occurs in the file)
   */
  WordDataList();

  /*! 
      -	puts a string of strings into the list object
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
      - prints the data recursively with a pointer
   */
  virtual void printPtr();

private:
    //! Variable
    /*!
      - array holding the WordData objects
    */
  WordData TheWords[10];

    //! Variable
    /*!
      - an int holding the total number of words
    */
  int numWords;

    //! incMatch()
    /*!
      - if a corresponding word is found, it's incremented
    */
  bool incMatch(string temp);
  
    //! printRecursivelyWorker()
    /*!
      - function to actually perform recursive print
    */
  void printRecursivelyWorker(int numWords);

    //! 
    /*!
      - function to actually perform recursive print using pointer
    */

  void printPtrWorker(int numWords);


};
  
#endif

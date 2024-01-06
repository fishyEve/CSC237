/*! \file WordList.h
    \brief An abstract base class for contains of WordData objects
    \class WordList
    \brief An abstract base class for contains of WordData objects
 */
#ifndef WORDLIST_H
#define WORDLIST_H

#include <fstream>
#include <string>

using namespace std;

class WordList {
public:

  //! parseIntoList()
  /*!
    - places a line of text into the data structure
   */
  virtual void parseIntoList(ifstream &inf)=0;

 
  //! printIteratively()
  /*!
    - prints the data iteratively
   */
  virtual void printIteratively()=0;
  
  // Print the data recursively
  //! printRecursively()
  /*!
    - prints the data recursively
   */
  virtual void printRecursively()=0;
  
  
  //! printPtr()
  /*!
    - prints the data recursively with a pointer
   */
  virtual void printPtr() {}   // not pure virtual; why? Because only WordDataList.h implements this
    
};
  
#endif

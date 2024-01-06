/***************************************
 *    File:    WordData.cpp            *
 *    Purpose:                         *
 *                                     *
 ***************************************/
  

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "WordData.h"

/*!
          \file WordData.cpp
          \brief a cpp containing the implementation for WordData.h
          \class WordData.cpp
          \brief a cpp containing the implementation for WordData.h

 */

using namespace std;


  //! WordData()
  /*! 
      \brief Constructs a WordData object by setting the word and count.
  */
WordData::WordData(string wrd, int cnt)
{
        setWordData(wrd, cnt);
}

  //! setWord()           
  /*!
      \brief Sets a word of string type by setting it equal to what the function passes in (a wrd of string type)..
  */
void WordData::setWord(string wrd)
{
        word = wrd;
}

  //! setCount()
  /*!
     \brief Sets a count of int type by setting it equal to what the function passes in (a cnt of int type).
  */
void WordData::setCount(int cnt)
{
        count = cnt;
}

  //! setWordData()
  /*!
     \brief Sets a word of string type by setting it equal to what the function passes in (a wrd of string type
        and a cnt of int type).
  */
void WordData::setWordData(string wrd, int cnt)
{
        setWord(wrd);
        setCount(cnt);
}


  //! getWord()
  /*!
     \brief Gets a word of string type by simply returning it
  */
string WordData::getWord() const
{
        return(word);
}


  //! getCount()
  /*!
     \brief Gets a count of int type by simply returning it
  */
int WordData::getCount() const
{
        return(count);
}


  //! incCount()
  /*!
     \brief Increments a count of int type by setting its value equal its value when added to inc, which is
       an int passed in by the function.
  */
void WordData::incCount(int inc)
{
        count+=inc;
}


  //! >
  /*!
     \brief Returns a bool indicating whether or not the WordData object passed in
       from the function is less than the current word	
  */
bool WordData::operator>(const WordData &right) const{
    return (right.getWord() < word);
}


  //! <         
  /*!
     \brief Returns a bool indicating whether or not the WordData object passed in
       from the	function is greater than the current word
  */
bool WordData::operator<(const WordData	&left)	const{
   return (left.getWord() > word);
}

  //! ==         
  /*!
     \brief Returns a bool indicating whether or not the WordData object passed in
       from the	function is equal to the current word
  */
bool WordData::operator==(const WordData &left) const{
  return(left.getWord() == word);
}

ostream &operator<<(ostream& output, const WordData &words)
{
  output<<words.getWord()<<"\t\t"<<words.getCount();
  return output;
}
